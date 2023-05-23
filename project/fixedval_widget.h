#ifndef FIXEDVAL_WIDGET_H
#define FIXEDVAL_WIDGET_H

#include <QWidget>
#include "baseset.h"

#define mm_max_pg 11
#define inch_max_pg 18
#define MOD_max_pg 9
#define DP_max_pg 11
#define zhuiluowen_max_pg 4
#define feed_max_pg 13

namespace Ui {
class FixedVal_widget;
}

class FixedVal_widget : public QWidget
{
    Q_OBJECT

public:
    explicit FixedVal_widget(QWidget *parent = nullptr);
    ~FixedVal_widget();

private:
    Ui::FixedVal_widget *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_button();
    void DealSlot();
    void Deal_bt_val(int index);
    void show_luowen_val();
    void show_zhuiluowen_val();
    void show_feed_val();
    void set_fixval();
    void set_luowen_val();
    void set_zhuiluowen_val();
    void set_feed_val();
    void mousePressEvent(QMouseEvent *e);
private slots:
    void bt0_val_slot();
    void bt1_val_slot();
    void bt2_val_slot();
    void bt_lastpg_slot();
    void bt_nextpg_slot();
    void Deal_bt_val_slot();
signals:
    void bt0_signal();
    void bt1_signal();
    void bt2_signal();

};

#endif // FIXEDVAL_WIDGET_H
