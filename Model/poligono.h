#ifndef POLIGONO_H
#define POLIGONO_H

#include "punto.h"
#include <math.h>

class Poligono {
public:
  virtual double getArea() const=0;
  virtual double getPerimetro() const=0;
  virtual Punto getBaricentro() const=0;
  virtual ~Poligono();
  virtual Poligono* clone() const=0;
};

#endif // POLIGONO_H
