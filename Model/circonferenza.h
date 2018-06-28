#ifndef CIRCONFERENZA_H
#define CIRCONFERENZA_H


class Circonferenza : public Poligono {
private:
  Punto centro;
  unsigned int raggio;
protected:
  static unsigned int PI;
public:
  Circonferenza(const Punto&, unsigned int);   //raggio espresso in pixel
  double getArea() const;
  double getPerimetro() const;
  Punto getBaricentro() const;   //da controllare il tipo di ritorno
};

#endif // CIRCONFERENZA_H
