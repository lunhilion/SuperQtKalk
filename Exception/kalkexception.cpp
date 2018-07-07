#include "kalkexception.h"
#include <QString>
#include <iostream>

KalkException::KalkException(QString s) : error(s) {}

void KalkException::printError() const {
    std::cout << error.toStdString() << std::endl;
}

TypeErr::TypeErr(QString s) : KalkException(s) {}

UndefValue::UndefValue(QString s) : KalkException(s) {}

EmptyObj::EmptyObj(QString s) : KalkException(s) {}

OperatErr::OperatErr(QString s) : KalkException(s) {}

EmptyPoly::EmptyPoly(QString s) : EmptyObj(s) {}

ViewUndefValue::ViewUndefValue(QString s) : UndefValue(s) {}
