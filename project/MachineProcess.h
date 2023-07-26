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
#include <MachineTrace.h>
#include <MachineSequence.h>
#include <Bar.h>
#include <QPainter>
#include <iostream>
#include <fstream>
#include<QDebug>
#include "baseset.h"
using namespace std;
#define TEST 1

    struct TrueCoordinate {
        double x;
        double y;
    };

class MachineProcess{

public:

    bool firstInsystem;
    MachineSequene m_mSeq;

    MachineProcess(int canvasWidth, int canvasHeight, double trueBarWidth, double trueBarHeight);

    // 坐标转换器:真实棒料的double类型坐标转换成
    coordinate StartCordTranslate(TrueCoordinate &start_cord);
    // 角度转换器：将角度转换成tan值，如输入45，输出tan(45) = 1
    double AngleToTan(int angle);
    // 工艺接口
    // 横向加工
    bool transverseMachining(TrueCoordinate startCord, double len, double h);
    // 斜向加工，切削出的为直角三角形，startCord都是右下点
        // 自顶点开始向左下↙
    bool obliqueMachiningLeftDown(TrueCoordinate startCord, double len, int angle);
        // 自顶点开始向右下↘
    bool obliqueMachiningRightDown(TrueCoordinate startCord, double len, int angle);
        // 横向螺纹加工
    bool tThreadMachining(TrueCoordinate startCord, double pitch, double depth, double len);
        // 斜向螺纹加工
    bool oThreadMachining(TrueCoordinate startCord, double pitch, double depth, double len, int angle);
    // 圆弧加工
    bool arcMachining(TrueCoordinate p1, TrueCoordinate p2, double radius, bool arcCodition);


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

    void outerCircle1_GCode_auto(machineNode*, ofstream*, bool*);
    void outerCircle2_GCode_auto(machineNode*, ofstream*, bool*);
    void outerCircle3_GCode_auto(machineNode*, ofstream*, bool*);
    void endFace1_GCode_auto(machineNode*, ofstream*, bool*);
    void endFace2_GCode_auto(machineNode*, ofstream*, bool*);
    void endFace3_GCode_auto(machineNode*, ofstream*, bool*);
    void innerHole1_GCode_auto(machineNode*, ofstream*, bool*);
    void innerHole2_GCode_auto(machineNode*, ofstream*, bool*);
    void innerHole3_GCode_auto(machineNode*, ofstream*, bool*);
    void innerHole4_GCode_auto(machineNode*, ofstream*, bool*);
    void innerHole5_GCode_auto(machineNode*, ofstream*, bool*);
    void coneFace1_GCode_auto(machineNode*, ofstream*, bool*);
    void coneFace2_GCode_auto(machineNode*, ofstream*, bool*);
    void coneFace3_GCode_auto(machineNode*, ofstream*, bool*);
    void coneFace4_GCode_auto(machineNode*, ofstream*, bool*);
    void screwThread1_GCode_auto(machineNode*, ofstream*, bool*);
    void screwThread2_GCode_auto(machineNode*, ofstream*, bool*);
    void screwThread3_GCode_auto(machineNode*, ofstream*, bool*);
    void screwThread4_GCode_auto(machineNode*, ofstream*, bool*);
    void chamfer1_GCode_auto(machineNode*, ofstream*, bool*);
    void chamfer2_GCode_auto(machineNode*, ofstream*, bool*);
    void chamfer3_GCode_auto(machineNode*, ofstream*, bool*);
    void chamfer4_GCode_auto(machineNode*, ofstream*, bool*);
    bool outputGCode_auto();


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

    bool recordVariable(void);
    bool recoverVariable(void);
    // 真实棒料比例 = 图棒料宽度/真实棒料宽度
    double scale_;

private:
    Bar *m_b;
    MachineTrace m_trace;
    // 初始化的画布
    int m_canvasWidth;
    int m_canvasHeight;

    // 画布中将要绘制的bar的描述（使用setBarAttribute函数进行bar的属性设置）
    coordinate startPos;// 棒料左下角坐标，用于绘制棒料
    coordinate rightDownPos;// 棒料右下角坐标,用于调整坐标系,使得工艺绘制时棒料右下角为{0,0}
    int m_barWidth;
    int m_barHeight;

    // 真实棒料大小
    double m_trueBarWidth;
    double m_trueBarHeight;

};

#endif // MACHINEPROCESS_H
