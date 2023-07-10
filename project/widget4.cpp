#include "widget4.h"
#include "ui_widget4.h"

static bool bt_light_flg=0;//工作灯
static bool bt_Lubrication_flg=0;//润滑
static bool bt_Cool_flg=0;//冷却
static int move_dir=0;//移动方向 1:上 2：下 3：左 4：右
static bool movefast_flg=0;//快速移动
static int SingleAndFastRate=2;//进给倍率
int probar_val1,probar_val2;//进度条当前值


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
    //ui->label_f->setGeometry(374,45,130,85);
    int a = 100;/*
    ui->bt_left->setGeometry(216+a,81,46,47);
    ui->bt_right->setGeometry(314+a,81,46,47);
    ui->bt_up->setGeometry(264+a,32,46,47);
    ui->bt_down->setGeometry(264+a,129,46,47);
    ui->bt_fastmove->setGeometry(264+a,81,46,47);*/
    ui->bt_left->hide();
    ui->bt_right->hide();
    ui->bt_up->hide();
    ui->bt_down->hide();
    ui->bt_fastmove->hide();
    ui->bt_MAxisStop->hide();
    ui->bt_MAxisForw->hide();
    ui->bt_MAxisRev->hide();
    ui->label->setText("10h 15m");
    ui->label_2->setText("10h 15m");
    ui->label_3->setText("999");


    axis_pro = new ProgressRing(ui->frame);
    axis_pro->setGeometry(512,48,108,108);
    //axis_pro->setClipCenter(false);
    axis_pro->setMinValue(0);
    axis_pro->setMaxValue(200);
    //axis_pro->setValue(150);
    axis_pro->setStartAngle(180);
    axis_pro->setBgColor(QColor(6,12,45));
    axis_pro->setRingBgColor(QColor(0,0,0,0));
    //axis_pro->setRingBgColor(QColor(94,98,119));
    bar_bk = new QLabel(ui->frame);
    bar_bk->setStyleSheet("border-image:url(:/new/blue_pic/wg4_probar_bk.png)");
    bar_bk->setGeometry(500,38,133,90);
    //axis_pro->hide();


    for (int i=0;i<8;i++)
    {
        lb[i] = new QLabel(ui->frame);
        lb[i]->setFont(weiruanyahei4);
        lb[i]->setStyleSheet("color:white;");
        lb[i]->setAlignment(Qt::AlignCenter);
    }
    lb[0]->setGeometry(243,106,33,16);
    lb[1]->setGeometry(185,126,150,20);
    lb[2]->setGeometry(395,92,33,16);
    lb[3]->setGeometry(310,120,200,20);
    lb[4]->setGeometry(551,109,33,16);
    lb[5]->setGeometry(466,125,200,20);
    lb[6]->setGeometry(495,103,50,30);
    lb[7]->setGeometry(590,103,50,30);

    text_lev = new widget4_text(ui->frame);
    //text_lev->setGeometry(195,45,130,85);
    text_lev->setGeometry(185,0,459,206);

    //timer->start(50);
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
        ui->label->setGeometry(14,18,83,25);
        ui->label_2->setGeometry(14,53,83,25);
        ui->label_3->setGeometry(14,87,83,25);
        //ui->label_f->setGeometry(383,45,150,86);
        ui->label_f->setGeometry(195,45,130,85);

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
    //connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));
}

void widget4::Timer_on_slot()
{
    update_workstate();
    text_lev->Timer_on_slot();

}

