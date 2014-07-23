#ifndef WAVRECORDMANAGER_H
#define WAVRECORDMANAGER_H

#include <QWidget>
#include <QMediaRecorder>
#include <QAudioRecorder>
#include <QAudioProbe>
#include "qaudiolevel.h"
#include "wavutil.h"
#include "QFramer/fstatebutton.h"
#include "QFramer/fshadowlabel.h"
#include "wavrecordwidget.h"
class WavRecordManager : public QWidget
{
    Q_OBJECT
private:
    FStateButton* voiceButton;
    FShadowLabel* voiceLabel;
    WavRecordWidget* wavRecord;

    QAudioRecorder *audioRecorder;
    QAudioProbe *probe;
    QList<QAudioLevel*> audioLevels;

private:
    void initData();
    void initUI();
    void initConnect();
    void clearAudioLevels();
public:
    explicit WavRecordManager(QWidget *parent = 0);

signals:

public slots:
    void changeVoiceLabel();
    void setVoiceButtonDisbled();
    void toggleRecord();
    void updateStatus(QMediaRecorder::Status);
    void updateProgress(qint64 pos);
    void processBuffer(const QAudioBuffer&);

};

#endif // WAVRECORDMANAGER_H
