#ifndef QWPROGRESSBAR_H
#define QWPROGRESSBAR_H

#include <QtUiPlugin/QDesignerExportWidget>
#include <QWidget>
#include <QPainter>
#include <QColor>

class QDESIGNER_WIDGET_EXPORT QwProgressBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int  percent READ getPercent WRITE setPercent NOTIFY statueChanged DESIGNABLE true)

public:
    explicit QwProgressBar(QWidget *parent = 0);
    int getPercent();
    void setPercent(int Percent);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    int percent=30;
signals:
    void   statueChanged(int);
public slots:
};

#endif
