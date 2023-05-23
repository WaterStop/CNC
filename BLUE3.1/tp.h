#ifndef TP_H
#define TP_H

#include "command.h"
#include "pos.h"

#define PI         3.1415926535897932
#define PI2        6.2831853071795864 // 2*PI






#define TC_GET_PROGRESS 0
#define TC_GET_STARTPOINT 1
#define TC_GET_ENDPOINT 2

typedef enum {
    TC_DIR_FORWARD = 0,
    TC_DIR_REVERSE
} tc_direction_t;

//主轴同步模式
typedef enum
{
    SPINDLE_SYNC_NONE=0,//G98
    SPINDLE_SYNC_VELOCITY,//G99
}SPINDLE_SYNC_TYPE_t;


//运动段的类型
typedef enum
{
    TC_TYPE_EMPTY=0,
    TC_TYPE_G0,
    TC_TYPE_G1,
    TC_TYPE_G2,
    TC_TYPE_G3,
    TC_TYPE_G28,//回零
    TC_TYPE_RIGIDTAP,//刚性攻丝
    TC_TYPE_SCREW,//螺纹
    TC_TYPE_MAC_HOME,//回机床零点
    TC_TYPE_PRO_HOME,//回程序零点
    TC_TYPE_MST,
    TC_TYPE_DONE,//NC程序结束标志
    

}TC_TYPE_t;



typedef enum {
    /*TP_ERR_INVALID = -9,
    TP_ERR_INPUT_TYPE = -8,
    TP_ERR_TOLERANCE = -7,
    TP_ERR_RADIUS_TOO_SMALL = -6,
    TP_ERR_GEOM = -5,
    TP_ERR_RANGE = -4,
    TP_ERR_MISSING_OUTPUT = -3,*/
    TP_ERR_MISSING_INPUT = -2,
    TP_ERR_FAIL = -1,
    TP_ERR_OK = 0,
    TP_ERR_WAITING,//等待
    TP_ERR_SLOWING,//减速
    TP_ERR_STOPPED,//停止
    TP_ERR_REVERSE_EMPTY,//不可以回退了
    TP_ERR_NO_ACTION,//没有移动，没有活动
    /*
    TP_ERR_ZERO_LENGTH,
    TP_ERR_LAST*/
} tp_err_t;









/*
单轴的
简单的
运动队列
*/
struct simple_tp_struct
{
    int moved;     /* non-zero if motion in progress *///表示是否有轴移动。0：没有，1有

    /* acceleration limit */
    //通过JOG命令设置
    //被钳位到axis->acc_limit和emcmotStatus->acc
    //多少个周期加速到最大速度
    double max_acc; 


    //使能状态，只有使能状态下规划出来的速度才不是0
    //失能状态下目标速度是0
    int enable;     /* if zero, motion stops ASAP *///as soon as possible  


    /*
    命令位置,目标位置
    */
    double pos_cmd;     /* position command */

    //各个轴的单轴队列的当前位置
    //同步电机编码器位置时，应当同步到电机位置
    //切换模式时，做同步
    //切换到手动时，应该用motion_internal->current_pos的值同步该值
    double current_pos;

    /* velocity limit */
    //这个速度没有方向，都是正数
    //通过JOG命令设置
    //被钳位到axis->vel_limit
    double max_vel;  

    /* current velocity */
    //有方向
    double curr_vel; 

};

//单轴的数据信息
struct axis_struct
{
    int head;
    int tail;


    struct simple_tp_struct tp;

    

    //各个轴的单轴队列的当前位置
    //同步电机编码器位置时，应当同步到电机位置
    //切换模式时，做同步
    //切换到手动时，应该用motion_internal->current_pos的值同步该值
    double current_pos;

    /* current velocity */
    //有方向
    double curr_vel;  


    //当前轴是否被激活，只有被激活的状态下才会计算位置，通过PLC的G信号设置激活状态
    //等同于轴选功能
    int active;


    /*
    命令位置,目标位置
    */
    double pos_cmd;     /* position command */
    
