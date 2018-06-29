#ifndef LATIFINITI_H
#define LATIFINITI_H
#include "poligono.h"
#include "punto.h"
#include <QVector>

class LatiFiniti : public Poligono {
private:
  QVector<const Punto*> vertici;    //vector costante o no?
public:
  LatiFiniti(const QVector<const Punto*>&);

  double getPerimetro() const;
  Punto getBaricentro() const;
  virtual ~LatiFiniti();
  double getLato(unsigned int) const;
  QVector<double> getLati() const;
  Punto getVertice(unsigned int) const;
  void setVertice(unsigned int, const Punto&);
};

//qui implementiamo tutto meno che il getArea. Quindi questa classe è virtuale

#endif // LATIFINITI_H
