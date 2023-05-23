#ifndef MACHINESEQUENCE_H
#define MACHINESEQUENCE_H


// 一个问题：是否使用STL中的list模板来进行处理更加好一些
// 新结构体：一个工艺链表节点{工艺类型，void*}，根据工艺类型去进行对应工艺结构体的指针类型转换，void*指向实际的结构体


#include "Bar.h"
#include "global_variable.h"
#include "machineStruct.h"
// 基本工艺结构体


// 如果核心数据结构是带尾指针的单链表是不是更好
class MachineSequene{
public:
    // 初始化时需要输入棒料的大小
    MachineSequene();// 构造函数
    machineNode *getHead();// 返回链表头指针
    // 将bar的长和高放到棒料中
    bool setbar(int barWidth, int barHeight);
    // 增加结点，函数重载
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

    machineIndex index;// 工艺链表索引

private:
    //machineIndex index;// 工艺链表索引
};



#endif // MACHINESEQUENCE_H


