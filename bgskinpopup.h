#ifndef BGSKINPOPUP_H
#define BGSKINPOPUP_H

#include <QWidget>
#include <QSlider>
class BgSkinPopup : public QWidget
{
    Q_OBJECT
private:
    QSlider* redSlider;
    QSlider* greenSlider;
    QSlider* blueSlider;

public:
    explicit BgSkinPopup(QWidget *parent = 0);
    bool eventFilter(QObject * watched, QEvent * event);
    void initUI();
    void initConnect();
signals:

public slots:
    void updateBackgroundColor(const int value);
};

#endif // BGSKINPOPUP_H
