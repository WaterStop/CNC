
#ifndef MOTION_H
#define MOTION_H


#include "tp.h"
#include "plc.h"
#include "pos.h"
#include <stdio.h>
#include "error.h"


#define MAX_MIII_ST 10//MIII从站最大数量




#define MINIM           0.000001
#define Minim 0.000001


#define SERVO_PERIOD 0.00003333333333 //  2/1000/60

#define CNC_PULSE  1000.0  //设置电机螺距的时候乘了1000，所以在计算的时候应该除1000

#define RevJingDu 10000//计算浮点型时控制精度用的 
#define JingDu 0.0001

extern struct motion_status_struct *motion_status;
extern struct motion_err_struct *motion_err;
extern struct motion_err_struct *motion_warn;
extern struct motion_internal_struct *motion_internal;
extern struct plc_shm_s *plc_shm;





#define TINY_DP(max_acc,period) (max_acc*period*period*0.001)

//#define get_axis_pos_override_limit_mask(axis_num) (motion_status->override_limit_mask & ( 2 << (axis_num*2)))
//#define get_axis_neg_override_limit_mask(axis_num) (motion_status->override_limit_mask & ( 1 << (axis_num*2)))
//
//#define set_axis_pos_override_limit_mask(axis_num) (motion_status->override_limit_mask | ( 2 << (axis_num*2)))
//#define set_axis_neg_override_limit_mask(axis_num) (motion_status->override_limit_mask | ( 1 << (axis_num*2)))

//#define isnan(v) _isnan(v)



#define AutoManner                        0//自动方式标志
#define EditManner                         1//编辑方式标志
#define HandManner                       2//手动方式标志
#define HandWheelManner              3//手轮方式标志
#define StepManner                        4//单步方式标志
#define InputManner                       5//录入方式标志
#define ManchineZeroManner          6//机械回零方式标志
#define DNCManner                         7//DNC方式标志
#define ProgramZeroManner            8 // 回零方式标志



#define MCodeNull                    0xFF
#define SCodeNull                    0xFF
#define TCodeNull                    0xFF

#define MCodeStep_Init           0x00
#define MCodeStep_Start         0x01
#define MCodeStep_End           0x02

#define SCodeStep_Init           0x00
#define SCodeStep_Start         0x01
#define SCodeStep_End           0x02

#define TCodeStep_Init           0x00
#define TCodeStep_Start         0x01
#define TCodeStep_End           0x02


/*
运动模块的模式
目前支持3中模式：自动、手动、手轮
其他的模式不在运动做区分，在任务层做区分，
*/
typedef enum {
    RUN_STYLE_AUTO=0,//自动
      
    RUN_STYLE_HAND,//手动
    RUN_STYLE_HAND_WHEEL,//手轮

    /*
    运动不区分MDI和自动，所以只用自动一种模式即可
    MDI和自动由任务的解释器区分
    只要进入自动模式，运动就一直尝试从运动队列中读取运动段
    如果运动段读取失败，则不移动轴，做响应的失败处理
    如果读取成功，则开始按照运动段做计算
    */
    RUN_STYLE_MDI,//MDI/录入


    /*
    如果是编辑模式，运动不执行任何操作
    可以做成自动模式，由任务区分编辑和自动，编辑模式不向运动队列中发数据
    */
    RUN_STYLE_EDIT,//编辑  


    
    /*
    因为要处理G28指令，所以把回机械零点并入自动模式
    自动模式从运动队列中取数据，发现是回零指令，则按照指令指定的轴开始回零    
    */
    RUN_STYLE_MAC_ZERO,//回机械零点

    /*
    回到G50设置的程序零点位置
    例：G50X10Z10,回程序零点后，会走到绝对坐标X10,Z10的位置
    例：G50X0Z0,回程序零点后，会走到绝对坐标X0,Z0的位置
    G50设置的程序零点下电不记忆
    如果未设置程序零点，执行回程序零点动作后会报警

    不使用这个模式，用自动模式替代，解释器判断如果是程序零点模式，
    直接给运动发送直线运动段即可，如果未设置G50，任务模块报警
    */
    RUN_STYLE_PRO_ZERO,//回程序零点
} run_style_t;


