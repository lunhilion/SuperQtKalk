#include "View/mainwindow.h"
#include "Controller/datamanager.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
//    Colore* a = new Cmyk("#90AA14");
//    Colore* b = new Rgb("#516264");
//    Colore* c = a->media(*b);
//    std::cout << c->getHex().toStdString();
    QApplication a(argc, argv);
    MainWindow* view = new MainWindow();
    DataManager dm(view);

    view->show();

    return a.exec();
}
