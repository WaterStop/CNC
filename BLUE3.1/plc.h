
#ifndef PLC_H
#define PLC_H

#include <stdbool.h>


extern struct plc_shm_s *plc_shm;

extern struct motion_err_struct *motion_err;
extern struct motion_err_struct *motion_warn;


#define LadFile_Col 8
#define LadFile_MaxRow 4500
#define X_NUM 64
#define Y_NUM 48
#define NUM_F 128
#define NUM_G 128
 
#define NUM_A 32
#define NUM_D 128
#define NUM_T 256 
#define NUM_R 2048
#define NUM_C 128 
#define NUM_K 128

#define MAX_PROG_OR_LBL 100
#define MAX_DIF_CMD 256
#define CTRNum   128
#define TMRNum   128


typedef struct {
    int m_nVal;
    int m_nType;
    bool m_nDownLink;
    int m_nAddr;
    char m_strName[7];
    unsigned char m_CodtHeight;
    char m_strNote[34];
} Ladder_Node;

struct LadArrayplc {
    int m_lSize;//梯图行数
    Ladder_Node m_pIndex[LadFile_MaxRow + 1];//xsr 2023.4.3

};



typedef struct {
    char LadVersion[15]; //"梯图版本:"
    char LadNote[40];    //"梯图备注:"
    char LadAuthor[20];  //"梯图设计:"
    char LadSaveDate[40]; //"修改日期:"
} Ladder_Info;//梯图信息

struct LadFileCell {
    bool isCreated;                      //是否已经创建此号文件
    char names[13];                      //完整文件名
    int name;
    long size;                               //文件大小
    int LadFileMaxRow;                           //梯图行数
    int LadFileEnd1Row;                    //一级程序行数
    int LadFileAllStep;                           //梯图总步数
    int LadFileEnd1Step;                    //一级程序步数
    Ladder_Info LadInfoObj;

    int LadFileIsModify;                         //是否需要保存用户对梯图的修改
    int LadFileCurRow;
    int LadFileCurCol;
    int LadFileUpRow;  //界面上第一行对应的梯图行号

    int CodTableSize[64][2];
    bool CtrUseNote[CTRNum];
    bool TmrUseNote[TMRNum];
    bool TMRBUseNote[TMRNum];
    bool LBLUseNote[MAX_PROG_OR_LBL];
    bool SPUseNote[MAX_PROG_OR_LBL];
    bool DifuArray[MAX_DIF_CMD];
};



struct plc_shm_s
{

/*control的数字含义

#define  PlcCmd_Con                  1
无
#define  PlcCmd_WriteLad          2
CncWriteLadToPLC
#define  PlcCmd_Stop                 3
plc停止
#define  PlcCmd_Run                  4
plc工作
#define  PlcCmd_DownCtr          5
更新c
#define  PlcCmd_DownTmr         6
更新t
#define  PlcCmd_DownData        7
更新d
#define  PlcCmd_DownKeep       8
更新k
#define  PlcCmd_ConDown         9
无
#define  PlcCmd_DownParaAll   10
无
#define  PlcCmd_StopUpdate      11
无

    */
    int control;
    unsigned char x[X_NUM];     //外界传入的?
    unsigned char xl[X_NUM];    //实际应用的值，外界取用的的时候取这个??
    unsigned char y[Y_NUM];
    unsigned char f[NUM_F];
    unsigned char g[NUM_G];   
    unsigned char a[NUM_A];
    int d[NUM_D];    
    unsigned char t[NUM_T];
    unsigned char r[NUM_R];
    unsigned char c[NUM_C];
    unsigned char k[NUM_K];
    int LoadLadderNumber;   //题图文件的后缀数字
    int Ladderstate;        //梯图更改信号 0-未更改 1-更改
    Ladder_Node LadArrayAddr_Array[LadFile_MaxRow][LadFile_Col];
    int m_lSize;
    struct LadFileCell LadFileEdit;
    //struct LadArrayplc PLadderArrayObj;//2023.3.31 xsr
};




//extern int shm_init(void);
extern int ReadSignalBit(char chType, unsigned short addr, unsigned short bitpos);

