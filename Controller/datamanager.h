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
    Colore* col5;


public:
    unsigned int getColorOperandMaxValue() const;
    DataManager(MainWindow*);

signals:
    void setColorOperandMaxValues(unsigned int);
    void setCol1Preview(QString);
    void setOP1(QString);
    void setOP2(QString);
    void setResult(QString);

public slots:
    void newColorOperand(int);
    void setval1(int);
    void setval2(int);
    void setval3(int);
    void setval4(int);
    void col1toOP1();
    void col1toOP2();
    void somma();
    void sottrai();
    void media();
};

#endif // DATAMANAGER_H