typedef enum {
    AXIS_X=0,
    AXIS_Z,
    AXIS_Y,
    AXIS_4,
    AXIS_5,
    SPINDLE1,
    SPINDLE2,
} AXIS_t;










struct pulse_s
{
    int x,y,z;    
    int axis4,axis5;
    int s1,s2;//s1-主轴1，s2-主轴2
};



/* 
反向间隙结构体
*/
struct reverse_clearance_s
{
    double clearance_value[MAX_AXIS_NUM];//计算得到的反向间隙值，要累加到当前位置上，得到反向间隙后的值
    int revers_direct[MAX_AXIS_NUM];//保存上一次的移动方向
};



struct wheel_info_struct 
{
    double surplus_length;//剩余长度
    int have_wheel_turn;//0-手轮没有移动量，1-手轮有移动量
    int wheel_done;//手轮执行完成 
    int wheel_delta;//手轮本周期移动格数
    int soft_limit_release;//超软限后反向移动标志
    int hard_limit_release;//超硬限后反向移动标志，可以反向移动,1-表示正在反向移动
    double min_acc_dec;//最小加减速
    double max_speed;//最大速度
    int index_latter_acc_time;//指数后加减速时间
    int init_flag;//0-未进行初始化，1-已经初始化
    int last_hand_wheel_val;//上一周期手轮的值，硬件传上来的值，用于计算本周期的增量

    /*
    首次切换到手轮模式，需要同步一次last_hand_wheel_val值，用这个变量记录是否已经同步过了手轮的值，

    置0的操作
    上电默认是0，表示没有同步过，所以第一次会做同步处理
    复位后设置为0，表示复位后需要同步手轮的值
    切换到手轮模式时需要同步

    置1的操作
    同步完成后置1
    */
    int already_sync_hardware_val;
    
};

struct spin_data_s
{
    //是否开始检测MARK信号的标记位
    unsigned long latchFlag ;
    
    unsigned short SPZPulseEnb;//本地第一主轴Z脉冲使能信号 //LZ 20210629新版本硬件第二主轴使用变量的第二位，第一主轴使用变量的第一位
    
    char SPZPulseSignal ;// 主轴Z脉冲信号
    
    int SpindZeroPos ;// 主轴Z脉冲时的编码值
    
    unsigned short SPZPulseSign;//本地第一主轴Z信号输入状态
    
    unsigned short spinEncInput ;//主轴编码器输入脉冲数

    int LastSpindSpeed[9];//上一次的主轴速度

    double SpindleCoderNum;// 时间(ms)与编码器线数的比值

    double spinAcuRev ;//hanwenye add 主轴从Z信号位置开始记录的主轴脉冲计数，用于计算主轴实际位置
    
    double SpindScaleIncVal ;//主轴编码器每个周期的刻度增量

    double ObjectSpindleSpeed  ;//采样200ms得到的速度G32G34时使用

    long CNC_Sspeed ;//主轴转速，8次采样滤波后的速度

    double SpidleGearRatio ;//主轴电子齿轮比

    double SpindleSampSpeed;//插补采样速度    

    double spindle_scale;//主轴倍率，由PLC的G信号设置

    int  CncViewSSpeed;//显示用的转速，滤波周期更大
    
    //主轴当前挡位，在输入函数中设置，根据G信号确定，在计算主轴电子齿轮比时使用
    //0表示1挡
    //7表示8裆
    //最大是8档
    //计算主轴输出使用
    int spind_gear;

    /*
    主轴的电子齿轮比，诊断用
    */
    double spindle_cmr_divd_cmd;

    //主轴的位置反馈
    double spind_pos_fb;

    /*
    主轴速度控制，在输入函数中根据PLC的G信号设置值
    在输出函数中使用，判断是否输出主轴转速
    -1：反转
    0：停止
    1：正转
    */
    int spind_speed_ctrl;

