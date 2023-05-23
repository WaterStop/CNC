#include "change_screentip.h"
#include "ui_change_screentip.h"
//************************************//
//*************提示窗口****************//
//************************************//
change_screentip::change_screentip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_screentip)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);//去掉最大化最小化关闭按钮
    Bace_init();
    Deal_slot();
}

change_screentip::~change_screentip()
{
    delete ui;
}

void change_screentip::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg1_btbk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void change_screentip::Bace_init()
{
    ui->label_tip->setFont(weiruanyahei6);
    ui->bt_ok->setFont(weiruanyahei6);
    ui->bt_cancel->setFont(weiruanyahei6);
    ui->label_tip->setStyleSheet("color: rgb(255, 255, 255);");
    ui->bt_ok->setStyleSheet("color: rgb(255, 255, 255);border-image:url(:/new/blue_pic/set_head_icon.png);");
    ui->bt_cancel->setStyleSheet("color: rgb(255, 255, 255);border-image:url(:/new/blue_pic/set_head_icon.png);");
    ui->label_tip->setGeometry(5,10,290,60);
    ui->bt_ok->setGeometry(40,100,75,40);
    ui->bt_cancel->setGeometry(190,100,75,40);
    ui->bt_ok->setText("是");
    ui->bt_cancel->setText("否");
}

void change_screentip::Deal_slot()
{
    connect(ui->bt_ok, SIGNAL(clicked()), this, SLOT(ok_slot()));
    connect(ui->bt_cancel, SIGNAL(clicked()), this, SLOT(cancel_slot()));
}

void change_screentip::ok_slot()
{
    accept();
}

void change_screentip::cancel_slot()
{
    reject();
}

void change_screentip::set_tip(QString str)
{
    ui->label_tip->setText(str);
}
