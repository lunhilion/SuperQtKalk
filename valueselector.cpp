#include "valueselector.h"

ValueSelector::ValueSelector(QString title, unsigned int max_range, QWidget *parent) : QWidget(parent)
{
    QLabel* lab = new QLabel(title, this);
    QSlider* slid = new QSlider(Qt::Horizontal, this);
    slid->setRange(0,max_range);
    QSpinBox* spin = new QSpinBox(this);
    spin->setRange(0,max_range);
    spin->setValue(0);
    //connect
    connect(slid,SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),slid,SLOT(setValue(int)));
    connect(slid,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
    connect(spin,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(lab);
    layout->addWidget(slid);
    layout->addWidget(spin);
    setLayout(layout);
}

