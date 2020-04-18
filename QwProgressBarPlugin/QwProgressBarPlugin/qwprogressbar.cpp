#include "qwprogressbar.h"


QwProgressBar::QwProgressBar(QWidget *parent) : QWidget(parent)
{

}

void QwProgressBar::setPercent(int Percent){
    percent = qMin(100,qMax(0,Percent));
    emit statueChanged(percent);
    repaint();
}

int QwProgressBar::getPercent(){
    return percent;
}


void QwProgressBar::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter    painter(this);//创建对象
    //设置尺寸
    int w = width();
    int h = height();
    //通过视口、窗口可以设置固定比例的控件
    //int minSide = qMin(w/5,h);
    //QRect rect(qAbs(w-minSide*5)/2,qAbs(h-minSide)/2,minSide*5,minSide);
    //painter.setViewport(rect);
    //painter.setWindow(-50,-10,100,20);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    //设置画笔
    QPen    pen;
    pen.setWidth(1); //线宽
    pen.setColor(Qt::green); //划线颜色
    pen.setStyle(Qt::SolidLine);//线的类型，实线、虚线等
    pen.setCapStyle(Qt::RoundCap);//线端点样式
    pen.setJoinStyle(Qt::BevelJoin);//线的连接点样式
    painter.setPen(pen);

    //设置画刷
    QBrush  brush;
    brush.setColor(Qt::green); //画刷颜色
    brush.setStyle(Qt::NoBrush); //画刷填充样式
    painter.setBrush(brush);


    //设置字体
    QFont    font;
    font.setPixelSize(18);
    font.setBold(true);
    painter.setFont(font);


    //画进度条SolidPattern
    QRectF rectf(0,0,w,h);
    painter.drawRoundedRect(rectf,h/2,h/2);
    if(percent>0){
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);
        int length = (qMax(percent,5)*1.0/100.0)*w;
        QRectF rectf2(0,0,length,h);
        painter.drawRoundedRect(rectf2,h/2,h/2);

        pen.setColor(Qt::black); //划线颜色
        painter.setPen(pen);
        QString percentStr=QString::asprintf("%d%%",percent);
        painter.drawText(qMin(w-42,length+2),h/2+7,percentStr);
    }

}













