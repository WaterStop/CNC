#include<MachineProcess.h>


/***********图像的放缩和移动需要再widget进行处理，下面是中间画图窗口的基本使用和初始化
    // 窗口大小
    int canvasWidth = 400;
    int canvasHeight = 320;
    int m_barWidth = 380;
    int m_barHeight = 170;
    //设置可会绘制的窗口位置（距离左上角）及大小
    this->setGeometry(40, 50, canvasWidth, canvasHeight);
    QPainter painter(this);
    //逻辑坐标：距离窗口坐标系的距离
    painter.setWindow(-60, -50, this->width(), (this->height()));
    // 视口：相对于窗口坐标下要显示的区域
    painter.setViewport(0,0, this->width(), this->height());
    // 坐标参数
    // 移动方向参数和放缩倍数
    coordinate variation;
    variation.x = 0;
    variation.y = 0;
    double magp = 0.5;//放缩




  mp.update_pixelArray();
    // 代码输出
    mp.outputGCode();

    // 使用QT的绘制接口进行缩放和移动
    painter.save();// 设置新的绘制状态
        QTransform transform; // 定义新画家
        transform.translate(variation.x,variation.y);  // 画家的移动
        transform.scale(magp,magp);  // 定义画的图缩放比例
        painter.setTransform(transform);
        mp.barPaint(painter);//++++
        mp.tracePaint(painter);
    painter.restore();// 释放当前绘制状态
*/










// 对于MachineProcess类中操作的重新封装
// 高度除以二是进行镜像处理
MachineProcess::MachineProcess(int canvasWidth, int canvasHeight, int barWidth, int barHeight, double trueBarWidth)
    :m_canvasWidth(canvasWidth), m_canvasHeight(canvasHeight), m_barWidth(barWidth), m_barHeight(barHeight), m_trueBarWidth(trueBarWidth)
{
    m_mSeq.setbar(barWidth, barHeight);
    // 防止未初始化而使用参数导致出错
    startPos.x = 0;
    startPos.y = 0;
    // 比例计算：m_barScale = bar图/bar真
    // 健壮处理,防止除零异常
    if(trueBarWidth == 0)
        cerr << "MachineProcess`s constructed function divide 0 error!!!";
    //m_barScale = barWidth/trueBarWidth;
    m_barScale = 1;

    // 棒料左下位置的初始化
    startPos.x = floor((m_canvasWidth-m_barWidth)/2);
    startPos.y = floor((m_canvasHeight-m_barHeight)/2);
    // 棒材位置右下角的初始化
    rightDownPos.x =  floor((m_canvasWidth-m_barWidth)/2 + m_barWidth);
    rightDownPos.y =  floor((m_canvasHeight-m_barHeight)/2);

}
// 增加节点接口的多态封装（横向工艺，斜向工艺，横螺纹工艺，斜螺纹工艺，圆弧工艺）
bool MachineProcess::addNode( s_outerCircleMode1 outerCircle1)
{
    
    // ---
    
    return m_mSeq.addNode(outerCircle1);
}

bool MachineProcess::addNode( s_outerCircleMode2 outerCircle2)
{
     return m_mSeq.addNode( outerCircle2);
}

bool MachineProcess::addNode(s_outerCircleMode3 outerCircle3)
{
     return m_mSeq.addNode(outerCircle3);
}

bool MachineProcess::addNode(s_endFaceMode1 endFace1)
{
     return m_mSeq.addNode(endFace1);
}

bool MachineProcess::addNode(s_endFaceMode2 endFace2)
{
     return m_mSeq.addNode(endFace2);
}

bool MachineProcess::addNode(s_endFaceMode3 endFace3)
{
     return m_mSeq.addNode(endFace3);
}

bool MachineProcess::addNode(s_innerHoleMode1 innerHole1)
{
    return m_mSeq.addNode(innerHole1);
}

bool MachineProcess::addNode(s_innerHoleMode2 innerHole2)
{
    return m_mSeq.addNode(innerHole2);
}

bool MachineProcess::addNode(s_innerHoleMode3 innerHole3)
{
    return m_mSeq.addNode(innerHole3);
}

bool MachineProcess::addNode(s_innerHoleMode4 innerHole4)
{
    return m_mSeq.addNode(innerHole4);
}

bool MachineProcess::addNode(s_innerHoleMode5 innerHole5)
{
    return m_mSeq.addNode(innerHole5);
}

bool MachineProcess::addNode(s_coneFaceMode1 coneFace1)
{
    return m_mSeq.addNode(coneFace1);
}

bool MachineProcess::addNode(s_coneFaceMode2 coneFace2)
{
    return m_mSeq.addNode(coneFace2);
}

bool MachineProcess::addNode(s_coneFaceMode3 coneFace3)
{
    return m_mSeq.addNode(coneFace3);
}
bool MachineProcess::addNode(s_coneFaceMode4 coneFace4)
{
    return m_mSeq.addNode(coneFace4);
}

bool MachineProcess::addNode(s_screwThreadMode1 screwThread1)
{
    return m_mSeq.addNode(screwThread1);
}

bool MachineProcess::addNode(s_screwThreadMode2 screwThread2)
{
    return m_mSeq.addNode(screwThread2);
}

bool MachineProcess::addNode(s_screwThreadMode3 screwThread3)
{
    return m_mSeq.addNode(screwThread3);
}

bool MachineProcess::addNode(s_screwThreadMode4 screwThread4)
{
    return m_mSeq.addNode(screwThread4);
}

bool MachineProcess::addNode(s_chamferMode1 chamfer1)
{
    return m_mSeq.addNode(chamfer1);
}

bool MachineProcess::addNode(s_chamferMode2 chamfer2)
{
    return m_mSeq.addNode(chamfer2);
}

bool MachineProcess::addNode(s_chamferMode3 chamfer3)
{
    return m_mSeq.addNode(chamfer3);
}

bool MachineProcess::addNode(s_chamferMode4 chamfer4)
{
    return m_mSeq.addNode(chamfer4);
}

// 查找节点
machineNode *MachineProcess::findNode(int position)
{
    return m_mSeq.findNode(position);
}
// 删除节点
bool MachineProcess::deleteNode(int position)
{
    return m_mSeq.deleteNode( position);
}
// 移动节点
bool MachineProcess::moveNode(int src, int des)
{
    return m_mSeq.moveNode( src, des);
}
// 改变节点的多态封装（横向工艺，斜向工艺，横螺纹工艺，斜螺纹工艺，圆弧工艺）
bool MachineProcess::changeNode(int pos, s_outerCircleMode1 outerCircle1)
{
    return m_mSeq.changeNode(pos, outerCircle1);
}

bool MachineProcess::changeNode(int pos, s_outerCircleMode2 outerCircle2)
{
    return m_mSeq.changeNode(pos, outerCircle2);
}

bool MachineProcess::changeNode(int pos, s_outerCircleMode3 outerCircle3)
{
    return m_mSeq.changeNode(pos, outerCircle3);
}

bool MachineProcess::changeNode(int pos, s_endFaceMode1 endFace1)
{
    return m_mSeq.changeNode(pos, endFace1);
}

bool MachineProcess::changeNode(int pos, s_endFaceMode2 endFace2)
{
    return m_mSeq.changeNode(pos, endFace2);
}

bool MachineProcess::changeNode(int pos, s_endFaceMode3 endFace3)
{
    return m_mSeq.changeNode(pos, endFace3);
}

bool MachineProcess::changeNode(int pos, s_innerHoleMode1 innerHole1)
{
    return m_mSeq.changeNode(pos, innerHole1);
}

bool MachineProcess::changeNode(int pos, s_innerHoleMode2 innerHole2)
{
    return m_mSeq.changeNode(pos, innerHole2);
}

bool MachineProcess::changeNode(int pos, s_innerHoleMode3 innerHole3)
{
    return m_mSeq.changeNode(pos, innerHole3);
}

bool MachineProcess::changeNode(int pos, s_innerHoleMode4 innerHole4)
{
    return m_mSeq.changeNode(pos, innerHole4);
}

bool MachineProcess::changeNode(int pos, s_innerHoleMode5 innerHole5)
{
    return m_mSeq.changeNode(pos, innerHole5);
}

bool MachineProcess::changeNode(int pos, s_coneFaceMode1 coneFace1)
{
    return m_mSeq.changeNode(pos, coneFace1);
}

bool MachineProcess::changeNode(int pos, s_coneFaceMode2 coneFace2)
{
    return m_mSeq.changeNode(pos, coneFace2);
}

bool MachineProcess::changeNode(int pos, s_coneFaceMode3 coneFace3)
{
    return m_mSeq.changeNode(pos, coneFace3);
}

bool MachineProcess::changeNode(int pos, s_coneFaceMode4 coneFace4)
{
    return m_mSeq.changeNode(pos, coneFace4);
}

bool MachineProcess::changeNode(int pos, s_screwThreadMode1 screwThread1)
{
    return m_mSeq.changeNode(pos, screwThread1);
}

bool MachineProcess::changeNode(int pos, s_screwThreadMode2 screwThread2)
{
    return m_mSeq.changeNode(pos, screwThread2);
}

bool MachineProcess::changeNode(int pos, s_screwThreadMode3 screwThread3)
{
    return m_mSeq.changeNode(pos, screwThread3);
}

bool MachineProcess::changeNode(int pos, s_screwThreadMode4 screwThread4)
{
    return m_mSeq.changeNode(pos, screwThread4);
}

bool MachineProcess::changeNode(int pos, s_chamferMode1 chamfer1)
{
    return m_mSeq.changeNode(pos, chamfer1);
}

bool MachineProcess::changeNode(int pos, s_chamferMode2 chamfer2)
{
    return m_mSeq.changeNode(pos, chamfer2);
}

bool MachineProcess::changeNode(int pos, s_chamferMode3 chamfer3)
{
    return m_mSeq.changeNode(pos, chamfer3);
}

bool MachineProcess::changeNode(int pos, s_chamferMode4 chamfer4)
{
    return m_mSeq.changeNode(pos, chamfer4);
}



/*
#### 放大思路
    - 棒料的放大：直接在直角坐标系中窗口的中间位置进行初始化
    - 雕刻工艺图形的放大：先将坐标移到原点，放大后再移动到中心位置

#### 移动思路
    - 采用单次完全刷新，每次重置棒料在二维数组中的位置（是否非单次完全刷新会更好。即单次放大，多次移动）
    - 现在是 实际位置 = （原始位置 * 放大倍数） + 平移量

*/


// 组合对象的混合操作处理
// 缩放倍数，移动方向上的变化量
bool MachineProcess::update_pixelArray()
{
    // TEST

    // 初始化一个放大相应倍数的棒料
       m_b = new Bar(m_canvasWidth, m_canvasHeight);
       // 初始化棒料位置
       int b_barWidth = m_barWidth;
       //TEST m_barHeight/2
       int b_barHeight = floor(m_barHeight);// 只实例化下半部分，上半部分最后进行对称处理
       m_b->barInit(b_barWidth, b_barHeight);
       machineNode *p = m_mSeq.getHead();
       coordinate startCord;
       coordinate endCord;
       // 棒料的左下点坐标,在构造函数中以初始化
       //startPos.x =  floor((m_canvasWidth-b_barWidth)/2);
       //startPos.y =  floor((m_canvasHeight-b_barHeight)/2);
       //qDebug()<<"startPos.y"<<startPos.y<<"m_canvasHeight"<<m_canvasHeight<<"b_barHeight"<<b_barHeight;
    // 改动
    // 遍历工艺链表，根据工艺类型判断将要使用的工艺结构体，并进行工艺加工
    while(p != nullptr){
           switch(p->type){
           case 0 :
               break;
           case OUTER_CIRCLE_ONE:
               //startCord.x = /*OUTER_CIRCLE_ONE_X +*/ startPos.x;
               //startCord.y = /*OUTER_CIRCLE_ONE_Y +*/ startPos.y;
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               transverseMachining(startCord, p->outerCircle1.L, p->outerCircle1.Cr);
               break;

           case OUTER_CIRCLE_TWO:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               obliqueMachiningLeftDown(startCord, p->outerCircle2.L, p->outerCircle2.A);// eg
               break;

           case OUTER_CIRCLE_THREE:
               startCord.x = (barstock_L1 + p->outerCircle2.L) * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               endCord.x = barstock_L1 * m_barScale * -1;
               endCord.y = (barstock_L1 + p->outerCircle2.Cr) * m_barScale;
               // TODO:画的是矩形,而不是圆弧 r =20
               arcMachining(startCord, endCord, p->outerCircle3.R, false);//p->outerCircle3.G2G3);
               break;

           case END_FACE_ONE:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               transverseMachining(startCord, p->endFace1.CT, p->endFace1.Lr);
               break;

           case END_FACE_TWO:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               transverseMachining(startCord, p->endFace2.W, p->endFace2.Lr);
               break;

           case END_FACE_THREE:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               transverseMachining(startCord, p->endFace3.CT, p->endFace3.Lr);
               break;

           case INNER_HOLE_ONE:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               transverseMachining(startCord, p->innerHole1.L, p->innerHole1.Tr);
               break;

           case INNER_HOLE_TWO:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               transverseMachining(startCord, p->innerHole2.L, p->innerHole2.A);
               break;

           case INNER_HOLE_THREE:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               transverseMachining(startCord, p->innerHole3.W, p->innerHole3.Lr);
               break;

           case INNER_HOLE_FOUR:
               startCord.x = (barstock_L1 + p->innerHole4.L) * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               endCord.x = barstock_L1 * m_barScale * -1;
               endCord.y = (barstock_L1 + p->innerHole4.Cr) * m_barScale;;
               arcMachining(startCord, endCord, p->innerHole4.R, p->innerHole4.G2G3);
               break;

           case CONE_FACE_ONE:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               obliqueMachiningLeftDown(startCord, p->coneFace1.L, p->coneFace1.A);// eg
               break;

           case CONE_FACE_TWO:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               obliqueMachiningRightDown(startCord, p->coneFace1.L, p->coneFace1.A);// eg
               break;

           case CONE_FACE_THREE:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               obliqueMachiningLeftDown(startCord, p->coneFace1.L, p->coneFace1.A);// eg
               break;

           case CONE_FACE_FOUR:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               obliqueMachiningRightDown(startCord, p->coneFace1.L, p->coneFace1.A);// eg
               break;

           case SCREW_THREAD_ONE:// 横螺纹
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               tThreadMachining(startCord, p->screwThread1.Tp, p->screwThread1.Cr, p->screwThread1.L);
              break;

           case SCREW_THREAD_TWO:// 斜螺纹
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               // 最后一个参数有问题，qt传进来是负数

               oThreadMachining(startCord, p->screwThread4.Tp, p->screwThread4.Cr, p->screwThread4.L, p->screwThread4.A);// eg
               //oThreadMachining(startCord, 5, 3, 30, 45);
               break;

           case SCREW_THREAD_THREE:// 横螺纹
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               tThreadMachining(startCord, p->screwThread3.Tp, p->screwThread3.Cr, p->screwThread3.L);
              break;

           case SCREW_THREAD_FOUR:// 斜螺纹
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               oThreadMachining(startCord, p->screwThread4.Tp, p->screwThread4.Cr, p->screwThread4.L, p->screwThread4.A);
               break;

           case CHAMFER_ONE:
               startCord.x = (barstock_L1 + p->chamfer1.L) * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               endCord.x = barstock_L1 * m_barScale * -1;
               endCord.y = (barstock_L1 + p->chamfer1.Cr) * m_barScale;;
               arcMachining(startCord, endCord, p->chamfer1.R, p->chamfer1.G2G3);
               break;

           case CHAMFER_TWO:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               obliqueMachiningLeftDown(startCord, p->chamfer2.L, p->chamfer2.A);// eg
               break;

           case CHAMFER_THREE:
               startCord.x = (barstock_L1 + p->chamfer3.L) * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;
               endCord.x = barstock_L1 * m_barScale * -1;
               endCord.y = (barstock_L1 + p->chamfer3.Cr) * m_barScale;;
               arcMachining(startCord, endCord, p->chamfer3.R, p->chamfer3.G2G3);
               break;

           case CHAMFER_FOUR:
               startCord.x = barstock_L1 * m_barScale * -1;
               startCord.y = barstock_D1 * m_barScale;

               obliqueMachiningLeftDown(startCord, p->chamfer4.L, p->chamfer4.A);// eg
               break;
/*         case 3 :// 横螺纹
               p->outerCircle3.startCord.x = (p->outerCircle3.startCord.x) + startPos.x;
               p->outerCircle3.startCord.y = (p->outerCircle3.startCord.y) + startPos.y;
               m_b->tThreadMachining(p->outerCircle3.startCord, p->outerCircle3.Cr, p->outerCircle3.Tr, p->outerCircle3.L);
               break;
           case 4 :// 斜螺纹
               p->oThread.startCord.x = p->oThread.startCord.x + startPos.x;
               p->oThread.startCord.y = p->oThread.startCord.y + startPos.y;
               m_b->oThreadMachining(p->oThread.startCord, p->oThread.pitch, p->oThread.depth, p->oThread.len, p->oThread.height);               break;
           case 5 :// 圆弧
               p->arc.p1.x = p->arc.p1.x + startPos.x;
               p->arc.p1.y = p->arc.p1.y + startPos.y;
               p->arc.p2.x = p->arc.p2.x + startPos.x;
               p->arc.p2.y = p->arc.p2.y + startPos.y;
               m_b->arcMachining(p->arc.p1, p->arc.p2, p->arc.radius, p->arc.arcCodition);
               break;
*/
           }
           p = p->next;
       }


       return true;


}



