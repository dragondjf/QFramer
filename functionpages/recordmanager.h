#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QAudioBuffer>
#include <QAudioProbe>
#include <QAudioRecorder>
#include <QDir>
#include <QFileDialog>
#include <QMediaRecorder>

#include "QFramer/fstatebutton.h"
#include "QFramer/fshadowlabel.h"
#include "audiorecord/qaudiolevel.h"

class WavRecord: public QWidget
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
    explicit WavRecord(QWidget *parent = 0);

signals:

public slots:
    void setSliderRange(int maxValue);
    void setSliderUnit(int value);

};


class RecordManager : public QWidget
{
    Q_OBJECT
private:
    FStateButton* voiceButton;
    FShadowLabel* voiceLabel;
    WavRecord* wavRecord;

    QAudioRecorder *audioRecorder;
    QAudioProbe *probe;
    QList<QAudioLevel*> audioLevels;

private:
    void initData();
    void initUI();
    void initConnect();
    void clearAudioLevels();
public:
    explicit RecordManager(QWidget *parent = 0);

signals:

public slots:
    void changeVoiceLabel();
    void setVoiceButtonDisbled();
    void toggleRecord();
    void updateStatus(QMediaRecorder::Status);
    void updateProgress(qint64 pos);
    void processBuffer(const QAudioBuffer&);
};



#endif // RECORDMANAGER_H