    /* velocity limit */
    //这个速度没有方向，都是正数
    //通过JOG命令设置
    //被钳位到axis->vel_limit
    double max_vel;   


    /* acceleration limit */
    //通过JOG命令设置
    //被钳位到axis->acc_limit和emcmotStatus->acc
    //多少个周期加速到最大速度
    double max_acc;     


    //使能状态，只有使能状态下规划出来的速度才不是0
    //失能状态下目标速度是0
    int enable;     /* if zero, motion stops ASAP *///as soon as possible   
    

      
    
    int moved;     /* non-zero if motion in progress *///表示是否有轴移动。0：没有，1有



    //单轴运动完成，通过轴选和速度同时判断
    //这个轴未被选，且这个轴的速度=0，则认为完成了
    //1：完成
    //0：未完成
    int done;

};





/*
直线数据结构
*/
struct line_s
{
    //起点坐标
    //在激活数据段时设置，
    //设置成当前坐标点
    double start[MAX_AXIS_NUM];

    
    //终点坐标
    //在生成直线运动段时设置，数据来自任务传下来的命令队列
    double end[MAX_AXIS_NUM];
    
    //各个向量的增量值/合成向量，向量在各个轴的投影
    //有正负
    //负数表示移动方向向负
    //有负数是原因是tp_line_update()函数计算出来的速度都是正数
    double u_vec[MAX_AXIS_NUM];

    //合成位移量
    //直线：平方和再开根号，合成位移量
    double tmag;

    //各个轴的位移量
    double object_s[MAX_AXIS_NUM];
};


struct circle_s
{
    //起点坐标
    //在激活数据段时设置，
    //设置成当前坐标点
    double start[MAX_AXIS_NUM];

    
    //终点坐标
    //在生成直线运动段时设置，数据来自任务传下来的命令队列
    double end[MAX_AXIS_NUM];

    //合成位移量
    //圆弧：圆弧的总弧长
    double tmag;

    //半径
    //在生成运动段信息时设置，数据来自任务传下来的命令队列
    double r;

    //圆心
    //在生成运动段信息时设置
    //数据来自于任务传下来的命令队列
    //也就是说，圆心由解释器计算，然后发下来    
    double center[MAX_AXIS_NUM];//0-X,1-Z,2-Y,3-4TH,4-5TH

    //起点向量和终点向量，相对坐标系的原点在圆心
    double start_p[MAX_AXIS_NUM];
    double end_p[MAX_AXIS_NUM];

    //总圆心角
    double angle;

    //相对坐标系的原点在圆心
    //相对坐标系的当前点位置，用于计算本周期的增量
    double current_pos_p[MAX_AXIS_NUM];
    
    
};


struct screw_s
{
    //起点坐标
    //在激活数据段时设置，
    //设置成当前坐标点
    double start[MAX_AXIS_NUM];
    
    //终点坐标
    //在生成直线运动段时设置，数据来自任务传下来的命令队列
    double end[MAX_AXIS_NUM];

    //合成位移量
    double tmag;

    int G34_flag;//表示G34变螺距螺纹，0表示G32

    int FeedDirectX,FeedDirectZ;
    double G32ScrewValue;//螺纹导程
    double G34ScrewValue;
    double G34TmpScrewValue;
    double acc;

