#ifndef __DECODE_H__
#define __DECODE_H__

#include <stdio.h>

#include "motion.h"
#include "plc.h"
#include "error.h"

extern struct decode_status_s * decode_status;

#define MACRO_NUM        2750   //宏变量个数 
#define OftMaxNum 33
#define OftDimensionNum 5   // 刀偏维数,排序为 X,Z,Y,R,T
#define  MaxNestingNum 5


#define NAMELEN 20//文件名最大字符数量


#define GCOUNT 17 /*G指令组数*/
#define MAX_STACK 7//词法分析中的表达式嵌套次数

#define BUFLEN            1500//一行程序最大字符数量
#define MAX_NUM_INT 999999999
#define NULLVARIABLE    10000000  /*1000000 代表空变量*/
#define Minim           0.000001

#define TotalScode 1000000
#define TotalTcode 1000
#define TotalMcode 100
#define FCOMMAXVAL        999999.9999
#define FCOMMINVAL        -999999.9999

#define G54G59MaxNum    8  

#define InvalVal        10000001   //无效值，可用于初始化译码数据。
#define NULLVARIABLE    10000000  //1000000 代表空变量


#define SYNTAX_Q_NUM 2000

//-------------------------G指令----------------------------------
//00组:G04 G10 G11 G27 G28 G31 G39 G65 G92
#define G04        4
#define G10        10
#define G11        11

#define G27        27
#define G28        28
#define G29        29
#define G30        30
#define G31        31
//#define G36        36
//#define G37        37
#define G39        39
#define G50        50
#define G53        53
#define G60        60
#define G65        65

#define G70        70
#define G71        71
#define G72        72
#define G73        73
#define G74        74
#define G75        75
#define G76        76
#define G78        78

//01组: G00 G01 G02 G03 
#define G00        0
#define G01        1
#define G02        2
#define G03        3
#define G05        5
#define G08        8
#define G09        9

#define G32        32
#define G34        34

#define G90        90
#define G92        92
#define G94        94
//02组：G96 G97
#define G96        96
#define G97        97

//03: G98 G99  原10组
#define G98        98
#define G99        99
//04:

//05组: G54 G55 G56 G57 G58 G59
#define G54        54
#define G55        55
#define G56        56
#define G57        57
#define G58        58
#define G59        59
//06组: G20 G21
#define G20        20
#define G21        21
//07组: G40 G41 G42
#define G40        40
#define G41        41
#define G42        42
//08组: G43 G44 G49
#define G43        43
#define G44        44
#define G49        49
//09组: G80 G84
#define G80        80
#define G84        84
#define G88        88
#define G33        33
//10组:

//11组: 

//12组:

//13组: 

//14组：G61 G62 G63 G64
#define G61        61
#define G62        62
#define G63        63
#define G64        64
//15组: G17 G18 G19
#define G17        17
#define G18        18
#define G19        19

//16组:G12 G13
#define G12        12
#define G13        13
/***********************added by lei**************************************/
#define G107            107            //圆柱
#define G122            122            //渐开线
#define G123            123            //指数
#define G132         132            //渐开线
#define G133            133            //指数
#define G162            162            //椭圆
#define G163            163            //椭圆
#define G172            172            //抛物线
#define G173            173            //抛物线
#define G182            182            // 双曲线
#define G183            183            // 双曲线



#define INTERP_HYPE(a) (a==182?1:(a==183?1:0))
#define INTERP_Cylinder(a) (a==107?1:0)
#define INTERP_ELLIPSE(a) (a==7?1:(a==162?1:(a==163?1:(a==6?1:0))))
#define INTERP_Parabola(a) (a==172?1:(a==173?1:0))//抛物线



extern struct accidence_data_s InitAccData;
extern struct parse_s InitSynData;
extern struct CNC_CodeSegMent InitCutData;


extern struct motion_internal_struct *motion_internal;
extern struct motion_status_struct *motion_status;
extern struct motion_err_struct *motion_err;
extern struct motion_err_struct *motion_warn;
extern struct plc_shm_s *plc_shm;

typedef enum 
{
    DECODE_OK=0,
    
    
    
}DECODE_ERR_t;




