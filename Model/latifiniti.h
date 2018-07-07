#ifndef LATIFINITI_H
#define LATIFINITI_H
#include "poligono.h"
#include "punto.h"
#include <QVector>

class LatiFiniti : public Poligono {
private:
  QVector<Punto*> vertici;
public:
  LatiFiniti(const QVector<Punto*>& = QVector<Punto*>());

  double getPerimetro() const;
  Punto getBaricentro() const;
  double getLato(unsigned int) const;
  QVector<double> getLati() const;
  Punto getVertice(unsigned int) const;
  void setVertice(unsigned int, const Punto&);
  double getArea() const=0;
  LatiFiniti* clone() const=0;
  unsigned int contaVertici() const;
  ~LatiFiniti();


protected:
  void pushVertice(const Punto&);

};

#endif // LATIFINITI_H