void widget4::set_wg4_button()
{
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
        ui->bt_switch->setGeometry(117,42,66,26);
        ui->bt_switch_2->setGeometry(117,101,66,26);
        ui->bt_switch_3->setGeometry(117,160,66,26);
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
    int tmp_int;
    //char *str1 = (char *)plc_shm->y[0];
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

    val = plc_shm->g[19] & 0xFF;
    if((((val >> 4) & 1) == 0)&&(((val >> 5) & 1) == 0))
    {
        SingleAndFastRate = 0;
        set_wg4_label_FastRate_solt();
        lb[0]->setText("F0");
        lb[1]->setText("X0.1");
    }
    else if((((val >> 4) & 1) == 1)&&(((val >> 5) & 1) == 0))
    {
        SingleAndFastRate = 1;
        set_wg4_label_FastRate_solt();
        lb[0]->setText("F25");
        lb[1]->setText("X1");
    }
    else if((((val >> 4) & 1) == 0)&&(((val >> 5) & 1) == 1))
    {
        SingleAndFastRate = 2;
        set_wg4_label_FastRate_solt();
        lb[0]->setText("F50");
        lb[1]->setText("X10");
    }
    else if((((val >> 4) & 1) == 1)&&(((val >> 5) & 1) == 1))
    {
        SingleAndFastRate = 3;
        set_wg4_label_FastRate_solt();
        lb[0]->setText("F100");
        lb[1]->setText("X100");
    }

    str = QString("%1%").arg(QString::number(motion_status->feed_scale*100).toInt());//进给速率
    lb[2]->setText(str);
    tmp_int = motion_status->requested_vel*motion_status->feed_scale;
    str = QString("%1mm/min").arg(tmp_int);//设定速度*倍率
    lb[3]->setText(str);
    //tmp_int = motion_internal->spin_data[0].spindle_scale*100;
    //str = QString("%1%").arg(tmp_int);//主轴倍率
    str = QString("%1%").arg(QString::number(motion_internal->spin_data[0].spindle_scale*100));//主轴倍率
    lb[4]->setText(str);
    tmp_int = motion_internal->spin_data[0].spindle_scale*motion_internal->spin_data[0].spind_speed_set;
    str = QString("%1rpm/min").arg(tmp_int);//设定主轴速度*倍率
    lb[5]->setText(str);
    axis_pro->setValue(motion_internal->spin_data[0].spindle_scale*100);
    lb[6]->setText("0");
    tmp_int = motion_internal->spin_data[0].spind_speed_set;
    str =  QString("%1").arg(tmp_int);//主轴设定速度
    lb[7]->setText(str);

    static int last_sta = 0;
    if((last_sta==0&&motion_internal->spin_data[0].spind_gear!=0)||(last_sta!=0&&motion_internal->spin_data[0].spind_gear==0))
    {
        if(motion_internal->spin_data[0].spind_gear==0)
        {
            bar_bk->setStyleSheet("border-image:url(:/new/blue_pic/wg4_probar_bk.png)");
            last_sta = motion_internal->spin_data[0].spind_gear;
        }
        else
        {
            bar_bk->setStyleSheet("border-image:url(:/new/blue_pic/wg4_probar_bk1.png)");
            last_sta = motion_internal->spin_data[0].spind_gear;
        }
    }
    update();

}

void widget4::set_wg4_button_solt()
{
    QString str;
    int val;
    val = plc_shm->y[0] & 0xFF;

    val ^= (1 << 0);
    plc_shm->y[0] = val;


}

void widget4::set_wg4_button_solt2()
{
    QString str;
    int val;
    val = plc_shm->y[0] & 0xFF;
    val ^= (1 << 1);//取反
    plc_shm->y[0] = val;

//    motion_status->requested_vel=2000;//去掉
//    motion_status->feed_scale = motion_status->feed_scale+0.1;
//    //motion_status->feed_scale = 1.5;
//    if(motion_status->feed_scale>1.6)
//    {
//        motion_status->feed_scale = 0;
//    }
}

void widget4::set_wg4_button_solt3()
{
    QString str;
    int val;
    val = plc_shm->y[0] & 0xFF;
    val ^= (1 << 2);//取反
    plc_shm->y[0] = val;

//    motion_internal->spin_data[0].spind_speed_set = 450;//去掉
//    motion_internal->spin_data[0].spindle_scale = motion_internal->spin_data[0].spindle_scale+0.01;
//    if(motion_internal->spin_data[0].spindle_scale>1)
//    {
//        motion_internal->spin_data[0].spindle_scale = 0;
//    }
}


int widget4::get_probar1_val()
{
    return probar_val1;
}

int widget4::get_probar2_val()
{
    return probar_val2;
}

