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

#ifndef WAVRECORDWIDGET_H
#define WAVRECORDWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include "QFramer/fshadowlabel.h"
#include "QFramer/fstatebutton.h"
class WavRecordWidget : public QWidget
{
    Q_OBJECT
private:
    void initData();
    void initUI();
    void initConnect();
public:

    FShadowLabel* fileNameLabel;
    QLineEdit* fileNameLineEdit;
    FShadowLabel* fileNameUnit;

    FShadowLabel* wavNameLabel;
    QLineEdit* wavNameLineEdit;
    FShadowLabel* wavNameUnit;

    FShadowLabel* samplingRateLabel;
    QComboBox* samplingRateComBox;
    FShadowLabel* samplingRateUnit;

    FShadowLabel* bitsLabel;
    QComboBox* bitsComBox;
    FShadowLabel* bitsUnit;

    FShadowLabel* contanerLabel;
    QComboBox* containerComBox;

    FShadowLabel* durationLabel;
    QSpinBox* durationSpinBox;
    FShadowLabel* durationUnit;

    QSlider* slider;
    FShadowLabel* sliderUnit;

    QPushButton* newWavButton;
    FStateButton* startButton;
    QPushButton* playerButton;
public:
    explicit WavRecordWidget(QWidget *parent = 0);

signals:

public slots:
    void setSliderRange(int maxValue);
    void setSliderUnit(int value);

};

#endif // WAVRECORDWIDGET_H
