#ifndef HARDWARE_ADDR_H
#define HARDWARE_ADDR_H



//输入
#define HW_ENC1 0x48//编码器1
#define HW_ENC2 0x4A//编码器2

#define HW_Z_SIGNAL1 0x58//z信号1
#define HW_Z_SIGNAL2 0x5A//z信号2

#define HW_SPIN_I 0X60//主轴IO的输入

#define HW_IN_0_15 0X68//本地输入0-15
#define HW_IN_16_31 0X6C//本地输入16-32

#define HW_MPG_IN 0X7C//本地输入MPG

#define HW_AUX_IN 0X6E//本地输入-附加面板输入，包括主轴倍率(J19)、进给倍率(J20)、附加面板输入(J21)

#define HW_WHEEL 0XA4//手轮

#define HW_AUX_WHEEL 0XA8//附加面板手轮接口


//输出
#define HW_DA1 0x40//模拟量输出1
#define HW_DA2 0x42//模拟量输出2

#define HW_PULSE1 0x20//脉冲输出1
#define HW_PULSE2 0x22//脉冲输出2


#define HW_Z_ENABLE 0x50//z信号使能，0位表示主轴1，1位表示主轴2

#define HW_Z_CLEAR 0x54//z信号清零，0位表示主轴1，1位表示主轴2


#define HW_SPIN_O 0X64//主轴IO的输入

#define HW_OUT_0_15 0X70//本地输出0-15
#define HW_OUT_16_31 0X74//本地输出16-32

#define HW_AUX_OUT 0X76//本地输出-附加面板输出



//其他
#define HW_KEY_OUT 0XB0//键盘写地址
#define HW_KEY_IN 0XB2//键盘读地址

#define HW_LED_OUT 0XE0//操作站指示灯地址,写

#define HW_WDT_ENABLE 0X44//看门狗使能

#define HW_WDT_COUNT 0X4C//看门狗计数








#endif //HARDWARE_ADDR_H
