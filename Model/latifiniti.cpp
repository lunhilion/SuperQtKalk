#include "latifiniti.h"
#include <QVector>


LatiFiniti::LatiFiniti(const QVector<const Punto*>& v) : vertici(v) {
}

QVector<double> LatiFiniti::getLati() const {
    QVector<double> t;
    for(QVector<const Punto*>::const_iterator it=vertici.begin(); it != vertici.end(); ++it) {
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

Punto LatiFiniti::getBaricentro() const {
    unsigned int nVertici = 0;
    unsigned int numerX = 0;
    unsigned int numerY = 0;
    for(QVector<const Punto*>::const_iterator it=vertici.begin(); it != vertici.end(); ++it) {
        nVertici++;
        numerX += (*it)->getX();
        numerY += (*it)->getY();
    }
    return Punto(numerX/nVertici,numerY/nVertici);

}

double LatiFiniti::getLato(unsigned int l) const {
    return getLati()[l];
}

Punto LatiFiniti::getVertice(unsigned int i) const {
    return *(vertici[i]);
}

void LatiFiniti::setVertice(unsigned int i, const Punto& p) {
    const_cast<Punto*>(vertici[i])->setX(p.getX());
    const_cast<Punto*>(vertici[i])->setY(p.getY());
}

