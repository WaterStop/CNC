#include "widget5.h"
#include "ui_widget5.h"

static bool lock_flg = 0;
static int cur_num = 0;

widget5::widget5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget5)
{
    ui->setupUi(this);
    set_wg5_background();
    set_wg5_button();
    set_wg5_edit();

    connect(ui->bt_lock,SIGNAL(clicked()),this,SLOT(set_lock_slot()));
    connect(ui->bt_num_1,SIGNAL(clicked()),this,SLOT(set_curnum_solt1()));
    connect(ui->bt_num_2,SIGNAL(clicked()),this,SLOT(set_curnum_solt2()));
    connect(ui->bt_num_3,SIGNAL(clicked()),this,SLOT(set_curnum_solt3()));
    connect(ui->bt_num_4,SIGNAL(clicked()),this,SLOT(set_curnum_solt4()));

}

widget5::~widget5()
{
    delete ui;
}

void widget5::set_wg5_background()
{
    //ui->label_bk->setPixmap(QPixmap(":/new_pic/blue_pic/wg5_bk.png"));
//    setAutoFillBackground(true);//做子窗口要设置，否则不显示
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new_pic/blue_pic/wg5_bk.png")));
//    setPalette(pal);

    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg5_bk.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}

void widget5::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new_pic/blue_pic/wg5_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget5::set_wg5_button()
{
    set_lock();
    set_curnum();

    if(scr_size==0)
    {
        ui->bt_lock->setGeometry(44,51,61,54);

        ui->bt_num_1->setGeometry(19,28,26,26);
        ui->bt_num_2->setGeometry(100,28,26,26);
        ui->bt_num_3->setGeometry(100,105,26,26);
        ui->bt_num_4->setGeometry(19,105,26,26);
    }
    else if(scr_size==1)
    {
        ui->bt_lock->setGeometry(57,66,79,70);

        ui->bt_num_1->setGeometry(25,36,34,34);
        ui->bt_num_2->setGeometry(128,36,34,34);
        ui->bt_num_3->setGeometry(128,135,34,34);
        ui->bt_num_4->setGeometry(25,135,34,34);

    }
}

void widget5::set_wg5_edit()
{
    QFont ft;

    if(scr_size==0)
    {
        ui->ed_1->setGeometry(179,31,25,17);
        ui->ed_2->setGeometry(179,50,25,17);
        ui->ed_3->setGeometry(179,101,25,17);


        ft.setPointSize(7);
        ui->ed_1->setFont(ft);
        ui->ed_2->setFont(ft);
        ui->ed_3->setFont(ft);
    }
    else if(scr_size==1)
    {
        ui->ed_1->setGeometry(230,40,32,22);
        ui->ed_2->setGeometry(230,65,32,22);
        ui->ed_3->setGeometry(230,130,32,22);

        ft.setPointSize(9);
        ui->ed_1->setFont(ft);
        ui->ed_2->setFont(ft);
        ui->ed_3->setFont(ft);
    }
}

void widget5::set_lock()
{
    if(lock_flg)
    {
        ui->bt_lock->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_lock_on.png);}");
    }
    else
    {
        ui->bt_lock->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_lock_off.png);}");
    }
}

void widget5::set_lock_slot()
{
    lock_flg = 1-lock_flg;
    set_lock();
}

void widget5::set_curnum()
{
    ui->bt_num_1->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num1_off.png);}");
    ui->bt_num_2->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num2_off.png);}");
    ui->bt_num_3->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num3_off.png);}");
    ui->bt_num_4->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num4_off.png);}");

    switch(cur_num)
    {
        case 0:
        ui->bt_num_1->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num1_on.png);}");
        break;
        case 1:
        ui->bt_num_2->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num2_on.png);}");
        break;
        case 2:
        ui->bt_num_3->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num3_on.png);}");
        break;
        case 3:
        ui->bt_num_4->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_num4_on.png);}");
        break;
        default:
        break;
    }
}

void widget5::set_curnum_solt1()
{
    cur_num = 0;
    set_curnum();
}
void widget5::set_curnum_solt2()
{
    cur_num = 1;
    set_curnum();
}
void widget5::set_curnum_solt3()
{
    cur_num = 2;
    set_curnum();
}
void widget5::set_curnum_solt4()
{
    cur_num = 3;
    set_curnum();
}
