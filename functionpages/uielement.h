#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <QTabWidget>

class UIElement : public QTabWidget
{
    Q_OBJECT
public:
    explicit UIElement(QWidget *parent = 0);
    void initUI();
    void initBaseElements();
    void initTableWidget();
    void initTreeWidget();
    void initComoBox();
signals:

public slots:

};

#endif // UIELEMENT_H
