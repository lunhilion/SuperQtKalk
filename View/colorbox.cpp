#include "colorbox.h"

ColorBox::ColorBox(QWidget *parent) : QWidget(parent)
{
    pal = new QPalette();
    pal->setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(*pal);
}

void ColorBox::repaintBackground(QString s) {
    pal->setColor(QPalette::Background,s);
    setPalette(*pal);
}

ColorBox::~ColorBox() {
    delete pal;
}
