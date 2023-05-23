#ifndef WIDGET3_15_H
#define WIDGET3_15_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget3_15;
}

class widget3_15 : public QWidget
{
    Q_OBJECT

public:
    explicit widget3_15(QWidget *parent = nullptr);
    ~widget3_15();
    void Foucus_init();
    void ClearEdit();
	void getInfo( s_screwThreadMode1* screwThread1);

private:
    Ui::widget3_15 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_edit();
    void set_button();
    void DealSlot();
    void dis_switch();
private slots:
    void shuaiwei_slot();
    void cuoweijiagong_slot();
    void goback_lastpage_slot();
    void Focus_switch_slot();
signals:
    void back_lastpage();
};

#endif // WIDGET3_15_H
