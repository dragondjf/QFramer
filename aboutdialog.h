#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "basedialog.h"

class AboutDialog : public BaseDialog
{
    Q_OBJECT
private:
    QPushButton* enterButton;

public:
    explicit AboutDialog(QWidget *parent = 0);
    void initUI();
    void initConnect();
signals:

public slots:

};

#endif // ABOUTDIALOG_H
