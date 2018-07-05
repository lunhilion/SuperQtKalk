#include "datamanager.h"
#include "Exception/kalkexception.h"
#include <iostream>

DataManager::DataManager(MainWindow * w) : view(w)
{
    poli = 0;
    col1 = 0;
    op1 = new Rgb(255,255,255);
    op2 = new Rgb(255,255,255);
    colorResult = new Rgb(255,255,255);
    polygonColor = new Rgb(0,0,0);
    connect(view,SIGNAL(newColorOperand(int)), this, SLOT(newColorOperand(int)));
    connect(this,SIGNAL(setColorOperandMaxValues(uint)),view,SIGNAL(setColorOperandMaxValues(uint)));
    connect(view,SIGNAL(val1changed(int)),this,SLOT(setval1(int)));
    connect(view,SIGNAL(val2changed(int)),this,SLOT(setval2(int)));
    connect(view,SIGNAL(val3changed(int)),this,SLOT(setval3(int)));
    connect(view,SIGNAL(val4changed(int)),this,SLOT(setval4(int)));
    connect(this,SIGNAL(setCol1Preview(QString)),view,SIGNAL(setCol1Preview(QString)));
    connect(view,SIGNAL(col1toOP1()),this,SLOT(col1toOP1()));
    connect(view,SIGNAL(col1toOP2()),this,SLOT(col1toOP2()));
    connect(view,SIGNAL(col1toPolygonColor()),this,SLOT(col1toPolygonColor()));
    connect(view,SIGNAL(colorResulttoPolygonColor()),this,SLOT(colorResulttoPolygonColor()));
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
    connect(this,SIGNAL(setPolygonMode(int)),view,SIGNAL(setPolygonMode(int)));
    connect(this,SIGNAL(updateDrawingColor(QString)),view,SIGNAL(updateDrawingColor(QString)));
    connect(view,SIGNAL(findArea()),this,SLOT(findArea()));
    connect(view,SIGNAL(findPerimetro()),this,SLOT(findPerimetro()));
    connect(view,SIGNAL(findBaricentro()),this,SLOT(findBaricentro()));
    connect(view,SIGNAL(findLati()),this,SLOT(findLati()));
    connect(this,SIGNAL(showArea(double)),view,SIGNAL(showArea(double)));
    connect(this,SIGNAL(showPerimetro(double)),view,SIGNAL(showPerimetro(double)));
    connect(this,SIGNAL(showBaricentro(QPoint)),view,SIGNAL(showBaricentro(QPoint)));
    connect(this,SIGNAL(showLati(QVector<double>)),view,SIGNAL(showLati(QVector<double>)));

    initializeOperands(2,0);

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
        //gestione eccezione: "valore non definito"
    }
}


void DataManager::setval1(int i) {
    try {
        if(dynamic_cast<Rgb*>(col1))
            static_cast<Rgb*>(col1)->setRed(i);
        else if(dynamic_cast<Cmyk*>(col1))
            static_cast<Cmyk*>(col1)->setCyan(i);
        else
            throw TypeErr("Valore non settabile");
        emit(setCol1Preview(col1->getHex()));
    }
    catch(KalkException k) {
        k.printError();
    }
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
    if(op1)
        delete op1;
    op1 = col1->clone();
    if(op1)
        emit(setOP1(op1->getHex()));
    //else
        //gestione eccezione
}

void DataManager::col1toOP2() {
    if(op2)
        delete op2;
    op2 = col1->clone();
    if(op2)
        emit(setOP2(op2->getHex()));
    //else
        //gestione eccezione
}

void DataManager::col1toPolygonColor() {
    if(polygonColor)
        delete polygonColor;
    polygonColor = col1->clone();
    emit(updateDrawingColor(polygonColor->getHex()));
}

void DataManager::colorResulttoPolygonColor() {
    if(polygonColor)
        delete polygonColor;
    polygonColor = colorResult->clone();
    emit(updateDrawingColor(polygonColor->getHex()));
}

void DataManager::somma() {
    if(colorResult)
        delete colorResult;
    colorResult=(*op1)+(*op2);
    if(colorResult)
        emit(setResult(colorResult->getHex()));
    //else
        //gestione eccezione
}

void DataManager::sottrai() {
    if(colorResult)
        delete colorResult;
    colorResult=(*op1)-(*op2);
    if(colorResult)
        emit(setResult(colorResult->getHex()));
    //else
        //gestione eccezione
}

void DataManager::media() {
    if(colorResult)
        delete colorResult;
    colorResult= op1->media(*op2);
    if(colorResult)
        emit(setResult(colorResult->getHex()));
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
        emit(setPolygonMode(0));
        //else
            //gestione eccezione
    }
    else if (i>0) {
        if(poli)
            delete poli;
        if(i==1)
        {
            poli = new Triangolo(Punto(-50,30),Punto(50,30),Punto(0,-50));
            emit(setPolygonMode(1));
        }
        else if (i==2)
        {
            poli = new Quadrilatero(Punto(-50,30),Punto(50,30),Punto(50,-30),Punto(-50,-30));
            emit(setPolygonMode(2));
        }
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


void DataManager::initializeOperands(int polygon, int color) {
    fetchPolygon(polygon);
    newColorOperand(color);
}

void DataManager::findArea() {
    std::cout<<poli->getArea()<<std::endl;
    emit(showArea(poli->getArea()));
}

void DataManager::findPerimetro() {
    std::cout<<poli->getPerimetro()<<std::endl;
    emit(showPerimetro(poli->getPerimetro()));
}

void DataManager::findBaricentro() {
    QPoint p = QPoint(poli->getBaricentro().getX(),poli->getBaricentro().getY());
    emit(showBaricentro(p));
}

void DataManager::findLati() {
    if(dynamic_cast<LatiFiniti*>(poli))
        emit(showLati(static_cast<LatiFiniti*>(poli)->getLati()));
    //else
        //gestione eccezione: operazione non possibile su questo poligono
}
