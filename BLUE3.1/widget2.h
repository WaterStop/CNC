#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include "baseset.h"
#include "widget2_workpic.h"

namespace Ui {
class widget2;
}

class widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit widget2(QWidget *parent = nullptr);
    ~widget2();
    void resizeEvent(QResizeEvent *event);
    //bool eventFilter(QObject *watched, QEvent *event);
    void show_wg2_popwin();
    void pic_update(int index,QString str);
    void clear_str_info();
    void set_bt_sett();//设定按钮坐标
    //MachineProcess *processData;
private:
    Ui::widget2 *ui;
    void set_wg2_background();
    void set_wg2_button();
    void set_wg2_t_button();
    void set_wg2_b_button();
    void magicTime();
    void paintEvent(QPaintEvent *);
    void Info_init();
    void DrawKnife();
    void DrawKnife1();
    void DrawKnife2(int x,int y);
    void DrawKnife3(int x,int y);
    void DrawKnife4(int x,int y);
    void DrawWork1();
    void DrawWaiYuan1();
    void DrawWaiYuan2();
    void DrawWaiYuan3();
    void DrawDuanMian1();
    void DrawDuanMian2();
    void DrawDuanMian3();
    void DrawLiKong1();
    void DrawLiKong2();
    void DrawLiKong3();
    void DrawLiKong4();
    void DrawLiKong5();
    void DrawZhuiMian2();
    void DrawZhuiMian3();
    void DrawZhuiMian4();
    void DrawLuoWen1();
    void DrawLuoWen2();
    void DrawLuoWen3();
    void DrawLuoWen4();
    void DrawDaoJiao1();
    void DrawDaoJiao2();
    void DrawDaoJiao3();
    void DrawDaoJiao4();
    void DrawBangLiao();
    void DealSlot();
    void DrawDirection();
    void PaintDirection();
    QString edit_str[7];
    QPushButton *bt_showindex[9];
    widget2_workpic *work_pic;
public slots:
    void show_wg2_popwin_slot();
    void DateUpdate_slot();
private slots:
    void on_b_but2_clicked();
    void set_wg2_workmode_slot();
    void set_wg2_workmod1_slot();
    void set_wg2_workmode2_slot();
    void set_wg2_workmode3_slot();
    void set_wg2_t_button_slot();
    void set_wg2_t_button_slot1();
    void set_wg2_t_button_slot2();
    void set_wg2_t_button_slot3();
    void set_wg2_t_button_slot4();
    void set_wg2_t_button_slot5();
    void set_wg2_t_button_slot6();
};

#endif // WIDGET2_H
