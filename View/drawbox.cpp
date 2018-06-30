#include "drawbox.h"

DrawBox::DrawBox(QWidget *parent) : QWidget(parent)
{
    pal = new QPalette();
    pal->setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(*pal);
    colorMode=0;
}


void DrawBox::paintEvent(QPaintEvent*)
{
 QPainter painter(this);
}

void DrawBox::setColorMode(int i) {
    colorMode = i;
}