    double angle;//起始角度
    double LongAxisLen, ShortAxisLen;     //长轴和短轴
    int CNC_ScrewInterpFlag;     //切削螺纹标志 1:发送主轴准停信号 2:等待主轴零点信号 3:等待主轴角度偏移 4:加工螺纹 5:退尾处理
    int ScrewSpindleOftNum ;     //由偏移角度算出的主轴编码器偏移数
    double LongExitTailLen, ShortExitTailLen;     //短轴和长轴的退尾量
    double ScrewSpeedRatio ;     //长短轴速度比
    double ScrewIncValR ;     //变距螺纹的增量值R
    double G34SumSp ;     //G34的主轴转过圈数
    double SumSpDelta ;     //螺纹加工，主轴转过的圈数
    int ScrewWaitTime ;     //螺纹等待时间
    char LongDecelerateFlag , ShortDecelerateFlag ;     //长短轴减速标志
    int LongDeceType ;     // 长轴减速类型　0:无　1:按一定加速度 2:变距减速
    char LongFirstIntoDeceFlag , ShortFirstIntoDeceFlag ;     //长短轴第一次进入减速标志
    double LongCurrentSpeed , ShortCurrentSpeed ;     // 长短轴当前速度
    double LongDeceAcc , ShortDeceAcc ;     // 长短轴的减加速度
    double ShortLinAcc ;     // 短轴退尾时的加速度
    char LongInterpCompleteFlag ;     //长轴插补完成标志
    char ShortInterpCompleteFlag ;     //短轴插补完成标志
    double SpidleRatioCoeff;     // 比例系数
    int ScrewSpeedArrive ;     // 速度是否到达当前主轴速度S*当前螺距值D
    char PreSegScrew ;     // 上段为螺纹插补
    char NextSegScrew ;     // 下段为螺纹插补
    double ScrewStartSpeed ;     // 螺纹长轴起始速度
    int ScrewAddSpeedN ;     // 螺纹加速周期
    double AddStartScrewVal ;     // 加速时的起始螺距
    double AddStartScrewR ;     // 起始螺距 加速时的变距R值
    double LongAxisEndSpeed ;     // 螺纹切削的长轴段尾速度
    int ContinueScrewType ;     // 连续螺纹类型 0: 无　1:锥度一样 2:锥度不一样 3:其它
    double ScrewAccSumSp ;     // 螺纹加速过程的主轴转动圈数
    double ScrewAccDistance ;     // 螺纹加速过程的加速距离
    double ScrewDecDistance[2];     // 螺纹快到终点时的减速距离 0:长轴的减速距离 1:短轴开始减速的长轴距离
    int ScrewDecN[2];     // 减速周期数  0:长轴的减速周期数 1:短轴的减速周期数
    double NextG32RValue;     // 下段螺纹　增量值R
    double NextScrewSpeedRatio;     // 下段螺纹速度比例
    int NextShortFeedDirect ;
    int StartSampSpindleSpeed ;     // 开始采样主轴速度
    double DgnScrewAccSpPos;     // 诊断　加速完时主轴的位置
    double DgnScrewAccZPos;     // 诊断　　加速完时长轴的位置
    int DgnScrewStartSpPos;     // 诊断 主轴起始位置(与零点的偏差值)
    int DgnScrewMinStartSpPos ;     //主轴最小起始位置(与零点的偏差值)
    int DgnScrewMaxStartSpPos ;     //主轴最大起始位置(与零点的偏差值)
    double DgnScrewMinWaveVal ;     // 10000
    double DgnScrewMaxWaveVal ;     //
    //-----------------------------------------------------------------//
    int ScrewInsertSegFlag ;     // 插入段标志
    double LinkSegLongStartDis ;     // 进入插入段的剩余距离
    double LinkSegStartPos[2] ;     // 连续螺纹插入段的起点
    double LinkSegEndPos[2] ;     // 连续螺纹插入段的终点
    double LinkSegCurSp ;     // 插入段过程中的主轴位置
    double LinkSegSumSp ;     // 插入段过程中的主轴总移动量
    double SumSpShortLinkSeg[2] ;     // 0:圴速区　1:变速区
    double SumSpLongLinkSeg[2] ;
    double LinkSegShortRVal ;     // 短轴增量值R
    double LinkSegLongRVal ;     // 长轴增量值R
    double LinkSegShortScrew[2] ;     //短轴起始和终点螺距
    double LinkSegLongScrew[2] ;     //长轴起始和终点螺距
    double FirstLinkSegSpSpeed ;
    double PreAccSpPos[2] ;     // 0:短轴在变速时的主轴位置 1:长轴在变速时的主轴位置
    double ObjectSpeed;


