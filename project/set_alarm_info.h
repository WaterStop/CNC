#ifndef SET_ALARM_INFO_H
#define SET_ALARM_INFO_H

#include <QWidget>
#include "baseset.h"
#include "mytablewidget.h"


#define row_num 10
#define max_error_num 50
#define head_height 25
#define row_height 25

namespace Ui {
class set_alarm_info;
}

class set_alarm_info : public QWidget
{
    Q_OBJECT

public:
    explicit set_alarm_info(QWidget *parent = nullptr);
    ~set_alarm_info();

private:
    Ui::set_alarm_info *ui;
    void Init();
    void button_set();
    void Deal_slot();
    void table_init();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    void update_info();
    void edit_update();
    QLabel* label_text[4];
    QTextEdit *edit_note;
    QTableWidget *table;
    QPushButton* bt_fun_right[8];
    //MyTableWidget* table_info;
public slots:
    void Timer_on_slot();
private slots:
    void pageup_slot();
    void pagedown_slot();
    void get_item_info_slot(int row,int col);//获取单元格信息
};

#endif // SET_ALARM_INFO_H
