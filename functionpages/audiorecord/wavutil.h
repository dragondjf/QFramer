#ifndef WAVUTIL_H
#define WAVUTIL_H

#include "stdlib.h"
#include "stdio.h"
#include <windows.h>
#include <conio.h>
#include <errno.h>

#include "iflytek/include/qisr.h"
#include "iflytek/include/qtts.h"
#include "iflytek/include/msp_cmn.h"
#include "iflytek/include/msp_errors.h"
#include "iflytek/include/msp_types.h"

#ifdef _WIN64
#pragma comment(lib,"iflytek/lib/msc_x64.lib")//x64
#else
#pragma comment(lib,"iflytek/lib/msc.lib")//x86
#endif

#define  BUFFER_NUM  4096
#define MAX_KEYWORD_LEN 4096

#include<QAudioFormat>
#include<QAudioBuffer>
#include <QVector>
qreal getPeakValue(const QAudioFormat &format);
QVector<qreal> getBufferLevels(const QAudioBuffer &buffer);

template <class T>
QVector<qreal> getBufferLevels(const T *buffer, int frames, int channels);

int get_grammar_id( int upload);
int run_asr(const char* asrfile ,  const char* param);
QString wavToText(const char* wavfilename);
#endif // WAVUTIL_H
