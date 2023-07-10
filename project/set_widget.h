#ifndef SET_WIDGET_H
#define SET_WIDGET_H

#include <QWidget>
#include "baseset.h"
#include"set_plc_plc.h"
#include "set_dgn.h"
#include "set_alarm_info.h"
#include "set_alm_note.h"
#include "set_data_para.h"
#include "navlistview.h"
#include "set_limit_and_time.h"
#include "set_over_limit_set.h"
#include "set_internet_set.h"
#include "set_file_manage.h"
#include "set_back_up.h"

#define base 0
#define alm_info base+0
#define alm_note base+1
#define dgn_ base+2
#define base_para base+3
#define para_set base+4
#define IP_addr base+5
#define knif_of base+6
#define luoju_of base+7
#define pos_set base+8
#define time_lev base+9
#define over_pro base+10
#define file_mag base+11
#define back_up base+12


namespace Ui {
class set_widget;
}

class set_widget : public QWidget
{
    Q_OBJECT

public:
    explicit set_widget(QWidget *parent = nullptr);
    ~set_widget();
    void show_alminfo_scr();

private:
    Ui::set_widget *ui;
    void set_background();
    void Init();
    void button_set();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    void DealSlot();
    void treewidget_info();
    void SetNavigationBar();
    void change_screen(int index);
    Set_Plc_plc *set_plc;
    set_dgn *dgn;
    set_alarm_info *alarm_info;
    set_alm_note *alarm_note;
    set_data_para *data_para;
    set_limit_and_time *lim_and_time;
    set_over_limit_set *over_set;
    set_internet_set *net_set;
    set_file_manage *file_manage;
    set_back_up *back;
    QPushButton *temp_but[4];
    QPushButton *temp_but2[1];
    QTreeWidget *tree;
    NavListView *tree_list;

public slots:
    void Timer_on_slot();
private slots:
    void goto_work_scr_slot();
    void goto_dgn_slot();
    void goto_alm_info_slot();
    void goto_alm_note_slot();
    void goto_data_para_slot();
    void back_slot();
    void screen_jump_slot(int index, int parentIndex);
signals:
    void back_signal();
};

#endif // SET_WIDGET_H
