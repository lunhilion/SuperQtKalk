#include "kalkexception.h"
#include <QString>
#include <iostream>

KalkException::KalkException(QString s) : error(s) {}

void KalkException::printError() const {
    std::cout << error.toStdString();
}


TypeErr::TypeErr(QString s) : KalkException(s) {}