typedef enum
{
    NOT_MACRO = 0,

    MACRO_IF,
    MACRO_DO,
    MACRO_END,
    MACRO_VAR,
    MACRO_GOTO,
    MACRO_THEN,
    MACRO_WHILE,


    MACRO_CALC_EQU,/*=    */
    MACRO_ADD,
    MACRO_SUB,
    MACRO_MUL,
    MACRO_DIV,

    MACRO_EQ, /*==*/
    MACRO_LT, /*<*/
    MACRO_NE, /*<>*/
    MACRO_LE, /*<=*/
    MACRO_GE, /*>=*/
    MACRO_GT, /*>*/

    MACRO_AND,
    MACRO_OR,
    MACRO_RIGHT_BRACKET,/*]*/
    MACRO_LEFT_BRACKET,/*[*/


    MACRO_ABS,
    MACRO_ACOS,
    MACRO_ASIN,
    MACRO_ATAN,
    MACRO_COS,
    MACRO_EXP,
    MACRO_FIX,
    MACRO_FUP,
    MACRO_LN,
    MACRO_ROUND,
    MACRO_SIN,
    MACRO_SQRT,
    MACRO_TAN
}DECODE_OPERATION;



struct accidence_data_s
{
    int numCtrl;         /*段号,显示用和控制用,它存储的是本程序段在文件中的偏移值，与nNo的区别是nNo是NC程序中的N值*/
    int nNo;             /*NC program segment sequence token*/
    //char bBusy;          /*the interperter program running  1:busy 0:free*/
    char EOB;            /*data segment end,1:end , 0:no/*文件结束*/

    //预留，暂时没有使用
//    char ProgramEndMark; /*the program segment end,1:end,0:no*//
    int IsHaveSkipFlag;  /*用于标识该段是否有跳段标志"/"  0:该段无跳段符 1:有，但跳段没打开 2:有，且跳段已打开*/
    int Gcode[GCOUNT];   /*00~15 Group*/
    double Fcode;        /*进给速度*/
    char Fflag;
    double Pcode;     /*根据G代码类型判断，是暂停时间还是子程序，G10的刀具偏置号*/
    char Pflag;       /*标志P代码是否用到1:有0:无*/
    double Qcode;     /*孔底偏移量*/
    int Qflag;        /*该段是否有Q代码*/
    double Rcode;     /*根据G代码类型判断是圆弧半径还是代码号,退刀量，*/
    int Rflag;        /*该段是否有R代码*/
    int Hcode;        /*G65指令的H码或G43、G44的H代码*/
    char Hflag;       /*有无H代码：1:有,0:无*/
    int Dcode;        /*半径刀补偏置号*/
    char Dflag;       /*有无D代码：1:有,0:无*/
    double Icode;     /*圆弧中心的I坐标值*/
    char Iflag;       /*有无I代码：1:有,0:无*/
    double Kcode;     /*圆弧中心的K坐标值,固定循环重复次数*/
    char Kflag;       /*有无K代码：1:有,0:无*/
    double Jcode;     /*圆弧中心的J坐标值   */
    char Jflag;       /*有无J代码：1:有,0:无*/
    int Ncode;        /*圆弧中心的N坐标值   */
    char Nflag;       /*有无N代码：1:有,0:无*/
    double Xcode;     /*根据G代码类型判断是X轴坐标,还是暂停时间*/
    char Xflag;       /*X是否有新赋值1:有0:无*/
    double Ycode;     /*Y轴坐标*/
    char Yflag;       /*Y是否有新赋值1:有0:无*/
    double Zcode;     /*Z轴坐标*/
    char Zflag;       /*Z是否有新赋值1:有0:无0*/
    char Axis4flag;   /*第四轴是否有新赋值1:有0:无*/
    double Axis4code; /*第四轴坐标*/
    char Axis5flag;   /*第五轴是否有新赋值1:有0:无*/
    double Axis5code; /*第五轴坐标*/
    int Ocode;        /*子程序标识*/
    double Lcode;     /*子程序重复次数 */
    char Lflag;
    int Mcode;
    int McodeGroup[3]; /*根据位参0338设置一段程序中可以指令的M代码(0:1个,1:最多三个)*/
    char Mflag;
    int Scode;
    char Sflag;
    int Tcode;
    char Tflag;

    char G65PVarFlag;  /*用于记录P的的值是常量还是变量表示(FALSE:常量,TRUE:变量)*/
    double G65Pcode;   /*G65时P的变量号*/

    char Aflag;
    double Acode;
    char Bflag;
    double Bcode;
    char Cflag;
    double Ccode;
    char Eflag;
    double Ecode;
    char Uflag;
    double Ucode;
    char Vflag;
    double Vcode;
    char Wflag;
    double Wcode;
    char CAflag;
    double CAcode;
    char RAflag;
    double RAcode;
};

/*
词法分析队列，用来实现与语法分析之间的交互
队列长度设为1的原因是与语法分析同步
*/
struct accidence_queue_s
{
    struct accidence_data_s accidence_data[1]; /*队列*/
    int size;                                  /*队列长度*/
};



