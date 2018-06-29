#include "quadrilatero.h"
#include <QVector>

Quadrilatero::Quadrilatero(const QVector<const Punto*>& v) : LatiFiniti(v) {

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

Quadrilatero* Quadrilatero::clone() const {
    return new Quadrilatero(*this);
}

