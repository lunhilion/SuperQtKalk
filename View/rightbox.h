#ifndef RIGHTBOX_H
#define RIGHTBOX_H

#include "valueselector.h"
#include "drawbox.h"
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
    ValueSelector* val1;
    ValueSelector* val2;
    ValueSelector* val3;
    ValueSelector* val4;
    DrawBox* colorpreview;

public:
    explicit RightBox(QWidget *parent = 0);

signals:

public slots:
    void setMode(int);
};

#endif // RIGHTBOX_H
