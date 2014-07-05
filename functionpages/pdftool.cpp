#include "pdftool.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPrinter>
#include<QPainter>
#include<QDir>
#include<QDebug>
PDFTool::PDFTool(QWidget *parent) :
    QWidget(parent)
{
    initData();
    initUI();
    initConnect();
}

void PDFTool::initData()
{

}

void PDFTool::initUI()
{
    pdfExport = new QPushButton(tr("Export PDF"));
    pngExport = new QPushButton(tr("Export PNG"));

    QVBoxLayout* controlLayout = new QVBoxLayout;
    controlLayout->addWidget(pdfExport);
    controlLayout->addWidget(pngExport);

    QHBoxLayout* mainLayout= new QHBoxLayout;
    mainLayout->addLayout(controlLayout);
    mainLayout->addStretch();
    setLayout(mainLayout);
}

void PDFTool::initConnect()
{
    connect(pdfExport, SIGNAL(clicked()), this, SLOT(exportPDF()));
    connect(pngExport, SIGNAL(clicked()), this, SLOT(exportPNG()));
}

void PDFTool::exportPDF()
{
    QPrinter printer_pixmap(QPrinter::HighResolution);
    printer_pixmap.setPageSize(QPrinter::A4);  //设置纸张大小为A4
    printer_pixmap.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
    printer_pixmap.setOutputFileName(QString("%1/doc/test.pdf").arg(QDir::currentPath()));   //设置输出路径
    QPixmap pixmap = this->grab(this->geometry());  //获取界面的图片
    qDebug(qPrintable(QString("%1/doc/test.pdf").arg(QDir::currentPath())));
    QPainter painter_pixmap;
    painter_pixmap.begin(&printer_pixmap);
    QRect rect = painter_pixmap.viewport();
    int multiple = rect.width()/pixmap.width();
    painter_pixmap.scale(multiple, multiple); //将图像(所有要画的东西)在pdf上放大multiple-1倍
    painter_pixmap.drawPixmap(0, 0, pixmap);  //画图
    painter_pixmap.end();
}

void PDFTool::exportPNG()
{

}
