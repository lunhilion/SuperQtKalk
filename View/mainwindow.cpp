#include "mainwindow.h"

MainWindow::MainWindow(DataManager* datamanager, QWidget *parent) :
    dm(0),
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

}

MainWindow::~MainWindow() {

}

