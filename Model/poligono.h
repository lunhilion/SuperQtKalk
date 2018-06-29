#ifndef POLIGONO_H
#define POLIGONO_H

#include "punto.h"
#include <QtMath>

class Poligono {
public:
  virtual double getArea() const=0;
  virtual double getPerimetro() const=0;
  virtual Punto getBaricentro() const=0;   //da controllare il tipo di ritorno
};

#endif // POLIGONO_H
