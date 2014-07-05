#ifndef PDFTOOL_H
#define PDFTOOL_H

#include <QWidget>
#include<QPushButton>
class PDFTool : public QWidget
{
    Q_OBJECT
public:
    QPushButton* pdfExport;
    QPushButton* pngExport;
public:
    explicit PDFTool(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();

signals:

public slots:
    void exportPDF();
    void exportPNG();
};

#endif // PDFTOOL_H
