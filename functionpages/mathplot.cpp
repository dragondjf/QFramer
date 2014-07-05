#include "mathplot.h"
#include<QGridLayout>
#include<QLinearGradient>
MathPlot::MathPlot(QWidget *parent) :
    QWidget(parent)
{
    FCustomPlot *plot1 = new FCustomPlot;
    FCustomPlot *plot2 = new FCustomPlot;
    FCustomPlot *plot3 = new FCustomPlot;
    FCustomPlot *plot4 = new FCustomPlot;
    FCustomPlot *plot5 = new FCustomPlot;
    FCustomPlot *plot6 = new FCustomPlot;
    FCustomPlot *plot7 = new FCustomPlot;
    FCustomPlot *plot8 = new FCustomPlot;
    FCustomPlot *plot9 = new FCustomPlot;

    setupQuadraticDemo(plot1);
    setupSimpleDemo(plot2);
    setupSincScatterDemo(plot3);
    setupScatterStyleDemo(plot4);
    setupLineStyleDemo(plot5);
    setupScatterPixmapDemo(plot6);
    setupDateDemo(plot7);
    setupTextureBrushDemo(plot8);
    setupMultiAxisDemo(plot9);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(plot1, 0, 0);
    mainLayout->addWidget(plot2, 0, 1);
    mainLayout->addWidget(plot3, 0, 2);
    mainLayout->addWidget(plot4, 1, 0);
    mainLayout->addWidget(plot5, 1, 1);
    mainLayout->addWidget(plot6, 1, 2);
    mainLayout->addWidget(plot7, 2, 0);
    mainLayout->addWidget(plot8, 2, 1);
    mainLayout->addWidget(plot9, 2, 2);
    setLayout(mainLayout);
}


void MathPlot::setupQuadraticDemo(QCustomPlot *customPlot)
{
//    demoName = "Quadratic Demo";
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i];  // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
}

