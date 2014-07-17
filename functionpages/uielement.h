#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <QProgressBar>
#include "QFramer/ftabwidget.h"
class UIElement : public FTabWidget
{
    Q_OBJECT
private:
    QList<QProgressBar *> progressBars;
public:
    explicit UIElement(QWidget *parent = 0);
    void initUI();
    void initBaseElements();
    void initTableWidget();
    void initTreeWidget();
    void initProgressBar();
signals:

public slots:
    void updateProgressBar();
};

#endif // UIELEMENT_H
