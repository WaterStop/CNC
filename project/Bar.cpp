
#include <Bar.h>
#include<QDebug>

// Bar
// 构造函数
Bar::Bar(int canvasWidth, int canvasHeight)
    :m_canvasWidth(canvasWidth), m_canvasHeight(canvasHeight)
{
    // 动态申请[m_canvasWidth, m_canvasHeight]大小的二维数组
    m_pixelArray = new BYTE*[canvasWidth];
    for(int i = 0; i < canvasWidth; i++){
        m_pixelArray[i] = new BYTE[canvasHeight];
    }
    // 将画布所有像素数组元素初始化为0
    for(int i = 0; i < canvasWidth; i++)
        for(int j = 0; j < canvasHeight; j++){
            m_pixelArray[i][j] = 0;
        }

}
// 析构函数
Bar::~Bar(){
    for(int i = 0; i < m_canvasWidth; i++){
        delete [] m_pixelArray[i];
    }
}

// 将bar在画布中心的初始化
bool Bar::barInit(int width, int height)
{
    // 参数健壮性判断
    if(width > m_canvasWidth || height > m_canvasHeight)
        cerr<< "barInit function error"<< endl;

    // 在画布中心画棒料
    int left = floor((m_canvasWidth-width)/2);
    int right = floor((m_canvasWidth+width)/2);
    int bottom = floor((m_canvasHeight-height)/2);
    int top = floor((m_canvasHeight+height)/2);
    for(int x = left; x < right; ++x)
        for(int y = bottom; y < top; ++y){
            m_pixelArray[x][y] = 1;
        }
    return true;
/*
    // 根据传入的棒料参数初始化棒料，并放在画布中间
    // 画布中心点坐标
    for(int x = start.x; x <= start.x+width; ++x)
        for(int y = start.y; y <= start.y+height; ++y){
            if(x >= 0 && x<m_canvasWidth && y >= 0 && y<m_canvasHeight)
                m_pixelArray[x][y] = 1;
        }
    return true;
    */

}






// 必须规定坐标系：棒料的二维数组的左下角坐标是(0,0)，右上角坐标是(MAX_COL,MAX_ROW)
// ### 工艺函数
// 1. transverseMachining横向加工，切削出的为矩形
    // - 参数（起始坐标，底边长度，每次削减深度(正负决定方向)，消减次数）
    // - 工艺的方向：起始点在右下角，向左雕刻，输入参数均为正数
