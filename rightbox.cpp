#include "rightbox.h"

RightBox::RightBox(QWidget *parent) : QWidget(parent)
{
    QGridLayout* rightboxlayout = new QGridLayout;

    colorSelector = new QComboBox(this);
    colorSelector->addItem(tr("RGB"));
    colorSelector->addItem(tr("CYMK"));
    rightboxlayout->addWidget(colorSelector,0,0,1,5);

    QLabel* lab1 = new QLabel("R",this);
    lab1->setMaximumWidth(20);
    rightboxlayout->addWidget(lab1,2,0,1,1);
    slid1 = new QSlider(Qt::Horizontal);
    rightboxlayout->addWidget(slid1,2,1,1,3);
    spin1 = new QSpinBox();
    rightboxlayout->addWidget(spin1,2,4);
    QLabel* lab2 = new QLabel("G",this);
    rightboxlayout->addWidget(lab2,3,0,1,1);
    slid2 = new QSlider(Qt::Horizontal);
    rightboxlayout->addWidget(slid2,3,1,1,3);
    spin2 = new QSpinBox();
    rightboxlayout->addWidget(spin2,3,4);
    QLabel* lab3 = new QLabel("B",this);
    rightboxlayout->addWidget(lab3,4,0,1,1);
    slid3 = new QSlider(Qt::Horizontal);
    rightboxlayout->addWidget(slid3,4,1,1,3);
    spin3 = new QSpinBox();
    rightboxlayout->addWidget(spin3,4,4);
    QLabel* lab4 = new QLabel("K",this);
    rightboxlayout->addWidget(lab4,5,0,1,1);
    slid4 = new QSlider(Qt::Horizontal);
    rightboxlayout->addWidget(slid4,5,1,1,3);
    spin4 = new QSpinBox();
    rightboxlayout->addWidget(spin4,5,4);
    QLCDNumber* hexlcd = new QLCDNumber;
    hexlcd->setMaximumHeight(35);
    rightboxlayout->addWidget(hexlcd,6,0,1,2);
    colorpreview = new QWidget(this);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    colorpreview->setAutoFillBackground(true);
    colorpreview->setPalette(pal);
    rightboxlayout->addWidget(colorpreview,6,2,1,2);




    setLayout(rightboxlayout);
}

