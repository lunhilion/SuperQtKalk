#include "rgb.h"
#include <QString>
#include <typeinfo>

//Rgb::Rgb(unsigned int r, unsigned int g, unsigned int b) : red(r), green(g), blue(b) {}
Rgb::Rgb(unsigned int r, unsigned int g, unsigned int b) {
    if(r <= RGB_MAX_VALUE) {
        red = r;
    }
    else
        red = RGB_MAX_VALUE;

    if(g <= RGB_MAX_VALUE){
        green = g;
    }
    else
        green = RGB_MAX_VALUE;

    if(b <= RGB_MAX_VALUE){
        blue = b;
    }
    else
        blue = RGB_MAX_VALUE;

}

Rgb::Rgb(QString s) {
    QString r = s.mid(1,2);
    QString g = g.mid(3,2);
    QString b = b.mid(5,2);
    red = r.toInt(0,10);
    green = r.toInt(0,10);
    blue = r.toInt(0,10);
}


unsigned int Rgb::getRed() const {
    return red;
}

unsigned int Rgb::getGreen() const {
    return green;
}

unsigned int Rgb::getBlue() const {
    return blue;
}

void Rgb::setRed(unsigned int i) {
    if(i <= RGB_MAX_VALUE) {
        red = i;
    }
    else {
        red = RGB_MAX_VALUE;
    }

}

void Rgb::setGreen(unsigned int i) {
    if(i <= RGB_MAX_VALUE) {
        green = i;
    }
    else {
        green = RGB_MAX_VALUE;
    }

}

void Rgb::setBlue(unsigned int i) {
    if(i <= RGB_MAX_VALUE) {
        blue = i;
    }
    else {
        blue = RGB_MAX_VALUE;
    }

}

QString Rgb::getHex() const {
    QString temp="#";
    temp += QString::number(red,16).rightJustified(2,'0');
    temp += QString::number(green,16).rightJustified(2,'0');
    temp += QString::number(blue,16).rightJustified(2,'0');
    return temp;
}

unsigned int Rgb::RGB_MAX_VALUE = 255;

Rgb* Rgb::clone() const {
    return new Rgb(*this);
}


Rgb* Rgb::operator+ (const Colore& c) const {

    unsigned int r = red;
    unsigned int g = green;
    unsigned int b = blue;
    if(typeid(c)==typeid(const Rgb&)) {
        const Rgb* rgbp = static_cast<const Rgb*>(&c);
        r += red + rgbp->getRed();
        g += green + rgbp->getGreen();
        b += blue + rgbp->getBlue();
        return new Rgb(r,g,b);
    }
    else {
        Rgb t = Rgb(c.getHex());
        r += red + t.getRed();
        g += green + t.getGreen();
        b += blue + t.getBlue();
        return new Rgb(r,g,b);

    }
}

Rgb* Rgb::operator- (const Colore& c) const {

    int r = red;
    int g = green;
    int b = blue;
    if(typeid(c)==typeid(const Rgb&)) {
        const Rgb* rgbp = static_cast<const Rgb*>(&c);
        r += red - rgbp->getRed();
        g += green - rgbp->getGreen();
        b += blue - rgbp->getBlue();
        if(r<0)
            r=0;
        if(g<0)
            g=0;
        if(b<0)
            b=0;
        return new Rgb(r,g,b);
    }
    else {
        Rgb t = Rgb(c.getHex());
        r += red - t.getRed();
        g += green - t.getGreen();
        b += blue - t.getBlue();
        if(r<0)
            r=0;
        if(g<0)
            g=0;
        if(b<0)
            b=0;
        return new Rgb(r,g,b);

    }
}

Rgb* Rgb::media (const Colore& c) const {

    unsigned int r = red;
    unsigned int g = green;
    unsigned int b = blue;
    if(typeid(c)==typeid(const Rgb&)) {
        const Rgb* rgbp = static_cast<const Rgb*>(&c);
        r += abs((red - rgbp->getRed()))/2;
        g += abs((green - rgbp->getGreen()))/2;
        b += abs((blue - rgbp->getBlue()))/2;
        return new Rgb(r,g,b);
    }
    else {
        Rgb t = Rgb(c.getHex());
        r += (red - t.getRed())/2;
        g += (green - t.getGreen())/2;
        b += (blue - t.getBlue())/2;
        return new Rgb(r,g,b);

    }
}

unsigned int Rgb::getMaxValues() const {
    return RGB_MAX_VALUE;
}