void MathPlot::setupSimpleDemo(QCustomPlot *customPlot)
{

  // add two new graphs and set their look:
  customPlot->addGraph();
  customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
  customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
  customPlot->addGraph();
  customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
  // generate some points of data (y0 for first, y1 for second graph):
  QVector<double> x(250), y0(250), y1(250);
  for (int i=0; i<250; ++i)
  {
    x[i] = i;
    y0[i] = exp(-i/150.0)*cos(i/10.0); // exponentially decaying cosine
    y1[i] = exp(-i/150.0);             // exponential envelope
  }
  // configure right and top axis to show ticks but no labels:
  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
  customPlot->xAxis2->setVisible(true);
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setVisible(true);
  customPlot->yAxis2->setTickLabels(false);
  // make left and bottom axes always transfer their ranges to right and top axes:
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
  // pass data points to graphs:
  customPlot->graph(0)->setData(x, y0);
  customPlot->graph(1)->setData(x, y1);
  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
  customPlot->graph(0)->rescaleAxes();
  // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
  customPlot->graph(1)->rescaleAxes(true);
  // Note: we could have also just called customPlot->rescaleAxes(); instead
  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void MathPlot::setupSincScatterDemo(QCustomPlot *customPlot)
{

  customPlot->legend->setVisible(true);
  customPlot->legend->setFont(QFont("Helvetica",9));
  // set locale to english, so we get english decimal separator:
  customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
  // add confidence band graphs:
  customPlot->addGraph();
  QPen pen;
  pen.setStyle(Qt::DotLine);
  pen.setWidth(1);
  pen.setColor(QColor(180,180,180));
  customPlot->graph(0)->setName("Confidence Band 68%");
  customPlot->graph(0)->setPen(pen);
  customPlot->graph(0)->setBrush(QBrush(QColor(255,50,30,20)));
  customPlot->addGraph();
  customPlot->legend->removeItem(customPlot->legend->itemCount()-1); // don't show two confidence band graphs in legend
  customPlot->graph(1)->setPen(pen);
  customPlot->graph(0)->setChannelFillGraph(customPlot->graph(1));
  // add theory curve graph:
  customPlot->addGraph();
  pen.setStyle(Qt::DashLine);
  pen.setWidth(2);
  pen.setColor(Qt::red);
  customPlot->graph(2)->setPen(pen);
  customPlot->graph(2)->setName("Theory Curve");
  // add data point graph:
  customPlot->addGraph();
  customPlot->graph(3)->setPen(QPen(Qt::blue));
  customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
  customPlot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 4));
  customPlot->graph(3)->setErrorType(QCPGraph::etValue);
  customPlot->graph(3)->setErrorPen(QPen(QColor(180,180,180)));
  customPlot->graph(3)->setName("Measurement");

  // generate ideal sinc curve data and some randomly perturbed data for scatter plot:
  QVector<double> x0(250), y0(250);
  QVector<double> yConfUpper(250), yConfLower(250);
  for (int i=0; i<250; ++i)
  {
    x0[i] = (i/249.0-0.5)*30+0.01; // by adding a small offset we make sure not do divide by zero in next code line
    y0[i] = sin(x0[i])/x0[i]; // sinc function
    yConfUpper[i] = y0[i]+0.15;
    yConfLower[i] = y0[i]-0.15;
    x0[i] *= 1000;
  }
  QVector<double> x1(50), y1(50), y1err(50);
  for (int i=0; i<50; ++i)
  {
    // generate a gaussian distributed random number:
    double tmp1 = rand()/(double)RAND_MAX;
    double tmp2 = rand()/(double)RAND_MAX;
    double r = sqrt(-2*log(tmp1))*cos(2*M_PI*tmp2); // box-muller transform for gaussian distribution
    // set y1 to value of y0 plus a random gaussian pertubation:
    x1[i] = (i/50.0-0.5)*30+0.25;
    y1[i] = sin(x1[i])/x1[i]+r*0.15;
    x1[i] *= 1000;
    y1err[i] = 0.15;
  }
  // pass data to graphs and let QCustomPlot determine the axes ranges so the whole thing is visible:
  customPlot->graph(0)->setData(x0, yConfUpper);
  customPlot->graph(1)->setData(x0, yConfLower);
  customPlot->graph(2)->setData(x0, y0);
  customPlot->graph(3)->setDataValueError(x1, y1, y1err);
  customPlot->graph(2)->rescaleAxes();
  customPlot->graph(3)->rescaleAxes(true);
  // setup look of bottom tick labels:
  customPlot->xAxis->setTickLabelRotation(30);
  customPlot->xAxis->setAutoTickCount(9);
  customPlot->xAxis->setNumberFormat("ebc");
  customPlot->xAxis->setNumberPrecision(1);
  customPlot->xAxis->moveRange(-10);
  // make top right axes clones of bottom left axes. Looks prettier:
  customPlot->axisRect()->setupFullAxesBox();
}

