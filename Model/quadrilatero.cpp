#include "quadrilatero.h"

Quadrilatero::Quadrilatero(const Punto& a, const Punto& b, const Punto& c, const Punto& d) : LatiFiniti(QVector<const Punto*>) {
    QVector<const Punto*> v;
    v.push_back(new Punto(a));
    v.push_back(new Punto(b));
    v.push_back(new Punto(c));
    v.push_back(new Punto(d));
    LatiFiniti(v);
}

double Quadrilatero::getArea() {
    QVector<double> l = getLati();
    double semiP1 = (l[0]+l[1]+l[2])/2;
    double area1 = sqrt(semiP * (semiP-l[0]) * (semiP-l[1]) * (semiP-l[2]));
    double semiP2 = (l[0]+l[2]+l[3])/2;
    double area2 = sqrt(semiP * (semiP-l[0]) * (semiP-l[2]) * (semiP-l[3]));
    return area1+area2;

}

double Quadrilatero::getAltezza() {
   return getArea()/getLato(1);

}

