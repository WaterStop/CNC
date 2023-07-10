#include <MachineFusion.h>

/*
 * 1. 找第一个交点，判断进出性并插入
 * 2. 实体多边形按序使用每一条边去裁剪裁剪多边形，裁剪一条边完成被裁剪后的一条实体多边形的边界
 * 3. 每次插入还要判断插入点是不是实体多边形的两个端点
 */

MachineFusion::MachineFusion(linkList* entityList, linkList* cropList)
    :entityList_(entityList), cropList_(cropList)
{


    // 打印测试链表
    auto test =  [](linkList *cur, bool flag){
        linkList *head = cur;

        do {
            if(flag){
                qDebug() << "{" << cur->pos.x<<  "," << cur->pos.y << "}" ;
                cur = cur->entityNext;
            }else{
                qDebug() << "{" << cur->pos.x<<  "," << cur->pos.y << "}" ;
                cur = cur->cropNext;
            }
        } while (cur != head);
        qDebug() << "*****************";

    };


    linkList *entityCurPtr;// 实体多边形单循环链表
    linkList *cropCurPtr; // 裁剪多边形单循环链表
    // 实体多边形链表节点
    linkList* e1 = new linkList({0, 10}, 1, 0, 0, nullptr, nullptr);
    linkList* e2 = new linkList({10, 10}, 1, 0, 0, nullptr, nullptr);
    linkList* e3 = new linkList({10, 0}, 1, 0, 0, nullptr, nullptr);
    linkList* e4 = new linkList({0, 0}, 1, 0, 0, nullptr, nullptr);
    entityCurPtr = e1;
    e1->entityNext = e2;
    e2->entityNext = e3;
    e3->entityNext = e4;
    e4->entityNext = e1;

    test(e1,1);

    // 裁剪多边形链表节点(逆向，根据实际数控系统雕刻路径进行仿真来的)
    linkList* c1 = new linkList({11, -2}, 1, 0, 0, nullptr, nullptr);
    linkList* c2 = new linkList({13, 0}, 1, 0, 0, nullptr, nullptr);
    linkList* c3 = new linkList({11, 2}, 1, 0, 0, nullptr, nullptr);
    linkList* c4 = new linkList({9, 0}, 1, 0, 0, nullptr, nullptr);
    // 将裁剪多边形链表链接成单向循环链表
    cropCurPtr= c1;
    c1->cropNext = c2;
    c2->cropNext = c3;
    c3->cropNext = c4;
    c4->cropNext = c1;
    test(c1,0);


    fusion(entityCurPtr, cropCurPtr);


    // 遍历融合后的链表
    qDebug() << "finshEntityList:";
    test(entityCurPtr->entityNext, 1);



    /*
    // 测试共线函数
    if (overlap({0,10},{10,10}, {5,10},{0,10}))
        qDebug() << "collinear";
    else
        qDebug() << "NOcollinear";
    */


    /*
    // 测试去重函数
    separateOverlap(entityCurPtr, cropCurPtr);
    if(c2->pos.y != 10)
        qDebug() << "yes"<< c2->pos.y;
    */
    /*
    // 测试交点函数代码
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
    */
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
    if(
        ( (b1.x-a1.x)*(a2.y-a1.y)-(b1.y-a1.y)*(a2.x-a1.x) ) *          //判断B是否跨过A
        ( (b2.x-a1.x)*(a2.y-a1.y)-(b2.y-a1.y)*(a2.x-a1.x) ) <=0 &&
        ( (a1.x-b1.x)*(b2.y-b1.y)-(a1.y-b1.y)*(b2.x-b1.x) ) *          //判断A是否跨过B
        ( (a2.x-b1.x)*(b2.y-b1.y)-(a2.y-b1.y)*(b2.x-b1.x) ) <=0
      )
        return true;
    else
        return false;


    /*
    // 匿名函数：B1为外点，A1-A2为基本线段
    auto cross = [](coordinate B1, coordinate A1, coordinate A2 )->double{
        return (A2.x-A1.x)*(B1.y-B1.x) -(A2.y-A1.y)*(B1.x-A1.x) ;
    };

    if(cross(b1, a1, a2)*cross(b2, a1, a2) > 0 || cross(a1, b1, b2)*cross(a2, b1, b2) > 0){
        return  false;
    }
    return true;
*/
}

