#ifndef RECORDTHREAD_H
#define RECORDTHREAD_H

#include <QThread>

class RecordThread : public QThread
{
    Q_OBJECT
public:
    explicit RecordThread(QObject *parent = 0);

signals:

public slots:

};

#endif // RECORDTHREAD_H
