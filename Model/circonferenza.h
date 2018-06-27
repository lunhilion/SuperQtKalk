#ifndef CIRCONFERENZA_H
#define CIRCONFERENZA_H


class Circonferenza : public Poligono {
private:
  Punto centro;
public:
  Circonferenza(Punto, unsigned int);   //raggio espresso in pixel
  double getArea() const;
  double getPerimetro() const;
  Punto getBaricentro() const;   //da controllare il tipo di ritorno
  void move(const Punto&);
};

#endif // CIRCONFERENZA_H
