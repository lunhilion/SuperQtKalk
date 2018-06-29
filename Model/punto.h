#ifndef PUNTO_H
#define PUNTO_H


class Punto {
private:
  unsigned int x;   //altezza in pixel dall'angolo in basso a sinistra del padre
  unsigned int y;
public:
  Punto(unsigned int=0, unsigned int=0);
  Punto getPunto() const;
  unsigned int getX() const;
  unsigned int getY() const;
  void setPunto(const Punto&);
  void setX(unsigned int);
  void setY(unsigned int);
  unsigned int distanza(const Punto&) const;
  static double distanzaDuePunti(const Punto&, const Punto&);
  Punto* clone() const;
};

#endif // PUNTO_H
