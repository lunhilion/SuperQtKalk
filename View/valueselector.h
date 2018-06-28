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
public:
    explicit ValueSelector(const QString&, QWidget *parent = 0);
    void setText(const QString&);

signals:
    int valueChanged(int);

public slots:

};

#endif // VALUESELECTOR_H