    /*
    主轴当前的模式，
        0：速度模式，
        1：位置模式
    切换方式，
    上电默认是速度模式，切换完成CS轴后，切换到位置模式，
    关闭CS轴后切换到速度模式
    */    
    int spind_mode;

    
    //设定的主轴S值，上电有一个默认的速度，之后通过任务命令生成的运动段更改，等于NC程序中的S值
    //在自动模式下处理运动段时处理到S指令后更改
    double spind_speed_set;

    /*
    由spind_speed_set和主轴倍率计算出来的脉冲数
    用法：如果主轴是速度模式，则判断PLC的主轴相关的G信号，如果G信号有，直接把这个值发给驱动，让主轴转，否则发0

    同时也是位置模式下的主轴位置脉冲数，位置模式具体做法再考虑
    */
    double spind_speed_pulse;
    
    //通过处理任务命令队列时修改
    //int spind_g98g99;//0-g98分进给，1-g99转进给

    //通过处理任务命令队列时修改
    //int spind_g97g96;//0-g97分进给，1-g96转进给

};




//运动内部使用变量
//不在共享内存中、只有运动自身使用，其他模块不可访问
struct motion_internal_struct
{
    int head;
    int tail;

    //联动插补轨迹规划器
    struct tp_struct coord_tp;

    //单轴数据结构
    struct axis_struct axis[MAX_AXIS_NUM];

    /*
    各个模式下计算出来的插补点数据
    螺距补偿前的值
    */    
    double current_pos[MAX_AXIS_NUM];//各个轴本周期计算后的插补位置

    //反向间隙和螺距补偿之后的位置值
    //由motion_internal_struct.current_pos经过螺距补偿和反向间隙补偿后得到
    double target_pos[MAX_AXIS_NUM];

    double spind_current_pos[MAX_SPIND_NUM];//主轴本周期的位置


    /*
    主轴是速度值
    如果是总线主轴，此值就是速度对应的脉冲数
    如果是模拟量主轴，此值就是对应的DA值(0-8192 对应 0-10V)
    */
    double spind_current_v_pulse[MAX_SPIND_NUM];

    struct wheel_info_struct wheel_info[MAX_AXIS_NUM];//0-X,1-Z

    //回零
    struct axis_struct home[MAX_AXIS_NUM];

    
    struct  reverse_clearance_s reverse;

    struct spin_data_s spin_data[MAX_SPIND_NUM];
};


//运动的当前状态
//放到共享内存中，与其他模块交互
//其他进程读写其中的变量
struct motion_status_struct
{
    int head;
    int tail;

    /*
    ------------------------------------------------------系统状态------------------------------------------------------
    */
    //非零表示有急停
    int emergency;//emergency stop 

    //需要在运动停止时执行复位操作
    // 1-表示需要处理
    // 0-表示不需要处理
    //在复位操作中设置，如果当前系统是运行状态下按的复位，则设置此标志位为1
    //在复位的设置此标志位判断之前设置为0，表示每一次复位都清除一次标志位?
    //在处理完成此操作后设置为0
    int need_movement_reset;

    int alarm;

    //系统当前的运行模式,由模式切换函数更改数值
    int run_style;
    
    //系统下一步规划切换到哪种模式，由命令处理函数处理任务-运动命令队列时更改
    int next_run_style; 

    int is_van;// 1:空运行状态，0：非空运行状态，由命令处理函数处理任务-运动命令队列时更改

    int is_machine_lock;// 1:机床锁锁住状态，0：不锁，由命令处理函数处理任务-运动命令队列时更改

    //进入过机床锁的分支中，最终的输出没有输出到伺服，
    //会导致伺服的脉冲数与运动的脉冲数差距很大
    //所以机床锁之后应该同步一次伺服位置
    //进入机床锁状态后置1，同步位置后置0
    int in_machine_lock;

    // 1:开启辅助锁状态 0：非辅助锁状态
    //辅助锁如果是开启状态，运动在处理MST时，直接完成，不需要发送给PLC
    int is_aux_lock; 

     
    // 1:开启单段状态 0：非单段状态
    int is_step;



      

