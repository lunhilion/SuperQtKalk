#include "bottombox.h"
#include "Exception/kalkexception.h"

BottomBox::BottomBox(QWidget *parent) : QFrame(parent)
{
    QGridLayout* layout = new QGridLayout;

    QLabel* lab1 = new QLabel("Operando 1:",this);
    layout->addWidget(lab1,0,0,1,2);
    lab1->setMaximumHeight(20);
    lab1->setAlignment(Qt::AlignCenter);

    QLabel* lab2 = new QLabel("Operando 2:",this);
    layout->addWidget(lab2,0,3,1,2);
    lab2->setAlignment(Qt::AlignCenter);

    hexlcd1 = new QLCDNumber(6);
    hexlcd1->setHexMode();
    hexlcd1->display("FFFFFF");
    hexlcd1->setMaximumHeight(35);
    layout->addWidget(hexlcd1,1,0,1,1);

    colorpreview1 = new ColorBox(this);
    layout->addWidget(colorpreview1,1,1,1,1);

    operandselector = new QComboBox(this);
    operandselector->addItem(tr("Somma"));
    operandselector->addItem(tr("Sottrazione"));
    operandselector->addItem(tr("Media"));
    layout->addWidget(operandselector,1,2,1,1);

    hexlcd2 = new QLCDNumber(6);
    hexlcd2->setHexMode();
    hexlcd2->display("FFFFFF");
    hexlcd2->setMaximumHeight(35);
    layout->addWidget(hexlcd2,1,3,1,1);

    colorpreview2 = new ColorBox(this);
    layout->addWidget(colorpreview2,1,4,1,1);

    QPushButton* bottomb1 = new QPushButton("Calcola",this);
    layout->addWidget(bottomb1,2,1,1,3);

    QLabel* lab3 = new QLabel("Risultato:",this);
    lab3->setAlignment(Qt::AlignCenter);
    layout->addWidget(lab3,3,0,1,1);

    hexlcd3 = new QLCDNumber(6);
    hexlcd3->setHexMode();
    hexlcd3->display("FFFFFF");
    hexlcd3->setMaximumHeight(35);
    layout->addWidget(hexlcd3,3,1,1,1);

    colorpreview3 = new ColorBox(this);
    layout->addWidget(colorpreview3,3,2,1,1);

    QPushButton* bottomb2 = new QPushButton("Applica",this);
    layout->addWidget(bottomb2,3,3,1,2);

    setFrameShape(QFrame::Box);
    setLineWidth(1);

    setLayout(layout);

    connect(this,SIGNAL(setOP1(QString)),hexlcd1,SLOT(display(QString)));
    connect(this,SIGNAL(setOP2(QString)),hexlcd2,SLOT(display(QString)));
    connect(this, SIGNAL(setOP1(QString)),colorpreview1,SLOT(repaintBackground(QString)));
    connect(this, SIGNAL(setOP2(QString)),colorpreview2,SLOT(repaintBackground(QString)));
    connect(bottomb1,SIGNAL(clicked()),this,SLOT(operationRouting()));
    connect(this,SIGNAL(setResult(QString)),hexlcd3,SLOT(display(QString)));
    connect(this,SIGNAL(setResult(QString)),colorpreview3,SLOT(repaintBackground(QString)));
    connect(bottomb2,SIGNAL(clicked()),this,SIGNAL(colorResulttoPolygonColor()));

}

void BottomBox::operationRouting() {
    try {
        if(operandselector->currentIndex()==0)
            emit(somma());
        else if(operandselector->currentIndex()==1)
            emit(sottrai());
        else if(operandselector->currentIndex()==2)
            emit(media());
        else
            throw ViewUndefValue("Indice operazione non valido. Operazione impostata a Somma.");
    }
    catch(KalkException k) {
        emit(somma());
        k.printError();
    }

}

BottomBox::~BottomBox() {
    delete operandselector;
    delete hexlcd1;
    delete hexlcd2;
    delete hexlcd3;
    delete colorpreview1;
    delete colorpreview2;
    delete colorpreview3;
}


