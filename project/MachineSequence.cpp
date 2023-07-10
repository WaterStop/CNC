#include "MachineSequence.h"
#include<string.h>
#include<QDebug>

MachineSequene::MachineSequene()
    :index({0, nullptr,nullptr})
{
    machineNode *head = new machineNode();
    head->type = 0;
    index.head = head;
    index.tail = head;
}

machineNode *MachineSequene::getHead()
{
    return index.head;
}

bool MachineSequene::setbar(int barWidth, int barHeight)
{
    index.barWidth = barWidth;
    index.barHeight = barHeight;
}

bool MachineSequene::addNode( s_outerCircleMode1 outerCircle1)
{
    qDebug() <<"00:" <<outerCircle1.Cn<<endl;
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = OUTER_CIRCLE_ONE;
    cur->outerCircle1 = outerCircle1;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;

    if(index.num < 0)
    {
        return false;
    }
    else
    {
        index.num++;    
        return true;
    }
}

bool MachineSequene::addNode(s_outerCircleMode2 outerCircle2)
{

    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = OUTER_CIRCLE_TWO;
    cur->outerCircle2 = outerCircle2;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        index.num++;
    return true;
}

bool MachineSequene::addNode(s_outerCircleMode3 outerCircle3)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = OUTER_CIRCLE_THREE;
    cur->outerCircle3 = outerCircle3;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        index.num++;
    return true;
}

bool MachineSequene::addNode( s_endFaceMode1 endFace1)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = END_FACE_ONE;
    cur->endFace1 = endFace1;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        index.num++;
    return true;
}

bool MachineSequene::addNode(s_endFaceMode2 endFace2)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = END_FACE_TWO;
    cur->endFace2 = endFace2;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_endFaceMode3 endFace3)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = END_FACE_THREE;
    cur->endFace3 = endFace3;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_innerHoleMode1 innerHole1)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = INNER_HOLE_ONE;
    cur->innerHole1 = innerHole1;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_innerHoleMode2 innerHole2)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = INNER_HOLE_TWO;
    cur->innerHole2 = innerHole2;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_innerHoleMode3 innerHole3)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = INNER_HOLE_THREE;
    cur->innerHole3 = innerHole3;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_innerHoleMode4 innerHole4)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = INNER_HOLE_FOUR;
    cur->innerHole4 = innerHole4;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_innerHoleMode5 innerHole5)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = INNER_HOLE_FIVE;
    cur->innerHole5 = innerHole5;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_coneFaceMode1 coneFace1)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CONE_FACE_ONE;
    cur->coneFace1 = coneFace1;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_coneFaceMode2 coneFace2)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CONE_FACE_TWO;
    cur->coneFace2 = coneFace2;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_coneFaceMode3 coneFace3)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CONE_FACE_THREE;
    cur->coneFace3 = coneFace3;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_coneFaceMode4 coneFace4)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CONE_FACE_FOUR;
    cur->coneFace4 = coneFace4;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_screwThreadMode1 screwThread1)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_ONE;
    cur->screwThread1 = screwThread1;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_screwThreadMode2 screwThread2)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_TWO;
    cur->screwThread2 = screwThread2;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_screwThreadMode3 screwThread3)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_THREE;
    cur->screwThread3 = screwThread3;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_screwThreadMode4 screwThread4)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_FOUR;
    cur->screwThread4 = screwThread4;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_chamferMode1 chamfer1)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CHAMFER_ONE;
    cur->chamfer1 = chamfer1;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_chamferMode2 chamfer2)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CHAMFER_TWO;
    cur->chamfer2 = chamfer2;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_chamferMode3 chamfer3)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CHAMFER_THREE;
    cur->chamfer3 = chamfer3;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}

bool MachineSequene::addNode(s_chamferMode4 chamfer4)
{
    machineNode *p = index.tail;
    machineNode *cur = new machineNode();
    memset(cur, 0, sizeof(machineNode));// 清空新结点的内存，防止错误
    // 工艺结点的赋值
    cur->type = CHAMFER_FOUR;
    cur->chamfer4 = chamfer4;
    cur->next = nullptr;
    // 在尾部增加工艺结点
    p->next = cur;
    // 更新索引结点
    index.tail = cur;
    if(index.num < 0)
        return false;
    else
        ++index.num;
    return true;
}



machineNode * MachineSequene::findNode(int n)
{
    // 参数健壮性检查
    if(n < 0 || n > index.num)
        return nullptr;

    machineNode *p = index.head;

    while(n--){
        p = p->next;
    }
    return p;

}

bool MachineSequene::deleteNode(int n)
{
    // 所要查询结点的前一个结点指针
    machineNode *prior = findNode(n-1);
    // 不合理的情况
    qDebug()<<"情况0.1";
    if(index.num == 0)
    {
        qDebug()<<"情况0.2";
        return false;
    }
    // 只有一个结点的情况
    else if(index.num == 1 && n == 1){
        qDebug()<<"情况1";
        index.tail = index.head;
        delete(prior->next);
    // 是最后一个结点的情况
    }else if(n == index.num){
        qDebug()<<"情况2";
        index.tail = prior;
        delete(prior->next);
        prior->next = nullptr;

    // 中间结点的情况
    }else{
        machineNode *p = prior->next;
        prior->next = p->next;
        delete(p);
    }

    --index.num;
    qDebug()<<"num2="<<index.num;
    return true;
}