// 如果两个线段相交，则求交点（通过引用进行返回值的传递）,如果重合或者不相交则返回false
bool MachineFusion::getIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2, coordinate &res){
    // 判断是否有交点
    if (isIntersection(a1, a2, b1, b2)) {
        // 向量法求交点
        coordinate vecA = {a2.x-a1.x, a2.y-a1.y};
        coordinate vecB = {b2.x-b1.x, b2.y-b1.y};
        double t;
        // 判断是否平行
        double denominator = (vecA.x * vecB.y) - (vecA.y * vecB.x);
        if (denominator == 0) {// 平行
            return false;// 有交点又重合说明共线，这种交点会被相邻的直线处理，可以不处理
        }
        //计算结果
        t = ((a1.y-b1.y)*vecB.x - vecB.y*(a1.x-b1.x))/ denominator;
        res = {(a1.x+t*vecA.x),(a1.y+t*vecA.y)};
        return true;
    } else {
        return false;
    }

}

// 判断两个交点是否相同
inline bool isSame(coordinate a, coordinate b){
    if(a.x == b.x && a.y == b.y){
        return true;
    }else
        return false;
}




/**
 * 通过计算两个向量的sin值判断两条线段的交点的进出性，进点为true
 * @param eStart 向量e的起点坐标
 * @param eEnd 向量e的终点坐标
 * @param cStart 向量c的起点坐标
 * @param cEnd 向量c的终点坐标
 * @return 两个向量的sin值的正负，正表示为0~180度为出点，负表示为180~360为进点
 */
inline bool MachineFusion::isEntry(coordinate eStart, coordinate eEnd, coordinate cStart, coordinate cEnd) {
    double a = (eEnd.x - eStart.x) * (cEnd.y - cStart.y) - (eEnd.y - eStart.y) * (cEnd.x - cStart.x);
    double b = sqrt((eEnd.x - eStart.x) * (eEnd.x - eStart.x) + (eEnd.y - eStart.y) * (eEnd.y - eStart.y));
    double c = sqrt((cEnd.x - cStart.x) * (cEnd.x - cStart.x) + (cEnd.y - cStart.y) * (cEnd.y - cStart.y));
    if ((a / (b * c)) > 0) {
        return false;
    } else {
        return true;
    }
// 防御性断言
#if ASSERT_CHECK
    assert(b*c == 0);// 除零异常
#endif
}

// 判断两个线段是否重合,
bool MachineFusion::overlap(coordinate a1, coordinate a2, coordinate b1, coordinate b2)
{
    //TODO:只有端点在直线上的时候
    //TODO:取交点的附近一点判断是否在直线上
    // 判断是否有交点
    if (isIntersection(a1, a2, b1, b2)) {
        // 向量法求交点
        coordinate vecA = {a2.x-a1.x, a2.y-a1.y};
        coordinate vecB = {b2.x-b1.x, b2.y-b1.y};
        // 判断是否平行
        double denominator = (vecA.x * vecB.y) - (vecA.y * vecB.x);
        if (denominator == 0) {// 平行
            return true;// 有交点又重合说明共线，这种交点会被相邻的直线处理，可以不处理
        }
    }
    return false;
}