    //0:未开启手轮试切
    // 1：开启手轮试切
    //通过操作站的按钮触发PLC设置手轮试切G信号
    //任务模块判断G信号，然后控制这个标志位
    //由命令处理函数处理任务-运动命令队列时更改
    int is_wheel_cut;

    
    //硬限位状态，在检查错误函数（check_for_faults）中，判断PLC的G信号决定是否置位
    /* 1 << (axis-num*2) = neg limit */
    /* 2 << (axis-num*2) = pos limit */
    int hard_limit;

    /* 1 << (axis-num*2) = neg limit */
    /* 2 << (axis-num*2) = pos limit */
    int soft_limit;
    
    //限位忽略标志位,1:忽略硬限位和软限位报警，0:不忽略，由命令处理函数处理任务-运动命令队列时更改
    int override_limit_mask;  

    
    //至少读取了一次MIII从站编码器的值，更新了坐标
    //认为系统上电后，首次读取过电机编码器后，伺服就准备好了
    //MIII总线形式的进给轴，读取编码器后就同步了电机编码器的位置
    //运动计算出来的值才是正确的脉冲值
    int enc_is_read_done[MAX_MIII_ST];
    
    /*
    是否正在执行标志
    在process_output()函数中更新
    通过判断速度确认是否有手动或者手轮在执行
    通过判断联动轨迹规划器，判断自动是否在执行
    不要忘了判断回零的状态
    1:正在执行，0未运行
    */
    int is_moving;

    
    //所有的有编码器的从站都读过一次编码器值(同步过一次坐标)后，就可以往伺服队列中存放数据了
    int servo_is_ready;
    

    /*
    运动模块复位处理完成标志，
    */
    int motion_reset_done;

    /*
    自动运行队列饥饿标志位
    可以表示运动段的状态，用于与解释器同步
    在自动中，如果读取运动段失败，则设置为1；
    如果成功，则设置为0
    复位时要设置为1
    初始化时设置为1
    */
    int motion_hungry;



    /*
    当前的刀具号
    如果参数配置的刀号小于2，表示是排刀，这个变量在处理T代码的时候赋值
    否则这个参数在每个周期刷新，读取PLC参数
    */
    int CurTCode;

    //表示MST发送给PLC的状态，0-M,1-S,2-T
    
    int MSTCode2PLC[3];

    
    /*
    ------------------------------------------------------进给轴相关------------------------------------------------------
    */
    int is_fast_feed;// 1:快移开关已经打开，0：快移开关未打开

    double feed_scale;//进给倍率，由PLC的G信号设置

    double fast_scale;//G0倍率、快移倍率，由PLC的G信号设置

    double hand_wheel_step_length;//手轮的步长，*1 *10 *100 *1000

    double feed_acc[MAX_AXIS_NUM];////各个轴JOG和FEED对应的加速度,单位:MM/MIN2，由FEED_ACC_PERIOD参数计算得到
    double fast_acc[MAX_AXIS_NUM];////各个轴快移对应的加速度,单位:MM/MIN2，由FAST_ACC_PERIOD参数计算得到
    double axis_max_acc[MAX_AXIS_NUM];////各个进给轴的最大加速度限制,单位:MM/MIN2，由AXIS_MAX_ACC_PERIOD参数计算得到
    double max_acc;//所有进给轴的加速度上限,单位:MM/MIN2，由MAX_ACC_PERIOD参数计算得到    
    
    double cmr_divd_cmd[MAX_AXIS_NUM];//电机编码器值/(螺距*1000),计算方法：AXIS_CMR[I]/AXIS_CMD[I]
    
    //轴的位置反馈
    //如果是MIII总线，这个值应该在process_input中，被赋值为mlinkMonitor[i].fback_pos
    //如果是其他总线或脉冲轴，这个值要单独设置
    double axis_pos_fb[MAX_AXIS_NUM];

    // 1:同步电机编码器的值,0:不需要同步
    //上电应该初始化成1，默认上电需要同步一次
    char need_read_enc[MAX_AXIS_NUM];
    
    //编码器已经准备好数据，可以同步了
    char enc_is_ready[MAX_AXIS_NUM];

    //等于motion_internal->pos的值，为了给界面显示使用
    //反向间隙和螺距补偿之前的位置
    double pos[MAX_AXIS_NUM];//各个轴本周期计算后的插补位置

