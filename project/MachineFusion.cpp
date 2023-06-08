#include <MachineFusion.h>

/*
 * 1. 找第一个交点，判断进出性并插入
 * 2. 实体多边形按序使用每一条边去裁剪裁剪多边形，裁剪一条边完成被裁剪后的一条实体多边形的边界
 * 3. 每次插入还要判断插入点是不是实体多边形的两个端点
 */

MachineFusion::MachineFusion()
{



    if (isEntry({10,10}, {10,0}, {5,10}, {10,0}))
        qDebug() << "true";
    else
        qDebug() << "false";
    linkList *entityCurPtr;// 实体多边形单循环链表
    linkList *cropCurPtr; // 裁剪多边形单循环链表
    // 实体多边形链表节点
    linkList* e1 = new linkList({0, 10}, 1, 0, 0, nullptr, nullptr);
    linkList* e2 = new linkList({10, 10}, 1, 0, 0, nullptr, nullptr);
    linkList* e3 = new linkList({10, 0}, 1, 0, 0, nullptr, nullptr);
    linkList* e4 = new linkList({0, 0}, 1, 0, 0, nullptr, nullptr);
    //
    entityCurPtr = e1;
    e1->entityNext = e2;
    e2->entityNext = e3;
    e3->entityNext = e4;
    e4->entityNext = e1;
    // 裁剪多边形链表节点(逆向)
    linkList* c1 = new linkList({5, 5}, 1, 0, 0, nullptr, nullptr);
    linkList* c2 = new linkList({5, 0}, 1, 0, 0, nullptr, nullptr);
    linkList* c3 = new linkList({10, 0}, 1, 0, 0, nullptr, nullptr);
    linkList* c4 = new linkList({10, 5}, 1, 0, 0, nullptr, nullptr);
    // 将裁剪多边形链表链接成单向循环链表
    cropCurPtr= c3;
    c1->cropNext = c2;
    c2->cropNext = c3;
    c3->cropNext = c4;
    c4->cropNext = c1;

    fusion(entityCurPtr, cropCurPtr);

    // 遍历融合后的链表
    linkList *cur = entityCurPtr->entityNext;
    do {
        qDebug() << endl <<"{" << cur->pos.x << ", " << cur->pos.y << "}"<< endl;
        cur = cur->entityNext;
    }while (cur != entityCurPtr->entityNext);


    // 测试代码
    coordinate a1 = {0,0};
    coordinate a2 = {2,2};
    coordinate b1 = {0,2};
    coordinate b2 = {2,0};
    coordinate res = {0,0};
    if(isIntersection(a1, a2, b1, b2)){
        getIntersection(a1, a2, b1, b2, res);
        qDebug()<<"faile";
    }
    qDebug() << res.x << ","<< res.y<<endl;

}




// 简单判断两个线段是否相交(线段A的两个端点a1和a2, 线段B的两个端点b1和b2)
bool MachineFusion::isIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2)
{
#if ASSERT_CHECK
    // 线段重合为一个点
    bool a = (a1.x == a2.x && a1.y == a2.y);
    bool b = (b1.x == b2.x && b1.y == b2.y);
    if((a || b))
        return false;
#endif
    //快速排斥实验：
    if(max(b1.x,b2.x)<min(a1.x,a2.x)||
       max(a1.x,a2.x)<min(b1.x,b2.x)||
       max(b1.y,b2.y)<min(a1.y,a2.y)||
       max(a1.y,a2.y)<min(b1.y,b2.y)) {
        return false;
    }
    // 跨立实验
    // 匿名函数：B1为外点，A1-A2为基本线段
    auto cross = [](coordinate B1, coordinate A1, coordinate A2 )->int{
        return (A2.x-A1.x)*(B1.y-B1.x) -(A2.y-A1.y)*(B1.x-A1.x) ;
    };

    if(cross(b1, a1, a2)*cross(b2, a1, a2) > 0 || cross(a1, b1, b2)*cross(a2, b1, b2) > 0){
        return  false;
    }
    return true;
}

