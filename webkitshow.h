#ifndef WEBKITSHOW_H
#define WEBKITSHOW_H

#include <QWidget>
#include<QWebView>
#include<QWebInspector>
#include <QtWebKitWidgets>
class WebkitShow : public QWidget
{
    Q_OBJECT


protected slots:
    void setProgress(int p);
    void finishLoading(bool);

public:
    QWebInspector* webInspector;
    QWebView* view;
    int progress;
public:
    explicit WebkitShow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void setupInspector();

signals:

public slots:
    void toggleInspector();
};

#endif // WEBKITSHOW_H
