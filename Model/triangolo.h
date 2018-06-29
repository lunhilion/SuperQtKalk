#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "latifiniti.h"

class Triangolo : public LatiFiniti {
public:
  Triangolo(const QVector<const Punto *>&);
  double getArea() const; //con magica formula di Erone
  Triangolo* clone() const;

};

//una funzionalità di triangolo a livello di GUI può essere quella di disegnare una circonferenza circoscritta

#endif // TRIANGOLO_H