extern void WriteSignalBit(char chType, unsigned short addr, unsigned short bitpos, unsigned short value);
extern unsigned char ReadSignalByte(char chType, int addr);
extern void WriteSignalByte(char chType, int addr, int value);
extern void clean_mst_f_signal(void);


#define PLC_SERVO_REQUEST_X 'G',0,0 //X轴请求上使能信号 0-下使能 1-上使能
#define PLC_SERVO_REQUEST_Z 'G',0,1
#define PLC_SERVO_REQUEST_Y 'G',0,2
#define PLC_SERVO_REQUEST_4 'G',0,3
#define PLC_SERVO_REQUEST_5 'G',0,4
#define PLC_SERVO_REQUEST_SPIN_1 'G',0,5 //主轴1请求上使能信号 0-下使能 1-上使能
#define PLC_SERVO_REQUEST_SPIN_2 'G',0,6 //主轴2请求上使能信号 0-下使能 1-上使能

#define PLC_AUXILIARY_FUNCTION_END 'G',4,3 //辅助功能结束信号 //任务的解释器使用

#define PLC_ELECTRIC_VEHICLE_FUNCTION_SWITCH 'G',5,0 //电子车功能切换

#define PLC_AUXILIARY_FUNCTION_LOCK 'G',5,6 //辅助功能锁住信号 运动处理

#define PLC_CHOICE_STOP 'G',6,1 //选择停信号 任务处理

#define PLC_CYCLE_START 'G',7,2 //循环启动信号 //任务处理
#define PLC_HAND_WHEEL_CUTTING 'G',7,4 //手轮试切信号 运动处理

#define PLC_EMERGENCY_STOP 'G',8,4 //急停信号 运动处理
#define PLC_FEED_HOLDING 'G',8,5 //进给保持信号 运动处理
#define PLC_RESET_G 'G',8,6 //复位信号 任务处理

#define PLC_LUBRICATION 'G',9,1 //润滑信号 任务处理

#define PLC_MANUAL_MOVEMENT_MAGNIFICATION 'G',10 //手动移动倍率信号 运动处理
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_0 'G',10,0 //手动移动倍率信号0位
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_1 'G',10,1 //手动移动倍率信号1位
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_2 'G',10,2 //手动移动倍率信号2位
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_3 'G',10,3 //手动移动倍率信号3位
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_4 'G',10,4 //手动移动倍率信号4位
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_5 'G',10,5 //手动移动倍率信号5位
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_6 'G',10,6 //手动移动倍率信号6位
#define PLC_MANUAL_MOVEMENT_MAGNIFICATION_7 'G',10,7 //手动移动倍率信号7位

#define PLC_FEED_SPEED_MAGNIFICATION 'G',12 //进给速度倍率信号 运动处理
#define PLC_FEED_SPEED_MAGNIFICATION_0 'G',12,0 //进给速度倍率信号0位
#define PLC_FEED_SPEED_MAGNIFICATION_1 'G',12,1 //进给速度倍率信号1位
#define PLC_FEED_SPEED_MAGNIFICATION_2 'G',12,2 //进给速度倍率信号2位
#define PLC_FEED_SPEED_MAGNIFICATION_3 'G',12,3 //进给速度倍率信号3位
#define PLC_FEED_SPEED_MAGNIFICATION_4 'G',12,4 //进给速度倍率信号4位
#define PLC_FEED_SPEED_MAGNIFICATION_5 'G',12,5 //进给速度倍率信号5位
#define PLC_FEED_SPEED_MAGNIFICATION_6 'G',12,6 //进给速度倍率信号6位
#define PLC_FEED_SPEED_MAGNIFICATION_7 'G',12,7 //进给速度倍率信号7位

#define PLC_FAST_SPEED_MAGNIFICATION 'G',14 //快速进给倍率信号 运动处理
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_0 'G',14,0 //快速进给倍率信号0位
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_1 'G',14,1 //快速进给倍率信号1位
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_2 'G',14,2 //快速进给倍率信号2位
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_3 'G',14,3 //快速进给倍率信号3位
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_4 'G',14,4 //快速进给倍率信号4位
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_5 'G',14,5 //快速进给倍率信号5位
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_6 'G',14,6 //快速进给倍率信号6位
#define PLC_RAPID_FEED_SPEED_MAGNIFICATION_7 'G',14,7 //快速进给倍率信号7位