// *****************************对称处理*******************************
// 根据棒料的二维像素数组和传进的画笔进行绘制,绘制窗口是widget_2_1的大小，而平移也是在二维像素数组上的平移
// 即一个逻辑窗口在二维像素数组上，然后对窗口内的进行输出
// 思路：获取缩放倍数和偏移位置，只对棒料对象的下半部分进行遍历，还要使用if边约束条件进行约束，防止访问越界。
void MachineProcess::barPaint(QPainter &painter)
{
// TODO:上下对称的上半部分差一个像素点
    // 获取画布的棒料数组
        unsigned char** m_pixelArray  = m_b->get_m_pixelArray();
        int m_barHeight = floor(this->m_barHeight/2);
        // 绘制bar的边界。（ *****************存在下边界出去之后，无法向上进行对称的问题***************）
        // 横向遍历，绘制纵向边界
        // 存在问题：如果边界恰好在x = 0处，则也不会进行边界的显示
        for(int x = startPos.x; x <= startPos.x + m_barWidth; ++x)
            for(int y = startPos.y; y <= startPos.y + m_barHeight ; ++y){
                if(x>=1 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)// 功能就是使得下面的x和y都在可显示的画布内
                    if (m_pixelArray[x][y]^m_pixelArray[x-1][y]){// 异或不同表示有边界
                        // 谁是1谁是边界
                        if(m_pixelArray[x][y] == 1){
                            if(x>=0 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                                painter.drawPoint(x,y);
                            if(x>=0 && x<m_canvasWidth&& 2*(startPos.y+m_barHeight)-y>=0 && 2*(startPos.y+m_barHeight)-y<m_canvasHeight)
                                painter.drawPoint(x,2*(startPos.y+m_barHeight)-y);// 镜像
                        }else{
                            if(x>=0 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                                painter.drawPoint(x-1,y);
                            if(x>=0 && x<m_canvasWidth&& 2*(startPos.y+m_barHeight)-y>=0 && 2*(startPos.y+m_barHeight)-y<m_canvasHeight)
                                painter.drawPoint(x-1,2*(startPos.y+m_barHeight)-y);
                        }
                    }
        }


        // 纵向遍历，绘制横向边界
        for(int y = 0; y < startPos.y + m_barHeight-1 ; y++)
            for(int x = 0; x < startPos.x + m_barWidth ; x++){
                if(x>=1 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                    if (m_pixelArray[x][y]^m_pixelArray[x][y+1]){
                        if(m_pixelArray[x][y] == 1){
                            if(x>=0 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                                painter.drawPoint(x,y);
                            if(x>=0 && x<m_canvasWidth&& 2*(startPos.y+m_barHeight)-y-1>=0 && 2*(startPos.y+m_barHeight)-y-1<m_canvasHeight)
                                painter.drawPoint(x,2*(startPos.y+m_barHeight)-y-1);// 镜像
                        }else{
                            if(x>=0 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                                painter.drawPoint(x,y+1);
                            if(x>=0 && x<m_canvasWidth&& 2*(startPos.y+m_barHeight)-y-1>=0 && 2*(startPos.y+m_barHeight)-y-1<m_canvasHeight)
                                painter.drawPoint(x,2*(startPos.y+m_barHeight)-y-1);// -1为了修复镜像的多纹现象
                        }
                    }
        }


        // 绘制镜像对称线
        QPen pen;
        pen.setWidth(1);//设置线条的宽度
        pen.setBrush(Qt::white);//设置画笔颜色
#ifdef TEST
    painter.drawLine(0,0, m_canvasWidth, m_canvasHeight);// 证明了绘制是窗口坐标系向右下为正
    // 棒材位置右下角的初始化

    /*
    // 棒材位置右下角的初始化
    rightDownPos.x =  floor((m_canvasWidth-m_barWidth)/2 + m_barWidth);
    rightDownPos.y =  floor((m_canvasHeight-m_barHeight)/2);
    */
    painter.drawLine(10,130,390,117);// 正确验证:左上角为坐标系(0,0),并且上半部分实际是裁剪的部分,因为对称下半部分不能用于裁剪
    painter.drawLine(rightDownPos.x, rightDownPos.y,rightDownPos.x+10,rightDownPos.y+20 );
#endif
        // 绘制镜像对称虚线
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        painter.drawLine(startPos.x-20, startPos.y + m_barHeight, startPos.x + m_barWidth + 20, startPos.y + m_barHeight);
        m_b->~Bar();



 }



void MachineProcess::tracePaint(QPainter &painter)
{

    // 通过t访问的数据是只读的
    const Trace &t = m_trace.getTrace();
    // 绘制雕刻轨迹
    if(t.end+1 != t.start){// 循环数组没满
        int i = 0;
        while (i <= t.end){
            painter.drawPoint(t.cord[i].x,t.cord[i].y);
            ++i;
        }
    }else{// 数组满了，为了避免每次计算余数，分两部分访问
        // 从0顺序访问到end
        for(int i = 0; i <= t.end; ++i){
            painter.drawPoint(t.cord[i].x,t.cord[i].y);
        }
        // 从start（end+1）访问到数组末尾
        for(int i = t.start; i <= 10000; ++i){
            painter.drawPoint(t.cord[i].x,t.cord[i].y);
        }

    }
}



void MachineProcess::outerCircle1_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    const int Cn = p->outerCircle1.Cn, xDir = p->outerCircle1.xDir, zDir = p->outerCircle1.zDir;
    const double L = p->outerCircle1.L, Tr = p->outerCircle1.Tr, Cr = p->outerCircle1.Cr, F = p->outerCircle1.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (0 == a)
        {
            if (true == *textHeadFlag)
            {
                *GCode<<"O200;"<<endl;
                *textHeadFlag = 0;
            }
            *GCode<< "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << "[" << L << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
            if (1 == Cn)
            {
                *GCode<<"M30;"<<endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << "[" << L << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
        }
        else
        {
            *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << "[" << L << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Cr << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
            *GCode<<"M30;"<<endl;
        }
    }
}

void MachineProcess::outerCircle2_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->outerCircle2.Cn, xDir = p->outerCircle2.xDir, zDir = p->outerCircle2.zDir;
    const double Tr = p->outerCircle2.Tr, F = p->outerCircle2.F;
    const double tanA = tan(p->outerCircle2.A/180*PI);
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode<<"O200;"<<endl;
            *textHeadFlag = 0;
        }
        *GCode<< "G01 U" << "[" << Tr * Num << " * #521]" << " F" << F << ";" <<endl;
        *GCode<< "G01 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << "[" << Tr * Num / tanA << " * #520]" << " F" << F << ";" <<endl;
        *GCode<< "G00 W" << "[" << Tr * Num / tanA << " * #520 * -1]" << " F" << F << ";" << endl;
        if (a == Cn - 1)
        {
            *GCode<<"M30;"<<endl;
        }
        Num = Num + 1;
    }
}


void MachineProcess::outerCircle3_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->outerCircle3.Cn, xDir = p->outerCircle3.xDir, zDir = p->outerCircle3.zDir;
    const double L = p->outerCircle3.L, Tr = p->outerCircle3.Tr, Cr = p->outerCircle3.Cr, R = p->outerCircle3.R, F = p->outerCircle3.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (0 == a)
        {
            if (true == *textHeadFlag)
            {
                *GCode<< "O200;" <<endl;
                *textHeadFlag = 0;
            }
            if ((1 == xDir && -1 == zDir) || (-1 == xDir && 1 == zDir))
            {
                *GCode<< "G01 W" << "[" << L / Cn << " * #520]" << " F" << F << ";" <<endl;
                *GCode<< "G02 U" << "[" << Tr << " * #521]" << " W" << "[" << L / Cn << " * #520 * -1]" << " R" << R - (Cr - Tr) << " F" << F << ";" <<endl;
                *GCode<< "G01 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
            }
            else
            {
                *GCode<< "G01 W" << "[" << L / Cn << " * #520]" << " F" << F << ";"<<endl;
                *GCode<< "G03 U" << "[" << Tr << " * #521]" << " W" << "[" << L / Cn << " * #520 * -1]" << " R" << R - (Cr - Tr) << " F" << F << ";" <<endl;
                *GCode<< "G01 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
            }
            if (1 == Cn)
            {
                *GCode<< "M30;" <<endl;
            }
            Num = Num + 1;
        }
        else if (a < (Cn - 1))
        {
            if ((1 == xDir && -1 == zDir) || (-1 == xDir && 1 == zDir))
            {
                *GCode<< "G01 W" << "[" << L / Cn * 2 << " * #520]" << " F" << F << ";" <<endl;
                *GCode<< "G02 U" << "[" << Tr * Num << " * #521]" << " W" << "[" << L / Cn * Num << " * #520 * -1]" << " R" << R - (Cr - Tr * Num) << " F" << F<< ";" <<endl;
                *GCode<< "G01 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
                *GCode<< "G03 U" << "[" << Tr * (Num - 1) << " * #521 * -1]" << " W" << "[" << L / Cn * (Num - 1) * zDir
                         << " R" << R - (Cr - Tr * (Num - 1)) << " F" << F << ";" <<endl;
            }
            else
            {
                *GCode<< "G01 W" << "[" << L / Cn * 2 << " * #520]" << " F" << F << ";" <<endl;
                *GCode<< "G03 U" << "[" << Tr * Num << " * #521]" << " W" << "[" << L / Cn * Num << " * #520 * -1]" << " R" << R - (Cr - Tr * Num) << " F" << F<< ";" <<endl;
                *GCode<< "G01 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
                *GCode<< "G02 U" << "[" << Tr * (Num - 1) << " * #521 * -1]" << " W" << "[" << L / Cn * (Num - 1) << " * #520]"
                         << " R" << "[" << R - (Cr - Tr * (Num - 1)) << " F" << F << ";" <<endl;
            }
            Num = Num + 1;
        }
        else
        {
            if ((1 == xDir && -1 == zDir) || (-1 == xDir && 1 == zDir))
            {
                *GCode<< "G01 W" << "[" << L / Cn * 2 << " * #520]" << " F" << F << ";" <<endl;
                *GCode<< "G02 U" << "[" << Tr * Num << " * #521]" << " W" << "[" << L / Cn * Num << " * #520 * -1]"
                         << " R" << "[" << R - (Cr - Tr * Num) << " F" << F << ";" <<endl;
                *GCode<< "G01 U" << "[" << Cr << " * #521 * -1]" << " F" << F << ";" <<endl;
            }
            else
            {
                *GCode<< "G01 W" << "[" << L / Cn * 2 << " * #520]" << " F" << F << ";" <<endl;
                *GCode<< "G03 U" << "[" << Tr * Num << " * #521]" << " W" << "[" << L / Cn * Num << " * #520 * -1]"
                         << " R" << R - (Cr - Tr * Num) << " F" << F << ";" <<endl;
                *GCode<< "G01 U" << "[" << Cr << " * #521 * -1]" << " F" << F << ";" <<endl;
            }
            *GCode<<"M30;"<<endl;
        }
    }
}

void MachineProcess::endFace1_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    const int Cn = p->endFace1.Cn, xDir = p->endFace1.xDir, zDir = p->endFace1.zDir;
    const double Lr = p->endFace1.Lr, deltaT = p->endFace1.deltaT, CT = p->endFace1.CT, F = p->endFace1.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (0 == a)
        {
            if (true == *textHeadFlag)
            {
                *GCode << "O200;" <<endl;
                *textHeadFlag = 0;
            }
            *GCode<< "G01 W" << "[" << deltaT << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Lr << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << deltaT << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Lr << " * #520 * -1]"<< " F" << F << ";" <<endl;
            if (1 == Cn)
            {
                *GCode<<"M30;"<<endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode<< "G01 W" << "[" << deltaT * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Lr << " * #520]" <<" F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << deltaT << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Lr << " * #520 * -1]"<< " F" << F << ";" <<endl;
        }
        else
        {
            *GCode<< "G01 W" << "[" << deltaT * 2<< " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Lr << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << CT << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Lr << " * #520 * -1]"<< " F" << F << ";" <<endl;
            *GCode<<"M30;"<<endl;
        }
    }
}

void MachineProcess::endFace2_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int w, a;
    int Wn = p->endFace2.W / p->endFace2.Tw;
    const double remainW = fmod(p->endFace2.W, p->endFace2.Tw);
    const int Cn = p->endFace2.Cn, xDir = p->endFace2.xDir, zDir = p->endFace2.zDir;
    const double Lr = p->endFace2.Lr, Tr = p->endFace2.Tr, W = p->endFace2.W, Tw = p->endFace2.Tw, F = p->endFace2.F;
    const machineNode *next = p->next;

    if (remainW != 0)
    {
        Wn = Wn + 1;
    }

    if (W < Tw)
    {
        qDebug()<<"warning: The opening width is less than the tool width"<<endl;
    }
    else
    {
        for (w = 0; w < Wn; w++)
        {
            for (a = 0; a < Cn; a++)
            {
                if (0 == a)
                {
                    if (true == *textHeadFlag)
                    {
                        *GCode<< "O200;" <<endl;
                        *textHeadFlag = 0;
                    }
                    *GCode<< "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
                    if (1 == Cn && w == Wn - 1)
                    {
                        *GCode<< "M30;" <<endl;
                    }
                }
                else if (a < (Cn - 1))
                {
                    *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << "[" << Lr << " * #521 * -1]" << " F" << F << ";" <<endl;
                }
            }
            if (w < Wn - 2)
            {
                *GCode<< "G00 W" << "[" << Tw << " * #520]" << " F" << F << ";" <<endl;
            }
            else if (w < Wn - 1)
            {
                if (remainW != 0)
                {
                    *GCode<< "G00 W" << "[" << remainW << " * #520]" << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G00 W" << "[" << Tw << " * #520]" << " F" << F << ";" <<endl;
                }
            }
            else
            {
                *GCode<< "G00 W" << "[" << (W - Tw) << " * #520 * -1]" << " F" << F << ";" <<endl;
                *GCode<< "M30;" <<endl;
            }
        }
    }
}

void MachineProcess::endFace3_GCode(machineNode *p, ofstream *GCode, bool* textHeadFlag) {
    const int Cn = p->endFace3.Cn, xDir = p->endFace3.xDir, zDir = p->endFace3.zDir;
    const double Lr = p->endFace3.Lr, deltaT = p->endFace3.deltaT, CT = p->endFace3.CT, F = p->endFace3.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++) {
        if (0 == a) {
            if (true == *textHeadFlag) {
                *GCode << "O200;" <<endl;
                *textHeadFlag = 0;
            }
            *GCode<< "G01 W" << "[" << deltaT << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Lr << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << deltaT << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Lr << " * #520 * -1]" << " F" << F << ";" <<endl;
            if (1 == Cn)
            {
                *GCode << "M30;" <<endl;
            }
        } else if (a < (Cn - 1)) {
            *GCode<< "G01 W" << "[" << deltaT * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Lr << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << deltaT << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Lr << " * #520 * -1]" << " F" << F << ";" <<endl;
        } else {
            *GCode<< "G01 W" << "[" << deltaT * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Lr << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << CT << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Lr << " * #520 * -1]" << " F" << F << ";" <<endl;
            *GCode << "M30;" <<endl;
        }
    }
}


void MachineProcess::innerHole1_GCode(machineNode *p, ofstream *GCode, bool* textHeadFlag)
{
    const int Cn = p->innerHole1.Cn, xDir = p->innerHole1.xDir, zDir = p->innerHole1.zDir;
    const double L = p->innerHole1.L, Tr = p->innerHole1.Tr, Cr = p->innerHole1.Cr, F = p->innerHole1.F;
    const machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (*textHeadFlag == true)
            {
                *GCode<< "O200;" <<endl;
                *textHeadFlag = false;
            }
            *GCode<< "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << "[" << L << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
            if (Cn == 1)
            {
                *GCode << "M30;" << endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << "[" << L << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
        }
        else
        {
            *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << "[" << L << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Cr << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "M30;" <<endl;
        }
    }
}

void MachineProcess::innerHole2_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->innerHole2.Cn, xDir = p->innerHole2.xDir, zDir = p->innerHole2.zDir;
    const double L = p->innerHole2.L, Tr = p->innerHole2.Tr, F = p->innerHole2.F;
    const machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (*textHeadFlag)
            {
                *GCode<< "O200;" <<endl;
                *textHeadFlag = false;
            }

            *GCode<< "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << "[" << L / Cn * Num << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L / Cn << " * #520 * -1]" << " F" << F << ";" <<endl;

            if (Cn == 1)
            {
                *GCode<< "M30;" <<endl;
            }

            Num++;
        }
        else if (a < Cn - 1)
        {
            *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << "[" << L / Cn * Num << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L / Cn << " * #520 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Tr * (Num - 1) << " * #521]" << " W" << "[" << L / Cn * (Num - 1) << " * #520 * -1]" << " F" << F << ";" <<endl;

            Num++;
        }
        else
        {
            *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << "[" << L / Cn * Num << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "M30;" <<endl;
        }
    }
}
void MachineProcess::innerHole3_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    double remainW = fmod(p->innerHole3.W, p->innerHole3.Tw);
    int Wn = p->innerHole3.W / p->innerHole3.Tw;
    int w;
    int a;
    if (remainW != 0)
    {
        Wn = Wn + 1;
    }

    if (p->innerHole3.W < p->innerHole3.Tw)
    {
        qDebug()<<"warning: The opening width is less than the tool width"<<endl;
    }
    else
    {
        const int Cn = p->innerHole3.Cn, xDir = p->innerHole3.xDir, zDir = p->innerHole3.zDir;
        const double Lr = p->innerHole3.Lr, Tr = p->innerHole3.Tr, W = p->innerHole3.W, W1 = p->innerHole3.W1, Tw = p->innerHole3.Tw, F = p->innerHole3.F;
        const machineNode* next = p->next;

        for (w = 0; w < Wn; w++)
        {

            if (0 == w)
            {
                if (true == *textHeadFlag)
                {
                    *GCode<< "O200;" <<endl;
                    *textHeadFlag = 0;
                }
                    *GCode<< "G00 U" << "[" << 3 << " * #521 * -1]" << " F" << F << ";" <<endl;
                    *GCode<< "G00 W" << "[" << (W1 + Tw) << " * #520]"<< " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << "[" << 3 << " * #521]" << " F" << F << ";" <<endl;
            }
            for (a = 0; a < Cn; a++)
            {
                if (0 == a)
                {
                    *GCode<< "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" << endl;
                    if (1 == Cn && w == Wn - 1)
                    {
                        *GCode<< "M30;" <<endl;
                    }
                }
                else if (a < (Cn - 1))
                {
                    *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F<<";"<<endl;
                    *GCode<< "G00 U" << "[" << Lr << " * #521 * -1]" << " F" << F<<";"<<endl;
                }
            }
            if (w < Wn - 2)
            {
                *GCode<< "G00 W" << "[" << Tw << " * #520]" << " F" << F << ";" <<endl;
            }
            else if (w < Wn - 1)
            {
                if (remainW != 0)
                {
                    *GCode<< "G00 W" << "[" << remainW << " * #520]" << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G00 W" << "[" << Tw << " * #520]" << " F" << F << ";" <<endl;
                }
            }
            else
            {
                *GCode<< "G00 U" << "[" << 3 << " * #521 * -1]" << " F" << F << ";" <<endl;
                *GCode<< "G00 W" << "[" << (W1 + W) << " * #520 * -1]" << " F" << F << ";" <<endl;
                *GCode<< "G00 U" << "[" << 3 << " * #521]" << " F" << F << ";" <<endl;
                *GCode<<"M30;"<<endl;
            }
        }
    }
}

void MachineProcess::innerHole4_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->innerHole4.Cn, xDir = p->innerHole4.xDir, zDir = p->innerHole4.zDir;
    double L = p->innerHole4.L, Tr = p->innerHole4.Tr, Cr = p->innerHole4.Cr, R = p->innerHole4.R,F = p->innerHole4.F;
    const machineNode* next = p->next;
    double Center[2]; // 0.X 01.Z
    /*===========================================平面求圆弧圆心=============================================== */
    double mid[2];// 0.Z  1.X
    double theta;
    double abs_radius;
    double half_length;
    double offset;
    double Turn2;

    abs_radius=abs(R);
    mid[1] = (0 + (Cr * xDir))/2;
    mid[0] = ((L * zDir) + 0)/2;

    half_length = sqrt((mid[1] - 0) * (mid[1] - 0) + (mid[0] - (L * zDir))*(mid[0] - (L * zDir)));
//    if (-1 == zDir)
        theta = atan2(((L * zDir) -0), (0 - (Cr * xDir))) - PI0_5;
//    else
//        theta = atan2((0 - (L * zDir)), ((Cr * xDir) - 0)) + PI0_5;

    if(half_length>abs_radius)
    {
        half_length=abs_radius;
    }
    Turn2 = asin (half_length/abs_radius);
    offset = abs_radius * cos(Turn2);
    Center[0] = mid[0] + (offset * cos(theta));
    Center[1] = mid[1] + (offset * sin(theta));
    if(1 == zDir)
    {
        Center[0] = (mid[0] + (offset * cos(theta))) * -1;
    }
    qDebug()<<Center[0]<<","<<Center[1]<<endl;
    /*===========================================平面求圆弧圆心=============================================== */
    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        if (-1 == zDir)
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
        }
        else
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }

        }

    }
    *GCode<<"M30;"<<endl;
}



