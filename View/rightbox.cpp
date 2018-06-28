#include "rightbox.h"

RightBox::RightBox(QWidget *parent) : QFrame(parent)
{
    QGridLayout* rightboxlayout = new QGridLayout;

    colorSelector = new QComboBox(this);
    colorSelector->addItem(tr("RGB"));
    colorSelector->addItem(tr("CYMK"));
    rightboxlayout->addWidget(colorSelector,0,0,1,5);

    val1 = new ValueSelector("R",this);
    rightboxlayout->addWidget(val1,1,0,1,5);
    val2 = new ValueSelector("G",this);
    rightboxlayout->addWidget(val2,2,0,1,5);
    val3 = new ValueSelector("B",this);
    rightboxlayout->addWidget(val3,3,0,1,5);
    val4 = new ValueSelector("K",this);
    rightboxlayout->addWidget(val4,4,0,1,5);
    val4->setVisible(false);

    QLCDNumber* hexlcd = new QLCDNumber;
    hexlcd->setMaximumHeight(35);
    rightboxlayout->addWidget(hexlcd,5,1,1,2);
    colorpreview = new DrawBox(this);
    colorpreview->setMinimumHeight(60);
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

    connect(colorSelector,SIGNAL(currentIndexChanged(int)),this,SLOT(setMode(int)));
}

void RightBox::setMode(int i) {
    if(i==0)
    {
        val1->setText("R");
        val2->setText("G");
        val3->setText("B");
        val4->setVisible(false);
    }
    else if (i==1)
    {
        val1->setText("C");
        val2->setText("M");
        val3->setText("Y");
        val4->setVisible(true);
    }
    else
    {
        //gestione errore
    }
}
