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
public:
    explicit LeftBox(QWidget *parent = 0);

signals:
    void fetchPolygon(int);
    void drawCircle(QPointF,double);
    void drawEdgedPolygon(QPolygonF);

public slots:
    void setPolygonMode(int);
};

#endif // LEFTBOX_H