struct accidence_one_line_cache_s
{
    char line_buf[BUFLEN];/*保存读到的一行NC程序段*/
    int line_pos;/*当前读到哪个字符*/
    char line_end;/*识别完字符串的所有字符后置1*/
    int if_flag;/*此行IF条件的结果，1表示有IF语句且IF后面的条件为真，0表示没有IF语句，2表示有IF语句且后面的条件为假*/
    int mcode_num;/*保存一行中有多少个M指令*/
};

/*
词法分析状态
*/
struct accidence_status_s
{
    FILE* fd;//当前执行的NC程序文件描述符


    /*
    保存一行的内容
    */
    struct accidence_one_line_cache_s cache;

    int line_end_signal;/*0表示一行未结束，1表示一行结束*/
    int file_end_signal;/*0表示文件未结束，1表示文件结束*/

    /*
    数值错误
    判断#变量中的值是否可用
    在读取#变量之前置0，如果读取的#变量值超范围，则设置该值为1
    */
    char VarNullFlag;


    /*
    跳段标志，等于PLC的跳段G信号
    循环启动之后，PLC应该控制不可以修改跳段G信号
    */
    int SkipSegFlagStartRun;
    
};
/*******************************************螺纹数据*************************************/
 struct ThreadData
{
    char         IsThreadTail;
    char         HaveThreadTail;
    char         NextIsThread;
    char        FormIsThread;
    char        ThreadTailSec;    
    int             ThreadHeadNum;        //螺纹的头数
    int             ThreadHeadNumFlag;    //第几头螺纹
    double         ThreadThreeLength;
    double         ThreadQAngle;
};
/****************************************主要保存语法分析中要用到的模态值******************************/
struct  TmpSaveModeDATA_s
{
    int G31SegMoveMode; //G31所在段的移动模态,跳转插补
    int IfM06; //是否有M06刀库程序调用
    int IfDisSubProgram; //是否显示子程序的内容
    int if_rigid_tapping; //是否刚性攻丝

    double     hole_cyc_X, hole_cyc_Y, hole_cyc_A, 
            hole_cyc_X0, hole_cyc_Z0, // 初始点
            hole_cyc_Z,  // 终点
            hole_cyc_R,  // R 点
            hole_cyc_P,  // 暂停时间
            hole_cyc_Q,  // 
            hole_cyc_K, // 重复次数               
            hole_cyc_Y0, hole_cyc_A0,
            hole_tap_spin_speed;//LZ ADD 2022.4.29 保存M29后面的S的速度值  
    int  hole_cyc_MCode;  // 3:右旋 4:左旋
    int  hole_cyc_state;
    
    //middle point for return to reference point
    double interPntVal[5];//中间点坐标值
    
    double G90_X;    //G90_X：切削终点X 轴绝对坐标. 
    double G90_Z;    //G90_Z：切削终点Z 轴绝对坐标.
    double G90_R;    //G90_R: 切削起点与切削终点X 轴绝对坐标的差值(半径值)，带方向. 
    double G32_F;    //G32_F: 指定螺纹导程，为主轴转一圈长轴的移动量.
    double G32_J;    //G32_J: 螺纹退尾时在短轴方向的移动量(退尾量).
    double G32_K;    //G32_K: 螺纹退尾时在长轴方向的长度. 
};


/*
    保存模态信息
*/
struct temp_save_s
{

    struct TmpSaveModeDATA_s TmpModeData;
    
    struct ThreadData CThread;                     //螺纹加工数据

    int        O;
    int        N;
    int     Numctrl;    //当前执行文件的行号
    /*
    解释器的轴位置
    同步规则：
        上电同步
        运动同步后同步，由运动发送同步型号给任务，任务接收后同步
        极坐标插补和圆柱插补取消时同步
    修改：
        语法分析中根据轴的编程数据修改，修改为此条语法解析后 的轴位置        
    */
    double X,Y,Z,A,B;
    double     R;  
    double     I;  
    double     J;  
    double     K; 

    /*
   在语法分析的F_Deal中设置
   */
    double      Feedrate;                       //分进给速度，译码到F指令时，把相应的值赋给它
    double      FeedrateRev;                    //转进给速度
    
    int MoveSelect; //01组，G00,G01,G02,G03,G32,G34，插补动作
    int ViewMoveSelect;//G90  G92 G94  G70~G76  循环动作
    int UnitFlag;//G20 G21 英制公制单位选择 G20:英制  G21:公制
    int MinSecSelect;//03: G98 G99 每分(每转)进给0:每分 1:每转    
    int PlaneSelect;//G17,G18,G19
    int CoordSelect;//G50,G54-----G59
    int ScrewSelect;//G33，G80，G84，G88