void MathPlot::setupScatterStyleDemo(QCustomPlot *customPlot)
{

  customPlot->legend->setVisible(true);
  customPlot->legend->setFont(QFont("Helvetica", 9));
  customPlot->legend->setRowSpacing(-3);
  QVector<QCPScatterStyle::ScatterShape> shapes;
  shapes << QCPScatterStyle::ssCross;
  shapes << QCPScatterStyle::ssPlus;
  shapes << QCPScatterStyle::ssCircle;
  shapes << QCPScatterStyle::ssDisc;
  shapes << QCPScatterStyle::ssSquare;
  shapes << QCPScatterStyle::ssDiamond;
  shapes << QCPScatterStyle::ssStar;
  shapes << QCPScatterStyle::ssTriangle;
  shapes << QCPScatterStyle::ssTriangleInverted;
  shapes << QCPScatterStyle::ssCrossSquare;
  shapes << QCPScatterStyle::ssPlusSquare;
  shapes << QCPScatterStyle::ssCrossCircle;
  shapes << QCPScatterStyle::ssPlusCircle;
  shapes << QCPScatterStyle::ssPeace;
  shapes << QCPScatterStyle::ssCustom;

  QPen pen;
  // add graphs with different scatter styles:
  for (int i=0; i<shapes.size(); ++i)
  {
    customPlot->addGraph();
    pen.setColor(QColor(sin(i*0.3)*100+100, sin(i*0.6+0.7)*100+100, sin(i*0.4+0.6)*100+100));
    // generate data:
    QVector<double> x(10), y(10);
    for (int k=0; k<10; ++k)
    {
      x[k] = k/10.0 * 4*3.14 + 0.01;
      y[k] = 7*sin(x[k])/x[k] + (shapes.size()-i)*5;
    }
    customPlot->graph()->setData(x, y);
    customPlot->graph()->rescaleAxes(true);
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setName(QCPScatterStyle::staticMetaObject.enumerator(QCPScatterStyle::staticMetaObject.indexOfEnumerator("ScatterShape")).valueToKey(shapes.at(i)));
    customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    // set scatter style:
    if (shapes.at(i) != QCPScatterStyle::ssCustom)
    {
      customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(i), 10));
    }
    else
    {
      QPainterPath customScatterPath;
      for (int i=0; i<3; ++i)
        customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
      customPlot->graph()->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(), QColor(40, 70, 255, 50), 10));
    }
  }
  // set blank axis lines:
  customPlot->rescaleAxes();
  customPlot->xAxis->setTicks(false);
  customPlot->yAxis->setTicks(false);
  customPlot->xAxis->setTickLabels(false);
  customPlot->yAxis->setTickLabels(false);
  // make top right axes clones of bottom left axes:
  customPlot->axisRect()->setupFullAxesBox();
}

void MathPlot::setupLineStyleDemo(QCustomPlot *customPlot)
{

  customPlot->legend->setVisible(true);
  customPlot->legend->setFont(QFont("Helvetica", 9));
  QPen pen;
  QStringList lineNames;
  lineNames << "lsNone" << "lsLine" << "lsStepLeft" << "lsStepRight"
               << "lsStepCenter" << "lsImpulse";
  // add graphs with different line styles:
  for (int i=QCPGraph::lsNone; i<=QCPGraph::lsImpulse; ++i)
  {
    customPlot->addGraph();
    pen.setColor(QColor(sin(i*1+1.2)*80+80, sin(i*0.3+0)*80+80, sin(i*0.3+1.5)*80+80));
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
    customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    // generate data:
    QVector<double> x(15), y(15);
    for (int j=0; j<15; ++j)
    {
      x[j] = j/15.0 * 5*3.14 + 0.01;
      y[j] = 7*sin(x[j])/x[j] - (i-QCPGraph::lsNone)*5 + (QCPGraph::lsImpulse)*5 + 2;
    }
    customPlot->graph()->setData(x, y);
    customPlot->graph()->rescaleAxes(true);
  }
  // zoom out a bit:
  customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
  customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
  // set blank axis lines:
  customPlot->xAxis->setTicks(false);
  customPlot->yAxis->setTicks(true);
  customPlot->xAxis->setTickLabels(false);
  customPlot->yAxis->setTickLabels(true);
  // make top right axes clones of bottom left axes:
  customPlot->axisRect()->setupFullAxesBox();
}