// 功能:将实体链表和裁剪链表中重合的部分进行分离
// 分离原则:将裁剪多边形的边向出点的方向移动
bool MachineFusion::separateOverlap(linkList *entityList, linkList *cropList)
{
    // 分别指向实体多边形和裁剪多边形的当前处理节点
    linkList *entityCurPtr = entityList;
    linkList *cropCurPtr = cropList;
    do {// 第一层循环遍历实体多边形
        do {// 第二层循环遍历裁剪多边形
            // 记录交点数量
            if (overlap(entityCurPtr->pos, entityCurPtr->entityNext->pos,  cropCurPtr->pos, cropCurPtr->cropNext->pos)) {
                // 计算重合的实体多边形边的垂直单位向量
                coordinate vertical_entity_vector = {0,0};// 垂直向量:x和y交换,并将y取反
                if ((entityCurPtr->pos.y - entityCurPtr->entityNext->pos.y) > 0){
                    vertical_entity_vector.x = 1*1e-14;// 最大到1e-15将会被省略
                } else if ((entityCurPtr->pos.y - entityCurPtr->entityNext->pos.y) < 0){
                    vertical_entity_vector.x = -1*1e-14;
                } else {
                    vertical_entity_vector.x = 0;
                }
                if ((entityCurPtr->entityNext->pos.x - entityCurPtr->pos.x) > 0){
                    vertical_entity_vector.y = 1*1e-14;
                } else if ((entityCurPtr->pos.x - entityCurPtr->entityNext->pos.x) < 0){
                    vertical_entity_vector.y = -1*1e-14;
                } else {
                    vertical_entity_vector.y = 0;
                }
                // 对重合裁剪边进行向出点方向偏移
                cropCurPtr->pos.x += vertical_entity_vector.x;
                cropCurPtr->pos.y += vertical_entity_vector.y;
                cropCurPtr->cropNext->pos.x += vertical_entity_vector.x;
                cropCurPtr->cropNext->pos.y += vertical_entity_vector.y;
            }
            cropCurPtr = cropCurPtr->cropNext;
         }while(cropCurPtr != cropList);
        // 实体多边形回到起点表明结束
        entityCurPtr = entityCurPtr->entityNext;
    }while(entityCurPtr != entityList);
    return true;
}

bool MachineFusion::isShapeIntersect(linkList *entityList, linkList *cropList)
{
    // 分别指向实体多边形和裁剪多边形的当前处理节点
    linkList *entityCurPtr = entityList;
    linkList *cropCurPtr = cropList;
    int intersectionCount = 0;
    do {// 第一层循环遍历实体多边形
        do {// 第二层循环遍历裁剪多边形
            // 记录交点数量
            if (isIntersection(entityCurPtr->pos, entityCurPtr->entityNext->pos,  cropCurPtr->pos, cropCurPtr->cropNext->pos)) {
                ++intersectionCount;
            }
            cropCurPtr = cropCurPtr->cropNext;
         }while(cropCurPtr != cropList);
        // 实体多边形回到起点表明结束
        entityCurPtr = entityCurPtr->entityNext;
    }while(entityCurPtr != entityList);
    // 不存在交点或者交点不是偶数则错误
    if (intersectionCount != 0 && intersectionCount % 2 == 0){
        return true;
    } else {
        return false;
    }
}


// 返回第一个进点
linkList *MachineFusion::firstEntry(linkList *entityList, linkList *cropList)
{
    // 分别指向实体多边形和裁剪多边形的当前处理节点
    linkList *entityCurPtr = entityList;
    linkList *cropCurPtr = cropList;
    // 形成交点与多边形的联合链表,每次拿一条实体多边形的边去求交裁剪多边形
    do {// 第一层循环遍历实体多边形
        do {// 第二层循环遍历裁剪多边形
            // 以entityCurPtr表示的边与裁剪多边形进行直线裁剪操作
            coordinate cord;// 存放交点
            if(getIntersection(entityCurPtr->pos,
                               entityCurPtr->entityNext->pos,
                               cropCurPtr->pos,
                               cropCurPtr->cropNext->pos,
                               cord)
             ){// 1. 线段不相交会跳过该裁剪线段 2.实体线段和裁剪线段重合会跳过，因为相邻的裁剪边会计算这个交点并加入，避免重复加入
                // 如果有交点，关键是否有侵入性
                if (isEntry(entityCurPtr->pos,
                            entityCurPtr->entityNext->pos,
                            cropCurPtr->pos,
                            cropCurPtr->cropNext->pos)) {// 如果是进点
                        //创建新交点
                        linkList *intersection = new linkList(cord,
                                                              cropList->cropNext->lineAttribute,
                                                              1, 2, nullptr, nullptr);
                        // 向交点中插入指向下一个的裁剪链表节点
                        intersection->cropNext =  cropCurPtr->cropNext;
                        intersection->entityNext = entityCurPtr->entityNext;
                        entityCurPtr->entityNext = intersection;
                        return intersection;
                    }
                }
            cropCurPtr = cropCurPtr->cropNext;
         }while(cropCurPtr != cropList);
        // 实体多边形回到起点表明结束
        entityCurPtr = entityCurPtr->entityNext;
    }while(entityCurPtr != entityList);
    return nullptr;

}



