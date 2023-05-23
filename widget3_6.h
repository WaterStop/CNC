#ifndef WIDGET3_6_H
#define WIDGET3_6_H

#include <QWidget>
#include "baseset.h"
#include "widget3_15.h"
namespace Ui {
class widget3_6;
}

class widget3_6 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_6(QWidget *parent = nullptr);
    ~widget3_6();
    void Foucus_init();
    bool wedget3_6ToProcessList(MachineProcess*, s_screwThreadMode1*, Ui::widget3_6* ui);
    bool wedget3_6ToProcessList(MachineProcess*, s_screwThreadMode3*, Ui::widget3_6* ui);
    void fixval_set();
    void INFO_init();
    void loadWorkInfo(int index);
private:
    Ui::widget3_6 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void set_comboBox();
    void set_left_button();
    void DealSlot();
    //void unit_choose();
    void ClearEdit();
    void change_axisdir_icon();
    widget3_15* widget15;
public slots:
    void widget3_6_editDataToGCode();
private slots:
    void show_keyboard_slot();
    void input_ok_slot();
    void Focus_switch_slot();
    void goto_LuowenSet_slot();
    void change_axisdir1_slot();
    void change_axisdir2_slot();
    void feed_fixval_slot();
    void luowen_fixval_slot();
    void show_unit_slot(int num);
    void edit_input_slot(QString str);
signals:
    void edit_press_signal();
    void input_ok_signal();
    void goto_LuowenSet_signal();
    void mode_changed_signal();
    void feed_fixval_signal();
    void luowen_fixval_signal();
    void edit_input_signal(int index,QString str);
};

#endif // WIDGET3_6_H
