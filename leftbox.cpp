#include "leftbox.h"

LeftBox::LeftBox(QWidget *parent) : QWidget(parent)
{
    QGridLayout* poligonPreview = new QGridLayout;

    poligonSelector = new QComboBox(this);
    poligonSelector->addItem(tr("Cerchio"));
    poligonSelector->addItem(tr("Triangolo"));
    poligonSelector->addItem(tr("Quadrato"));
    poligonPreview->addWidget(poligonSelector,0,0,1,4);
    drawbox = new DrawBox(this);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    drawbox->setAutoFillBackground(true);
    drawbox->setPalette(pal);
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

    QLCDNumber* lcdLato1 = new QLCDNumber();
    QLCDNumber* lcdLato2 = new QLCDNumber();
    QLCDNumber* lcdLato3 = new QLCDNumber();
    QLCDNumber* lcdLato4 = new QLCDNumber();
    lcdLato1->setMaximumHeight(30);
    poligonPreview->addWidget(lcdLato1,6,0);
    poligonPreview->addWidget(lcdLato2,6,1);
    poligonPreview->addWidget(lcdLato3,6,2);
    poligonPreview->addWidget(lcdLato4,6,3);

    setLayout(poligonPreview);
    setGeometry(0,160,250,250);
}

