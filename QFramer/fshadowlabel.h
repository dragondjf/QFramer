#ifndef FSHADOWLABEL_H
#define FSHADOWLABEL_H

#include <QLabel>

class FShadowLabel : public QLabel
{
    Q_OBJECT
public:
    explicit FShadowLabel(const QString &text, QWidget *parent = 0);
    explicit FShadowLabel(QWidget *parent = 0);

signals:

public slots:

};

#endif // FSHADOWLABEL_H
