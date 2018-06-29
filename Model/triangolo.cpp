#include "triangolo.h"
#include <qvector.h>
#include <math.h>

Triangolo::Triangolo(QVector<const Punto*> v) : LatiFiniti(v) {

}

double Triangolo::getArea() const {
    double semiP = getPerimetro()/2;
    QVector<double> l = getLati();
    double area = sqrt(semiP * (semiP-l[0]) * (semiP-l[1]) * (semiP-l[2]));
    return area;
}
