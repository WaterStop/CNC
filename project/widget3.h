#ifndef WIDGET3_H
#define WIDGET3_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsView>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

#include "baseset.h"


extern int cur_angle;
//extern MLINK_MONITOR_STRUCT mlinkMonitor[SLV_ST_MAX];
namespace Ui {
class widget3;
}

class widget3 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3(QWidget *parent = nullptr);
    ~widget3();
    void resizeEvent(QResizeEvent *event);
    void DisLabel_title();
    void Info_dis();
    void loadWorkInfo(int index);
private:
    Ui::widget3 *ui;
    void set_wg3_background();
    void set_wg3_edit_pos();
    void set_wg3_label_pos();
    void set_wg3_label_point(int angle);
    void set_button();
    void info_init();
    void DealSlot();
    void paintEvent(QPaintEvent *event);
    void deal_point();
    void UpdataTimer();
    //QTimer *timer;//定时器
    QLabel *label_zhuzhou_per = new QLabel(this);
    QLabel *label_feed_per = new QLabel(this);
    QLabel *label_request_speed = new QLabel(this);//设定速度
    QPushButton *axis_zero[3];
    QLabel *lab_pro[3];
    QLabel *lab_val[5];
    MyLineEdit *edit_L0;
    MyLineEdit *edit_D0;
    MyLineEdit *edit_L1;
    MyLineEdit *edit_D1;
    QLabel *lab_dir[2];

public slots:
    void Timer_on_slot();

private slots:
    void setpoint(int value);
    void show_keyboard_slot();
    void show_keyboard_slot1();
    void show_keyboard_slot2();
    void show_keyboard_slot3();
    void show_keyboard_slot4();
    void show_keyboard_slot5();
    void deal_enter_slot();//处理回车
    void edit_input_slot(QString str);
    void set_edit_style_slot();
    void return_zero_slot_X();//X回零
    void return_zero_slot_Z();//Z回零
signals:
    void edit_press_signal(int index);//编辑栏按下信号
    void close_keyboard_signal();
    void barstock_set_signal();
    void edit_input_signal(int index,QString str);
};

#endif // WIDGET3_H
