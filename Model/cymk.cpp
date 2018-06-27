#include "cmyk.h"

Cymk::Cymk(unsigned int c, unsigned int m, unsigned int y, unsigned int b) {
    if(c <= CYMK_MAX_VALUE) {
        cyan(c);
    }
    else
        red(CYMK_MAX_VALUE);

    if(m <= CYMK_MAX_VALUE){
        magenta(m);
    }
    else
        magenta(CYMK_MAX_VALUE);

    if(y <= CYMK_MAX_VALUE){
        yellow(y);
    }
    else
        yellow(CYMK_MAX_VALUE);

    if(b <= CYMK_MAX_VALUE) {
        black(b);
    }
    else
        black(CYMK_MAX_VALUE);

}

unsigned int Cymk::getCyan() const {
    return cyan;
}

unsigned int Cymk::getMagenta() const {
    return magenta;
}

unsigned int Cymk::getYellow() const {
    return yellow;
}

unsigned int Cymk::getBlack() const {
    return black;
}

void Cymk::setCyan(unsigned int i) {
    cyan = i;
}

void Cymk::setMagenta(unsigned int i) {
    magenta = i;
}

void Cymk::setYellow(unsigned int i) {
    yellow = i;
}

void Cymk::setBlack(unsigned int i) {
    black = i;
}

QString getHex() const {
    Qstring temp = "#";
    unsigned int r = ( 1 - cyan / 100) * ( 1 - black / 100);
    unsigned int g = ( 1 - magenta / 100) * ( 1 - black / 100);
    unsigned int b = ( 1 - yellow / 100) * ( 1 - black / 100);
    temp += QString::number(r,16);
    temp += QString::number(g,16);
    temp += QString::number(b,16);
    return temp;

}

/*
Red = 255 × ( 1 - Cyan ÷ 100 ) × ( 1 - Black ÷ 100 )
Green = 255 × ( 1 - Magenta ÷ 100 ) × ( 1 - Black ÷ 100 )
Blue = 255 × ( 1 - Yellow ÷ 100 ) × ( 1 - Black ÷ 100 )
*/

