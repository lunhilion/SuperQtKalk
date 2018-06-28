#include "leftbox.h"

LeftBox::LeftBox(QWidget *parent) : QFrame(parent)
{
    QGridLayout* poligonPreview = new QGridLayout;

    poligonSelector = new QComboBox(this);
    poligonSelector->addItem(tr("Cerchio"));
    poligonSelector->addItem(tr("Triangolo"));
    poligonSelector->addItem(tr("Quadrato"));
    poligonPreview->addWidget(poligonSelector,0,0,1,4);
    drawbox = new DrawBox(this);
    poligonPreview->addWidget(drawbox,1,0,1,4);
    poligonPreview->setRowStretch(1,1);

    calcolaArea = new QPushButton("Calcola Area",this);
    poligonPreview->addWidget(calcolaArea,2,0,1,3);
    QLCDNumber* lcdArea = new QLCDNumber();
    poligonPreview->addWidget(lcdArea,2,3);

    calcolaPerimetro = new QPushButton("Calcola Perimetro",this);
    poligonPreview->addWidget(calcolaPerimetro,3,0,1,3);
    QLCDNumber* lcdPerimetro = new QLCDNumber();
    poligonPreview->addWidget(lcdPerimetro,3,3);

    calcolaBaricentro = new QPushButton("Trova Baricentro",this);
    poligonPreview->addWidget(calcolaBaricentro,4,0,1,3);

    calcolaLati = new QPushButton("Calcola Lunghezza Lati",this);
    poligonPreview->addWidget(calcolaLati,5,0,1,3);

    lcdLato1 = new QLCDNumber();
    lcdLato2 = new QLCDNumber();
    lcdLato3 = new QLCDNumber();
    lcdLato4 = new QLCDNumber();
    lcdLato1->setMaximumHeight(35);
    poligonPreview->addWidget(lcdLato1,6,0);
    poligonPreview->addWidget(lcdLato2,6,1);
    poligonPreview->addWidget(lcdLato3,6,2);
    poligonPreview->addWidget(lcdLato4,6,3);
    calcolaLati->setVisible(false);
    lcdLato1->setVisible(false);
    lcdLato2->setVisible(false);
    lcdLato3->setVisible(false);
    lcdLato4->setVisible(false);


    setLayout(poligonPreview);
    setGeometry(0,160,250,250);

    connect(poligonSelector,SIGNAL(currentIndexChanged(int)),this,SLOT(setMode(int)));
}

void LeftBox::setMode(int i){
    if(i==0)
    {
        calcolaLati->setVisible(false);
        lcdLato1->setVisible(false);
        lcdLato2->setVisible(false);
        lcdLato3->setVisible(false);
        lcdLato4->setVisible(false);

    }
    else if (i==1) {
        calcolaLati->setVisible(true);
        lcdLato1->setVisible(true);
        lcdLato2->setVisible(true);
        lcdLato3->setVisible(true);
        lcdLato4->setVisible(false);
    }
    else if (i==2) {
        calcolaLati->setVisible(true);
        lcdLato1->setVisible(true);
        lcdLato2->setVisible(true);
        lcdLato3->setVisible(true);
        lcdLato4->setVisible(true);

    }
}
