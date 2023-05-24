#include <MachineFusion.h>


MachineFusion::MachineFusion()
{
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
    //快速排斥实验：
    if(max(b1.x,b2.x)<min(a1.x,a2.x)||max(a1.x,a2.x)<min(b1.x,b2.x)||max(b1.y,b2.y)<min(a1.y,a2.y)||max(a1.y,a2.y)<min(b1.y,b2.y)){
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

// 如果两个线段相交，则求交点（通过引用进行返回值的传递）
void MachineFusion::getIntersection(coordinate a1,coordinate a2,coordinate b1,coordinate b2, coordinate &res){

    // 向量法求交点
    coordinate vecA = {a2.x-a1.x, a2.y-a1.y};
    coordinate vecB = {b2.x-b1.x, b2.y-b1.y};
    double t;
    // 捕获除零异常
    try{
        t = ((a1.y-b1.y)*vecB.x - vecB.y*(a1.x-b1.x))/ ((vecA.x*vecB.y) - (vecA.y*vecB.x));
        qDebug()<<"t:"<<t<< endl;
    }catch (...){
        cerr<< "machineFusion除零错误";
    }
    // 结果
    res = {(a1.x+t*vecA.x),(a1.y+t*vecA.y)};
}
// 测完判断点是否在两个线段上即可判定是否相交



// 输入：实体多边形链表和裁剪多边形链表
// 输出：以引用的形式返回裁剪后的实体多边形链表
void MachineFusion::fusion(linkList &entityList, linkList cropList){
    // 分别指向实体多边形和裁剪多边形的当前处理节点
    linkList *entityCurPtr = entityList.mainNext;
    linkList *cropCurPtr = cropList.mainNext;
    // 形成交点与多边形的联合链表
    do{// 第一层循环遍历实体多边形
        do {// 第二层循环遍历裁剪多边形
            // 以entityCurPtr表示的边与裁剪多边形进行直线裁剪操作
            if(isIntersection(entityCurPtr->pos, entityCurPtr->mainNext->pos, cropCurPtr->pos, cropCurPtr->mainNext->pos)){// 如果有交点
                // 计算交点
                coordinate cord;// 存放交点
                getIntersection(entityCurPtr->pos, entityCurPtr->mainNext->pos, cropCurPtr->pos, cropCurPtr->mainNext->pos, cord);
                // 初始化交点
                    // 节点属性：坐标，线段属性，多边形输出，本节点属性， 链表指针域， 交点指针域
                linkList *intersection = new linkList(cord, cropList.mainNext->lineAttribute, 0, 2, nullptr, nullptr);
                // 在实体链表中插入交点
                intersection->mainNext =  entityCurPtr->mainNext;
                entityCurPtr->mainNext = intersection;
                // 在裁剪链表中插入交点
                intersection->extraNext = cropCurPtr->mainNext;
                cropCurPtr->mainNext = intersection;
            }else{
                cropCurPtr = cropCurPtr->mainNext;
                continue;
            }
         } while (cropCurPtr != cropList.mainNext);// 实体多边形回到起点表明结束
         entityCurPtr = entityCurPtr->mainNext;
    }while(entityCurPtr != entityCurPtr->mainNext);


    // 从实体链表开始遍历节点，遇到第一个交点为进点，开始遍历裁剪链表，下一个交点为出点，开始遍历实体链表。如此交替完整形成裁剪后的实体链表
    int flag = 1;
    do {
        if (flag == 1) {// 遍历实体链表
            if(entityCurPtr->intersection == 2){// 遇到进点
                // 将进点设置为裁剪后多边形的实体顶点
                entityCurPtr->mainNext = entityCurPtr->extraNext;
                entityCurPtr->extraNext = nullptr;
                entityCurPtr->intersection = 0;//
                flag = 0;
            }
        }else{// 遍历裁剪多边形
            if(entityCurPtr->intersection == 2){// 遇到出点
                // 将出点设置为裁剪后多边形的实体顶点
                entityCurPtr->extraNext = nullptr;
                entityCurPtr->intersection = 0;//
                flag = 1;//
            }
        }
        entityCurPtr = entityCurPtr->mainNext;
    }while (entityCurPtr != entityList.mainNext);

    // 防御性编程
    #ifdef ARRSERT
        assert();
    #endif

}

// 输入：实体多边形链表和裁剪多边形链表的头指针或引用
// 输出：被裁剪后的实体多边形链表



































