#include "drawbox.h"

DrawBox::DrawBox(QWidget *parent) : QWidget(parent)
{
    pal = new QPalette();
    activeshape = none;
    pal->setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(*pal);
}


void DrawBox::paintEvent(QPaintEvent* paintEvent)
{
    /*
    QPainter painter(this);
    switch (activeshape){
    case none:
        break;

    case circle:
        painter.drawEllipse(0,0,30,30);
        break;

    case triangle:
        QPoint points[3] = {(10,10),(10,40),(25,25)};
        painter.drawConvexPolygon(points,3);
        break;

    case square:
        QPoint points[4] = {(10,10),(10,40),(40,40),(40,10)};
        painter.drawConvexPolygon(points,4);
        break;

    default:
        //geastione eccezione
        break;
    }
    */
}

void DrawBox::repaintBackground(QString s) {
    pal->setColor(QPalette::Background,s);
    setPalette(*pal);
}

void DrawBox::setMode(Shape s) {
    activeshape = s;
    update();
}
