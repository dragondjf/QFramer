#ifndef WAVUTIL_H
#define WAVUTIL_H
#include<QAudioFormat>
#include<QAudioBuffer>
#include <QVector>
qreal getPeakValue(const QAudioFormat &format);
QVector<qreal> getBufferLevels(const QAudioBuffer &buffer);

template <class T>
QVector<qreal> getBufferLevels(const T *buffer, int frames, int channels);

#endif // WAVUTIL_H
