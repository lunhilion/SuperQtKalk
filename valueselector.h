#ifndef VALUESELECTOR_H
#define VALUESELECTOR_H

#include <QWidget>

class ValueSelector : public QWidget
{
    Q_OBJECT
public:

    explicit ValueSelector(QString, unsigned int, QWidget *parent = 0);
signals:
    void valueChanged(int);
public slots:
};

#endif // VALUESELECTOR_H
