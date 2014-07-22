#include "recordmanager.h"

#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>


static qreal getPeakValue(const QAudioFormat &format);
static QVector<qreal> getBufferLevels(const QAudioBuffer &buffer);

template <class T>
static QVector<qreal> getBufferLevels(const T *buffer, int frames, int channels);


WavRecord::WavRecord(QWidget *parent):
    QWidget(parent)
{
    initData();
    initUI();
    initConnect();
}

void WavRecord::initData()
{

}

void WavRecord::initUI()
{
    fileNameLabel = new FShadowLabel(tr("App Name:"));
    fileNameLineEdit = new QLineEdit;
    fileNameLineEdit->setPlaceholderText(tr("Please input app name"));

    wavNameLabel = new FShadowLabel(tr("Wav Name:"));
    wavNameLineEdit = new QLineEdit;
    wavNameLineEdit->setPlaceholderText(tr("Please input wav name"));

    samplingRateLabel = new FShadowLabel(tr("Sampling rate:"));
    samplingRateComBox = new QComboBox;
    samplingRateComBox->addItem(tr("Default"), QVariant(0));
    samplingRateUnit = new FShadowLabel(tr("KHZ"));

    contanerLabel = new FShadowLabel(tr("File container"));
    containerComBox = new QComboBox;
    containerComBox->addItem(tr("Default"), QVariant(QString()));

    bitsLabel = new FShadowLabel(tr("Bits:"));
    bitsComBox = new QComboBox;
    QStringList bits;
    bits << "8" << "16";
    bitsComBox->addItems(bits);
    bitsUnit = new FShadowLabel(tr("bit"));

    durationLabel = new FShadowLabel(tr("Duration:"));
    durationSpinBox = new QSpinBox;
    durationSpinBox->setValue(5);
    durationUnit = new FShadowLabel(tr("s"));


    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, durationSpinBox->value());
    sliderUnit = new FShadowLabel(tr("s"));

    newWavButton = new QPushButton(tr("New"));
    newWavButton->setFixedSize(50, 30);
    playerButton = new QPushButton(tr("Play"));
    playerButton->setFixedSize(50, 30);

    QGridLayout* wavLayout = new QGridLayout;
    wavLayout->setSpacing(10);
    wavLayout->addWidget(fileNameLabel, 0, 0);
    wavLayout->addWidget(fileNameLineEdit, 0, 1);

    wavLayout->addWidget(wavNameLabel, 1, 0);
    wavLayout->addWidget(wavNameLineEdit, 1, 1);

    wavLayout->addWidget(contanerLabel, 2, 0);
    wavLayout->addWidget(containerComBox, 2, 1);

    wavLayout->addWidget(samplingRateLabel, 3, 0);
    wavLayout->addWidget(samplingRateComBox, 3, 1);
    wavLayout->addWidget(samplingRateUnit, 3, 2);

    wavLayout->addWidget(bitsLabel, 4, 0);
    wavLayout->addWidget(bitsComBox, 4, 1);
    wavLayout->addWidget(bitsUnit, 4 ,2);

    wavLayout->addWidget(durationLabel, 5 ,0);
    wavLayout->addWidget(durationSpinBox, 5 ,1);
    wavLayout->addWidget(durationUnit, 5 ,2);

    wavLayout->addWidget(slider, 6, 1);
    wavLayout->addWidget(sliderUnit, 6 ,2);

    QHBoxLayout* controlLayout = new QHBoxLayout;
    controlLayout->addWidget(newWavButton);
    controlLayout->addStretch();
    controlLayout->addWidget(playerButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addLayout(wavLayout);
    mainLayout->addLayout(controlLayout);
    mainLayout->addStretch();
    setLayout(mainLayout);
}

void WavRecord::initConnect()
{
    connect(durationSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setSliderRange(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setSliderUnit(int)));
}

void WavRecord::setSliderRange(int maxValue)
{
    slider->setRange(0, maxValue);
}

void WavRecord::setSliderUnit(int value)
{
    sliderUnit->setText(QString::number(value) + "s");
}


