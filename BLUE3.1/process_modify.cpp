#include "process_modify.h"
#include "ui_process_modify.h"

Process_modify::Process_modify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Process_modify)
{
    ui->setupUi(this);
    set_background();
    set_button();
    DealSlot();
}

Process_modify::~Process_modify()
{
    delete ui;
}

void Process_modify::set_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/process_modify.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void Process_modify::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/process_modify.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}


void Process_modify::set_button()
{
    ui->bt_cut->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->bt_move->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->bt_copy->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->bt_del->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->bt_stick->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->bt_edit->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->bt_add->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    if(scr_size==0)
    {
        ui->bt_cut->setGeometry(61,62,31,31);
        ui->bt_move->setGeometry(61,103,31,31);
        ui->bt_copy->setGeometry(114,387,65,29);
        ui->bt_del->setGeometry(248,17,20,20);
        ui->bt_stick->setGeometry(61,105,31,31);
        ui->bt_edit->setGeometry(114,387,65,29);
        ui->bt_add->setGeometry(248,17,20,20);
    }
    else if(scr_size==1)
    {
        ui->bt_cut->setGeometry(45,18,85,35);
        ui->bt_move->setGeometry(45,65,85,35);
        ui->bt_copy->setGeometry(45,100,85,35);
        ui->bt_del->setGeometry(45,140,85,35);
        ui->bt_stick->setGeometry(45,183,85,35);
        ui->bt_edit->setGeometry(45,221,85,35);
        ui->bt_add->setGeometry(45,260,85,35);
    }

    ui->bt_cut->setText("剪切");
    ui->bt_move->setText("移动");
    ui->bt_copy->setText("复制");
    ui->bt_del->setText("删除");
    ui->bt_stick->setText("粘贴");
    ui->bt_edit->setText("编辑");
    ui->bt_add->setText("添加");

    ui->bt_cut->setFont(weiruanyahei6);
    ui->bt_move->setFont(weiruanyahei6);
    ui->bt_copy->setFont(weiruanyahei6);
    ui->bt_del->setFont(weiruanyahei6);
    ui->bt_stick->setFont(weiruanyahei6);
    ui->bt_edit->setFont(weiruanyahei6);
    ui->bt_add->setFont(weiruanyahei6);
}

void Process_modify::DealSlot()
{
    connect(ui->bt_cut, SIGNAL(clicked()), this, SLOT(bt_pressed_slot()));
    connect(ui->bt_move, SIGNAL(clicked()), this, SLOT(bt_pressed_slot1()));
    connect(ui->bt_copy, SIGNAL(clicked()), this, SLOT(bt_pressed_slot2()));
    connect(ui->bt_del, SIGNAL(clicked()), this, SLOT(bt_pressed_slot3()));
    connect(ui->bt_stick, SIGNAL(clicked()), this, SLOT(bt_pressed_slot4()));
    connect(ui->bt_edit, SIGNAL(clicked()), this, SLOT(bt_pressed_slot5()));
    connect(ui->bt_add, SIGNAL(clicked()), this, SLOT(bt_pressed_slot6()));
}

void Process_modify::bt_pressed_slot()//剪切
{
    emit bt_pressed(jianqie);
}

void Process_modify::bt_pressed_slot1()//移动
{
    emit bt_pressed(yidong);
}

void Process_modify::bt_pressed_slot2()//复制
{
    emit bt_pressed(fuzhi);
}

void Process_modify::bt_pressed_slot3()//删除
{
    emit bt_pressed(shanchu);
}

void Process_modify::bt_pressed_slot4()//粘贴
{
    emit bt_pressed(zhantie);
}

void Process_modify::bt_pressed_slot5()//编辑
{
    emit bt_pressed(bianji);
}

void Process_modify::bt_pressed_slot6()//添加
{
    emit bt_pressed(tianjia);
}

