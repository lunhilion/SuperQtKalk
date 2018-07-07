#include "View/mainwindow.h"
#include "Controller/datamanager.h"
#include <QApplication>
#include <iostream>
#include "Exception/kalkexception.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow* view = new MainWindow();
    DataManager dm(view);

    view->show();

    return a.exec();

}