#define PLC_ELECTRIC_VEHICLE_GEAR_LEVER_X_P 'G',15,0 //电子车档杆X+
#define PLC_ELECTRIC_VEHICLE_GEAR_LEVER_X_N 'G',15,1 //电子车档杆X-
#define PLC_ELECTRIC_VEHICLE_GEAR_LEVER_Z_P 'G',15,2 //电子车档杆Z+
#define PLC_ELECTRIC_VEHICLE_GEAR_LEVER_Z_N 'G',15,3 //电子车档杆Z-
#define PLC_ELECTRIC_VEHICLE_RAPID_MOVEMENT_BUTTON_X_P 'G',15,4 //电子车快移按钮X+
#define PLC_ELECTRIC_VEHICLE_RAPID_MOVEMENT_BUTTON_X_N 'G',15,5 //电子车快移按钮X-
#define PLC_ELECTRIC_VEHICLE_RAPID_MOVEMENT_BUTTON_Z_P 'G',15,6 //电子车快移按钮Z+
#define PLC_ELECTRIC_VEHICLE_RAPID_MOVEMENT_BUTTON_Z_N 'G',15,7 //电子车快移按钮Z-

#define PLC_HOME_X 'G',17,0 //X轴减速回零信号 运动处理
#define PLC_HOME_Z 'G',17,1 //Z轴减速回零信号
#define PLC_HOME_Y 'G',17,2 //Y轴减速回零信号
#define PLC_HOME_4TH 'G',17,3 //4TH轴减速回零信号
#define PLC_HOME_5TH 'G',17,4 //5TH轴减速回零信号

#define PLC_HAND_WHEEL_CHOICE_X 'G',18,0 //X轴手轮进给选择信号 运动处理
#define PLC_HAND_WHEEL_CHOICE_Z 'G',18,1 //Z轴手轮进给选择信号
#define PLC_HAND_WHEEL_CHOICE_Y 'G',18,2 //Y轴手轮进给选择信号
#define PLC_HAND_WHEEL_CHOICE_4TH 'G',18,3 //4TH轴手轮进给选择信号
#define PLC_HAND_WHEEL_CHOICE_5TH 'G',18,4 //5TH轴手轮进给选择信号

#define PLC_HAND_WHEEL_MAGNIFICATION_0 'G',19,4 //手轮倍率信号1位 运动处理
#define PLC_HAND_WHEEL_MAGNIFICATION_1 'G',19,5 //手轮倍率信号2位

#define PLC_MANUAL_FAST_CHOICE 'G',19,7 //手动快移信号 运动处理

#define PLC_SPINDLE_SPEED_MAGNIFICATION 'G',21//主轴速度倍率 运动处理
#define PLC_SPINDLE_SPEED_MAGNIFICATION_0 'G',21,0 //主轴速度倍率信号0位
#define PLC_SPINDLE_SPEED_MAGNIFICATION_1 'G',21,1 //主轴速度倍率信号1位
#define PLC_SPINDLE_SPEED_MAGNIFICATION_2 'G',21,2 //主轴速度倍率信号2位
#define PLC_SPINDLE_SPEED_MAGNIFICATION_3 'G',21,3 //主轴速度倍率信号3位
#define PLC_SPINDLE_SPEED_MAGNIFICATION_4 'G',21,4 //主轴速度倍率信号4位
#define PLC_SPINDLE_SPEED_MAGNIFICATION_5 'G',21,5 //主轴速度倍率信号5位
#define PLC_SPINDLE_SPEED_MAGNIFICATION_6 'G',21,6 //主轴速度倍率信号6位
#define PLC_SPINDLE_SPEED_MAGNIFICATION_7 'G',21,7 //主轴速度倍率信号7位