bool MachineSequene::moveNode(int src, int des)
{
    if (src < 1 || des < 1) return false;
    if (src == des) return true;

    // 所要查询结点的前一个结点指针
    machineNode *srcPrior = findNode(src-1);
    machineNode *srcNode = srcPrior->next;// 要移动的结点
    machineNode *desPrior = findNode(des-1);
    if(index.num > 1){
        // 目标位置在结点前从1开始编码
        srcPrior->next = srcPrior->next->next;
        srcNode->next = desPrior->next;
        desPrior->next = srcNode;

    }else if(index.num == 0)
        return false;
    else if(index.num == 1)
        return true;

    // 处理索引结点的tail
    while(srcNode->next != nullptr)
        srcNode = srcNode->next;
    index.tail = srcNode;
    return true;


}

bool MachineSequene::changeNode(int pos, s_outerCircleMode1 outerCircle1)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = OUTER_CIRCLE_ONE;
    cur->outerCircle1 = outerCircle1;
    return true;

}

bool MachineSequene::changeNode(int pos, s_outerCircleMode2 outerCircle2)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = OUTER_CIRCLE_TWO;
    cur->outerCircle2 = outerCircle2;
    return true;
}

bool MachineSequene::changeNode(int pos, s_outerCircleMode3 outerCircle3)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = OUTER_CIRCLE_THREE;
    cur->outerCircle3 = outerCircle3;
    return true;
}

bool MachineSequene::changeNode(int pos, s_endFaceMode1 endFace1)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = END_FACE_ONE;
    cur->endFace1 = endFace1;
    return true;
}

bool MachineSequene::changeNode(int pos, s_endFaceMode2 endFace2)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = END_FACE_TWO;
    cur->endFace2 = endFace2;
    return true;
}

bool MachineSequene::changeNode(int pos, s_endFaceMode3 endFace3)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = END_FACE_THREE;
    cur->endFace3 = endFace3;
    return true;
}

bool MachineSequene::changeNode(int pos, s_innerHoleMode1 innerHole1)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = INNER_HOLE_ONE;
    cur->innerHole1 = innerHole1;
    return true;
}

bool MachineSequene::changeNode(int pos, s_innerHoleMode2 innerHole2)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = INNER_HOLE_TWO;
    cur->innerHole2 = innerHole2;
    return true;
}

bool MachineSequene::changeNode(int pos, s_innerHoleMode3 innerHole3)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = INNER_HOLE_THREE;
    cur->innerHole3 = innerHole3;
    return true;
}

bool MachineSequene::changeNode(int pos, s_innerHoleMode4 innerHole4)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = INNER_HOLE_FOUR;
    cur->innerHole4 = innerHole4;
    return true;
}

bool MachineSequene::changeNode(int pos, s_innerHoleMode5 innerHole5)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = INNER_HOLE_FIVE;
    cur->innerHole5 = innerHole5;
    return true;
}

bool MachineSequene::changeNode(int pos, s_coneFaceMode1 coneFace1)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CONE_FACE_ONE;
    cur->coneFace1 = coneFace1;
    return true;
}

bool MachineSequene::changeNode(int pos, s_coneFaceMode2 coneFace2)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CONE_FACE_TWO;
    cur->coneFace2 = coneFace2;
    return true;
}

bool MachineSequene::changeNode(int pos, s_coneFaceMode3 coneFace3)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CONE_FACE_THREE;
    cur->coneFace3 = coneFace3;
    return true;
}

bool MachineSequene::changeNode(int pos, s_coneFaceMode4 coneFace4)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CONE_FACE_FOUR;
    cur->coneFace4 = coneFace4;
    return true;
}

bool MachineSequene::changeNode(int pos, s_screwThreadMode1 screwThread1)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_ONE;
    cur->screwThread1 = screwThread1;
    return true;
}

bool MachineSequene::changeNode(int pos, s_screwThreadMode2 screwThread2)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_TWO;
    cur->screwThread2 = screwThread2;
    return true;
}

bool MachineSequene::changeNode(int pos, s_screwThreadMode3 screwThread3)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_THREE;
    cur->screwThread3 = screwThread3;
    return true;
}

bool MachineSequene::changeNode(int pos, s_screwThreadMode4 screwThread4)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = SCREW_THREAD_FOUR;
    cur->screwThread4 = screwThread4;
    return true;
}

bool MachineSequene::changeNode(int pos, s_chamferMode1 chamfer1)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CHAMFER_ONE;
    cur->chamfer1 = chamfer1;
    return true;
}

bool MachineSequene::changeNode(int pos, s_chamferMode2 chamfer2)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CHAMFER_TWO;
    cur->chamfer2 = chamfer2;
    return true;
}

bool MachineSequene::changeNode(int pos, s_chamferMode3 chamfer3)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CHAMFER_THREE;
    cur->chamfer3 = chamfer3;
    return true;
}

bool MachineSequene::changeNode(int pos, s_chamferMode4 chamfer4)
{
    machineNode *cur = findNode(pos);
    // 工艺结点的赋值
    cur->type = CHAMFER_FOUR;
    cur->chamfer4 = chamfer4;
    return true;
}
