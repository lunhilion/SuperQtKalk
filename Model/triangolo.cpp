#include "triangolo.h"
#include <QVector>
#include <math.h>

Triangolo::Triangolo(const Punto& p1, const Punto& p2, const Punto& p3) : LatiFiniti() {
    pushVertice(p1);
    pushVertice(p2);
    pushVertice(p3);
}

double Triangolo::getArea() const {
    double semiP = getPerimetro()/2;
    QVector<double> l = getLati();
    double area = sqrt(semiP * (semiP-l[0]) * (semiP-l[1]) * (semiP-l[2]));
    return area;
}

double Triangolo::getAltezza() const {
    return (getArea()/2)/getLato(1);
}

Triangolo* Triangolo::clone() const {
    return new Triangolo(*this);
}