    int         ThreadHeadNum;            //多头螺纹的头数
    int      ScrewFlag;    
    double   ScrewLead;
    double   toothNo;               //牙数
    double      ScrewTailJ;            //螺纹短轴退尾
    double      ScrewTailK;            //螺纹长轴退尾
    
    int MannerSelect; //G61,G62,G63,G64
    int G96G97Select; //02组,    G96、G97
    int G12G13Select; //16组,    G12、G13
    int CompensateRSelect; //G40 G41 G42  G40:注销  G41:左侧  G42:右侧    
    int CompensateLSelect; //G43 G44 G49 
    int      G512G502Selsct;  //LZ ADD 20210621 双主轴耦合
    //记录上次的状态，以便于恢复
    int         PreCompensateRSelect;  //用于记住G53，G50等指令暂时取消半径刀补前的刀补指令。
    int         PreCompensateLSelect;  //用于记住G50等指令暂时取消长度刀补前的刀补指令。
    
    int      Dcode;                 //半径偏置号    
    double   TCompensateR;        //R刀补值 
    int      TCompPointNO;        //刀尖号
    int      HCode;               //长度偏置号    


    double TCompensateLX; //X轴长度补偿值
    double TCompensateLY; //Y轴长度补偿值
    double TCompensateLZ; //Z轴长度补偿值

    int Mcode;
    int McodeGroup[3]; //根据位参0338设置一段程序中可以指令的M代码(0:1个,1:最多三个)
    int Tcode;//刀具号
    int TOftNo;//刀偏号

    int SCode;//速度设定值，在词法分析的S_Deal中设置
    double MaxSpindleSpeed;//指定最大主轴速度//目前没有作用
    int G96Speed; //指定最大主轴速度

    //用户坐标值,
    /*
    用户坐标值
    在初始化时赋值为G54-59的值+G50的值
    */
    //double userCoordVal[5]; //存在的意义是防止运行过程中修改了坐标系的值
    int IsG54G50; //当前是工件坐标系还是浮动坐标系(0:G50,1:G54~G59)

    int Polar;         //在reset之后这个值得置为0
    int Cylinder;      //在reset之后这个值得置为0
    double Cylinder_C;
};




/*
    语法分析结构体
*/
struct parse_s
{
    int numCtrl; /*段号,显示用和控制用,它存储的是本程序段在文件中的偏移值，与nNo的区别是nNo是NC程序中的N值*/
    int nNo; //NC program segment sequence token

    /*
    EOB 用于表示整个NC程序结束了
    ProgramEndMark 用于表示当前的文件结束了
    区别是如果有子程序，当子程序结束时ProgramEndMark设置为文件结束，EOB设置为未结束
    */
    int EOB;//data segment end,1:end , 0:no  

    double X, Y, Z, A, B; //绝对坐标值

    double       RA;  //倒圆角弦长
    double       CA;  //倒斜角长度

    //G指令，根据需要可增加
    char         G04Flag;//该段是否有暂停指令
    char         G50Flag;//该段是否有坐标系设定指令
    char          G27Flag;//该段是否有返回参考点检查指令
    char          G28Flag;//该段是否有返回参考点指令
    char          G29Flag;//该段是否有从参考点返回指令
    char          G30Flag;////该段是否有返回第2，3，4参考点指令
    char         G31Flag;//该段是否有测量功能指令
    char         G39Flag;//该段是否有拐角偏移圆弧插补指令
    char         G53Flag;//该段是否有选择机床坐标系指令

    char        IsSetCoordSelect;        //坐标选择，1:G54-G59 0:G50
    char        IsSetLCompSelect;         //长度补偿        
    char        IsSetG96G97Select;//该段是否有恒表面切削速度控制指令G96、G97
    char        IsSetG12Select;//该段是否有行程检测功能指令G12
    char        G512G502Flag;//LZ ADD 20210621 双主轴耦合标志
    int         G512G502Select;//LZ ADD 20210621 双主轴耦合标志
    int            ThreadHeadNumFlag;//第几头螺纹
    int           ScrewFlag;    //没有使用
    double        ScrewLead;//螺纹导程，为主轴转一圈长轴的移动量
    double     toothNo;    //螺纹的牙数
    double     ScrewAngle;  //起始角度


    //圆弧插补的参数
    double       R;               //arc radius
    double       I;               //the central of circle (x)
    double       J;               //the central of circle (y)   
    double       K;               //the central of circle (z)
    double center[3];

