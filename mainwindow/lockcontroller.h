#ifndef LOCKCONTROLLER_H
#define LOCKCONTROLLER_H

#include <QObject>

class LockController : public QObject
{
    Q_OBJECT
public:
    explicit LockController(QObject *parent = 0);

signals:

public slots:
    void lockMovable();
    void lockUnmoved();
    void unLock();
};

#endif // LOCKCONTROLLER_H
