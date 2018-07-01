#ifndef DRAWBOX_H
#define DRAWBOX_H

#include <QWidget>
#include <QPainter>

class DrawBox : public QWidget
{
    Q_OBJECT

public:
    explicit DrawBox(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    enum Shape {none,circle,triangle,square};

private:
    QPalette* pal;
    Shape activeshape;

signals:

public slots:
    void repaintBackground(QString);
    void setMode(Shape s);
};

#endif // DRAWBOX_H
