
#ifndef ERROR_H
#define ERROR_H
#include <stdio.h>



#define MAX_ERROR_NUM 32    /* how many errors we can queue */
#define error_printf printf

struct motion_err_s
{
    int id;//报警号
    int axis;//报警的轴    
    int mix;//其他综合信息
};


//运动反馈的错误
//放到共性内存中，与其他模块交互
struct motion_err_struct
{
    int head;
    int tail;
    int size;        /* number of items */
    struct motion_err_s data[MAX_ERROR_NUM];
};



/*
报警分类
    系统报警，
        硬件错误：
            铁电错误，RTC错误，等
        文件丢失报警，上电应该检查所需文件
        定时锁系统
    任务报警（违法的操作）        
        不允许移动轴
        不允许切换模式
        等            
    解释器报警
        词法或语法的报警
    运动报警
        
    PLC报警
        A报警
    总线报警
        初始化报警
        看门狗报警
        等
    伺服报警
        电压低
        超速
        等
    GUI报警
        参数超范围
        权限不足等
*/
typedef enum 
{
    ERROR_NO_ERROR = 0,//系统用报警号
    ERROR_SYS_READ_PARA_ERROR,//读取参数错误
    ERROR_SYS_EMERGENCY,//急停报警

    ERROR_TASK=1000,//任务用报警号

    ERROR_DECODE=2000,//解释器用报警号
        ERROR_DECODE_SKIP_SEG_FLAG,//本段是跳段
        ERROR_DECODE_HAVE_POUNE,//本段有#变量，需要等待运动同步
        ERROR_DECODE_ALARM,//表示有报警
        ERROR_DECODE_NOT_HAVE_START_FLAG,//没有开始标志
        ERROR_DECODE_ACCIDENCE_Q_IS_FULL,//词法分析队列满了，不能继续词法译码
        ERROR_DECODE_ACCIDENCE_Q_IS_EMPTE,//词法分析队列没有数据，不能继续语法译码
        ERROR_DECODE_QUEUE_IS_FULL,//解释器的输出队列满了，
        ERROR_DECODE_MST_NOT_COMPLETE,//mst指令没有执行完成
        ERROR_DECODE_FILE_OPEN_ERR,//打开文件失败
        ERROR_DECODE_FILE_END,//文件结束或者读取 失败 
        ERROR_DECODE_PARA_IS_NULL,//参数传入的是NULL，
        ERROR_DECODE_ONE_LINE_BUF_IS_TOO_LONG,//一行中的字符数超过设定值，BUFLEN-2
        ERROR_DECODE_NOT_NUMBER,//需要一个数字
        ERROR_DECODE_OUT_OF_RANGE,//超出范围
        ERROR_DECODE_UNKNOW_ERR,    
        ERROR_DECODE_RESULT_IS_NULL,        
        ERROR_DECODE_ILLEGAL_CHAR, /*非法字符*/
        ERROR_DECODE_ERR_CALLED,/*错误的调用位置*/
        ERROR_DECODE_END_OF_LINE_BECAUSE_SKIP,/*当前段因为跳段，直接结束*/
        ERROR_DECODE_ERR_AXIS_NAME_SET,/*错误的轴名设置*/
        ERROR_DECODE_RIGHT_VAL_IS_ZERO,/*除数是零*/
        ERROR_DECODE_NO_SUPPORT_OPERATION,/*不支持的操作符*/
        ERROR_DECODE_read_real_value_IS_NAN,/*read_real_value函数返回的值是Nan*/
        ERROR_DECODE_EXPECT_INT,/*期望一个int型的数据*/
        ERROR_DECODE_CAN_NOT_WRITE_MACRO_VAL,/*该地址的宏变量不能写操作*/
        ERROR_DECODE_ILLEGAL_MACRO_VAL,/*指定了非法的变量号.ok*/
        ERROR_DECODE_EQUAL_SIGN_MISSING_IN_PARAMETER_SETTING,/*井号后面缺少等号*/
        ERROR_DECODE_ERR_DECIMAL_POINT,/*错误使用小数点*/
        ERROR_DECODE_INVALIDE_G_CODE,/*不支持的G指令*/
        ERROR_DECODE_INVALIDE_M_CODE,/*不支持的M指令*/
        ERROR_DECODE_EXPECT_POUND,/*期望一个#变量*/
        ERROR_DECODE_ILLEGAL_NEGATIVE_OPER,/*非法负号*/
        ERROR_DECODE_EXPECT_SECOND_LOOP,//需要第二个循环语句
        ERROR_DECODE_CAN_NOT_USE_M_END_IN_LOOP,//在循环中不能使用结束类型的M指令，M02/30/98/99
        ERROR_DECODE_CAN_NOT_USE_T_IN_LOOP,//在循环中不能换刀
        ERROR_DECODE_T_CODE_OUT_OF_RANGE,//换刀参数超出范围，偏置号或刀号超范围
        ERROR_DECODE_T_VALUE_OUT_OF_RANGE,//刀长补偿值超范围
        ERROR_DECODE_T_CAN_NOT_USE_WITH_CYCLE,//圆弧指令不能建立刀补
        ERROR_DECODE_CAN_NOT_CHANGE_PLAN_WITH_LOOP,//固定循环模态中不能切换平面
        ERROR_DECODE_CAN_NOT_CHANGE_PLAN_AXIS_NUM_LESS_LEN_3,//轴数小于3不能切平面
        ERROR_DECODE_CAN_NOT_CHANGE_COORD_WITHOUT_G40,//有半径补偿时不可以切换坐标系
        ERROR_DECODE_G02G03_NOT_HAVE_IJK_OR_R,////在圆弧插补中R与(I,J,K)全为零.
        ERROR_DECODE_END_POS_NOT_ON_CYCLE,//圆弧终点不在圆上
        ERROR_DECODE_SCREW_PARA_ERROR,//螺纹指令的参数错误
        ERROR_DECODE_SCREW_R_INVALID,//变螺距螺纹切削过程中出现螺距小于0
        ERROR_DECODE_SCREW_F_OR_I_OUTOF_RANGE,//螺纹导程超范围
        ERROR_DECODE_SCREW_LONG_AXIS_LENGTH_ERROR,//螺纹长轴长度值错误
        ERROR_DECODE_SCREW_K_OR_J_OUTOF_RANGE,//螺纹的J或K参数设置超出范围

    ERROR_MOTION=3000,
         ERROR_MOTION_INVALID_AXIS_NUM,//无效的进给轴号
         ERROR_MOTION_INVALID_RUN_STYLE,//无效的运行状态
         ERROR_MOTION_NAN,//NAN错误
         ERROR_MOTION_INVALID_NEXT_RUN_STYLE,//下一个状态错误
         ERROR_MOTION_CYCLE_INVALID_R_OR_END,//起点和终点的距离大于直径
         ERROR_MOTION_CAN_NOT_CHANGE_DIRECTION,//不允许改变运行方向
         ERROR_MOTION_SOFT_LIMIT_POS_X,//软限正向报警
         ERROR_MOTION_SOFT_LIMIT_POS_Z,
         ERROR_MOTION_SOFT_LIMIT_POS_Y,
         ERROR_MOTION_SOFT_LIMIT_POS_4,
         ERROR_MOTION_SOFT_LIMIT_POS_5,
         
         ERROR_MOTION_SOFT_LIMIT_NEG_X,//软限负向报警
         ERROR_MOTION_SOFT_LIMIT_NEG_Z,
         ERROR_MOTION_SOFT_LIMIT_NEG_Y,
         ERROR_MOTION_SOFT_LIMIT_NEG_4,
         ERROR_MOTION_SOFT_LIMIT_NEG_5,
         
         ERROR_MOTION_HARD_LIMIT_POS_X,//硬限正向报警
         ERROR_MOTION_HARD_LIMIT_POS_Z,
         ERROR_MOTION_HARD_LIMIT_POS_Y,
         ERROR_MOTION_HARD_LIMIT_POS_4,
         ERROR_MOTION_HARD_LIMIT_POS_5,

         
         ERROR_MOTION_HARD_LIMIT_NEG_X,//硬限负向报警
         ERROR_MOTION_HARD_LIMIT_NEG_Z,
         ERROR_MOTION_HARD_LIMIT_NEG_Y,
         ERROR_MOTION_HARD_LIMIT_NEG_4,
         ERROR_MOTION_HARD_LIMIT_NEG_5,

         ERROR_MOTION_SCREW_AXIS_SPEED_LIMIT,//螺纹加工时，进给轴速度超过最大限制
         ERROR_MOTION_SCREW_NO_SPIN_SPEED,//主轴速度为零
         ERROR_MOTION_SCREW_CALC_NO_RESULT,//计算结果无解
         ERROR_MOTION_SCREW_ZPOS_LIMIT,//主轴零点偏移过大
         ERROR_MOTION_SCREW_LONG_AXIS_SPEED_OVER,//进给轴速度过大
         ERROR_MOTION_SCREW_SPIN_SPEED_FLUCTUATE_TOO_MUCH,//主轴速度波动过大

         ERROR_MOTION_CAN_NOT_SEND_MST_TO_PLC,//给PLC发送MST信号时，G4.3是1,表示MST的逻辑顺序出现问题
         ERROR_MOTION_MST_CAN_NOT_REVERSE,//MST段不可以反向运行

    ERROR_PLC=4000,
    ERROR_PLC_OPEN_ERROR,//看门狗错误，
    ERROR_PLC_A0_0,//PLC A报警
    ERROR_PLC_IncorrectVerticalLines,//网络中有不正确的垂直线
    ERROR_PLC_RowsOutOfSupport,//网络连接行数超出支持范围
    ERROR_PLC_ConnectedInParallel, //水平导通线与节点网络并联
    ERROR_PLC_NotConnectedOrShorted,//网络水平线未连上或短路
    ERROR_PLC_UnnecessaryRelaysOrCoils,//存在有不必要的继电器或线圈
    ERROR_PLC_IllegalOutput,//网络中存在非法的输出
    ERROR_PLC_NotSetAddress,//继电器或者线圈的地址未设定
    ERROR_PLC_structureIsIncomplete,//网络结构不完整
    ERROR_PLC_NotConnectedCorrectly,//功能指令未正确连接
    ERROR_PLC_NotCurrentlySupportedNetworkStructure,//出现当前不支持的网络结构
    ERROR_PLC_FunctionInstructionsNotOutputCorrectly,//功能指令未正确输出
    ERROR_PLC_NameMissing,//功能指令名丢失
    ERROR_PLC_ParametersAreMissing,//功能指令中缺少参数
    ERROR_PLC_ParameterFileNotLoaded,//PLC系统参数文件未载入
    ERROR_PLC_ExceedsMaximumAllowedNumberOfRowsOrSteps,//用户梯形图超出最大允许行数或者步数
    ERROR_PLC_IllegalCharacterOrDataOutOfRange,//指定了非法字符或数据超出范围
    ERROR_PLC_DuplicateCTRAddress,//CTR地址重复
    ERROR_PLC_DuplicateTMRAddress,//TMR地址重复
    ERROR_PLC_JMPLBLNotProcessedCorrectlyOrExceedsTheCapacity,//功能指令JMP/LBL未正确处理或者超出容量
    ERROR_PLC_CALLSPSPENotUsedCorrectly,//CALL/SP/SPE未正确使用
    ERROR_PLC_DIFUDIFDNotUsedCorrectly,//DIFU/DIFD未正确使用
    ERROR_PLC_SameOutputAddressUsedInAnotherPlace,//同一输出地址在另一处被使用
    ERROR_PLC_END1OrEND2NotUsedCorrectly,//功能指令END1或END2未正确使用
    ERROR_PLC_AddressDataNotEnteredCorrectly,//地址数据未正确输入
    ERROR_PLC_LadderDiagramUploadedAgainRestartTheSystem,//重新上传了梯图，请重启系统
    ERROR_PLC_LadderDiagramFileFormatError,//梯图文件格式错误
    ERROR_PLC_ModifiedParameterPrimaryPowerSupplyMustBeCutOff,//修改了必须切断一次电源的参数
    ERROR_PLC_LossNetworkWhileEditingLadderDuePowerFailure,//在编辑梯形图时断电导致在编辑的网络丢失
    ERROR_PLC_AddressOrConstantOutOfRange,//功能指令参数的地址或常数超出范围
    ERROR_PLC_UserDataAreaFull,//用户数据区已满,请减少COD指令数据表容量
    ERROR_PLC_JMPLBLNotProcessedCorrectlyOrExceedsCapacity,//功能指令JMP/LBL未正确处理或者超出容量
    ERROR_PLC_SFTInstructionExceedsTheMaximumAllowedUsage,//SFT指令超出最大允许使用数
    ERROR_PLC_COMCOMENotUsedCorrectly,//功能指令COM/COME未正确使用
    ERROR_PLC_CommandOrNetworkNotWithinExecutableRange,//指令或网络不在可执行范围内
    ERROR_PLC_FirstLevelOfLadderTooLarge,//梯形图的第一级太大,不能及时执行完毕
    ERROR_PLC_LadderDiagramFileTooSmall,//梯图文件过小，不是梯图文件




    ERROR_BUS=5000,
        ERROR_BUS_WDT,//看门狗错误，
        ERROR_BUS_OPEN_DEV_FAILD,//打开驱动节点文件失败
        ERROR_BUS_TIMEOUT_SLVRUN_WaitSensorOn,//等待SLVRUN_WaitSensorOn超时
        ERROR_BUS_TIMEOUT_SLVRUN_ServoOff,
        ERROR_BUS_TIMEOUT_MST_WaitDisconnect,
        ERROR_BUS_TIMEOUT_MST_WaitConnect,
        ERROR_BUS_TIMEOUT_MST_WaitClrAlm,
        ERROR_BUS_TIMEOUT_MST_WaitEnterSync,
    
    ERROR_GUI=6000,
    
    ERROR_SERVO=10000,

    
}error_id;

extern int error_init(struct motion_err_struct * err_q);
extern void report_error(int err_id, int axis, int mix);
extern int warn_init(struct motion_err_struct * warn_q);
extern void report_warn(int warn_id, int axis, int mix);
extern int find_error(int id);
extern void del_error(int id);


#endif
