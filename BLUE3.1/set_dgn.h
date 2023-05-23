#ifndef SET_DGN_H
#define SET_DGN_H

#include <QWidget>
#include "baseset.h"

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
    void DealSlot();
    void load_info();
    void set_info();
    QPushButton* bt_fun[8];
    QPushButton* bt_fun_right[8];
    QLabel* label_in[32];
    QLabel* label_out[32];
    QLabel* label_handwheel[5];
    QTimer *timer = new QTimer;
    QPushButton *bt_back;
private slots:
    void Timer_on_slot();
    void back_slot();
signals:
    void back_signal();
};

#endif // SET_DGN_H
