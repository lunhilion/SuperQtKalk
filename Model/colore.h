#ifndef COLORE_H
#define COLORE_H
#include <QString>


class Colore
{
public:
    //virtual Colore& operator+(const Colore&) const=0; //controllare se è il modo migliore per farlo!
    virtual QString getHex() const=0;
    //virtual Colore& media(const Colore&) const=0;
    virtual Colore* clone() const=0;
    virtual ~Colore();
};

#endif // COLORE_H
