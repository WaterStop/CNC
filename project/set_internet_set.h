#ifndef SET_INTERNET_SET_H
#define SET_INTERNET_SET_H

#include <QWidget>
#include <QHostAddress>
#include <QNetworkInterface>
#include "baseset.h"
#include "key_board_2.h"

namespace Ui {
class set_internet_set;
}

class set_internet_set : public QWidget
{
    Q_OBJECT

public:
    explicit set_internet_set(QWidget *parent = nullptr);
    ~set_internet_set();

private:
    Ui::set_internet_set *ui;
    void Init();
    void label_set();
    void edit_set();
    void button_set();
    void Deal_slot();
    void update_info();
    QString getHostIpAddress();
    QString getMAC();
    void get_info();
    void read_file();
    void load_info();
    void set_info();
    QString macAddress(QString network);
    QLabel *lab_title[4];
    QLabel *lab_p[9];
    MyLineEdit *edit[12];
    QLineEdit *edit_mac;
    QPushButton *bt_set;
    key_board_2 *keyboard;
public slots:
    void Timer_on_slot();
private slots:
    void keyboard_show_slot();
    void val_input_slot(QString);
    void save_slot();
};

#endif // SET_INTERNET_SET_H
