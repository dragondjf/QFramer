#ifndef WATERWIDGET_H
#define WATERWIDGET_H

#include <QLabel>

class WaterWidget : public QLabel
{
    Q_OBJECT
private:
    void initData();
    void initUI();
    void initConnect();

public:
    explicit WaterWidget(QWidget *parent = 0);

signals:

public slots:

};

#endif // WATERWIDGET_H
