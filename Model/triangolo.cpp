#include "triangolo.h"
#include <qvector.h>
#include <math.h>

Triangolo::Triangolo(const Punto& a, const Punto& b, const Punto& c) : LatiFiniti(QVector<const Punto*>()) {
    QVector<const Punto*> v;
    v.push_back(new Punto(a));
    v.push_back(new Punto(b));
    v.push_back(new Punto(c));
    LatiFiniti(v);
}

double Triangolo::getArea() const {
    double semiP = getPerimetro()/2;
    QVector<double> l = getLati();
    double area = sqrt(semiP * (semiP-l[0]) * (semiP-l[1]) * (semiP-l[2]));
    return area;
}
