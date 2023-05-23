#ifndef T3DASHBOARD_H
#define T3DASHBOARD_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QtMath>
#include <QLabel>
#include <QDebug>

class T3DashBoard : public QLabel
{
public:
    explicit T3DashBoard(QWidget *parent=Q_NULLPTR);
    ~T3DashBoard();

    /**
     * @brief setCurrentAndMaxNum   设置仪表盘的当前值以及最大值
     * @param current               当前值
     * @param MaxNum                最大值
     */
    void setCurrentAndMaxNum(int current,int MaxNum);

private:

    void paintEvent(QPaintEvent *);

    void resizeEvent(QResizeEvent*);

    int         _currentScale;          //当前值与最大值的比值（百分比）
    int         _currentNum;            //当前值
    int         _MaxNum;                //最大值
};

#endif // T3DASHBOARD_H
