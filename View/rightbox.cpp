#include "rightbox.h"

RightBox::RightBox(QWidget *parent) : QFrame(parent)
{
    QGridLayout* rightboxlayout = new QGridLayout;

    colorOperandMaxValue = 255;
    colorSelector = new QComboBox(this);
    colorSelector->addItem(tr("RGB"));
    colorSelector->addItem(tr("CMYK"));
    rightboxlayout->addWidget(colorSelector,0,0,1,5);

    val1 = new ValueSelector(this);
    val1->set("R",0,colorOperandMaxValue);
    rightboxlayout->addWidget(val1,1,0,1,5);
    val2 = new ValueSelector(this);
    val2->set("G",0,colorOperandMaxValue);
    rightboxlayout->addWidget(val2,2,0,1,5);
    val3 = new ValueSelector(this);
    val3->set("B",0,colorOperandMaxValue);
    rightboxlayout->addWidget(val3,3,0,1,5);
    val4 = new ValueSelector(this);
    val4->set("K",0,colorOperandMaxValue);
    rightboxlayout->addWidget(val4,4,0,1,5);
    val4->setVisible(false);

    hexlcd = new QLCDNumber(6);
    hexlcd->setMaximumHeight(35);
    hexlcd->setHexMode();
    hexlcd->display("000000");
    rightboxlayout->addWidget(hexlcd,5,1,1,2);
    colorpreview = new DrawBox(this);
    colorpreview->setMinimumHeight(60);
    colorpreview->repaintBackground("000000");
    rightboxlayout->addWidget(colorpreview,6,1,2,2);
    QPushButton* rightb1 = new QPushButton("Operando1",this);
    rightboxlayout->addWidget(rightb1,5,3,1,2);
    QPushButton* rightb2 = new QPushButton("Operando 2",this);
    rightboxlayout->addWidget(rightb2,6,3,1,2);
    QPushButton* rightb3 = new QPushButton("Applica",this);
    rightboxlayout->addWidget(rightb3,7,3,1,2);


    setLayout(rightboxlayout);
    setFrameShape(QFrame::Box);
    setLineWidth(1);

    connect(colorSelector,SIGNAL(currentIndexChanged(int)),this,SIGNAL(newColorOperand(int)));
    connect(colorSelector,SIGNAL(currentIndexChanged(int)),this,SLOT(setMode(int)));
    connect(colorSelector,SIGNAL(currentIndexChanged(int)),this,SIGNAL(val1changed(int)));
    connect(val1,SIGNAL(valueChanged(int)),this,SIGNAL(val1changed(int)));
    connect(val2,SIGNAL(valueChanged(int)),this,SIGNAL(val2changed(int)));
    connect(val3,SIGNAL(valueChanged(int)),this,SIGNAL(val3changed(int)));
    connect(val4,SIGNAL(valueChanged(int)),this,SIGNAL(val4changed(int)));
    connect(this,SIGNAL(setCol1Preview(QString)),hexlcd,SLOT(display(QString)));
    connect(this, SIGNAL(setCol1Preview(QString)),colorpreview,SLOT(repaintBackground(QString)));
    connect(rightb1,SIGNAL(clicked()),this,SIGNAL(col1toOP1()));
    connect(rightb2,SIGNAL(clicked()),this,SIGNAL(col1toOP2()));
}

void RightBox::setMode(int i) {
    if(i==0)
    {
        val1->set("R",0,colorOperandMaxValue);
        val2->set("G",0,colorOperandMaxValue);
        val3->set("B",0,colorOperandMaxValue);
        val4->setVisible(false);
    }
    else if (i==1)
    {
        val1->set("C",0,colorOperandMaxValue);
        val2->set("M",0,colorOperandMaxValue);
        val3->set("Y",0,colorOperandMaxValue);
        val4->set("K",0,colorOperandMaxValue);
        val4->setVisible(true);
    }
    else
    {
        //gestione errore
    }
}

void RightBox::setColorOperandMaxValues(uint i) {
    colorOperandMaxValue = i;
}
