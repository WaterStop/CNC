#include "set_dgn.h"
#include "ui_set_dgn.h"

set_dgn::set_dgn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_dgn)
{
    ui->setupUi(this);
    Init();
    set_background();
    //DealSlot();
    Deal_slot();
    load_info();
    set_info();
}

set_dgn::~set_dgn()
{
    delete ui;
}

void set_dgn::set_background()
{

}

void set_dgn::Init()
{
    button_set();
    timer->start(20);
}

void set_dgn::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    //image.load(":/new/blue_pic/set_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void set_dgn::DealSlot()
{
//    connect(bt_fun_right[0],SIGNAL(pressed()),this,SLOT(RIGHT_FUN0_slot()));
//    connect(bt_fun_right[1],SIGNAL(pressed()),this,SLOT(RIGHT_FUN1_slot()));
//    connect(bt_fun_right[2],SIGNAL(pressed()),this,SLOT(RIGHT_FUN2_slot()));
//    connect(bt_fun_right[3],SIGNAL(pressed()),this,SLOT(RIGHT_FUN3_slot()));
//    connect(bt_fun_right[4],SIGNAL(pressed()),this,SLOT(RIGHT_FUN4_slot()));
//    connect(bt_fun_right[5],SIGNAL(pressed()),this,SLOT(RIGHT_FUN5_slot()));
//    connect(bt_fun_right[6],SIGNAL(pressed()),this,SLOT(RIGHT_FUN6_slot()));
//    connect(bt_fun_right[7],SIGNAL(pressed()),this,SLOT(RIGHT_FUN7_slot()));
}

void set_dgn::button_set()
{
//    int i;
//    for (i=0;i<8;i++)
//    {
//        bt_fun[i] = new QPushButton(this);
//        bt_fun[i]->setGeometry(30+i*70,460,40,40);
//        bt_fun_right[i] = new QPushButton(this);
//        bt_fun_right[i]->setGeometry(630,20+i*55,40,40);
//    }
    bt_back = new QPushButton(this);
    bt_back->setFont(weiruanyahei4);
    bt_back->setGeometry(550,440,50,30);
    bt_back->setText("返回");
    //bt_back->setStyleSheet("color: rgb(255, 255, 255);");

}

void set_dgn::Deal_slot()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));
    connect(bt_back,SIGNAL(clicked()),this,SLOT(back_slot()));
}

void set_dgn::load_info()
{
    int i,j,k;
    for (i=0;i<32;i++)
    {
        label_in[i] = new QLabel(this);
        label_out[i] = new QLabel(this);
        label_in[i]->setGeometry(20+(i/7)*110,20+(i%7)*20,95,20);
        label_out[i]->setGeometry(20+(i/7)*110,190+(i%7)*20,95,20);
        label_in[i]->setFont(weiruanyahei4);
        label_out[i]->setFont(weiruanyahei4);
        label_in[i]->setStyleSheet("color: rgb(255, 255, 255);");
        label_out[i]->setStyleSheet("color: rgb(255, 255, 255);");
    }
    for (j=0;j<5;j++)
    {
        label_handwheel[j] = new QLabel(this);
        label_handwheel[j]->setFont(weiruanyahei4);
        label_handwheel[j]->setGeometry(20,370+j*20,250,20);
        label_handwheel[j]->setStyleSheet("color: rgb(255, 255, 255);");
    }
//    label_handwheel[0] = new QLabel(this);
//    label_handwheel[1] = new QLabel(this);
//    label_handwheel[0]->setFont(weiruanyahei4);
//    label_handwheel[1]->setFont(weiruanyahei4);
//    label_handwheel[0]->setGeometry(20,370,95,20);
//    label_handwheel[1]->setGeometry(20,390,95,20);
//    label_handwheel[0]->setStyleSheet("color: rgb(255, 255, 255);");
//    label_handwheel[1]->setStyleSheet("color: rgb(255, 255, 255);");
}

void set_dgn::set_info()
{
    int i;
    QString str;
    for (i=0;i<32;i++)
    {
        str = QString("X%1 %2").arg(i).arg(plc_shm->xl[i]);
        label_in[i]->setText(str);
        str = QString("Y%1 %2").arg(i).arg(plc_shm->y[i]);
        label_out[i]->setText(str);
    }
    str = QString("MPG手轮:local_data[68]  %1 ").arg(motion_status->local_data[68]);
    label_handwheel[0]->setText(str);
    str = QString("操作站手轮:local_data[66]  %1 ").arg(motion_status->local_data[66]);
    label_handwheel[1]->setText(str);
    str = QString("附加面板手轮:local_data[70]  %1 ").arg(motion_status->local_data[70]);
    label_handwheel[2]->setText(str);
    str = QString("编码器1：local_data[50]  %1 ").arg(motion_status->local_data[50]);
    label_handwheel[3]->setText(str);
    str = QString("编码器2：local_data[51]  %1 ").arg(motion_status->local_data[51]);
    label_handwheel[4]->setText(str);
}

void set_dgn::Timer_on_slot()
{
    set_info();
}

void set_dgn::back_slot()
{
    emit back_signal();
}

void set_dgn::paintEvent(QPaintEvent *)
{

}
