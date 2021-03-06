#ifndef CMYK_H
#define CMYK_H
#include "colore.h"
#include <QString>


class Cmyk : public Colore {
    private:
        unsigned int cyan;
        unsigned int magenta;
        unsigned int yellow;
        unsigned int black;
        static unsigned int CMYK_MAX_VALUE;
    public:
        Cmyk(unsigned int=0, unsigned int=0, unsigned int=0, unsigned int=0);
        Cmyk(QString);
        unsigned int getCyan() const;
        unsigned int getMagenta() const;
        unsigned int getYellow() const;
        unsigned int getBlack() const;
        void setCyan(unsigned int);
        void setMagenta(unsigned int);
        void setYellow(unsigned int);
        void setBlack(unsigned int);
        QString getHex() const;
        Cmyk* operator+(const Colore&) const;
        Cmyk* operator-(const Colore&) const;
        Cmyk* media(const Colore&) const;
        Cmyk* clone() const;
        unsigned int getMaxValues() const;
};

#endif // CMYK_H
