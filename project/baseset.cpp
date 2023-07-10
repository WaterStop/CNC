#include "baseset.h"


int scr_size = 1;//屏幕分辨率 0:800*600  1:1024*768
int currect_screen = -1;//当前屏幕
int limit_lev = 1;//权限等级
int m_nValue;//指针旋转角度
int MainAxisState=0;//主轴状态 0：停止 1：顺时针 2：逆时针
bool popupwin_flg = 0;//是否启动左侧弹窗
bool popupwin_flg1 = 0;//是否启动右侧弹窗
int page = 1;
int cur_work_mod = -1;//当前工作模式
int last_work_mod = 0;//上一次工作模式
QString edit_val;
int cur_dir;//当前轴运动方向
int textboxFlag;
int is_work = 0;//是否处于工作状态 0为否
bool is_output_scr = 0;//是否在输出参数屏 0:否 1:是
int cur_Node = 1;//当前节点，用于节点数据修改
int save_flg = 0;//保存由弹窗触发还是按钮触发 0：按钮 1：弹窗
bool modify_flg = 0;//是否为修改状态 0：否 1：是
bool val_change = 0;//工艺参数是否修改 0：否 1：是
//MachineProcess *dealInterfaceData;

MachineProcess *dealInterfaceData = new MachineProcess(400,320,380,170,380);
//MachineSequene *machineinfo = new MachineSequene();
bool first_input = 0;
bool input_clear = 1;//是否清除控件内数值，1是  0否
bool luowen_set_flg = 0;//螺纹设置是否打开 0：否 1：是
bool input_ok_flg = 0;
int cur_luowen_unit =0;//当前螺纹单位
int fixedval_mod = 0;//固定值弹窗类型 0：螺纹 1：锥螺纹 2：进给
double tmp_fixval = 0;//临时固定值储存
int language = 0;//当前制式 0：公制 1：英制
st_luowen st_lw;
bool barstock_flg = 1;//棒料设置标志位 0：否 1：是
int barstock_width;//棒料长
int barstock_height;//棒料宽
int barstock_L1;//起刀点x
int barstock_D1;//起刀点z

QString Warn_File_List[WarnMaxNum];
QString WarnNote_File_List[WarnMaxNum];
QString RUNSTATE_File_List[17];
int warn_flg =0;//报警提示，0：否 1：是
bool RadiusPrg = 0;//0:直径编程  1：半径编程
QTimer *main_timer;//主定时器
int limittime;//允许时间-小时
int alarmtime;//提前报警
uint Remainingtime;//剩余时间(总共时间，大于锁机)
QString User_Name;//用户编码
bool protect_flg = 0;//是否开启限时保护，0否 1是
bool has_set_protect = 0;//是否设置过限时保护，0否 1是
int cur_year;
int cur_mon;
int cur_day;
int cur_hour;
int cur_min;
int cur_sec;
int cur_week;


//第一个参数是字体（微软雅黑），第二个是字体大小(单位为pt)，第三个是加粗（50代表正常），第四个是斜体（true代表斜体）
QFont weiruanyahei4("Microsoft YaHei", 10, 50, false);
QFont weiruanyahei6("Microsoft YaHei", 12, 50, false);
QFont weiruanyahei8("Microsoft YaHei", 14, 50, false);
QFont weiruanyahei10("Microsoft YaHei", 16, 50, false);
QFont weiruanyahei11("Microsoft YaHei", 17, 50, false);
QFont weiruanyahei12("Microsoft YaHei", 18, 50, false);

QFont songti4("SimSun", 4, 50, false);
QFont songti6("SimSun", 6, 50, false);
QFont songti8("SimSun", 8, 50, false);
QFont songti10("SimSun", 10, 50, false);
QFont songti12("SimSun", 12, 50, false);
QFont songti11("SimSun", 14, 50, false);

BaseSet::BaseSet()
{
    //main_timer = new QTimer;
    //main_timer->start(50);
}

char *CNCStrCpy(char *strDest, const char *strSrc, int cpyNum)
{
    strncpy(strDest, strSrc, cpyNum - 1);
    strDest[cpyNum - 1] = 0;
    return strDest;
}

int  GetIndexByLine(int iLine)  /*由序号得到 数组的索引*/
{
    int index;

    if (iLine >= 0 && iLine <= 50) {
        index = iLine;
    }
    else if (iLine >= 100 && iLine <= 199) {
        index = iLine - 100 + 51;
    }
    else if (iLine >= 500 && iLine <= 999) {
        index = iLine - 500 + 151;
    }
    else if (iLine >= 1000 && iLine <= 1047) {
        index = iLine - 1000 + 750;
    }
    else if (iLine >= 1100 && iLine <= 1147) {
        index = iLine - 1100 + 798;
    }
    else if ((iLine >= 1500) && (iLine < 1500 + OftMaxNum - 1)) { /* 32个X轴偏置*/
        index = iLine - 1500 + 846;
    }
    else if ((iLine >= 1600) && (iLine < 1600 + OftMaxNum - 1)) {
        index = iLine - 1600 + 878;
    }
    else if ((iLine >= 1700) && (iLine < 1700 + OftMaxNum - 1)) {
        index = iLine - 1700 + 910;
    }
    else if ((iLine >= 1800) && (iLine < 1800 + OftMaxNum - 1)) {
        index = iLine - 1800 + 942;
    }
    else if ((iLine >= 1900) && (iLine < 1900 + OftMaxNum - 1)) {
        index = iLine - 1900 + 974;
    }
    else if ((iLine >= 2000) && (iLine < 2000 + OftMaxNum - 1)) {
        index = iLine - 2000 + 1006;
    }
    else if ((iLine >= 2100) && (iLine < 2100 + OftMaxNum - 1)) {
        index = iLine - 2100 + 1038;
    }
    else if ((iLine >= 2200) && (iLine < 2200 + OftMaxNum - 1)) {
        index = iLine - 2200 + 1070;
    }
    else if (iLine == 3000) {
        index = iLine - 3000 + 1102;
    }
    else if (iLine >= 3500 && iLine <= 3755) {
        index = iLine - 3500 + 1103;
    }
    else if (iLine >= 4000 && iLine <= 4030) {
        index = iLine - 4000 + 1359;
    }
    else if (iLine >= 5001 && iLine <= 5030) {
        index = iLine - 5001 + 1390;
    }
    else if (iLine >= 5201 && iLine <= 5235) {
        index = iLine - 5201 + 1420;
    }
    else {
        index = -1;
    }

    return index;
}
