#ifndef DRAWBOX_H
#define DRAWBOX_H

#include <QWidget>
#include <QPainter>
#include <QColor>

class DrawBox : public QWidget
{
    Q_OBJECT


private:
    bool drawingCircle;
    bool drawingSinglePoint;
    QPalette pal;
    QColor color;
    QPointF circleCenter;
    double circleRadius;
    QPolygonF edgedPolygon;
    QPoint singlePoint;


public:
    explicit DrawBox(QWidget *parent = 0);
    void paintEvent(QPaintEvent* PaintEvent);

signals:
    void fetchPolygon();

public slots:
    void drawCircle(QPointF,double);
    void drawEdgedPolygon(QPolygonF);
    void updateDrawingColor(QString s);
    void drawPoint(QPoint);

};

#endif // DRAWBOX_H
