#ifndef MACHINESTRUCT_H
#define MACHINESTRUCT_H



// 公用坐标结构体
typedef struct{
    double x;
    double y;
} coordinate;

// 顶点结构体
typedef struct v{
    coordinate p;
    struct v *next;
}vertex;


// **********工艺序列类中的结构体******************

// 切外圆1模式结构体
typedef struct{
    coordinate startCord;// 起始点坐标
    short int xDir;
    short int zDir;
    double L;// 矩形的长
    double Tr;// 每次进刀量
    int Cn;// 进刀的次数
    double Cr;// 矩形的宽Cr = Tr*Cn
    double F;// 转速
}s_outerCircleMode1;

// 切外圆2模式结构体
typedef struct{
   coordinate startCord;
   short int xDir;
   short int zDir;
   double L;
   double Tr;
   int Cn;
   double Cr;
   double A;
   double F;
}s_outerCircleMode2;

// 切外圆3模式结构体
typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    bool G2G3;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double R;
    double F;
}s_outerCircleMode3;

    // 斜向螺纹加工
typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double Lr;
    double deltaT;
    int Cn;
    double CT;
    double F;
}s_endFaceMode1;

    // 圆弧加工
typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double Lr;
    double Tr;
    int Cn;
    double W;
    double Tw;
    double F;
}s_endFaceMode2;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double Lr;
    double deltaT;
    int Cn;
    double CT;
    double F;
}s_endFaceMode3;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double F;
}s_innerHoleMode1;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double A;
    double F;
}s_innerHoleMode2;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double Lr;
    double Tr;
    int Cn;
    double W;
    double W1;
    double Tw;
    double F;
}s_innerHoleMode3;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    bool G2G3;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double R;
    double F;
}s_innerHoleMode4;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double deltaT;
    int Cn;
    double BT;
    double F;
}s_innerHoleMode5;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double A;
    double F;
}s_coneFaceMode1;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double A;
    double F;
}s_coneFaceMode2;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double A;
    double F;
}s_coneFaceMode3;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double A;
    double F;
}s_coneFaceMode4;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double Tp;
    double F;
    int unit;//Tp单位
    int multi_head;//多头
    double startA;//起始角度
    bool tailFlick;//甩尾
    bool filingProcessing;//挫位加工
    double filingDistance;//挫位距离
}s_screwThreadMode1;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double Tp;
    double A;
    double F;
    int unit;//Tp单位
    int multi_head;//多头
    double startA;//起始角度
    bool tailFlick;//甩尾
    bool filingProcessing;//挫位加工
    double filingDistance;//挫位距离
}s_screwThreadMode2;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double Tp;
    double F;
    int unit;//Tp单位
    int multi_head;//多头
    double startA;//起始角度
    bool tailFlick;//甩尾
    bool filingProcessing;//挫位加工
    double filingDistance;//挫位距离
}s_screwThreadMode3;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double Tp;
    double A;
    double F;
    int unit;//Tp单位
    int multi_head;//多头
    double startA;//起始角度
    bool tailFlick;//甩尾
    bool filingProcessing;//挫位加工
    double filingDistance;//挫位距离
}s_screwThreadMode4;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    bool G2G3;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double R;
    double F;
}s_chamferMode1;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double A;
    double F;
}s_chamferMode2;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    bool G2G3;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double R;
    double F;
}s_chamferMode3;

typedef struct{
    coordinate startCord;
    short int xDir;
    short int zDir;
    double L;
    double Tr;
    int Cn;
    double Cr;
    double A;
    double F;
}s_chamferMode4;


// 总工艺结点结构体
typedef struct machineNode{
    int type;
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
    struct machineNode *next;
}machineNode;

typedef struct {
    int num;
    machineNode *head;
    machineNode *tail;
    int barWidth;
    int barHeight;
}machineIndex;










#endif // MACHINESTRUCT_H