#define PLC_SPINDLE_CHOICE_1 'G',25,0 //第一主轴选择信号 运动处理
#define PLC_SPINDLE_CHOICE_2 'G',25,1 //第二主轴选择信号 运动处理
#define PLC_ORI_1 'G',25,2 //第一主轴定向请求信号 运动处理
#define PLC_CS_1 'G',25,3 //第一主轴CS切换请求信号 运动处理
#define PLC_SPINDLE_FORWARD_1 'G',25,4 //第一主轴正转信号 运动处理
#define PLC_SPINDLE_REVERSAL_1 'G',25,5 //第一主轴反转信号 运动处理
#define PLC_SPINDLE_FORWARD_2 'G',25,6 //第二主轴正转信号 运动处理
#define PLC_SPINDLE_REVERSAL_2 'G',25,7 //第二主轴反转信号 运动处理

#define PLC_ORI_2 'G',26,2 //第二主轴定向请求信号 运动处理
#define PLC_CS_2 'G',26,3 //第二主轴CS切换请求信号 运动处理
#define PLC_SPINDLE_SPEED_POS_SWITCH_COMPLETE_1 'G',26,4 //第一主轴速度位置切换完成
#define PLC_SPINDLE_SPEED_POS_SWITCH_COMPLETE_2 'G',26,5 //第二主轴速度位置切换完成
#define PLC_SPINDLE_EXTERNALING_COMPLETE_1 'G',26,6 //第一主轴外部定位完成信号
#define PLC_SPINDLE_EXTERNALING_COMPLETE_2 'G',26,7 //第二主轴外部定位完成信号

#define PLC_MANUAL_CHOICE_X_P 'G',27,0 //手动选轴X+ 任务处理
#define PLC_MANUAL_CHOICE_Z_P 'G',27,1 //手动选轴Z+
#define PLC_MANUAL_CHOICE_Y_P 'G',27,2 //手动选轴Y+
#define PLC_MANUAL_CHOICE_4TH_P 'G',27,3 //手动选轴4TH+
#define PLC_MANUAL_CHOICE_5TH_P 'G',27,4 //手动选轴5TH+

#define PLC_MANUAL_CHOICE_X_N 'G',28,0 //手动选轴X- 任务处理
#define PLC_MANUAL_CHOICE_Z_N 'G',28,1 //手动选轴Z-
#define PLC_MANUAL_CHOICE_Y_N 'G',28,2 //手动选轴Y-
#define PLC_MANUAL_CHOICE_4TH_N 'G',28,3 //手动选轴4TH-
#define PLC_MANUAL_CHOICE_5TH_N 'G',28,4 //手动选轴5TH-

#define PLC_HW_LIMIT_X_P 'G',30,0 //轴超程信号X+ 运动处理
#define PLC_HW_LIMIT_Z_P 'G',30,1 //轴超程信号Z+
#define PLC_HW_LIMIT_Y_P 'G',30,2 //轴超程信号Y+
#define PLC_HW_LIMIT_4TH_P 'G',30,3 //轴超程信号4TH+
#define PLC_HW_LIMIT_5TH_P 'G',30,4 //轴超程信号5TH+

#define PLC_HW_LIMIT_X_N 'G',31,0 //轴超程信号X-  运动处理
#define PLC_HW_LIMIT_Z_N 'G',31,1 //轴超程信号Z-
#define PLC_HW_LIMIT_Y_N 'G',31,2 //轴超程信号Y-
#define PLC_HW_LIMIT_4TH_N 'G',31,3 //轴超程信号4TH-
#define PLC_HW_LIMIT_5TH_N 'G',31,4 //轴超程信号5TH-

#define PLC_SPINDLE_JOG_1 'G',36,0 //第一主轴点动功能信号 PLC直接设置G25.4 25.5 即可
#define PLC_SPINDLE_JOG_2 'G',36,1 //第二主轴点动功能信号

