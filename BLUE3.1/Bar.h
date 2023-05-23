#ifndef BAR_H
#define BAR_H

#include<iostream>
#include <QWidget>
#include <QPainter>
#include <cmath>
#include<machineStruct.h>
using namespace std;


// ************棒料类：主要处理棒料的属性和操作*****************

#define BYTE unsigned char
#define  MAX(a, b) ((a) > (b) ? (a) : (b))
#define  MIN(a, b) ((a) < (b) ? (a) : (b))


class Bar
{

public:
    // 构造函数
    Bar(int m_canvasWidth, int m_canvasHeight);
    ~Bar();
    // 棒料的输入是一半高度，并且居中
    bool barInit(int width, int height);

    // n个   工艺函数（起始点，进刀量，进刀次数，···）
    // 作用：通过参数计算完成该工艺后形成的顶点坐标序列


    // 将bar中工艺的startCord起始点设置为bar的左下角
    void setStartCord(coordinate &startCord);



    // 横向加工
    bool transverseMachining(coordinate startCord, int len, int height);
    // 斜向加工，切削出的为直角三角形，startCord都是右下点
        // 自顶点开始向左下↙
    bool obliqueMachiningLeftDown(coordinate startCord, int len, float slope);
        // 自顶点开始向右下↘
    bool obliqueMachiningRightDown(coordinate startCord, int len, float slope);
    // 螺纹加工
    inline int vecCalculate(coordinate PointA, coordinate PointB, coordinate PointP);
        // 横向螺纹加工
    bool tThreadMachining(coordinate startCord, int pitch, int depth, int len);
        // 斜向螺纹加工
    void getIntersectPoint(coordinate aStart, coordinate aEnd, coordinate bStart, coordinate bEnd, double *arr);
    bool oThreadMachining(coordinate startCord, int pitch, int depth, int len, int height);

    // 圆弧加工
    coordinate *Circle_Center(coordinate p1,coordinate p2,double dRadius);
    bool arcMachining(coordinate p1, coordinate p2, double radius, bool arcCodition);

    // 将二位数数组画出来
    // 将画布和工艺一起放大，生成二维数组，最后传送并画在widget中

    // 获得私有变量 m_pixelArray
    BYTE** get_m_pixelArray();


private:
    // m_表示是类的数据成员
    // 使用以下三个变量描述一个动态的二维数组，用来抽象画布
    BYTE ** m_pixelArray;
    int m_canvasWidth;
    int m_canvasHeight;





};










#endif // BAR_H