    double       CNCPause;        //如果Pause大于零，则暂停Pause*4ms的时间，暂停就是让伺服任务不向轴发指令
    
    //词法检查的数据结构
    //ParseCutter()中，用于判断是否需要设置各个位是否有改动，例如data2->IsSetX
    struct accidence_data_s  AccParseData;    
    
    int Polar;         //在reset之后这个值得置为0
    int Cylinder;      //在reset之后这个值得置为0

    //表示是MST段
    int is_mst;
};







/*
解释器状态结构体
描述解释器的整体状
*/
struct decode_status_s
{
    /*
    报警标志位,在任务的开始判断报警队列长度设置该值
    1；报警
    0：未报警
    */
    int alarm;

    /*
    需要软件复位标志位
    1-需要复位
    0-不需要
    需要复位的时候设置为1
    在复位函数中清零
    */
    int need_soft_rst_flg;


    /*
    PLC是否执行完成了MST信号
    词法分析遇到MST时置0，
    根据PLC的MST完成G信号的上升沿置1，
    词法分析中，会判断此位，如果此位是0，表示MST还未执行完成，需要等待MST执行完成后才能继续词法分析
    */
    int MST_done;


    /*
    跳段的状态
    由任务根据PLC的G信号设置，或清除
    用于词法分析时设置跳段标志位
    */
    int skip_status;
    
    /*
    开始解释器运行标志位
    任务识别PLC的循环启动G信号，设置1
    复位操作设置为0
    M30等结束标志设置为0
    在词法分析中检查此标志位，只有为1时才能开始词法分析
    */
    int start_flag;


    /*
    需要初始化解释器环境
    复位后需要初始化，
    程序执行完成后需要初始化，
    如果需要初始化，设置此位为1即可，会在词法分析之前调用初始化函数，执行完初始化动作后由初始化函数置0
    */
    int need_init;

    /*
    -------------------------------------------NC程序相关，0表示主程序，其他表示子程序，最多嵌套5层
    */
    char file_name[MaxNestingNum][NAMELEN];/*打开的文件名，最多嵌套5层，文件名最多20个字符(子程序)*/

    /*
    file_line与lineno
    file_line是文件指针，不是行号，他的数值是按字符计算的，
    lineno是文件指针所在位置是文件的第几行，是行号
    */
    unsigned int  file_line[MaxNestingNum];/*保存每一个文件的文件指针，lseek,读到文件的哪个位置*/

    unsigned int lineno[MaxNestingNum];/*保存每一个文件读到哪行了，使用file_line太长了*/

    /*
    表示当前执行的是哪个程序，0表示主NC程序
    跳转到子程序或者返回上一层程序是会更改
    复位时应该置0
    执行时需要检查该值的合法性，不能大于嵌套的层数
    */    
    int file_p;

    int last_file_p;//当前打开的是哪个文件，用于判断是否需要重新打开文件

    //子程序调用次数
    int     SubprogramNum[MaxNestingNum];            
    /*
    -------------------------------------------NC程序相关，END
    */

    // 宏变量-------存放插补后的数据
    double GlobMacroBuf[MACRO_NUM];  
    /*
    刀补值，实时值，可以在界面修改，修改后立即更新此值
    X轴保存的是半径的值
    */
    double OffsetBuf[OftMaxNum][OftDimensionNum][2];  //第一维：刀号。第二维：X,Z,Y,R,T。第三维：[0]:偏置   [1]:磨损
    
    // 实际使用的刀偏整体偏移值
    //数值来源于OffsetBuf的0号元素，可以根据参数设置，是否使用整体的偏移值
    //X轴保存的是半径的值
    double ToolWorkOft[5];  

    //工件坐标系，界面设置数值，下电保存
    //第一维: 
    //0-5:G54-G59，其他备用  
    //
    //第二维: 0:X，1:Z，2:Y,3:4TH,4:5TH
    //X轴保存的是半径的值
    double G54G59[G54G59MaxNum][5];

    //正在使用的工件坐标系的值，是G54-G59的值加上总的坐标系偏移的值
    //在初始化阶段，根据G54G59的值计算得到
    //X轴保存的是半径的值
    double WorkCoordG54G59[5]; // 0:X  1:Z 
    
    // 0:X  1:Z  //外部工件偏移值，参考NumParabuf[ExtWorkOff_X + i]和ParseNumParabuf[ExtWorkOff_X + i]
    //界面直接设置
    //正在使用的值
    //X轴保存的是半径的值
    double ExtWorkCoordG54G59[5];

