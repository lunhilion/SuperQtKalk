#include "punto.h"
#include <math.h>

Punto::Punto(double a, double b) : x(a), y(b) {}

double Punto::getX() const {
    return x;
}

double Punto::getY() const {
    return y;
}

Punto Punto::getPunto() const {
    return Punto(x,y);
}

void Punto::setPunto(const Punto& p) {
    x = p.getX();
    y = p.getY();
}

void Punto::setX(double i) {
    x = i;
}

void Punto::setY(double i) {
    y = i;
}


double Punto::distanzaDuePunti(const Punto& a, const Punto& b) {
    double v = pow(b.getX() - a.getX(), 2);
    double z = pow(b.getY() - a.getY(), 2);
    double dist = sqrt(v+z);
    return dist;

}

Punto* Punto::clone() const {
    return new Punto(*this);
}
