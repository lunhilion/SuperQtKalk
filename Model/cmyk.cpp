#include "cmyk.h"
#include <QString>
#include <math.h>
#include <typeinfo>
#include <iostream>
Cmyk::Cmyk(unsigned int c, unsigned int m, unsigned int y, unsigned int b) {
    if(c < CMYK_MAX_VALUE) {
        cyan=c;
    }
    else
        cyan = CMYK_MAX_VALUE;

    if(m < CMYK_MAX_VALUE){
        magenta = m;
    }
    else
        magenta = CMYK_MAX_VALUE;

    if(y < CMYK_MAX_VALUE){
        yellow = y;
    }
    else
        yellow = CMYK_MAX_VALUE;

    if(b < CMYK_MAX_VALUE) {
        black = b;
    }
    else
        black = CMYK_MAX_VALUE;

}

Cmyk::Cmyk(QString s) {
    QString r = s.mid(1,2);
    QString g = s.mid(3,2);
    QString b = s.mid(5,2);
    double r1=r.toInt(0,16);
    double r2=g.toInt(0,16);
    double r3=b.toInt(0,16);
    r1 = r1/255;
    r2 = r2/255;
    r3 = r3/255;
    double max = std::max(r1,r2);
    max = std::max(max,r3);
    double bl = 1-max;
    black = bl*100;
    double cy = (1-r1-bl) / (1-bl);
    cyan = cy*100;
    double mag = (1-r2-bl) / (1-bl);
    magenta = mag*100;
    double yel = (1-r3-bl) / (1-bl);
    yellow = yel * 100;

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

void Cmyk::setCyan(unsigned int c) {
    if(c < CMYK_MAX_VALUE) {
        cyan=c;
    }
    else
        cyan = CMYK_MAX_VALUE;
}

void Cmyk::setMagenta(unsigned int m) {
    if(m < CMYK_MAX_VALUE){
        magenta = m;
    }
    else
        magenta = CMYK_MAX_VALUE;
}

void Cmyk::setYellow(unsigned int y) {
    if(y < CMYK_MAX_VALUE){
        yellow = y;
    }
    else
        yellow = CMYK_MAX_VALUE;
}

void Cmyk::setBlack(unsigned int b) {
    if(b < CMYK_MAX_VALUE) {
        black = b;
    }
    else
        black = CMYK_MAX_VALUE;
}

QString Cmyk::getHex() const {
    QString temp = "#";
    float c = cyan;
    float m = magenta;
    float y = yellow;
    float bl = black;

    int r = round(255*( 1 - c / 100) * ( 1 - bl / 100));
    int g = round(255*( 1 - m / 100) * ( 1 - bl / 100));
    int b = round(255*( 1 - y / 100) * ( 1 - bl / 100));

    temp += QString::number(r,16).rightJustified(2,'0');
    temp += QString::number(g,16).rightJustified(2,'0');
    temp += QString::number(b,16).rightJustified(2,'0');
    return temp;

}

unsigned int Cmyk::CMYK_MAX_VALUE = 100;

Cmyk* Cmyk::clone() const {
    return new Cmyk(*this);
}

Cmyk* Cmyk::operator+(const Colore& c) const {
    unsigned int c1 = cyan;
    unsigned int m = magenta;
    unsigned int y = yellow;
    unsigned int k = black;
    if(typeid(c)==typeid(const Cmyk&)) {
        const Cmyk* cmykp = static_cast<const Cmyk*>(&c);
        c1 += cmykp->getCyan();
        m += cmykp->getMagenta();
        y += cmykp->getYellow();
        k += cmykp->getBlack();
        return new Cmyk(c1,m,y,k);
    }
    else {
        Cmyk t = Cmyk(c.getHex());
        c1 += t.getCyan();
        m += t.getMagenta();
        y += t.getYellow();
        k += t.getBlack();
        return new Cmyk(c1,m,y,k);

    }

}

Cmyk* Cmyk::operator-(const Colore& c) const {
    int c1 = cyan;
    int m = magenta;
    int y = yellow;
    int k = black;
    if(typeid(c)==typeid(const Cmyk&)) {
        const Cmyk* cmykp = static_cast<const Cmyk*>(&c);
        c1 -= cmykp->getCyan();
        m -= cmykp->getMagenta();
        y -= cmykp->getYellow();
        k -= cmykp->getBlack();
        if(c1<0)
            c1=0;
        if(m<0)
            m=0;
        if(y<0)
            y=0;
        if(k<0)
            k=0;
        return new Cmyk(c1,m,y,k);
    }
    else {
        Cmyk t = Cmyk(c.getHex());
        c1 -= t.getCyan();
        m -= t.getMagenta();
        y -= t.getYellow();
        k -= t.getBlack();
        if(c1<0)
            c1=0;
        if(m<0)
            m=0;
        if(y<0)
            y=0;
        if(k<0)
            k=0;
        return new Cmyk(c1,m,y,k);

    }

}

Cmyk* Cmyk::media (const Colore& c) const {

    unsigned int c1 = cyan;
    unsigned int m = magenta;
    unsigned int y = yellow;
    unsigned int k = black;
    if(typeid(c)==typeid(const Cmyk&)) {
        const Cmyk* cmykp = static_cast<const Cmyk*>(&c);
        c1 += cmykp->getCyan();
        m += cmykp->getMagenta();
        y += cmykp->getYellow();
        k += cmykp->getBlack();
        return new Cmyk(abs(c1/2),abs(m/2),abs(y/2),abs(k/2));
    }
    else {
        Cmyk t = Cmyk(c.getHex());
        c1 += t.getCyan();
        m += t.getMagenta();
        y += t.getYellow();
        k += t.getBlack();
        return new Cmyk(abs(c1/2),abs(m/2),abs(y/2),abs(k/2));

    }
}
unsigned int Cmyk::getMaxValues() const {
    return CMYK_MAX_VALUE;
}

/*
Red = 255 × ( 1 - Cyan ÷ 100 ) × ( 1 - Black ÷ 100 )
Green = 255 × ( 1 - Magenta ÷ 100 ) × ( 1 - Black ÷ 100 )
Blue = 255 × ( 1 - Yellow ÷ 100 ) × ( 1 - Black ÷ 100 )
*/

