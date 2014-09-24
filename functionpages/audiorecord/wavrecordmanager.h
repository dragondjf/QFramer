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

#ifndef WAVRECORDMANAGER_H
#define WAVRECORDMANAGER_H

#include <QWidget>
#include <QMediaRecorder>
#include <QAudioRecorder>
#include <QAudioProbe>
#include <QThread>
#include "qaudiolevel.h"
#include "wavutil.h"
#include "QFramer/fstatebutton.h"
#include "QFramer/fshadowlabel.h"
#include "wavrecordwidget.h"


class IFlyTekTask : public QThread
{
private:
    const char* wavefilename;
public:
    explicit IFlyTekTask(const char* filename, QObject * parent = 0);
    void run();
    void setFileName(const char* filename);
};


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
    IFlyTekTask *wavTask;

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
