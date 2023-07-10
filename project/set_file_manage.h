#ifndef SET_FILE_MANAGE_H
#define SET_FILE_MANAGE_H

#include <QWidget>
#include "baseset.h"
#include"QFileInfoList"


namespace Ui {
class set_file_manage;
}

class set_file_manage : public QWidget
{
    Q_OBJECT

public:
    explicit set_file_manage(QWidget *parent = nullptr);
    ~set_file_manage();

private:
    Ui::set_file_manage *ui;
    void Init();
    void label_set();
    void edit_set();
    void button_set();
    void load_loc_file();
    void load_usb_file();
    void load_loc_item();
    void load_usb_item();
    void update_info();
    void file_copy();//文件拷贝
    void folder_copy();//文件夹拷贝
    QFileInfoList LoadAllFile(QTreeWidgetItem *root,QString path);
    void Deal_slot();
    QTreeWidget *tree;
    QTreeWidget *tree2;
    QPushButton *bt[2];
public slots:
    void Timer_on_slot();
private slots:
    void deal_item_slot(QTreeWidgetItem *item);//点击展开或者收起
    void deal_item_slot2(QTreeWidgetItem *item);//点击展开或者收起
    void get_loc_path_slot(QTreeWidgetItem *item ,int count);//获取点击项目路径
    void get_usb_path_slot(QTreeWidgetItem *item ,int count);//获取点击项目路径
    void copy_slot();
    void delate_slot();
};

#endif // SET_FILE_MANAGE_H