#define PLC_TOOL_NUMBER 'G',37 //刀号 运动处理
#define PLC_TOOL_NUMBER_0 'G',37,0 //当前刀具号0位
#define PLC_TOOL_NUMBER_1 'G',37,1 //当前刀具号1位
#define PLC_TOOL_NUMBER_2 'G',37,2 //当前刀具号2位
#define PLC_TOOL_NUMBER_3 'G',37,3 //当前刀具号3位
#define PLC_TOOL_NUMBER_4 'G',37,4 //当前刀具号4位
#define PLC_TOOL_NUMBER_5 'G',37,5 //当前刀具号5位
#define PLC_TOOL_NUMBER_6 'G',37,6 //当前刀具号6位
#define PLC_TOOL_NUMBER_7 'G',37,7 //当前刀具号7位

#define PLC_RUN_STYLE 'G',43 //模式 任务处理
#define PLC_RUN_STYLE_0 'G',43,0 //当前工作方式选择1
#define PLC_RUN_STYLE_1 'G',43,1 //当前工作方式选择2
#define PLC_RUN_STYLE_2 'G',43,2 //当前工作方式选择3
#define PLC_RUN_STYLE_3 'G',43,7 //当前工作方式选择4

#define PLC_PROGRAM_JUMP 'G',44,0 //程序跳段信号 任务处理
#define PLC_MACHINE_LOCK 'G',44,1 //机床锁住信号 运动处理

#define PLC_PROGRAM_SINGLE 'G',46,1 //单程序段信号 运动处理
#define PLC_VAN 'G',46,7 //空运行信号 运动处理

#define PLC_SPINDLE_GEAR 'G',48 //主轴挡位 运动处理
#define PLC_SPINDLE_GEAR_0 'G',48,0 //齿轮选择信号1位
#define PLC_SPINDLE_GEAR_1 'G',48,1 //齿轮选择信号2位
#define PLC_SPINDLE_GEAR_2 'G',48,2 //齿轮选择信号3位

#define PLC_MACRO_INPUT_0 'G',54,0 //宏输入信号0位 任务处理
#define PLC_MACRO_INPUT_1 'G',54,1 //宏输入信号1位
#define PLC_MACRO_INPUT_2 'G',54,2 //宏输入信号2位
#define PLC_MACRO_INPUT_3 'G',54,3 //宏输入信号3位
#define PLC_MACRO_INPUT_4 'G',54,4 //宏输入信号4位
#define PLC_MACRO_INPUT_5 'G',54,5 //宏输入信号5位
#define PLC_MACRO_INPUT_6 'G',54,6 //宏输入信号6位
#define PLC_MACRO_INPUT_7 'G',54,7 //宏输入信号7位

#define PLC_MACRO_INPUT_8 'G',55,0 //宏输入信号8位  任务处理
#define PLC_MACRO_INPUT_9 'G',55,1 //宏输入信号9位
#define PLC_MACRO_INPUT_10 'G',55,2 //宏输入信号10位
#define PLC_MACRO_INPUT_11 'G',55,3 //宏输入信号11位
#define PLC_MACRO_INPUT_12 'G',55,4 //宏输入信号12位
#define PLC_MACRO_INPUT_13 'G',55,5 //宏输入信号13位
#define PLC_MACRO_INPUT_14 'G',55,6 //宏输入信号14位
#define PLC_MACRO_INPUT_15 'G',55,7 //宏输入信号15位

#define PLC_HAND_ISR_REQUEST_X 'G',56,0 //手脉中断标志请求信号X轴 运动处理
#define PLC_HAND_ISR_REQUEST_Z 'G',56,1 //手脉中断标志请求信号Z轴
#define PLC_HAND_ISR_REQUEST_Y 'G',56,2 //手脉中断标志请求信号Y轴
#define PLC_HAND_ISR_REQUEST_4TH 'G',56,3 //手脉中断标志请求信号4TH轴
#define PLC_HAND_ISR_REQUEST_5TH 'G',56,4 //手脉中断标志请求信号5TH轴

#define PLC_ELECTRIC_VEHICLE_GEAR_LEVER_BE_IN_FORWARD_ROTATION 'G',62,0 //档杆处于正转位置
#define PLC_ELECTRIC_VEHICLE_GEAR_LEVER_BE_IN_REVERSAL 'G',62,1 //档杆处于反转位置
#define PLC_ELECTRIC_VEHICLE_GEAR_LEVER_BE_IN_STOP 'G',62,2 //档杆处于停止位置
#define PLC_RESET_WHETHER_STOP_SPINDLE 'G',62,4 //复位是否停止主轴





