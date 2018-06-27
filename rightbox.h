#ifndef RIGHTBOX_H
#define RIGHTBOX_H

#include <QWidget>
#include <QComboBox>
#include <QSlider>
#include <QSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPalette>

class RightBox : public QWidget
{
    Q_OBJECT

private:
    QComboBox* colorSelector;
    QSlider* slid1;
    QSlider* slid2;
    QSlider* slid3;
    QSlider* slid4;
    QSpinBox* spin1;
    QSpinBox* spin2;
    QSpinBox* spin3;
    QSpinBox* spin4;
    QWidget* colorpreview;

public:
    explicit RightBox(QWidget *parent = 0);

signals:

public slots:
};

#endif // RIGHTBOX_H
