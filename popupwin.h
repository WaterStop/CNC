#ifndef POPUPWIN_H
#define POPUPWIN_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class PopupWin;
}

class PopupWin : public QWidget
{
    Q_OBJECT

public:
    explicit PopupWin(QWidget *parent = nullptr);
    ~PopupWin();

private:
    Ui::PopupWin *ui;
    void set_popupwin_background();
    void resizeEvent(QResizeEvent *event);
    void set_popupwin_button();
    void set_workpath();
public slots:
    void show_popwin_slot();
    void set_workpath_slot();
    void set_workpath_slot1();
    void set_workpath_slot2();
    void set_workpath_slot3();
    void set_workpath_slot4();
};

#endif // POPUPWIN_H
