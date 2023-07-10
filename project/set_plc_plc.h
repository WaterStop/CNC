#ifndef SET_PLC_PLC_H
#define SET_PLC_PLC_H

#include <QWidget>
#include <plc.h>
#include "baseset.h"
#include "plc_plc_pic.h"

namespace Ui {
class Set_Plc_plc;
}

class Set_Plc_plc : public QWidget
{
    Q_OBJECT

public:
    explicit Set_Plc_plc(QWidget *parent = nullptr);
    ~Set_Plc_plc();

private:
    Ui::Set_Plc_plc *ui;
    void set_background();
    void Init();
    void button_set();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    void DealSlot();
    void set_PLC_Lad();
    void UpdataTimer();
    void menuRight_info_show(int index);
    void BaseCmd();
    void FuncCmd();
    void EditCmd();
    QPushButton* bt_fun[8];
    QPushButton* bt_fun_right[8];
    plc_fun_cmd* func_popwin;
    PLC_plc_pic* plc_w;
public slots:
    void Timer_on_slot();
private slots:
    void RIGHT_FUN0_slot();
    void RIGHT_FUN1_slot();
    void RIGHT_FUN2_slot();
    void RIGHT_FUN3_slot();
    void RIGHT_FUN4_slot();
    void RIGHT_FUN5_slot();
    void RIGHT_FUN6_slot();
    void RIGHT_FUN7_slot();
    void FUN0_slot();
    void FUN1_slot();
    void FUN2_slot();
    void FUN3_slot();
    void FUN4_slot();
    void FUN5_slot();
    void FUN6_slot();
    void FUN7_slot();
    void fun_pageup_slot();
    void fun_pagedown_slot();
};

#endif // SET_PLC_PLC_H
