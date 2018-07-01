#ifndef DRAWBOX_H
#define DRAWBOX_H

#include <QWidget>
#include <QPainter>

class DrawBox : public QWidget
{
    Q_OBJECT

private:
    QPalette* pal;

public:
    explicit DrawBox(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void repaintBackground(QString);
};

#endif // DRAWBOX_H