    //G50偏移值
    //通过G50指令设置，公式参考WorkCoordG50[0] = InterSegData[1].userCoordVal[0]-WorkCoordG54G59[0];
    //X轴保存的是半径的值
    double WorkCoordG50[5]; 

    /*
    用于语法分析的缓存值在初始化解释器环境时设置为各个值的系统当前值
    */
    /*
    用于语法分析中暂存偏置值。
    是OffsetBuf的副本，在初始化语法数据时copy于OffsetBuf，
    作用是在运行的过程中可以修改刀补值，但是新改的刀补值不生效   
    X轴保存的是半径的值
    */
    double ParseOffsetBuf[OftMaxNum][OftDimensionNum][2];   

    //用于语法分析中暂存工件坐标系
    //X轴保存的是半径的值
    double ParseG54G59[G54G59MaxNum][5];   

    //#变量保存的位置
    double ParseMacroBuf[MACRO_NUM];

    /*
    用于判断程序是否有M30，如果没有M30在程序结束的时候要做一次M30处理
    0表示没有M30
    在M代码指令中设置，如果有M30则=1
    在初始化解释器的时候应该设置为0
    */
    int HaveM30Flag;

    //记录不能与其他数据同段的M代码数量
    //M00/M01/M02/M30/M98/M99
    int McodeOnlyFlag;  
    
    /*
    在词法解析的大多数字母解析的时候置1
    初始化解释器环境时置0
    词法分析中，有除了MST之外的代码，用于判断是否要mst拆段
    */
    int HaveOtherCodeFlag;

    unsigned int NcodeTempFilePos[MaxNestingNum][99999][2];/* = { 0,0 };//用来在转移指令时联系N值和numCtrl的对应关系,子程序，行号，文件指针位置和N代码*/


    /*
    解释器的模态信息
    */
    struct temp_save_s temp_save;


    /*
    G7X的第一行标志位
    1表示已经读到了第一行
    0表示没有读到第一行
    只用于报警检测，如果有G7X的第一行，那么下一条如果不是第二行，则要报警
    读到第一行设置为1，
    如果发生报警设置为0
    如果未发生报警也设置为0，说明读到了第二行,或者没有第一行
    初始化解释器环境时设置为0
    */
    int G7x2AbsentFlag;


    /*
    词法分析数据缓存
    为了实现M代码拆分，把当前的词法分析数据先暂存到这，当希望执行拆分的M代码时，从这恢复
    */
    struct accidence_data_s accidence_data_cache;
    

    /*
    表示是否有M代码被拆分
    1：有
    0：没有
    在判断是否拆分时，如果拆分则设置为1
    执行完成被拆分的M代码后设置为0
    初始化解释器环境时设置为0
    */
    int have_m_code_split;   



    /*
    循环指令值
    表示当前执行的是哪个循环指令
    在读取到循环指令时设置为循环指令的值，例如71
    在循环指令的最后一个阶段设置为0
    在初始化解释器环境时设置为0
    */
    int G70CutLoop;

    /*
    循环指令预读完成信号
    用于判断是否执行循环指令的实际加工阶段，循环指令分为预读阶段和实际加工阶段
    1：完成，可以开始执行加工了
    0：未完成预读，还需要获取循环指令的参数或者型线轨迹

    在预读完成后置1
    在循环指令的最后一个阶段设置为0
    在初始化解释器环境时设置为0
    */
    int G9070CirParse;


    /*
    G70执行最后的一步，返回起始位置
    G70执行完型线之后置1
    初始化解释器环境时置0
    执行了G70最后一步后置0
    */
    int G70Initial;

    /*
    记录G71/72是否是2类型，预读G71/72时设置，如果是2类型则设置为1
    初始化解释器环境时置0
    */
    int gIsG71Type2Flg;
    int gIsG72Type2Flg;


    
    int G70Pno ;  // G71 到G73 保存的P值
    int G70Qno ;  // G71 到G73 的Q值.

    int G70TempPno;//G70的P Q值
    int G70TempQno;


    //固定循环(G33,G84,G88)状态 0:需词法分析，其它:不需要词法分析 0:无 1:处理中 2:完成
    int Hole_cycState;



    //存放拆分时的临时数据
    //0保存原始数据，
    // 1保存第二步执行的代码，可能是其他代码，也可能是特殊的M，
    // 2保存最后执行的数据，只可能是特殊的M代码
    struct accidence_data_s tmpAcciData[3];
};



struct CNC_CodeSegMent
{
    struct      accidence_data_s  ViewData;                   //为界面显示提供数据
    //struct      temp_save_s TmpModeData;              //保存语法分析中要用到的模态值
    //螺纹预留
    //struct      ThreadData    CThread;                     //螺纹加工数据

