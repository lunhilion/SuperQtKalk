#ifndef COLORE_H
#define COLORE_H
#include <QString>


class Colore
{
public:
    Colore();
    virtual Colore& operator+(const Colore&) const=0; //controllare se è il modo migliore per farlo!
    virtual QString getHex() const=0;
    virtual Colore& media(const Colore&) const=0;
    virtual ~Colore() =default;
};

#endif // COLORE_H
