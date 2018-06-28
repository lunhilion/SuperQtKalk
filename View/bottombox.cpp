#include "bottombox.h"

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

    QLCDNumber* hexlcd1 = new QLCDNumber;
    hexlcd1->setMaximumHeight(35);
    layout->addWidget(hexlcd1,1,0,1,1);

    DrawBox* colorpreview1 = new DrawBox(this);
    layout->addWidget(colorpreview1,1,1,1,1);

    QComboBox* operandselector = new QComboBox(this);
    operandselector->addItem(tr("Somma"));
    operandselector->addItem(tr("Sottrazione"));
    operandselector->addItem(tr("Media"));
    layout->addWidget(operandselector,1,2,1,1);

    QLCDNumber* hexlcd2 = new QLCDNumber;
    hexlcd2->setMaximumHeight(35);
    layout->addWidget(hexlcd2,1,3,1,1);

    DrawBox* colorpreview2 = new DrawBox(this);
    layout->addWidget(colorpreview2,1,4,1,1);

    QPushButton* Bottomb1 = new QPushButton("Calcola",this);
    layout->addWidget(Bottomb1,2,1,1,3);

    QLabel* lab3 = new QLabel("Risultato:",this);
    lab3->setAlignment(Qt::AlignCenter);
    layout->addWidget(lab3,3,0,1,1);

    QLCDNumber* hexlcd3 = new QLCDNumber;
    hexlcd1->setMaximumHeight(35);
    layout->addWidget(hexlcd3,3,1,1,1);

    DrawBox* colorpreview3 = new DrawBox(this);
    layout->addWidget(colorpreview3,3,2,1,1);

    QPushButton* Bottomb2 = new QPushButton("Applica",this);
    layout->addWidget(Bottomb2,3,3,1,2);

    setFrameShape(QFrame::Box);
    setLineWidth(1);

    setLayout(layout);

}