    int Dec_ovrd_cofe;//减速标志位，0表示减速，1表示不减速

    double StepCoefficientX;
    double StepCoefficientZ;
};




struct tc_struct 
{
    /*******************************************需要从运动队列中获取的数据*************************************************************/
    /*
    本运动段是什么类型的段
    */
    TC_TYPE_t tc_type;

    struct mst_data_s mst;

    /*
    主轴同步模式，G98/G99
    */
    SPINDLE_SYNC_TYPE_t spindle_sync;

    /*
    ID号    
    */
    int id;

    /*
    子ID号，只用于G7X等循环，标记子段    
    */
    int sub_id;

    
    /*
    保存运动段的模态信息，
    来自任务发送过来的运动段
    在激活段时，传递给TP,方便界面显示
    */
    struct state_tag_s tag;

    /*
    目标速度
    F值，不论是G99还是G98模式，都用这一个F值
    */
    double cmd_f;

    /*
    最大的速度
    */
    double maxvel;

    /*
    最大加速度
    */
    double maxacc;
    
    /*******************************************需要从运动队列中获取的数据end*************************************************************/


    /*******************************************执行过程中的状态信息*************************************************************/
    /*
    删除标记
    段完成后，回设置该标志位为1
    在自动的结尾，判断如果是1，就执行段结束处理
    */
    int remove;

    /*
    当前速度,合成速度
    本周期速度值
    设置为0.0：
        添加运动段时设置为0
        运动段完成处理时设置为0

    使用：
        aborting时，判断速度是否为0，不为零需要继续减速到0
        更新运动状态时赋值给motion_status->current_vel

    计算：
        计算插补点时计算，
        G0根据各个轴的速度分量计算出一个合成速度
        G1直接用该值计算，每周期根据剩余距离和加速度计算出一个新的速度
    */
    double current_vel;

    /*
    当前速度,单轴速度,主要用于G0
    本周期速度值
    */
    double alone_axis_current_vel[MAX_AXIS_NUM];

    /*
    激活标志
    数据段预处理时判断和设置
    如果未激活，则开始激活操作，然后设置为已激活
    在数据段完成处理时，设置成0，为了回退做准备
    */
    int active;


    /*
    直线数据
    */
    struct line_s line;


    /*
    圆弧数据
    */
    struct circle_s circle;

    /*
    螺纹数据
    */
    struct screw_s screw;  

    /*
    当前位置，是合成距离，所以是一个double类型
    范围：0.0 ~ target
    */
    double progress;

    /*
    当前位置，单轴位置，主要用于G0
    在tp_g0_update()函数中做为参数传进去，然后在函数内部更改数值
    范围：0.0 ~ endpos
    在添加运动段时设置为0.0
    */
    double alone_axis_current_pos[MAX_AXIS_NUM];

    /*
    合成位移量，所以是一个double数据，在运动段激活时设置。
    */
    double target;

    /*
    请求速度，是合成速度，如果是G0，是各个轴的参数设定值合成速度，否则是F设定值
    */
    double reqvel;

    

    

    /*******************************************执行过程中的状态信息end*************************************************************/
    
};


/*
运动段队列
解释器添加数据
运动模块取数据
*/
struct tcq_struct 
{
    struct tc_struct queue[TCQ_NUM];   /* ptr to the tcs */
    int _len;           /* number of tcs now in queue */
    int _rlen;          /* number of tcs now in reverse history  */
    int start, end;     /* indices to next to get, next to put */
    int rend;           /* 回退终点*/
    int size;
};

/*
螺纹数据
*/
struct  screw_data_s
{
    int ThreadLongFlag;//长轴标志，表示哪个轴是长轴，0:X轴 1:Z轴
};

//联动轨迹规划器
//内部的变量都需要通过函数设置，不可以直接设置
struct tp_struct
{
    int head;
    int tail;

    /*
    运动段队列
    */
    struct tcq_struct queue;


