#ifndef WIDGET3_12_H
#define WIDGET3_12_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget3_12;
}

class widget3_12 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_12(QWidget *parent = nullptr);
    ~widget3_12();
    void Foucus_init();
    bool wedget3_12ToProcessList(MachineProcess*, s_screwThreadMode2*, Ui::widget3_12* ui);
    bool wedget3_12ToProcessList(MachineProcess*, s_screwThreadMode4*, Ui::widget3_12* ui);
    void fixval_set();
    void INFO_init();
    void loadWorkInfo(int index);

private:
    Ui::widget3_12 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void set_left_button();
    void DealSlot();
    void ClearEdit();
    void change_axisdir_icon();
public slots:
    void widget3_12_editDataToGCode();
private slots:
    void show_keyboard_slot();
    void input_ok_slot();
    void Focus_switch_slot();
    void goto_LuowenSet_slot();
    void change_axisdir1_slot();
    void change_axisdir2_slot();
    void zhuiluowen_fixval_slot();
    void feed_fixval_slot();
    void edit_input_slot(QString str);
signals:
    void edit_press_signal();
    void goto_LuowenSet_signal();
    void input_ok_signal();
    void zhuiluowen_fixval_signal();
    void feed_fixval_signal();
    void edit_input_signal(int index,QString str);
};

#endif // WIDGET3_12_H
