#ifndef WIDGET5_2_H
#define WIDGET5_2_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget5_2;
}

class widget5_2 : public QWidget
{
    Q_OBJECT

public:
    explicit widget5_2(QWidget *parent = nullptr);
    ~widget5_2();
    void INFO_init();

private:
    Ui::widget5_2 *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void Deal_Slot();
    void set_button();
    void set_curnum();
public slots:
    void set_curtype1_solt();
    void set_curtype2_solt();
    void set_curtype3_solt();
    void set_curtype4_solt();
};

#endif // WIDGET5_2_H
