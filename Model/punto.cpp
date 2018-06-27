#include "punto.h"
#include <math.h>

Punto::Punto(unsigned int a, unsigned int b) : x(a), y(b) {}

unsigned int Punto::getX() const {
    return x;
}

unsigned int Punto::getY() const {
    return y;
}

Punto Punto::getPunto() const {
    Punto temp = Punto(x,y);
    return temp;
}

void Punto::setPunto(const Punto& p) {
    x = p.getX();
    y = p.getY();
}

void Punto::setX(unsigned int i) {
    x = i;
}

void Punto::setX(unsigned int i) {
    y = i;
}

unsigned int Punto::distanza(const Punto& p) const {

    unsigned int a = pow(p.getX() - x, 2);
    unsigned int b = pow(p.getY() - y, 2);
    unsigned int dist = sqrt(a+b);
    return dist;


}

unsigned int Punto::distanzaDuePunti(const Punto& a, const Punto& b) {
    unsigned int v = pow(b.getX() - a.getX(), 2);
    unsigned int z = pow(b.getY() - a.getY(), 2);
    unsigned int dist = sqrt(v+z);
    return dist;

}
