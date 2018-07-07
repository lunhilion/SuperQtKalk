#include "leftbox.h"

LeftBox::LeftBox(QWidget *parent) : QFrame(parent)
{
    QGridLayout* polygonPreview = new QGridLayout;

    polygonSelector = new QComboBox(this);
    polygonSelector->addItem(tr("Cerchio"));
    polygonSelector->addItem(tr("Triangolo"));
    polygonSelector->addItem(tr("Quadrilatero"));
    polygonPreview->addWidget(polygonSelector,0,0,1,3);

    QPushButton* disegna = new QPushButton("Disegna",this);
    polygonPreview->addWidget(disegna,0,3,1,1);

    drawbox = new DrawBox(this);
    //drawbox->setMinimumHeight(365);
    //drawbox->setMinimumWidth(450);
    polygonPreview->addWidget(drawbox,1,0,1,4);
    polygonPreview->setRowStretch(1,1);

    calcolaArea = new QPushButton("Calcola Area",this);
    calcolaArea->setEnabled(false);
    polygonPreview->addWidget(calcolaArea,2,0,1,3);
    lcdArea = new QLCDNumber(8);
    polygonPreview->addWidget(lcdArea,2,3);

    calcolaPerimetro = new QPushButton("Calcola Perimetro",this);
    calcolaPerimetro->setEnabled(false);
    polygonPreview->addWidget(calcolaPerimetro,3,0,1,3);
    lcdPerimetro = new QLCDNumber(8);
    polygonPreview->addWidget(lcdPerimetro,3,3);

    calcolaBaricentro = new QPushButton("Trova Baricentro",this);
    calcolaBaricentro->setEnabled(false);
    polygonPreview->addWidget(calcolaBaricentro,4,0,1,3);

    calcolaLati = new QPushButton("Calcola Lunghezza Lati",this);
    calcolaLati->setEnabled(false);
    polygonPreview->addWidget(calcolaLati,5,0,1,3);

    lcdLato1 = new QLCDNumber(8);
    lcdLato2 = new QLCDNumber(8);
    lcdLato3 = new QLCDNumber(8);
    lcdLato4 = new QLCDNumber(8);
    lcdLato4->setVisible(false);
    lcdLato1->setMinimumHeight(25);
    polygonPreview->addWidget(lcdLato1,6,0);
    polygonPreview->addWidget(lcdLato2,6,1);
    polygonPreview->addWidget(lcdLato3,6,2);
    polygonPreview->addWidget(lcdLato4,6,3);




    setLayout(polygonPreview);
    setGeometry(0,160,250,250);

    //connect(polygonSelector,SIGNAL(currentIndexChanged(int)),this,SLOT(setPolygonMode(int)));
    connect(disegna,SIGNAL(clicked()),this,SLOT(polygonRouter()));
    connect(this,SIGNAL(drawCircle(QPointF,double)),drawbox,SLOT(drawCircle(QPointF,double)));
    connect(this,SIGNAL(drawEdgedPolygon(QPolygonF)),drawbox,SLOT(drawEdgedPolygon(QPolygonF)));
    connect(this,SIGNAL(updateDrawingColor(QString)),drawbox,SLOT(updateDrawingColor(QString)));
    connect(calcolaArea,SIGNAL(clicked()),this,SIGNAL(findArea()));
    connect(calcolaPerimetro,SIGNAL(clicked()),this,SIGNAL(findPerimetro()));
    connect(calcolaBaricentro,SIGNAL(clicked()),this,SIGNAL(findBaricentro()));
    connect(calcolaLati,SIGNAL(clicked()),this,SIGNAL(findLati()));
    connect(this,SIGNAL(drawPoint(QPoint)),drawbox,SLOT(drawPoint(QPoint)));
    connect(drawbox,SIGNAL(sendRadius(double)),this,SIGNAL(sendRadius(double)));
    connect(drawbox,SIGNAL(sendPolygonPoint(QPointF,uint)),this,SIGNAL(sendPolygonPoint(QPointF,uint)));
}


void LeftBox::polygonRouter() {
    lcdArea->display(0);
    lcdPerimetro->display(0);
    lcdLato1->display(0);
    lcdLato2->display(0);
    lcdLato3->display(0);
    lcdLato4->display(0);
    emit(fetchPolygon(polygonSelector->currentIndex()));
    emit(setPolygonMode(polygonSelector->currentIndex()));
}

void LeftBox::setPolygonMode(int i){
    if(i==0)
    {
        polygonSelector->setCurrentIndex(0);
        calcolaArea->setEnabled(true);
        calcolaPerimetro->setEnabled(true);
        calcolaBaricentro->setEnabled(true);
        calcolaLati->setEnabled(false);
    }
    else if (i==1) {
        polygonSelector->setCurrentIndex(1);
        calcolaArea->setEnabled(true);
        calcolaPerimetro->setEnabled(true);
        calcolaBaricentro->setEnabled(true);
        calcolaLati->setEnabled(true);
        lcdLato4->setVisible(false);
    }
    else if (i==2) {
        polygonSelector->setCurrentIndex(2);
        calcolaArea->setEnabled(true);
        calcolaPerimetro->setEnabled(true);
        calcolaBaricentro->setEnabled(true);
        calcolaLati->setEnabled(true);
        lcdLato4->setVisible(true);
    }
    //else
        /*
        polygonSelector->setCurrentIndex(0);
        calcolaArea->setEnabled(true);
        calcolaPerimetro->setEnabled(true);
        calcolaBaricentro->setEnabled(true);
        calcolaLati->setEnabled(false);
        throw exception("Inizializzazione di operando poligono non valida. Operando inizializzato a Circonferenza.");
    */
}

void LeftBox::showArea(double d) {
    QString s = QString::number(d, 'f',2);
    lcdArea->display(s);
}

void LeftBox::showPerimetro(double d) {
    QString s = QString::number(d, 'f',2);
    lcdPerimetro->display(s);
}

void LeftBox::showBaricentro(QPoint p) {
    emit(drawPoint(p));
}

void LeftBox::showLati(QVector<double> q) {
    QString s;
    if(q.size()>0) {
        s = QString::number(q[0], 'f',2);
        lcdLato1->display(s);
    }
    if(q.size()>1) {
        s = QString::number(q[1], 'f',2);
        lcdLato2->display(s);
    }
    if(q.size()>2) {
        s = QString::number(q[2], 'f',2);
        lcdLato3->display(s);
    }
    if(q.size()>3) {
        s = QString::number(q[3], 'f',2);
        lcdLato4->display(s);
    }
}

LeftBox::~LeftBox() {
    delete polygonSelector;
    delete drawbox;
    delete calcolaArea;
    delete calcolaPerimetro;
    delete calcolaBaricentro;
    delete calcolaLati;
    delete lcdLato1;
    delete lcdLato2;
    delete lcdLato3;
    delete lcdLato4;
    delete lcdArea;
    delete lcdPerimetro;
}
