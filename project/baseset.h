#ifndef BASESET_H
#define BASESET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QtMath>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QGraphicsView>
#include <QPixmap>
#include<QString>
#include<QPen>
#include<QApplication>
#include <QTimer>
#include<QFont>
#include<QDomDocument>
#include <MachineProcess.h>
#include "mylineedit.h"
#include "MachineSequence.h"
#include <QGraphicsDropShadowEffect>
//#include "global_variable.h"
#include <QAbstractListModel>
#include<QTextEdit>
#include <QList>
#include <QVector>
#include <QListView>
#include <QTimerEvent>
#include"QFileInfoList"
#include <QDir>
#include<QDialog>
#include<QThread>
#include<QTableWidgetItem>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QHeaderView>
#include<QFileDialog>
#include<QDateTime>
#include<QMessageBox>
#include<QSignalMapper>
#include<QTextCodec>
#include<QProcess>
#include<QFileInfo>
#include <cstdlib>
#include <unistd.h>
#include "cnavview.h"
#include "cnavdelegate.h"
#include "cnavmodel.h"
#include"plc.h"
#include"shm.h"
#include "motion.h"
#include"decode.h"
#include "plc_plc_pic.h"
#include "plc_fun_cmd.h"
#include "gui_ctl.h"
#include "para.h"
//#include "m3.h"

class MachineProcess;



#define debug_on 1 //调试状态

//当前屏幕
#define scr_bangliao      -1
#define scr_waiyuan1      bangliao+1
#define scr_waiyuan2      bangliao+2
#define scr_waiyuan3      bangliao+3
#define scr_duanmian1     bangliao+4
#define scr_duanmian2     bangliao+5
#define scr_duanmian3     bangliao+6
#define scr_likong1       bangliao+7
#define scr_likong2       bangliao+8
#define scr_likong3       bangliao+9
#define scr_likong4       bangliao+10
#define scr_likong5       bangliao+11
#define scr_zhuimian1     bangliao+12
#define scr_zhuimian2     bangliao+13
#define scr_zhuimian3     bangliao+14
#define scr_zhuimian4     bangliao+15
#define scr_luowen1       bangliao+16
#define scr_luowen2       bangliao+17
#define scr_luowen3       bangliao+18
#define scr_luowen4       bangliao+19
#define scr_daojiao1      bangliao+20
#define scr_daojiao2      bangliao+21
#define scr_daojiao3      bangliao+22
#define scr_daojiao4      bangliao+23

#define scr_SET 40
#define scr_alminfo scr_SET+1
#define scr_almnote scr_SET+2
#define scr_datapara scr_SET+3
#define scr_dgn scr_SET+4
#define scr_lim_and_time scr_SET+5
#define scr_over_lim_set scr_SET+6
#define scr_internet_set scr_SET+7
#define scr_file_manage scr_SET+8
#define scr_back_up scr_SET+9

//工艺选择模式
#define bangliao      -1
#define waiyuan1      0
#define waiyuan2      1
#define waiyuan3      2
#define duanmian1     3
#define duanmian2     4
#define duanmian3     5
#define likong1       6
#define likong2       7
#define likong3       8
#define likong4       9
#define likong5       10
#define zhuimian1     11
#define zhuimian2     12
#define zhuimian3     13
#define zhuimian4     14
#define luowen1       15
#define luowen2       16
#define luowen3       17
#define luowen4       18
#define daojiao1      19
#define daojiao2      20
#define daojiao3      21
#define daojiao4      22


//工艺图运动方向标志位
#define Xplus      0//x+
#define Xneg      1//x-
#define Zplus      2//z+
#define Zneg      3//z-

//螺纹tp模式
#define mode_mm 0
#define mode_inch 1
#define mode_MOD 2
#define mode_DP 3

//固定值弹窗标志位
#define fix_luowen 0
#define fix_zhuiluowen 1
#define fix_feed 2

//工艺列表弹出菜单
#define jianqie 0
#define yidong 1
#define fuzhi 2
#define shanchu 3
#define zhantie 4
#define bianji 5
#define tianjia 6

#define USERERR -1

#define WarnMaxNum 20000
#define ErrorMaxNum 20000

//#define scr_size //1   //0:800*600   1:104*768
extern int scr_size;
extern int currect_screen;
extern int limit_lev;//权限等级
extern int m_nValue;
extern int MainAxisState;
extern bool popupwin_flg;
extern bool popupwin_flg1;
extern int page;
extern int cur_work_mod;
extern int last_work_mod;
extern int cur_dir;
extern QString edit_val;

extern MachineProcess *dealInterfaceData;
//extern MachineSequene *machineinfo;
extern bool first_input;
extern bool input_clear;
extern bool luowen_set_flg;
extern bool input_ok_flg;
extern int cur_luowen_unit;
extern int fixedval_mod;
extern double tmp_fixval;
extern int language;
extern int is_work;
extern bool is_output_scr;
extern int cur_Node;
extern int save_flg;//保存由弹窗触发还是按钮触发 0：按钮 1：弹窗
extern bool modify_flg;//是否为修改状态 0：否 1：是
extern bool val_change;//工艺参数是否修改 0：否 1：是
extern bool barstock_flg;//棒料设置标志位 0：否 1：是
extern int barstock_width;//棒料长
extern int barstock_height;//棒料宽
extern int barstock_L1;//起刀点x
extern int barstock_D1;//起刀点z
extern bool RadiusPrg;//0:直径编程  1：半径编程
//extern QTimer *main_timer;//主定时器

extern QString Warn_File_List[ErrorMaxNum];//报警内容
extern QString WarnNote_File_List[ErrorMaxNum];//报警注释
extern QString RUNSTATE_File_List[17];//运行状态提示
extern int warn_flg;//报警提示，0：否 1：是
extern int limittime;//允许时间-小时
extern int alarmtime;//提前报警
extern uint Remainingtime;//剩余时间(总共时间，大于锁机)
extern QString User_Name;//用户编码
extern bool protect_flg;//是否开启限时保护，0否 1是
extern bool has_set_protect;//是否设置过限时保护，0否 1是

extern int cur_year;
extern int cur_mon;
extern int cur_day;
extern int cur_hour;
extern int cur_min;
extern int cur_sec;
extern int cur_week;

extern QFont weiruanyahei4;
extern QFont weiruanyahei6;
extern QFont weiruanyahei8;
extern QFont weiruanyahei10;
extern QFont weiruanyahei12;
extern QFont weiruanyahei11;

extern QFont songti4;
extern QFont songti6;
extern QFont songti8;
extern QFont songti10;
extern QFont songti12;
extern QFont songti11;

typedef struct
{
    int duotou;
    double qishijiaodu;
    bool shuaiwei;
    bool cuoweijiagong;
    double cuoweijuli;
}st_luowen;
extern st_luowen st_lw;
class BaseSet
{
public:
    BaseSet();
};

extern char *CNCStrCpy(char *strDest, const char *strSrc, int cpyNum);
extern int  GetIndexByLine(int iLine);  /*由序号得到 数组的索引*/

#endif // BASESET_H
