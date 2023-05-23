#ifndef WIDGET4_H
#define WIDGET4_H

#include <QWidget>
#include "baseset.h"
#include <cstdlib>
namespace Ui {
class widget4;
}

class widget4 : public QWidget
{
    Q_OBJECT

public:
    explicit widget4(QWidget *parent = nullptr);
    ~widget4();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::widget4 *ui;
    void set_wg4_background();
    void set_wg4_button();
    void set_wg4_label();
    void DealSlot();
    void info_init();
    void update_workstate();
    void show_move_state(int index);
    QTimer *timer = new QTimer;
public slots:
    void set_wg4_button_solt();
    void set_wg4_button_solt2();
    void set_wg4_button_solt3();
    void set_wg4_button_move_up_solt();
    void set_wg4_button_move_down_solt();
    void set_wg4_button_move_left_solt();
    void set_wg4_button_move_right_solt();
    void set_wg4_button_move_fast_solt();
    void set_wg4_label_FastRate_solt();
    void set_wg4_button_MainAxis_F();//主轴顺时针
    void set_wg4_button_MainAxis_R();//主轴逆时针
    void set_wg4_button_MainAxis_S();//主轴停
    void Timer_on_slot();
};

#endif // WIDGET4_H
