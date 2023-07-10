#ifndef SET_ALM_NOTE_H
#define SET_ALM_NOTE_H

#include <QWidget>
#include "baseset.h"
#include "mytablewidget.h"

#define row_num 10
#define head_height 25
#define row_height 25

namespace Ui {
class set_alm_note;
}

class set_alm_note : public QWidget
{
    Q_OBJECT

public:
    explicit set_alm_note(QWidget *parent = nullptr);
    ~set_alm_note();

private:
    Ui::set_alm_note *ui;
    void Init();
    void button_set();
    void Deal_slot();
    void table_init();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    void set_info();
    void read_file();
    bool save_file();
    void edit_update();
    void update_info();
    void update_notelist();
    QLabel *label_tip;
    QTableWidget *table;
    QTextEdit *edit_note;
    QLabel* label_text[4];
    QPushButton* bt_fun_right[8];
public slots:
    void Timer_on_slot();
private slots:
    void save_func_slot();
    void del_almnote_slot();
    void pageup_slot();
    void pagedown_slot();
    void get_item_info_slot(int row,int col);//获取单元格信息
};

#endif // SET_ALM_NOTE_H
