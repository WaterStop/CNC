#ifndef WEDGET1_H
#define WEDGET1_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include "baseset.h"
#include "myprogressbar.h"

class MachineSequene;

namespace Ui {
class wedget1;
}

class wedget1 : public QWidget
{
    Q_OBJECT

public:
    explicit wedget1(QWidget *parent = nullptr);
    ~wedget1();
    void input_work_pic();
    void UpDate_Screen();

private:
    Ui::wedget1 *ui;
    void set_wg1_background();
    void resizeEvent(QResizeEvent *);
    void set_proBar();
    void set_proBar_value();    
    void set_button();
    void set_bt_pic();
    void DealSlot();
    void paintEvent(QPaintEvent *event);
    QTimer *timer = new QTimer;
    //MachineSequene* machineinfo;
public slots:
    void set_proBar_value_solt(int value);
private slots:
    void bt_0_slot();
    void bt_1_slot();
    void bt_2_slot();
    void bt_3_slot();
    void bt_4_slot();
    void bt_0_slot_l();
    void bt_1_slot_l();
    void bt_2_slot_l();
    void bt_3_slot_l();
    void bt_4_slot_l();
    void long_press_slot();
signals:
    void bt_signal(int index);
    void long_press_signal(int index);

};



#endif // WEDGET1_H
