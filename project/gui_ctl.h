#ifndef GUI_CTL_H
#define GUI_CTL_H


/*
当前工艺选择
*/
typedef enum {
    GUI_BANG_LIAO = -1,
    GUI_WAI_YUAN1,
    GUI_WAI_YUAN2,
    GUI_WAI_YUAN3,
    GUI_DUAN_MIAN1,
    GUI_DUAN_MIAN2,
    GUI_DUAN_MIAN3,
    GUI_LI_KONG1,
    GUI_LI_KONG2,
    GUI_LI_KONG3,
    GUI_LI_KONG4,
    GUI_LI_KONG5,
    GUI_ZHUI_MIAN1,
    GUI_ZHUI_MIAN2,
    GUI_ZHUI_MIAN3,
    GUI_ZHUI_MIAN4,
    GUI_LUO_WEN1,
    GUI_LUO_WEN2,
    GUI_LUO_WEN3,
    GUI_LUO_WEN4,
    GUI_DAO_JIAO1,
    GUI_DAO_JIAO2,
    GUI_DAO_JIAO3,
    GUI_DAO_JIAO4,
    
} TECH_t;

struct gui_ctl_s
{
    int head;
    int tail;

    //开始总线通讯
    //GUI启动后设置为1，任务处理此变量，如果为1，
    //则
    // 1、任务发送开始通讯命令到运动，然后运动处理
    // 2、设置该变量为2，防止重复发送
    int start_bus;

    /*
    当前选择的模式
    0-自动
    1-手动单工艺
    2-手动单刀
    */
    int current_mode;

    /*
    由于模式切换有可能出现不允许切换的情况，所以界面应该设置的模式是这个变量
    然后任务模块判断，是否可以切换，如果可以切换就把当前的模式current_mode切
    换到next_mode,否则把next_mode赋值为current_mode
    */
    int next_mode;
    
    //回零请求
    //由界面设置为1，任务处理后设置为0
    int request_mac_home[5];

    int request_g96;
    int request_g97;
    int request_g98;
    int request_g99;

    int current_tech;//当前工艺

    char mdi[200];//MDI数据，由界面设置，循环启动后解释器读取这个字符串

    //诊断界面用
    int temp_int[100];//未使用
    double temp_dou[100];//给此数组赋值，界面会在诊断界面显示出来
    char temp_char[200][20];//对应上面的temp_dou数组，为描述信息


};

extern struct gui_ctl_s *gui_ctl;

#endif //GUI_CTL_H
