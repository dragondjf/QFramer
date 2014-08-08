#include "qssbuilder.h"
#include "QFramer/futil.h"
#include <QGridLayout>
#include <QColorDialog>
#include <QLabel>
#include<QJsonDocument>
#include<QFile>
#include<QDir>
QssBuilder::QssBuilder(QWidget *parent) :
    QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void QssBuilder::initData()
{
    colorKeys << "main background color";
    colorLabels << "main_background_color";
    colorValues << "rgb(51, 79, 91)";

    colorKeys << "main background image";
    colorLabels << "main_background_image";
    colorValues << "none";

    colorKeys << "navgation background color";
    colorLabels << "nav_background_color";
    colorValues << "rgb(43, 152, 188)";

    colorKeys << "main hover color";
    colorLabels << "main_hover_color";
    colorValues << "rgb(27, 118, 150)";

    colorKeys << "main select color";
    colorLabels << "main_select_color";
    colorValues << "rgb(34, 125, 155)";

    colorKeys << "separator border";
    colorLabels << "border_separator";
    colorValues << "1px solid rgb(34, 125, 155)";

    colorKeys << "title color";
    colorLabels << "Ftitle_color";
    colorValues << "white";

    colorKeys << "menu left border";
    colorLabels << "Menu_border_left";
    colorValues << "5px solid rgb(255, 127, 39)";

    colorKeys << "animation line background color";
    colorLabels << "AntimationLine_background-color";
    colorValues << "rgb(255, 127, 39)";

    colorKeys << "label font color";
    colorLabels << "Label_color";
    colorValues << "rgb(53, 153, 135)";

    colorKeys << "pusbutton color";
    colorLabels << "PushButton_color";
    colorValues << "white";

    colorKeys << "pusbutton background color";
    colorLabels << "PushButton_background_color";
    colorValues << "rgb(43, 65, 77)";

    colorKeys << "pusbutton pressed background color";
    colorLabels << "PushButton_Pressed_background_color";
    colorValues << "rgb(50, 77, 92)";

    colorKeys << "pusbutton left border";
    colorLabels << "PushButton_border_left";
    colorValues << "5px solid rgb(255, 127, 39)";

    colorKeys << "pusbutton bottom border";
    colorLabels << "PushButton_border_bottom";
    colorValues << "0px solid rgb(255, 127, 39)";

    colorKeys << "combox background color";
    colorLabels << "Combox_background_color";
    colorValues << "rgb(0, 0, 64)";

    colorKeys << "scrollbar background color";
    colorLabels << "ScrollBar_background_color";
    colorValues << "white";

    colorKeys << "scrollbar handle color";
    colorLabels << "ScrollBar_handle_color";
    colorValues << "rgb(70, 97, 102)";

    colorKeys << "headview background color";
    colorLabels << "HeadView_background_color";
    colorValues << "rgb(34, 125, 155)";

    colorKeys << "table or tree background color";
    colorLabels << "TableTree_background_color";
    colorValues << "rgb(27, 118, 150)";
}

void QssBuilder::initUI()
{
    QGridLayout* mainLayout = new QGridLayout;
    for(int i=0; i< colorKeys.length(); i++)
    {
        QLabel* label = new QLabel("<h4>" + colorKeys[i] + ":" + "</h4>");
        label->setStyleSheet("QLabel{\
           padding: 5px;\
           color: green;\
           qproperty-alignment: AlignRight ;\
        }");
        label->setFixedSize(250, 36);
        QLineEdit* lineedit = new QLineEdit(colorValues[i]);
        lineedit->setFixedSize(300, 36);
        QPushButton* button = new QPushButton;

        QString style = QString("QPushButton#setColor{background-color: %1;}");
        style = style.arg(colorValues[i]);
        button->setStyleSheet(style);
        button->setObjectName("setColor");
        button->setFixedSize(60, 36);
        lineedits.append(lineedit);
        buttons.append(button);

        mainLayout->addWidget(label, i, 0);
        mainLayout->addWidget(lineedit, i, 1);
        mainLayout->addWidget(button, i, 2);
        mainLayout->setColumnStretch(4, 1);

        colorMap[colorLabels[i]] = colorValues[i];
    }

    setLayout(mainLayout);
}

void QssBuilder::initConnect()
{
    for(int i=0; i<buttons.length(); i++){
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(getColor()));
        connect(lineedits[i], SIGNAL(textChanged(QString)), this, SLOT(setButtonColor(QString)));
    }
}

void QssBuilder::getColor()
{
    currentIndex = buttons.indexOf((QPushButton*)sender());
    QColorDialog* colorDialog = new QColorDialog();
    colorDialog->setObjectName("colorDialog");
    connect(colorDialog, SIGNAL(currentColorChanged(QColor)), this, SLOT(setButtonColor(QColor)));
    colorDialog->exec();
}

void QssBuilder::setButtonColor(QColor color)
{
    QString ctr = QString("rgb(%1, %2, %3)");
    ctr = ctr.arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()));
    QString style = QString("QPushButton#setColor{background-color: %1;}");
    style = style.arg(ctr);
    lineedits.at(currentIndex)->setText(ctr);
    buttons.at(currentIndex)->setStyleSheet(style);

    colorMap[colorLabels[currentIndex]] = ctr;

    QJsonDocument doc = QJsonDocument(colorMap);
    QFile outFile("customColor.json");
    outFile.open(QIODevice::WriteOnly);
    outFile.write(doc.toJson());
    outFile.close();

    QString qss = getQssFromFile(":/qss/skin/qss/template.qss");
    for(int i=0; i< colorLabels.length(); i++){
       qss.replace(colorLabels[i], colorMap[colorLabels[i]].toString());
    }
    qApp->setStyleSheet(qss);
    qDebug(qPrintable(qss));

    QFile outqssFile("test.qss");
    outqssFile.open(QIODevice::WriteOnly);
    outqssFile.write(qss.toStdString().data());
    outqssFile.close();


}

void QssBuilder::setButtonColor(QString color)
{
    currentIndex = lineedits.indexOf((QLineEdit*)sender());
    QString style = QString("QPushButton#setColor{background-color: %1;}");
    style = style.arg(color);
    buttons.at(currentIndex)->setStyleSheet(style);
}
