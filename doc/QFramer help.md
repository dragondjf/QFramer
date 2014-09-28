QFramer help 
===============================================
#####1.How to use QFramer in your project?
+ 1.**`New`** a Qt project in your Qt Creater IDE;
+ 2.**`Copy`** directory **【QFramer】** to your project folder, add `include(./QFramer/QFramer.pri)` in your **.pro** file

    So you can use QFramer in your code like this:  

        #include "QFramer/fcenterwindow.h"

#####2. How to use QFramer in your code?


+ 1. custom your mainwindow inherited by `FMainWindow`
     define an `centerwindow` variable and ** `setCentralWidget(centerwindow)`**  

`mainwindow.h`

        #ifndef MAINWINDOW_H
        #define MAINWINDOW_H
        
        #include "QFramer/fmainwindow.h"
        #include "centerwindow.h"
        
        class MainWindow : public FMainWindow
        {
            Q_OBJECT
        public:
            CenterWindow* centerWindow;
        public:
            explicit MainWindow(QWidget *parent = 0);
            void initUI();
        signals:
        
        public slots:
        
        };

`mainwindow.cpp`
        #include "mainwindow.h"
        #include "centerwindow.h"

        
        MainWindow::MainWindow(QWidget *parent) :
            FMainWindow(parent)
        {
            initUI();
        }
        
        
        void MainWindow::initUI()
        {
            centerWindow = new CenterWindow;
            setCentralWidget(centerWindow);
        }


+ 2. custom your centerwindow inherited by `FCenterWindow`
     + custom your widgets like  `uiElements` `mathPlot` `aboutPage` `qssBuilder`
     + use the api  `addWidget` to add your custom widget in centerwindow
        `addWidget(tr("Home"), tr("Home"), uiElements);`

`centerwindow.h`

        #ifndef CENTERWINDOW_H
        #define CENTERWINDOW_H
        
        #include "QFramer/fcenterwindow.h"
        #include "functionpages/aboutpage.h"
        #include "functionpages/mathplot.h"
        #include "functionpages/uielement.h"
        #include "functionpages/qssbuilder.h"
        #include <QVBoxLayout>
        
        
        class CenterWindow : public FCenterWindow
        {
            Q_OBJECT
        
        public:
            UIElement* uiElements;
            MathPlot* mathPlot;
            AboutPage* aboutPage;
            QssBuilder* qssBuilder;
        
        public:
            explicit CenterWindow(QWidget *parent = 0);
            void initUI();
        signals:
        
        public slots:
        };
        
        #endif // CENTERWINDOW_H
        
`centerwindow.cpp`

        #include "centerwindow.h"
        
        
        CenterWindow::CenterWindow(QWidget *parent) :
            FCenterWindow(parent)
        {
            initUI();
        }
        
        void CenterWindow::initUI()
        {
            uiElements = new UIElement;
            mathPlot = new MathPlot;
            aboutPage = new AboutPage;
            qssBuilder = new QssBuilder;
        
            addWidget(tr("Home"), tr("Home"), uiElements);
            addWidget(tr("MathPlot"),tr("MathPlot"), mathPlot);
        
            addWidget(tr("QssBuilder"),tr("QssBuilder"), qssBuilder);
            addWidget(tr("About"),tr("About"), aboutPage);
        
            setAlignment(TopCenter);
        }

So easy, this is the basic usage with QFramer, you can enjoy with it.If you want to go deep into it, you should read code seriously  in a moment.
