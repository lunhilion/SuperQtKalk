#include "drawbox.h"
#include <iostream>
#include <qmath.h>

DrawBox::DrawBox(QWidget *parent) : QWidget(parent)
{
    drawingCircle = false;
    drawingSinglePoint = false;
    mousePressed = false;
    color = Qt::black;
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    //emit(fetchPolygon());
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

void DrawBox::mousePressEvent(QMouseEvent *event) {
    if(drawingCircle) {
        double x = event->x()-circleCenter.x();
        double y = event->y()-circleCenter.y();
        double r = sqrt(pow(x, 2) + pow(y, 2));
        if(r > circleRadius-10 && r < circleRadius+10)
            mousePressed = true;
    }
    else {
        int i = 0;
        while(i<edgedPolygon.size() && mousePressed == false) {
            double x = event->pos().x();
            double y = event->pos().y();
            if(x > edgedPolygon[i].x()-10  &&  x < edgedPolygon[i].x()+10  &&  y > edgedPolygon[i].y()-10  &&  y < edgedPolygon[i].y()+10) {
                mousePressed = true;
                grabbed = i;
            }
            i++;
        }
    }
}

void DrawBox::mouseMoveEvent(QMouseEvent *event) {
    if(event->type() == QEvent::MouseMove && mousePressed == true) {
        if(drawingCircle) {
            double x = event->x()-circleCenter.x();
            double y = event->y()-circleCenter.y();
            double r = sqrt(pow(x, 2) + pow(y, 2));
            circleRadius = r;
            update();
        }
        else {
            edgedPolygon[grabbed].setX(event->x());
            edgedPolygon[grabbed].setY(event->y());
            update();
        }
    }
}

void DrawBox::mouseReleaseEvent(QMouseEvent*) {
    mousePressed = false;
    if(drawingCircle)
        emit(sendRadius(circleRadius));
    else
        emit(sendPolygonPoint(edgedPolygon[grabbed],grabbed));
    update();
}
