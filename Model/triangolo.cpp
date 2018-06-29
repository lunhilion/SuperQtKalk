#include "triangolo.h"
#include <QVector>
#include <math.h>

Triangolo::Triangolo(const QVector<const Punto*>& v) : LatiFiniti(v) {

}

double Triangolo::getArea() const {
    double semiP = getPerimetro()/2;
    QVector<double> l = getLati();
    double area = sqrt(semiP * (semiP-l[0]) * (semiP-l[1]) * (semiP-l[2]));
    return area;
}

Triangolo* Triangolo::clone() const {
    return new Triangolo(*this);
}
