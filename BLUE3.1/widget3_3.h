#ifndef WIDGET3_3_H
#define WIDGET3_3_H

#include <QWidget>
#include "baseset.h"
#include <MachineProcess.h>


class MachineProcess;

namespace Ui {
class widget3_3;
}

class widget3_3 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_3(QWidget *parent = nullptr);
    ~widget3_3();
    bool wedget3_3ToProcessList(MachineProcess*, s_outerCircleMode1*, Ui::widget3_3* ui);
    bool wedget3_3ToProcessList(MachineProcess*, s_innerHoleMode1*, Ui::widget3_3* ui);
    void Foucus_init();
    void fixval_set();
    void INFO_init();
    void loadWorkInfo(int index);
private:
    Ui::widget3_3 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void set_left_button();
    void DealSlot();
    void ClearEdit();
    void change_axisdir_icon();
public slots:
    void Focus_switch_slot();
    void widget3_3_editDataToGCode();
private slots:
    void show_keyboard_slot();
    void input_ok_slot();
    void change_axisdir1_slot();
    void change_axisdir2_slot();
    void feed_fixval_slot();
    void edit_input_slot(QString str);
signals:
    void edit_press_signal();
    void input_ok_signal();
    void feed_fixval_signal();
    void edit_input_signal(int index,QString str);
};

#endif // WIDGET3_3_H
