#include "triangolo.h"
#include <qvector.h>

Triangolo::Triangolo(const Punto& a, const Punto& b, const Punto& c) {
    Qvector<const Punto*> v;
    v.push_back(new Punto(a));
    v.push_back(new Punto(b));
    v.push_back(new Punto(c));
    LatiFiniti(v);
}