void MachineProcess::innerHole5_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->innerHole5.Cn;
    double deltaT = p->innerHole5.deltaT;
    int zDir = p->innerHole5.zDir;
    double F = p->innerHole5.F;
    double BT = p->innerHole5.BT;
    double L = p->innerHole5.L;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (*textHeadFlag == true)
            {
                *GCode << "O200;" << endl;
                *textHeadFlag = false;
            }
            *GCode << "G01 W" << "[" << deltaT << " * #521]" << " F" << F << ";" << endl;
            if (Cn == 1)
            {
                *GCode << "G00 W" << "[" << deltaT << " * #521 * -1]" << " F" << F << ";" << endl;
            }
            else
            {
                *GCode << "G00 W" << "[" << BT << " * #521 * -1]" << " F" << F << ";" << endl;
            }
            if (Cn == 1)
            {
                *GCode << "M30;" << endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode << "G01 W" << "[" << (deltaT + BT) << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << BT << " * #521 * -1]" << " F" << F << ";" << endl;
        }
        else
        {
            *GCode << "G01 W" << "[" << (deltaT + BT) << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << L << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "M30;" << endl;
        }
    }
}

void MachineProcess::coneFace1_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->coneFace1.Cn;
    double Tr = p->coneFace1.Tr;
    int xDir = p->coneFace1.xDir;
    double A = p->coneFace1.A;
    int zDir = p->coneFace1.zDir;
    double F = p->coneFace1.F;

    int Num = 1;
    for (int a = 0; a < Cn; a++)
    {
        if (*textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = false;
        }
        *GCode << "G01 U" << "[" << Tr * Num << " * #521]" << " F" << F << ";" << endl;
        *GCode << "G01 U" << "[" << Tr * Num << " * #521 * -1]"
               << " W" << "[" << Tr * Num / tan(A / 180 * PI) << " * #520]"
               << " F" << F << ";" << endl;
        *GCode << "G00 W" << "[" << Tr * Num / tan(A / 180 * PI) << " * #520 * -1]"
               << " F" << F << ";" << endl;
        if (1 == Cn || a == Cn - 1)
        {
            *GCode << "M30;" << endl;
        }
        Num = Num + 1;
    }
}

void MachineProcess::coneFace2_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int xDir = p->coneFace2.xDir, zDir = p->coneFace2.zDir, Cn = p->coneFace2.Cn ;
    double L = p->coneFace2.L, Tr = p->coneFace2.Tr, Cr = p->coneFace2.Cr, A = p->coneFace2.A, F = p->coneFace2.F, remain = 0.005;
    machineNode* next = p->next;
    for (int a = 0; a < p->coneFace2.Cn; a++)
    {
        if (0 == a)
        {
            if(true == *textHeadFlag)
            {
                *GCode<<"O200;"<<endl;
                *textHeadFlag = 0;
            }
            *GCode<<"G01 W"<< "[" <<remain << " * #520]"<<" F"<<F<<";"<<endl;
            *GCode<<"G01 U"<< "[" <<Tr << " * #521]" <<" W"<< "[" <<Tr / tan(A / 180 * PI) << " * #520]"<<" F"<<F<<";"<<endl;
            *GCode<<"G01 W"<< "[" <<(L - (Tr / tan(A / 180 * PI)) - (remain * 2)) << " * #520]"<<" F"<<F<<";"<<endl;
            *GCode<<"G01 U"<< "[" <<Tr << " * #521 * -1]" <<" F"<<F<<";"<<endl;
            *GCode<<"G00 W"<< "[" <<(L - (remain * 2) - (Tr / tan(A / 180 * PI))) << " * #520 * -1]" <<";"<<endl;
            *GCode<<"G01 U"<< "[" <<Tr << " * #521]" <<" F"<<F<<";"<<endl;
            if(1 == Cn)
            {
                *GCode<<"M30;"<<endl;
            }
        }
        else
        {
            if((L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) < 0)
            {
                break;
            }
            if((L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 2))) > 0)
            {
                *GCode<<"G01 U"<< "[" <<Tr << " * #521]" <<" W"<< "[" <<Tr / tan(A / 180 * PI) << " * #520]"<<" F"<<F<<";"<<endl;
                *GCode<<"G01 W"<< "[" <<(L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) << " * #520]"<<" F"<<F<<";"<<endl;
                *GCode<<"G01 U"<< "[" <<Tr << " * #521 * -1]" <<" F"<<F<<";"<<endl;
                *GCode<<"G00 W"<< "[" <<(L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) << " * #520 * -1]" <<";"<<endl;
                *GCode<<"G01 U"<< "[" <<Tr << " * #521]" <<" F"<<F<<";"<<endl;
            }
            else if((L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) > 0)
            {
                *GCode<<"G01 U"<< "[" <<Tr << " * #521]" <<" W"<< "[" <<Tr / tan(A / 180 * PI) << " * #520]"<<" F"<<F<<";"<<endl;
                *GCode<<"G01 W"<< "[" <<(L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) << " * #520]"<<" F"<<F<<";"<<endl;
                *GCode<<"G01 U"<< "[" <<Tr * (a + 1) << " * #521 * -1]" <<" F"<<F<<";"<<endl;
                *GCode<<"G00 W"<< "[" <<(L - remain) << " * #520 * -1]" <<";"<<endl;
            }
        }
    }
    *GCode<<"G01 U"<< "[" <<Cr << " * #521]" <<" W"<< "[" <<L << " * #520]"<<" F"<<F<<";"<<endl;
    *GCode<<"G01 U"<< "[" <<Cr << " * #521 * -1]" <<" F"<<F<<";"<<endl;
    *GCode<<"G00 W"<< "[" <<L << " * #520 * -1]" <<";"<<endl;
    *GCode<<"M30;"<<endl;
}


void MachineProcess::coneFace3_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    int Cn = p->coneFace3.Cn, xDir = p->coneFace3.xDir, zDir = p->coneFace3.zDir;
    double Tr = p->coneFace3.Tr, Cr = p->coneFace3.Cr, L = p->coneFace3.L, F = p->coneFace3.F;
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (1 == *textHeadFlag)
            {
                *GCode << "O200\n";
                *textHeadFlag = 0;
            }
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F <<endl;
            *GCode << "G01 U" << "[" << Cr << " * #521 * -1]" << " W" << "[" << L << " * #520]" << " F" << F <<endl;
            *GCode << "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F <<endl;
            *GCode << "G00 U" << "[" << Cr << " * #521]" << " W" << "[" << L << " * #520 * -1]" << " F" << F <<endl;
            if (1 == Cn)
            {
                *GCode << "M30"<<endl;
            }
            Num++;
        }
        else if (a < (Cn - 1))
        {
            *GCode << "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F <<endl;
            *GCode << "G01 U" << "[" << Cr << " * #521 * -1]" << " W" << "[" << L << " * #520]" << " F" << F <<endl;
            *GCode << "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F <<endl;
            *GCode << "G00 U" << "[" << Cr << " * #521]" << " W" << "[" << L << " * #520 * -1]" << " F" << F <<endl;
            Num++;
        }
        else
        {
            *GCode<< "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << "[" << Cr << " * #521 * -1]" << " W" << "[" << L << " * #520]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Cr << " * #521]" << " W" << "[" << L << " * #520 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << "[" << Tr * (Num - 1) << " * #521 * -1]" << " F" << F << ";" <<endl;
            *GCode<< "M30;" <<endl;
        }
    }
}

void MachineProcess::coneFace4_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag) {
    int Num;
    int Cn = p->coneFace4.Cn, xDir = p->coneFace4.xDir, zDir = p->coneFace4.zDir;
    double Tr = p->coneFace4.Tr, Cr = p->coneFace4.Cr, L = p->coneFace4.L, F = p->coneFace4.F;
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++) {
        if (0 == a) {
            if (true == *textHeadFlag) {
                *GCode << "O200;" << endl;
                *textHeadFlag = 0;
            }
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Cr << " * #521]" << " W" << "[" << L << " * #520]"<< " F" << F << ";" << endl;
            *GCode << "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 U" << "[" << Cr << " * #521 * -1]" << " W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            if (1 == Cn) {
                *GCode << "M30;" << endl;
            }
            Num = Num + 1;
        }
        else if (a < (Cn - 1)) {
            *GCode << "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Cr << " * #521]" << " W" << "[" << L << " * #520]"<< " F" << F << ";" << endl;
            *GCode << "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 U" << "[" << Cr << " * #521 * -1]" << " W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            Num = Num + 1;
        }
        else {
            *GCode << "G01 U" << "[" << Tr * 2 << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Cr << " * #521]" << " W" << "[" << L << " * #520]"<< " F" << F << ";" << endl;
            *GCode << "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 U" << "[" << Cr << " * #521 * -1]" << " W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 U" << "[" << Tr * (Cn - 1) << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "M30;" << endl;
        }
    }
}


void MachineProcess::screwThread1_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag) {
    int num = 2;
    const int Cn = p->screwThread1.Cn, xDir = p->screwThread1.xDir, zDir = p->screwThread1.zDir;
    const double L = p->screwThread1.L, Tr = p->screwThread1.Tr, Tp = p->screwThread1.Tp, F = p->screwThread1.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (0 == a)
        {
            if (true == *textHeadFlag)
            {
                *GCode << "O200;" << endl;
                *textHeadFlag = 0;
            }
            *GCode << "M3 S300 G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G32 W" << "[" << L << " * #520]"<< " F" << Tp << ";" << endl;
            *GCode << "G00 U" << "[" << Tr * 2 << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            if (1 == Cn) {
                *GCode << "M30;" << endl;
            }
        } else if (a < (Cn - 1)) {
            *GCode << "G01 U" << "[" << Tr * num << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G32 W" << "[" << L << " * #520]" << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << "[" << Tr * (num + 1) << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            num = num + 1;
        } else {
            *GCode << "G01 U" << "[" << Tr * num << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G32 W" << "[" << L << " * #520]"<< " F" << Tp << ";" << endl;
            *GCode << "G00 U" << "[" << Tr * num << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            *GCode << "M30;" << endl;
        }
    }
}

void MachineProcess::screwThread2_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->screwThread2.Cn, xDir = p->screwThread2.xDir, zDir = p->screwThread2.zDir;
    const double Tr = p->screwThread2.Tr, Tp = p->screwThread2.Tp, F = p->screwThread2.F;
    const double tanA = tan(p->screwThread2.A/180 * PI);
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        *GCode << "M3 S100 G01 U" << "[" << Tr * Num << " * #521]" << " F" << F << ";" << endl;
        *GCode << "G32 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << "[" << Tr * Num / tanA << " * #520]"<< " F" << Tp << ";" << endl;
        *GCode << "G00 W" << "[" << Tr * Num / tanA << " * #520 * -1]" << " F" << F << ";" << endl;
        if (a == Cn -1)
        {
            *GCode << "M30;" << endl;
        }
        Num = Num + 1;
    }
}

void MachineProcess::screwThread3_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int num = 2;
    const int Cn = p->screwThread3.Cn, xDir = p->screwThread3.xDir, zDir = p->screwThread3.zDir;
    const double L = p->screwThread3.L, Tr = p->screwThread3.Tr, Tp = p->screwThread3.Tp, F = p->screwThread3.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++) {
        if (0 == a) {
            if (true == *textHeadFlag) {
                *GCode << "O200;" << endl;
                *textHeadFlag = 0;
            }
            *GCode << "M3 S300 G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G32 W" << "[" << L << " * #520]" << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << "[" << Tr * 2 << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            if (1 == Cn) {
                *GCode << "M30;" << endl;
            }
        } else if (a < (Cn - 1)) {
            *GCode << "G01 U" << "[" << Tr * num << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G32 W" << "[" << L << " * #520]"<< " F" << Tp << ";" << endl;
            *GCode << "G00 U" << "[" << Tr * (num + 1) << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            num = num + 1;
        } else {
            *GCode << "G01 U" << "[" << Tr * num << " * #521]" << " F" << F << ";" << endl;
            *GCode << "G32 W" << "[" << L << " * #520]" << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << "[" << Tr << " * #521 * -1]" << " F" << F << ";" << endl;
            *GCode << "G00 W" << "[" << L << " * #520 * -1]" << " F" << F << ";" << endl;
            *GCode << "G01 U" << "[" << Tr << " * #521]" << " F" << F << ";" << endl;
            *GCode << "M30;" << endl;
        }
    }
}

void MachineProcess::screwThread4_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->screwThread4.Cn, xDir = p->screwThread4.xDir, zDir = p->screwThread4.zDir;
    const double Tr = p->screwThread4.Tr, Tp = p->screwThread4.Tp, F = p->screwThread4.F;
    const double tanA = tan(p->screwThread4.A/180 * PI);
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        *GCode << "G01 U" << "[" << Tr * Num << " * #521]" << " F" << F << "M3 S100;" << ";" << endl;
        *GCode << "G32 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << Tr * Num / tanA << " * #520]"<< " F" << Tp << ";" << endl;
        *GCode << "G00 W" << "[" << Tr * Num / tanA << " * #520 * -1]" << " F" << F << ";" << endl;
        if (1 == Cn)
        {
            *GCode << "M30;" << endl;
        }
        Num = Num + 1;
    }
}
void MachineProcess::chamfer1_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->chamfer1.Cn, xDir = p->chamfer1.xDir, zDir = p->chamfer1.zDir;
    double L = p->chamfer1.L, Tr = p->chamfer1.Tr, Cr = p->chamfer1.Cr, R = p->chamfer1.R,F = p->chamfer1.F;
    double Center[2]; // 0.X 01.Z
    /*===========================================平面求圆弧圆心=============================================== */
    double mid[2];// 0.Z  1.X
    double theta;
    double abs_radius;
    double half_length;
    double offset;
    double Turn2;

    abs_radius=abs(R);
    mid[1] = (0 + (Cr * xDir))/2;
    mid[0] = ((L * zDir) + 0)/2;

    half_length = sqrt((mid[1] - 0) * (mid[1] - 0) + (mid[0] - (L * zDir))*(mid[0] - (L * zDir)));
//    if (-1 == zDir)
        theta = atan2(((L * zDir) -0), (0 - (Cr * xDir))) - PI0_5;
//    else
//        theta = atan2((0 - (L * zDir)), ((Cr * xDir) - 0)) + PI0_5;

    if(half_length>abs_radius)
    {
        half_length=abs_radius;
    }
    Turn2 = asin (half_length/abs_radius);
    offset = abs_radius * cos(Turn2);
    Center[0] = mid[0] + (offset * cos(theta));
    Center[1] = mid[1] + (offset * sin(theta));
    if(1 == zDir)
    {
        Center[0] = (mid[0] + (offset * cos(theta))) * -1;
    }
    qDebug()<<Center[0]<<","<<Center[1]<<endl;
    /*===========================================平面求圆弧圆心=============================================== */
    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        if (-1 == zDir)
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
        }
        else
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }

        }

    }
    *GCode<<"M30;"<<endl;
}

void MachineProcess::chamfer2_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->chamfer2.Cn, xDir = p->chamfer2.xDir, zDir = p->chamfer2.zDir;
    const double Tr = p->chamfer2.Tr, F = p->chamfer2.F, L = p->chamfer2.L / p->chamfer2.Cn;
    machineNode* next = p->next;

    if (*textHeadFlag)
    {
        *GCode << "O200;" << endl;
        *textHeadFlag = false;
    }

    for (int a = 0; a < Cn; a++)
    {
        *GCode << "G01 U" << "[" << Tr * Num << " * #521]" << " F" << F << ";" << endl;
        *GCode << "G01 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << "[" << L * Num << " * #520]" << " F" << F << ";" << endl;
        *GCode << "G00 W" << "[" << L * Num << " * #520 * -1]" << " F" << F << ";" << endl;
        if (a == Cn - 1)
        {
            *GCode << "M30;" << endl;
        }
        Num++;
    }
}

