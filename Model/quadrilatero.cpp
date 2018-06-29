#include "quadrilatero.h"

Quadrilatero::Quadrilatero(const Punto& a, const Punto& b, const Punto& c, const Punto& d) /* : LatiFiniti(QVector<const Punto*>)*/ {
    QVector<const Punto*> v;
    v.push_back(new Punto(a));
    v.push_back(new Punto(b));
    v.push_back(new Punto(c));
    v.push_back(new Punto(d));
   // LatiFiniti(v);            //qui c'è qualcosa di sbagliato! Mi sa nel concetto generale... Può essere un'idea mettergli un costruttore di default, ed un setter? In ogni caso, bisogna pensarci bene
}

double Quadrilatero::getArea() const {      //occhio che questa è sbagliata
    QVector<double> l = getLati();
    double semiP1 = (l[0]+l[1]+l[2])/2;
    double area1 = sqrt(semiP1 * (semiP1-l[0]) * (semiP1-l[1]) * (semiP1-l[2]));
    double semiP2 = (l[0]+l[2]+l[3])/2;
    double area2 = sqrt(semiP2 * (semiP2-l[0]) * (semiP2-l[2]) * (semiP2-l[3]));
    return area1+area2;

}

double Quadrilatero::getAltezza() const {
   return getArea()/getLato(1);

}

