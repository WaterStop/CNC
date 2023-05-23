#ifndef WIDGET3_13_H
#define WIDGET3_13_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget3_13;
}

class widget3_13 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_13(QWidget *parent = nullptr);
    ~widget3_13();
    void Foucus_init();
    void fixval_set();
    void INFO_init();

private:
    Ui::widget3_13 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void set_left_button();
    void DealSlot();
    void ClearEdit();
    void change_axisdir_icon();
private slots:
    void show_keyboard_slot();
    void input_ok_slot();
    void Focus_switch_slot();
    void change_axisdir1_slot();
    void change_axisdir2_slot();
    void feed_fixval_slot();
signals:
    void edit_press_signal();
    void input_ok_signal();
    void feed_fixval_signal();
};

#endif // WIDGET3_13_H
