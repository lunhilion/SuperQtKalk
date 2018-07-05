#include "latifiniti.h"
#include <QVector>


LatiFiniti::LatiFiniti(const QVector<Punto*>& v) : vertici(v) {
}

QVector<double> LatiFiniti::getLati() const {
    QVector<double> t;
    for(QVector<Punto*>::const_iterator it=vertici.begin(); it != vertici.end()-1; ++it) {
        t.push_back(Punto::distanzaDuePunti(**it,**(it+1)));
    }
    t.push_back(Punto::distanzaDuePunti(*(vertici.first()),*(vertici.last())));
    return t;
}
double LatiFiniti::getPerimetro() const {
    double perim = 0;
    QVector<double> lati = getLati();
    for(QVector<double>::const_iterator it= lati.begin();it!=lati.end();++it) {
        perim += *it;
    }
    return perim;
}

unsigned int LatiFiniti::contaVertici() const {
    unsigned int nVertici = 0;
    for(QVector<Punto*>::const_iterator cit=vertici.begin(); cit != vertici.end(); ++cit) {
        nVertici++;
    }
    return nVertici;
}

Punto LatiFiniti::getBaricentro() const {
    unsigned int nVertici = contaVertici();
    double numerX = 0;
    double numerY = 0;
    for(unsigned int i=0; i<nVertici; ++i) {
        numerX += vertici[i]->getX();
        numerY += vertici[i]->getY();
    }
    return Punto(numerX/nVertici,numerY/nVertici);

}

double LatiFiniti::getLato(unsigned int l) const {
    return getLati()[l];
}

Punto LatiFiniti::getVertice(unsigned int i) const {
    return *vertici[i];
}

void LatiFiniti::setVertice(unsigned int i, const Punto& p) {
    const_cast<Punto*>(vertici[i])->setX(p.getX());
    const_cast<Punto*>(vertici[i])->setY(p.getY());
}

void LatiFiniti::pushVertice(const Punto & p) {
    vertici.push_back(new Punto(p));
}