void MachineProcess::chamfer3_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->chamfer3.Cn, xDir = p->chamfer3.xDir, zDir = p->chamfer3.zDir;
    double L = p->chamfer3.L, Tr = p->chamfer3.Tr, Cr = p->chamfer3.Cr, R = p->chamfer3.R,F = p->chamfer3.F;
    machineNode* next = p->next;
    double Center[2]; // 0.X 01.Z
    /*===========================================平面求圆弧圆心=============================================== */
    double mid[2];// 0.Z  1.X
    double theta;
    double abs_radius;
    double half_length;
    double offset;
    double Turn2;

    abs_radius=abs(R);
    mid[1] = (0 + (Cr * xDir))/2;
    mid[0] = ((L * zDir) + 0)/2;

    half_length = sqrt((mid[1] - 0) * (mid[1] - 0) + (mid[0] - (L * zDir))*(mid[0] - (L * zDir)));
//    if (-1 == zDir)
        theta = atan2(((L * zDir) -0), (0 - (Cr * xDir))) - PI0_5;
//    else
//        theta = atan2((0 - (L * zDir)), ((Cr * xDir) - 0)) + PI0_5;

    if(half_length>abs_radius)
    {
        half_length=abs_radius;
    }
    Turn2 = asin (half_length/abs_radius);
    offset = abs_radius * cos(Turn2);
    Center[0] = mid[0] + (offset * cos(theta));
    Center[1] = mid[1] + (offset * sin(theta));
    if(1 == zDir)
    {
        Center[0] = (mid[0] + (offset * cos(theta))) * -1;
    }
    qDebug()<<Center[0]<<","<<Center[1]<<endl;
    /*===========================================平面求圆弧圆心=============================================== */
    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        if (-1 == zDir)
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
        }
        else
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }

        }

    }
    *GCode<<"M30;"<<endl;
}

void MachineProcess::chamfer4_GCode(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    int Cn = p->chamfer4.Cn, xDir = p->chamfer4.xDir, zDir = p->chamfer4.zDir;
    double Tr = p->chamfer4.Tr, L = p->chamfer4.L, F = p->chamfer4.F;
    machineNode* next = p->next;

    if (*textHeadFlag)
    {
        *GCode << "O200;" << endl;
        *textHeadFlag = false;
    }

    for (int a = 0; a < Cn; a++)
    {
        *GCode << "G01 U" << "[" << Tr * Num << " * #521]" << " F" << F << ";" << endl;
        *GCode << "G01 U" << "[" << Tr * Num << " * #521 * -1]" << " W" << "[" << L / Cn * Num << " * #520]" << " F" << F << ";" << endl;
        *GCode << "G00 W" << "[" << L / Cn * Num << " * #520 * -1]" << " F" << F << ";" << endl;
        if (Cn == 1)
        {
            *GCode << "M30;" << endl;
        }
        Num++;
    }
}


// 根据工艺序列输出G代码
bool MachineProcess::outputGCode()
{
    machineNode *p = nullptr;
    if(modify_flg == 0)
    {
        p = dealInterfaceData->m_mSeq.index.tail;
    }
    if(modify_flg == 1)
    {
        p = findNode(cur_Node);
    }
    string TEXT = "/home/root/nc/O0300.CNC";
    ofstream GCode(TEXT,ios::out);

    bool textHeadFlag = true;

    // 文件打开失败
    if(!GCode)
    {
        return false;
    }
    switch(p->type){

        case OUTER_CIRCLE_ONE :// 外圆1模式工艺
            outerCircle1_GCode(p, &GCode, &textHeadFlag);
            break;

        case OUTER_CIRCLE_TWO :// 外圆2模式工艺
            outerCircle2_GCode(p, &GCode, &textHeadFlag);
            break;

        case OUTER_CIRCLE_THREE :// 外圆3模式工艺
            outerCircle3_GCode(p, &GCode, &textHeadFlag);
            break;
        case END_FACE_ONE :
            endFace1_GCode(p, &GCode, &textHeadFlag);
            break;
        case END_FACE_TWO :
            endFace2_GCode(p, &GCode, &textHeadFlag);
            break;
        case END_FACE_THREE :
            endFace3_GCode(p, &GCode, &textHeadFlag);
            break;
        case INNER_HOLE_ONE :
            innerHole1_GCode(p, &GCode, &textHeadFlag);
            break;
        case INNER_HOLE_TWO :
            innerHole2_GCode(p, &GCode, &textHeadFlag);
            break;
        case INNER_HOLE_THREE :
            innerHole3_GCode(p, &GCode, &textHeadFlag);
            break;
        case INNER_HOLE_FOUR :
            innerHole4_GCode(p, &GCode, &textHeadFlag);
            break;
        case INNER_HOLE_FIVE :
            innerHole5_GCode(p, &GCode, &textHeadFlag);
            break;
        case CONE_FACE_ONE :
            coneFace1_GCode(p, &GCode, &textHeadFlag);
            break;
        case CONE_FACE_TWO :
            coneFace2_GCode(p, &GCode, &textHeadFlag);
            break;
        case CONE_FACE_THREE :
            coneFace3_GCode(p, &GCode, &textHeadFlag);
            break;
        case CONE_FACE_FOUR :
            coneFace4_GCode(p, &GCode, &textHeadFlag);
            break;
        case SCREW_THREAD_ONE :
            screwThread1_GCode(p, &GCode, &textHeadFlag);
            break;
        case SCREW_THREAD_TWO :
            screwThread2_GCode(p, &GCode, &textHeadFlag);
            break;
        case SCREW_THREAD_THREE :
            screwThread3_GCode(p, &GCode, &textHeadFlag);
            break;
        case SCREW_THREAD_FOUR :
            screwThread4_GCode(p, &GCode, &textHeadFlag);
            break;
        case CHAMFER_ONE :
            chamfer1_GCode(p, &GCode, &textHeadFlag);
            break;
        case CHAMFER_TWO :
            chamfer2_GCode(p, &GCode, &textHeadFlag);
            break;
        case CHAMFER_THREE :
            chamfer3_GCode(p, &GCode, &textHeadFlag);
            break;
        case CHAMFER_FOUR :
            chamfer4_GCode(p, &GCode, &textHeadFlag);
            break;
        default:
            break;
    }
    GCode.close();
    return true;
}

bool MachineProcess::textRecordData()
{
    machineNode *p = m_mSeq.getHead();
    string TEXT = "interfaceData.txt";
    ofstream interfaceData(TEXT,ios::out);

    // 文件打开失败
    if(!interfaceData)
    {
        return false;
    }

    // bar的坐标系是bar的左下角是原点，向右和向上分别为正。而G代码的坐标系是bar边界和镜像线交点为原点，向右Z（U）和向下X（W）为正数
    while(p != nullptr)
    {
        switch(p->type)
        {
            case OUTER_CIRCLE_ONE :// 切外圆模式1
            {
                interfaceData<<"OUTER_CIRCLE_ONE"<<endl;                        // 模式类型
                interfaceData<<std::to_string(p->outerCircle1.xDir)<<endl;
                interfaceData<<std::to_string(p->outerCircle1.zDir)<<endl;
                interfaceData<<std::to_string(p->outerCircle1.L)<<endl;           // 每次切深
                interfaceData<<std::to_string(p->outerCircle1.Tr)<<endl;          // 每次走刀量
                interfaceData<<std::to_string(p->outerCircle1.Cn)<<endl;          // 进给次数
                interfaceData<<std::to_string(p->outerCircle1.Cr)<<endl;          // 总进刀量
                interfaceData<<std::to_string(p->outerCircle1.F)<<endl;           // 进给速度
                break;
            }

            case OUTER_CIRCLE_TWO :// 切外圆模式2
            {
                interfaceData<<"OUTER_CIRCLE_TWO"<<endl;                         // 模式类型
                interfaceData<<std::to_string(p->outerCircle2.xDir)<<endl;
                interfaceData<<std::to_string(p->outerCircle2.zDir)<<endl;
                interfaceData<<std::to_string(p->outerCircle2.L)<<endl;           // 每次切深
                interfaceData<<std::to_string(p->outerCircle2.Tr)<<endl;          // 每次走刀量
                interfaceData<<std::to_string(p->outerCircle2.Cn)<<endl;          // 进给次数
                interfaceData<<std::to_string(p->outerCircle2.Cr)<<endl;          // 总进刀量
                interfaceData<<std::to_string(p->outerCircle2.A)<<endl;          // 总进刀量
                interfaceData<<std::to_string(p->outerCircle2.F)<<endl;           // 进给速度
                break;
            }

            case OUTER_CIRCLE_THREE :// 切外圆模式3
            {
                interfaceData<<"OUTER_CIRCLE_THREE"<<endl;
                interfaceData<<std::to_string(p->outerCircle3.xDir)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.zDir)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.G2G3)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.L)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.Tr)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.Cn)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.Cr)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.R)<<endl;
                interfaceData<<std::to_string(p->outerCircle3.F)<<endl;
                break;
            }

            case END_FACE_ONE :
            {
                interfaceData<<"END_FACE_ONE"<<endl;
                interfaceData<<std::to_string(p->endFace1.xDir)<<endl;
                interfaceData<<std::to_string(p->endFace1.zDir)<<endl;
                interfaceData<<std::to_string(p->endFace1.Lr)<<endl;
                interfaceData<<std::to_string(p->endFace1.deltaT)<<endl;
                interfaceData<<std::to_string(p->endFace1.Cn)<<endl;
                interfaceData<<std::to_string(p->endFace1.CT)<<endl;
                interfaceData<<std::to_string(p->endFace1.F)<<endl;
                break;
            }

            case END_FACE_TWO :
            {
                interfaceData<<"END_FACE_TWO"<<endl;
                interfaceData<<std::to_string(p->endFace2.xDir)<<endl;
                interfaceData<<std::to_string(p->endFace2.zDir)<<endl;
                interfaceData<<std::to_string(p->endFace2.Lr)<<endl;
                interfaceData<<std::to_string(p->endFace2.Tr)<<endl;
                interfaceData<<std::to_string(p->endFace2.Cn)<<endl;
                interfaceData<<std::to_string(p->endFace2.W)<<endl;
                interfaceData<<std::to_string(p->endFace2.Tw)<<endl;
                interfaceData<<std::to_string(p->endFace2.F)<<endl;
                break;
            }

            case END_FACE_THREE :
            {
                interfaceData<<"END_FACE_THREE"<<endl;
                interfaceData<<std::to_string(p->endFace3.xDir)<<endl;
                interfaceData<<std::to_string(p->endFace3.zDir)<<endl;
                interfaceData<<std::to_string(p->endFace3.Lr)<<endl;
                interfaceData<<std::to_string(p->endFace3.deltaT)<<endl;
                interfaceData<<std::to_string(p->endFace3.Cn)<<endl;
                interfaceData<<std::to_string(p->endFace3.CT)<<endl;
                interfaceData<<std::to_string(p->endFace3.F)<<endl;
                break;
            }

            case INNER_HOLE_ONE :
            {
                interfaceData<<"INNER_HOLE_ONE"<<endl;
                interfaceData<<std::to_string(p->innerHole1.xDir)<<endl;
                interfaceData<<std::to_string(p->innerHole1.zDir)<<endl;
                interfaceData<<std::to_string(p->innerHole1.L)<<endl;
                interfaceData<<std::to_string(p->innerHole1.Tr)<<endl;
                interfaceData<<std::to_string(p->innerHole1.Cn)<<endl;
                interfaceData<<std::to_string(p->innerHole1.Cr)<<endl;
                interfaceData<<std::to_string(p->innerHole1.F)<<endl;
                break;
            }
            case INNER_HOLE_TWO :
            {
                interfaceData<<"INNER_HOLE_TWO"<<endl;
                interfaceData<<std::to_string(p->innerHole2.xDir)<<endl;
                interfaceData<<std::to_string(p->innerHole2.zDir)<<endl;
                interfaceData<<std::to_string(p->innerHole2.L)<<endl;
                interfaceData<<std::to_string(p->innerHole2.Tr)<<endl;
                interfaceData<<std::to_string(p->innerHole2.Cn)<<endl;
                interfaceData<<std::to_string(p->innerHole2.Cr)<<endl;
                interfaceData<<std::to_string(p->innerHole2.A)<<endl;
                interfaceData<<std::to_string(p->innerHole2.F)<<endl;
                break;
            }

            case INNER_HOLE_THREE :
            {
                interfaceData<<"INNER_HOLE_THREE"<<endl;
                interfaceData<<std::to_string(p->innerHole3.xDir)<<endl;
                interfaceData<<std::to_string(p->innerHole3.zDir)<<endl;
                interfaceData<<std::to_string(p->innerHole3.Lr)<<endl;
                interfaceData<<std::to_string(p->innerHole3.Tr)<<endl;
                interfaceData<<std::to_string(p->innerHole3.Cn)<<endl;
                interfaceData<<std::to_string(p->innerHole3.W)<<endl;
                interfaceData<<std::to_string(p->innerHole3.W1)<<endl;
                interfaceData<<std::to_string(p->innerHole3.Tw)<<endl;
                interfaceData<<std::to_string(p->innerHole3.F)<<endl;
                break;
            }

            case INNER_HOLE_FOUR :
            {
                interfaceData<<"INNER_HOLE_FOUR"<<endl;
                interfaceData<<std::to_string(p->innerHole4.xDir)<<endl;
                interfaceData<<std::to_string(p->innerHole4.zDir)<<endl;
                interfaceData<<std::to_string(p->innerHole4.G2G3)<<endl;
                interfaceData<<std::to_string(p->innerHole4.L)<<endl;
                interfaceData<<std::to_string(p->innerHole4.Tr)<<endl;
                interfaceData<<std::to_string(p->innerHole4.Cn)<<endl;
                interfaceData<<std::to_string(p->innerHole4.Cr)<<endl;
                interfaceData<<std::to_string(p->innerHole4.R)<<endl;
                interfaceData<<std::to_string(p->innerHole4.F)<<endl;
                break;
            }

            case INNER_HOLE_FIVE :
            {
                interfaceData<<"INNER_HOLE_FIVE"<<endl;
                interfaceData<<std::to_string(p->innerHole5.xDir)<<endl;
                interfaceData<<std::to_string(p->innerHole5.zDir)<<endl;
                interfaceData<<std::to_string(p->innerHole5.L)<<endl;
                interfaceData<<std::to_string(p->innerHole5.deltaT)<<endl;
                interfaceData<<std::to_string(p->innerHole5.Cn)<<endl;
                interfaceData<<std::to_string(p->innerHole5.BT)<<endl;
                interfaceData<<std::to_string(p->innerHole5.F)<<endl;
                break;
            }

            case CONE_FACE_ONE :
            {
                interfaceData<<"CONE_FACE_ONE"<<endl;
                interfaceData<<std::to_string(p->coneFace1.xDir)<<endl;
                interfaceData<<std::to_string(p->coneFace1.zDir)<<endl;
                interfaceData<<std::to_string(p->coneFace1.L)<<endl;
                interfaceData<<std::to_string(p->coneFace1.Tr)<<endl;
                interfaceData<<std::to_string(p->coneFace1.Cn)<<endl;
                interfaceData<<std::to_string(p->coneFace1.Cr)<<endl;
                interfaceData<<std::to_string(p->coneFace1.A)<<endl;
                interfaceData<<std::to_string(p->coneFace1.F)<<endl;
                break;
            }

            case CONE_FACE_TWO :
            {
                interfaceData<<"CONE_FACE_TWO"<<endl;
                interfaceData<<std::to_string(p->coneFace2.xDir)<<endl;
                interfaceData<<std::to_string(p->coneFace2.zDir)<<endl;
                interfaceData<<std::to_string(p->coneFace2.L)<<endl;
                interfaceData<<std::to_string(p->coneFace2.Tr)<<endl;
                interfaceData<<std::to_string(p->coneFace2.Cn)<<endl;
                interfaceData<<std::to_string(p->coneFace2.Cr)<<endl;
                interfaceData<<std::to_string(p->coneFace2.A)<<endl;
                interfaceData<<std::to_string(p->coneFace2.F)<<endl;
                break;
            }

            case CONE_FACE_THREE :
            {
                interfaceData<<"CONE_FACE_THREE"<<endl;
                interfaceData<<std::to_string(p->coneFace3.xDir)<<endl;
                interfaceData<<std::to_string(p->coneFace3.zDir)<<endl;
                interfaceData<<std::to_string(p->coneFace3.L)<<endl;
                interfaceData<<std::to_string(p->coneFace3.Tr)<<endl;
                interfaceData<<std::to_string(p->coneFace3.Cn)<<endl;
                interfaceData<<std::to_string(p->coneFace3.Cr)<<endl;
                interfaceData<<std::to_string(p->coneFace3.A)<<endl;
                interfaceData<<std::to_string(p->coneFace3.F)<<endl;
                break;
            }

            case CONE_FACE_FOUR :
            {
                interfaceData<<"CONE_FACE_FOUR"<<endl;
                interfaceData<<std::to_string(p->coneFace4.xDir)<<endl;
                interfaceData<<std::to_string(p->coneFace4.zDir)<<endl;
                interfaceData<<std::to_string(p->coneFace4.L)<<endl;
                interfaceData<<std::to_string(p->coneFace4.Tr)<<endl;
                interfaceData<<std::to_string(p->coneFace4.Cn)<<endl;
                interfaceData<<std::to_string(p->coneFace4.Cr)<<endl;
                interfaceData<<std::to_string(p->coneFace4.A)<<endl;
                interfaceData<<std::to_string(p->coneFace4.F)<<endl;
                break;
            }

            case SCREW_THREAD_ONE :
            {
                interfaceData<<"SCREW_THREAD_ONE"<<endl;
                interfaceData<<std::to_string(p->screwThread1.xDir)<<endl;
                interfaceData<<std::to_string(p->screwThread1.zDir)<<endl;
                interfaceData<<std::to_string(p->screwThread1.L)<<endl;
                interfaceData<<std::to_string(p->screwThread1.Tr)<<endl;
                interfaceData<<std::to_string(p->screwThread1.Cn)<<endl;
                interfaceData<<std::to_string(p->screwThread1.Cr)<<endl;
                interfaceData<<std::to_string(p->screwThread1.Tp)<<endl;
                interfaceData<<std::to_string(p->screwThread1.F)<<endl;
                interfaceData<<std::to_string(p->screwThread1.unit)<<endl;
                interfaceData<<std::to_string(p->screwThread1.multi_head)<<endl;
                interfaceData<<std::to_string(p->screwThread1.startA)<<endl;
                interfaceData<<std::to_string(p->screwThread1.tailFlick)<<endl;
                interfaceData<<std::to_string(p->screwThread1.filingProcessing)<<endl;
                interfaceData<<std::to_string(p->screwThread1.filingDistance)<<endl;
                break;
            }

            case SCREW_THREAD_TWO :
            {
                interfaceData<<"SCREW_THREAD_TWO"<<endl;
                interfaceData<<std::to_string(p->screwThread2.xDir)<<endl;
                interfaceData<<std::to_string(p->screwThread2.zDir)<<endl;
                interfaceData<<std::to_string(p->screwThread2.L)<<endl;
                interfaceData<<std::to_string(p->screwThread2.Tr)<<endl;
                interfaceData<<std::to_string(p->screwThread2.Cn)<<endl;
                interfaceData<<std::to_string(p->screwThread2.Cr)<<endl;
                interfaceData<<std::to_string(p->screwThread2.Tp)<<endl;
                interfaceData<<std::to_string(p->screwThread2.A)<<endl;
                interfaceData<<std::to_string(p->screwThread2.F)<<endl;
                interfaceData<<std::to_string(p->screwThread2.unit)<<endl;
                interfaceData<<std::to_string(p->screwThread2.multi_head)<<endl;
                interfaceData<<std::to_string(p->screwThread2.startA)<<endl;
                interfaceData<<std::to_string(p->screwThread2.tailFlick)<<endl;
                interfaceData<<std::to_string(p->screwThread2.filingProcessing)<<endl;
                interfaceData<<std::to_string(p->screwThread2.filingDistance)<<endl;
                break;
            }

            case SCREW_THREAD_THREE :
            {
                interfaceData<<"SCREW_THREAD_THREE"<<endl;
                interfaceData<<std::to_string(p->screwThread3.xDir)<<endl;
                interfaceData<<std::to_string(p->screwThread3.zDir)<<endl;
                interfaceData<<std::to_string(p->screwThread3.L)<<endl;
                interfaceData<<std::to_string(p->screwThread3.Tr)<<endl;
                interfaceData<<std::to_string(p->screwThread3.Cn)<<endl;
                interfaceData<<std::to_string(p->screwThread3.Cr)<<endl;
                interfaceData<<std::to_string(p->screwThread3.Tp)<<endl;
                interfaceData<<std::to_string(p->screwThread3.F)<<endl;
                interfaceData<<std::to_string(p->screwThread3.unit)<<endl;
                interfaceData<<std::to_string(p->screwThread3.multi_head)<<endl;
                interfaceData<<std::to_string(p->screwThread3.startA)<<endl;
                interfaceData<<std::to_string(p->screwThread3.tailFlick)<<endl;
                interfaceData<<std::to_string(p->screwThread3.filingProcessing)<<endl;
                interfaceData<<std::to_string(p->screwThread3.filingDistance)<<endl;
                break;
            }

            case SCREW_THREAD_FOUR :
            {
                interfaceData<<"SCREW_THREAD_FOUR"<<endl;
                interfaceData<<std::to_string(p->screwThread4.xDir)<<endl;
                interfaceData<<std::to_string(p->screwThread4.zDir)<<endl;
                interfaceData<<std::to_string(p->screwThread4.L)<<endl;
                interfaceData<<std::to_string(p->screwThread4.Tr)<<endl;
                interfaceData<<std::to_string(p->screwThread4.Cn)<<endl;
                interfaceData<<std::to_string(p->screwThread4.Cr)<<endl;
                interfaceData<<std::to_string(p->screwThread4.Tp)<<endl;
                interfaceData<<std::to_string(p->screwThread4.A)<<endl;
                interfaceData<<std::to_string(p->screwThread4.F)<<endl;
                interfaceData<<std::to_string(p->screwThread4.unit)<<endl;
                interfaceData<<std::to_string(p->screwThread4.multi_head)<<endl;
                interfaceData<<std::to_string(p->screwThread4.startA)<<endl;
                interfaceData<<std::to_string(p->screwThread4.tailFlick)<<endl;
                interfaceData<<std::to_string(p->screwThread4.filingProcessing)<<endl;
                interfaceData<<std::to_string(p->screwThread4.filingDistance)<<endl;
                break;
            }

            case CHAMFER_ONE :
            {
                interfaceData<<"CHAMFER_ONE"<<endl;
                interfaceData<<std::to_string(p->chamfer1.xDir)<<endl;
                interfaceData<<std::to_string(p->chamfer1.zDir)<<endl;
                interfaceData<<std::to_string(p->chamfer1.G2G3)<<endl;
                interfaceData<<std::to_string(p->chamfer1.L)<<endl;
                interfaceData<<std::to_string(p->chamfer1.Tr)<<endl;
                interfaceData<<std::to_string(p->chamfer1.Cn)<<endl;
                interfaceData<<std::to_string(p->chamfer1.Cr)<<endl;
                interfaceData<<std::to_string(p->chamfer1.R)<<endl;
                interfaceData<<std::to_string(p->chamfer1.F)<<endl;
                break;
            }
            case CHAMFER_TWO :
            {
                interfaceData<<"CHAMFER_TWO"<<endl;
                interfaceData<<std::to_string(p->chamfer2.xDir)<<endl;
                interfaceData<<std::to_string(p->chamfer2.zDir)<<endl;
                interfaceData<<std::to_string(p->chamfer2.L)<<endl;
                interfaceData<<std::to_string(p->chamfer2.Tr)<<endl;
                interfaceData<<std::to_string(p->chamfer2.Cn)<<endl;
                interfaceData<<std::to_string(p->chamfer2.Cr)<<endl;
                interfaceData<<std::to_string(p->chamfer2.A)<<endl;
                interfaceData<<std::to_string(p->chamfer2.F)<<endl;
                break;
            }

            case CHAMFER_THREE :
            {
                interfaceData<<"CHAMFER_THREE"<<endl;
                interfaceData<<std::to_string(p->chamfer3.xDir)<<endl;
                interfaceData<<std::to_string(p->chamfer3.zDir)<<endl;
                interfaceData<<std::to_string(p->chamfer3.G2G3)<<endl;
                interfaceData<<std::to_string(p->chamfer3.L)<<endl;
                interfaceData<<std::to_string(p->chamfer3.Tr)<<endl;
                interfaceData<<std::to_string(p->chamfer3.Cn)<<endl;
                interfaceData<<std::to_string(p->chamfer3.Cr)<<endl;
                interfaceData<<std::to_string(p->chamfer3.R)<<endl;
                interfaceData<<std::to_string(p->chamfer3.F)<<endl;
                break;
            }

            case CHAMFER_FOUR :
            {
                interfaceData<<"CHAMFER_FOUR"<<endl;
                interfaceData<<std::to_string(p->chamfer4.xDir)<<endl;
                interfaceData<<std::to_string(p->chamfer4.zDir)<<endl;
                interfaceData<<std::to_string(p->chamfer4.L)<<endl;
                interfaceData<<std::to_string(p->chamfer4.Tr)<<endl;
                interfaceData<<std::to_string(p->chamfer4.Cn)<<endl;
                interfaceData<<std::to_string(p->chamfer4.Cr)<<endl;
                interfaceData<<std::to_string(p->chamfer4.A)<<endl;
                interfaceData<<std::to_string(p->chamfer4.F)<<endl;
                break;
            }
        default:
            break;
        }
        p = p->next;
    }
    interfaceData.close();
    return true;
}

