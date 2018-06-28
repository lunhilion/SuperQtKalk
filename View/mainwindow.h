#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Controller/datamanager.h"
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
    DataManager* dm;
    LeftBox* leftbox;
    RightBox* rightbox;
    BottomBox* bottombox;


public:
    explicit MainWindow(DataManager*,QWidget *parent = 0);
    ~MainWindow();

};

#endif // MAINWINDOW_H