RecordManager::RecordManager(QWidget *parent) :
    QWidget(parent)
{
    initData();
    initUI();
    initConnect();
}

void RecordManager::initData()
{

    audioRecorder = new QAudioRecorder(this);
    probe = new QAudioProbe;
    connect(probe, SIGNAL(audioBufferProbed(QAudioBuffer)),
            this, SLOT(processBuffer(QAudioBuffer)));
    probe->setSource(audioRecorder);

    connect(audioRecorder, SIGNAL(durationChanged(qint64)), this,
            SLOT(updateProgress(qint64)));
    connect(audioRecorder, SIGNAL(statusChanged(QMediaRecorder::Status)), this,
            SLOT(updateStatus(QMediaRecorder::Status)));


}

void RecordManager::initUI()
{
    voiceButton = new FStateButton(QString(":/images/skin/images/fvoice.png"),\
                                                 QString(":/images/skin/images/bvoice.png"),\
                                                 0, this);
    voiceButton->setObjectName("Record");
    voiceButton->setDisabled(true);
    voiceLabel = new FShadowLabel;
    voiceLabel->setObjectName("Listening");
    wavRecord = new WavRecord;

    foreach (const QString &containerName, audioRecorder->supportedContainers()) {
        wavRecord->containerComBox->addItem(containerName, QVariant(containerName));
    }

    foreach (int sampleRate, audioRecorder->supportedAudioSampleRates()) {
        wavRecord->samplingRateComBox->addItem(QString::number(sampleRate), QVariant(
                sampleRate));
    }

    QVBoxLayout* voiceLayout = new QVBoxLayout;
    voiceLayout->addWidget(wavRecord);
    voiceLayout->addWidget(voiceButton);
    voiceLayout->addWidget(voiceLabel);
    voiceLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(voiceLayout);
    mainLayout->addStretch();
    setLayout(mainLayout);
}

void RecordManager::initConnect()
{
    connect(voiceButton, SIGNAL(stateChanged()), this, SLOT(changeVoiceLabel()));
    connect(voiceButton, SIGNAL(stateChanged()), this, SLOT(toggleRecord()));
    connect(wavRecord->newWavButton, SIGNAL(clicked()), this, SLOT(setVoiceButtonDisbled()));
}

void RecordManager::updateProgress(qint64 duration)
{
    if (audioRecorder->error() != QMediaRecorder::NoError || duration < 2000)
        return;
    wavRecord->slider->setValue(duration / 1000);
}


void RecordManager::updateStatus(QMediaRecorder::Status status)
{
    switch (status) {
    case QMediaRecorder::RecordingStatus:
        if (audioLevels.count() != audioRecorder->audioSettings().channelCount()) {
            qDeleteAll(audioLevels);
            audioLevels.clear();
            for (int i = 0; i < audioRecorder->audioSettings().channelCount(); ++i) {
                QAudioLevel *level = new QAudioLevel(this);
                audioLevels.append(level);
                wavRecord->layout()->addWidget(level);
            }
        }
        break;
    case QMediaRecorder::PausedStatus:
        clearAudioLevels();
        break;
    case QMediaRecorder::UnloadedStatus:
    case QMediaRecorder::LoadedStatus:
        clearAudioLevels();
    default:
        break;
    }
}

void RecordManager::clearAudioLevels()
{
    for (int i = 0; i < audioLevels.size(); ++i)
        audioLevels.at(i)->setLevel(0);
}

void RecordManager::toggleRecord()
{
    if (audioRecorder->state() == QMediaRecorder::StoppedState) {
//        audioRecorder->setAudioInput(boxValue(ui->audioDeviceBox).toString());

        QAudioEncoderSettings settings;
        settings.setCodec("audio/PCM");
        settings.setSampleRate(8000);
        settings.setBitRate(32000);
        settings.setChannelCount(2);
        settings.setQuality(QMultimedia::EncodingQuality(3));
        settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);

        QString container = "audio/x-wav";

        audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), container);


        QString fileName = QString("%1/test.wav").arg(QDir::currentPath());
        audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileName));
        qDebug(qPrintable(fileName));

        audioRecorder->record();
    }
    else {
        audioRecorder->stop();
    }
}

