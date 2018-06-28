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
public:
    explicit BottomBox(QWidget *parent = 0);

signals:

public slots:
};

#endif // BOTTOMBOX_H
