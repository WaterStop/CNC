#ifndef WIDGET2_WORKPIC_H
#define WIDGET2_WORKPIC_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget2_workpic;
}

class widget2_workpic : public QWidget
{
    Q_OBJECT

public:
    explicit widget2_workpic(QWidget *parent = nullptr);
    ~widget2_workpic();
private:
    Ui::widget2_workpic *ui;
    void paintEvent(QPaintEvent *);
    void DealSlot();
    void draw_running_pic();
public slots:
    void Updata_Info_slot();
private slots:

};

#endif // WIDGET2_WORKPIC_H