    /*
    -------------------------------------------NC程序相关，0表示主程序，其他表示子程序，最多嵌套5层
    */
    char file_name[MaxNestingNum][NAMELEN];/*打开的文件名，最多嵌套5层，文件名最多20个字符(子程序)*/

    /*
    file_line与lineno
    file_line是文件指针，不是行号，他的数值是按字符计算的，
    lineno是文件指针所在位置是文件的第几行，是行号
    */
    unsigned int  file_line[MaxNestingNum];/*保存每一个文件的文件指针，lseek,读到文件的哪个位置*/

    unsigned int lineno[MaxNestingNum];/*保存每一个文件读到哪行了，使用file_line太长了*/

    /*
    表示当前执行的是哪个程序，0表示主NC程序
    跳转到子程序或者返回上一层程序是会更改
    复位时应该置0
    执行时需要检查该值的合法性，不能大于嵌套的层数
    */    
    int file_p;

    int last_file_p;//当前打开的是哪个文件，用于判断是否需要重新打开文件
    /*
    -------------------------------------------NC程序相关，END
    */
    
    //段基本信息
    int Numctrl;//段号,显示用和控制用,它存储的是本程序段在文件中的偏移值，文件中的实际行号，0表示程序文件的第一行
    int Ncode;//显示用,N后的数字，并不是实际行号，仅仅用于显示
    int EOB;//data segment end,1:end , 0:no，1表示程序结束，0表示程序未结束 
    
//    char        ProgramEndMark;        //the program segment end,1:end,0:no 
    int           IsHaveSkipFlag;               //用于标识该段是否有跳段标志"/"    0:无 1:跳段未打开 2:已打开
    //M、S、T、F辅助指令
    char        IsHaveMCode;              //该段是否有M代码
    char        IsHaveSCode;               //该段是否有S代码
    char        IsHaveTCode;               //该段是否有T代码
    char        IsHaveFCode;               //该段是否有F代码    
    int           MCode;                            //M代码号
    int           McodeGroup[3];         //根据位参0338设置一段程序中可以指令的M代码(0:1个,1:最多三个)
    int           SCode;                             //该段中的S代码(档位控制)/(主轴速度)
    int           MaxSpindleSpeed;         //G96指定最大主轴速度
    int           G96Speed;                      //指定主轴速度    
    int           TCode;                            //刀号
    int           TOftNo;                           // 刀偏号 
    //刀具寿命管理
    char           TControl;   // 1:刀具寿命有效 0:刀具寿命无效
    int          TGroup;     //组号
    //int         TGrpIndex;   //组序号
    
    double         Feedrate;               //分进给速度
    double         FeedrateRev;        //转进给速度
    //从界面取的数值
    double         TCompLX;    //X轴长度补偿值
    double         TCompLY;    //Y轴长度补偿值
    double         TCompLZ;    //Z轴长度补偿值
    double         TCompR;     //用于刀补计算的刀补半径(无符号)
    double         TCutCompR;  //R半径补偿值(有符号值)
    int         TCompPointNO;  // 刀尖号
    //G指令，根据需要可增加
    char         G04Flag;//该段是否有暂停指令
    //char         G65Flag;//该段是否有宏指令   // G65直接在语法分析中计算和执行，只需要往下发送空段即可
    char         G50Flag;//该段是否有坐标系设定指令
    char          G27Flag;//该段是否有返回参考点检查指令
    char          G28Flag;//该段是否有返回参考点指令
    char          G29Flag;//该段是否有从参考点返回指令
    char          G30Flag;////该段是否有返回第2，3，4参考点指令
    char         G31Flag;//该段是否有测量功能指令
    char         G39Flag;//该段是否有拐角偏移圆弧插补指令
    char         G53Flag;//该段是否有选择机床坐标系指令
    
    char         IsSetCoordSelect;    //该段是否有坐标选择指令    
    char         IsSetG96G97Select;    //该段是否有恒表面切削速度控制指令
    char         IsSetG12Select;          //该段是否有行程检测功能指令G12
    
    char         IfHaveSetCRadiusComp;    //FALSE:刀补未建立，    TRUE:刀补已建立
    char         InterferenceCheckFlag;      //FALSE:不需要干涉检查，TRUE:需要干涉检查
    char         IfHaveInterferncecheck;     //FALSE:干涉检查未执行，TRUE:干涉检查已执行
    
    char         IsSetLCompSelect;        //该段是否有长度补偿指令
    char         CNCSegThreadFlag;            //刚性攻丝            
    char         SetSameCompType;     //执行刀尖定位

