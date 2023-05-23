#ifndef CHANGE_SCREENTIP_H
#define CHANGE_SCREENTIP_H

#include <QDialog>
#include "baseset.h"

namespace Ui {
class change_screentip;
}

class change_screentip : public QDialog
{
    Q_OBJECT

public:
    explicit change_screentip(QWidget *parent = nullptr);
    ~change_screentip();
    void set_tip(QString str);

private:
    Ui::change_screentip *ui;
    void resizeEvent(QResizeEvent *event);
    void Bace_init();
    void Deal_slot();
private slots:
    void ok_slot();
    void cancel_slot();
signals:
    void ok_signal();
    void cancel_signal();
};

#endif // CHANGE_SCREENTIP_H
