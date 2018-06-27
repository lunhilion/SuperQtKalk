#include "trianglepreview.h"

TrianglePreview::TrianglePreview(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* thplayout1 = new QHBoxLayout;
    QPushButton* calcolaArea = new QPushButton("Calcola Area",this);
    QLCDNumber* lcdArea = new QLCDNumber(this);
    thplayout1->addWidget(calcolaArea);
    thplayout1->addWidget(lcdArea);

    QHBoxLayout* thplayout2 = new QHBoxLayout;
    QPushButton* calcolaPerimetro = new QPushButton("Calcola Perimetro",this);
    QLCDNumber* lcdPerimetro = new QLCDNumber(this);
    thplayout2->addWidget(calcolaPerimetro);
    thplayout2->addWidget(lcdPerimetro);

    QHBoxLayout* thplayout3 = new QHBoxLayout;
    QPushButton* calcolaBaricentro = new QPushButton("Calcola Baricentro",this);
    thplayout3->addWidget(calcolaBaricentro);

    QHBoxLayout* thplayout4 = new QHBoxLayout;
    QPushButton* calcolaLati = new QPushButton("Calcola Lati",this);
    QLCDNumber* lcdLato1 = new QLCDNumber(this);
    QLCDNumber* lcdLato2 = new QLCDNumber(this);
    QLCDNumber* lcdLato3 = new QLCDNumber(this);
    thplayout4->addWidget(calcolaLati);
    thplayout4->addWidget(lcdLato1);
    thplayout4->addWidget(lcdLato2);
    thplayout4->addWidget(lcdLato3);

    QVBoxLayout* trianglePreviewLayout = new QVBoxLayout;
    trianglePreviewLayout->addLayout(thplayout1);
    trianglePreviewLayout->addLayout(thplayout2);
    trianglePreviewLayout->addLayout(thplayout3);
    trianglePreviewLayout->addLayout(thplayout4);

    setLayout(trianglePreviewLayout);


}

