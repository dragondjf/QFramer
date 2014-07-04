#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H
#include "QFramer/fbasedialog.h"

class SettingDialog : public FBaseDialog
{
    Q_OBJECT
public:
    explicit SettingDialog(QWidget *parent = 0);
    void initUI();
    void initConnect();
signals:

public slots:

};

#endif // SETTINGDIALOG_H
