#include "widget4.h"
#include "ui_widget4.h"

static bool bt_light_flg=0;//工作灯
static bool bt_Lubrication_flg=0;//润滑
static bool bt_Cool_flg=0;//冷却
static int move_dir=0;//移动方向 1:上 2：下 3：左 4：右
static bool movefast_flg=0;//快速移动
static int SingleAndFastRate=2;//进给倍率


widget4::widget4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget4)
{
    ui->setupUi(this);
    info_init();
    set_wg4_background();
    set_wg4_button();
    set_wg4_label();
    DealSlot();
}

widget4::~widget4()
{
    delete ui;
}

void widget4::set_wg4_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg4_bk.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget4::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg4_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget4::info_init()
{
    QString str;
    int val;
    str = QString( plc_shm->y[0]);
    val = str.toInt();
    //if(((a&(1<<tem_i))>>tem_i)==1)//第0位
    if(((val >> 0) & 1) == 1) //第0位
    {
        bt_light_flg = 1;
    }
    else
    {
        bt_light_flg = 0;
    }

    if(((val >> 1) & 1) == 1) //第1位
    {
        bt_Lubrication_flg = 1;
    }
    else
    {
        bt_Lubrication_flg = 0;
    }

    if(((val >> 2) & 1) == 1) //第2位
    {
        bt_Cool_flg = 1;
    }
    else
    {
        bt_Cool_flg = 0;
    }
    timer->start(50);
}

void widget4::set_wg4_label()
{
    QFont ft;
    switch(SingleAndFastRate)
    {
        case 0:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f0.png);}");
        break;
        case 1:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f25.png);}");
        break;
        case 2:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f50.png);}");
        break;
        case 3:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f100.png);}");
        break;
        default:
        break;
    }

    if(scr_size==0)
    {
        ui->label->setGeometry(28,15,64,19);
        ui->label_2->setGeometry(28,41,64,19);
        ui->label_3->setGeometry(28,67,64,19);
        ui->label_f->setGeometry(300,35,117,67);

        ft.setPointSize(7);
        ui->label->setFont(ft);
        ui->label_2->setFont(ft);
        ui->label_3->setFont(ft);
    }
    else if(scr_size==1)
    {
        ui->label->setGeometry(36,20,83,25);
        ui->label_2->setGeometry(36,53,83,25);
        ui->label_3->setGeometry(36,87,83,25);
        ui->label_f->setGeometry(383,45,150,86);

        ft.setPointSize(9);
        ui->label->setFont(weiruanyahei4);
        ui->label_2->setFont(weiruanyahei4);
        ui->label_3->setFont(weiruanyahei4);
    }
}

void widget4::DealSlot()
{
    connect(ui->bt_switch,SIGNAL(clicked()),this,SLOT(set_wg4_button_solt()));
    connect(ui->bt_switch_2,SIGNAL(clicked()),this,SLOT(set_wg4_button_solt2()));
    connect(ui->bt_switch_3,SIGNAL(clicked()),this,SLOT(set_wg4_button_solt3()));
//    connect(ui->bt_up,SIGNAL(clicked()),this,SLOT(set_wg4_button_move_up_solt()));
//    connect(ui->bt_down,SIGNAL(clicked()),this,SLOT(set_wg4_button_move_down_solt()));
//    connect(ui->bt_left,SIGNAL(clicked()),this,SLOT(set_wg4_button_move_left_solt()));
//    connect(ui->bt_right,SIGNAL(clicked()),this,SLOT(set_wg4_button_move_right_solt()));
//    connect(ui->bt_fastmove,SIGNAL(clicked()),this,SLOT(set_wg4_button_move_fast_solt()));
//    connect(ui->bt_MAxisRev,SIGNAL(clicked()),this,SLOT(set_wg4_button_MainAxis_R()));
//    connect(ui->bt_MAxisForw,SIGNAL(clicked()),this,SLOT(set_wg4_button_MainAxis_F()));
//    connect(ui->bt_MAxisStop,SIGNAL(clicked()),this,SLOT(set_wg4_button_MainAxis_S()));
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));
}

void widget4::Timer_on_slot()
{
    update_workstate();
}