// 如果两个线段相交，则求交点（通过引用进行返回值的传递）,如果重合或者不相交则返回false
bool MachineFusion::getIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2, coordinate &res){
    // 判断是否有交点
    if (!isIntersection(a1, a2, b1, b2)) {
        return false;
    }

    // 向量法求交点
    coordinate vecA = {a2.x-a1.x, a2.y-a1.y};
    coordinate vecB = {b2.x-b1.x, b2.y-b1.y};
    double t;
    // 判断是否重合
    double denominator = (vecA.x * vecB.y) - (vecA.y * vecB.x);
    if (denominator == 0) {// 重合
        return false;// 有交点又重合说明共线，这种交点会被相邻的直线处理，可以不处理
    }

    //计算结果
    t = ((a1.y-b1.y)*vecB.x - vecB.y*(a1.x-b1.x))/ denominator;
    res = {(a1.x+t*vecA.x),(a1.y+t*vecA.y)};
    return true;

#if ASSERT_CHECK
    assert(((vecA.x*vecB.y) - (vecA.y*vecB.x)) == 0);// 除零异常
#endif
}

// 判断两个交点是否相同
inline bool isSame(coordinate a, coordinate b){
    if(a.x == b.x && a.y == b.y){
        return true;
    }else
        return false;
}
// 判断两条线段的交点的进出性，进点为true
inline bool MachineFusion::isEntry(coordinate eStart, coordinate eEnd, coordinate cStart, coordinate cEnd){
    // 计算两个向量的点积
    double dotProduct = (eEnd.x - eStart.x) * (cEnd.x - cStart.x) + (eEnd.y - eStart.y) * (cEnd.y - cStart.y);
    // 计算两个向量的模长
    double length1 = sqrt(pow(eEnd.x - eStart.x, 2) + pow(eEnd.y - eStart.y, 2));
    double length2 = sqrt(pow(cEnd.x - cStart.x, 2) + pow(cEnd.y - cStart.y, 2));
    // 计算夹角的余弦值
    double cosAngle = dotProduct / (length1 * length2);
    // 计算夹角的角度值
    //double angle = acos(cosAngle) * 180 / M_PI;
    // 判断是否大于180度
    if (cosAngle > 0) {// 0~180度表示出点，以实体多边形边为基准逆时针到裁剪多边形边的角度
        return false;
    } else {
        return true;
    }

#if ASSERT_CHECK
    assert(cosAngle == 0);// 除零异常
#endif
}



// 测完判断点是否在两个线段上即可判定是否相交

// TODO:应该从第一个交点开始遍历