    int            InterpMoveSelect;//01组，G00,G01,G02,G03,G32,G34,插补运动
    int          ViewInterpMoveSelect;//G00,G01,G02,G03,G32,G34  +  G90,G92,G94,G70~G76
    int           InterpG96G97Select;//02组,    G96、G97,恒线和恒转速
    int           InterpG98G99Select;//03组，G98,G99，每分钟进给和每转进给
    int           InterpCoordSelect;//05组, G50,G54-----G59
    int           InterpG20G21Select;//06组,英制公制单位选择 (G20:英制  G21:公制)
    int           InterpRCompSelect;//07组,G40,G41,G42，刀具半径补偿
    int           TCutRCompSelect;  //G40 G41 G42,用于刀补判断
    int          InterpLCompSelect;//08组,G43,G44,G49，刀具长度补偿
    int          InterpScrewSelect;//09组,G84，轴向刚性攻丝,G80,G84,G88,G33,攻丝指令
    int         InterpG512G502Select;//04组,G512 G502双主轴耦合，轮切功能                 LZ ADD 20210617
    
    int         ThreadHeadNum;//螺纹切削
    int            ScrewFlag;    
    double      ScrewLead;
    double      toothNo;    
    double         ScrewTailJ;  // 螺纹短轴退尾
    double         ScrewTailK; // 螺纹长轴退尾
    double         ScrewAngle; //起始角度
    int          InterpMannerSelect;//14组,G61,G62,G63,G64        
    int          InterpPlaneSlect;//15组，G17,G18,G19，插补平面选择
    int          InterpG12G13Select;//16组, G12,G13，存储行程检测功能接通/断开
    
    //P,Q,H,D
    double P;
    double Q;
//    int H;                          //长度偏置号 用T代替
//    int D;                          //半径偏置号
    char IsSetP;    
    //坐标值，该段运行到的实际位置
    char IsSetX;    
    char IsSetY;    
    char IsSetZ;    
    char IsSetA;    
    char IsSetB;    
    char IsSetU;    
    char IsSetV;    
    char IsSetW;        
    char IsSetR;    
    char IsSetI;    
    char IsSetJ;    
    char IsSetK;    
    char IsSetL;
    char IsSetCA;
    char IsSetRA;
    char CanUse;    
    double X;            //机床坐标(ParseCutter()中转换)，如果有半径补偿,则半径补偿过
    double fParseX;      //绝对坐标，没有半径补偿和长度补偿
    double Y;
    double fParseY;
    double Z;
    double fParseZ;
    double A;
    double fParseA;
    double B;
    double fParseB;
    double BefComPos[5];  //机床坐标，进行了长度补偿，但没有半径补偿
    double R;
    double I;
    double J;
    double K;
    double CNCPause;
    double L;
    double   RA;  //倒圆角弦长
    double   CA;  //倒斜角长度
    double  G12SetVal[10]; 
    int G7xModifyParaFlag;
    double G7xNumPara[5];    
    //C 刀补用
    double Ox;
    double Oy;
    double Oz;    
    double Ptdu[5]; //预读并剔除冗余点后的插值节点增量的单位向量
    double Ptb[5];//各插值段起点切线方向的单位向量
    double Pte[5];//各插值段终点切线方向的单位向量。
    double Temp_R;        
    double EndSpeed;   //单段终点速度mm/min
    double CosAngle; //单位:弧度
    double Length;//单位:mm
    double EndPos[5]; // 0:X  1:Z  2:Y
    double Center[5];   // 轴排序为X,Z,Y. 圆心排序为IKJ
    //double userCoordVal[5];//存在的意义是防止运行过程中修改了坐标系的值
    
    /***************************added by lei 2017-02-17******************/
    char Polar;
    char Cylinder;
    double Cylinder_C;
    double Cylinder_AxisSavePos;
    double a;
    double b;
    double BJX_P;
    double BJX_Q;
    double TanVecter[5];
    /***************************added by lei 2017-02-17******************/
};


/*
刀长补偿坐标系补偿队列
*/
struct syntax_cut_queue_s
{
    struct CNC_CodeSegMent cut_data[SYNTAX_Q_NUM]; /*队列*/
    int start;
    int end;
    int num;
    int head, tail;
};




extern void init_decode(void);
extern int decode(void);

extern int shm_init(void);

extern char put_cut_queue(struct CNC_CodeSegMent* data);
extern char get_syntax_cut_queue(struct CNC_CodeSegMent* data);
extern int init_syntax_cut_queue();
extern char cut_queue_is_full(void);

extern int decode_reset(void);

extern int sync_motion_pos_to_decode(void);

#endif //__DECODE_H__





