#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataManager* datamanager = new DataManager;
    MainWindow w(datamanager);
    w.show();

    return a.exec();
}
