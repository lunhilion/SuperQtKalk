#include "datamanager.h"

DataManager::DataManager(MainWindow * w) : view(w)
{
    col1 = new Rgb();
    col2 = new Rgb();
    col3 = new Rgb();
    col4 = new Rgb();
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

}


void DataManager::newColorOperand(int i) {
    delete col1;
    if(i==0) {
        col1 = new Rgb();
        emit(setColorOperandMaxValues(col1->getMaxValues()));
    }
    else if (i==1)
    {
        col1 = new Cmyk();
        emit(setColorOperandMaxValues(col1->getMaxValues()));
    }
    else {
        //gestione eccezione
    }
}


void DataManager::setval1(int i) {
    Colore* c = dynamic_cast<Rgb*>(col1);
    if(c)
        static_cast<Rgb*>(col1)->setRed(i);
    else
        static_cast<Cmyk*>(col1)->setCyan(i);
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::setval2(int i) {
    Colore* c = dynamic_cast<Rgb*>(col1);
    if(c)
        static_cast<Rgb*>(col1)->setGreen(i);
    else
        static_cast<Cmyk*>(col1)->setMagenta(i);
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::setval3(int i) {
    Colore* c = dynamic_cast<Rgb*>(col1);
    if(c)
        static_cast<Rgb*>(col1)->setBlue(i);
    else
        static_cast<Cmyk*>(col1)->setYellow(i);
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::setval4(int i) {
    Colore* c = dynamic_cast<Cmyk*>(col1);
    if(c)
        static_cast<Cmyk*>(col1)->setBlack(i);
    emit(setCol1Preview(col1->getHex()));
}

void DataManager::col1toOP1() {
    delete col2;
    col2 = col1->clone();
    emit(setOP1(col2->getHex()));
}

void DataManager::col1toOP2() {
    delete col3;
    col3 = col1->clone();
    emit(setOP2(col3->getHex()));
}

void DataManager::somma() {
    delete col4;
    col4=(*col2)+(*col3);
    emit(setResult(col4->getHex()));
}

void DataManager::sottrai() {
    delete col4;
    col4=(*col2)-(*col3);
    emit(setResult(col4->getHex()));
}

void DataManager::media() {
    delete col4;
    col4= col2->media(*col3);
    emit(setResult(col4->getHex()));
}
