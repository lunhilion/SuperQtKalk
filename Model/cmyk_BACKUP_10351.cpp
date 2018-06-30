#include "cmyk.h"
#include <QString>

Cmyk::Cmyk(unsigned int c, unsigned int m, unsigned int y, unsigned int b) {
    if(c <= CMYK_MAX_VALUE) {
        cyan=c;
    }
    else
        cyan = CMYK_MAX_VALUE;

    if(m <= CMYK_MAX_VALUE){
        magenta = m;
    }
    else
        magenta = CMYK_MAX_VALUE;

    if(y <= CMYK_MAX_VALUE){
        yellow = y;
    }
    else
        yellow = CMYK_MAX_VALUE;

    if(b <= CMYK_MAX_VALUE) {
        black = b;
    }
    else
        black = CMYK_MAX_VALUE;

}


unsigned int Cmyk::getCyan() const {
    return cyan;
}

unsigned int Cmyk::getMagenta() const {
    return magenta;
}

unsigned int Cmyk::getYellow() const {
    return yellow;
}

unsigned int Cmyk::getBlack() const {
    return black;
}

void Cmyk::setCyan(unsigned int i) {
    cyan = i;
}

void Cmyk::setMagenta(unsigned int i) {
    magenta = i;
}

void Cmyk::setYellow(unsigned int i) {
    yellow = i;
}

void Cmyk::setBlack(unsigned int i) {
    black = i;
}

QString Cmyk::getHex() const {
    QString temp = "#";
    unsigned int r = 255 * ( 1 - cyan / 100) * ( 1 - black / 100);
    unsigned int g = 255 * ( 1 - magenta / 100) * ( 1 - black / 100);
    unsigned int b = 255 * ( 1 - yellow / 100) * ( 1 - black / 100);
    temp += QString::number(r,16);
    temp += QString::number(g,16);
    temp += QString::number(b,16);
    return temp;

}

unsigned int Cmyk::CMYK_MAX_VALUE = 100;

Cmyk* Cmyk::clone() const {
    return new Cmyk(*this);
}

<<<<<<< HEAD
Cmyk& Cmyk::media(const Colore& c) const {
    return *(new Cmyk());
}

Cmyk& Cmyk::operator+(const Colore& c) const {
    return *(new Cmyk());

}

Cmyk& Cmyk::operator-(const Colore& c) const {
    return *(new Cmyk());
=======
unsigned int Cmyk::getMaxValues() const {
    return CMYK_MAX_VALUE;
>>>>>>> e25bdd12aa77d98d7bef2df58c4c074a14ea1676
}

/*
Red = 255 × ( 1 - Cyan ÷ 100 ) × ( 1 - Black ÷ 100 )
Green = 255 × ( 1 - Magenta ÷ 100 ) × ( 1 - Black ÷ 100 )
Blue = 255 × ( 1 - Yellow ÷ 100 ) × ( 1 - Black ÷ 100 )
*/