// 输入：实体多边形链表和裁剪多边形链表
// 输出：以引用的形式返回裁剪后的实体多边形链表
void MachineFusion::fusion(linkList *entityList, linkList *cropList){
    // 分别指向实体多边形和裁剪多边形的当前处理节点
    linkList *entityCurPtr = entityList;
    linkList *cropCurPtr = cropList;

    // 形成交点与多边形的联合链表,每次拿一条实体多边形的边去求交裁剪多边形
    do {// 第一层循环遍历实体多边形
        do {// 第二层循环遍历裁剪多边形
            // 以entityCurPtr表示的边与裁剪多边形进行直线裁剪操作
            coordinate cord;// 存放交点
            if(getIntersection(entityCurPtr->pos,//0，10w
                               entityCurPtr->entityNext->pos,//10，10
                               cropCurPtr->pos,// 5，5
                               cropCurPtr->cropNext->pos,// 10.5
                               cord)
             ){// 1. 线段不相交会跳过该裁剪线段 2.实体线段和裁剪线段重合会跳过，因为相邻的裁剪边会计算这个交点并加入，避免重复加入
                // 如果有交点，关键是否有侵入性
                if (isSame(entityCurPtr->pos, cord)){                     // 交点为实体链表边起点
                    if (isEntry(entityCurPtr->pos,
                                entityCurPtr->entityNext->pos,
                                cropCurPtr->pos,
                                cropCurPtr->cropNext->pos)) {
                        // 交点为entityCurPtr并且为进点
                        entityCurPtr->cropNext = cropCurPtr->cropNext;
                        cropCurPtr->cropNext = entityCurPtr;

                    } else {
                        continue;
                    }
                } else if (isSame(entityCurPtr->entityNext->pos, cord)){  // 交点为实体链表边终点
                    if (isEntry(entityCurPtr->pos,
                                entityCurPtr->entityNext->pos,
                                cropCurPtr->pos,
                                cropCurPtr->cropNext->pos)) {//
                        // 交点为entityCurPtr->entityNext并且进点
                        continue;
                    } else {
                        entityCurPtr->entityNext->cropNext = cropCurPtr->cropNext;
                        cropCurPtr->cropNext = entityCurPtr->entityNext;
                    }
                } else if (isSame(cropCurPtr->pos, cord)){              // 交点为裁剪链表边起点
                    if (isEntry(entityCurPtr->pos,
                                entityCurPtr->entityNext->pos,
                                cropCurPtr->pos,
                                cropCurPtr->cropNext->pos)) {//
                        // 交点为进点
                        cropCurPtr->entityNext = entityCurPtr->entityNext;
                        entityCurPtr->entityNext = cropCurPtr;
                    } else {
                        continue;
                    }
                }else if (isSame(cropCurPtr->cropNext->pos, cord)){     // 交点为裁剪链表边终点
                    if (isEntry(entityCurPtr->pos,
                                entityCurPtr->entityNext->pos,
                                cropCurPtr->pos,
                                cropCurPtr->cropNext->pos)) {//
                        // 交点为进点
                        continue;
                    } else {
                        // 交点为出点
                        cropCurPtr->cropNext->entityNext = entityCurPtr->entityNext;
                        entityCurPtr->entityNext = cropCurPtr->cropNext;
                    }
                }else{                                                  // 交点不为裁剪和实体链表边的端点
                    //创建新交点
                    linkList *intersection = new linkList(cord,
                                                          cropList->cropNext->lineAttribute,
                                                          0, 2, nullptr, nullptr);
                    // 在实体链表中插入交点
                    intersection->entityNext =  entityCurPtr->entityNext;
                    entityCurPtr->entityNext = intersection;
                    // 在裁剪链表中插入交点
                    intersection->cropNext = cropCurPtr->cropNext;
                    cropCurPtr->cropNext = intersection;
                }
            }
            qDebug() << cropCurPtr->pos.x << cropCurPtr->pos.y <<"C"<< endl;
            cropCurPtr = cropCurPtr->cropNext;
         }while(cropCurPtr != cropList);
        // 实体多边形回到起点表明结束
        qDebug() << entityCurPtr->pos.x << entityCurPtr->pos.y <<"E"<< endl;
        entityCurPtr = entityCurPtr->entityNext;
    }while(entityCurPtr != entityList);


    // 从实体链表开始遍历节点，遇到第一个交点为进点，开始遍历裁剪链表，下一个交点为出点，开始遍历实体链表。如此交替完整形成裁剪后的实体链表
    int flag = 1;
    do {
        if (flag == 1) {// 遍历实体链表
            if(entityCurPtr->intersection == 2){// 遇到进点
                // 将进点设置为裁剪后多边形的实体顶点
                entityCurPtr->entityNext = entityCurPtr->cropNext;
                entityCurPtr->cropNext = nullptr;
                entityCurPtr->intersection = 0;//
                flag = 0;
            }
        }else{// 遍历裁剪多边形
            if(entityCurPtr->intersection == 2){// 遇到出点
                // 将出点设置为裁剪后多边形的实体顶点
                entityCurPtr->cropNext = nullptr;
                entityCurPtr->intersection = 0;//
                flag = 1;//
            }
        }
        entityCurPtr = entityCurPtr->entityNext;
    }while (entityCurPtr != entityList->entityNext);

// 防御性编程
#ifdef ARRSERT
    assert();
#endif

}

// 输入：实体多边形链表和裁剪多边形链表的头指针或引用
// 输出：被裁剪后的实体多边形链表



// 每次将`相邻的横向和斜向&&中间没有辅助工艺`的部分融合成一个工艺
// G71的转换，需要将第一个交点到最后一个交点的路径部分转换成G71和G72































