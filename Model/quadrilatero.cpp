#include "quadrilatero.h"
#include <QVector>

Quadrilatero::Quadrilatero(const Punto& p1, const Punto& p2, const Punto& p3, const Punto& p4) : LatiFiniti() {
    pushVertice(p1);
    pushVertice(p2);
    pushVertice(p3);
    pushVertice(p4);
}

double Quadrilatero::getArea() const {
    QVector<double> l = getLati();
    double diag = Punto::distanzaDuePunti((getVertice(0)),(getVertice(2)));
    double semiP1 = (l[0]+l[1]+diag)/2;
    double area1 = sqrt(semiP1 * (semiP1-l[0]) * (semiP1-l[1]) * (semiP1-diag));
    double semiP2 = (diag+l[2]+l[3])/2;
    double area2 = sqrt(semiP2 * (semiP2-diag) * (semiP2-l[2]) * (semiP2-l[3]));
    return area1+area2;

}

Quadrilatero* Quadrilatero::clone() const {
    return new Quadrilatero(*this);
}

