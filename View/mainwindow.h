#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawbox.h"
#include "leftbox.h"
#include "rightbox.h"
#include "bottombox.h"
#include <QMainWindow>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>





class MainWindow : public QWidget
{
    Q_OBJECT
private:
    LeftBox* leftbox;
    RightBox* rightbox;
    BottomBox* bottombox;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void newColorOperand(int);
    void setColorOperandMaxValues(uint);
    void val1changed(int);
    void val2changed(int);
    void val3changed(int);
    void val4changed(int);
    void setCol1Preview(QString);
    void col1toOP1();
    void col1toOP2();
    void setOP1(QString);
    void setOP2(QString);
    void somma();
    void sottrai();
    void media();
    void setResult(QString);

};

#endif // MAINWINDOW_H
