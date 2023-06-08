#ifndef MACHINEPROCESS_H
#define MACHINEPROCESS_H

/*
1. 主要成员
    - class Bar
    - class MachineSequence
2.功能
    - Bar类主要提供对于内部成员m_pixelArray[][]的处理，该数据成员抽象表示了棒料经过各种工艺处理后的二维平面像素点
    - MachineSequence类负责增删改查和移动由不同工艺操作参数封装的结构体链表，最后通过getHead()函数向其他对象传递处理结果
3. 总体架构
    - MachineProcess类由Bar类和MachineSequence类对象组合而成，通过对于两个对象的处理流程的再次封装，向其他widget提供统一的图形绘制、移动和缩放的接口

@author：sen
@time：2022.11.11
 */

#include <fstream>
#include <iostream>
#include <QDebug>
#include <QPainter>

#include <Bar.h>
#include <MachineFusion.h>
#include <machineStruct.h>
#include <MachineSequence.h>
#include <MachineTrace.h>

using namespace std;
class MachineProcess{

public:

    bool firstInsystem;
    MachineSequene m_mSeq;
    // 通过最后一个trueBarWidth和barWidth计算真正棒料和图中棒料的比例
    MachineProcess(int canvasWidth, int canvasHeight, int barWidth, int barHeight, double trueBarWidth);

    // 工艺接口
    // 横向加工
    bool transverseMachining(coordinate startCord, int len, int h);
    // 斜向加工，切削出的为直角三角形，startCord都是右下点
        // 自顶点开始向左下↙
    bool obliqueMachiningLeftDown(coordinate startCord, int len, float slope);
        // 自顶点开始向右下↘
    bool obliqueMachiningRightDown(coordinate startCord, int len, float slope);
    // 螺纹加工
        // 横向螺纹加工
    bool tThreadMachining(coordinate startCord, int pitch, int depth, int len);
        // 斜向螺纹加工
    bool oThreadMachining(coordinate startCord, int pitch, int depth, int len, int height);
    // 圆弧加工
    bool arcMachining(coordinate p1, coordinate p2, double radius, bool arcCodition);


    bool addNode(s_outerCircleMode1 outerCircle1);
    bool addNode(s_outerCircleMode2 outerCircle2);
    bool addNode(s_outerCircleMode3 outerCircle3);
    bool addNode(s_endFaceMode1 endFace1);
    bool addNode(s_endFaceMode2 endFace2);
    bool addNode(s_endFaceMode3 endFace3);
    bool addNode(s_innerHoleMode1 innerHole1);
    bool addNode(s_innerHoleMode2 innerHole2);
    bool addNode(s_innerHoleMode3 innerHole3);
    bool addNode(s_innerHoleMode4 innerHole4);
    bool addNode(s_innerHoleMode5 innerHole5);
    bool addNode(s_coneFaceMode1 coneFace1);
    bool addNode(s_coneFaceMode2 coneFace2);
    bool addNode(s_coneFaceMode3 coneFace3);
    bool addNode(s_coneFaceMode4 coneFace4);
    bool addNode(s_screwThreadMode1 screwThread1);
    bool addNode(s_screwThreadMode2 screwThread2);
    bool addNode(s_screwThreadMode3 screwThread3);
    bool addNode(s_screwThreadMode4 screwThread4);
    bool addNode(s_chamferMode1 chamfer1);
    bool addNode(s_chamferMode2 chamfer2);
    bool addNode(s_chamferMode3 chamfer3);
    bool addNode(s_chamferMode4 chamfer4);
    // 查找结点
    machineNode *findNode(int position);
    // 删除结点
    bool deleteNode(int position);
    // 移动结点
    bool moveNode(int src, int des);
    // 更改结点
    bool changeNode(int pos, s_outerCircleMode1 outerCircle1);
    bool changeNode(int pos, s_outerCircleMode2 outerCircle2);
    bool changeNode(int pos, s_outerCircleMode3 outerCircle3);
    bool changeNode(int pos, s_endFaceMode1 endFace1);
    bool changeNode(int pos, s_endFaceMode2 endFace2);
    bool changeNode(int pos, s_endFaceMode3 endFace3);
    bool changeNode(int pos, s_innerHoleMode1 innerHole1);
    bool changeNode(int pos, s_innerHoleMode2 innerHole2);
    bool changeNode(int pos, s_innerHoleMode3 innerHole3);
    bool changeNode(int pos, s_innerHoleMode4 innerHole4);
    bool changeNode(int pos, s_innerHoleMode5 innerHole5);
    bool changeNode(int pos, s_coneFaceMode1 coneFace1);
    bool changeNode(int pos, s_coneFaceMode2 coneFace2);
    bool changeNode(int pos, s_coneFaceMode3 coneFace3);
    bool changeNode(int pos, s_coneFaceMode4 coneFace4);
    bool changeNode(int pos, s_screwThreadMode1 screwThread1);
    bool changeNode(int pos, s_screwThreadMode2 screwThread2);
    bool changeNode(int pos, s_screwThreadMode3 screwThread3);
    bool changeNode(int pos, s_screwThreadMode4 screwThread4);
    bool changeNode(int pos, s_chamferMode1 chamfer1);
    bool changeNode(int pos, s_chamferMode2 chamfer2);
    bool changeNode(int pos, s_chamferMode3 chamfer3);
    bool changeNode(int pos, s_chamferMode4 chamfer4);

