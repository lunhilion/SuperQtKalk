#include "datamanager.h"

DataManager::DataManager(MainWindow * w) : view(w)
{
    col1 = new Rgb();
    connect(view,SIGNAL(newColorOperand(int)), this, SLOT(newColorOperand(int)));
    connect(this,SIGNAL(setColorOperandMaxValues(uint)),view,SIGNAL(setColorOperandMaxValues(uint)));
    connect(view,SIGNAL(val1changed(int)),this,SLOT(setval1(int)));
    connect(view,SIGNAL(val2changed(int)),this,SLOT(setval2(int)));
    connect(view,SIGNAL(val3changed(int)),this,SLOT(setval3(int)));
    connect(view,SIGNAL(val4changed(int)),this,SLOT(setval4(int)));
    connect(this,SIGNAL(setCol1Preview(QString)),view,SIGNAL(setCol1Preview(QString)));
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
