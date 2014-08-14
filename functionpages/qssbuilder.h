#ifndef QSSBUILDER_H
#define QSSBUILDER_H

#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QJsonObject>


class QssBuilder : public QFrame
{
    Q_OBJECT
private:
    int currentIndex;
private:
    void initData();
    void initUI();
    void initConnect();
public:
    QStringList colorKeys;
    QStringList colorLabels;
    QStringList colorValues;

    QList<QLineEdit * > lineedits;
    QList<QPushButton *> buttons;
    QJsonObject colorMap;
public:
    explicit QssBuilder(QWidget *parent = 0);
    void updateTheme();

signals:

public slots:
    void getColor();
    void setButtonColor(QColor color);
    void setButtonColor(QString color);
    void changeIconColor(int mode);
};

#endif // QSSBUILDER_H
