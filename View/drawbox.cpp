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
