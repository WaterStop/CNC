#ifndef SET_DGN_H
#define SET_DGN_H

#include <QWidget>
#include "baseset.h"
#include "key_board_2.h"

#define Row_NUM 18

namespace Ui {
class set_dgn;
}

class set_dgn : public QWidget
{
    Q_OBJECT

public:
    explicit set_dgn(QWidget *parent = nullptr);
    ~set_dgn();

private:
    Ui::set_dgn *ui;
    void set_background();
    void Init();
    void button_set();
    void Deal_slot();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    //void DealSlot();
    void load_info();
    void set_info();
    void set_table_info();
    void temp_dgn_load();
    void table_init();
    void draw_signal();
    QPushButton* bt_fun[8];
    QPushButton* bt_fun_right[8];
    QLabel* label_in[32];
    QLabel* label_out[32];
    QLabel* label_handwheel[5];
    QLabel* label_tem[400];
    QLabel* label_Xtitle[48];
    QLabel* label_Ytitle[48];
    QLabel* label_Xsignal[48];
    QLabel* label_Ysignal[48];
    //QTimer *timer = new QTimer;
    QPushButton *bt_back;
    QPushButton *bt_up;
    QPushButton *bt_down;
    QTableWidget *table_info;
    QPushButton *bt_page[2];
    QLabel *lab_mdi;
    MyLineEdit *edit_mdi;
    QPushButton *bt_G98G99;
    QLabel *lab_G98G99;
    key_board_2 *keyboard;
public slots:
    void Timer_on_slot();
private slots:
    void back_slot();
    void uppage_slot();
    void downpage_slot();
    void uppage_slot1();
    void downpage_slot1();
    void keyboard_show();
    void val_input_slot(QString);
    void change_g98g99();
signals:
    void back_signal();
};

#endif // SET_DGN_H
