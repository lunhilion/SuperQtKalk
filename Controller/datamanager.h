#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QString>
#include "Model/poligono.h"
#include "Model/rgb.h"
#include "Model/cmyk.h"
#include "View/mainwindow.h"



class DataManager : public QObject {

    Q_OBJECT

private:
    MainWindow* view;
    Poligono* poli;
    Colore* col1;
    Colore* col2;
    Colore* col3;
    Colore* col4;


public:
    unsigned int getColorOperandMaxValue() const;
    DataManager(MainWindow*);

signals:
    void setColorOperandMaxValues(unsigned int);
    void setCol1Preview(QString);

public slots:
    void newColorOperand(int);
    void setval1(int);
    void setval2(int);
    void setval3(int);
    void setval4(int);

};

#endif // DATAMANAGER_H