// 在实体链表边上找进点
linkList *MachineFusion::entityEntry(linkList *exitPoint, linkList *cropList, linkList *firstEntry)
{
    // 走到尽头的两种情况:1. 遇到与裁剪边的交点,并且为出点(进点则错误) 2. 遇到第一个交点,遍历结束
    // 分别指向实体多边形和裁剪多边形的当前处理节点
    linkList *entityCurPtr = exitPoint;
    linkList *cropCurPtr = cropList;
    // 形成交点与多边形的联合链表,每次拿一条实体多边形的边去求交裁剪多边形
    do {// 第一层循环遍历实体多边形
        do {// 第二层循环遍历裁剪多边形
            // 以entityCurPtr表示的边与裁剪多边形进行直线裁剪操作
            coordinate cord;// 存放交点
            if(getIntersection(entityCurPtr->pos,
                               entityCurPtr->entityNext->pos,
                               cropCurPtr->pos,
                               cropCurPtr->cropNext->pos,
                               cord)
             ){// 1. 线段不相交会跳过该裁剪线段 2.实体线段和裁剪线段重合会跳过，因为相邻的裁剪边会计算这个交点并加入，避免重复加入
                // 如果有交点，关键是否有侵入性
                if (isEntry(entityCurPtr->pos,
                            entityCurPtr->entityNext->pos,
                            cropCurPtr->pos,
                            cropCurPtr->cropNext->pos)) {// 如果是进点
                        //创建新交点
                        linkList *intersection = new linkList(cord,
                                                              cropList->cropNext->lineAttribute,
                                                              1, 2, nullptr, nullptr);
                        // 向交点中插入指向下一个的裁剪链表节点
                        intersection->cropNext =  cropCurPtr->cropNext;
                        intersection->entityNext = entityCurPtr->entityNext;
                        entityCurPtr->entityNext = intersection;
                        return intersection;
                    }
                }
            cropCurPtr = cropCurPtr->cropNext;
         }while(cropCurPtr != cropList);
        // 实体多边形回到起点表明结束
        entityCurPtr = entityCurPtr->entityNext;
    }while(entityCurPtr->entityNext != firstEntry);
    return nullptr;
}
// 在裁剪链表上找出点
linkList *MachineFusion::cropExit(linkList *entityList, linkList *entryPoint) {
    linkList *entityCurPtr = entityList;
    linkList *cropCurPtr = entryPoint;
    // 走到尽头的两种情况:1. 遇到与实体边的交点,并且为出点 2. 遇到第一个交点,遍历结束
    do {// 遍历一遍裁剪链表
        do {
            coordinate cord;// 存放交点
            if(getIntersection(entityCurPtr->pos,
                               entityCurPtr->entityNext->pos,
                               cropCurPtr->pos,
                               cropCurPtr->cropNext->pos,
                               cord)
             ){// 1. 线段不相交会跳过该裁剪线段 2.实体线段和裁剪线段重合会跳过，因为相邻的裁剪边会计算这个交点并加入，避免重复加入
                // 如果有交点，关键是否有侵入性
                if (isEntry(entityCurPtr->pos,
                            entityCurPtr->entityNext->pos,
                            cropCurPtr->pos,
                            cropCurPtr->cropNext->pos)) {// 如果是进点
                    // 排除最初的交点
                    if(isSame(cord, entryPoint->pos)) {
                        entityCurPtr = entityCurPtr->entityNext;
                        continue;
                    } else {
                        return nullptr;
                    }
                } else {
                    //创建新交点
                    linkList *intersection = new linkList(cord,
                                                          entityCurPtr->lineAttribute,
                                                          0, 2, nullptr, nullptr);
                    // 向交点插入指向下一个的裁剪链表节点
                    intersection->entityNext =  entityCurPtr->entityNext;
                    intersection->cropNext = cropCurPtr->cropNext;// 出点只需要上一个裁剪链表结点next域指向即可
                    cropCurPtr->cropNext = intersection;
                    return intersection;
                }
            }
            entityCurPtr = entityCurPtr->entityNext;
        } while (entityCurPtr != entityList);
        cropCurPtr = cropCurPtr->cropNext;
    } while (cropCurPtr->cropNext != entryPoint);
    return nullptr;// 没有遇到出点,出现错误
}

