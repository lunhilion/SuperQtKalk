#include "leftbox.h"

LeftBox::LeftBox(QWidget *parent) : QFrame(parent)
{
    QGridLayout* polygonPreview = new QGridLayout;

    polygonSelector = new QComboBox(this);
    polygonSelector->addItem(tr("Cerchio"));
    polygonSelector->addItem(tr("Triangolo"));
    polygonSelector->addItem(tr("Quadrato"));
    polygonPreview->addWidget(polygonSelector,0,0,1,4);

    drawbox = new DrawBox(this);
    polygonPreview->addWidget(drawbox,1,0,1,4);
    polygonPreview->setRowStretch(1,1);

    calcolaArea = new QPushButton("Calcola Area",this);
    polygonPreview->addWidget(calcolaArea,2,0,1,3);
    QLCDNumber* lcdArea = new QLCDNumber();
    polygonPreview->addWidget(lcdArea,2,3);

    calcolaPerimetro = new QPushButton("Calcola Perimetro",this);
    polygonPreview->addWidget(calcolaPerimetro,3,0,1,3);
    QLCDNumber* lcdPerimetro = new QLCDNumber();
    polygonPreview->addWidget(lcdPerimetro,3,3);

    calcolaBaricentro = new QPushButton("Trova Baricentro",this);
    polygonPreview->addWidget(calcolaBaricentro,4,0,1,3);

    calcolaLati = new QPushButton("Calcola Lunghezza Lati",this);
    polygonPreview->addWidget(calcolaLati,5,0,1,3);

    lcdLato1 = new QLCDNumber();
    lcdLato2 = new QLCDNumber();
    lcdLato3 = new QLCDNumber();
    lcdLato4 = new QLCDNumber();
    lcdLato1->setMaximumHeight(35);
    polygonPreview->addWidget(lcdLato1,6,0);
    polygonPreview->addWidget(lcdLato2,6,1);
    polygonPreview->addWidget(lcdLato3,6,2);
    polygonPreview->addWidget(lcdLato4,6,3);
    calcolaLati->setEnabled(false);
    lcdLato4->setVisible(false);


    setLayout(polygonPreview);
    setGeometry(0,160,250,250);

    connect(polygonSelector,SIGNAL(currentIndexChanged(int)),this,SLOT(setPolygonMode(int)));
    connect(polygonSelector,SIGNAL(currentIndexChanged(int)),this,SIGNAL(fetchPolygon(int)));
    connect(this,SIGNAL(drawCircle(QPointF,double)),drawbox,SLOT(drawCircle(QPointF,double)));
    connect(this,SIGNAL(drawEdgedPolygon(QPolygonF)),drawbox,SLOT(drawEdgedPolygon(QPolygonF)));

}


void LeftBox::setPolygonMode(int i){
    if(i==0)
    {
        polygonSelector->setCurrentIndex(0);
        calcolaLati->setEnabled(false);

    }
    else if (i==1) {
        polygonSelector->setCurrentIndex(1);
        calcolaLati->setEnabled(true);
        lcdLato4->setVisible(false);
    }
    else if (i==2) {
        polygonSelector->setCurrentIndex(2);
        calcolaLati->setEnabled(true);
        lcdLato4->setVisible(true);

    }
}
