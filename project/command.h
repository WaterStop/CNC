
#ifndef COMMAND_H
#define COMMAND_H

#include "config.h"


extern struct command_queue_s * command_q;
extern struct task_command_queue_s * task_command_q;

extern struct command_queue_s *wait_q;

//运动段的类型
typedef enum
{
    /*
    运动段命令
    */
    COMMAND_EMPTY=0,
    COMMAND_G0,
    COMMAND_G1,
    COMMAND_G2,
    COMMAND_G3,
    COMMAND_G4,//LZ ADD 2022.11.13 暂停需要由运动处理
    COMMAND_RIGIDTAP,//刚性攻丝
    COMMAND_SCREW,//螺纹    
    COMMAND_MST,
    COMMAND_DONE,//NC程序结束标志
    
    COMMAND_MAC_HOME,//回机床零点
    COMMAND_PRO_HOME,//回程序零点
    /*
    手动控制命令
    */
    COMMAND_JOG,

    /*
    模态控制命令
    */
    COMMAND_G99,//设置为G99模式
    COMMAND_G98,//设置为G98模式
    COMMAND_G97,//设置为G97模式
    COMMAND_G96,//设置为G96模式

    /*
    模式切换命令
    */
    COMMAND_HAND,//切换到手动
    COMMAND_AUTO,//切换到自动
    COMMAND_WHEEL,//切换到手轮

    COMMAND_RESET,//复位命令
    COMMAND_STOP_NOW,//命令运动立即停止（减速停）

    COMMAND_START_BUS,//通知运动开始与总线通讯，开始走通讯流程

    COMMAND_SET_OVERRIDE_LIMIT,//忽略限位报警
    COMMAND_CLEAR_OVERRIDE_LIMIT,//清除忽略限位报警

    COMMAND_HOLD,//进给保持命令
    COMMAND_RESUME//进给保持恢复
}COMMAND_TYPE_t;



struct mst_data_s
{
    unsigned int t;
    unsigned int m[3];
    double s[MAX_SPIND_NUM];//0-第一主轴速度，1-第二主轴速度
    unsigned int have_s[MAX_SPIND_NUM];
    unsigned int have_t;
    /*
    有多少个M码
    0表示没有M码
    */
    unsigned int m_code_num;
};

/*
保存段的模态信息
用于界面显示
*/
struct state_tag_s
{
    double feed,speed;

    unsigned int g[20];

    unsigned int m[20];

};



//运动内部使用变量
//不在共享内存中、只有运动自身使用，其他模块不可访问
struct command_data_s
{
    int head;
    int tail;

    COMMAND_TYPE_t cmd;//命令号，指示是哪个命令，不同命令使用不同的结构体变量

    /*
    运动段相关数据
    */
    int id;//解释器的行号，单段重译码时会向任务反馈这个行号，

    int sub_id;//子ID号，目的是解决循环工艺重译码问题。非循环工艺该数据是0
    
    double end_pos[MAX_AXIS_NUM];//终点位置

    double feed_speed;//进给速度

    double center_pos[MAX_AXIS_NUM];//圆心位置

    double r;//半径
    
    struct mst_data_s mst_data;//如果命令是MST命令，则会读取此结构体，然后生成运动段

    struct state_tag_s tag;//模态信息，目前只用于界面显示

    /*
    手动控制相关数据    
    */
    int axis_num_select;//选轴   轴号，0-x ，1-z，2-y ，3-4th，4-5th
    int axis_dirction;// 1表示正方向，-1表示反方向，0表示抬起

    /*
    螺纹相关
    */
    double screw_lead;//螺纹导程
    double short_tail;//短轴退尾长度
    double long_tail;//长轴退尾长度
    double angle;//起始角度
    int G34_flag;// 1:表示是G34变螺距螺纹，0表示是G32正常螺纹
    double inc_val_r;//螺距变化量
};

struct command_queue_s
{
    struct command_data_s data[COMMAND_Q_NUM];   
    int start;        
    int end;            
    int num;  
    int head,tail;
};


typedef enum
{   
    TASK_COMMAND_MAC_HOME_X,//回机床零点
    TASK_COMMAND_MAC_HOME_Z,
    
    TASK_COMMAND_PRO_HOME,//回程序零点
    /*
    手动控制命令
    */
    TASK_COMMAND_JOG_X_POSITIVE,
    TASK_COMMAND_JOG_X_NEGATIVE,
    TASK_COMMAND_JOG_Z_POSITIVE,
    TASK_COMMAND_JOG_Z_NEGATIVE,
    /*
    模态控制命令
    */
    TASK_COMMAND_G99,//设置为G99模式
    TASK_COMMAND_G98,//设置为G98模式
    TASK_COMMAND_G97,//设置为G97模式
    TASK_COMMAND_G96,//设置为G96模式

    /*
    模式切换命令
    */
    TASK_COMMAND_HAND,//切换到手动
    TASK_COMMAND_AUTO,//切换到自动
    TASK_COMMAND_WHEEL,//切换到手轮

    TASK_COMMAND_RESET,//复位命令
    TASK_COMMAND_STOP_NOW,//命令运动立即停止（减速停）

    TASK_COMMAND_START_BUS,//通知运动开始与总线通讯，开始走通讯流程

    TASK_COMMAND_SET_OVERRIDE_LIMIT,//忽略限位报警
    TASK_COMMAND_CLEAR_OVERRIDE_LIMIT,//清除忽略限位报警

    TASK_COMMAND_HOLD,//进给保持命令
    TASK_COMMMAND_RESUME,//进给保持恢复
    
    TASK_COMMMAND_START_DECODE,//开始解释器解析   
}TASK_COMMAND_TYPE_t;


struct task_command_data_s
{
    int cmd;
};

struct task_command_queue_s
{
    struct task_command_data_s data[COMMAND_Q_NUM];   
    int start;        
    int end;            
    int num;  
    int head,tail;
};


extern int init_command_queue(struct command_queue_s * q);
extern int clear_command_queue(struct command_queue_s * q);
extern int command_handle(void);
extern int wait_q_handle(void);

extern int command_add_reset(struct command_queue_s * q);//轨迹规划器指针

extern int command_add_change_run_style(struct command_queue_s * q,//轨迹规划器指针
                                                COMMAND_TYPE_t cmd
                                                );

extern int command_add_jog(struct command_queue_s * q,//轨迹规划器指针
                            int axis_num,
                            int direction
                            );                                        
extern int command_add_stop_now(struct command_queue_s * q);
extern int command_add_machine_home(struct command_queue_s * q,//轨迹规划器指针                                 
                                 COMMAND_TYPE_t cmd,//命令号，直线应该传入 COMMAND_G0或    COMMAND_G1
                                 int axis_num
                                 );

extern int command_add_hold(struct command_queue_s * q);

extern int command_add_resume(struct command_queue_s * q);

extern int command_add_start_bus(struct command_queue_s * q);

extern int command_add_g99_g98(struct command_queue_s * q,int mod);

extern int command_add_g96_g97(struct command_queue_s * q,int mod);

extern int task_command_handle(void);

extern int task_command_add_reset(void);
extern int task_command_add_start_bus(void);
extern int task_command_add_start_decode(void);
extern int task_command_add_mac_home(int axis);
extern int task_command_add_change_mode(int mode);
extern int task_command_add_jog(int axis,int dir);

extern int task_command_add_hold(void);
extern int task_command_add_resume(void);

extern int task_command_add_g96_g97(int mode);
extern int task_command_add_g99_g98(int mode);
#endif //COMMAND_H