void MathPlot::setupScatterPixmapDemo(QCustomPlot *customPlot)
{

  customPlot->axisRect()->setBackground(QPixmap("./solarpanels.jpg"));
  customPlot->addGraph();
  customPlot->graph()->setLineStyle(QCPGraph::lsLine);
  QPen pen;
  pen.setColor(QColor(255, 200, 20, 200));
  pen.setStyle(Qt::DashLine);
  pen.setWidthF(2.5);
  customPlot->graph()->setPen(pen);
  customPlot->graph()->setBrush(QBrush(QColor(255,200,20,70)));
  customPlot->graph()->setScatterStyle(QCPScatterStyle(QPixmap("./sun.png")));
  // set graph name, will show up in legend next to icon:
  customPlot->graph()->setName("Data from Photovoltaic\nenergy barometer 2011");
  // set data:
  QVector<double> year, value;
  year  << 2005 << 2006 << 2007 << 2008  << 2009  << 2010;
  value << 2.17 << 3.42 << 4.94 << 10.38 << 15.86 << 29.33;
  customPlot->graph()->setData(year, value);

  // set title of plot:
  customPlot->plotLayout()->insertRow(0);
  customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, "Regenerative Energies"));
  // set a fixed tick-step to one tick per year value:
  customPlot->xAxis->setAutoTickStep(false);
  customPlot->xAxis->setTickStep(1);
  customPlot->xAxis->setSubTickCount(3);
  // other axis configurations:
  customPlot->xAxis->setLabel("Year");
  customPlot->yAxis->setLabel("Installed Gigawatts of\nphotovoltaic in the European Union");
  customPlot->xAxis2->setVisible(true);
  customPlot->yAxis2->setVisible(true);
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setTickLabels(false);
  customPlot->xAxis2->setTicks(false);
  customPlot->yAxis2->setTicks(false);
  customPlot->xAxis2->setSubTickCount(0);
  customPlot->yAxis2->setSubTickCount(0);
  customPlot->xAxis->setRange(2004.5, 2010.5);
  customPlot->yAxis->setRange(0, 30);
  // setup legend:
  customPlot->legend->setFont(QFont(font().family(), 7));
  customPlot->legend->setIconSize(50, 20);
  customPlot->legend->setVisible(true);
}

