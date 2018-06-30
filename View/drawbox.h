#ifndef DRAWBOX_H
#define DRAWBOX_H

#include <QWidget>
#include <QPainter>

class DrawBox : public QWidget
{
    Q_OBJECT

private:
    QPalette* pal;
    int colorMode;

public:
    explicit DrawBox(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void setColorMode(int);
};

#endif // DRAWBOX_H
