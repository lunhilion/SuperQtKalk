#include "circonferenza.h"
#include "punto.h"

Circonferenza::Circonferenza(const Punto& p, unsigned int r) : centro(p), raggio(r) {}

double Circonferenza::getArea() const {
    double a = raggio * raggio * M_PI;
    return a;

}

double Circonferenza::getPerimetro() const {
    double p = 2 * raggio * M_PI;
    return p;
}

Punto Circonferenza::getBaricentro() const {
    return centro;
}

Circonferenza* Circonferenza::clone() const {
    return new Circonferenza(*this);
}

double Circonferenza::getRaggio() const {
    return raggio;
}
