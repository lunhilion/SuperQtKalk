#ifndef POLIGONO_H
#define POLIGONO_H

class Poligono {
public:
  virtual double getArea() const=0;
  virtual double getPerimetro() const=0;
  virtual Punto getBaricentro() const=0;   //da controllare il tipo di ritorno
  virtual void move(const Punto&)=0;
};

#endif // POLIGONO_H