bool MachineProcess::textRecoverData()
{
    string TEXT = "interfaceData.txt";
    ifstream interfaceData(TEXT,ios::in);

    s_outerCircleMode1 outerCircle1;
    s_outerCircleMode2 outerCircle2;
    s_outerCircleMode3 outerCircle3;
    s_endFaceMode1 endFace1;
    s_endFaceMode2 endFace2;
    s_endFaceMode3 endFace3;
    s_innerHoleMode1 innerHole1;
    s_innerHoleMode2 innerHole2;
    s_innerHoleMode3 innerHole3;
    s_innerHoleMode4 innerHole4;
    s_innerHoleMode5 innerHole5;
    s_coneFaceMode1 coneFace1;
    s_coneFaceMode2 coneFace2;
    s_coneFaceMode3 coneFace3;
    s_coneFaceMode4 coneFace4;
    s_screwThreadMode1 screwThread1;
    s_screwThreadMode2 screwThread2;
    s_screwThreadMode3 screwThread3;
    s_screwThreadMode4 screwThread4;
    s_chamferMode1 chamfer1;
    s_chamferMode2 chamfer2;
    s_chamferMode3 chamfer3;
    s_chamferMode4 chamfer4;

    string TempData;
    int loopNumber;
    int type;
    int findNodeNum = 1;

    // 文件打开失败
    if (!interfaceData)
    {
        dealInterfaceData->firstInsystem = true;
        return false;
    }
    while (getline(interfaceData,TempData))
    {
        checkWitchType(&loopNumber, &type, TempData);

        TextRecoverNode(loopNumber, type, TempData, &outerCircle1, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &outerCircle2, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &outerCircle3, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &endFace1, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &endFace2, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &endFace3, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &innerHole1, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &innerHole2, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &innerHole3, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &innerHole4, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &innerHole5, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &coneFace1, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &coneFace2, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &coneFace3, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &coneFace4, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &screwThread1, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &screwThread2, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &screwThread3, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &screwThread4, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &chamfer1, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &chamfer2, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &chamfer3, &findNodeNum);
        TextRecoverNode(loopNumber, type, TempData, &chamfer4, &findNodeNum);

        loopNumber--;
    }
    interfaceData.close();
    return true;
}

