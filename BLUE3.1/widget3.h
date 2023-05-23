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
private:
    Ui::widget3 *ui;
    void set_wg3_background();
    void set_wg3_edit_pos();
    void set_wg3_label_pos();
    void set_wg3_label_point(int angle);
    void DealSlot();
    void paintEvent(QPaintEvent *event);
    void set_edit_style();
    void deal_point();
    void UpdataTimer();
    QTimer *timer;//定时器    
    QLabel *label_zhuzhou_per = new QLabel(this);
    QLabel *label_feed_per = new QLabel(this);
    QLabel *label_request_speed = new QLabel(this);//设定速度
private slots:
    void setpoint(int value);
    void show_keyboard_slot();
    void show_keyboard_slot1();
    void show_keyboard_slot2();
    void show_keyboard_slot3();
    void show_keyboard_slot4();
    void show_keyboard_slot5();
    void deal_enter_slot();
    void edit_input_slot(QString str);
    void Timer_on_slot();
signals:
    void edit_press_signal(int index);
    void close_keyboard_signal();
    void barstock_set_signal();
    void edit_input_signal(int index,QString str);
};

#endif // WIDGET3_H
