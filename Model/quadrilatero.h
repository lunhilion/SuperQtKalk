#ifndef QUADRILATERO_H
#define QUADRILATERO_H

#include "latifiniti.h"
#include <QVector>

class Quadrilatero : public LatiFiniti {
public:
  Quadrilatero(QVector<const Punto*>);
  ~Quadrilatero();
  double getArea() const;     //la calcoliamo dividendo in due con una diagonale, e calcolando per due triangoli generici
  double getAltezza() const;  //NB: NON FUNZIONA CON QUADRILATERI CONCAVI
};


//è stato scelto il nome quadrilatero e non quadrato, perchè muovendo un vertice non sarebbe stato più un quadrato!

#endif // QUADRILATERO_H