void MachineProcess::checkWitchType(int* loopNum, int* type, string data)
{
    if ("OUTER_CIRCLE_ONE" == data)
    {
        *type = OUTER_CIRCLE_ONE;
        *loopNum = 7 + 1;                   //加一是因为有一次类型判断需要一次循环
    }
    else if ("OUTER_CIRCLE_TWO" == data)
    {
        *type = OUTER_CIRCLE_TWO;
        *loopNum = 8 + 1;
    }
    else if ("OUTER_CIRCLE_THREE" == data)
    {
        *type = OUTER_CIRCLE_THREE;
        *loopNum = 9 + 1;
    }
    else if ("END_FACE_ONE" == data)
    {
        *type = END_FACE_ONE;
        *loopNum = 7 + 1;
    }
    else if ("END_FACE_TWO" == data)
    {
        *type = END_FACE_TWO;
        *loopNum = 8 + 1;
    }
    else if ("END_FACE_THREE" == data)
    {
        *type = END_FACE_THREE;
        *loopNum = 7 + 1;
    }
    else if ("INNER_HOLE_ONE" == data)
    {
        *type = INNER_HOLE_ONE;
        *loopNum = 7 + 1;
    }
    else if ("INNER_HOLE_TWO" == data)
    {
        *type = INNER_HOLE_TWO;
        *loopNum = 8 + 1;
    }
    else if ("INNER_HOLE_THREE" == data)
    {
        *type = INNER_HOLE_THREE;
        *loopNum = 9 + 1;
    }
    else if ("INNER_HOLE_FOUR" == data)
    {
        *type = INNER_HOLE_FOUR;
        *loopNum = 9 + 1;
    }
    else if ("INNER_HOLE_FIVE" == data)
    {
        *type = INNER_HOLE_FIVE;
        *loopNum = 7 + 1;
    }
    else if ("CONE_FACE_ONE" == data)
    {
        *type = CONE_FACE_ONE;
        *loopNum = 8 + 1;
    }
    else if ("CONE_FACE_TWO" == data)
    {
        *type = CONE_FACE_TWO;
        *loopNum = 8 + 1;
    }
    else if ("CONE_FACE_THREE" == data)
    {
        *type = CONE_FACE_THREE;
        *loopNum = 8 + 1;
    }
    else if ("CONE_FACE_FOUR" == data)
    {
        *type = CONE_FACE_FOUR;
        *loopNum = 8 + 1;
    }
    else if ("SCREW_THREAD_ONE" == data)
    {
        *type = SCREW_THREAD_ONE;
        *loopNum = 14 + 1;
    }
    else if ("SCREW_THREAD_TWO" == data)
    {
        *type = SCREW_THREAD_TWO;
        *loopNum = 15 + 1;
    }
    else if ("SCREW_THREAD_THREE" == data)
    {
        *type = SCREW_THREAD_THREE;
        *loopNum = 14 + 1;
    }
    else if ("SCREW_THREAD_FOUR" == data)
    {
        *type = SCREW_THREAD_FOUR;
        *loopNum = 15 + 1;
    }
    else if ("CHAMFER_ONE" == data)
    {
        *type = CHAMFER_ONE;
        *loopNum = 9 + 1;
    }
    else if ("CHAMFER_TWO" == data)
    {
        *type = CHAMFER_TWO;
        *loopNum = 8 + 1;
    }
    else if ("CHAMFER_THREE" == data)
    {
        *type = CHAMFER_THREE;
        *loopNum = 9 + 1;
    }
    else if ("CHAMFER_FOUR" == data)
    {
        *type = CHAMFER_FOUR;
        *loopNum = 8 + 1;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_outerCircleMode1 *outerCircle1, int* findNodeNum)
{
    if(OUTER_CIRCLE_ONE == type)
    {
        if(7 == loopNum)
        {
            outerCircle1->xDir = std::stoi(data);
        }
        if(6 == loopNum)
        {
            outerCircle1->zDir = std::stoi(data);
        }
        if(5 == loopNum)
        {
            outerCircle1->L = std::stod(data);
        }
        if(4 == loopNum)
        {
            outerCircle1->Tr = std::stod(data);
        }
        if(3 == loopNum)
        {
            outerCircle1->Cn = std::stoi(data);
        }
        if(2 == loopNum)
        {
            outerCircle1->Cr = std::stod(data);
        }
        if(1 == loopNum)
        {
            outerCircle1->F = std::stod(data);
            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*outerCircle1);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *outerCircle1);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_outerCircleMode2 *outerCircle2, int* findNodeNum)
{
    if(OUTER_CIRCLE_TWO == type)
    {
        if (8 == loopNum)
        {
            outerCircle2->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            outerCircle2->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            outerCircle2->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            outerCircle2->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            outerCircle2->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            outerCircle2->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            outerCircle2->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            outerCircle2->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*outerCircle2);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *outerCircle2);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_outerCircleMode3 *outerCircle3, int* findNodeNum)
{
    if(OUTER_CIRCLE_THREE == type)
    {
        if (9 == loopNum)
        {
            outerCircle3->xDir = std::stoi(data);
        }
        if (8 == loopNum)
        {
            outerCircle3->zDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            outerCircle3->G2G3 = std::stoi(data);
        }
        if (6 == loopNum)
        {
            outerCircle3->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            outerCircle3->Tr = std::stoi(data);
        }
        if (4 == loopNum)
        {
            outerCircle3->Cn = std::stod(data);
        }
        if (3 == loopNum)
        {
            outerCircle3->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            outerCircle3->R = std::stod(data);
        }
        if (1 == loopNum)
        {
            outerCircle3->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*outerCircle3);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *outerCircle3);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}


void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_endFaceMode1 *endFace1, int* findNodeNum)
{
    if(END_FACE_ONE == type)
    {
        if (7 == loopNum)
        {
            endFace1->xDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            endFace1->zDir = std::stoi(data);
        }
        if (5 == loopNum)
        {
            endFace1->Lr = std::stod(data);
        }
        if (4 == loopNum)
        {
            endFace1->deltaT = std::stod(data);
        }
        if (3 == loopNum)
        {
            endFace1->Cn = std::stoi(data);
        }
        if (2 == loopNum)
        {
            endFace1->CT = std::stod(data);
        }
        if (1 == loopNum)
        {
            endFace1->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*endFace1);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *endFace1);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_endFaceMode2 *endFace2, int* findNodeNum)
{
    if(END_FACE_TWO == type)
    {
        if (8 == loopNum)
        {
            endFace2->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            endFace2->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            endFace2->Lr = std::stod(data);
        }
        if (5 == loopNum)
        {
            endFace2->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            endFace2->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            endFace2->W = std::stod(data);
        }
        if (2 == loopNum)
        {
            endFace2->Tw = std::stod(data);
        }
        if (1 == loopNum)
        {
            endFace2->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*endFace2);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *endFace2);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_endFaceMode3 *endFace3, int* findNodeNum)
{
    if(END_FACE_THREE == type)
    {
        if (7 == loopNum)
        {
            endFace3->xDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            endFace3->zDir = std::stoi(data);
        }
        if (5 == loopNum)
        {
            endFace3->Lr = std::stod(data);
        }
        if (4 == loopNum)
        {
            endFace3->deltaT = std::stod(data);
        }
        if (3 == loopNum)
        {
            endFace3->Cn = std::stoi(data);
        }
        if (2 == loopNum)
        {
            endFace3->CT = std::stod(data);
        }
        if (1 == loopNum)
        {
            endFace3->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*endFace3);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *endFace3);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_innerHoleMode1 *innerHole1, int* findNodeNum)
{
    if(INNER_HOLE_ONE == type)
    {
        if (7 == loopNum)
        {
            innerHole1->xDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            innerHole1->zDir = std::stoi(data);
        }
        if (5 == loopNum)
        {
            innerHole1->L = std::stod(data);
        }
        if (4 == loopNum)
        {
            innerHole1->Tr = std::stod(data);
        }
        if (3 == loopNum)
        {
            innerHole1->Cn = std::stoi(data);
        }
        if (2 == loopNum)
        {
            innerHole1->Cr = std::stod(data);
        }
        if (1 == loopNum)
        {
            innerHole1->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*innerHole1);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *innerHole1);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_innerHoleMode2 *innerHole2, int* findNodeNum)
{
    if(INNER_HOLE_TWO == type)
    {
        if (8 == loopNum)
        {
            innerHole2->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            innerHole2->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            innerHole2->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            innerHole2->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            innerHole2->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            innerHole2->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            innerHole2->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            innerHole2->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*innerHole2);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *innerHole2);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_innerHoleMode3 *innerHole3, int* findNodeNum)
{
    if(INNER_HOLE_THREE == type)
    {
        if (9 == loopNum)
        {
            innerHole3->xDir = std::stoi(data);
        }
        if (8 == loopNum)
        {
            innerHole3->zDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            innerHole3->Lr = std::stod(data);
        }
        if (6 == loopNum)
        {
            innerHole3->Tr = std::stod(data);
        }
        if (5 == loopNum)
        {
            innerHole3->Cn = std::stoi(data);
        }
        if (4 == loopNum)
        {
            innerHole3->W = std::stod(data);
        }
        if (3 == loopNum)
        {
            innerHole3->W1 = std::stod(data);
        }
        if (2 == loopNum)
        {
            innerHole3->Tw = std::stod(data);
        }
        if (1 == loopNum)
        {
            innerHole3->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*innerHole3);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *innerHole3);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_innerHoleMode4 *innerHole4, int* findNodeNum)
{
    if(INNER_HOLE_FOUR == type)
    {
        if (9 == loopNum)
        {
            innerHole4->xDir = std::stoi(data);
        }
        if (8 == loopNum)
        {
            innerHole4->zDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            innerHole4->G2G3 = std::stoi(data);
        }
        if (6 == loopNum)
        {
            innerHole4->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            innerHole4->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            innerHole4->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            innerHole4->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            innerHole4->R = std::stod(data);
        }
        if (1 == loopNum)
        {
            innerHole4->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*innerHole4);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *innerHole4);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_innerHoleMode5 *innerHole5, int* findNodeNum)
{
    if(INNER_HOLE_FIVE == type)
    {
        if (7 == loopNum)
        {
            innerHole5->xDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            innerHole5->zDir = std::stoi(data);
        }
        if (5 == loopNum)
        {
            innerHole5->L = std::stod(data);
        }
        if (4 == loopNum)
        {
            innerHole5->deltaT = std::stod(data);
        }
        if (3 == loopNum)
        {
            innerHole5->Cn = std::stoi(data);
        }
        if (2 == loopNum)
        {
            innerHole5->BT = std::stod(data);
        }
        if (1 == loopNum)
        {
            innerHole5->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*innerHole5);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *innerHole5);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_coneFaceMode1 *coneFace1, int* findNodeNum)
{
    if(CONE_FACE_ONE == type)
    {
        if (8 == loopNum)
        {
            coneFace1->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            coneFace1->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            coneFace1->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            coneFace1->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            coneFace1->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            coneFace1->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            coneFace1->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            coneFace1->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*coneFace1);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *coneFace1);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_coneFaceMode2 *coneFace2, int* findNodeNum)
{
    if(CONE_FACE_TWO == type)
    {
        if (8 == loopNum)
        {
            coneFace2->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            coneFace2->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            coneFace2->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            coneFace2->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            coneFace2->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            coneFace2->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            coneFace2->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            coneFace2->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*coneFace2);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *coneFace2);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_coneFaceMode3 *coneFace3, int* findNodeNum)
{
    if(CONE_FACE_THREE == type)
    {
        if (8 == loopNum)
        {
            coneFace3->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            coneFace3->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            coneFace3->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            coneFace3->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            coneFace3->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            coneFace3->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            coneFace3->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            coneFace3->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*coneFace3);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *coneFace3);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_coneFaceMode4 *coneFace4, int* findNodeNum)
{
    if(CONE_FACE_FOUR == type)
    {
        if (8 == loopNum)
        {
            coneFace4->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            coneFace4->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            coneFace4->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            coneFace4->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            coneFace4->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            coneFace4->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            coneFace4->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            coneFace4->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*coneFace4);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *coneFace4);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_screwThreadMode1 *screwThread1, int* findNodeNum)
{
    if(SCREW_THREAD_ONE == type)
    {
        if (14 == loopNum)
        {
            screwThread1->xDir = std::stoi(data);
        }
        if (13 == loopNum)
        {
            screwThread1->zDir = std::stoi(data);
        }
        if (12 == loopNum)
        {
            screwThread1->L = std::stod(data);
        }
        if (11 == loopNum)
        {
            screwThread1->Tr = std::stod(data);
        }
        if (10 == loopNum)
        {
            screwThread1->Cn = std::stoi(data);
        }
        if (9 == loopNum)
        {
            screwThread1->Cr = std::stod(data);
        }
        if (8 == loopNum)
        {
            screwThread1->Tp = std::stod(data);
        }
        if (7 == loopNum)
        {
            screwThread1->F = std::stod(data);
        }
        if (6 == loopNum)
        {
            screwThread1->unit = std::stoi(data);
        }
        if (5 == loopNum)
        {
            screwThread1->multi_head = std::stoi(data);
        }
        if (4 == loopNum)
        {
            screwThread1->startA = std::stod(data);
        }
        if (3 == loopNum)
        {
            screwThread1->tailFlick = std::stoi(data);
        }
        if (2 == loopNum)
        {
            screwThread1->filingProcessing = std::stoi(data);
        }
        if (1 == loopNum)
        {
            screwThread1->filingDistance = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*screwThread1);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *screwThread1);
                *findNodeNum = *findNodeNum + 1;
            }

        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_screwThreadMode2 *screwThread2, int* findNodeNum)
{
    if(SCREW_THREAD_TWO == type)
    {
        if (15 == loopNum)
        {
            screwThread2->xDir = std::stoi(data);
        }
        if (14 == loopNum)
        {
            screwThread2->zDir = std::stoi(data);
        }
        if (13 == loopNum)
        {
            screwThread2->L = std::stod(data);
        }
        if (12 == loopNum)
        {
            screwThread2->Tr = std::stod(data);
        }
        if (11 == loopNum)
        {
            screwThread2->Cn = std::stoi(data);
        }
        if (10 == loopNum)
        {
            screwThread2->Cr = std::stod(data);
        }
        if (9 == loopNum)
        {
            screwThread2->Tp = std::stod(data);
        }
        if (8 == loopNum)
        {
            screwThread2->A = std::stod(data);
        }
        if (7 == loopNum)
        {
            screwThread2->F = std::stod(data);
        }
        if (6 == loopNum)
        {
            screwThread2->unit = std::stoi(data);
        }
        if (5 == loopNum)
        {
            screwThread2->multi_head = std::stoi(data);
        }
        if (4 == loopNum)
        {
            screwThread2->startA = std::stod(data);
        }
        if (3 == loopNum)
        {
            screwThread2->tailFlick = std::stoi(data);
        }
        if (2 == loopNum)
        {
            screwThread2->filingProcessing = std::stoi(data);
        }
        if (1 == loopNum)
        {
            screwThread2->filingDistance = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*screwThread2);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *screwThread2);
                *findNodeNum = *findNodeNum + 1;
            }

        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_screwThreadMode3 *screwThread3, int* findNodeNum)
{
    if(SCREW_THREAD_THREE == type)
    {
        if (14 == loopNum)
        {
            screwThread3->xDir = std::stoi(data);
        }
        if (13 == loopNum)
        {
            screwThread3->zDir = std::stoi(data);
        }
        if (12 == loopNum)
        {
            screwThread3->L = std::stod(data);
        }
        if (11 == loopNum)
        {
            screwThread3->Tr = std::stod(data);
        }
        if (10 == loopNum)
        {
            screwThread3->Cn = std::stoi(data);
        }
        if (9 == loopNum)
        {
            screwThread3->Cr = std::stod(data);
        }
        if (8 == loopNum)
        {
            screwThread3->Tp = std::stod(data);
        }
        if (7 == loopNum)
        {
            screwThread3->F = std::stod(data);
        }
        if (6 == loopNum)
        {
            screwThread3->unit = std::stoi(data);
        }
        if (5 == loopNum)
        {
            screwThread3->multi_head = std::stoi(data);
        }
        if (4 == loopNum)
        {
            screwThread3->startA = std::stod(data);
        }
        if (3 == loopNum)
        {
            screwThread3->tailFlick = std::stoi(data);
        }
        if (2 == loopNum)
        {
            screwThread3->filingProcessing = std::stoi(data);
        }
        if (1 == loopNum)
        {
            screwThread3->filingDistance = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*screwThread3);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *screwThread3);
                *findNodeNum = *findNodeNum + 1;
            }

        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_screwThreadMode4 *screwThread4, int* findNodeNum)
{
    if(SCREW_THREAD_FOUR == type)
    {
        if (15 == loopNum)
        {
            screwThread4->xDir = std::stoi(data);
        }
        if (14 == loopNum)
        {
            screwThread4->zDir = std::stoi(data);
        }
        if (13 == loopNum)
        {
            screwThread4->L = std::stod(data);
        }
        if (12 == loopNum)
        {
            screwThread4->Tr = std::stod(data);
        }
        if (11 == loopNum)
        {
            screwThread4->Cn = std::stoi(data);
        }
        if (10 == loopNum)
        {
            screwThread4->Cr = std::stod(data);
        }
        if (9 == loopNum)
        {
            screwThread4->Tp = std::stod(data);
        }
        if (8 == loopNum)
        {
            screwThread4->A = std::stod(data);
        }
        if (7 == loopNum)
        {
            screwThread4->F = std::stod(data);
        }
        if (6 == loopNum)
        {
            screwThread4->unit = std::stoi(data);
        }
        if (5 == loopNum)
        {
            screwThread4->multi_head = std::stoi(data);
        }
        if (4 == loopNum)
        {
            screwThread4->startA = std::stod(data);
        }
        if (3 == loopNum)
        {
            screwThread4->tailFlick = std::stoi(data);
        }
        if (2 == loopNum)
        {
            screwThread4->filingProcessing = std::stoi(data);
        }
        if (1 == loopNum)
        {
            screwThread4->filingDistance = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*screwThread4);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *screwThread4);
                *findNodeNum = *findNodeNum + 1;
            }

        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_chamferMode1 *chamfer1, int* findNodeNum)
{
    if(CHAMFER_ONE == type)
    {
        if (9 == loopNum)
        {
            chamfer1->xDir = std::stoi(data);
        }
        if (8 == loopNum)
        {
            chamfer1->zDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            chamfer1->G2G3 = std::stoi(data);
        }
        if (6 == loopNum)
        {
            chamfer1->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            chamfer1->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            chamfer1->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            chamfer1->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            chamfer1->R = std::stod(data);
        }
        if (1 == loopNum)
        {
            chamfer1->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*chamfer1);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *chamfer1);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_chamferMode2 *chamfer2, int* findNodeNum)
{
    if(CHAMFER_TWO == type)
    {
        if (8 == loopNum)
        {
            chamfer2->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            chamfer2->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            chamfer2->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            chamfer2->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            chamfer2->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            chamfer2->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            chamfer2->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            chamfer2->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*chamfer2);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *chamfer2);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_chamferMode3 *chamfer3, int* findNodeNum)
{
    if(CHAMFER_THREE == type)
    {
        if (9 == loopNum)
        {
            chamfer3->xDir = std::stoi(data);
        }
        if (8 == loopNum)
        {
            chamfer3->zDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            chamfer3->G2G3 = std::stoi(data);
        }
        if (6 == loopNum)
        {
            chamfer3->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            chamfer3->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            chamfer3->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            chamfer3->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            chamfer3->R = std::stod(data);
        }
        if (1 == loopNum)
        {
            chamfer3->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*chamfer3);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *chamfer3);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

void MachineProcess::TextRecoverNode(int loopNum, int type, string data, s_chamferMode4 *chamfer4, int* findNodeNum)
{
    if(CHAMFER_FOUR == type)
    {
        if (8 == loopNum)
        {
            chamfer4->xDir = std::stoi(data);
        }
        if (7 == loopNum)
        {
            chamfer4->zDir = std::stoi(data);
        }
        if (6 == loopNum)
        {
            chamfer4->L = std::stod(data);
        }
        if (5 == loopNum)
        {
            chamfer4->Tr = std::stod(data);
        }
        if (4 == loopNum)
        {
            chamfer4->Cn = std::stoi(data);
        }
        if (3 == loopNum)
        {
            chamfer4->Cr = std::stod(data);
        }
        if (2 == loopNum)
        {
            chamfer4->A = std::stod(data);
        }
        if (1 == loopNum)
        {
            chamfer4->F = std::stod(data);

            if(nullptr == findNode(*findNodeNum))
            {
                addNode(*chamfer4);
                *findNodeNum = *findNodeNum + 1;
            }
            else
            {
                changeNode(*findNodeNum, *chamfer4);
                *findNodeNum = *findNodeNum + 1;
            }
        }
        dealInterfaceData->firstInsystem = false;
    }
}

inline void MachineProcess::StartCordTranslate(coordinate &start_cord) {
    start_cord.x += rightDownPos.x;
    start_cord.y += rightDownPos.y;
}

// 矩形工艺
inline bool MachineProcess::transverseMachining(coordinate startCord, int len, int h)
{

    StartCordTranslate(startCord);
    int length = floor(len * m_barScale);//**********************
    int height = floor(h * m_barScale);

    return m_b->transverseMachining(startCord, length, height);
}

bool MachineProcess::obliqueMachiningLeftDown(coordinate startCord, int len, float slope)
{

    StartCordTranslate(startCord);
    int length = floor(len * m_barScale);
    slope = tan(slope);
    return m_b->obliqueMachiningLeftDown(startCord, length, slope);// 确定方向
}
bool MachineProcess::obliqueMachiningRightDown(coordinate startCord, int len, float slope)
{
    StartCordTranslate(startCord);
    int length = floor(len * m_barScale);
    float i = tan(slope * PI / 180.0f);
    int h = floor( i * m_barScale);
    return m_b->obliqueMachiningRightDown(startCord, length, i);// 确定方向
}
// 横向螺纹
inline bool MachineProcess::tThreadMachining(coordinate startCord, int pitch, int depth, int len)
{
    StartCordTranslate(startCord);
    int length = floor(len * m_barScale);
    int d = floor(depth * m_barScale);
    pitch = 2;// TODO:上层工艺没有调用
    return m_b->tThreadMachining(startCord, pitch, d, length);
}
// 斜向螺纹
inline bool MachineProcess::oThreadMachining(coordinate startCord, int pitch, int depth, int len, float slope)
{
    StartCordTranslate(startCord);
    int p = floor(pitch * m_barScale);
    int d = floor(depth * m_barScale);
    int l = floor(len * m_barScale);
    float i = len/tan(slope * PI / 180.0f);
    int h = floor( i * m_barScale);

    return m_b->oThreadMachining(startCord, p, d, l, h);
}
// 圆弧加工
inline bool MachineProcess::arcMachining(coordinate p1, coordinate p2, double radius, bool arcCodition)
{
    StartCordTranslate(p1);
    StartCordTranslate(p2);
    int r = floor(radius * m_barScale);
    return m_b->arcMachining( p1, p2, r, arcCodition);
}
//

void MachineProcess::outerCircle1_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    const int Cn = p->outerCircle1.Cn, xDir = p->outerCircle1.xDir, zDir = p->outerCircle1.zDir;
    const double L = p->outerCircle1.L, Tr = p->outerCircle1.Tr, Cr = p->outerCircle1.Cr, F = p->outerCircle1.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (0 == a)
        {
            if (true == *textHeadFlag)
            {
                *GCode<<"O200;"<<endl;
                *textHeadFlag = 0;
            }
            *GCode<< "G01 U" << Tr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << L * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L * zDir * -1 << " F" << F << ";" <<endl;
            if (nullptr == next && 1 == Cn)
            {
                *GCode<<"M30;"<<endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << L * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L * zDir * -1 << " F" << F << ";" <<endl;
        }
        else
        {
            *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << L * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Cr * xDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L * zDir * -1 << " F" << F << ";" <<endl;
            if (nullptr == next)
            {
                *GCode<<"M30;"<<endl;
            }
        }
    }
}

void MachineProcess::outerCircle2_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->outerCircle2.Cn, xDir = p->outerCircle2.xDir, zDir = p->outerCircle2.zDir;
    const double Tr = p->outerCircle2.Tr, F = p->outerCircle2.F;
    const double tanA = tan(p->outerCircle2.A/180*PI);
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode<<"O200;"<<endl;
            *textHeadFlag = 0;
        }
        *GCode<< "G01 U" << Tr * Num * xDir << " F" << F << ";" <<endl;
        *GCode<< "G01 U" << Tr * Num * xDir * -1 << " W" << Tr * Num / tanA * zDir << " F" << F << ";" <<endl;
        *GCode<<"G00 W"<<Tr * Num / tanA * zDir * -1<<" F"<<F<<";"<<endl;
        if (nullptr == next && a == Cn - 1)
        {
            *GCode<<"M30;"<<endl;
        }
        Num = Num + 1;
    }
}


void MachineProcess::outerCircle3_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->outerCircle3.Cn, xDir = p->outerCircle3.xDir, zDir = p->outerCircle3.zDir;
    const double L = p->outerCircle3.L, Tr = p->outerCircle3.Tr, Cr = p->outerCircle3.Cr, R = p->outerCircle3.R, F = p->outerCircle3.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (0 == a)
        {
            if (true == *textHeadFlag)
            {
                *GCode<< "O200;" <<endl;
                *textHeadFlag = 0;
            }
            if ((1 == xDir && -1 == zDir) || (-1 == xDir && 1 == zDir))
            {
                *GCode<< "G01 W" << L / Cn * zDir << " F" << F << ";"<<endl;
                *GCode<< "G02 U" << Tr * xDir<< " W" << L / Cn * zDir * -1 << " R" << R - (Cr - Tr) << " F" << F << ";" <<endl;
                *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
            }
            else
            {
                *GCode<< "G01 W" << L / Cn * zDir << " F" << F << ";"<<endl;
                *GCode<< "G03 U" << Tr * xDir<< " W" << L / Cn * zDir * -1 << " R" << R - (Cr - Tr) << " F" << F << ";" <<endl;
                *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
            }
            if (nullptr == next && 1 == Cn)
            {
                *GCode<<"M30;"<<endl;
            }
            Num = Num + 1;
        }
        else if (a < (Cn - 1))
        {
            if ((1 == xDir && -1 == zDir) || (-1 == xDir && 1 == zDir))
            {
                *GCode<< "G01 W" << L / Cn * 2 * zDir << " F" << F << ";" <<endl;
                *GCode<< "G02 U" << Tr * Num * xDir << " W" << L / Cn * Num * zDir * -1 << " R" << R - (Cr - Tr * Num) << " F" << F<< ";" <<endl;
                *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
                *GCode<< "G03 U" << Tr * (Num - 1) * xDir * -1 << " W" << L / Cn * (Num - 1) * zDir
                         << " R" << R - (Cr - Tr * (Num - 1)) << " F" << F << ";" <<endl;
            }
            else
            {
                *GCode<< "G01 W" << L / Cn * 2 * zDir << " F" << F << ";" <<endl;
                *GCode<< "G03 U" << Tr * Num * xDir << " W" << L / Cn * Num * zDir * -1 << " R" << R - (Cr - Tr * Num) << " F" << F<< ";" <<endl;
                *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
                *GCode<< "G02 U" << Tr * (Num - 1) * xDir * -1 << " W" << L / Cn * (Num - 1) * zDir
                         << " R" << R - (Cr - Tr * (Num - 1)) << " F" << F << ";" <<endl;
            }
            Num = Num + 1;
        }
        else
        {
            if ((1 == xDir && -1 == zDir) || (-1 == xDir && 1 == zDir))
            {
                *GCode<< "G01 W" << L / Cn * 2 * zDir << " F" << F << ";" <<endl;
                *GCode<< "G02 U" << Tr * Num * xDir << " W" << L / Cn * Num * zDir * -1
                         << " R" << R - (Cr - Tr * Num) << " F" << F << ";" <<endl;
                *GCode<< "G00 U" << Cr * xDir * -1 << " F" << F << ";" <<endl;
            }
            else
            {
                *GCode<< "G01 W" << L / Cn * 2 * zDir << " F" << F << ";" <<endl;
                *GCode<< "G03 U" << Tr * Num * xDir << " W" << L / Cn * Num * zDir * -1
                         << " R" << R - (Cr - Tr * Num) << " F" << F << ";" <<endl;
                *GCode<< "G00 U" << Cr * xDir * -1 << " F" << F << ";" <<endl;
            }
            if (nullptr == next)
            {
                *GCode<<"M30;"<<endl;
            }
        }
    }
}

