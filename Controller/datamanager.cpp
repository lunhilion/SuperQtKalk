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
    connect(view,SIGNAL(fetchPolygon(int)),this,SLOT(drawPolygon(int)));
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
    connect(view,SIGNAL(sendRadius(double)),this,SLOT(setRadius(double)));
    connect(view,SIGNAL(sendPolygonPoint(QPointF,uint)),this,SLOT(setPolygonPoint(QPointF,uint)));

    initializeOperands(2,0);

}



void DataManager::newColorOperand(int i) {
    try {
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
            throw UndefValue();
        }
    }
    catch(KalkException k) {
        k.printError();
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
    try {
        if(dynamic_cast<Rgb*>(col1))
            static_cast<Rgb*>(col1)->setGreen(i);
        else if(dynamic_cast<Cmyk*>(col1))
            static_cast<Cmyk*>(col1)->setMagenta(i);
        else
            throw TypeErr();
        emit(setCol1Preview(col1->getHex()));
    }
    catch (KalkException k) {
            k.printError();
        }

}

void DataManager::setval3(int i) {
    try {
        if(dynamic_cast<Rgb*>(col1))
            static_cast<Rgb*>(col1)->setBlue(i);
        else if(dynamic_cast<Cmyk*>(col1))
            static_cast<Cmyk*>(col1)->setYellow(i);
        else
            throw TypeErr();
        emit(setCol1Preview(col1->getHex()));
    }
    catch (KalkException k) {
            k.printError();
        }
}

void DataManager::setval4(int i) {
    try {
        if(dynamic_cast<Cmyk*>(col1))
            static_cast<Cmyk*>(col1)->setBlack(i);
        else
            throw TypeErr();
        emit(setCol1Preview(col1->getHex()));
    }
    catch (KalkException k) {
            k.printError();
        }

}

void DataManager::col1toOP1() {
    try {
        if(op1)
            delete op1;
        op1 = col1->clone();
        if(op1)
            emit(setOP1(op1->getHex()));
        else
            throw  EmptyObj();
    }
    catch(KalkException k) {
        k.printError();
    }
}

void DataManager::col1toOP2() {
    try {
        if(op2)
            delete op2;
        op2 = col1->clone();
        if(op2)
            emit(setOP2(op2->getHex()));
        else
            throw  EmptyObj();
    }
    catch(KalkException k) {
        k.printError();
    }
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
    try {
        if(colorResult)
            delete colorResult;
        colorResult=(*op1)+(*op2);
        if(colorResult)
            emit(setResult(colorResult->getHex()));
        else
            throw OperatErr();
    }
    catch(KalkException k) {
        k.printError();
    }
}

void DataManager::sottrai() {
    try {
        if(colorResult)
            delete colorResult;
        colorResult=(*op1)-(*op2);
        if(colorResult)
            emit(setResult(colorResult->getHex()));
        else
            throw OperatErr();
    }
    catch(KalkException k) {
        k.printError();
    }
}

void DataManager::media() {
    try {
        if(colorResult)
            delete colorResult;
        colorResult= op1->media(*op2);
        if(colorResult)
            emit(setResult(colorResult->getHex()));
        else
            throw OperatErr();
    }
    catch(KalkException k) {
        k.printError();
    }
}

void DataManager::fetchPolygon(int i) {
    try {
        if(i==0) {
            if(poli)
                delete poli;
            poli = new Circonferenza(Punto(0,0), 50);
        }
        else if(i==1) {
            if(poli)
                delete poli;
            poli = new Triangolo(Punto(-50,30),Punto(50,30),Punto(0,-50));
        }
        else if (i==2) {
            if(poli)
                delete poli;
            poli = new Quadrilatero(Punto(-50,50),Punto(50,50),Punto(50,-50),Punto(-50,-50));
        }
        else
            throw EmptyPoly();
    }
    catch(KalkException k) {
        k.printError();
    }

}

void DataManager::drawPolygon(int i) {
    try {
        emit(setPolygonMode(i));
        if(i==0) {
            Circonferenza* temp = static_cast<Circonferenza*>(poli);
            double x = temp->getBaricentro().getX();
            double y = temp->getBaricentro().getY();
            emit(drawCircle(QPointF(x,y),temp->getRaggio()));
        }
        else if (i>0) {
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
    catch(KalkException k) {
        k.printError();
    }
}


void DataManager::initializeOperands(int polygon, int color) {
    fetchPolygon(polygon);
    newColorOperand(color);
}

void DataManager::findArea() {
    emit(showArea(poli->getArea()));
}

void DataManager::findPerimetro() {
    emit(showPerimetro(poli->getPerimetro()));
}

void DataManager::findBaricentro() {
    QPoint p = QPoint(poli->getBaricentro().getX(),poli->getBaricentro().getY());
    emit(showBaricentro(p));
}

void DataManager::findLati() {
    try {
        if(dynamic_cast<LatiFiniti*>(poli))
            emit(showLati(static_cast<LatiFiniti*>(poli)->getLati()));
        else
            throw TypeErr();
    }
    catch(KalkException k) {
        k.printError();
    }
}

void DataManager::setRadius(double r) {
    if(dynamic_cast<Circonferenza*>(poli))
        static_cast<Circonferenza*>(poli)->setRaggio(r);
    //else
        //gestione eccezione
}

void DataManager::setPolygonPoint(QPointF p, uint i) {
    Punto t(p.x(),p.y());
    if(dynamic_cast<LatiFiniti*>(poli))
        static_cast<LatiFiniti*>(poli)->setVertice(i,t);
    //else
        //gestione eccezione
}
