#include "baseset.h"


int scr_size = 1;//屏幕分辨率 0:800*600  1:1024*768
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
//MachineProcess *dealInterfaceData;

MachineProcess *dealInterfaceData = new MachineProcess(400,320,380,170,3800);
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

QString Warn_File_List[WarnMaxNum];
int warn_flg =0;//报警提示，0：否 1：是
bool RadiusPrg = 0;//0:直径编程  1：半径编程
QTimer *main_timer;//主定时器



//第一个参数是字体（微软雅黑），第二个是字体大小(单位为pt)，第三个是加粗（50代表正常），第四个是斜体（true代表斜体）
QFont weiruanyahei4("Microsoft YaHei", 4, 50, false);
QFont weiruanyahei6("Microsoft YaHei", 6, 50, false);
QFont weiruanyahei8("Microsoft YaHei", 8, 50, false);
QFont weiruanyahei10("Microsoft YaHei", 10, 50, false);
QFont weiruanyahei12("Microsoft YaHei", 12, 50, false);
QFont weiruanyahei11("Microsoft YaHei", 14, 50, false);

QFont songti4("SimSun", 4, 50, false);
QFont songti6("SimSun", 6, 50, false);
QFont songti8("SimSun", 8, 50, false);
QFont songti10("SimSun", 10, 50, false);
QFont songti12("SimSun", 12, 50, false);
QFont songti11("SimSun", 14, 50, false);

BaseSet::BaseSet()
{
    main_timer = new QTimer;
    main_timer->start(50);
}

char *CNCStrCpy(char *strDest, const char *strSrc, int cpyNum)
{
    strncpy(strDest, strSrc, cpyNum - 1);
    strDest[cpyNum - 1] = 0;
    return strDest;
}
