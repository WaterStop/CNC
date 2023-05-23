#ifndef WIDGET5_H
#define WIDGET5_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget5;
}

class widget5 : public QWidget
{
    Q_OBJECT

public:
    explicit widget5(QWidget *parent = nullptr);
    ~widget5();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::widget5 *ui;
    void set_wg5_background();
    void set_wg5_button();
    void set_lock();
    void set_wg5_edit();
    void set_curnum();
public slots:
    void set_lock_slot();
    void set_curnum_solt1();
    void set_curnum_solt2();
    void set_curnum_solt3();
    void set_curnum_solt4();
};

#endif // WIDGET5_H
