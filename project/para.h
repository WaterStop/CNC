

#ifndef INIT_H
#define INIT_H


//读取参数，传入参数号
#define read_para(num)  (para[num].type ? para[num].cur_val.double_val : para[num].cur_val.int_val)

//写double类型的参数
#define write_para(num,val) if(para[num].type) para[num].cur_val.double_val=(val); else para[num].cur_val.int_val=(val);
#define write_para_type(num,val) (para[num].type=val)


typedef enum 
{
    //------------------------------------------------------------------------------------------------------------进给轴参数  
    NUM_AXIS_USED=1,//使用的轴数量

    AXIS_NAME_Y,//轴名称，用ASCII码的10进制表示字母，65-A,66-B,67-C,88-X,89-Y,90-Z,其中前两个轴的轴名不可以更改，固定为88，90
    AXIS_NAME_4,
    AXIS_NAME_5,

    YAxisType0,// 设定Y轴类型(0:直线轴 1:旋转轴)
    YAxisType1,// 设定Y轴类型(0:旋转轴A型 1:旋转轴B型)
    YAxisAbsPos360Cir,// Y轴为旋转轴时,绝对坐标循环功能无效/有效
    YAxisHandyRotate,// Y轴为旋转轴时,就近旋转/按符号方向旋转 
    YAxisRelPos360Cir,// Y轴为旋转轴时,相对坐标循环功能无效/有效

    // 4th轴的设定
    Th4AxisType0,//设定4th轴类型(0:直线轴 1:旋转轴)
    Th4AxisType1,//设定4th轴类型(0:旋转轴A型 1:旋转轴B型)
    Th4AxisAbsPos360Cir,//0/1:4th轴为旋转轴时,绝对坐标循环功能无效/有效 
    Th4AxisHandyRotate,//0/1:4th轴为旋转轴时,就近旋转/按符号方向旋转
    Th4AxisRelPos360Cir,// 0/1:4th轴为旋转轴时,相对坐标循环功能无效/有效

    // 5th轴的设定
    Th5AxisType0,//设定5th轴类型(0:直线轴 1:旋转轴)
    Th5AxisType1,//设定5th轴类型(0:旋转轴A型 1:旋转轴B型)
    Th5AxisAbsPos360Cir,//0/1:5th轴为旋转轴时,绝对坐标循环功能无效/有效 
    Th5AxisHandyRotate,//0/1:5th轴为旋转轴时,就近旋转/按符号方向旋转 
    Th5AxisRelPos360Cir,//0/1:5th轴为旋转轴时,相对坐标循环功能无效/有效

    
    IS_ABS_ENC_X,// 1:绝对值编码器，0增量编码器
    IS_ABS_ENC_Z,
    IS_ABS_ENC_Y,
    IS_ABS_ENC_4,
    IS_ABS_ENC_5,

    MOTION_DIRECTION_X,//电机旋转方向，0：旋转方向为负，1：旋转方向为正
    MOTION_DIRECTION_Z,
    MOTION_DIRECTION_Y,
    MOTION_DIRECTION_4,
    MOTION_DIRECTION_5,

    XMoveKeyReverse,//X轴移动键是否取反(0:否 1:是)
    ZMoveKeyReverse,//Z轴移动键是否取反(0:否 1:是)
    YMoveKeyReverse,//Y轴移动键是否取反(0:否 1:是)
    Th4MoveKeyReverse,// 4th轴移动键是否取反(0:否 1:是)
    Th5MoveKeyReverse,// 5th轴移动键是否取反(0:否 1:是)


    AXIS_CMR_X,//进给轴每转脉冲数(脉冲输入倍频系数)
    AXIS_CMR_Z,
    AXIS_CMR_Y,
    AXIS_CMR_4,
    AXIS_CMR_5,

    AXIS_CMD_X,//进给轴螺距*1000(脉冲输出分频系数 )
    AXIS_CMD_Z,
    AXIS_CMD_Y,
    AXIS_CMD_4,
    AXIS_CMD_5,

    FERROR_MIN_X,//跟随误差报警限制值
    FERROR_MIN_Z,
    FERROR_MIN_Y,
    FERROR_MIN_4,
    FERROR_MIN_5,

    FERROR_MAX_X,//最高速度跟随误差限制值
    FERROR_MAX_Z,
    FERROR_MAX_Y,
    FERROR_MAX_4,
    FERROR_MAX_5,

    //------------------------------------------------------------------------------------------------------------主轴参数    
    /*
    第一主轴
    */
    SPINDLE_BUS_CTRL_1=100,    // 主轴1控制方式选择(0：总线主轴 1：模拟主轴)
    SPINDLE1_SPEED_OUTPUT_TYPE,    //主轴1模拟控制时速度模式输出（0：模拟电压 1：脉冲）
    IS_CHECK_SPINDLE1_SPEED,      // 切削前(0:不检查 1:检查)主轴1SAR信号      *是否检查主轴转速到达信号
    S1_SERVO_ALM_VOLATE,                   // 0/1:主轴1模拟控制时报警信号为(0:高 1:低)电平报警
    S1_ORI_ONCE,                   // 0/1:主轴1定向(0:每次 1:首次)搜索MARK
    S1_ORI_MODE,                  // 0/1:主轴1定向方式(0:内部 1:外部)
    SPIND_INPUT_DIR_1,                   // 0/1:主轴1输入极性(0:正向 1:负向)
    SPIND_OUT_DIR_1,                   // 0/1:主轴1输出极性(0:正向 1:负向)
    
    SPINDLE_FEEDBACK_MODE_1,//主轴反馈方式（0：内编 1：外编接伺服 2：外编接系统）
    SPINDLE_MOTOR_ENCODER_RESOLUTION_1, //主轴电机的一转脉冲数    
    SPINDLE_ENCODER_RESOLUTION_1,//主轴外编的编码器一转脉冲数

    S1_GEAR1_CMR,//主轴1_档位1_分子
    S1_GEAR1_CMD,//主轴1_档位1_分母
    S1_GEAR2_CMR,
    S1_GEAR2_CMD,
    S1_GEAR3_CMR,
    S1_GEAR3_CMD,
    S1_GEAR4_CMR,
    S1_GEAR4_CMD,
    S1_GEAR5_CMR,
    S1_GEAR5_CMD,
    S1_GEAR6_CMR,
    S1_GEAR6_CMD,
    S1_GEAR7_CMR,
    S1_GEAR7_CMD,
    S1_GEAR8_CMR,
    S1_GEAR8_CMD,

    S1_GEAR1_MAX_SPEED,//各个挡位对应的最大速度
    S1_GEAR2_MAX_SPEED,
    S1_GEAR3_MAX_SPEED,
    S1_GEAR4_MAX_SPEED,
    S1_GEAR5_MAX_SPEED,
    S1_GEAR6_MAX_SPEED,
    S1_GEAR7_MAX_SPEED,
    S1_GEAR8_MAX_SPEED,

    MAX_SPIND_SPEED_1,//主轴最大速度    
    SPINDLE1_SPOT_MOVE,//主轴1点动速度
    SPINDLE1_GEAR_NUM,    //编码器与主轴1齿轮比参数:主轴齿轮数
    S1_ENCODER_GEAR_NUM,    //编码器与主轴1齿轮比参数: 编码器齿轮数

    S1_TAP_GEAR1_JIANXI,//主轴1反转的间隙补偿量(第1档齿轮)
    S1_TAP_GEAR2_JIANXI,
    S1_TAP_GEAR3_JIANXI,
    S1_TAP_GEAR4_JIANXI,
    S1_TAP_GEAR5_JIANXI,
    S1_TAP_GEAR6_JIANXI,
    S1_TAP_GEAR7_JIANXI,
    S1_TAP_GEAR8_JIANXI,

    SPINDLE1_CSAXIS_NUM,        //   主轴1CS轴控制时的进给轴号
    SPINDLE1_ORI_SPEED,         //   主轴1定向速度 
    SPINDLE1_ORI_OFFSET,         //   主轴1定向偏移 
    SPINDLE1_ACCELERATION,         //   主轴1定向加速度
    MIMIC_1,    //  主轴1模拟控制时电压零漂补偿 
    SPINDLE1_SHIFT_OUT_V,    //  主轴1模拟控制换档时输出的电压    //LZ MOD 此参数原来未使用，改为励磁时间使用 2021.11.18
    SPINDLE1_COMP_SPEED_PERCENT,  // 主轴1模拟控制速度一致百分比

    /*
    第二主轴
    */
    SPINDLE_BUS_CTRL_2=200,    // 主轴1控制方式选择(0：总线主轴 1：模拟主轴)
    SPINDLE2_SPEED_OUTPUT_TYPE,    //主轴1模拟控制时速度模式输出（0：模拟电压 1：脉冲）
    IS_CHECK_SPINDLE2_SPEED,      // 切削前(0:不检查 1:检查)主轴1SAR信号      *是否检查主轴转速到达信号
    S2_SERVO_ALM_VOLATE,                   // 0/1:主轴1模拟控制时报警信号为(0:高 1:低)电平报警
    S2_ORI_ONCE,                   // 0/1:主轴1定向(0:每次 1:首次)搜索MARK
    S2_ORI_MODE,                  // 0/1:主轴1定向方式(0:内部 1:外部)
    SPIND_INPUT_DIR_2,                   // 0/1:主轴1输入极性(0:正向 1:负向)
    SPIND_OUT_DIR_2,                   // 0/1:主轴1输出极性(0:正向 1:负向)
    
    SPINDLE_FEEDBACK_MODE_2,//主轴反馈方式（0：内编 1：外编接伺服 2：外编接系统）
    SPINDLE_MOTOR_ENCODER_RESOLUTION_2, //主轴电机的一转脉冲数    
    SPINDLE_ENCODER_RESOLUTION_2,//主轴外编的编码器一转脉冲数

    S2_GEAR1_CMR,//主轴1_档位1_分子
    S2_GEAR1_CMD,//主轴1_档位1_分母
    S2_GEAR2_CMR,
    S2_GEAR2_CMD,
    S2_GEAR3_CMR,
    S2_GEAR3_CMD,
    S2_GEAR4_CMR,
    S2_GEAR4_CMD,
    S2_GEAR5_CMR,
    S2_GEAR5_CMD,
    S2_GEAR6_CMR,
    S2_GEAR6_CMD,
    S2_GEAR7_CMR,
    S2_GEAR7_CMD,
    S2_GEAR8_CMR,
    S2_GEAR8_CMD,

    S2_GEAR1_MAX_SPEED,//各个挡位对应的最大速度
    S2_GEAR2_MAX_SPEED,
    S2_GEAR3_MAX_SPEED,
    S2_GEAR4_MAX_SPEED,
    S2_GEAR5_MAX_SPEED,
    S2_GEAR6_MAX_SPEED,
    S2_GEAR7_MAX_SPEED,
    S2_GEAR8_MAX_SPEED,

    MAX_SPIND_SPEED_2,//主轴最大速度    
    SPINDLE2_SPOT_MOVE,//主轴1点动速度
    SPINDLE2_GEAR_NUM,    //编码器与主轴1齿轮比参数:主轴齿轮数
    S2_ENCODER_GEAR_NUM,    //编码器与主轴1齿轮比参数: 编码器齿轮数

    S2_TAP_GEAR1_JIANXI,//主轴1反转的间隙补偿量(第1档齿轮)
    S2_TAP_GEAR2_JIANXI,
    S2_TAP_GEAR3_JIANXI,
    S2_TAP_GEAR4_JIANXI,
    S2_TAP_GEAR5_JIANXI,
    S2_TAP_GEAR6_JIANXI,
    S2_TAP_GEAR7_JIANXI,
    S2_TAP_GEAR8_JIANXI,

    SPINDLE2_CSAXIS_NUM,        //   主轴1CS轴控制时的进给轴号
    SPINDLE2_ORI_SPEED,         //   主轴1定向速度 
    SPINDLE2_ORI_OFFSET,         //   主轴1定向偏移 
    SPINDLE2_ACCELERATION,         //   主轴1定向加速度
    MIMIC_2,    //  主轴1模拟控制时电压零漂补偿 
    SPINDLE2_SHIFT_OUT_V,    //  主轴1模拟控制换档时输出的电压    //LZ MOD 此参数原来未使用，改为励磁时间使用 2021.11.18
    SPINDLE2_COMP_SPEED_PERCENT,  // 主轴1模拟控制速度一致百分比
    
    //------------------------------------------------------------------------------------------------------------速度类参数
    IsFastFoStop=300,// 0/1:快速进给时,快速进给倍率为Fo时不停止/停止    *
    VanRunG00SpeedMode,//0/1:空运行时,G00运行的速度为手动进给/快速速度
    FEED_SPEED_X,//手动模式下速度
    FEED_SPEED_Z,
    FEED_SPEED_Y,
    FEED_SPEED_4,
    FEED_SPEED_5,    
    
    FAST_SPEED_X,//各个轴的G0速度
    FAST_SPEED_Z,
    FAST_SPEED_Y,
    FAST_SPEED_4,
    FAST_SPEED_5,
    
    AXIS_MAX_SPEED_X,//各个进给轴的最大速度限制
    AXIS_MAX_SPEED_Z,
    AXIS_MAX_SPEED_Y,
    AXIS_MAX_SPEED_4,
    AXIS_MAX_SPEED_5,
    
    AXIS_MIN_SPEED,//所有进给轴的速度下限，轴的起始速度，减速的中止速度
    INIT_RUN_SPEED,    //接通电源时的切削进给速度,上电默认的F值
    FAST_RUN_F0_SPEED,   //快速移动倍率为F0时的快速移动速度

    MAX_VEL,//所有进给轴的速度上限

    //------------------------------------------------------------------------------------------------------------加速度类参数
    FastAccDccType0=400,      // 401.0 FT0~FT1:快速定位加减速类型 (0:直线型 1:前加减速S型/后加减速指数型)  *
    FastAccDccType1,      // 401.1 FT0~FT1:快速定位加减速类型(0:前加减速 1:后加减速)   *
    CutAccDccType0,       // 401.2 CT0~CT1:切削进给加减速类型(0:直线型 1:S型/指数型)   *
    CutAccDccType1,       // 401.3 CT0~CT1:切削进给加减速类型(0:前加减速 1:后加减速)  *
    JOGAccDccStyle,       // 401.4  0/1:JOG运行选择直线/指数型加减速        *
    WheelAccDccStyle,       // 401.5  0/1:手轮运行选择直线/指数型加减速     *
    AccLitEnable,      // 401.6  指数型加减速切削进给加速度是否钳制(0:否 1:是)
    
    //S曲线加速度参数在做S曲线时添加
    FEED_ACC_PERIOD_X,//各个轴JOG和FEED对应的加速度,单位：周期，多少个周期加速到最大速度    
    FEED_ACC_PERIOD_Z,
    FEED_ACC_PERIOD_Y,
    FEED_ACC_PERIOD_4,
    FEED_ACC_PERIOD_5,

    FAST_ACC_PERIOD_X,//各个轴快移对应的加速度,单位：周期，多少个周期加速到最大速度
    FAST_ACC_PERIOD_Z,
    FAST_ACC_PERIOD_Y,
    FAST_ACC_PERIOD_4,
    FAST_ACC_PERIOD_5,

    AXIS_MAX_ACC_PERIOD_X,//各个进给轴的最大加速度限制,单位：周期，多少个周期加速到最大速度
    AXIS_MAX_ACC_PERIOD_Z,
    AXIS_MAX_ACC_PERIOD_Y,
    AXIS_MAX_ACC_PERIOD_4,
    AXIS_MAX_ACC_PERIOD_5,

    MAX_ACC_PERIOD,//所有进给轴的加速度上限，单位：周期，多少个周期加速到最大速度

    //------------------------------------------------------------------------------------------------------------螺距补偿
    IsExcuteScrewComp=500,               // 501.0  0/1:螺距误差补偿功能无效/有效 * 
    REF_SCW_NUM_X,    //   PECORGX  X轴机床零点位置对应的螺距误差补偿位置号,螺距误差补偿原点的位置点
    REF_SCW_NUM_Z,    //   PECORGZ  Z轴机床零点位置对应的螺距误差补偿位置号
    REF_SCW_NUM_Y,    //   PECORGY  Y轴机床零点对应的螺距误差补偿位置号
    REF_SCW_NUM_A,    //   PECORG4   4TH轴机床零点对应的螺距误差补偿位置号
    REF_SCW_NUM_B,    //   PECORG5   5TH轴机床零点对应的螺距误差补偿位置号
    SCW_COMP_DISTANCE_X,    //   PECINTX   X轴螺距误差补偿间隔距离
    SCW_COMP_DISTANCE_Z,    //   PECINTZ   Z轴螺距误差补偿间隔距离
    SCW_COMP_DISTANCE_Y,    //   Y轴螺距误差补偿间隔距离
    SCW_COMP_DISTANCE_A,    //   4TH轴螺距误差补偿间隔距离
    SCW_COMP_DISTANCE_B,    //   5TH轴螺距误差补偿间隔距离
    SCW_COMP_FORD_X,         //  X轴螺距误差补偿倍率  
    SCW_COMP_FORD_Z,         //  Z轴螺距误差补偿倍率   
    SCW_COMP_FORD_Y,         //  Y轴螺距误差补偿倍率                                                     
    SCW_COMP_FORD_A,         //  4TH轴螺距误差补偿倍率                                                      
    SCW_COMP_FORD_B,       //    5TH轴螺距误差补偿倍率      

    //------------------------------------------------------------------------------------------------------------反向间隙    
    JIAN_XI_COMP_VAL_X=600,//反向间隙补偿量
    JIAN_XI_COMP_VAL_Z,
    JIAN_XI_COMP_VAL_Y,
    JIAN_XI_COMP_VAL_4,
    JIAN_XI_COMP_VAL_5,
    JIAN_XI_RET_MINM,             //612 反向间隙补偿确定反向的精度(X0.0001) 


    //------------------------------------------------------------------------------------------------------------回零    
    MACHINE_ZERO_TYPE_X=700,//回零方式:A-B(各个轴单独设置)----0:A方式,1:B方式
    MACHINE_ZERO_TYPE_Z,
    MACHINE_ZERO_TYPE_Y,
    MACHINE_ZERO_TYPE_4,
    MACHINE_ZERO_TYPE_5,
    
    IS_MACHINE_ZERO_SWITCH_X,//回零开关:有-无(各个轴单独设置)----0:无,1:有
    IS_MACHINE_ZERO_SWITCH_Z,
    IS_MACHINE_ZERO_SWITCH_Y,
    IS_MACHINE_ZERO_SWITCH_4,
    IS_MACHINE_ZERO_SWITCH_5,
   
    IS_MACHINE_ZERO_MARK_X, //是否有MARK信号:有-无(各个轴单独设置)----0:无,1:有
    IS_MACHINE_ZERO_MARK_Z,
    IS_MACHINE_ZERO_MARK_Y,
    IS_MACHINE_ZERO_MARK_4,
    IS_MACHINE_ZERO_MARK_5,
    
    MACHINE_ZERO_BEFOR_OR_AFTER_X, //回零位置:档块前-档块后----0:前,1:后
    MACHINE_ZERO_BEFOR_OR_AFTER_Z,
    MACHINE_ZERO_BEFOR_OR_AFTER_Y,
    MACHINE_ZERO_BEFOR_OR_AFTER_4,
    MACHINE_ZERO_BEFOR_OR_AFTER_5,
    
    MACHINE_ZERO_DIRECTION_X,//回零方向----0:坐标负方向,1:坐标正方向
    MACHINE_ZERO_DIRECTION_Z,
    MACHINE_ZERO_DIRECTION_Y,
    MACHINE_ZERO_DIRECTION_4,
    MACHINE_ZERO_DIRECTION_5,
    
    MACHINE_ZERO_HIGH_SPEED_X,//回零高速速度(各个轴单独设置)  
    MACHINE_ZERO_HIGH_SPEED_Z,
    MACHINE_ZERO_HIGH_SPEED_Y,
    MACHINE_ZERO_HIGH_SPEED_4,
    MACHINE_ZERO_HIGH_SPEED_5,
      
    MACHINE_ZERO_LOW_SPEED_X,//回零低速速度(各个轴单独设置)  
    MACHINE_ZERO_LOW_SPEED_Z,
    MACHINE_ZERO_LOW_SPEED_Y,
    MACHINE_ZERO_LOW_SPEED_4,
    MACHINE_ZERO_LOW_SPEED_5,
     
    MACHINE_ZERO_OFFSET_X,//零点偏移量(各个轴单独设置) 
    MACHINE_ZERO_OFFSET_Z,
    MACHINE_ZERO_OFFSET_Y,
    MACHINE_ZERO_OFFSET_4,
    MACHINE_ZERO_OFFSET_5,
        
    MACHINE_ZERO_REMEMBER,//机械零点记忆:记忆-不记忆,如果记忆且已经回零,则直接G0到零点,如果不记忆,则每次都走回零过程--0:不记忆,1:记忆
    Machine_Zero_Axis_Num,// 0/1:手动回零点可以/不能同时选择多轴    
    Pre_Ref_Zero_Hang_Fast,//从接通电源到返回参考点前,手动快速(0:无效,1:有效)
    Mach_Zero_Fast_Or_Jog,// 0/1:参考点建立且记忆后手动返回参考点取快速/手动速度        *
    No_Ref_Point_G28_Deal,// 0/1:参考点没有建立时的G28指令使用挡块/报警  *
    No_Ref_Point_Is_Warn,// 0/1:参考点没建立,指定G28以外指令不报警/报警                *
    Is_M_Zero_Set_Rlt_Coord,//  进行参考点返回的相对坐标(0:不取消,1:取消),取消就是让相对坐标一直是0


    
    //------------------------------------------------------------------------------------------------------------手轮相关
    STEP_AND_HAND=800, //0:单步方式 1:手脉方式
    
    X_WHEEL_LENGTH,//0/1:X轴手轮或单步按坐标位置/机床位置移动
    
    WHEEL_STOP_STYLE,//0/1:手轮轮盘转动位移量(不需/需要)全部运行    *手轮移动量是否选择完全运行
    
    HAND_WHEEL_DIRECTION_X,// 0/1:手轮顺/逆时针旋转时坐标增大
    HAND_WHEEL_DIRECTION_Z,
    HAND_WHEEL_DIRECTION_Y,
    HAND_WHEEL_DIRECTION_4,
    HAND_WHEEL_DIRECTION_5,
    
    HAND_WHEEL_MAX_SPEED_X,//各个轴的手轮最大速度
    HAND_WHEEL_MAX_SPEED_Z,
    HAND_WHEEL_MAX_SPEED_Y,
    HAND_WHEEL_MAX_SPEED_4,
    HAND_WHEEL_MAX_SPEED_5,
    
    //0：不使用，1使用。是否使用编码器接口做为各个手轮的输入值,电子车专用参数
    //为了防止切换后导致的数值突然增加，再修改后需要重新同步一下手轮的值
    //设置这个变量为0-----MOTION_#defineERNAL->WHEEL_INFO[AXIS].ALREADY_SYNC_HARDWARE_VAL
    //目前只使用了WHEEL_USED_ENCODE，用作总开关
    WHEEL_USED_ENCODE,
    //WHEEL_USED_ENCODE_Z,
    //WHEEL_USED_ENCODE_Y,
    //WHEEL_USED_ENCODE_4,
    //WHEEL_USED_ENCODE_5,

    //------------------------------------------------------------------------------------------------------------刀补
    TOOL_MAX_NUM=900,//总刀位数
    RUN_COMP_MODE,// 901.0   0/1:以移动方式/坐标偏移方式执行刀具偏置
    DEFAULT_COMP_DORR,// 901.1  0/1:刀具补偿值以直径/半径值表示     
    IS_TOOL_WORK_OFT,// 901.2  NO.0刀补平移工件坐标系是否有效(0:无效 1:有效)

    OFT_MAX_VAL,    // 刀具偏置&磨损界面中每次输入的刀具磨损量的正/负极限量
    CR_C_DELTA,// 0904  刀具半径补偿C中沿拐角外侧移动时忽视矢量的极限值(系统保留,不显示)
    CR_MAX_ERROR,// 0905 刀具半径补偿C的最大值误差值(系统保留,不显示)


    //------------------------------------------------------------------------------------------------------------限位    
    SHIELD_EXTERN_OUT_ESP=1000,// 1001.0 是否检查外接急停信号(0:检查 1:不检查)
    SHIELD_EXTERN_IN_ESP,// 1001.1  是否检查内置急停信号(0:检查 1:不检查)
    ALL_AXIS_LOCK_SINGLE,// 1001.2  所有轴互锁信号是否有效    *
    ESP_ALM_PERMIT,// 1001.3  是否忽略急停报警(0:否 1:是)
    HARD_LIMIT_POS_ALM_PERMIT,  // 1001.4  是否忽略硬限位报警(0:否 1:是)

    CHECK_SOFT_LIMIT_BEFOR_MOVE,// 1002.0  移动前是否行程检测    *
    RefPoint2Type,// 1002.1  第二行程限位的禁入区域(0:里面,1:外面)                 *
    PreRefZeroPosCheck,// 1002.2  接通电源后到手动返回参考点前是否进行行程检测(1:是)    *
    PreLimtPosAlm,// 1002.3  发出超程指令时,在超程前/后报警              
    FirstG12OrG13,// 1102.4  接通电源时或清除状态时设定(0:G12,1:G13)      *


    SOFT_LIMIT_MAX_X,//各个轴的软限位上限
    SOFT_LIMIT_MAX_Z,
    SOFT_LIMIT_MAX_Y,
    SOFT_LIMIT_MAX_4,
    SOFT_LIMIT_MAX_5,

    SOFT_LIMIT_MIN_X,//各个轴的软限位下限
    SOFT_LIMIT_MIN_Z,
    SOFT_LIMIT_MIN_Y,
    SOFT_LIMIT_MIN_4,
    SOFT_LIMIT_MIN_5,

    //------------------------------------------------------------------------------------------------------------程序工艺
    PrgAutoLineNum=1100,     // 1105   自动插入程序段号时的段号增量值
    CtrlPrecDegree,     // 1106  切削进给到位精度
    RadiusError,    // 1107   圆弧半径误差最大值
    CtrlArcPrecDegree,         //1108   圆弧插补控制精度，最大允许弓高误差
    ArcMaxAcc,     // 1109  圆弧插补法向加速度限制，最大机床允许加速度
    ArcRToMinSpeed,     // 1110  圆弧插补法向加速度嵌位的低速下限
    G96BaseAxis,            //1111  表面速度控制时作为计数基准的轴  
    G96MinSpeed,    //  1112  恒线速(G96)控制下,主轴的最低转速   
    AgainStartAxisTurn,      // 1113  移动到程序再开始位置的各轴移动顺序 
    NeedAllWorkNum,    // 1117  需要加工总零件数
    AllWorkNum,    // 1118  已加工总零件数  
    PowerAllTime,    // 1119  通电时间的累计值(小时)
    CuttingAllTime,    // 1120  切削时间的累计值(小时)
    
    //------------------------------------------------------------------------------------------------------------螺纹    
    THREAD_EXIT_TRAIL_LEN=1200, //螺纹切削时的退尾长度(0.1*LUOW)
    
    THREAD_EXIT_TRAIL_TIME,//螺纹退尾时短轴加速时间常数
    
    THREAD_MIN_SPEED,//螺纹切削时长轴的起始速度
    
    THREAD_SP_SPEED_VAR,//螺纹加工主轴转速波动限制值（设为0表示不检测） 
    
    SP_SAMP_TIMES, //螺纹加工时主轴速度采样周期
    
    THREAD_TAIL_SPEED,//螺纹加工退尾短轴速度（设为0按螺纹切削进给速度退尾）
    
    THREAD_LAD_TIME1,//螺纹切削长轴加速度时间常数

    //------------------------------------------------------------------------------------------------------------攻丝
    IfTapCanVanRun=1300,// 1301.0  攻丝期间,空运行(0:无效,1:有效)
    TapSpidleCtrlStyle,// 1301.1    刚性攻丝时主轴控制方式(0:跟随,1:伺服)
    RigidTap_HighSpeedPeck,// 1301.2  攻丝是否变为高速深孔攻丝循环(0:否 1:是)
    RigidTap_FrontExactStop,// 1301.3  柔性攻丝开始时,主轴是否进行准停(0:否 1:是)
    RigidTap_Tool_IlkTimec,// 1301.4  刚性攻丝进刀,退刀是否使用相同的时间常数(0:否 1:是)
    RigidTap_Recede_DynaEna,// 1301.5  刚性攻丝退刀时,倍率是否有效(0:否 1:是)
    RigidTap_Recede_Dyna,// 1301.6  刚性攻丝退刀倍率(0:1%,1:10%)

    RigidTap_Recede_Dyn,     // 1302 RTAPBACKRATE 刚性攻丝退刀时的倍率值
    RigidTapMaxSpeed,     // 1303  CAMAX_S 刚性攻丝允许的最高主轴转速
    DeepBoreRecedeSpace,     //1304  深孔攻丝循环时回退量或留空量
    GreaGrade1ADTime,          //1305 主轴与攻丝轴的直线加减速时间常数(第1档齿轮)                                                      
    GreaGrade2ADTime,          //1306  主轴与攻丝轴的直线加减速时间常数(第2档齿轮)                                                      
    GreaGrade3ADTime,          //1307  主轴与攻丝轴的直线加减速时间常数(第3档齿轮)
    GreaGrade4ADTime,          //1308  主轴与攻丝轴的直线加减速时间常数(第4档齿轮)
    GreaGrade5ADTime,        //1309  主轴与攻丝轴的直线加减速时间常数(第5档齿轮)
    GreaGrade6ADTime,          //1310  主轴与攻丝轴的直线加减速时间常数(第6档齿轮)
    GreaGrade7ADTime,          //1311  主轴与攻丝轴的直线加减速时间常数(第7档齿轮)
    GreaGrade8ADTime,          //1312  主轴与攻丝轴的直线加减速时间常数(第8档齿轮)
    GreaGrade1UpADTime,       //1313  退刀时主轴与攻丝轴的时间常数(第1档齿轮)                                                          
    GreaGrade2UpADTime,       //1314  退刀时主轴与攻丝轴的时间常数(第2档齿轮)                                                          
    GreaGrade3UpADTime,       //1315  退刀时主轴与攻丝轴的时间常数(第3档齿轮)                                                          
    GreaGrade4UpADTime,       //1316  退刀时主轴与攻丝轴的时间常数(第3档齿轮)                                                          
    GreaGrade5UpADTime,       //1317  退刀时主轴与攻丝轴的时间常数(第3档齿轮)                                                          
    GreaGrade6UpADTime,       //1318  退刀时主轴与攻丝轴的时间常数(第3档齿轮)                                                          
    GreaGrade7UpADTime,       //1319  退刀时主轴与攻丝轴的时间常数(第3档齿轮)                                                          
    GreaGrade8UpADTime,       //1320  退刀时主轴与攻丝轴的时间常数(第3档齿轮) 

    //------------------------------------------------------------------------------------------------------------固定循环参数
    G71G72SingleEnterLen=1400,//G71/G72循环车削时的单次进刀量
    G71G72SingleExitLen,//G71/G72循环车削时的单次退刀量
    G73ExitLenX,//G73循环车削时,X轴的退刀量  (退刀量总和)
    G73ExitLenZ,//G73循环车削时,Z轴的退刀量  (退刀量总和)
    G73CutNum,//G73循环车削的切削次数
    G74G75ExitLenZ,//G74/G75循环车削Z/X轴的退刀量
    G76RepeatTimes,//G76循环精加工的重复次数
    G76ToolPointAngle,//G76循环中的刀尖角度(0,29,30,55,60,80)
    G76MinCutDepth,//G76循环中的最小切削深度
    G76CutRemain,//G76循环中的精加工余量


    //------------------------------------------------------------------------------------------------------------系统配置
    RADIUS_PRG=1500,//0:直径编程 1:半径编程   *仅对X轴 *影响的是界面上输入输出值是直径还是半径
    MIN_SIZE_STYLE,// 输入单位(0:公制输入 1：英制输入) *
    LineAxisMinG20G21,//    0/1:最小指令单位为公制/英制,重新开机后有效 *  (输出单位)
    G20G21_CompSet,//   0/1:公英制输入转换时刀补值不转换/自动转换 *
    G20G21_WorkCrdSet,//    0/1:公英制输入转换时工件坐标系值不转换/自动转换 *


    M02IsReset,//     0/1:M02执行后光标不返回/返回开头 *
    M30IsReset,//     0/1:M30执行后光标不返回/返回开头 *
    ResertIsReturnHead,//   复位时光标返回程序开头在(0:编辑方式 1:任何方式)有效   *非编辑方式复位光标是否返回程序起始位置
    PrgAutoLine,//   SEQ:是否自动插入顺序号0:不插入,1:插入    *
    MdiToM30Clear,//   程序状态界面执行M02,M30或%时是否清除已编制程序    *
    MdiResetClear,//  程序状态界面下复位键是否删除编制的程序    *

    FIRST_G01_OR_G00,//   接通电源或清除状态时(0:G00方式,1:G01方式)    *
    FastTrackStyle,// 0/1:定位(G00)插补轨迹为非直线型/直线型    *
    AngleSpdCtrl,//   程序段与程度段之间(0:平滑过渡 1:准确执行到位)      
    AutoAngleLimite,//   自动拐角倍率功能是否有效(0:否 1:是)
    IsCancelG28InInterPnt,//   0/1:G28,G30指令移动到中间点,不取消/取消半径补偿
    IsInterferenceChk,//  半径补偿干涉检查(0:否,1:是)进行
    Default_CompRadiusMode,//   0/1:刀具半径补偿中起刀形式A/B型    *

    MacroPrgSingleValid,//   宏程序指令语句中是否可以使用单段
    MacroPrgNotDelay,//   宏程序指令语句中不予延时(0:延时 1:不延时)
    MinuteDegreePlatformSIM,//   分度指令和其它控制轴指令同段是否报警(0:不报警,1:除G0,G28,G30等外报警)
    FastG96SpTerminus,//   G0快速定位时计算G96主轴转速(0:据终点坐标 1:据当前坐标)
    ClampSpiSpAfterFord,//   G96主轴转速钳制(0:主轴倍率之前 1:主轴倍率之后)
    G99G04Vallite,//   每转进给方式下,G04是否为每转暂停(0:否 1:是)

    OutUserAlmPermit,//  (0:不忽略 1:忽略)外部用户报警
    FeedMotorAlmPermit,//   是否忽略进给轴驱动器报警(0:否 1:是)
    SpidleMotorAlmPermit,//   是否忽略主轴驱动器报警(0:否 1:是)
    IsUseingOutLockEdit,//   是否使用外部编辑锁(0:否 1:是)
    ShieldExternST,//   外接循环启动信号(0:有效 1:无效)
    ShieldExternSP,//   外接暂停信号(0:有效 1:无效)
    Language_en,//   选择英文(0:汉语 1:英语)


    REST_SINGL_OUT_TIM,    //   复位信号输出时间

    DA1_LOW_VAL,//da1对应接口的能获取的最小值
    DA1_HIGH_VAL,//da1对应接口的能获取的最大值

    

    //------------------------------------------------------------------------------------------------------------总线参数    
    
    SLV_ST_NUM=1600,//从站数量
    
    SLV_ADDR_1,//从站地址
    SLV_ADDR_2,
    SLV_ADDR_3,
    SLV_ADDR_4,
    SLV_ADDR_5,
    SLV_ADDR_6,
    SLV_ADDR_7,
    SLV_ADDR_8,
    SLV_ADDR_9,
    SLV_ADDR_10,
    
    SLV_TYPE_1,//从站类型：0-进给轴，1-IO盒，2-主轴
    SLV_TYPE_2,
    SLV_TYPE_3,
    SLV_TYPE_4,
    SLV_TYPE_5,
    SLV_TYPE_6,
    SLV_TYPE_7,
    SLV_TYPE_8,
    SLV_TYPE_9,
    SLV_TYPE_10,    
    
    
    //------------------------------------------------------------------------------------------------------------预留*/    
    

}PARA_NUM_t;

#define PARA_NUM 2000

#define PARA_TYPE_INT 0
#define PARA_TYPE_DOUBLE 1

#define PARA_VISIBLE_ENABLE 1
#define PARA_VISIBLE_DISABLE 0
/*
参数结构体
*/
struct para_s
{
    int type;//参数类型，0-int数参,1-double数参
    char macro_name[50];//对应宏名字
    char comment[200];//参数描述说明

    //各个类型对应的值,当前值，最小值，最大值    
    union 
    {
        int     int_val;
        double  double_val;
    }cur_val,min_val,max_val;
    
    char visible;//是否可见 0不可见 1可见
};

extern struct para_s * para;


#endif //INIT_H
    
