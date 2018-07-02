#ifndef CIRCONFERENZA_H
#define CIRCONFERENZA_H

#include "punto.h"
#include "poligono.h"

class Circonferenza : public Poligono {
private:
  Punto centro;
  double raggio;
protected:
  static unsigned int PI;
public:
  Circonferenza(const Punto&, unsigned int);
  double getArea() const;
  double getPerimetro() const;
  Punto getBaricentro() const;   //da controllare il tipo di ritorno
  Circonferenza* clone() const;
  double getRaggio() const;
};

#endif // CIRCONFERENZA_H
