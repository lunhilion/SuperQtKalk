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

public slots:


};

#endif // BOTTOMBOX_H
