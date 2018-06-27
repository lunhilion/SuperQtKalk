#ifndef TRIANGLEPREVIEW_H
#define TRIANGLEPREVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QVBoxLayout>

class TrianglePreview : public QWidget
{
    Q_OBJECT
public:
    explicit TrianglePreview(QWidget *parent = 0);

signals:

public slots:
};

#endif // TRIANGLEPREVIEW_H