void RecordManager::changeVoiceLabel()
{
    if (voiceButton->getState() == 1)
    {
        voiceButton->setToolTip(tr("Recording on "));
        voiceLabel->setText("Listening...");
        wavRecord->setEnabled(false);
        wavRecord->newWavButton->setEnabled(false);
    }
    else if (voiceButton->getState() == 0)
    {
        voiceButton->setToolTip(tr("Recording off"));
        voiceLabel->setText("");
        wavRecord->setEnabled(true);
        wavRecord->newWavButton->setEnabled(true);
    }
}

void RecordManager::setVoiceButtonDisbled()
{
    wavRecord->newWavButton->setEnabled(false);
    voiceButton->setEnabled(true);
}


void RecordManager::processBuffer(const QAudioBuffer& buffer)
{
    QVector<qreal> levels = getBufferLevels(buffer);
    for (int i = 0; i < levels.count(); ++i)
        audioLevels.at(i)->setLevel(levels.at(i));
}

// This function returns the maximum possible sample value for a given audio format
qreal getPeakValue(const QAudioFormat& format)
{
    // Note: Only the most common sample formats are supported
    if (!format.isValid())
        return qreal(0);

    if (format.codec() != "audio/pcm")
        return qreal(0);

    switch (format.sampleType()) {
    case QAudioFormat::Unknown:
        break;
    case QAudioFormat::Float:
        if (format.sampleSize() != 32) // other sample formats are not supported
            return qreal(0);
        return qreal(1.00003);
    case QAudioFormat::SignedInt:
        if (format.sampleSize() == 32)
            return qreal(INT_MAX);
        if (format.sampleSize() == 16)
            return qreal(SHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(CHAR_MAX);
        break;
    case QAudioFormat::UnSignedInt:
        if (format.sampleSize() == 32)
            return qreal(UINT_MAX);
        if (format.sampleSize() == 16)
            return qreal(USHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(UCHAR_MAX);
        break;
    }

    return qreal(0);
}

// returns the audio level for each channel
QVector<qreal> getBufferLevels(const QAudioBuffer& buffer)
{
    QVector<qreal> values;

    if (!buffer.format().isValid() || buffer.format().byteOrder() != QAudioFormat::LittleEndian)
        return values;

    if (buffer.format().codec() != "audio/pcm")
        return values;

    int channelCount = buffer.format().channelCount();
    values.fill(0, channelCount);
    qreal peak_value = getPeakValue(buffer.format());
    if (qFuzzyCompare(peak_value, qreal(0)))
        return values;

    switch (buffer.format().sampleType()) {
    case QAudioFormat::Unknown:
    case QAudioFormat::UnSignedInt:
        if (buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<quint32>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<quint16>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<quint8>(), buffer.frameCount(), channelCount);
        for (int i = 0; i < values.size(); ++i)
            values[i] = qAbs(values.at(i) - peak_value / 2) / (peak_value / 2);
        break;
    case QAudioFormat::Float:
        if (buffer.format().sampleSize() == 32) {
            values = getBufferLevels(buffer.constData<float>(), buffer.frameCount(), channelCount);
            for (int i = 0; i < values.size(); ++i)
                values[i] /= peak_value;
        }
        break;
    case QAudioFormat::SignedInt:
        if (buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<qint32>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<qint16>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<qint8>(), buffer.frameCount(), channelCount);
        for (int i = 0; i < values.size(); ++i)
            values[i] /= peak_value;
        break;
    }

    return values;
}

template <class T>
QVector<qreal> getBufferLevels(const T *buffer, int frames, int channels)
{
    QVector<qreal> max_values;
    max_values.fill(0, channels);

    for (int i = 0; i < frames; ++i) {
        for (int j = 0; j < channels; ++j) {
            qreal value = qAbs(qreal(buffer[i * channels + j]));
            if (value > max_values.at(j))
                max_values.replace(j, value);
        }
    }

    return max_values;
}





