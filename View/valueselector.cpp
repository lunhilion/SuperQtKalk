#include "valueselector.h"

ValueSelector::ValueSelector(const QString& s, QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout;
    lab = new QLabel(s,this);
    lab->setAlignment((Qt::AlignCenter));
    QSlider* slid = new QSlider(Qt::Horizontal,this);
    QSpinBox* spin = new QSpinBox(this);
    layout->addWidget(lab,0,0,1,1);
    layout->addWidget(slid,0,1,1,3);
    layout->addWidget(spin,0,4);
    setLayout(layout);

    connect(slid,SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),slid,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
}

void ValueSelector::setText(const QString& s) {
    lab->setText(s);
}
