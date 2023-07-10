#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "baseset.h"
#include "change_screentip.h"
#include "set_over_limit.h"

//class PopupWin1;
#define MAX_ERROR_NUM 32

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Ui::Widget *ui;
    Widget *wedget1;
    void resizeEvent(QResizeEvent *event);
    void show_tipInfo();

private:
   void set_wg1();
   void set_background();
   void set_widget_size();
   void set_widget_button();
   void show_wg_popwin();
   void deal_slot();
   void screen_dis();//切换界面时调用
   void show_keybord();
   void close_keyboard();
   void work_info_init();
   void addWorkInfo(int index);//向工艺列表添加图标
   void goto_setcsreen();
   void close_worklist_scr();//关闭所有工作列表界面
   void Save_Info();//保存当前页面数据到节点
   void Info_init();
   void load_warnInfo();
   void load_run_state_Info();   
   void get_LimTime();//获取剩余时间
   void load_warn_text(QString str);
   void CNC_Warning();
   void to_barstock_set();//跳转至棒料设置界面
   void update_time();
   void to_protect();//进行过期保护
   //void update_info();
   change_screentip* Tip;
   int position_index;//节点号
   QTimer *timer = new QTimer;
   QTimer *t_warn = new QTimer;
   QLabel *tip_error;
   QLabel *tip_bk;
   QTimer *t;
   QPushButton *bt_tip_error;
   QLabel *cur_time;
   set_over_limit *over_limit;
protected:
    void paintEvent(QPaintEvent* event);
public slots:
    void show_wg_popwin_slot();
    void show_dis_screen_slot();
    void Timer_on_slot();

private slots:
    void main_update_slot();//界面切换调用弹窗
    void goto_LuowenSet_slot();
    void gouback_lastpage_slot();
    void hide_fixval_slot();
    void show_fixval_slot();//显示固定值弹窗
    void addWorkInfo_slot(int index);
    void deal_pro_modi_slot(int index);//工艺修改菜单
    void show_pro_modi_slot(int index);
    void goto_setcsreen_slot();
    void show_keybord_slot(int index);
    void close_keyboard_slot();
    void edit_input_slot(int index,QString str);
    void change_warn_text_slot();
    void set_win_back_slot();
    void page_jump_slot(int index);
    void jump_to_alm_info_slot();
    void screen_change(int scr_num);
signals:
    void edit_input_signal(int index,QString str);
    void set_scr_change(int scr_num);
};
#endif // WIDGET_H
