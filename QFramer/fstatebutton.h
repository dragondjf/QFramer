#ifndef FSTATEBUTTON_H
#define FSTATEBUTTON_H

#include <QPushButton>

class FStateButton : public QPushButton
{
    Q_OBJECT
private:
    QString fStateIcon;
    QString bStateIcon;
    int state;
    int bflag;
private slots:
    void changeState();
public:
    explicit FStateButton(const QString &ficon, const QString &bicon, int buttonFlag = 0, QWidget *parent = 0);
    int getState();
signals:
    void stateChanged();
public slots:

};

#endif // FSTATEBUTTON_H