    //等于motion_internal->pulsed的值，为了给界面诊断使用
    double pulse[MAX_AXIS_NUM];//发送给伺服队列的脉冲数值，由struct axis_pose pos计算得到

    
    //各个进给轴反馈的脉冲数
    //电机编码器反馈的原始值
    double pos_fb[MAX_AXIS_NUM];

    //发送给伺服队列的脉冲数值，由motion_internal->target_pos计算得到
    //在caculate_pulse_and_add_data()函数中直接赋值给队列消息
    //主轴如果是位置模式，应该在caculate_pulse_and_add_data()中计算脉冲数
    struct pulse_s current_pulse;
    
    /*
    目标速度，合成速度
    */
    double requested_vel;

    /*
    当前速度，合成速度
    */
    double current_vel;


    /*
    各个轴的剩余距离
    */
    double dtg[MAX_AXIS_NUM];

    /*
    手轮的轴选信号,由PLC信号控制，再process_input中读取PLC信号 
    0-表示选择了X轴
    1-Z
    2-Y
    3-4TH
    4-5TH
    */
    int select_axis;

    //通过处理任务命令队列时修改
    int spind_g98g99;//0-g98分进给，1-g99转进给

    //通过处理任务命令队列时修改
    int spind_g97g96;//0-g97分进给，1-g96转进给
    
    /*
    ------------------------------------------------------主轴相关------------------------------------------------------
    */
    
    
    /*
    ------------------------------------------------------总线相关------------------------------------------------------
    */
    /*
    开始总线通讯标志位
    作用是在启动完所有模块，系统进入稳定状态后，由任务模块发送开始通讯命令，设置这个标志位，
    然后在M3通讯中才能执行通讯流程
    否则M3在处理状态机时直接退出
    */
    int start_bus_flag;

    int axis_to_st[MAX_AXIS_NUM];//实现通过轴号快速找到从站号，根据参数计算得到

    int spind_to_st[MAX_SPIND_NUM];//实现通过轴号快速找到从站号，根据参数计算得到



    /*
    ------------------------------------------------------IO数据------------------------------------------------------
    */
    unsigned short local_data[100];

    unsigned short encode_input_mpg;//MPG手轮输入，从硬件读上来的值，做了对4取余的操作
    unsigned short encode_input_local;//本地手轮
    unsigned short encode_input_aux;//附件面板手轮
    unsigned short encode_input_spindle1;//本地主轴1编码器
    unsigned short encode_input_spindle2;//本地主轴2编码器



    /*
    ------------------------------------------------------回零------------------------------------------------------
    */
    //回零标志位:是否已经回零.(各个轴单独设置)  
    int machine_zero_done_flag[MAX_AXIS_NUM];//0未完成,1完成

    //回零状态机,标志回零阶段(各个轴单独设置)  
    int machine_zero_state[MAX_AXIS_NUM];

    double abs_enc_offset[MAX_AXIS_NUM];//绝对编码器零点偏移值，回零的时候设置成当前的编码器值，需要下电保存
    
    /*
    ------------------------------------------------------诊断用数据------------------------------------------------------
    */

    //给伺服队列发送数据的次数    
    int  put_servo_num;

    //从伺服队列拿走的数据的次数
    int  get_servo_num;


    //手动插补进入速度计算的次数
    int in_hand_axis_enable_num[MAX_AXIS_NUM];


};


#define SET_MOVING_FLAG(axis_num,fl) if (fl) motion_status->is_moving |= (1<<axis_num); else  (motion_status)->is_moving &= ~(1<<axis_num);
#define GET_MOVING_FLAG(axis_num) (motion_status->is_moving & (1<<axis_num) ? 1 : 0)
//#define GET_MOVING_FLAG(axis_num) (motion_status->is_moving & (1<<axis_num) ? 1 : 0)




extern void Interp_Task1(void *prio) ;
extern int init_motion(void);
extern int get_limit(int   val,int axis);
extern void handle_reset(void);
extern void handle_reset_during_movement(void);

extern void MeasureAxisSpeed(void); //主轴转速测量

extern void stop_now(void);

#endif//MOTION_H
