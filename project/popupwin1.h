#ifndef POPUPWIN1_H
#define POPUPWIN1_H

#include <QWidget>
#include "baseset.h"
//#include "widget.h"

class Widget;

namespace Ui {
class PopupWin1;
}

class PopupWin1 : public QWidget
{
    Q_OBJECT

public:
    explicit PopupWin1(QWidget *parent = nullptr);
    ~PopupWin1();
    Ui::PopupWin1 *popui;

private:
    Ui::PopupWin1 *ui;
    void set_popwin1_background();
    void resizeEvent(QResizeEvent *event);
    void set_popwin1_button();
    void close_popwin1();
    void set_workmode();
    void set_bt_path();
    void set_WaiYuan_pic();
    void set_DuanMian_pic();
    void set_LiKong_pic();
    void set_ZhuiMian_pic();
    void set_LuoWen_pic();
    void set_DaoJiao_pic();
    void set_DingZhi_pic();
    void DealSlot();
    void Deal_cur_wormod();
    //Widget* wedget_main=nullptr;
public slots:
    void close_popwin1_solt();
    void set_workmode_solt();
    void set_workmode_solt1();
    void set_workmode_solt2();
    void set_workmode_solt3();
    void set_workmode_solt4();
    void set_bt_path_solt();
    void set_bt_path_solt1();
    void set_bt_path_solt2();
    void set_bt_path_solt3();
    void set_bt_path_solt4();
    void set_bt_path_solt5();
    void set_bt_path_solt6();
signals:
    void change_work_signal();
};

#endif // POPUPWIN1_H