#define PLC_COMPLETE_COUNT 'F',0,3 //加工完成计数 上升沿时PLC清除循环启动G信号
#define PLC_FEED_HOLD_LAMP 'F',0,4 //进给暂停灯信号
#define PLC_CYCLE_RUN_LAMP 'F',0,5 //循环启动灯信号
#define PLC_SERVO_READY 'F',0,6 //伺服就绪信号-PLC用来做卡盘和主轴换挡的前置条件
#define PLC_AUTO_RUN 'F',0,7 //自动运行信号-正在运行时设置1，PLC未使用

#define PLC_ALARM 'F',1,0 //报警信号 ，为1时停止主轴，系统alarm灯亮
#define PLC_RESET_F 'F',1,1 //复位信号，做的PLC的复位处理
#define PLC_SPINDLE_SPEED_ARRIVE 'F',1,2 //主轴转速到达信号-判断编程速度和反馈速度，小于一定值时置1
#define PLC_DISTRIBUTION_END 'F',1,3 //分配结束信号 //PLC未使用
#define PLC_TAPPING 'F',1,5 //攻丝信号 //为1使PLC设置主轴倍率为100%

#define PLC_FAST_FEED 'F',2,1 //快速进给信号 ，PLC未使用
#define PLC_HAND_WHEEL_CUT 'F',2,2 //手轮试切信号 plc用来在自动模式下使手轮生效
#define PLC_THREAD_CUT 'F',2,3 //螺纹切削信号  为1使PLC设置主轴倍率为100%
#define PLC_CHOICE_STOP_LAMP 'F',2,5 //选择停检测信号 指示灯
#define PLC_VAN_LAMP 'F',2,7 //空运行检测信号 指示灯

#define PLC_SINGLE_STEP_RUN_STYLE 'F',3,0 //单步模式 单步方式时 设置为1 
#define PLC_HAND_WHEEL_RUN_STYLE 'F',3,1 //手轮模式 
#define PLC_JOG_RUN_STYLE 'F',3,2 //JOG模式 
#define PLC_MDI_RUN_STYLE 'F',3,3 //MDI/录入模式 
#define PLC_DNC_RUN_STYLE 'F',3,4 //DNC模式 
#define PLC_AUTOMATIC_RUN_STYLE 'F',3,5 //自动模式 
#define PLC_EDIT_RUN_STYLE 'F',3,6 //编辑模式 

#define PLC_JUMP_LAMP 'F',4,0 //跳段检测信号 指示灯
#define PLC_LOCK_LAMP 'F',4,1 //机床锁检测信号 指示灯
#define PLC_HAND_ISR_SIGNAL 'F',4,2 //开启手轮中断功能--手轮中断模式下才能选在到对应的G信号'G',56,0
#define PLC_SINGLE_PROGRAM_LAMP 'F',4,3 //单段检测信号 指示灯
#define PLC_AUXILIARY_LOCK_LAMP 'F',4,4 //辅助锁检测信号 指示灯
#define PLC_MACHINE_HOME_RUN_STYLE 'F',4,5 //机床零点模式  
#define PLC_PROGRAM_HOME_RUN_STYLE 'F',4,6 //程序零点模式  

#define PLC_MST_SIGNAL 'F',7 //辅助功能选通信号
#define PLC_M_SIGNAL 'F',7,0 //辅助功能选通信号
#define PLC_S_SIGNAL 'F',7,2 //主轴速度选通信号
#define PLC_T_SIGNAL 'F',7,3 //刀具功能选通信号

#define PLC_M30_SIGNAL 'F',9,4 //M30译码信号
#define PLC_M02_SIGNAL 'F',9,5 //M02译码信号
#define PLC_M01_SIGNAL 'F',9,6 //M01译码信号
#define PLC_M00_SIGNAL 'F',9,7 //M00译码信号

