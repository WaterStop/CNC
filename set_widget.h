#ifndef SET_WIDGET_H
#define SET_WIDGET_H

#include <QWidget>
#include "baseset.h"
#include"set_plc_plc.h"
#include "set_dgn.h"

namespace Ui {
class set_widget;
}

class set_widget : public QWidget
{
    Q_OBJECT

public:
    explicit set_widget(QWidget *parent = nullptr);
    ~set_widget();

private:
    Ui::set_widget *ui;
    void set_background();
    void Init();
    void button_set();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    void DealSlot();
    void SetNavigationBar();
//    void set_PLC_Lad();
//    void UpdataTimer();
//    void menuRight_info_show_plcpic(int index);
//    void basic_ins();
//    void edit_ins();
//    QPushButton* bt_fun[8];
//    QPushButton* bt_fun_right[8];
    Set_Plc_plc *set_plc;
    set_dgn *dgn;
private slots:
//    void RIGHT_FUN0_slot();
//    void RIGHT_FUN1_slot();
//    void RIGHT_FUN2_slot();
//    void RIGHT_FUN3_slot();
//    void RIGHT_FUN4_slot();
//    void RIGHT_FUN5_slot();
//    void RIGHT_FUN6_slot();
//    void RIGHT_FUN7_slot();
//    void FUN0_slot();
//    void FUN1_slot();
//    void FUN2_slot();
//    void FUN3_slot();
//    void FUN4_slot();
//    void FUN5_slot();
//    void FUN6_slot();
//    void FUN7_slot();
//    void fun_pageup_slot();
//    void fun_pagedown_slot();
    void back_slot();
signals:
    void back_signal();
};

#endif // SET_WIDGET_H
