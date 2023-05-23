#ifndef PROCESS_MODIFY_H
#define PROCESS_MODIFY_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class Process_modify;
}

class Process_modify : public QWidget
{
    Q_OBJECT

public:
    explicit Process_modify(QWidget *parent = nullptr);
    ~Process_modify();

private:
    Ui::Process_modify *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_button();
    void DealSlot();
private slots:
    void bt_pressed_slot();
    void bt_pressed_slot1();
    void bt_pressed_slot2();
    void bt_pressed_slot3();
    void bt_pressed_slot4();
    void bt_pressed_slot5();
    void bt_pressed_slot6();
signals:
    void bt_pressed(int index);
};

#endif // PROCESS_MODIFY_H
