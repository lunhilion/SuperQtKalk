#include "valueselector.h"

ValueSelector::ValueSelector(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout;
    lab = new QLabel(this);
    lab->setAlignment((Qt::AlignCenter));
    slid = new QSlider(Qt::Horizontal,this);
    spin = new QSpinBox(this);
    layout->addWidget(lab,0,0,1,1);
    layout->addWidget(slid,0,1,1,3);
    layout->addWidget(spin,0,4);
    setLayout(layout);

    connect(slid,SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),slid,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
}

void ValueSelector::set(const QString& s, unsigned int i, unsigned int max) {
    lab->setText(s);
    if(i>max)
        i=max;
    slid->setValue(i);
    slid->setMaximum(max);
    spin->setMaximum(max);
}
