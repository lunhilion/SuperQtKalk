#ifndef QUADRILATERO_H
#define QUADRILATERO_H

#include "latifiniti.h"
#include <QVector>

class Quadrilatero : public LatiFiniti {
public:
  Quadrilatero(const Punto&, const Punto&, const Punto&, const Punto&);
  double getArea() const;     //la calcoliamo dividendo in due con una diagonale, e calcolando per due triangoli generici
  Quadrilatero* clone() const;
};



#endif // QUADRILATERO_H
