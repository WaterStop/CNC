#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QMouseEvent>
#include <QTimer>

namespace Ui {
class MyTableWidget;
}

enum ENUM_SLIDER_DIR{ DIR_DEFAULT = 0, DIR_VERI = 0, DIR_HORI };

class MyTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit MyTableWidget(QWidget *parent = nullptr);
    ~MyTableWidget();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void sigWindowMove(QPoint posDiff);
    void sigLoadMoreCandidate();


public slots:
    void slotTimerOut();

public:
    // 设置在QTableWidget中拖动时允许左拖动还是右拖动
    void setSliderDir(ENUM_SLIDER_DIR dir);

private:
    void implReboundEffect( int curScrollBarVal );

private:
    QTimer *m_timer;
    QPoint  m_pressedAxis;
    QScrollBar *m_curAdjustScrollBar;
    ENUM_SLIDER_DIR m_sliderDir;
    bool m_enableMove;
    bool m_movedFlag;
    bool m_pressedFlag;
    bool m_initOneTimeFlag;
    int  m_scrollBarVal;
    int  m_preOffset;
    int  m_scrollBarLastMaxVal;


   unsigned short  m_adjustedCellNo;
   unsigned short  m_preValSaved;
   typedef void (MyTableWidget::*funPtr)(int, int);
   funPtr setWHFunPtr;
};

#endif // MYTABLEWIDGET_H
