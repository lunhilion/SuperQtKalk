#ifndef RIGHTBOX_H
#define RIGHTBOX_H

#include "valueselector.h"
#include "colorbox.h"
#include <QFrame>
#include <QComboBox>
#include <QSlider>
#include <QSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPalette>
#include <QPushButton>

class RightBox : public QFrame
{
    Q_OBJECT

private:
    QComboBox* colorSelector;
    unsigned int colorOperandMaxValue;
    ValueSelector* val1;
    ValueSelector* val2;
    ValueSelector* val3;
    ValueSelector* val4;
    ColorBox* colorpreview;
    QLCDNumber* hexlcd;

public:
    explicit RightBox(QWidget *parent = 0);
    ~RightBox();


signals:

    void newColorOperand(int);
    void val1changed(int);
    void val2changed(int);
    void val3changed(int);
    void val4changed(int);
    void setCol1Preview(QString);
    void col1toOP1();
    void col1toOP2();
    void col1toPolygonColor();

public slots:
    void setColorMode(int);
    void setColorOperandMaxValues(uint);
};

#endif // RIGHTBOX_H
