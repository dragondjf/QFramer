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

    void setMenu(QMenu *menu);

public slots:
    void recover();

};

#endif // FTOOLBUTTON_H
