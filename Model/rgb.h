#ifndef RGB_H
#define RGB_H

#include "colore.h"

class Rgb : public Colore {
    private:
        unsigned int red;
        unsigned int green;
        unsigned int blue;
        static unsigned int RGB_MAX_VALUE;
    public:
        Rgb(unsigned int=0, unsigned int=0, unsigned int=0);
        Rgb(QString);
        unsigned int getRed() const;
        unsigned int getGreen() const;
        unsigned int getBlue() const;
        void setRed(unsigned int);
        void setGreen(unsigned int);
        void setBlue(unsigned int);
        QString getHex() const;
        Rgb* operator+ (const Colore&) const;
        Rgb* operator- (const Colore&) const;
        Rgb* media(const Colore&) const;
        Rgb* clone() const;
        unsigned int getMaxValues() const;
};

#endif // RGB_H