    bool update_pixelArray();
    // 绘制相关操作
    // 将Bar转化成动态对象，每次操作都将改变bar的大小
    void barPaint(QPainter &painter);
    // 绘制路径
    void tracePaint(QPainter &painter);
    // 将工艺序列转化成G代码
    void outerCircle1_GCode(machineNode*, ofstream*, bool*);
    void outerCircle2_GCode(machineNode*, ofstream*, bool*);
    void outerCircle3_GCode(machineNode*, ofstream*, bool*);
    void endFace1_GCode(machineNode*, ofstream*, bool*);
    void endFace2_GCode(machineNode*, ofstream*, bool*);
    void endFace3_GCode(machineNode*, ofstream*, bool*);
    void innerHole1_GCode(machineNode*, ofstream*, bool*);
    void innerHole2_GCode(machineNode*, ofstream*, bool*);
    void innerHole3_GCode(machineNode*, ofstream*, bool*);
    void innerHole4_GCode(machineNode*, ofstream*, bool*);
    void innerHole5_GCode(machineNode*, ofstream*, bool*);
    void coneFace1_GCode(machineNode*, ofstream*, bool*);
    void coneFace2_GCode(machineNode*, ofstream*, bool*);
    void coneFace3_GCode(machineNode*, ofstream*, bool*);
    void coneFace4_GCode(machineNode*, ofstream*, bool*);
    void screwThread1_GCode(machineNode*, ofstream*, bool*);
    void screwThread2_GCode(machineNode*, ofstream*, bool*);
    void screwThread3_GCode(machineNode*, ofstream*, bool*);
    void screwThread4_GCode(machineNode*, ofstream*, bool*);
    void chamfer1_GCode(machineNode*, ofstream*, bool*);
    void chamfer2_GCode(machineNode*, ofstream*, bool*);
    void chamfer3_GCode(machineNode*, ofstream*, bool*);
    void chamfer4_GCode(machineNode*, ofstream*, bool*);
    bool outputGCode();

    //将用户输入数据以文本形式记录
    bool textRecordData();

    //将参数记录文本恢复成界面参数
    bool textRecoverData();
    void checkWitchType(int*, int*, string);
    void TextRecoverNode(int, int, string, s_outerCircleMode1*, int*);
    void TextRecoverNode(int, int, string, s_outerCircleMode2*, int*);
    void TextRecoverNode(int, int, string, s_outerCircleMode3*, int*);
    void TextRecoverNode(int, int, string, s_endFaceMode1*, int*);
    void TextRecoverNode(int, int, string, s_endFaceMode2*, int*);
    void TextRecoverNode(int, int, string, s_endFaceMode3*, int*);
    void TextRecoverNode(int, int, string, s_innerHoleMode1*, int*);
    void TextRecoverNode(int, int, string, s_innerHoleMode2*, int*);
    void TextRecoverNode(int, int, string, s_innerHoleMode3*, int*);
    void TextRecoverNode(int, int, string, s_innerHoleMode4*, int*);
    void TextRecoverNode(int, int, string, s_innerHoleMode5*, int*);
    void TextRecoverNode(int, int, string, s_coneFaceMode1*, int*);
    void TextRecoverNode(int, int, string, s_coneFaceMode2*, int*);
    void TextRecoverNode(int, int, string, s_coneFaceMode3*, int*);
    void TextRecoverNode(int, int, string, s_coneFaceMode4*, int*);
    void TextRecoverNode(int, int, string, s_screwThreadMode1*, int*);
    void TextRecoverNode(int, int, string, s_screwThreadMode2*, int*);
    void TextRecoverNode(int, int, string, s_screwThreadMode3*, int*);
    void TextRecoverNode(int, int, string, s_screwThreadMode4*, int*);
    void TextRecoverNode(int, int, string, s_chamferMode1*, int*);
    void TextRecoverNode(int, int, string, s_chamferMode2*, int*);
    void TextRecoverNode(int, int, string, s_chamferMode3*, int*);
    void TextRecoverNode(int, int, string, s_chamferMode4*, int*);






private:
    Bar *m_b;
    MachineTrace m_trace;
    // 初始化的画布
    int m_canvasWidth;
    int m_canvasHeight;

    // 画布中将要绘制的bar的描述（使用setBarAttribute函数进行bar的属性设置）
    coordinate startPos;// 棒料左下角坐标，这应该封装在棒料里面！！！
    int m_barWidth;
    int m_barHeight;

    // 真实棒料大小
    double m_trueBarWidth;
    // 真实棒料比例 = 图棒料宽度/真实棒料宽度
    double m_barScale;

};

#endif // MACHINEPROCESS_H
