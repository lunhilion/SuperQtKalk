#ifndef COLORE_H
#define COLORE_H
#include <QString>


class Colore
{
public:
    virtual Colore& operator+(const Colore&) const=0;
    virtual Colore& operator-(const Colore&) const=0;
    virtual QString getHex() const=0;
    virtual Colore& media(const Colore&) const=0;
    virtual Colore* clone() const=0;
    virtual ~Colore();
    virtual unsigned int getMaxValues() const =0;
};

#endif // COLORE_H
