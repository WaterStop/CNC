// 单例模式重新改造，因为轨迹数据具有唯一性，并且轨迹数组特别占用内存

#ifndef MACHINETRACE_H
#define MACHINETRACE_H
#include <vector>
#include <climits>
// 共享内存
#include <QBuffer>
#include <QSharedMemory>
#include <QDebug>
using namespace std;
#include "Bar.h"
/*
// 顶点结构体,在Bar.h中定义，避免重复定义
typedef struct {
    int x;
    int y;
} coordinate;
*/
typedef struct {
    int start;// 开始下标
    int end;// 结束下标
    coordinate cord[10000];// 10000个坐标点的数组
}Trace;


class MachineTrace{
public:
    MachineTrace();
    // 获取共享内存中的坐标数据
    void getSharedMemory();// 放到一个线程中去
    // 通过该函数获取的私有变量trace引用只能读取，不能修改
    const Trace& getTrace();
    // 在trace中增加一个坐标点
    bool addPoint(const coordinate& p);
private:
    // 由雕刻路线的坐标点组成的结构体
    Trace trace;

};


#endif // MACHINETRACE_H
