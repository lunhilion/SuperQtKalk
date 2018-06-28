#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <Model/poligono.h>
#include <Model/colore.h>

class DataManager
{
private:
    Poligono* poli;
    Colore* col1;
    Colore* col2;
    Colore* col3;


public:
    DataManager();
};

#endif // DATAMANAGER_H