#define PLC_M_CODE 'F',10 //辅助功能码传输位
#define PLC_AUXILIARY_FUNCTION_CODE_0 'F',10,0 //辅助功能代码0位
#define PLC_AUXILIARY_FUNCTION_CODE_1 'F',10,1 //辅助功能代码1位
#define PLC_AUXILIARY_FUNCTION_CODE_2 'F',10,2 //辅助功能代码2位
#define PLC_AUXILIARY_FUNCTION_CODE_3 'F',10,3 //辅助功能代码3位
#define PLC_AUXILIARY_FUNCTION_CODE_4 'F',10,4 //辅助功能代码4位
#define PLC_AUXILIARY_FUNCTION_CODE_5 'F',10,5 //辅助功能代码5位
#define PLC_AUXILIARY_FUNCTION_CODE_6 'F',10,6 //辅助功能代码6位
#define PLC_AUXILIARY_FUNCTION_CODE_7 'F',10,7 //辅助功能代码7位

#define PLC_PLC_GET_INTO_TEST_MODE 'F',14,0 //PLC进入调试模式 PLC中模式切换和循环启动的前置条件

#define PLC_HAVE_AXIS_Y 'F',15,2 //是否使用Y轴 根据参数的使用几个轴有关，使用2个轴，这3个标志位都为0，使用3个轴F15.2为1，4个轴15.2和153为1，最多5个轴，都为1
#define PLC_HAVE_AXIS_4TH 'F',15,3 //是否使用4TH轴
#define PLC_HAVE_AXIS_5TH 'F',15,4 //是否使用5TH轴

#define PLC_ELECTRIC_VEHICLE_CYCLE_START 'F',16,0 //电子车循环启动
#define PLC_ELECTRIC_VEHICLE_RESET 'F',16,1 //电子车复位

#define PLC_SHIELD_EXTERNALLY_CONNECTED_EMERGENCY_STOP 'F',21,3 //屏蔽外接急停信号
#define PLC_SHIELD_KEYBOARD_EMERGENCY_STOP 'F',21,4 //屏蔽键盘急停信号
#define PLC_SHIELD_EXTERNALLY_CONNECTED_SUSPEND 'F',21,5 //屏蔽外接进给保持信号
#define PLC_SHIELD_EXTERNALLY_CONNECTED_CYCLE_START 'F',21,6 //屏蔽外接循环启动信号

#define PLC_S_CODE 'F',22
#define PLC_SPINDLE_SPEED_CODE_0 'F',22,0 //主轴速度代码信号0位 
#define PLC_SPINDLE_SPEED_CODE_1 'F',22,1 //主轴速度代码信号1位
#define PLC_SPINDLE_SPEED_CODE_2 'F',22,2 //主轴速度代码信号2位
#define PLC_SPINDLE_SPEED_CODE_3 'F',22,3 //主轴速度代码信号3位
#define PLC_SPINDLE_SPEED_CODE_4 'F',22,4 //主轴速度代码信号4位
#define PLC_SPINDLE_SPEED_CODE_5 'F',22,5 //主轴速度代码信号5位
#define PLC_SPINDLE_SPEED_CODE_6 'F',22,6 //主轴速度代码信号6位
#define PLC_SPINDLE_SPEED_CODE_7 'F',22,7 //主轴速度代码信号7位

#define PLC_T_CODE 'F',26                                                                       //给PLC的刀号，PLC换刀使用
#define PLC_TOOL_FUNCTION_CODE_0 'F',26,0 //刀具功能代码信号0位
#define PLC_TOOL_FUNCTION_CODE_1 'F',26,1 //刀具功能代码信号1位
#define PLC_TOOL_FUNCTION_CODE_2 'F',26,2 //刀具功能代码信号2位
#define PLC_TOOL_FUNCTION_CODE_3 'F',26,3 //刀具功能代码信号3位
#define PLC_TOOL_FUNCTION_CODE_4 'F',26,4 //刀具功能代码信号4位
#define PLC_TOOL_FUNCTION_CODE_5 'F',26,5 //刀具功能代码信号5位
#define PLC_TOOL_FUNCTION_CODE_6 'F',26,6 //刀具功能代码信号6位
#define PLC_TOOL_FUNCTION_CODE_7 'F',26,7 //刀具功能代码信号7位