bool Bar::transverseMachining(coordinate startCord, int len, int height ){

  qDebug()<<"len="<< len;
    // 参数健壮性检查
    if (len<0 || height <0)
        return false;
    // 被裁剪图形的边界
    int top = startCord.y+height;
    int bottom = startCord.y;
    int left = startCord.x-len;// 工艺左边界不能超越棒料底部
    int right = startCord.x;
    //int rr;
    // 将工艺雕刻的范围中的在画布中的部分设置为0
    for(int x = left; x <= right; x++)
         for(int y = bottom; y <= top; y++ ){
            if(x>=0 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                //rr = m_pixelArray[x][y];
                //cout << rr;
                m_pixelArray[x][y] = 0;

        }
    return true;
}

bool Bar::obliqueMachiningRightDown(coordinate startCord, int len, float slope)
{
    // 参数健壮性检查
    if (len < 0  || slope < 0 )
        return false;
    startCord.x -=  len;// 统一为右边
    // 绘制三角形
    int topBoundary;
    int bottomBoundary;
    int leftBoundary;
    int rightBoundary;

    topBoundary = startCord.y + len/slope;
    bottomBoundary = startCord.y;
    leftBoundary = startCord.x;
    rightBoundary = startCord.x+len;

    if(topBoundary >= m_canvasHeight || bottomBoundary < 0 || leftBoundary < 0 || rightBoundary >= m_canvasWidth)
        return false;

    // 当点在裁剪区域内并且斜率小于斜边斜率表明在三角中
    for(int x = leftBoundary; x < rightBoundary; ++x)
        for(int y = bottomBoundary; y < topBoundary; ++y)
            if ((rightBoundary-x) > slope *(y-bottomBoundary))// 使用移位除法除去零错误
                    m_pixelArray[x][y] = 0;
    return true;

}

// 2. 斜向加工，切削出的为直角三角形,左下和右下都是从顶点开始计算的
    // 参数（起始点（直角顶点），底边长度，顶角斜率(底部/高度)）
bool Bar::obliqueMachiningLeftDown(coordinate startCord, int len, float slope){// slope是直角三角形上顶点的斜率

    // 参数健壮性检查
    if (len < 0  || slope < 0 )
        return false;

    // 绘制三角形
    int topBoundary;
    int bottomBoundary;
    int leftBoundary;
    int rightBoundary;

    topBoundary = startCord.y + len/slope;
    bottomBoundary = startCord.y;
    leftBoundary = startCord.x - len;
    rightBoundary = startCord.x ;

    if(topBoundary >= m_canvasHeight || bottomBoundary < 0 || leftBoundary < 0 || rightBoundary >= m_canvasWidth)
        return false;

    // 当点在裁剪区域内并且斜率小于斜边斜率表明在三角中
    for(int x = leftBoundary; x < rightBoundary; ++x)
        for(int y = bottomBoundary; y < topBoundary; ++y)
            if ((x-(startCord.x-len)) > slope *(y-startCord.y))// 使用移位除法除去零错误
                    m_pixelArray[x][y] = 0;

     return true;
}



// 2. 螺纹加工
    // 利用向量叉乘原理画没有底部的三角形：向量AB×向量AP为正表示AP到AB的角度为0~180
int Bar::vecCalculate(coordinate A, coordinate B, coordinate P)
{
    // 计算两个边的向量
    coordinate AB = {A.x-B.x, A.y-B.y};
    coordinate AP = {A.x-P.x, A.y-P.y};
    // 计算二维向量叉乘后的值
    int val = AB.x*AP.y - AP.x*AB.y;
    return val;
}



    // 横向螺纹加工
    // 参数（起始点（在右下角），螺距(三角低长)，螺纹深度（进刀量*次数），螺纹长度）
bool Bar::tThreadMachining(coordinate startCord, int pitch, int depth, int len)
{

    // 参数健壮性检查
    if (len < 0  || pitch < 0)
        return false;
    //限制深度，避免过小而像素无法显示
    if (depth < 2) depth = 3;

    // 三角形的三点的坐标，其中A点是核心交点
    coordinate A = {startCord.x-pitch/2, startCord.y+depth};// 顶点
    coordinate B1 = startCord;// 右下
    coordinate B2 = {startCord.x-pitch, startCord.y};// 左下
    // 向量
    coordinate P;
    // 计算像素矩阵内符合条件的像素点并赋0
    for (int x = startCord.x-pitch; x <= startCord.x; ++x)
        for(int y = startCord.y; y<= startCord.y+depth; ++y){
            P = {x,y};

            // 都是顺时针形成的角度,B1为钝角sin小于0,B2为锐角sin大于0
                if( vecCalculate(A, B1, P)<0 && vecCalculate(A, B2, P)>0){
                    for(int i = 0; i < ceil(len/pitch)+1; ++i){
                        // 这里应该做一下优化，将雕刻方向自左向右，第一个不在窗口内说明后面没必要雕刻了
                        int xTmp = x-i*pitch;
                        if(xTmp>=0 && xTmp<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                            m_pixelArray[xTmp][y] = 0;
                    }
                }

        }
    return true;
}




// 斜向螺纹加工
    // 求两条直线的交点，输入为两条直线的端点
void Bar::getIntersectPoint(coordinate lineOnePt1, coordinate lineOnePt2,
                             coordinate lineTwoPt1, coordinate lineTwoPt2, double* arr) {
        double x;
        double y;
        if((lineOnePt1.x- lineOnePt2.x)==0 || (lineTwoPt1.x - lineTwoPt2.x)==0)
            cerr << "Bar::getIntersectPoint Divide By Zero"<< endl;

        double k = (lineOnePt1.y - lineOnePt2.y) / (lineOnePt1.x- lineOnePt2.x);
        double b = lineOnePt1.y - k * lineOnePt1.x;

        double k1 = (lineTwoPt1.y - lineTwoPt2.y) / (lineTwoPt1.x - lineTwoPt2.x);
        double b1 = lineTwoPt1.y - k1 * lineTwoPt1.x;

        x = (b1 - b) / (k - k1);
        y = k * x + b;

        arr[0] = x-lineOnePt1.x;
        arr[1] = y-lineOnePt1.y;
}

// 参数描述的是直角三角形，在该三角形的斜边上雕刻螺纹，直角边的交点是右下角startCord，len描述底边，height描述高
// pitch和depth分别描述小三角性的底和高
bool Bar::oThreadMachining(coordinate startCord, int pitch, int depth, int len, int height)
{
    // 先切一个斜三角区域
    obliqueMachiningLeftDown(startCord, len, len/height);
    // 参数健壮性检查
    if (len < 0 || pitch < 0 || height < 0)
        return false;
    // 初始三角形的三点的坐标，其中A点是核心交点
    coordinate A = {startCord.x-len+pitch/2, startCord.y+depth};// 顶点
    coordinate B1 = {startCord.x-len+pitch, startCord.y};// 右下
    coordinate B2 = {startCord.x-len, startCord.y};// 左下
    // 螺纹三角形必须左斜边斜率大于雕刻螺纹的斜边才能显示
//    if( ((A.y-B2.y)/(A.x-B2.x)) > (height/len) && pitch > 1)
//        oThreadMachining(startCord, pitch, depth+1, len, height);

    // 计算第一个螺纹三角形右斜边和斜线的交点
    // 通过交点计算相邻螺纹三角间的斜向和横向增量
    coordinate aStart = B2;
    coordinate aEnd = {startCord.x, startCord.y+height};
    coordinate bStart = B1;
    coordinate bEnd = A;

    double* arr = new double[2];// x坐标
    getIntersectPoint(aStart, aEnd, bStart, bEnd, arr);
    int triCount = ceil(len/arr[0])-1;// 三角形的个数
    // 向量
    coordinate P;
    // 计算像素矩阵内符合条件的像素点并赋0
    for (int x = startCord.x-len; x <= startCord.x-len+pitch; ++x)
        for(int y = startCord.y; y<= startCord.y+depth; ++y){
            P = {x,y};
            // 都是顺时针形成的角度,B1为钝角sin小于0,B2为锐角sin大于0
            if( vecCalculate(A, B1, P)<0 && vecCalculate(A, B2, P)>0 ){
                for(int i = 0; i < triCount; ++i){
                    int tmpx = x+(int)ceil(i*arr[0]);
                    int tmpy = y+(int)ceil(i*arr[1]);
                    if(tmpx>=0 && tmpx<m_canvasWidth&& tmpy>=0 && tmpy<m_canvasHeight)
                        m_pixelArray[tmpx][tmpy] = 0;
                }

            }

        }

    free(arr);
    return true;

}



// 圆弧
    // 求圆心
coordinate *Bar::Circle_Center(coordinate p1, coordinate p2, double dRadius)
{
    double k = 0.0,k_verticle = 0.0;
    double mid_x = 0.0,mid_y = 0.0;
    double a = 1.0;
    double b = 1.0;
    double c = 1.0;
    coordinate center1,center2;
    // 防止除零异常
    if(p2.x !=  p1.x)
        k = double((p2.y - p1.y) )/ double((p2.x - p1.x));
    else {


        int c_2 = pow(dRadius, 2);
        int h_2 = pow((p2.y - p1.y)/2, 2);
        int w = ceil(sqrt(c_2 - h_2));


        coordinate *centerP = new coordinate[2];
        centerP[0].x =p1.x - w;
        centerP[0].y =(p2.y + p1.y)/2;
        centerP[1].x =p1.x + w;
        centerP[1].y =(p2.y + p1.y)/2;
        return centerP;

    }

    if(k == 0)
    {
        center1.x = (p1.x + p2.x) / 2.0;
        center2.x = (p1.x + p2.x) / 2.0;
        center1.y = p1.y + sqrt(dRadius * dRadius -(p1.x - p2.x) * (p1.x - p2.x) / 4.0);
        center2.y = p2.y - sqrt(dRadius * dRadius -(p1.x - p2.x) * (p1.x - p2.x) / 4.0);
    }
    else
    {
        k_verticle = -1.0 / k;
        mid_x = (p1.x + p2.x) / 2.0;
        mid_y = (p1.y + p2.y) / 2.0;
        a = 1.0 + k_verticle * k_verticle;
        b = -2 * mid_x - k_verticle * k_verticle * (p1.x + p2.x);
        c = mid_x * mid_x + k_verticle * k_verticle * (p1.x + p2.x) * (p1.x + p2.x) / 4.0 -
            (dRadius * dRadius - ((mid_x - p1.x) * (mid_x - p1.x) + (mid_y - p1.y) * (mid_y - p1.y)));

        center1.x = (-1.0 * b + sqrt(b * b -4 * a * c)) / (2 * a);
        center2.x = (-1.0 * b - sqrt(b * b -4 * a * c)) / (2 * a);

        center1.y = k_verticle * center1.x - k_verticle * mid_x + mid_y;
        center2.y = k_verticle * center2.x - k_verticle * mid_x + mid_y;
    }
    // 输出结点
    coordinate *centerP = new coordinate[2];
    centerP[0].x =center1.x;
    centerP[0].y =center1.y;
    centerP[1].x =center2.x;
    centerP[1].y =center2.y;
    return centerP;
}



// 画优弧
    // 参数含义：圆弧的起始点和终点，圆弧表示的圆的半径，0表示优弧1表示劣弧，0表示从下方进刀1表示从右边进刀
bool Bar::arcMachining(coordinate p1, coordinate p2, double radius, bool arCCodition)
{

    // TODO:当半径不足时,会绘制正方形
    // 归一化处理
    coordinate pu = (p1.y > p2.y) ? p1 : p2;// under上面的弧点
    coordinate pd = (p1.y < p2.y) ? p1 : p2;// down下面的弧点
    // 求圆心
    coordinate *centerP = Circle_Center(pu, pd, radius);
    // 像素处理
    // centerP[1]是左边优弧的圆心，centerP[0]是右边圆弧
    if(arCCodition){
        // 优弧
        for(int y = pd.y; y <= pu.y; ++y)
            for (int x = pd.x; x <= pu.x; ++x){
                int a = pow(x-centerP[1].x,2);
                int b = pow(y-centerP[1].y,2);
                int c = pow(radius,2);
                if(a + b > c)
                   if(x>=0 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                        m_pixelArray[x][y] = 0;
            }

    }else{
        // 劣弧
        for(int y = pd.y; y <= pu.y; ++y)
            for (int x = pd.x; x <= pu.x; ++x){
                int a = pow(x-centerP[0].x,2);
                int b = pow(y-centerP[0].y,2);
                int c = pow(radius,2);
                if(a + b < c)
                   if(x>=0 && x<m_canvasWidth&& y>=0 && y<m_canvasHeight)
                        m_pixelArray[x][y] = 0;
            }

    }


    free(centerP);
    return true;

}

// 对外提供的访问类内私有变量的接口
unsigned char **Bar::get_m_pixelArray()
{
    return this->m_pixelArray;
}