    /*
    当前执行的段的类型，TC_TYPE_枚举类型，G0/G1/G2/G3/MST/空段/攻丝等
    在段激活时(MST/空段)或者计算插补点时(运动段)赋值
    目前用于界面显示
    */
    int motion_type;

    /*
    轨迹规划器的执行方向，    正向或负向
    负向用于手轮试切回退。
    影响下一段运动段的获取方向、    终点位置计算、剩余移动量计算
    通过由任务模块设置，通过设置一个共享内存变量，然后在process_input()函数根据标志位设置这个变量
    1：负方向
    0：正方向
    */
    int reverse_run;

    /*
    执行的ID号    
    */
    int exec_id;

    /*
    执行的子ID号，只用于G7X等循环，标记子段    
    */
    int exec_sub_id;

    /*
    NC程序完成标志
    表示这个NC程序结束了
    1：完成，0：未完成
    用于：
        读到空段时，判断如果已经结尾了，就做收尾处理
    设置为0：
        添加运动段时设置为0
        初始化TP时，要设置0
        处理完一次收尾动作后设置0，立即等待新的段开始
    设置为1：
        abort时设置为1
        当读到运动段的类型是完成时，设置这个标志位
    */    
    int nc_done;


    /*
    当前运动段完成标志
    用于模式切换时判断自动是否在运行
    运动段处理完成时设置为1，
    初始化运动成功后设置为0
    */
    int done;

       


    /*
    用于：
        1、计算倍率，如果是aborting，获取进给倍率返回0.0
        2、处于aborting状态不能向运动队列添加段
        3、每个运动计算之前都判断这个标志位，如果速度同时为0，说明已经减速停止了，则初始化运动队列和TP。（tp_handle_abort()函数）
    设置0：
        1、处理NC程序结束时，设置为0
        2、自动循环中，处理aborting标志位时，处理完成aborting后设置为0,(只处理一次aborting)
        3、初始化TP时设置为0
    设置1：
        1、判断队列参数有问题，设置为1
        2、process_input()中，任务控制设置为1，
        3、根据报警状态设置为1
    */
    int aborting;


    /*
    用于：
        1、判断倍率，如果是aborting，获取进给倍率返回0.0
    设置0：
        1、处理NC程序结束时，设置为0
        2、初始化TP时设置为0
        3、process_input()中，任务控制设置为0
        4、处理abort操作时设置为0
    设置1：
        1、判断队列参数有问题，设置为1
        2、process_input()中，任务控制设置为1
        4、设置aborting时同时设置为1

    备注：单段是不需要控制这个标志位，单段后会清空运动队列，然后解释器一行一行解析，所以不需要设置，程序依然能会停住
    */    
    int pausing;



    /*
    程序零点坐标
    NC程序通过G50设置
    任务通过共享内存设置motion_status中的值，然后运动在process_input()函数中处理值和标志位
    */
    //double pro_zero_pos[MAX_AXIS_NUM];



    /*
    当前位置
    轨迹规划器的当前位置
    更新规则：
    1、每周期计算完新的插补点后更新
    2、同步机床坐标时同步    
    */
    double current_pos[MAX_AXIS_NUM];



    /*
    保存运动段的模态信息，
    来自任务发送过来的运动段
    在激活段时，传递给TP,方便界面显示
    */
    struct state_tag_s exec_tag;


    /*
    本周期的主轴反馈速度，转/分
    计算G99转进给模式下的进给轴速度
    在process_input()函数中更新，只在自动模式下更新即可
    */
    double spindle_speed_back;

    /*
    螺纹数据
    */
    struct  screw_data_s screw_data;



    //-----------------------------------------------------------------------以下为诊断数据用的变量
    double start_pos[MAX_AXIS_NUM];
    double end_pos[MAX_AXIS_NUM];
    double befor_pos[MAX_AXIS_NUM];
    //命令值的增量g0
    double cmd_delta[MAX_AXIS_NUM];
    //本周期计算出来的增量值    
    double current_delta[MAX_AXIS_NUM];
    //目标速度
    double v_target[MAX_AXIS_NUM];

