#ifndef COLORBOX_H
#define COLORBOX_H

#include <QWidget>
#include <QPainter>

class ColorBox : public QWidget
{
    Q_OBJECT

public:
    explicit ColorBox(QWidget *parent = 0);

private:
    QPalette* pal;

signals:

public slots:
    void repaintBackground(QString);
};

#endif // COLORBOX_H
