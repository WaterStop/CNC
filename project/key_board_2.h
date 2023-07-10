#ifndef KEY_BOARD_2_H
#define KEY_BOARD_2_H

#include <QWidget>
#include "baseset.h"



namespace Ui {
class key_board_2;
}

class key_board_2 : public QWidget
{
    Q_OBJECT

public:
    explicit key_board_2(QWidget *parent = nullptr);
    ~key_board_2();
    void change_init();//切换界面刷新
    void focus_init();
    void limit_set(QString str1,QString str2);
private:
    Ui::key_board_2 *ui;
    void Init();
    void button_set();
    void Deal_slot();
    void key_press_deal(int ket_num,QString str);
    void change_key();//键盘转换
    void change_cap();//大小写转换
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    QPushButton *bt_e[31];
    QPushButton *bt_n[30];
    QLineEdit *edit_input;
    QLabel *lim_val;
    QTimer* timer;
private slots:
    void press_deal_slot(int index);
    void press_deal_slot1(int index);
    void KeyOneClick_slot();//单击
    void timer_out_slot();
signals:
    void enter_signal(QString str);
    void enter_signal();
};

#endif // KEY_BOARD_2_H
