#ifndef BOTTOMBOX_H
#define BOTTOMBOX_H

#include "drawbox.h"
#include <QFrame>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPalette>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class BottomBox : public QFrame
{
    Q_OBJECT

private:
    QComboBox* operandselector;
    QLCDNumber* hexlcd1;
    QLCDNumber* hexlcd2;
    QLCDNumber* hexlcd3;
    DrawBox* colorpreview1;
    DrawBox* colorpreview2;
    DrawBox* colorpreview3;

public:
    explicit BottomBox(QWidget *parent = 0);

signals:
    void setOP1(QString);
    void setOP2(QString);
    void somma();
    void sottrai();
    void media();
    void setResult(QString);

public slots:
    void operationRouting();


};

#endif // BOTTOMBOX_H