void MathPlot::setupDateDemo(QCustomPlot *customPlot)
{
  // set locale to english, so we get english month names:
  customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
  // seconds of current time, we'll use it as starting point in time for data:
  double now = QDateTime::currentDateTime().toTime_t();
  srand(8); // set the random seed, so we always get the same random data
  // create multiple graphs:
  for (int gi=0; gi<5; ++gi)
  {
    customPlot->addGraph();
    QPen pen;
    pen.setColor(QColor(0, 0, 255, 200));
    customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setBrush(QBrush(QColor(255/4.0*gi,160,50,150)));
    // generate random walk data:
    QVector<double> time(250), value(250);
    for (int i=0; i<250; ++i)
    {
      time[i] = now + 24*3600*i;
      if (i == 0)
        value[i] = (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      else
        value[i] = fabs(value[i-1])*(1+0.02/4.0*(4-gi)) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
    }
    customPlot->graph()->setData(time, value);
  }
  // configure bottom axis to show date and time instead of number:
  customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
  customPlot->xAxis->setDateTimeFormat("MMMM\nyyyy");
  // set a more compact font size for bottom and left axis tick labels:
  customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
  customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
  // set a fixed tick-step to one tick per month:
  customPlot->xAxis->setAutoTickStep(false);
  customPlot->xAxis->setTickStep(2628000); // one month in seconds
  customPlot->xAxis->setSubTickCount(3);
  // apply manual tick and tick label for left axis:
  customPlot->yAxis->setAutoTicks(false);
  customPlot->yAxis->setAutoTickLabels(false);
  customPlot->yAxis->setTickVector(QVector<double>() << 5 << 55);
  customPlot->yAxis->setTickVectorLabels(QVector<QString>() << "Not so\nhigh" << "Very\nhigh");
  // set axis labels:
  customPlot->xAxis->setLabel("Date");
  customPlot->yAxis->setLabel("Random wobbly lines value");
  // make top and right axes visible but without ticks and labels:
  customPlot->xAxis2->setVisible(true);
  customPlot->yAxis2->setVisible(true);
  customPlot->xAxis2->setTicks(false);
  customPlot->yAxis2->setTicks(false);
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setTickLabels(false);
  // set axis ranges to show all data:
  customPlot->xAxis->setRange(now, now+24*3600*249);
  customPlot->yAxis->setRange(0, 60);
  // show legend:
  customPlot->legend->setVisible(true);
}

void MathPlot::setupTextureBrushDemo(QCustomPlot *customPlot)
{
  // add two graphs with a textured fill:
  customPlot->addGraph();
  QPen redDotPen;
  redDotPen.setStyle(Qt::DotLine);
  redDotPen.setColor(QColor(170, 100, 100, 180));
  redDotPen.setWidthF(2);
  customPlot->graph(0)->setPen(redDotPen);
  customPlot->graph(0)->setBrush(QBrush(QPixmap("://skin/images/balboa.jpg"))); // fill with texture of specified image

  customPlot->addGraph();
  customPlot->graph(1)->setPen(QPen(Qt::red));

  // activate channel fill for graph 0 towards graph 1:
  customPlot->graph(0)->setChannelFillGraph(customPlot->graph(1));

  // generate data:
  QVector<double> x(250);
  QVector<double> y0(250), y1(250);
  for (int i=0; i<250; ++i)
  {
    // just playing with numbers, not much to learn here
    x[i] = 3*i/250.0;
    y0[i] = 1+exp(-x[i]*x[i]*0.8)*(x[i]*x[i]+x[i]);
    y1[i] = 1-exp(-x[i]*x[i]*0.4)*(x[i]*x[i])*0.1;
  }

  // pass data points to graphs:
  customPlot->graph(0)->setData(x, y0);
  customPlot->graph(1)->setData(x, y1);
  // activate top and right axes, which are invisible by default:
  customPlot->xAxis2->setVisible(true);
  customPlot->yAxis2->setVisible(true);
  // make tick labels invisible on top and right axis:
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setTickLabels(false);
  // set ranges:
  customPlot->xAxis->setRange(0, 2.5);
  customPlot->yAxis->setRange(0.9, 1.6);
  // assign top/right axes same properties as bottom/left:
  customPlot->axisRect()->setupFullAxesBox();
}

void MathPlot::setupMultiAxisDemo(QCustomPlot *customPlot)
{
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

  customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
  customPlot->legend->setVisible(true);
  QFont legendFont = font();  // start out with MainWindow's font..
  legendFont.setPointSize(9); // and make a bit smaller for legend
  customPlot->legend->setFont(legendFont);
  customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
  // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
  customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

  // setup for graph 0: key axis left, value axis bottom
  // will contain left maxwell-like function
  customPlot->addGraph(customPlot->yAxis, customPlot->xAxis);
  customPlot->graph(0)->setPen(QPen(QColor(255, 100, 0)));
  customPlot->graph(0)->setBrush(QBrush(QPixmap("://skin/images/balboa.jpg"))); // fill with texture of specified image
  customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
  customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
  customPlot->graph(0)->setName("Left maxwell function");

  // setup for graph 1: key axis bottom, value axis left (those are the default axes)
  // will contain bottom maxwell-like function
  customPlot->addGraph();
  customPlot->graph(1)->setPen(QPen(Qt::red));
  customPlot->graph(1)->setBrush(QBrush(QPixmap("://skin/images/balboa.jpg"))); // same fill as we used for graph 0
  customPlot->graph(1)->setLineStyle(QCPGraph::lsStepCenter);
  customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
  customPlot->graph(1)->setErrorType(QCPGraph::etValue);
  customPlot->graph(1)->setName("Bottom maxwell function");

  // setup for graph 2: key axis top, value axis right
  // will contain high frequency sine with low frequency beating:
  customPlot->addGraph(customPlot->xAxis2, customPlot->yAxis2);
  customPlot->graph(2)->setPen(QPen(Qt::blue));
  customPlot->graph(2)->setName("High frequency sine");

  // setup for graph 3: same axes as graph 2
  // will contain low frequency beating envelope of graph 2
  customPlot->addGraph(customPlot->xAxis2, customPlot->yAxis2);
  QPen blueDotPen;
  blueDotPen.setColor(QColor(30, 40, 255, 150));
  blueDotPen.setStyle(Qt::DotLine);
  blueDotPen.setWidthF(4);
  customPlot->graph(3)->setPen(blueDotPen);
  customPlot->graph(3)->setName("Sine envelope");

  // setup for graph 4: key axis right, value axis top
  // will contain parabolically distributed data points with some random perturbance
  customPlot->addGraph(customPlot->yAxis2, customPlot->xAxis2);
  customPlot->graph(4)->setPen(QColor(50, 50, 50, 255));
  customPlot->graph(4)->setLineStyle(QCPGraph::lsNone);
  customPlot->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
  customPlot->graph(4)->setName("Some random data around\na quadratic function");

  // generate data, just playing with numbers, not much to learn here:
  QVector<double> x0(25), y0(25);
  QVector<double> x1(15), y1(15), y1err(15);
  QVector<double> x2(250), y2(250);
  QVector<double> x3(250), y3(250);
  QVector<double> x4(250), y4(250);
  for (int i=0; i<25; ++i) // data for graph 0
  {
    x0[i] = 3*i/25.0;
    y0[i] = exp(-x0[i]*x0[i]*0.8)*(x0[i]*x0[i]+x0[i]);
  }
  for (int i=0; i<15; ++i) // data for graph 1
  {
    x1[i] = 3*i/15.0;;
    y1[i] = exp(-x1[i]*x1[i])*(x1[i]*x1[i])*2.6;
    y1err[i] = y1[i]*0.25;
  }
  for (int i=0; i<250; ++i) // data for graphs 2, 3 and 4
  {
    x2[i] = i/250.0*3*M_PI;
    x3[i] = x2[i];
    x4[i] = i/250.0*100-50;
    y2[i] = sin(x2[i]*12)*cos(x2[i])*10;
    y3[i] = cos(x3[i])*10;
    y4[i] = 0.01*x4[i]*x4[i] + 1.5*(rand()/(double)RAND_MAX-0.5) + 1.5*M_PI;
  }

  // pass data points to graphs:
  customPlot->graph(0)->setData(x0, y0);
  customPlot->graph(1)->setDataValueError(x1, y1, y1err);
  customPlot->graph(2)->setData(x2, y2);
  customPlot->graph(3)->setData(x3, y3);
  customPlot->graph(4)->setData(x4, y4);
  // activate top and right axes, which are invisible by default:
  customPlot->xAxis2->setVisible(true);
  customPlot->yAxis2->setVisible(true);
  // set ranges appropriate to show data:
  customPlot->xAxis->setRange(0, 2.7);
  customPlot->yAxis->setRange(0, 2.6);
  customPlot->xAxis2->setRange(0, 3.0*M_PI);
  customPlot->yAxis2->setRange(-70, 35);
  // set pi ticks on top axis:
  QVector<double> piTicks;
  QVector<QString> piLabels;
  piTicks << 0  << 0.5*M_PI << M_PI << 1.5*M_PI << 2*M_PI << 2.5*M_PI << 3*M_PI;
  piLabels << "0" << QString::fromUtf8("½π") << QString::fromUtf8("π") << QString::fromUtf8("1½π") << QString::fromUtf8("2π") << QString::fromUtf8("2½π") << QString::fromUtf8("3π");
  customPlot->xAxis2->setAutoTicks(false);
  customPlot->xAxis2->setAutoTickLabels(false);
  customPlot->xAxis2->setTickVector(piTicks);
  customPlot->xAxis2->setTickVectorLabels(piLabels);
  // add title layout element:
  customPlot->plotLayout()->insertRow(0);
  customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, "Way too many graphs in one plot"));
  // set labels:
  customPlot->xAxis->setLabel("Bottom axis with outward ticks");
  customPlot->yAxis->setLabel("Left axis label");
  customPlot->xAxis2->setLabel("Top axis label");
  customPlot->yAxis2->setLabel("Right axis label");
  // make ticks on bottom axis go outward:
  customPlot->xAxis->setTickLength(0, 5);
  customPlot->xAxis->setSubTickLength(0, 3);
  // make ticks on right axis go inward and outward:
  customPlot->yAxis2->setTickLength(3, 3);
  customPlot->yAxis2->setSubTickLength(1, 1);
}
