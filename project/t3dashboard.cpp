#include "t3dashboard.h"

/********仪表盘*******/
T3DashBoard::T3DashBoard(QWidget *parent)
    :QLabel(parent)
{
    _currentScale = 0;
    _currentNum = 0;
    _MaxNum = 100;
}

T3DashBoard::~T3DashBoard()
{

}

void T3DashBoard::setCurrentAndMaxNum(int current, int MaxNum)
{
    if(current < 0 || MaxNum <= 0 || current > MaxNum)
        return;
    _currentNum = current;
    _MaxNum = MaxNum;
    //_currentScale = _currentNum*100/_MaxNum;//进度条和指针最大旋转角度
    _currentScale = _currentNum*75/_MaxNum;
    update();
}

void T3DashBoard::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    //反走样
    painter.setRenderHint(QPainter::Antialiasing);
    //使用平滑的pixmap变换算法(双线性插值算法),而不是近邻插值算法
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    //label的宽高
    int w_ = this->rect().width();
    int h_ = this->rect().height();

    int ww_ = /*10*/w_/40;//仪表盘进度条的宽度

    //仪表盘背景进度条
    //painter.setPen(QPen(QColor(96,88,153),ww_*2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //painter.setPen(QPen(QColor(96,88,153),ww_*2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //painter.setBrush(QColor(96,88,153));
    //painter.setBrush(QColor(255,0,0));

    int radius0_ = w_/2 - ww_;
    int h1_0 = radius0_/2 + ww_ + h_/2;
    QPointF p1_0(0,h1_0);
    QPointF p2_0;
    float x1_0;
    x1_0 = (w_ * 100)/100.0 + ww_;
    float y1_0;
    y1_0 = h1_0 - h1_0*100/200 - ww_;
    p2_0.setX(x1_0);
    p2_0.setY(y1_0);
    QLinearGradient rad0(p1_0,p2_0);
    //rad.setColorAt(0,QColor(117,230,228));
    //rad.setColorAt(0.5,QColor(124,181,232));
    //rad.setColorAt(1,QColor(202,165,239));
    rad0.setColorAt(0,QColor(0,255,0));
    rad0.setColorAt(0.5,QColor(255,255,0));
    rad0.setColorAt(1,QColor(255,0,0));
    rad0.setSpread(QGradient::RepeatSpread);
    painter.setPen(QPen(rad0,ww_*2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(rad0);

    //painter.drawArc(ww_,ww_,w_ - 2*ww_,h_ - 2*ww_,210*16,-1*240*16);//后两位为起始和结束角度
    painter.drawArc(ww_,ww_,w_ - 2*ww_,h_ - 2*ww_,180*16,-1*180*16);

    //仪表盘背景刻度
    painter.translate(w_/2,h_/2);//变化坐标系原点
    painter.save();//保存坐标系（此处为中心）
    painter.rotate(90);//刻度尺起始位置
    int linepenwidth_ = w_/300;
    linepenwidth_ ++;
    painter.setPen(QPen(QColor(160,175,209),linepenwidth_));
    int linewidth_ = w_/2 - 2*ww_ - ww_/2;
    for(int i = 0; i <= 100; i ++) //画刻度尺
    {
        if(i%5 == 0)
        {
            painter.drawLine(0,linewidth_ - ww_,0,linewidth_);
        }
        else
        {
            painter.drawLine(0,linewidth_ - ww_*7/10,0,linewidth_);
        }
        painter.rotate(1.8);//刻度尺覆盖范围（角度）
    }
    painter.restore();//回到保存的坐标系原点（此处为中心）

    //绘画表针
    int current_ = _currentScale;
    if(current_ < 0 || current_ > 100)
        current_ = 0;
    painter.rotate(90 + _currentScale*2.4);//指针起始 角度
    //int handLength_ = w_/2 - 4*ww_;
    int handLength_ = w_/2 - 4*ww_;
    QPolygon pts;
    pts.setPoints(4, 0,handLength_,-ww_*8/5,ww_*8,0,0, ww_*8/5,ww_*8);
    QLinearGradient rad2(0,handLength_,0,0);
    rad2.setColorAt(0,QColor(117,230,228));//指针颜色
    rad2.setColorAt(0.5,QColor(124,181,232));
    rad2.setColorAt(1,QColor(202,165,239));
    rad2.setSpread(QGradient::RepeatSpread);
    painter.setPen(Qt::NoPen);
    painter.setBrush(rad2);
    painter.drawConvexPolygon(pts);

    QLinearGradient rad3(0,-ww_/2 - 2,0,ww_/2 + 2);
    rad3.setColorAt(0,QColor(117,230,228));//圆点颜色
    rad3.setColorAt(0.5,QColor(124,181,232));
    rad3.setColorAt(1,QColor(202,165,239));
    rad3.setSpread(QGradient::RepeatSpread);
    painter.setPen(Qt::NoPen);
    painter.setBrush(rad3);
    painter.drawEllipse(-ww_/2,-ww_/2,ww_,ww_);

    //painter.rotate(-(60 + _currentScale*2.4));
    painter.rotate(-(60 + _currentScale*2.4));
    //返回原来坐标系
    painter.translate(-w_/2,-h_/2);

    //“电池已使用时长”文字
    /*painter.setPen(QPen(QColor(138,155,192),2));
    QFont font1;
    font1.setPointSize(ww_*0.9);
    painter.setFont(font1);
    painter.drawText((w_/2 - ww_*4),h_-2*ww_,ww_*8,2*ww_,Qt::AlignCenter,"电池已使用时长");

    if(_currentScale < 0 || _currentScale > 100)
        return;
        */
    //仪表盘当前进度条
    int radius_ = w_/2 - ww_;
    int h1_ = radius_/2 + ww_ + h_/2;
    QPointF p1(0,h1_);
    QPointF p2;
    float x1_;
    if(_currentScale < 25)
    {
        x1_ = (w_ * 25)/100.0 + ww_;
    }
    else
    {
        x1_ = (w_ * _currentScale)/100.0 + ww_;
    }
    float y1_;
    if(_currentScale < 50)
    {
        y1_ = h1_ - h1_*_currentScale/50 - ww_;
    }
    else
    {
        y1_ = 0;
    }
    p2.setX(x1_);
    p2.setY(y1_);
    //p2.setX(155);
    //p2.setY(0);
    //设置渐变色（进度条）
    QLinearGradient rad(p1,p2);
    //rad.setColorAt(0,QColor(/*83,211,233*/117,230,228));
    //rad.setColorAt(0.5,QColor(124,181,232));
    //rad.setColorAt(1,QColor(/*218,119,244*/202,165,239));
    rad.setColorAt(0,QColor(0,255,0));
    rad.setColorAt(0.5,QColor(255,255,0));
    rad.setColorAt(1,QColor(255,0,0));
    rad.setSpread(QGradient::RepeatSpread);

    painter.setPen(QPen(rad,ww_*2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(rad);
    //painter.drawArc(ww_,ww_,w_ - 2*ww_,h_ - 2*ww_,210*16,-1*240*16*_currentScale/100);
    //painter.drawArc(ww_,ww_,w_ - 2*ww_,h_ - 2*ww_,210*16,-1*240*16*_currentScale/100);//指针进度之前的颜色


    //仪表盘显示表盘数字
#if 0
    painter.translate(w_/2,h_/2);
    QLinearGradient rad11(-(w_/2 - ww_*4),0,w_/2 - ww_*4,0);
    rad11.setColorAt(0,QColor(/*83,211,233*/117,230,228));
    rad11.setColorAt(0.5,QColor(124,181,232));
    rad11.setColorAt(1,QColor(/*218,119,244*/202,165,239));
    rad11.setSpread(QGradient::RepeatSpread);
    painter.setPen(QPen(rad,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(rad);

    QFont font22;
    font22.setPointSize((w_/2 - ww_*4)*0.25);
    painter.setFont(font22);

    painter.drawText(-(w_/2 - ww_*4),-ww_*2,w_/2 - ww_*4 + ww_/2,ww_*2,Qt::AlignCenter,QString::number(_currentNum));
    painter.drawLine(2*ww_,-ww_*2,-2*ww_,ww_*2);
    painter.drawText(- ww_/2,0,w_/2 - ww_*4 + ww_/2,ww_*2,Qt::AlignCenter,QString::number(_MaxNum) + "h");
#endif
    //设置当前值文字及最大值文字 下方百分比
    painter.translate(w_/2,h_/2 + h_/4 + ww_);
    int numWidth_ = w_/2 - ww_*4;
    QLinearGradient rad1(-(numWidth_),0,numWidth_,0);
    //rad1.setColorAt(0,QColor(/*83,211,233*/117,230,228));
    //rad1.setColorAt(0.5,QColor(124,181,232));
    //rad1.setColorAt(1,QColor(/*218,119,244*/202,165,239));
    rad1.setColorAt(0,QColor(0,255,0));
    rad1.setColorAt(0.5,QColor(255,255,0));
    rad1.setColorAt(1,QColor(255,0,0));


    rad1.setSpread(QGradient::RepeatSpread);
    painter.setPen(QPen(rad,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(rad);
    QFont font;
    font.setPointSize((ww_*2)*0.8);
    painter.setFont(font);
    //painter.drawText(-numWidth_,-ww_,numWidth_,ww_*2,Qt::AlignCenter,QString::number(_currentNum) + "h");
    //painter.drawLine(ww_/2,-ww_,-ww_/2,2*ww_);
    //painter.drawText(0,0,numWidth_,ww_*2,Qt::AlignCenter,QString::number(_MaxNum) + "h");
}

void T3DashBoard::resizeEvent(QResizeEvent *)
{
    int w_ = this->width();
    int h_ = this->height();
    if(w_ > h_)
    {
        this->resize(w_,w_);
    }
    else if(w_ < h_)
    {
        this->resize(h_,h_);
    }
    update();
}
/*********仪表盘*********/
