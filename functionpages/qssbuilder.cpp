/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

#include "qssbuilder.h"
#include "QFramer/futil.h"
#include <QGridLayout>
#include <QColorDialog>
#include <QLabel>
#include <QFile>
#include <QDir>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    #include <QJsonDocument>
    #include <QJsonObject>
#endif


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

    colorKeys << "statusBar background color";
    colorLabels << "statusBar_background_color";
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
    QGridLayout* themeLayout = new QGridLayout;
    for(int i=0; i< colorKeys.length(); i++)
    {
        QLabel* label = new QLabel("<h4>" + colorKeys[i] + ":" + "</h4>");
        label->setObjectName("qssBuilderLabel");
        label->setFixedSize(280, 24);
        QLineEdit* lineedit = new QLineEdit(colorValues[i]);
        lineedit->setFixedSize(300, 24);
        QPushButton* button = new QPushButton;

        QString style = QString("QPushButton#setColor{background-color: %1;}");
        style = style.arg(colorValues[i]);
        button->setStyleSheet(style);
        button->setObjectName("setColor");
        button->setFixedSize(60, 24);
        lineedits.append(lineedit);
        buttons.append(button);

        themeLayout->addWidget(label, i, 0);
        themeLayout->addWidget(lineedit, i, 1);
        themeLayout->addWidget(button, i, 2);
        themeLayout->setColumnStretch(4, 1);

        colorMap[colorLabels[i]] = colorValues[i];
    }


    QLabel* iconLabel = new QLabel(tr("Icon color:"));
    QRadioButton* blackButton = new QRadioButton(tr("Balck"));
    QRadioButton* whiteButton = new QRadioButton(tr("White"));
    whiteButton->setChecked(true);
    QButtonGroup* iconGroup = new QButtonGroup;
    iconGroup->addButton(blackButton, 0);
    iconGroup->addButton(whiteButton, 1);
    connect(iconGroup, SIGNAL(buttonClicked(int)), this, SLOT(changeIconColor(int)));

    QGridLayout* previwerLayout = new QGridLayout;
    previwerLayout->addWidget(iconLabel, 0, 0);
    previwerLayout->addWidget(blackButton, 0, 1);
    previwerLayout->addWidget(whiteButton, 0, 2);
    previwerLayout->setColumnStretch(4, 1);
    previwerLayout->setRowStretch(1, 1);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(themeLayout);
//    mainLayout->addLayout(previwerLayout);
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
    updateTheme();
}

void QssBuilder::setButtonColor(QString color)
{
    currentIndex = lineedits.indexOf((QLineEdit*)sender());
    colorMap[colorLabels[currentIndex]] = color;
    QString style = QString("QPushButton#setColor{background-color: %1;}");
    style = style.arg(color);
    buttons.at(currentIndex)->setStyleSheet(style);
    updateTheme();
}

void QssBuilder::updateTheme()
{

//#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
//    QJsonDocument doc = QJsonDocument(QJsonObject::fromVariantMap(colorMap));
//    QFile outFile("customColor.json");
//    outFile.open(QIODevice::WriteOnly);
//    outFile.write(doc.toJson());
//    outFile.close();
//#endif

    QString qss = getQssFromFile(":/qss/skin/qss/template.qss");
    for(int i=0; i< colorLabels.length(); i++){
       qss.replace(colorLabels[i], colorMap[colorLabels[i]]);
    }
    qApp->setStyleSheet(qss);

    QFile outqssFile("test.qss");
    outqssFile.open(QIODevice::WriteOnly);
    outqssFile.write(qss.toStdString().data());
    outqssFile.close();
}


void QssBuilder::changeIconColor(int mode)
{
    QString qss = getQssFromFile(":/qss/skin/qss/template.qss");
    for(int i=0; i< colorLabels.length(); i++){
       qss.replace(colorLabels[i], colorMap[colorLabels[i]]);
    }

    if(mode == 0){
        qss.replace(QString(":/skin/icons/dark/"), QString(":/skin/icons/light/"));
    }else if(mode == 1){
        qss.replace(QString(":/skin/icons/light/"), QString(":/skin/icons/dark/"));
    }

    qApp->setStyleSheet(qss);
    QFile outqssFile("test.qss");
    outqssFile.open(QIODevice::WriteOnly);
    outqssFile.write(qss.toStdString().data());
    outqssFile.close();
}
