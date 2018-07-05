#ifndef PUNTO_H
#define PUNTO_H


class Punto {
private:
  double x;   //altezza in pixel dall'angolo in basso a sinistra del padre
  double y;
public:
  Punto(double=0, double=0);
  Punto getPunto() const;
  double getX() const;
  double getY() const;
  void setPunto(const Punto&);
  void setX(double);
  void setY(double);
  double distanza(const Punto&) const;
  static double distanzaDuePunti(const Punto&, const Punto&);
  Punto* clone() const;
};

#endif // PUNTO_H