void MachineProcess::endFace1_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    const int Cn = p->endFace1.Cn, xDir = p->endFace1.xDir, zDir = p->endFace1.zDir;
    const double Lr = p->endFace1.Lr, deltaT = p->endFace1.deltaT, CT = p->endFace1.CT, F = p->endFace1.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (0 == a)
        {
            if (true == *textHeadFlag)
            {
                *GCode << "O200;" <<endl;
                *textHeadFlag = 0;
            }
            *GCode<< "G01 W" << deltaT * zDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Lr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << deltaT * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F << ";" <<endl;
            if (nullptr == next && 1 == Cn)
            {
                *GCode<<"M30;"<<endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode<< "G01 W" << deltaT * 2 * zDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Lr * xDir <<" F" << F << ";" <<endl;
            *GCode<< "G00 W" << deltaT * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F << ";" <<endl;
        }
        else
        {
            *GCode<< "G01 W" << deltaT * 2 * zDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Lr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << CT * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F << ";" <<endl;
            if (nullptr == next)
            {
                *GCode<<"M30;"<<endl;
            }
        }
    }
}

void MachineProcess::endFace2_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int w, a;
    int Wn = p->endFace2.W / p->endFace2.Tw;
    const double remainW = fmod(p->endFace2.W, p->endFace2.Tw);
    const int Cn = p->endFace2.Cn, xDir = p->endFace2.xDir, zDir = p->endFace2.zDir;
    const double Lr = p->endFace2.Lr, Tr = p->endFace2.Tr, W = p->endFace2.W, Tw = p->endFace2.Tw, F = p->endFace2.F;
    const machineNode *next = p->next;

    if (remainW != 0)
    {
        Wn = Wn + 1;
    }

    if (W < Tw)
    {
        qDebug()<<"warning: The opening width is less than the tool width"<<endl;
    }
    else
    {
        for (w = 0; w < Wn; w++)
        {
            for (a = 0; a < Cn; a++)
            {
                if (0 == a)
                {
                    if (true == *textHeadFlag)
                    {
                        *GCode<< "O200;" <<endl;
                        *textHeadFlag = 0;
                    }
                    *GCode<< "G01 U" << Tr * xDir << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
                    if (nullptr == next && 1 == Cn && w == Wn - 1)
                    {
                        *GCode<< "M30;" <<endl;
                    }
                }
                else if (a < (Cn - 1))
                {
                    *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F << ";" <<endl;
                }
            }
            if (w < Wn - 2)
            {
                *GCode<< "G00 W" << Tw * zDir << " F" << F << ";" <<endl;
            }
            else if (w < Wn - 1)
            {
                if (remainW != 0)
                {
                    *GCode<< "G00 W" << remainW * zDir << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G00 W" << Tw * zDir << " F" << F << ";" <<endl;
                }
            }
            else
            {
                *GCode<< "G00 W" << (W - Tw) * zDir * -1 << " F" << F << ";" <<endl;
                if (nullptr == next)
                {
                    *GCode<< "M30;" <<endl;
                }
            }
        }
    }
}

void MachineProcess::endFace3_GCode_auto(machineNode *p, ofstream *GCode, bool* textHeadFlag) {
    const int Cn = p->endFace3.Cn, xDir = p->endFace3.xDir, zDir = p->endFace3.zDir;
    const double Lr = p->endFace3.Lr, deltaT = p->endFace3.deltaT, CT = p->endFace3.CT, F = p->endFace3.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++) {
        if (0 == a) {
            if (true == *textHeadFlag) {
                *GCode << "O200;" <<endl;
                *textHeadFlag = 0;
            }
            *GCode<< "G01 W" << deltaT * zDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Lr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << deltaT * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F << ";" <<endl;
            if (nullptr == next && 1 == Cn) {
                *GCode << "M30;" <<endl;
            }
        } else if (a < (Cn - 1)) {
            *GCode<< "G01 W" << deltaT * 2 * zDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Lr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << deltaT * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F << ";" <<endl;
        } else {
            *GCode<< "G01 W" << deltaT * 2 * zDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Lr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << CT * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F << ";" <<endl;
            if (nullptr == next) {
                *GCode << "M30;" <<endl;
            }
        }
    }
}


void MachineProcess::innerHole1_GCode_auto(machineNode *p, ofstream *GCode, bool* textHeadFlag)
{
    const int Cn = p->innerHole1.Cn, xDir = p->innerHole1.xDir, zDir = p->innerHole1.zDir;
    const double L = p->innerHole1.L, Tr = p->innerHole1.Tr, Cr = p->innerHole1.Cr, F = p->innerHole1.F;
    const machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (*textHeadFlag == true)
            {
                *GCode<< "O200;" <<endl;
                *textHeadFlag = false;
            }
            *GCode<< "G01 U" << Tr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << L * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L * zDir * -1 << " F" << F << ";" <<endl;
            if (next == nullptr && Cn == 1)
            {
                *GCode << "M30;" << endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << L * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L * zDir * -1 << " F" << F << ";" <<endl;
        }
        else
        {
            *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 W" << L * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Cr * xDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L * zDir * -1 << " F" << F << ";" <<endl;
            if (next == nullptr)
            {
                *GCode<< "M30;" <<endl;
            }
        }
    }
}

void MachineProcess::innerHole2_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->innerHole2.Cn, xDir = p->innerHole2.xDir, zDir = p->innerHole2.zDir;
    const double L = p->innerHole2.L, Tr = p->innerHole2.Tr, F = p->innerHole2.F;
    const machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (*textHeadFlag)
            {
                *GCode<< "O200;" <<endl;
                *textHeadFlag = false;
            }

            *GCode<< "G01 U" << Tr * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Tr * Num * xDir * -1 << " W" << L / Cn * Num * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L / Cn * zDir * -1 << " F" << F << ";" <<endl;

            if (next == nullptr && Cn == 1)
            {
                *GCode<< "M30;" <<endl;
            }

            Num++;
        }
        else if (a < Cn - 1)
        {
            *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Tr * Num * xDir * -1 << " W" << L / Cn * Num * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L / Cn * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Tr * (Num - 1) * xDir << " W" << L / Cn * (Num - 1) * zDir * -1 << " F" << F << ";" <<endl;

            Num++;
        }
        else
        {
            *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Tr * Num * xDir * -1 << " W" << L / Cn * Num * zDir << " F" << F << ";" <<endl;
            *GCode<< "G00 W" << L * zDir * -1 << " F" << F << ";" <<endl;

            if (next == nullptr)
            {
                *GCode<< "M30;" <<endl;
            }
        }
    }
}
void MachineProcess::innerHole3_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    double remainW = fmod(p->innerHole3.W, p->innerHole3.Tw);
    int Wn = p->innerHole3.W / p->innerHole3.Tw;
    int w;
    int a;
    if (remainW != 0)
    {
        Wn = Wn + 1;
    }

    if (p->innerHole3.W < p->innerHole3.Tw)
    {
        qDebug()<<"warning: The opening width is less than the tool width"<<endl;
    }
    else
    {
        const int Cn = p->innerHole3.Cn, xDir = p->innerHole3.xDir, zDir = p->innerHole3.zDir;
        const double Lr = p->innerHole3.Lr, Tr = p->innerHole3.Tr, W = p->innerHole3.W, W1 = p->innerHole3.W1, Tw = p->innerHole3.Tw, F = p->innerHole3.F;
        const machineNode* next = p->next;

        for (w = 0; w < Wn; w++)
        {

            if (0 == w)
            {
                if (true == *textHeadFlag)
                {
                    *GCode<< "O200;" <<endl;
                    *textHeadFlag = 0;
                }
                    *GCode<< "G00 U" << 3 * xDir * -1 << " F" << F << ";" <<endl;
                    *GCode<< "G00 W" << (W1 + Tw) * zDir << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << 3 * xDir << " F" << F << ";" <<endl;
            }
            for (a = 0; a < Cn; a++)
            {
                if (0 == a)
                {
                    *GCode<< "G01 U" << Tr * xDir << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" << endl;
                    if (nullptr == next && 1 == Cn && w == Wn - 1)
                    {
                        *GCode<< "M30;" <<endl;
                    }
                }
                else if (a < (Cn - 1))
                {
                    *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
                    *GCode<< "G00 U" << Tr * xDir * -1 << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F<<";"<<endl;
                    *GCode<< "G00 U" << Lr * xDir * -1 << " F" << F<<";"<<endl;
                }
            }
            if (w < Wn - 2)
            {
                *GCode<< "G00 W" << Tw * zDir << " F" << F << ";" <<endl;
            }
            else if (w < Wn - 1)
            {
                if (remainW != 0)
                {
                    *GCode<< "G00 W" << remainW * zDir << " F" << F << ";" <<endl;
                }
                else
                {
                    *GCode<< "G00 W" << Tw * zDir << " F" << F << ";" <<endl;
                }
            }
            else
            {
                *GCode<< "G00 U" << 3 * xDir * -1 << " F" << F << ";" <<endl;
                *GCode<< "G00 W" << (W1 + W) * zDir * -1 << " F" << F << ";" <<endl;
                *GCode<< "G00 U" << 3 * xDir << " F" << F << ";" <<endl;
                if(nullptr == next)
                {
                    *GCode<<"M30;"<<endl;
                }
            }
        }
    }
}

void MachineProcess::innerHole4_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->innerHole4.Cn, xDir = p->innerHole4.xDir, zDir = p->innerHole4.zDir;
    double L = p->innerHole4.L, Tr = p->innerHole4.Tr, Cr = p->innerHole4.Cr, R = p->innerHole4.R,F = p->innerHole4.F;
    const machineNode* next = p->next;
    double Center[2]; // 0.X 01.Z
    /*===========================================平面求圆弧圆心=============================================== */
    double mid[2];// 0.Z  1.X
    double theta;
    double abs_radius;
    double half_length;
    double offset;
    double Turn2;

    abs_radius=abs(R);
    mid[1] = (0 + (Cr * xDir))/2;
    mid[0] = ((L * zDir) + 0)/2;

    half_length = sqrt((mid[1] - 0) * (mid[1] - 0) + (mid[0] - (L * zDir))*(mid[0] - (L * zDir)));
//    if (-1 == zDir)
        theta = atan2(((L * zDir) -0), (0 - (Cr * xDir))) - PI0_5;
//    else
//        theta = atan2((0 - (L * zDir)), ((Cr * xDir) - 0)) + PI0_5;

    if(half_length>abs_radius)
    {
        half_length=abs_radius;
    }
    Turn2 = asin (half_length/abs_radius);
    offset = abs_radius * cos(Turn2);
    Center[0] = mid[0] + (offset * cos(theta));
    Center[1] = mid[1] + (offset * sin(theta));
    if(1 == zDir)
    {
        Center[0] = (mid[0] + (offset * cos(theta))) * -1;
    }
    qDebug()<<Center[0]<<","<<Center[1]<<endl;
    /*===========================================平面求圆弧圆心=============================================== */
    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        if (-1 == zDir)
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
        }
        else
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }

        }

    }
    if(nullptr == next)
    {
        *GCode<<"M30;"<<endl;
    }
}



void MachineProcess::innerHole5_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->innerHole5.Cn;
    double deltaT = p->innerHole5.deltaT;
    int zDir = p->innerHole5.zDir;
    double F = p->innerHole5.F;
    double BT = p->innerHole5.BT;
    double L = p->innerHole5.L;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (*textHeadFlag == true)
            {
                *GCode << "O200;" << endl;
                *textHeadFlag = false;
            }
            *GCode << "G01 W" << deltaT * zDir << " F" << F << ";" << endl;
            if (Cn == 1)
            {
                *GCode << "G00 W" << deltaT * zDir * -1 << " F" << F << ";" << endl;
            }
            else
            {
                *GCode << "G00 W" << BT * zDir * -1 << " F" << F << ";" << endl;
            }
            if (p->next == nullptr && Cn == 1)
            {
                *GCode << "M30;" << endl;
            }
        }
        else if (a < (Cn - 1))
        {
            *GCode << "G01 W" << (deltaT + BT) * zDir << " F" << F << ";" << endl;
            *GCode << "G00 W" << BT * zDir * -1 << " F" << F << ";" << endl;
        }
        else
        {
            *GCode << "G01 W" << (deltaT + BT) * zDir << " F" << F << ";" << endl;
            *GCode << "G00 W" << L * zDir * -1 << " F" << F << ";" << endl;
            if (p->next == nullptr)
            {
                *GCode << "M30;" << endl;
            }
        }
    }
}

void MachineProcess::coneFace1_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->coneFace1.Cn;
    double Tr = p->coneFace1.Tr;
    int xDir = p->coneFace1.xDir;
    double A = p->coneFace1.A;
    int zDir = p->coneFace1.zDir;
    double F = p->coneFace1.F;

    int Num = 1;
    for (int a = 0; a < Cn; a++)
    {
        if (*textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = false;
        }
        *GCode << "G01 U" << Tr * Num * xDir << " F" << F << ";" << endl;
        *GCode << "G01 U" << Tr * Num * xDir * -1
               << " W" << Tr * Num / tan(A / 180 * PI) * zDir
               << " F" << F << ";" << endl;
        *GCode << "G00 W" << Tr * Num / tan(A / 180 * PI) * zDir * -1
               << " F" << F << ";" << endl;
        if (nullptr == p->next && 1 == Cn)
        {
            *GCode << "M30;" << endl;
        }
        Num = Num + 1;
    }
}

void MachineProcess::coneFace2_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int xDir = p->coneFace2.xDir, zDir = p->coneFace2.zDir, Cn = p->coneFace2.Cn ;
    double L = p->coneFace2.L, Tr = p->coneFace2.Tr, Cr = p->coneFace2.Cr, A = p->coneFace2.A, F = p->coneFace2.F, remain = 0.005;
    machineNode* next = p->next;
    for (int a = 0; a < p->coneFace2.Cn; a++)
    {
        if (0 == a)
        {
            if(true == *textHeadFlag)
            {
                *GCode<<"O200;"<<endl;
                *textHeadFlag = 0;
            }
            *GCode<<"G01 W"<<remain * zDir<<" F"<<F<<";"<<endl;
            *GCode<<"G01 U"<<Tr * xDir<<" W"<<Tr / tan(A / 180 * PI) * zDir<<" F"<<F<<";"<<endl;
            *GCode<<"G01 W"<<(L - (Tr / tan(A / 180 * PI)) - (remain * 2)) * zDir<<" F"<<F<<";"<<endl;
            *GCode<<"G01 U"<<Tr * xDir * -1<<" F"<<F<<";"<<endl;
            *GCode<<"G00 W"<<(L - (remain * 2) - (Tr / tan(A / 180 * PI))) * zDir * -1<<";"<<endl;
            *GCode<<"G01 U"<<Tr * xDir<<" F"<<F<<";"<<endl;
            if(nullptr == next && 1 == Cn)
            {
                *GCode<<"M30;"<<endl;
            }
        }
        else
        {
            if((L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) < 0)
            {
                break;
            }
            if((L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 2))) > 0)
            {
                *GCode<<"G01 U"<<Tr * xDir<<" W"<<Tr / tan(A / 180 * PI) * zDir<<" F"<<F<<";"<<endl;
                *GCode<<"G01 W"<<(L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) * zDir<<" F"<<F<<";"<<endl;
                *GCode<<"G01 U"<<Tr * xDir * -1<<" F"<<F<<";"<<endl;
                *GCode<<"G00 W"<<(L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) * zDir * -1<<";"<<endl;
                *GCode<<"G01 U"<<Tr * xDir<<" F"<<F<<";"<<endl;
            }
            else if((L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) > 0)
            {
                *GCode<<"G01 U"<<Tr * xDir<<" W"<<Tr / tan(A / 180 * PI) * zDir<<" F"<<F<<";"<<endl;
                *GCode<<"G01 W"<<(L - (remain * 2) - ((Tr / tan(A / 180 * PI)) * (a + 1))) * zDir<<" F"<<F<<";"<<endl;
                *GCode<<"G01 U"<<Tr * (a + 1) * xDir * -1<<" F"<<F<<";"<<endl;
                *GCode<<"G00 W"<<(L - remain) * zDir * -1<<";"<<endl;
            }
        }
    }
    *GCode<<"G01 U"<<Cr * xDir<<" W"<<L * zDir<<" F"<<F<<";"<<endl;
    *GCode<<"G01 U"<<Cr * xDir * -1<<" F"<<F<<";"<<endl;
    *GCode<<"G00 W"<<L * zDir * -1<<";"<<endl;
    if(nullptr == next)
    {
        *GCode<<"M30;"<<endl;
    }
}


