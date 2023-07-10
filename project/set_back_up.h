#ifndef SET_BACK_UP_H
#define SET_BACK_UP_H

#include <QWidget>
#include "baseset.h"
#include "QtGui/private/qzipreader_p.h"
#include "QtGui/private/qzipwriter_p.h"

namespace Ui {
class set_back_up;
}

class set_back_up : public QWidget
{
    Q_OBJECT

public:
    explicit set_back_up(QWidget *parent = nullptr);
    ~set_back_up();

private:
    Ui::set_back_up *ui;
    void Init();
    void label_set();
    void edit_set();
    void button_set();
    void Deal_slot();
    bool zipReader(QString zipPath, QString zipDir);
    void zipWriter(QString zipPath, QFileInfoList fileList);
    QPushButton *bt[2];
public slots:
    void Timer_on_slot();
private slots:
    void back_up_slot();//备份
    void restore_slot();//恢复
};

#endif // SET_BACK_UP_H
