#ifndef QUADRILATERO_H
#define QUADRILATERO_H


class Quadrilatero : public Poligono {
public:
  Quadrilatero(Punto, Punto, Punto, Punto);
  ~Quadrilatero();
  double getArea() const;     //la calcoliamo dividendo in due con una diagonale, e calcolando per due triangoli generici
  double getAltezza() const;  //NB: NON FUNZIONA CON QUADRILATERI CONCAVI
};


//è stato scelto il nome quadrilatero e non quadrato, perchè muovendo un vertice non sarebbe stato più un quadrato!

#endif // QUADRILATERO_H
