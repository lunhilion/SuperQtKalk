#ifndef LEFTBOX_H
#define LEFTBOX_H

#include "drawbox.h"
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>

class LeftBox : public QWidget
{
    Q_OBJECT

private:
    QComboBox* poligonSelector;
    DrawBox* drawbox;
    QPushButton* calcolaArea;
    QPushButton* calcolaPerimetro;
    QPushButton* calcolaBaricentro;
    QPushButton* calcolaLati;
public:
    explicit LeftBox(QWidget *parent = 0);

signals:

public slots:
};

#endif // LEFTBOX_H
