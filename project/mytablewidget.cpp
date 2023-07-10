#include "mytablewidget.h"
#include "ui_mytablewidget.h"
#include <QScrollBar>
#include <QScrollBar>

//**************表格滑动以及回弹****//

MyTableWidget::MyTableWidget(QWidget *parent) : QTableWidget(parent),
    m_pressedAxis(0, 0),
    m_curAdjustScrollBar( this->verticalScrollBar() ),
    m_sliderDir(DIR_DEFAULT),
    m_movedFlag(false),
    m_pressedFlag(false),
    m_initOneTimeFlag(false),
    m_scrollBarVal(0),
    m_preOffset(0),
    m_adjustedCellNo(0),
    m_preValSaved(0)
{
    m_timer = new QTimer();
    m_timer->stop();
    connect(m_timer, &QTimer::timeout, this, &MyTableWidget::slotTimerOut);

}
MyTableWidget::~MyTableWidget()
{
}
void MyTableWidget::setSliderDir(ENUM_SLIDER_DIR dir)
{
    m_sliderDir = dir;
    // 区分横向或纵向，暂不同时支持横向纵向
    if ( DIR_VERI == m_sliderDir )
    {
        m_curAdjustScrollBar = this->verticalScrollBar();
        setWHFunPtr = &MyTableWidget::setRowHeight;
    }
    else
    {
        m_curAdjustScrollBar = this->horizontalScrollBar();
        setWHFunPtr = &MyTableWidget::setColumnWidth;
    }
}


void MyTableWidget::slotTimerOut()
{
    int curVal = ( DIR_VERI == m_sliderDir ) ? rowHeight(m_adjustedCellNo) :columnWidth(m_adjustedCellNo);
    if ( curVal <= 5 || m_preValSaved == curVal )
    {
        m_timer->stop();
        if ( DIR_VERI == m_sliderDir )
        {
            removeRow(m_adjustedCellNo);
            setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        }
        else
        {
            removeColumn(m_adjustedCellNo);
        }
        // qDebug() << "m_timer->stop(); remove m_adjustedCellNo=" << m_adjustedCellNo;
        m_adjustedCellNo = -1;
        m_preValSaved = 0;
    }
    else
    {
        // qDebug() << "curVal=" << curVal;
        m_preValSaved = curVal;
        (this->*setWHFunPtr)( m_adjustedCellNo, curVal/2 );
    }
}


void MyTableWidget::implReboundEffect( int overBoderVal )
{
    if (false == m_initOneTimeFlag)
    {
        m_initOneTimeFlag = true;
        if ( DIR_VERI == m_sliderDir )
        {
            m_adjustedCellNo = (overBoderVal<0) ? 0 : rowCount();
            insertRow(m_adjustedCellNo);
            if ( !verticalScrollBar()->isVisible() )
            {
                setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            }
        }
        else
        {
            m_adjustedCellNo = (overBoderVal<0) ? 0 : columnCount();
            insertColumn(m_adjustedCellNo);
        }
        m_preOffset = m_curAdjustScrollBar->maximum();
        // qDebug() << "m_sliderDir=" << m_sliderDir << ", m_adjustedCellNo=" << m_adjustedCellNo;
    }
    overBoderVal = (overBoderVal > 0 ) ? overBoderVal-m_preOffset : overBoderVal;
    (this->*setWHFunPtr)(m_adjustedCellNo, abs(overBoderVal));
}
void MyTableWidget::mousePressEvent(QMouseEvent *ev)
{
    m_scrollBarVal = m_curAdjustScrollBar->value();
    m_pressedAxis = ev->pos();
    m_preOffset = 0;
    m_pressedFlag = true;
    m_scrollBarLastMaxVal = 0;
    m_initOneTimeFlag = false;
    if ( m_timer->isActive() )
    {
        (this->*setWHFunPtr)(m_adjustedCellNo, 0 );
        slotTimerOut();
    }


   QTableWidget::mousePressEvent( ev );
}


void MyTableWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if ( false == m_pressedFlag )
    {
        // 未经过按下事件，不应到这里来
       QTableWidget::mouseMoveEvent( ev );
        return;
    }
    int curXPos = ev->x(), curYPos = ev->y();
    int max = 0, offset = 0;
    if ( DIR_VERI == m_sliderDir )
    {
        offset = curYPos - m_pressedAxis.y();
    }
    else
    {
        offset = curXPos - m_pressedAxis.x();
    }
    max = m_curAdjustScrollBar->maximum();


    if ( m_preOffset != offset )
    {
        int  curScrollBarVal = m_scrollBarVal-offset;
        if ( curScrollBarVal < 0 )
        {
            implReboundEffect(curScrollBarVal);
            curScrollBarVal = 0;
        }
        else if ( curScrollBarVal > max )
        {
            // qDebug() << "max=" << max << ",overBoderVal=" << curScrollBarVal-max;
            implReboundEffect(curScrollBarVal);
            curScrollBarVal = m_curAdjustScrollBar->maximum();
        }
        m_curAdjustScrollBar->setValue(curScrollBarVal);
        m_preOffset = offset;
    }


   // 考虑到触屏精度不高，手指点击不动时也会有坐标也略有跳动，在此增加判断条件--滑动超过10个像素才视为已经滑动
    int tmpDiffPosX = curXPos-m_pressedAxis.x();
    int tmpDiffPosY = curYPos-m_pressedAxis.y();
    tmpDiffPosX = (tmpDiffPosX>0) ? tmpDiffPosX : (0-tmpDiffPosX);
    tmpDiffPosY = (tmpDiffPosY>0) ? tmpDiffPosY : (0-tmpDiffPosY);
    if ( tmpDiffPosX > 10 || tmpDiffPosY > 10 )
    {
        m_movedFlag = true;
    }
}

void MyTableWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if( true == m_initOneTimeFlag )
    {
        m_initOneTimeFlag = false;
        m_timer->start(50);
    }
    // 把滑动过程中可能选中了的取消
    setCurrentItem(NULL);
    m_pressedAxis = QPoint(0, 0);
    m_preOffset = 0;
    m_pressedFlag = false;
    if ( m_movedFlag == true )
    {
        m_movedFlag = false;
        // 正常情况下，滑动后松手单元格会被选中，这里截断mouseReleaseEvent不继续传递，保证滑动完不会选中单元格
        return;
    }
    QTableWidget::mouseReleaseEvent( ev );
}
