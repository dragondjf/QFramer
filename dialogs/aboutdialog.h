#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "QFramer/fbasedialog.h"

class AboutDialog : public FBaseDialog
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
    void animationClose();
};

#endif // ABOUTDIALOG_H
