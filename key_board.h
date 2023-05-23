#ifndef KEY_BOARD_H
#define KEY_BOARD_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class key_board;
}

class key_board : public QWidget
{
    Q_OBJECT

public:
    explicit key_board(QWidget *parent = nullptr);
    ~key_board();

private:
    Ui::key_board *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_key_bk();
    void set_key_press();
    void set_key_release();
    void key_pressed();
    void Deal_enter_fun();
public slots:
    void press_num_0_slot();
    void press_num_1_slot();
    void press_num_2_slot();
    void press_num_3_slot();
    void press_num_4_slot();
    void press_num_5_slot();
    void press_num_6_slot();
    void press_num_7_slot();
    void press_num_8_slot();
    void press_num_9_slot();
    void press_key_point_slot();
    void press_key_back_slot();
    void press_key_enter_slot();
    void set_key_release_slot();
signals:
    void keyPress();
    void waiyuan1_enter_signal();
    void waiyuan2_enter_signal();
    void waiyuan3_enter_signal();
    void duanmian1_enter_signal();
    void duanmian2_enter_signal();
    void duanmian3_enter_signal();
    void likong1_enter_signal();
    void likong2_enter_signal();
    void likong3_enter_signal();
    void likong4_enter_signal();
    void likong5_enter_signal();
    void zhuimian1_enter_signal();
    void zhuimian2_enter_signal();
    void zhuimian3_enter_signal();
    void zhuimian4_enter_signal();
    void luowen1_enter_signal();
    void luowen2_enter_signal();
    void luowen3_enter_signal();
    void luowen4_enter_signal();
    void luowenset_enter_signal();
    void daojiao1_enter_signal();
    void daojiao2_enter_signal();
    void daojiao3_enter_signal();
    void daojiao4_enter_signal();
    void output_enter_signak();
};

#endif // KEY_BOARD_H
