#include "drawbox.h"

DrawBox::DrawBox(QWidget *parent) : QWidget(parent)
{
    pal = new QPalette();
    pal->setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(*pal);
}


void DrawBox::paintEvent(QPaintEvent*)
{
 QPainter painter(this);
}

void DrawBox::repaintBackground(QString s) {
    pal->setColor(QPalette::Background,s);
    setPalette(*pal);
}
