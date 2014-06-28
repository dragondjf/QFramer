#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>
#include<QMouseEvent>
#include "titlebar.h"

class BaseDialog : public QDialog
{
    Q_OBJECT
private:
    QPoint dragPosition;

private:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    TitleBar* titlebar;
public:
    explicit BaseDialog(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();

signals:

public slots:

};

#endif // BASEDIALOG_H
