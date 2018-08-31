#ifndef FTOOLBUTTON_H
#define FTOOLBUTTON_H

#include <QMenu>
#include <QToolButton>

class FToolButton : public QToolButton
{
    Q_OBJECT
public:
    FToolButton(QWidget* parent = 0);
    ~FToolButton();

#ifdef Q_OS_LINUX
    void setMenu(QMenu *menu);
public slots:
    void recover();
#endif
};

#endif // FTOOLBUTTON_H
