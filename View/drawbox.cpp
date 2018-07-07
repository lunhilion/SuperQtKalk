#include "drawbox.h"
#include <iostream>

DrawBox::DrawBox(QWidget *parent) : QWidget(parent)
{
    drawingCircle = false;
    drawingSinglePoint = false;
    color = Qt::black;
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    emit(fetchPolygon());
}


void DrawBox::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen = QPen();
    pen.setWidth(2);
    pen.setColor(color);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    if(drawingSinglePoint) {
        painter.drawPoint(singlePoint);
    }
    drawingSinglePoint = false;
    if(drawingCircle) {
        painter.drawEllipse(circleCenter,circleRadius,circleRadius);
    }
    else {
        painter.drawPolygon(edgedPolygon);
    }
}

void DrawBox::drawCircle(QPointF p,double d) {
    drawingCircle = true;
    circleCenter = QPointF(p.x()+ width()/2, p.y()+ height()/2);
    circleRadius = d;
    update();
}

void DrawBox::drawEdgedPolygon(QPolygonF q) {
    drawingCircle = false;
    QPolygonF qf;
    for (int i=0; i<q.size(); ++i) {
        QPointF qp(q[i].x() + width()/2, q[i].y() + height()/2);
        qf.push_back(qp);
    }
    edgedPolygon = qf;
    update();
}

void DrawBox::updateDrawingColor(QString s) {
    color = QColor(s);
    update();
}

void DrawBox::drawPoint(QPoint p) {
    drawingSinglePoint = true;
    singlePoint.setX(p.x()+width()/2);
    singlePoint.setY(p.y()+height()/2);
    update();
}