void MachineProcess::coneFace3_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    int Cn = p->coneFace3.Cn, xDir = p->coneFace3.xDir, zDir = p->coneFace3.zDir;
    double Tr = p->coneFace3.Tr, Cr = p->coneFace3.Cr, L = p->coneFace3.L, F = p->coneFace3.F;
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (a == 0)
        {
            if (1 == *textHeadFlag)
            {
                *GCode << "O200\n";
                *textHeadFlag = 0;
            }
            *GCode << "G01 U" << Tr * xDir << " F" << F <<endl;
            *GCode << "G01 U" << Cr * xDir * -1 << " W" << L * zDir << " F" << F <<endl;
            *GCode << "G00 U" << Tr * xDir * -1 << " F" << F <<endl;
            *GCode << "G00 U" << Cr * xDir << " W" << L * zDir * -1 << " F" << F <<endl;
            if (nullptr == next && 1 == Cn)
            {
                *GCode << "M30\n";
            }
            Num++;
        }
        else if (a < (Cn - 1))
        {
            *GCode << "G01 U" << Tr * 2 * xDir << " F" << F <<endl;
            *GCode << "G01 U" << Cr * xDir * -1 << " W" << L * zDir << " F" << F <<endl;
            *GCode << "G00 U" << Tr * xDir * -1 << " F" << F <<endl;
            *GCode << "G00 U" << Cr * xDir << " W" << L * zDir * -1 << " F" << F <<endl;
            Num++;
        }
        else
        {
            *GCode<< "G01 U" << Tr * 2 * xDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Cr * xDir * -1 << " W" << L * zDir << " F" << F << ";" <<endl;
            *GCode<< "G01 U" << Tr * xDir * - 1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Cr * xDir << " W" << L * zDir * -1 << " F" << F << ";" <<endl;
            *GCode<< "G00 U" << Tr * (Num - 1) * xDir * - 1 << " F" << F << ";" <<endl;
            if (nullptr == next)
            {
                *GCode<< "M30;" <<endl;
            }
        }
    }
}

void MachineProcess::coneFace4_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag) {
    int Num;
    int Cn = p->coneFace4.Cn, xDir = p->coneFace4.xDir, zDir = p->coneFace4.zDir;
    double Tr = p->coneFace4.Tr, Cr = p->coneFace4.Cr, L = p->coneFace4.L, F = p->coneFace4.F;
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++) {
        if (0 == a) {
            if (true == *textHeadFlag) {
                *GCode << "O200;" << endl;
                *textHeadFlag = 0;
            }
            *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
            *GCode << "G01 U" << Cr * xDir << " W" << L * zDir << " F" << F << ";" << endl;
            *GCode << "G00 U" << Tr * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 U" << Cr * xDir * -1 << " W" << L * zDir * -1 << " F" << F << ";" << endl;
            if (nullptr == next && 1 == Cn) {
                *GCode << "M30;" << endl;
            }
            Num = Num + 1;
        }
        else if (a < (Cn - 1)) {
            *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
            *GCode << "G01 U" << Cr * xDir << " W" << L * zDir << " F" << F << ";" << endl;
            *GCode << "G00 U" << Tr * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 U" << Cr * xDir * -1 << " W" << L * zDir * -1 << " F" << F << ";" << endl;
            Num = Num + 1;
        }
        else {
            *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
            *GCode << "G01 U" << Cr * xDir << " W" << L * zDir << " F" << F << ";" << endl;
            *GCode << "G01 U" << Tr * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 U" << Cr * xDir * -1 << " W" << L * zDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 U" << Tr * (Cn - 1) * xDir * -1 << " F" << F << ";" << endl;
            if (nullptr == next) {
                *GCode << "M30;" << endl;
            }
        }
    }
}


void MachineProcess::screwThread1_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag) {
    int num = 2;
    const int Cn = p->screwThread1.Cn, xDir = p->screwThread1.xDir, zDir = p->screwThread1.zDir;
    const double L = p->screwThread1.L, Tr = p->screwThread1.Tr, Tp = p->screwThread1.Tp, F = p->screwThread1.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++) {
        if (0 == a) {
            if (true == *textHeadFlag) {
                *GCode << "O200;" << endl;
                *textHeadFlag = 0;
            }
            *GCode << "M3 S300 G01 U" << Tr * xDir << " F" << F << ";" << endl;
            *GCode << "G32 W" << L * zDir << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << Tr * 2 * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 W" << L * zDir * -1 << " F" << F << ";" << endl;
            *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
            if (nullptr == next && 1 == Cn) {
                *GCode << "M30;" << endl;
            }
        } else if (a < (Cn - 1)) {
            *GCode << "G01 U" << Tr * num * xDir << " F" << F << ";" << endl;
            *GCode << "G32 W" << L * zDir << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << Tr * (num + 1) * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 W" << L * zDir * -1 << " F" << F << ";" << endl;
            *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
            num = num + 1;
        } else {
            *GCode << "G01 U" << Tr * num * xDir << " F" << F << ";" << endl;
            *GCode << "G32 W" << L * zDir << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << Tr * num * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 W" << L * zDir * -1 << " F" << F << ";" << endl;
            *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
            if (nullptr == next) {
                *GCode << "M30;" << endl;
            }
        }
    }
}

void MachineProcess::screwThread2_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->screwThread2.Cn, xDir = p->screwThread2.xDir, zDir = p->screwThread2.zDir;
    const double Tr = p->screwThread2.Tr, Tp = p->screwThread2.Tp, F = p->screwThread2.F;
    const double tanA = tan(p->screwThread2.A/180 * PI);
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        *GCode << "M3 S100 G01 U" << Tr * Num * xDir << " F" << F << ";" << endl;
        *GCode << "G32 U" << Tr * Num * xDir * -1 << " W" << Tr * Num / tanA * zDir << " F" << Tp << ";" << endl;
        *GCode << "G00 W" << Tr * Num / tanA * zDir * -1 << " F" << F << ";" << endl;
        if (nullptr == next && 1 == Cn)
        {
            *GCode << "M30;" << endl;
        }
        Num = Num + 1;
    }
}

void MachineProcess::screwThread3_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int num = 2;
    const int Cn = p->screwThread3.Cn, xDir = p->screwThread3.xDir, zDir = p->screwThread3.zDir;
    const double L = p->screwThread3.L, Tr = p->screwThread3.Tr, Tp = p->screwThread3.Tp, F = p->screwThread3.F;
    const machineNode *next = p->next;

    for (int a = 0; a < Cn; a++) {
        if (0 == a) {
            if (true == *textHeadFlag) {
                *GCode << "O200;" << endl;
                *textHeadFlag = 0;
            }
            *GCode << "M3 S300 G01 U" << Tr * xDir << " F" << F << ";" << endl;
            *GCode << "G32 W" << L * zDir << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << Tr * 2 * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 W" << L * zDir * -1 << " F" << F << ";" << endl;
            *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
            if (nullptr == next && 1 == Cn) {
                *GCode << "M30;" << endl;
            }
        } else if (a < (Cn - 1)) {
            *GCode << "G01 U" << Tr * num * xDir << " F" << F << ";" << endl;
            *GCode << "G32 W" << L * zDir << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << Tr * (num + 1) * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 W" << L * zDir * -1 << " F" << F << ";" << endl;
            *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
            num = num + 1;
        } else {
            *GCode << "G01 U" << Tr * num * xDir << " F" << F << ";" << endl;
            *GCode << "G32 W" << L * zDir << " F" << Tp << ";" << endl;
            *GCode << "G00 U" << Tr * num * xDir * -1 << " F" << F << ";" << endl;
            *GCode << "G00 W" << L * zDir * -1 << " F" << F << ";" << endl;
            *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
            if (nullptr == next) {
                *GCode << "M30;" << endl;
            }
        }
    }
}

void MachineProcess::screwThread4_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->screwThread4.Cn, xDir = p->screwThread4.xDir, zDir = p->screwThread4.zDir;
    const double Tr = p->screwThread4.Tr, Tp = p->screwThread4.Tp, F = p->screwThread4.F;
    const double tanA = tan(p->screwThread4.A/180 * PI);
    machineNode* next = p->next;

    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        *GCode << "G01 U" << Tr * Num * xDir << " F" << F << "M3 S100;" << ";" << endl;
        *GCode << "G32 U" << Tr * Num * xDir * -1 << " W" << Tr * Num / tanA * zDir << " F" << Tp << ";" << endl;
        *GCode << "G00 W" << Tr * Num / tanA * zDir * -1 << " F" << F << ";" << endl;
        if (nullptr == next && 1 == Cn)
        {
            *GCode << "M30;" << endl;
        }
        Num = Num + 1;
    }
}
void MachineProcess::chamfer1_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->chamfer1.Cn, xDir = p->chamfer1.xDir, zDir = p->chamfer1.zDir;
    double L = p->chamfer1.L, Tr = p->chamfer1.Tr, Cr = p->chamfer1.Cr, R = p->chamfer1.R,F = p->chamfer1.F;
    double Center[2]; // 0.X 01.Z
    /*===========================================平面求圆弧圆心=============================================== */
    double mid[2];// 0.Z  1.X
    double theta;
    double abs_radius;
    double half_length;
    double offset;
    double Turn2;

    abs_radius=abs(R);
    mid[1] = (0 + (Cr * xDir))/2;
    mid[0] = ((L * zDir) + 0)/2;

    half_length = sqrt((mid[1] - 0) * (mid[1] - 0) + (mid[0] - (L * zDir))*(mid[0] - (L * zDir)));
//    if (-1 == zDir)
        theta = atan2(((L * zDir) -0), (0 - (Cr * xDir))) - PI0_5;
//    else
//        theta = atan2((0 - (L * zDir)), ((Cr * xDir) - 0)) + PI0_5;

    if(half_length>abs_radius)
    {
        half_length=abs_radius;
    }
    Turn2 = asin (half_length/abs_radius);
    offset = abs_radius * cos(Turn2);
    Center[0] = mid[0] + (offset * cos(theta));
    Center[1] = mid[1] + (offset * sin(theta));
    if(1 == zDir)
    {
        Center[0] = (mid[0] + (offset * cos(theta))) * -1;
    }
    qDebug()<<Center[0]<<","<<Center[1]<<endl;
    /*===========================================平面求圆弧圆心=============================================== */
    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        if (-1 == zDir)
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
        }
        else
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }

        }

    }
    if(nullptr == p->next)
    {
        *GCode<<"M30;"<<endl;
    }
}

void MachineProcess::chamfer2_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    const int Cn = p->chamfer2.Cn, xDir = p->chamfer2.xDir, zDir = p->chamfer2.zDir;
    const double Tr = p->chamfer2.Tr, F = p->chamfer2.F, L = p->chamfer2.L / p->chamfer2.Cn;
    machineNode* next = p->next;

    if (*textHeadFlag)
    {
        *GCode << "O200;" << endl;
        *textHeadFlag = false;
    }

    for (int a = 0; a < Cn; a++)
    {
        *GCode << "G01 U" << Tr * Num * xDir << " F" << F << ";" << endl;
        *GCode << "G01 U" << Tr * Num * xDir * -1 << " W" << L * Num * zDir << " F" << F << ";" << endl;
        *GCode << "G00 W" << L * Num * zDir * -1 << " F" << F << ";" << endl;
        if (nullptr == next && 1 == Cn)
        {
            *GCode << "M30;" << endl;
        }
        Num++;
    }
}

void MachineProcess::chamfer3_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Cn = p->chamfer3.Cn, xDir = p->chamfer3.xDir, zDir = p->chamfer3.zDir;
    double L = p->chamfer3.L, Tr = p->chamfer3.Tr, Cr = p->chamfer3.Cr, R = p->chamfer3.R,F = p->chamfer3.F;
    machineNode* next = p->next;
    double Center[2]; // 0.X 01.Z
    /*===========================================平面求圆弧圆心=============================================== */
    double mid[2];// 0.Z  1.X
    double theta;
    double abs_radius;
    double half_length;
    double offset;
    double Turn2;

    abs_radius=abs(R);
    mid[1] = (0 + (Cr * xDir))/2;
    mid[0] = ((L * zDir) + 0)/2;

    half_length = sqrt((mid[1] - 0) * (mid[1] - 0) + (mid[0] - (L * zDir))*(mid[0] - (L * zDir)));
//    if (-1 == zDir)
        theta = atan2(((L * zDir) -0), (0 - (Cr * xDir))) - PI0_5;
//    else
//        theta = atan2((0 - (L * zDir)), ((Cr * xDir) - 0)) + PI0_5;

    if(half_length>abs_radius)
    {
        half_length=abs_radius;
    }
    Turn2 = asin (half_length/abs_radius);
    offset = abs_radius * cos(Turn2);
    Center[0] = mid[0] + (offset * cos(theta));
    Center[1] = mid[1] + (offset * sin(theta));
    if(1 == zDir)
    {
        Center[0] = (mid[0] + (offset * cos(theta))) * -1;
    }
    qDebug()<<Center[0]<<","<<Center[1]<<endl;
    /*===========================================平面求圆弧圆心=============================================== */
    for (int a = 0; a < Cn; a++)
    {
        if (true == *textHeadFlag)
        {
            *GCode << "O200;" << endl;
            *textHeadFlag = 0;
        }
        if (-1 == zDir)
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir<< " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
        }
        else
        {
            if(1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G03 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }
            if(-1 == xDir)
            {
                if (0 == a)
                {
                    *GCode << "G01 U" << Tr * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr* xDir * (a + 1) - Center[1]) * (Tr* xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]
                              - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])))  * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else if (a < Cn - 1)
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0]) * zDir * -1
                            << " F" << F << ";" << endl;
                    *GCode << "G02 U" << Tr * xDir * -1
                           << " W" << ((sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0])
                            - (sqrt(R * R - (Tr * xDir * (a + 1) - Center[1]) * (Tr * xDir * (a + 1) - Center[1])) + Center[0])) * zDir * -1
                            << " R" << R << " F" << F << ";" << endl;
                    *GCode << "G01 W" << (sqrt(R * R - (Tr * xDir * a - Center[1]) * (Tr * xDir * a - Center[1])) + Center[0]) * zDir << " F" << F << ";" << endl;
                }
                else
                {
                    *GCode << "G01 U" << Tr * 2 * xDir << " F" << F << ";" << endl;
                    if(1 == xDir)
                    {
                        *GCode << "G03 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    else
                    {
                        *GCode << "G02 U" << Cr * xDir * -1<< " W" << L * zDir<< " R" << R << " F" << F << ";" << endl;
                    }
                    *GCode << "G01 W" << L * zDir * -1 << " F" << F << ";" << endl;
                }
            }

        }

    }
    if(nullptr == next)
    {
        *GCode<<"M30;"<<endl;
    }
}

void MachineProcess::chamfer4_GCode_auto(machineNode* p, ofstream* GCode, bool* textHeadFlag)
{
    int Num = 1;
    int Cn = p->chamfer4.Cn, xDir = p->chamfer4.xDir, zDir = p->chamfer4.zDir;
    double Tr = p->chamfer4.Tr, L = p->chamfer4.L, F = p->chamfer4.F;
    machineNode* next = p->next;

    if (*textHeadFlag)
    {
        *GCode << "O200;" << endl;
        *textHeadFlag = false;
    }

    for (int a = 0; a < Cn; a++)
    {
        *GCode << "G01 U" << Tr * Num * xDir << " F" << F << ";" << endl;
        *GCode << "G01 U" << Tr * Num * xDir * -1 << " W" << L / Cn * Num * zDir << " F" << F << ";" << endl;
        *GCode << "G00 W" << L / Cn * Num * zDir * -1 << " F" << F << ";" << endl;
        if (next == nullptr && Cn == 1)
        {
            *GCode << "M30;" << endl;
        }
        Num++;
    }
}

bool MachineProcess::outputGCode_auto()
{
    machineNode *p = m_mSeq.getHead();
    string TEXT = "/home/root/nc/O0200.CNC";
    ofstream GCode(TEXT,ios::out);

    bool textHeadFlag = true;

    // 文件打开失败
    if(!GCode)
    {
        return false;
    }
    while(p != nullptr)
    {
        switch(p->type){

            case OUTER_CIRCLE_ONE :// 外圆1模式工艺
                outerCircle1_GCode_auto(p, &GCode, &textHeadFlag);
                break;

            case OUTER_CIRCLE_TWO :// 外圆2模式工艺
                outerCircle2_GCode_auto(p, &GCode, &textHeadFlag);
                break;

            case OUTER_CIRCLE_THREE :// 外圆3模式工艺
                outerCircle3_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case END_FACE_ONE :
                endFace1_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case END_FACE_TWO :
                endFace2_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case END_FACE_THREE :
                endFace3_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case INNER_HOLE_ONE :
                innerHole1_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case INNER_HOLE_TWO :
                innerHole2_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case INNER_HOLE_THREE :
                innerHole3_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case INNER_HOLE_FOUR :
                innerHole4_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case INNER_HOLE_FIVE :
                innerHole5_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CONE_FACE_ONE :
                coneFace1_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CONE_FACE_TWO :
                coneFace2_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CONE_FACE_THREE :
                coneFace3_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CONE_FACE_FOUR :
                coneFace4_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case SCREW_THREAD_ONE :
                screwThread1_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case SCREW_THREAD_TWO :
                screwThread2_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case SCREW_THREAD_THREE :
                screwThread3_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case SCREW_THREAD_FOUR :
                screwThread4_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CHAMFER_ONE :
                chamfer1_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CHAMFER_TWO :
                chamfer2_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CHAMFER_THREE :
                chamfer3_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            case CHAMFER_FOUR :
                chamfer4_GCode_auto(p, &GCode, &textHeadFlag);
                break;
            default:
                break;
        }
        p = p->next;
    }
    GCode.close();
    return true;
}

bool MachineProcess::recordVariable()
{
    string TEXT = "E:\\QT\\program\\BLUE\\File\\Variable.txt";
    ofstream Variable(TEXT,ios::out);

    // 文件打开失败
    if(!Variable)
    {
        return false;
    }

    Variable<<barstock_width<<endl;
    Variable<<barstock_height<<endl;
    Variable<<barstock_L1<<endl;
    Variable<<barstock_D1<<endl;

    return true;
}

bool MachineProcess::recoverVariable()
{
    string TEXT = "E:\\QT\\program\\BLUE\\File\\Variable.txt";
    ifstream Variable(TEXT,ios::in);
    string TempData;
    int lineNum = 0;
    if (!Variable)
    {
        dealInterfaceData->firstInsystem = true;
        return false;
    }
    while (getline(Variable,TempData))
    {
        if(lineNum == 0)
        {
            barstock_width = std::stod(TempData);
        }
        else if(lineNum == 1)
        {
            barstock_height = std::stod(TempData);
        }
        else if(lineNum == 2)
        {
            barstock_L1 = std::stod(TempData);
        }
        else if(lineNum == 3)
        {
            barstock_D1 = std::stod(TempData);
        }

        lineNum++;
    }
    return true;
}
