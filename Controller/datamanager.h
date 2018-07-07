#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QString>
#include "Model/circonferenza.h"
#include "Model/quadrilatero.h"
#include "Model/triangolo.h"
#include "Model/rgb.h"
#include "Model/cmyk.h"
#include "View/mainwindow.h"



class DataManager : public QObject {

    Q_OBJECT

private:
    MainWindow* view;
    Poligono* poli;
    Colore* col1;
    Colore* op1;
    Colore* op2;
    Colore* colorResult;
    Colore* polygonColor;

    void initializeOperands(int, int);


public:
    unsigned int getColorOperandMaxValue() const;
    DataManager(MainWindow*);

signals:
    void setColorOperandMaxValues(unsigned int);
    void setColorMode(int);
    void setCol1Preview(QString);
    void setOP1(QString);
    void setOP2(QString);
    void setResult(QString);
    void drawCircle(QPointF,double);
    void drawEdgedPolygon(QPolygonF);
    void setPolygonMode(int);
    void updateDrawingColor(QString);
    void showArea(double);
    void showPerimetro(double);
    void showBaricentro(QPoint);
    void showLati(QVector<double>);

public slots:
    void newColorOperand(int);
    void setval1(int);
    void setval2(int);
    void setval3(int);
    void setval4(int);
    void col1toOP1();
    void col1toOP2();
    void col1toPolygonColor();
    void colorResulttoPolygonColor();
    void somma();
    void sottrai();
    void media();
    void fetchPolygon(int);
    void findArea();
    void findPerimetro();
    void findBaricentro();
    void findLati();
    void drawPolygon(int);
    void setRadius(double);
    void setPolygonPoint(QPointF,uint);

};

#endif // DATAMANAGER_H
