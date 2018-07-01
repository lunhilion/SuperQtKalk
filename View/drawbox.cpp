#include "drawbox.h"

DrawBox::DrawBox(QWidget *parent) : QWidget(parent)
{
    pal = new QPalette();
    pal->setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(*pal);
}


void DrawBox::paintEvent(QPaintEvent* paintEvent)
{
    QPainter painter(this);
   // painter.drawEllipse(0,0,20,20);
}

void DrawBox::repaintBackground(QString s) {
    pal->setColor(QPalette::Background,s);
    setPalette(*pal);
}