#define PLC_AXIS_MOVE_X 'F',38,0 //X轴移动信号  如果轴移动，需要设置这个信号为1
#define PLC_AXIS_MOVE_Z 'F',38,1 //Z轴移动信号
#define PLC_AXIS_MOVE_Y 'F',38,2 //Y轴移动信号
#define PLC_AXIS_MOVE_4TH 'F',38,3 //4TH轴移动信号
#define PLC_AXIS_MOVE_5TH 'F',38,4 //5TH轴移动信号

#define PLC_AXIS_MOVE_DIRECTION_X 'F',39,0 //X轴运动方向信号   0表示负  1表示正
#define PLC_AXIS_MOVE_DIRECTION_Z 'F',39,1 //Z轴运动方向信号
#define PLC_AXIS_MOVE_DIRECTION_Y 'F',39,2 //Y轴运动方向信号
#define PLC_AXIS_MOVE_DIRECTION_4TH 'F',39,3 //4TH轴运动方向信号
#define PLC_AXIS_MOVE_DIRECTION_5TH 'F',39,4 //5TH轴运动方向信号

#define PLC_HOME_DONE_X 'F',42,0 //X轴返回程序零点结束信号
#define PLC_HOME_DONE_END_Z 'F',42,1 //Z轴返回程序零点结束信号
#define PLC_HOME_DONE_END_Y 'F',42,2 //Y轴返回程序零点结束信号
#define PLC_HOME_DONE_END_4TH 'F',42,3 //4TH轴返回程序零点结束信号
#define PLC_HOME_DONE_END_5TH 'F',42,4 //5TH轴返回程序零点结束信号

#define PLC_SPINDLE_JOG_LAMP 'F',43,0 //主轴点动检测信号
#define PLC_SPINDLE_REQUEST_SWITCH_SPEED_POS_1 'F',43,4 //第一主轴请求速度/位置切换，1切换到位置，0切换到速度
#define PLC_SPINDLE_REQUEST_SWITCH_SPEED_POS_2 'F',43,5 //第一主轴请求速度/位置切换，1切换到位置，0切换到速度

#define PLC_SPINDLE_CS_SWITCH_DONE_1 'F',44,1 //第一主轴CS轮廓控制切换结束信号
#define PLC_SPINDLE_CS_SWITCH_DONE_2 'F',44,2 //第一主轴CS轮廓控制切换结束信号
#define PLC_SPINDLE_SPEED_ARRIVE_1 'F',44,5 //第一主轴速度到达信号
#define PLC_SPINDLE_SPEED_ARRIVE_2 'F',44,6 //第二主轴速度到达信号

#define PLC_SPINDLE_ZERO_SPEED_1 'F',45,0 //第一主轴零速信号
#define PLC_SPINDLE_ZERO_SPEED_2 'F',45,1 //第二主轴零速信号
#define PLC_SPINDLE_ORI_DONE_1 'F',45,2 //第一主轴定向完成信号
#define PLC_SPINDLE_ORI_DONE_2 'F',45,3 //第二主轴定向完成信号

#define PLC_EXTERNAL_ORI_1 'F',45,6 //第一主轴外部定位模式  根据参数设置给值
#define PLC_EXTERNAL_ORI_2 'F',45,7 //第二主轴外部定位模式

#define PLC_AXIS_DIRECTION_CHOICE_X 'F',51,0 //X轴方向选择 //参数配置，移动按键是否取反
#define PLC_AXIS_DIRECTION_CHOICE_Z 'F',51,1 //Z轴方向选择
#define PLC_AXIS_DIRECTION_CHOICE_Y 'F',51,2 //Y轴方向选择
#define PLC_AXIS_DIRECTION_CHOICE_4TH 'F',51,3 //4TH轴方向选择
#define PLC_AXIS_DIRECTION_CHOICE_5TH 'F',51,4 //5TH轴方向选择



#endif //PLC_H