    //当前各个轴的速度
    double v_current[MAX_AXIS_NUM];

    //剩余距离，G1
    double dx;//G1的剩余距离
    double g1_v_target;//G1的目标速度
    double g1_cur_v;//G1的当前速度
    double progress;//G1的当前位置


    //G2G3
    double start_pos_p[MAX_AXIS_NUM];
    double end_pos_p[MAX_AXIS_NUM];
    double center[MAX_AXIS_NUM];
    double ren[MAX_AXIS_NUM];
    double g2g3_v_target;//G2g3的目标速度
    double g2g3_cur_v;
    double angle;

    
};



extern tp_err_t auto_tp(struct tp_struct * tp);

extern void simple_tp_update(struct simple_tp_struct * tp);
extern void hand_tp(int axis_num);
extern int tp_add_line(struct tp_struct * tp,//轨迹规划器指针
                     double * cmd_pos,//目标位置，终点位置
                     TC_TYPE_t type,//运动段类型，这个函数只支持G0/G1
                     SPINDLE_SYNC_TYPE_t sync,//主轴同步模式，G98/G99
                     int id,
                     int sub_id,
                     struct state_tag_s tag,//运动段模态信息
                     double f_value,//进给倍率F值
                     double max_vel,//最大速度
                     double max_acc//最大加速度
                     );
extern int tp_add_cycle(struct tp_struct * tp,//轨迹规划器指针
                      double * cmd_pos,//目标位置，终点位置
                      double * center,//圆心位置
                      double r,//半径
                      TC_TYPE_t type,//运动段类型，这个函数只支持G2/G3
                      SPINDLE_SYNC_TYPE_t sync,//主轴同步模式，G98/G99
                      int id,
                      int sub_id,
                      struct state_tag_s tag,//运动段模态信息
                      double f_value,//进给倍率F值
                      double max_vel,//最大速度
                      double max_acc//最大加速度
                      );      

extern int tp_add_screw(struct tp_struct * tp,//轨迹规划器指针
                      double * cmd_pos,//目标位置，终点位置
                      double screw_lead,//螺纹导程
                      double short_tail,//短轴退尾长度
                      double long_tail,//长轴退尾长度
                      double angle,//起始角度
                      int G34_flag,// 1:表示是G34变螺距螺纹，0表示是G32正常螺纹
                      double inc_val_r,//螺距变化量
                      TC_TYPE_t type,//运动段类型，     TC_TYPE_SCREW             
                      int id,
                      int sub_id,
                      struct state_tag_s tag//运动段模态信息
                      ) ;                    

extern int tp_add_empty(struct tp_struct * tp,//轨迹规划器指针
                    int id,
                    int sub_id,
                    struct state_tag_s tag//运动段模态信息
                    );

extern int tp_add_mst(struct tp_struct * tp,//轨迹规划器指针
                    struct mst_data_s mst_data,
                    int id,
                    int sub_id,
                    struct state_tag_s tag//运动段模态信息
                    );
                    
extern void tp_calculate_trapezoidal_accel();
extern void tp_calculate_s_accel();
extern int tp_set_tp_current_pos(struct tp_struct * tp,double *pos);
extern int tp_init(struct tp_struct *  tp);
extern int tp_simple_tp_init(struct simple_tp_struct * tp);
extern int tp_axis_init(struct axis_struct * axis,double current_pos);
extern int tp_set_run_dir(struct tp_struct *  tp, tc_direction_t dir);
extern int tp_resume(struct tp_struct *  tp);

extern void tp_set_axis_active(int axis_num,int val);
extern int tp_can_hand_axis(int axis,int dir);

extern tp_err_t hand_wheel_tp(int i);
extern void clear_hand_wheel_surplus_length(void);
extern int calc_wheel_delta(unsigned short enc_input,int axis);
extern void init_wheel_info_struct(void);
extern void hand_wheel_delta_resource(void);
extern unsigned short read_hand_wheelor_code_val(int hardware, unsigned short CurVal);




#endif

