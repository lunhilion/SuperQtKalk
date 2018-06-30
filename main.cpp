#include "View/mainwindow.h"
#include "Controller/datamanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    const Punto* ca = new Punto(10,10);
    ca->getX();
    QApplication a(argc, argv);
    MainWindow* view = new MainWindow();
    DataManager dm(view);

    view->show();

    return a.exec();
}
