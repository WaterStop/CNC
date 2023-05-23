#include "textticker.h"
//********************************//
//********滚动label****************//
//********************************//

TextTicker::TextTicker(QWidget *parent)
    : QWidget(parent)
{
    offset = 0;
    myTimerId = 0;
    //QTimer* change_timer = new QTimer(this);
    DealSlot();
    change_timer->start(10000);
    setAttribute(Qt::WA_StyledBackground,true);
    emit tick_end();
}
void TextTicker::setText(const QString &newText)
{
    myText=newText;
    update();
    updateGeometry();
}
QSize TextTicker::sizeHint() const
{
    return fontMetrics().size(0,text());
}

void TextTicker::paintEvent(QPaintEvent * /*event*/)
{
//    Qstyleoption opt;
//    opt.init(this);
//    QPainter p(this);
//    style()->drawPrimitive(Qstyle::PE Widget, &opt,&p,this);

    QPainter painter(this);
    //获取窗口部件字体相关信息
    int textWidth=fontMetrics().horizontalAdvance(text());
    if(textWidth<1)
        return ;
    int x=-offset;
    if(textWidth>=width())
    {
        while (x<width())
        {
            painter.drawText(x,0,textWidth,height(),Qt::AlignHCenter|Qt::AlignVCenter,text());
            x+=textWidth;
        }
    }
    else
    {
        painter.drawText(0,0,width(),height(),Qt::AlignHCenter|Qt::AlignVCenter,text());
    }
}

void TextTicker::DealSlot()
{
    connect(change_timer, SIGNAL(timeout()), this, SLOT(timeout_slot()));
}

void TextTicker::timeout_slot()
{
    if(warn_flg==1)
    {
        //emit tick_end();
    }
}

void TextTicker::showEvent(QShowEvent */*event*/)
{
    myTimerId=startTimer(100);
}

void TextTicker::timerEvent(QTimerEvent *event)
{
    if (event->timerId()==myTimerId)
    {
        ++offset;
        if (offset>=fontMetrics().horizontalAdvance(text()))
            offset=0;
        scroll(-1,0);
    }
    else{
        QWidget::timerEvent(event);
    }
}

void TextTicker::hideEvent(QHideEvent */*event*/)
{
    killTimer(myTimerId);
    myTimerId=0;
}
TextTicker::~TextTicker()
{
}

