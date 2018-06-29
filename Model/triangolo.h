#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "latifiniti.h"

class Triangolo : public LatiFiniti {
public:
  Triangolo(QVector<const Punto *>);
  ~Triangolo();
  double getArea() const; //con magica formula di Erone

};

//una funzionalità di triangolo a livello di GUI può essere quella di disegnare una circonferenza circoscritta

#endif // TRIANGOLO_H
