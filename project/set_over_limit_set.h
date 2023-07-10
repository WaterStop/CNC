#ifndef SET_OVER_LIMIT_SET_H
#define SET_OVER_LIMIT_SET_H

#include <QWidget>
#include "baseset.h"
#include "key_board_2.h"

namespace Ui {
class set_over_limit_set;
}

class set_over_limit_set : public QWidget
{
    Q_OBJECT

public:
    explicit set_over_limit_set(QWidget *parent = nullptr);
    ~set_over_limit_set();

private:
    Ui::set_over_limit_set *ui;
    void Init();
    void label_set();
    void edit_set();
    void button_set();
    void Deal_slot();
    void set_LimTime();
    QLabel *lab[9];
    //MyLineEdit *edit_val[3];
    QPushButton *bt_save;
    QLabel *lab_end_time;
    key_board_2 *keyboard;
public slots:
    void Timer_on_slot();
private slots:
    void keyboard_show_slot();
    void val_input_slot(QString);
    void set_LimTime_slot();
};

#endif // SET_OVER_LIMIT_SET_H
