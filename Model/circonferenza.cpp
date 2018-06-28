#include "circonferenza.h"

Circonferenza::Circonferenza(const Punto& p, unsigned int r) : centro(p), raggio(r) {}

double Circonferenza::getArea() const {
    a = raggio * raggio * PI;

}

double Circonferenza::getPerimetro() const {
    p = 2 * raggio * PI;
    return p;
}

Punto Circonferenza::getBaricentro() {
    return centro;
}

unsigned int Circonferenza::PI = 3.14159265;

