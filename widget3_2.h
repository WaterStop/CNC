#ifndef WIDGET3_2_H
#define WIDGET3_2_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget3_2;
}

class widget3_2 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_2(QWidget *parent = nullptr);
    ~widget3_2();

private:
    Ui::widget3_2 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void set_Axis_dire();
    void set_left_button();
    void ClearEdit();
    //void change_axisdir_icon();
public slots:
    void set_Axis_dire_slot1();
    void set_Axis_dire_slot2();
    //void change_axisdir1_slot();
    //void change_axisdir2_slot();
};

#endif // WIDGET3_2_H
