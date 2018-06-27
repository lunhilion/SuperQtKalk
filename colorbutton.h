#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QPushButton>

class ColorButton : public QPushButton
{
public:
    ColorButton(QString, bool active=false, parent* =0);
};

#endif // COLORBUTTON_H
