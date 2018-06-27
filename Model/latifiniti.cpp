#include "latifiniti.h"

LatiFiniti::LatiFiniti(const Qvector<const Punto*>& v) {
    vertici = v;
}

Qvector<double> LatiFiniti::getLati() const {
    Qvector<double> t;
    for(Qvector<const Punto*>::const_iterator it=vertici.begin(); it != vertici.end(); ++it) {
        t.push_back(Punto::distanzaDuePunti(*it,*(it+1)));
    }
    t.push_back(Punto::vertici.first(),vertici.last());
    return t;
}
double LatiFiniti::getPerimetro() const {
    double perim = 0;
    Qvector<double> lati = getLati();
    for(Qvector<double>::const_iterator it= lati.begin();it!=lati.end();++it) {
        perim += *it;
    }
    return perim;
}

