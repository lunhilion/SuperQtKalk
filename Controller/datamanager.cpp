#include "datamanager.h"

DataManager::DataManager(MainWindow * w) : view(w)
{
    poli = new Circonferenza(Punto(),25);
    col1 = new Rgb(0,0,0);
    col2 = new Rgb(255,255,255);
    col3 = new Rgb(255,255,255);
    col4 = new Rgb(255,255,255);
    col5 = new Rgb(0,0,0);
    connect(view,SIGNAL(newColorOperand(int)), this, SLOT(newColorOperand(int)));
    connect(this,SIGNAL(setColorOperandMaxValues(uint)),view,SIGNAL(setColorOperandMaxValues(uint)));
    connect(view,SIGNAL(val1changed(int)),this,SLOT(setval1(int)));
    connect(view,SIGNAL(val2changed(int)),this,SLOT(setval2(int)));
    connect(view,SIGNAL(val3changed(int)),this,SLOT(setval3(int)));
    connect(view,SIGNAL(val4changed(int)),this,SLOT(setval4(int)));
    connect(this,SIGNAL(setCol1Preview(QString)),view,SIGNAL(setCol1Preview(QString)));
    connect(view,SIGNAL(col1toOP1()),this,SLOT(col1toOP1()));
    connect(view,SIGNAL(col1toOP2()),this,SLOT(col1toOP2()));
    connect(this,SIGNAL(setOP1(QString)),view,SIGNAL(setOP1(QString)));
    connect(this,SIGNAL(setOP2(QString)),view,SIGNAL(setOP2(QString)));
    connect(view,SIGNAL(somma()),this,SLOT(somma()));
    connect(view,SIGNAL(sottrai()),this,SLOT(sottrai()));
    connect(view,SIGNAL(media()),this,SLOT(media()));
    connect(this,SIGNAL(setResult(QString)),view,SIGNAL(setResult(QString)));
    connect(view,SIGNAL(fetchPolygon(int)),this,SLOT(fetchPolygon(int)));
    connect(this,SIGNAL(drawCircle(QPointF,double)),view,SIGNAL(drawCircle(QPointF,double)));
    connect(this,SIGNAL(drawEdgedPolygon(QPolygonF)),view,SIGNAL(drawEdgedPolygon(QPolygonF)));
    connect(this,SIGNAL(setColorMode(int)),view,SIGNAL(setColorMode(int)));

    //inizializzazione figura
    fetchPolygon(0);

    //inizializzazione colore
    newColorOperand(0);
}

//commento

void DataManager::newColorOperand(int i) {
    if(col1)
        delete col1;
    if(i==0) {
        col1 = new Rgb();
        emit(setColorOperandMaxValues(col1->getMaxValues()));
        emit(setCol1Preview(col1->getHex()));
        emit(setColorMode(0));
    }
    else if (i==1)
    {
        col1 = new Cmyk();
        emit(setColorOperandMaxValues(col1->getMaxValues()));
        emit(setCol1Preview(col1->getHex()));
        emit(setColorMode(1));
    }
    else {
        //gestione eccezione
    }
}


void DataManager::setval1(int i) {
    if(dynamic_cast<Rgb*>(col1))
        static_cast<Rgb*>(col1)->setRed(i);
    else if(dynamic_cast<Cmyk*>(col1))
        static_cast<Cmyk*>(col1)->setCyan(i);
    //else
        //gestione eccezione
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::setval2(int i) {
    if(dynamic_cast<Rgb*>(col1))
        static_cast<Rgb*>(col1)->setGreen(i);
    else if(dynamic_cast<Cmyk*>(col1))
        static_cast<Cmyk*>(col1)->setMagenta(i);
    //else
        //gestione eccezione
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::setval3(int i) {
    if(dynamic_cast<Rgb*>(col1))
        static_cast<Rgb*>(col1)->setBlue(i);
    else if(dynamic_cast<Cmyk*>(col1))
        static_cast<Cmyk*>(col1)->setYellow(i);
    //else
        //gestione eccezione
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::setval4(int i) {
    if(dynamic_cast<Cmyk*>(col1))
        static_cast<Cmyk*>(col1)->setBlack(i);
    //else
        //gestione eccezione
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::col1toOP1() {
    if(col3)
        delete col2;
    col2 = col1->clone();
    if(col2)
        emit(setOP1(col2->getHex()));
    //else
        //gestione eccezione
}

void DataManager::col1toOP2() {
    if(col3)
        delete col3;
    col3 = col1->clone();
    if(col3)
        emit(setOP2(col3->getHex()));
    //else
        //gestione eccezione
}

void DataManager::somma() {
    if(col4)
        delete col4;
    col4=(*col2)+(*col3);
    if(col4)
        emit(setResult(col4->getHex()));
    //else
        //gestione eccezione
}

void DataManager::sottrai() {
    if(col4)
        delete col4;
    col4=(*col2)-(*col3);
    if(col4)
        emit(setResult(col4->getHex()));
    //else
        //gestione eccezione
}

void DataManager::media() {
    if(col4)
        delete col4;
    col4= col2->media(*col3);
    if(col4)
        emit(setResult(col4->getHex()));
    //else
        //gestione eccezione
}

void DataManager::fetchPolygon(int i) {
    if(i==0) {
        if(poli)
            delete poli;
        poli = new Circonferenza(Punto(0,0), 50);
        Circonferenza* temp = static_cast<Circonferenza*>(poli);
        double x = temp->getBaricentro().getX();
        double y = temp->getBaricentro().getY();
        emit(drawCircle(QPointF(x,y),temp->getRaggio()));
        //else
            //gestione eccezione
    }
    else if (i>0) {
        if(poli)
            delete poli;
        if(i==1)
            poli = new Triangolo(Punto(-50,30),Punto(50,30),Punto(0,-50));
        else if (i==2)
            poli = new Quadrilatero(Punto(-50,30),Punto(50,30),Punto(50,-60),Punto(-50,-60));
        //else
            //gestione eccezione: poligono non implementato
        LatiFiniti* temp = static_cast<LatiFiniti*>(poli);
        QPolygonF p;
        double x;
        double y;
        for (unsigned int j = 0; j < temp->contaVertici(); ++j) {
                x = temp->getVertice(j).getX();
                y = temp->getVertice(j).getY();
                QPointF q = QPointF(x,y);
                p.push_back(q);
            }
        emit(drawEdgedPolygon(p));
    }
}
