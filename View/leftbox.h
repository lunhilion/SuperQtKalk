#ifndef LEFTBOX_H
#define LEFTBOX_H

#include "drawbox.h"
#include <QFrame>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>

class LeftBox : public QFrame
{
    Q_OBJECT

private:
    QComboBox* polygonSelector;
    DrawBox* drawbox;
    QPushButton* calcolaArea;
    QPushButton* calcolaPerimetro;
    QPushButton* calcolaBaricentro;
    QPushButton* calcolaLati;
    QLCDNumber* lcdLato1;
    QLCDNumber* lcdLato2;
    QLCDNumber* lcdLato3;
    QLCDNumber* lcdLato4;
    QLCDNumber* lcdArea;
    QLCDNumber* lcdPerimetro;
public:
    explicit LeftBox(QWidget *parent = 0);

signals:
    void fetchPolygon(int);
    void drawCircle(QPointF,double);
    void drawEdgedPolygon(QPolygonF);
    void updateDrawingColor(QString);
    void findArea();
    void findPerimetro();
    void findBaricentro();
    void findLati();
    void drawPoint(QPoint);
    void sendRadius(double);
    void sendPolygon(QPolygonF);


public slots:
    void setPolygonMode(int);
    void showArea(double);
    void showPerimetro(double);
    void showBaricentro(QPoint);
    void showLati(QVector<double>);
    void polygonRouter();
};

#endif // LEFTBOX_H
