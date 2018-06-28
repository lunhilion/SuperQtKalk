#include "circonferenza.h"
#include "punto.h"

Circonferenza::Circonferenza(const Punto& p, unsigned int r) : centro(p), raggio(r) {}

double Circonferenza::getArea() const {
    double a = raggio * raggio * PI;
    return a;

}

double Circonferenza::getPerimetro() const {
    double p = 2 * raggio * PI;
    return p;
}

Punto Circonferenza::getBaricentro() const {
    return centro;
}

unsigned int Circonferenza::PI = 3.14159265;

