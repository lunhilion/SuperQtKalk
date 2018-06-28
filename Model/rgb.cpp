#include "rgb.h"
#include <QString>

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


Rgb Rgb::getRed() const {
    return red;
}

Rgb Rgb::getGreen() const {
    return green;
}

Rgb Rgb::getBlue() const {
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
    temp += QString::number(red,16);
    temp += QString::number(green,16);
    temp += QString::number(blue,16);
    return temp;
}

unsigned int Rgb::RGB_MAX_VALUE = 255;

