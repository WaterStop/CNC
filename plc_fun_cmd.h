#ifndef PLC_FUN_CMD_H
#define PLC_FUN_CMD_H

#include <QDialog>
#include "baseset.h"

namespace Ui {
class plc_fun_cmd;
}

class plc_fun_cmd : public QDialog
{
    Q_OBJECT

public:
    explicit plc_fun_cmd(QWidget *parent = nullptr);
    ~plc_fun_cmd();

private:
    Ui::plc_fun_cmd *ui;
    void Deal_solt();
    void Init_set();
    virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void itemClicked_slot(QTableWidgetItem* item);
    void show_iteminfo_slot(int row,int col);
};

#endif // PLC_FUN_CMD_H
