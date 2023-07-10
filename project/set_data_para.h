#ifndef SET_DATA_PARA_H
#define SET_DATA_PARA_H

#include <QWidget>
#include "baseset.h"
#include "key_board_2.h"
#include <QElapsedTimer>

#define Row_NUM 10
#define Col_NUM 10


namespace Ui {
class set_data_para;
}

class set_data_para : public QWidget
{
    Q_OBJECT

public:
    explicit set_data_para(QWidget *parent = nullptr);
    ~set_data_para();

private:
    Ui::set_data_para *ui;
    void Init();
    void button_set();
    void Deal_slot();
    void table_init();
    void update_info();
    void load_para_info();//载入参数列表
    void updata_para_info();//更新参数文件
    void read_file();
    void save_file();
    void set_line_info(QString str);//载入信息
    void set_line_num(QString str);//设定首行行号
    void tip_set(QString str);
    void quick_jump(int num);
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    QPushButton* bt_fun_right[8];
    key_board_2 *keyboard;
    QTableWidget *table_info;
    QLabel *lab_tip;//提示控件
    QTimer *tip_timer = new QTimer;
public slots:
    void Timer_on_slot();
private slots:
    void get_item_info_slot(int row,int col);//获取单元格信息
    void val_input_slot(QString str);
    void seacher_slot();
    void uppage_slot();
    void downpage_slot();
    void clear_tip_slot();
    void bt_fun_slot1();
    void bt_fun_slot2();
    void bt_fun_slot3();
    void bt_fun_slot4();
    void bt_fun_slot5();

};

#endif // SET_DATA_PARA_H
