#ifndef SET_OVER_LIMIT_H
#define SET_OVER_LIMIT_H

#include <QWidget>
#include <QRandomGenerator>
#include "baseset.h"
#include "key_board_2.h"

#define MAX_DEADLINE_CONFIG_ITEM  5
#define MAX_CODE_NUM 22
#define MAX_MANUFACTURER_LENGTH  6

namespace Ui {
class set_over_limit;
}

class set_over_limit : public QWidget
{
    Q_OBJECT

public:
    explicit set_over_limit(QWidget *parent = nullptr);
    ~set_over_limit();

private:
    Ui::set_over_limit *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void Init();
    void label_set();
    void edit_set();
    void button_set();
    void Deal_slot();
    void creat_radom();//生成随机数
    void tip_set(QString str);
    int limit_decode(char *unlockCode);//解码函数
    void deal_time();//处理延长时间
    QLabel *lab[5];
    MyLineEdit *edit_val;
    key_board_2 *keyboard;
    QTimer *tip_timer = new QTimer;
private slots:
    void keyboard_show_slot();
    void val_input_slot(QString);
    void clear_tip_slot();
};

#endif // SET_OVER_LIMIT_H