void widget4::set_wg4_button()
{
    ui->bt_clock->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_clock.png);}");
    //---------------------工作灯
    if(bt_light_flg)
    {
        ui->bt_switch->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");
    }
    else
    {
        ui->bt_switch->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }
    //-------------润滑开关
    if(bt_Lubrication_flg)
    {
        ui->bt_switch_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");
    }
    else
    {
        ui->bt_switch_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }
    //---------------------冷却
    if(bt_Cool_flg)
    {
        ui->bt_switch_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on2.png);}");
    }
    else
    {
        ui->bt_switch_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off2.png);}");
    }
    //----------------------
    ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_up_off.png);}");
    ui->bt_down->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_down_off.png);}");
    ui->bt_left->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_left_off.png);}");
    ui->bt_right->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_off.png);}");
    ui->bt_fastmove->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_fastmove_off.png);}");

    //----------------------------移动方向
    if(move_dir==1)
    {
        ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_up_on.png);}");
    }
    else if(move_dir==2)
    {
        ui->bt_down->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_down_on.png);}");
    }
    else if(move_dir==3)
    {
        ui->bt_left->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_left_on.png);}");
    }
    else if(move_dir==4)
    {
        ui->bt_right->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_on.png);}");
    }

    //-----------------------------------主轴旋转
    ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_off.png);}");
    ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_off.png);}");
    ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_on.png);}");

    //------------------------位置尺寸
    if(scr_size==0)
    {
        ui->bt_clock->setGeometry(10,95,22,24);
        ui->bt_switch->setGeometry(111,33,51,20);
        ui->bt_switch_2->setGeometry(111,78,51,20);
        ui->bt_switch_3->setGeometry(111,125,51,20);
        ui->bt_up->setGeometry(217,25,36,36);
        ui->bt_down->setGeometry(217,100,36,36);
        ui->bt_left->setGeometry(178,62,36,36);
        ui->bt_right->setGeometry(255,62,36,36);
        ui->bt_fastmove->setGeometry(217,62,35,36);
        ui->bt_MAxisForw->setGeometry(447,14,33,26);
        ui->bt_MAxisRev->setGeometry(447,116,33,26);
        ui->bt_MAxisStop->setGeometry(447,63,35,33);
    }
    else if(scr_size==1)
    {
        ui->bt_clock->setGeometry(14,130,29,31);
        ui->bt_switch->setGeometry(141,42,66,26);
        ui->bt_switch_2->setGeometry(141,101,66,26);
        ui->bt_switch_3->setGeometry(141,160,66,26);
        ui->bt_up->setGeometry(275,32,46,47);
        ui->bt_down->setGeometry(275,129,46,47);
        ui->bt_left->setGeometry(226,81,46,47);
        ui->bt_right->setGeometry(324,81,46,47);
        ui->bt_fastmove->setGeometry(275,81,46,47);
        ui->bt_MAxisForw->setGeometry(564,19,43,34);
        ui->bt_MAxisRev->setGeometry(564,150,43,34);
        ui->bt_MAxisStop->setGeometry(564,80,45,43);
    }
}

void widget4::update_workstate()
{
    QString str;
    int val;
    char *str1 = (char *)plc_shm->y[0];
    //str = QString( plc_shm->y[0]);
    //str = QString(QLatin1String(str1));
    //val = str.toInt();
    val = plc_shm->y[0] & 0xFF;
    //qDebug()<<"实时val"<<plc_shm->y[0]<<str<<val;
    //if(((a&(1<<tem_i))>>tem_i)==1)//第0位
    if(((val >> 0) & 1) == 1) //第0位
    {
        bt_light_flg = 1;
    }
    else
    {
        bt_light_flg = 0;
    }

    if(((val >> 1) & 1) == 1) //第1位
    {
        bt_Lubrication_flg = 1;
    }
    else
    {
        bt_Lubrication_flg = 0;
    }

    if(((val >> 2) & 1) == 1) //第2位
    {
        bt_Cool_flg = 1;
    }
    else
    {
        bt_Cool_flg = 0;
    }

    if(bt_light_flg)
    {
        ui->bt_switch->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");

    }
    else
    {
        ui->bt_switch->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }

    if(bt_Lubrication_flg)
    {
        ui->bt_switch_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");

    }
    else
    {
        ui->bt_switch_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }

    if(bt_Cool_flg)
    {
        ui->bt_switch_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on2.png);}");

    }
    else
    {
        ui->bt_switch_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off2.png);}");
    }
    val = plc_shm->xl[0] & 0xFF;
    if(((val >> 0) & 1) == 1) //第0位
    {
        show_move_state(1);
    }
    if(((val >> 1) & 1) == 1) //第1位
    {
        show_move_state(2);
    }
    if(((val >> 2) & 1) == 1) //第2位
    {
        show_move_state(3);
    }
    if(((val >> 3) & 1) == 1) //第3位
    {
        show_move_state(4);
    }
    if(((val >> 4) & 1) == 1) //第4位
    {
        ui->bt_fastmove->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_fastmove_on.png);}");
    }
    else
    {
        ui->bt_fastmove->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_fastmove_off.png);}");
    }

    if(((val >> 5) & 1) == 1) //p点
    {
        ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_off.png);}");
        ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_off.png);}");
        ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_on.png);}");
    }
    else
    {
        ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_off.png);}");
        ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_off.png);}");
        ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_off.png);}");
    }
    if(((val >> 6) & 1) == 1) //正反转
    {
        ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_on.png);}");
        ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_off.png);}");
        ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_off.png);}");
    }
    else
    {
        ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_off.png);}");
        ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_on.png);}");
        ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_off.png);}");
    }
