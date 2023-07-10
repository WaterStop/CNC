#ifndef WIDGET4_H
#define WIDGET4_H

#include <QWidget>
#include "baseset.h"
#include <cstdlib>
#include "gaugeround.h"
#include "progressring.h"
#include "widget4_text.h"

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
    void draw_prossbar(int x,int y);
    int get_probar1_val();
    int get_probar2_val();
    void paintEvent(QPaintEvent *);
    QLabel *lb[8];
    QLabel *bar_bk;
    //GaugeRound *probar;
    ProgressRing *axis_pro;
    widget4_text *text_lev;

    //QTimer *timer = new QTimer;
public slots:
    void Timer_on_slot();
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
};

#endif // WIDGET4_H
