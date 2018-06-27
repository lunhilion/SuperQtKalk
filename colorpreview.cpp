#include "colorpreview.h"

ColorPreview::ColorPreview(unsigned int i, QWidget *parent) : QWidget(parent)
{
    try {
        //color preview di RGB
        if(i == 1) {

        }
        //color preview di CYMK
        else if (i == 2) {

        }
        else {
            //return exception;
        }
    }
    catch () {
        //messaggio di errore
    }
}

