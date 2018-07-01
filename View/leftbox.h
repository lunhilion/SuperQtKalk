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
    QComboBox* poligonSelector;
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
    void fetchPolygon();

public slots:
    void setMode(int);
};

#endif // LEFTBOX_H
