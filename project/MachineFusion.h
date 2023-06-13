#ifndef MACHINEFUSION_H
#define MACHINEFUSION_H

#define ASSERT_CHECK 1


#include<iostream>
#include <QDebug>

#include"MachineSequence.h"
#include "machineStruct.h"
using namespace std;

/*
    1.



*/
// 数据结构
typedef struct LinkList{
    coordinate pos;// 坐标
    int lineAttribute;// 表示该点开始到下一点的线段的属性，如直线、圆弧、螺纹
    bool entryExit;// 进点为1,出点为0

    int intersection;// 标识本节点的属性；-1表示头节点；0为实体多边形节点；1为裁剪多边形节点；2为交点
    struct LinkList *entityNext;// 指针域
    struct LinkList *cropNext;// 下一个是交点

    LinkList(coordinate p, int l, bool u, int i, struct LinkList *mn, struct LinkList *en):
        pos(p), lineAttribute(l), entryExit(u), intersection(i), entityNext(mn), cropNext(en){};
}linkList;



class MachineFusion{
public:
    // 构造函数
    MachineFusion(linkList* entityList, linkList* cropList);
    // 将工艺转换成链表
    void machineToList();
    // 判断两个线段是否为交点
    inline bool isIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2);
    // 判断相交线段的进出性
    bool isEntry(coordinate eStart, coordinate eEnd, coordinate cStart, coordinate cEnd);
    // 返回第一个进点
    linkList* firstEntry(linkList *entityList, linkList *cropList);
    // 判断两条线段重合
    bool overlap(coordinate eStart, coordinate eEnd, coordinate cStart, coordinate cEnd);
    // 将线段的重合部分分离
    bool separateOverlap(linkList *entityList, linkList *cropList);
    // 判断裁剪多边形和实体多边形是否该具有重合的点
    bool isShapeIntersect(linkList *entityList, linkList *cropList);
    // 求两个点的距离
    double getDistance(coordinate p1, coordinate p2);
    // 如果两个线段相交，则求交点（通过引用进行返回值的传递）
    bool getIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2, coordinate &res);
    linkList *entityEntry(linkList *entityList, linkList *cropList, linkList *firstEntry);
    linkList *cropExit(linkList *entityList, linkList *cropList);
    // 多边形裁剪和工艺链表裁剪的融合
    void fusion(linkList *entityList, linkList *cropList);
    // 将图遍历形成结果链表
    bool ouputEntityList(linkList *first_entry);
    // 输出结果链表指针
    linkList *getResult();



private:
    linkList *entityList_;
    linkList *cropList_;
    linkList *resultPtr_;// 结果链表头指针


};
















#endif // MACHINEFUSION_H
