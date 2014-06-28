#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H
#include "basedialog.h"

class SettingDialog : public BaseDialog
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
