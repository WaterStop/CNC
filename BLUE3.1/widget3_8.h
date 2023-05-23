#ifndef WIDGET3_8_H
#define WIDGET3_8_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget3_8;
}

class widget3_8 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_8(QWidget *parent = nullptr);
    ~widget3_8();
    void Foucus_init();
    bool wedget3_8ToProcessList(MachineProcess*, s_endFaceMode2*, Ui::widget3_8* ui);
    void fixval_set();
    void INFO_init();
    void loadWorkInfo(int index);

private:
    Ui::widget3_8 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void set_left_button();
    void DealSlot();
    void ClearEdit();
    void change_axisdir_icon();
public slots:
    void widget3_8_editDataToGCode();
private slots:
    void show_keyboard_slot();
    void input_ok_slot();
    void Focus_switch_slot();
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

#endif // WIDGET3_8_H
