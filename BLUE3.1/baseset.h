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
#include <QList>
#include <QVector>
#include <QListView>
#include <QTimerEvent>
#include <QDir>
#include<QDialog>
#include<QTableWidgetItem>
#include <cstdlib>
#include "cnavview.h"
#include "cnavdelegate.h"
#include "cnavmodel.h"
#include"plc.h"
#include"shm.h"
#include "motion.h"
#include "plc_plc_pic.h"
#include "plc_fun_cmd.h"

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

#define WarnMaxNum 10000
#define ErrorMaxNum 10000

//#define scr_size //1   //0:800*600   1:104*768
extern int scr_size;
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
extern bool barstock_flg;
extern int barstock_width;//棒料长
extern int barstock_height;//棒料宽
extern bool RadiusPrg;//0:直径编程  1：半径编程
extern QTimer *main_timer;//主定时器

extern QString Warn_File_List[ErrorMaxNum];
extern int warn_flg;//报警提示，0：否 1：是

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

#endif // BASESET_H
