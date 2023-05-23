#ifndef POPUPWIN_LEFT_H
#define POPUPWIN_LEFT_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class popupwin_left;
}

class popupwin_left : public QWidget
{
    Q_OBJECT

public:
    explicit popupwin_left(QWidget *parent = nullptr);
    ~popupwin_left();

private:
    Ui::popupwin_left *ui;
    void set_wg2_background();
};

#endif // POPUPWIN_LEFT_H