void widget4::draw_prossbar(int x,int y)
{
    QPainter painter;
    QPen pen,pen1;
    QString str;
    pen = QPen(QColor(39,172,83));
    pen1.setColor(Qt::white);
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
    //qDebug()<<"draw_prossbar";

    //painter.drawLine(0,0,400,300);

    QPolygon t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14;
    painter.setBrush(QColor(39,172,83));

    t0<<QPoint(x,y+1)<<QPoint(x+17,y+1)<<QPoint(x+17,y-4)<<QPoint(x+1,y-7);
    t1<<QPoint(x+1,y-10)<<QPoint(x+19,y-6)<<QPoint(x+20,y-11)<<QPoint(x+3,y-18);
    t2<<QPoint(x+5,y-21)<<QPoint(x+21,y-14)<<QPoint(x+23,y-19)<<QPoint(x+9,y-29);
    t3<<QPoint(x+11,y-32)<<QPoint(x+25,y-21)<<QPoint(x+29,y-25)<<QPoint(x+16,y-38);
    t4<<QPoint(x+19,y-40)<<QPoint(x+31,y-27)<<QPoint(x+35,y-30)<<QPoint(x+25,y-45);
    t5<<QPoint(x+29,y-46)<<QPoint(x+37,y-31)<<QPoint(x+42,y-33)<<QPoint(x+36,y-50);
    t6<<QPoint(x+39,y-50)<<QPoint(x+45,y-33)<<QPoint(x+50,y-34)<<QPoint(x+47,y-52);
    t7<<QPoint(x+50,y-52)<<QPoint(x+52,y-35)<<QPoint(x+57,y-34)<<QPoint(x+58,y-52);
    t8<<QPoint(x+60,y-52)<<QPoint(x+60,y-34)<<QPoint(x+64,y-32)<<QPoint(x+69,y-50);
    t9<<QPoint(x+72,y-49)<<QPoint(x+67,y-32)<<QPoint(x+71,y-29)<<QPoint(x+80,y-45);
    t10<<QPoint(x+83,y-44)<<QPoint(x+73,y-28)<<QPoint(x+77,y-25)<<QPoint(x+90,y-39);
    t11<<QPoint(x+92,y-37)<<QPoint(x+79,y-23)<<QPoint(x+83,y-19)<<QPoint(x+98,y-31);
    t12<<QPoint(x+99,y-29)<<QPoint(x+84,y-17)<<QPoint(x+87,y-12)<<QPoint(x+103,y-20);
    t13<<QPoint(x+104,y-18)<<QPoint(x+88,y-10)<<QPoint(x+91,y-5)<<QPoint(x+106,y-9);
    t14<<QPoint(x+107,y-7)<<QPoint(x+91,y-3)<<QPoint(x+91,y+2)<<QPoint(x+108,y+2);

    //motion_status->feed_scale = 1.5;
    int feed_per = motion_status->feed_scale*100;
    if(feed_per==0)
    {

    }
    if(feed_per>0)
    {
        painter.drawPolygon(t0);
    }
    if(feed_per>10)
    {
        painter.drawPolygon(t1);
    }
    if(feed_per>20)
    {
        painter.drawPolygon(t2);
    }
    if(feed_per>30)
    {
        painter.drawPolygon(t3);
    }
    if(feed_per>40)
    {
        painter.drawPolygon(t4);
    }
    if(feed_per>50)
    {
        painter.drawPolygon(t5);
    }
    if(feed_per>60)
    {
        painter.drawPolygon(t6);
    }
    if(feed_per>70)
    {
        painter.drawPolygon(t7);
    }
    if(feed_per>80)
    {
        painter.drawPolygon(t8);
    }
    if(feed_per>90)
    {
        painter.drawPolygon(t9);
    }
    if(feed_per>100)
    {
        painter.setPen(pen);
        painter.drawPolygon(t10);
    }
    if(feed_per>110)
    {
        painter.setPen(pen);
        painter.drawPolygon(t11);
    }
    if(feed_per>120)
    {
        painter.setPen(pen);
        painter.drawPolygon(t12);
    }
    if(feed_per>130)
    {
        painter.setPen(pen);
        painter.drawPolygon(t13);
    }
    if(feed_per>140)
    {
        painter.setPen(pen);
        painter.drawPolygon(t14);
    }

    painter.setPen(pen1);

    painter.drawLine(x+72,y-49,x+67,y-32);
    painter.drawLine(x+67,y-32,x+71,y-29);
    painter.drawLine(x+71,y-29,x+80,y-45);
    painter.drawLine(x+80,y-45,x+72,y-49);

//    painter.drawLine(x+83,y-44,x+73,y-28);
//    painter.drawLine(x+73,y-28,x+77,y-25);
//    painter.drawLine(x+77,y-25,x+90,y-39);
//    painter.drawLine(x+90,y-39,x+83,y-44);

//    painter.drawLine(x+92,y-37,x+79,y-23);
//    painter.drawLine(x+79,y-23,x+83,y-19);
//    painter.drawLine(x+83,y-19,x+98,y-31);
//    painter.drawLine(x+98,y-31,x+92,y-37);

//    painter.drawLine(x+99,y-29,x+84,y-17);
//    painter.drawLine(x+84,y-17,x+87,y-12);
//    painter.drawLine(x+87,y-12,x+103,y-20);
//    painter.drawLine(x+103,y-20,x+99,y-29);

//    painter.drawLine(x+104,y-18,x+88,y-10);
//    painter.drawLine(x+88,y-10,x+91,y-5);
//    painter.drawLine(x+91,y-5,x+106,y-9);
//    painter.drawLine(x+106,y-9,x+104,y-18);

//    painter.drawLine(x+107,y-7,x+91,y-3);
//    painter.drawLine(x+91,y-3,x+91,y+2);
//    painter.drawLine(x+91,y+2,x+108,y+2);
//    painter.drawLine(x+108,y+2,x+107,y-7);

    painter.drawText(367,117, "0");
    painter.drawText(448,117, "150");


    painter.end();
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

void widget4::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPen pen;
    QString str;

    //QPixmap pixmap(":/new/blue_pic/wg4_bk.png");
    painter.begin(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.setRenderHint(QPainter::Antialiasing);
    //painter.drawPixmap(rect(),pixmap,QRect());
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);

    //draw_prossbar(362,100);


    painter.end();
}
