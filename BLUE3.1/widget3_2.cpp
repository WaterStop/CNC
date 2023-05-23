#include "widget3_2.h"
#include "ui_widget3_2.h"

static int t_mod = 0;
widget3_2::widget3_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget3_2)
{
    ui->setupUi(this);
    set_background();
    set_edit();
    set_button();

    connect(ui->bt_t_1,SIGNAL(clicked()),this,SLOT(set_Axis_dire_slot1()));
    connect(ui->bt_t_2,SIGNAL(clicked()),this,SLOT(set_Axis_dire_slot2()));
}

widget3_2::~widget3_2()
{
    delete ui;
}

void widget3_2::set_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg3_bk2.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget3_2::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg3_bk2.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget3_2::set_edit()
{
    ui->edit_1->setFont(weiruanyahei6);
    ui->edit_2->setFont(weiruanyahei6);
    ui->edit_3->setFont(weiruanyahei6);
    ui->edit_4->setFont(weiruanyahei6);
    ui->edit_5->setFont(weiruanyahei6);
    ui->edit_6->setFont(weiruanyahei6);
    ui->edit_7->setFont(weiruanyahei6);
    if(scr_size==0)
    {
        ui->edit_1->setGeometry(73,73,89,24);
        ui->edit_2->setGeometry(73,105,89,24);
        ui->edit_3->setGeometry(73,139,89,24);
        ui->edit_4->setGeometry(73,174,89,24);
        ui->edit_5->setGeometry(73,209,89,24);
        ui->edit_6->setGeometry(73,241,89,24);
        ui->edit_7->setGeometry(73,281,89,24);
    }
    else if(scr_size==1)
    {
        ui->edit_1->setGeometry(94,94,115,31);
        ui->edit_2->setGeometry(94,135,115,31);
        ui->edit_3->setGeometry(94,179,115,31);
        ui->edit_4->setGeometry(94,223,115,31);
        ui->edit_5->setGeometry(94,268,115,31);
        ui->edit_6->setGeometry(94,309,115,31);
        ui->edit_7->setGeometry(94,360,115,31);
        ui->bt_close->setGeometry(248,17,20,20);

    }
}

void widget3_2::set_button()
{
    set_Axis_dire();
    set_left_button();

    if(scr_size==0)
    {
        ui->bt_t_1->setGeometry(71,32,46,28);
        ui->bt_t_2->setGeometry(117,32,46,28);

        ui->bt_l_1->setGeometry(47,139,24,24);
        ui->bt_l_2->setGeometry(47,174,24,24);
    }
    else if(scr_size==1)
    {
        ui->bt_t_1->setGeometry(92,42,59,37);
        ui->bt_t_2->setGeometry(151,42,59,37);

        ui->bt_l_1->setGeometry(61,179,31,31);
        ui->bt_l_2->setGeometry(61,223,31,31);

    }

}

void widget3_2::set_Axis_dire()//轴旋转方向
{
    ui->bt_t_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_t_bt1_off.png);}");
    ui->bt_t_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_t_bt2_off.png);}");

    switch(t_mod)
    {
        case 0:
        ui->bt_t_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_t_bt1_on.png);}");
        break;
        case 1:
        ui->bt_t_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_t_bt2_on.png);}");
        break;
        default:
        break;
    }
}

void widget3_2::set_left_button()
{
    ui->bt_l_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt1.png);}");
    ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt2.png);}");
    ui->bt_close->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_bt_close.png);}");

}

void widget3_2::set_Axis_dire_slot1()
{
    t_mod = 0;
    set_Axis_dire();
}

void widget3_2::set_Axis_dire_slot2()
{
    t_mod = 1;
    set_Axis_dire();
}