// 测完判断点是否在两个线段上即可判定是否相交

// TODO:应该从第一个交点开始遍历

// 输入：实体多边形链表和裁剪多边形链表
// 输出：以引用的形式返回裁剪后的实体多边形链表
void MachineFusion::fusion(linkList *entityList, linkList *cropList){
    // TODO: 两个多边形只重合一个点,并且重合的部分不平行

    // 分别指向实体多边形和裁剪多边形的当前处理节点
    linkList *entityCurPtr = entityList;
    linkList *cropCurPtr = cropList;

    // 分离重合的实体多边形和裁剪多边形的边
    if(!separateOverlap(entityList, cropList))
        qDebug() << "separateOverlap error!!";
    else
        qDebug() << "separateOverlap yes.";
    // 两个多边形是否相交
    if(isShapeIntersect(entityList, cropList)){
        qDebug() << "isShapeIntersect yes";
    } else {
        qDebug() << "isShapeIntersect error!!";
        return ;
    }
    // 实体链表和裁剪链表的第一个进点交点
    linkList *first_Entry = firstEntry(entityCurPtr, cropCurPtr);

    cropCurPtr = first_Entry;
    do {
        // 在剩下的裁剪链表中找出点
        entityCurPtr = cropExit(entityList, cropCurPtr);// 插入裁剪链表
        // 在剩下的实体链表中找进点
        cropCurPtr =  entityEntry(entityCurPtr, cropList, first_Entry);// 插入实体链表
    } while (cropCurPtr != nullptr);
    // 输出实体链表
    ouputEntityList(first_Entry);

/*
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
*/
// 防御性编程
#ifdef ARRSERT
    assert();
#endif

}


// 生成链表
bool MachineFusion::ouputEntityList(linkList *first_entry)
{
    linkList *cur = first_entry;
    bool flag = 1;
    // 将路径上的全部节点改为enityNext相连
    do {
        if (cur->intersection == 2)// 交点时设置flag
            flag = cur->entryExit;
        // 结果链表
        if (flag == 1) {// 进点开始走cropList
            cur->entityNext = cur->cropNext;
            cur->cropNext = nullptr;
        } else {
            cur->cropNext = nullptr;
        }
        cur = cur->entityNext;
    } while (cur != first_entry);
    this->resultPtr_ = first_entry;
    return  true;
}

linkList *MachineFusion::getResult()
{
    return resultPtr_;
}

// 输入：实体多边形链表和裁剪多边形链表的头指针或引用
// 输出：被裁剪后的实体多边形链表



// 每次将`相邻的横向和斜向&&中间没有辅助工艺`的部分融合成一个工艺
// G71的转换，需要将第一个交点到最后一个交点的路径部分转换成G71和G72




/*

// 如果跟踪第一个交点的裁剪多边形边界，如果出现新的进点，则以该进点为最终的第一个交点
// 没找到返回nullptr
// 问题:找到的第一个交点可能是边重合导致的(实体矩形,左上角裁剪小矩形的情况)
// 放弃的解决:通过裁剪多边形对于实体多边形的侵入方向来判断,裁剪多边形的起始顶点,输入的裁剪多边形必须都是左上角为起始顶点
// 解决:判断交点的接下来的实体边和裁剪边是否重合,如果重合将交点设置为下一个顶点
// 可以判断裁剪多边形的下一个顶点是否在实体多边形的边上
auto overlap = [](coordinate Pi, coordinate Pj, coordinate Q)->bool{
    if((Q.x - Pi.x) * (Pj.y - Pi.y) == (Pj.x - Pi.x) * (Q.y - Pi.y)  //叉乘
       //保证Q点坐标在pi,pj之间
       && min(Pi.x , Pj.x) <= Q.x && Q.x <= max(Pi.x , Pj.x)
       && min(Pi.y , Pj.y) <= Q.y && Q.y <= max(Pi.y , Pj.y))
        return true;
    else
        return false;
};

*/




