//    static int tem_l,tem_l1;
//    {
//        tem_l++;
//        if(tem_l==20)
//        {
//            tem_l1++;
//            if()
//        }
//    }

    val = plc_shm->g[19] & 0xFF;
    if((((val >> 4) & 1) == 0)&&(((val >> 5) & 1) == 0))
    {
        SingleAndFastRate = 0;
        set_wg4_label_FastRate_solt();
    }
    else if((((val >> 4) & 1) == 1)&&(((val >> 5) & 1) == 0))
    {
        SingleAndFastRate = 1;
        set_wg4_label_FastRate_solt();
    }
    else if((((val >> 4) & 1) == 0)&&(((val >> 5) & 1) == 1))
    {
        SingleAndFastRate = 2;
        set_wg4_label_FastRate_solt();
    }
    else if((((val >> 4) & 1) == 1)&&(((val >> 5) & 1) == 1))
    {
        SingleAndFastRate = 3;
        set_wg4_label_FastRate_solt();
    }
}

void widget4::set_wg4_button_solt()
{
    QString str;
    int val;
    val = plc_shm->y[0] & 0xFF;

    val ^= (1 << 0);
    qDebug()<<"val1"<<val;
    plc_shm->y[0] = val;
    qDebug()<<"plc_shm->y[0]"<<plc_shm->y[0];

//    if(bt_light_flg)
//    {
//        ui->bt_switch->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");

//    }
//    else
//    {
//        ui->bt_switch->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
//    }
}

void widget4::set_wg4_button_solt2()
{
    QString str;
    int val;
    val = plc_shm->y[0] & 0xFF;
    val ^= (1 << 1);//取反
    plc_shm->y[0] = val;
    //bt_Lubrication_flg = 1-bt_Lubrication_flg;

//    if(bt_Lubrication_flg)
//    {
//        ui->bt_switch_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");

//    }
//    else
//    {
//        ui->bt_switch_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
//    }
}

void widget4::set_wg4_button_solt3()
{
    QString str;
    int val;
    val = plc_shm->y[0] & 0xFF;
    val ^= (1 << 2);//取反
    plc_shm->y[0] = val;
    //bt_Cool_flg = 1-bt_Cool_flg;

//    if(bt_Cool_flg)
//    {
//        ui->bt_switch_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on2.png);}");

//    }
//    else
//    {
//        ui->bt_switch_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off2.png);}");
//    }
}

void widget4::show_move_state(int index)
{
    ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_up_off.png);}");
    ui->bt_down->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_down_off.png);}");
    ui->bt_left->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_left_off.png);}");
    ui->bt_right->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_off.png);}");
    switch (index)
    {
        case 1:
        ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_up_on.png);}");
        break;
        case 2:
        ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_down_on.png);}");
        break;
        case 3:
        ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_left_on.png);}");
        break;
        case 4:
        ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_on.png);}");
        break;
        case 5:
        ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_on.png);}");
        break;
        default:
        break;

    }
}

void widget4::set_wg4_button_move_up_solt()
{
    move_dir = 1;

}

void widget4::set_wg4_button_move_down_solt()
{
    move_dir = 2;
    ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_up_off.png);}");
    ui->bt_down->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_down_on.png);}");
    ui->bt_left->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_left_off.png);}");
    ui->bt_right->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_off.png);}");
}

void widget4::set_wg4_button_move_left_solt()
{
    move_dir = 3;
    ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_up_off.png);}");
    ui->bt_down->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_down_off.png);}");
    ui->bt_left->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_left_on.png);}");
    ui->bt_right->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_off.png);}");
}

void widget4::set_wg4_button_move_right_solt()
{
    move_dir = 4;
    ui->bt_up->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_up_off.png);}");
    ui->bt_down->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_down_off.png);}");
    ui->bt_left->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_left_off.png);}");
    ui->bt_right->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_right_on.png);}");
}

void widget4::set_wg4_button_move_fast_solt()
{
    movefast_flg = 1-movefast_flg;
    if(movefast_flg)
    {
        ui->bt_fastmove->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_fastmove_on.png);}");
    }
    else
    {
        ui->bt_fastmove->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_fastmove_off.png);}");
    }
}

void widget4::set_wg4_label_FastRate_solt()
{
    switch(SingleAndFastRate)
    {
        case 0:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f0.png);}");
        break;
        case 1:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f25.png);}");
        break;
        case 2:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f50.png);}");
        break;
        case 3:
        ui->label_f->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/wg4_f100.png);}");
        break;
        default:
        break;
    }
}

void widget4::set_wg4_button_MainAxis_F()
{
    MainAxisState =1;
    ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_on.png);}");
    ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_off.png);}");
    ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_off.png);}");

}

void widget4::set_wg4_button_MainAxis_R()
{
    MainAxisState =2;
    ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_off.png);}");
    ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_on.png);}");
    ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_off.png);}");

}

void widget4::set_wg4_button_MainAxis_S()
{
    MainAxisState =0;
    ui->bt_MAxisForw->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisForw_off.png);}");
    ui->bt_MAxisRev->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MAxisRev_off.png);}");
    ui->bt_MAxisStop->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_MainAxisStop_on.png);}");

}
