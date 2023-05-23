#ifndef MACHINEFUSION_H
#define MACHINEFUSION_H

#include <QDebug>
#include<iostream>

#include"MachineSequence.h"
#include "machineStruct.h"
using namespace std;

/*
    1.



*/
// 裁剪多边形和实体多边形的节点
typedef struct LinkNode{
    coordinate pos;// 坐标
    int lineAttribute;// 表示该点开始到下一点的线段的属性，如直线、圆弧、螺纹
    int intersection;// 标识本节点的属性；0为实体多边形节点；1为裁剪多边形节点；2为交点
    bool used;// 用于多个输出多边形的情况（所有交点的used初值为0，当一个交点被输出时，其used域置为1）
}linkNode;
typedef struct LinkList{
    linkNode data;
    struct LinkList *next;// 链表指针域
    struct LinkList *intersectionNext;// 下一个是交点
}linkList;



class MachineFusion{
public:
    // 构造函数
    MachineFusion();
    // 判断两个线段是否为交点
    inline bool isIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2);
    // 如果两个线段相交，则求交点（通过引用进行返回值的传递）
    void getIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2, coordinate &res);
    // 多边形裁剪和工艺链表裁剪的融合
    void fusion(linkList &entityList, linkList cropList);




private:



};
















#endif // MACHINEFUSION_H
