#include "drawbox.h"

DrawBox::DrawBox(QWidget *parent) : QWidget(parent)
{
    drawingCircle = false;
    color = Qt::black;
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    emit(fetchPolygon());
}


void DrawBox::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(color);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    if(drawingCircle) {
        painter.drawEllipse(circleCenter,circleRadius,circleRadius);
    }
    else {
        painter.drawPolygon(edgedPolygon);
    }


}

void DrawBox::drawCircle(QPointF p,double d) {
    drawingCircle = true;
    circleCenter = QPointF(p.x() + width()/2, p.y() + height()/2);
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
