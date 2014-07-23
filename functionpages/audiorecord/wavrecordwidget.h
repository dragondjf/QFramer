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
