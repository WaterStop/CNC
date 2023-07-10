#ifndef WIDGET3_7_H
#define WIDGET3_7_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget3_7;
}

class widget3_7 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_7(QWidget *parent = nullptr);
    ~widget3_7();
    void Foucus_init();
    bool wedget3_7ToProcessList(MachineProcess*, s_chamferMode1*, Ui::widget3_7* ui);
    bool wedget3_7ToProcessList(MachineProcess*, s_chamferMode3*, Ui::widget3_7* ui);
    void fixval_set();
    void INFO_init();
    void loadWorkInfo(int index);

private:
    Ui::widget3_7 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void set_left_button();
    void DealSlot();
    void ClearEdit();
    void show_rotation();
    void change_axisdir_icon();
public slots:
    void widget3_7_editDataToGCode();
private slots:
    void show_keyboard_slot();
    void input_ok_slot();
    void Focus_switch_slot();
    void change_axisdir1_slot();
    void change_axisdir2_slot();
    void change_anticlockwise_slot();
    void change_clockwise_slot();
    void feed_fixval_slot();
    void edit_input_slot(QString str);
    void updateTrCnCr();
signals:
    void edit_press_signal();
    void input_ok_signal();
    void feed_fixval_signal();
    void edit_input_signal(int index,QString str);
};

#endif // WIDGET3_7_H
