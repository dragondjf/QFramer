#include "recordmanager.h"

#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>

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
    QStringList samplingrates;
    samplingrates << "8" << "16" << "22" << "44";
    samplingRateComBox->addItems(samplingrates);
    samplingRateUnit = new FShadowLabel(tr("KHZ"));

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

    wavLayout->addWidget(samplingRateLabel, 2, 0);
    wavLayout->addWidget(samplingRateComBox, 2, 1);
    wavLayout->addWidget(samplingRateUnit, 2, 2);

    wavLayout->addWidget(bitsLabel, 3, 0);
    wavLayout->addWidget(bitsComBox, 3, 1);
    wavLayout->addWidget(bitsUnit, 3 ,2);

    wavLayout->addWidget(durationLabel, 4 ,0);
    wavLayout->addWidget(durationSpinBox, 4 ,1);
    wavLayout->addWidget(durationUnit, 4 ,2);

    wavLayout->addWidget(slider, 5, 1);
    wavLayout->addWidget(sliderUnit, 5 ,2);

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
    connect(wavRecord->newWavButton, SIGNAL(clicked()), this, SLOT(setVoiceButtonDisbled()));
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



