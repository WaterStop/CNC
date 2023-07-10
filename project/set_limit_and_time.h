#ifndef SET_LIMIT_AND_TIME_H
#define SET_LIMIT_AND_TIME_H

#include <QWidget>
#include "baseset.h"
#include "key_board_2.h"


namespace Ui {
class set_limit_and_time;
}

class set_limit_and_time : public QWidget
{
    Q_OBJECT

public:
    explicit set_limit_and_time(QWidget *parent = nullptr);
    ~set_limit_and_time();

private:
    Ui::set_limit_and_time *ui;
    void set_background();
    void Init();
    void label_set();
    void edit_set();
    void button_set();
    void Deal_slot();
    void read_file();
    void dis_para_switch();//参数开关
    void set_time();//时间设置
    bool change_lim_lev(QString str);//修改权限等级
    bool modify_key(QString str);//修改密码
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    QLabel *lab_title[4];
    MyLineEdit *edit_val[3];
    QPushButton *bt_para_swt;
    key_board_2 *keyboard;
    QLabel *lab_time[6];
    MyLineEdit *edit_time[6];
    QLabel *lab_calendar[42];
    QLabel *lab_calendar_title[10];
public slots:
    void Timer_on_slot();
private slots:
    void change_para_swt_slot();
    void keyboard_show_slot();
    void val_input_slot(QString);
};

#endif // SET_LIMIT_AND_TIME_H
