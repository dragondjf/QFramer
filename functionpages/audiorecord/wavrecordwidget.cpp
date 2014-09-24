/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

#include "wavrecordwidget.h"

WavRecordWidget::WavRecordWidget(QWidget *parent):
    QWidget(parent)
{
    initData();
    initUI();
    initConnect();
}

void WavRecordWidget::initData()
{

}

void WavRecordWidget::initUI()
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

void WavRecordWidget::initConnect()
{
    connect(durationSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setSliderRange(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setSliderUnit(int)));
}

void WavRecordWidget::setSliderRange(int maxValue)
{
    slider->setRange(0, maxValue);
}

void WavRecordWidget::setSliderUnit(int value)
{
    sliderUnit->setText(QString::number(value) + "s");
}
