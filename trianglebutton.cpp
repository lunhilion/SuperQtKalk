#include "trianglebutton.h"

TriangleButton::TriangleButton(QWidget* parent) :QPushButton("Triangolo",parent)
{

}

PoligonPreview* buildPoligonPreview() const {
    //crea il widget di poligonPreview

    QPushButton*
    PoligonPreview* r = new PoligonPreview;
    return r;
}
