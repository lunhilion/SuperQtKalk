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
    rightbox1 = new RightBox(this);
    rightbox2 = new RightBox(this);
    QHBoxLayout* rightlayout = new QHBoxLayout;
    rightlayout->addWidget(rightbox1);
    rightlayout->addWidget(rightbox2);
    QVBoxLayout* bottomlayout = new QVBoxLayout;
    bottomlayout->addLayout(rightlayout);
    bottombox = new BottomBox(this);
    bottomlayout->addWidget(bottombox);

    layout->addLayout(bottomlayout);


    //queste connect si devono occupare di tenere aggiornati i dati tra datamanager e vista





    //definizione layout finestra
    QSize bestsize(1200,600);
    setMaximumSize(bestsize);
    setMinimumSize(bestsize);
    setLayout(layout);

}

MainWindow::~MainWindow() {

}

