#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout;



    //costruzione leftbox
    leftbox = new LeftBox(this);
    layout->addWidget(leftbox);

    //costruzione rightbox
    rightbox = new RightBox(this);
    QHBoxLayout* rightlayout = new QHBoxLayout;
    rightlayout->addWidget(rightbox);
    QVBoxLayout* bottomlayout = new QVBoxLayout;
    bottomlayout->addLayout(rightlayout);
    bottombox = new BottomBox(this);
    bottomlayout->addWidget(bottombox);

    layout->addLayout(bottomlayout);

    //definizione layout finestra
    QSize bestsize(1000,600);
    setMaximumSize(bestsize);
    setMinimumSize(bestsize);
    setLayout(layout);

    connect(rightbox,SIGNAL(newColorOperand(int)),this,SIGNAL(newColorOperand(int)));
    connect(this,SIGNAL(setColorOperandMaxValues(uint)),rightbox,SLOT(setColorOperandMaxValues(uint)));
    connect(rightbox,SIGNAL(val1changed(int)),this,SIGNAL(val1changed(int)));
    connect(rightbox,SIGNAL(val2changed(int)),this,SIGNAL(val2changed(int)));
    connect(rightbox,SIGNAL(val3changed(int)),this,SIGNAL(val3changed(int)));
    connect(rightbox,SIGNAL(val4changed(int)),this,SIGNAL(val4changed(int)));
    connect(this,SIGNAL(setCol1Preview(QString)),rightbox,SIGNAL(setCol1Preview(QString)));
    connect(rightbox,SIGNAL(col1toOP1()),this,SIGNAL(col1toOP1()));
    connect(rightbox,SIGNAL(col1toOP2()),this,SIGNAL(col1toOP2()));
    connect(this,SIGNAL(setOP1(QString)),bottombox,SIGNAL(setOP1(QString)));
    connect(this,SIGNAL(setOP2(QString)),bottombox,SIGNAL(setOP2(QString)));
    connect(bottombox,SIGNAL(somma()),this,SIGNAL(somma()));
    connect(bottombox,SIGNAL(sottrai()),this,SIGNAL(sottrai()));
    connect(bottombox,SIGNAL(media()),this,SIGNAL(media()));
    connect(this,SIGNAL(setResult(QString)),bottombox,SIGNAL(setResult(QString)));

}

MainWindow::~MainWindow() {

}

