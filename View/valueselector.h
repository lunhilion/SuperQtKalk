#ifndef VALUESELECTOR_H
#define VALUESELECTOR_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QGridLayout>
#include <QString>

class ValueSelector : public QWidget
{
    Q_OBJECT

private:
    QLabel* lab;
    QSlider* slid;
    QSpinBox* spin;

public:
    explicit ValueSelector(QWidget *parent = 0);
    void set(const QString&, unsigned int, unsigned int);

signals:
    int valueChanged(int);

public slots:

};

#endif // VALUESELECTOR_H
