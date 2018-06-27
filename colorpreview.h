#ifndef COLORPREVIEW_H
#define COLORPREVIEW_H

#include <QWidget>

class ColorPreview : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPreview(unsigned int, QWidget *parent = 0);

signals:

public slots:
};

#endif // COLORPREVIEW_H
