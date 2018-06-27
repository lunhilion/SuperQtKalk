#include "colorpanel.h"

ColorPanel::ColorPanel(unsigned int CallerButton, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* ColorLayout = new QVBoxLayout();
    if CallerButton == 1
    {
        //Costruzione di RGB control panel
        ValueSelector* R = new ValueSelector("R", RGB_MAX_VALUE);
        ValueSelector* G = new ValueSelector("G", RGB_MAX_VALUE);
        ValueSelector* B = new ValueSelector("B", RGB_MAX_VALUE);
        connect(R,SIGNAL());
        ColorLayout->addWidget(R);
        ColorLayout->addWidget(G);
        ColorLayout->addWidget(B);

    }
    if CallerButton == 2
    {
        //Costruire CYMK
    }
    ColorPreview* colorPreview = new ColorPreview();
    ColorLayout->addWidget(colorPreview);
    setLayout(ColorLayout);
}

