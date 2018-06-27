#ifndef PUNTO_H
#define PUNTO_H


class Punto {
private:
  unsigned int x;   //altezza in pixel dall'angolo in basso a sinistra del padre
  unsigned int y;
public:
  Punto(unsigned int, unsigned int);
  Punto getPunto() const;
  unsigned int getX() const;
  unsigned int getY() const;
  void setPunto(const Punto&);
  void setX(unsigned int);
  void setY(unsigned int);
  unsigned int distanza(const Punto&) const;
  static unsigned int distanzaDuePunti(const Punto&, const Punto&);
};

#endif // PUNTO_H
