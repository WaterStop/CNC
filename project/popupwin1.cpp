#include "popupwin1.h"
#include "ui_popupwin1.h"

static int work_mod = 0;//工作模式 二级菜单
static int work_path = 0;//工作路径 一级菜单
static int cur_mod[2];//当前工作状态，0为1级菜单，1为2级菜单

#define WAIYUAN     0
#define DUANMIAN    1
#define LIKONG      2
#define ZHUIMIAN    3
#define LUOWEN      4
#define DAOJIAO     5
#define DINGZHI     6


PopupWin1::PopupWin1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupWin1)
{
    ui->setupUi(this);
    set_popwin1_background();
    set_popwin1_button();
    DealSlot();

}

PopupWin1::~PopupWin1()
{
    delete ui;
}

void PopupWin1::set_popwin1_background()
{
//    setAutoFillBackground(true);//做子窗口要设置，否则不显示
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/blue_pic/PopupWin_2.png")));
//    setPalette(pal);

    ui->frame->setAutoFillBackground(true);
    //ui->frame->setAutoFillBackground(false);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/PopupWin_2.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
    //ui->frame->setStyleSheet("background:transparent;");
    //setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_TranslucentBackground,true);
}

void PopupWin1::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    setAutoFillBackground(true);
    image.load(":/new/blue_pic/PopupWin_2.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    //this->setPalette(palette);
    ui->frame->setPalette(palette);
    //this->setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground,true);

}

void PopupWin1::set_popwin1_button()
{
    int a= 30;
    ui->bt_return->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/pop1_return.png);}");
    set_workmode();
    set_bt_path();
    ui->bt_return->hide();
    if(scr_size==0)
    {
        ui->bt_return->setGeometry(7,156,20,57);

        ui->bt_mod->setGeometry(27,31,70,62);
        ui->bt_mod_1->setGeometry(27,117,70,62);
        ui->bt_mod_2->setGeometry(27,203,70,62);
        ui->bt_mod_3->setGeometry(27,289,70,62);

        ui->bt_0->setGeometry(110,54,42,42);
        ui->bt_1->setGeometry(110,109,42,42);
        ui->bt_2->setGeometry(110,171,42,42);
        ui->bt_3->setGeometry(110,226,42,42);
        ui->bt_4->setGeometry(110,281,42,42);
    }
    else if(scr_size==1)
    {
        ui->bt_return->setGeometry(12-a,200,26,73);

        ui->bt_mod->setGeometry(55-a,40,82,68);
        ui->bt_mod_1->setGeometry(55-a,120,82,68);
        ui->bt_mod_2->setGeometry(55-a,200,82,68);
        ui->bt_mod_3->setGeometry(55-a,280,82,68);
        ui->bt_mod_4->setGeometry(55-a,360,82,68);

        ui->bt_0->setGeometry(165-a,40,50,50);
        ui->bt_1->setGeometry(165-a,100,50,50);
        ui->bt_2->setGeometry(165-a,160,50,50);
        ui->bt_3->setGeometry(165-a,220,50,50);
        ui->bt_4->setGeometry(165-a,280,50,50);
        ui->bt_5->setGeometry(165-a,340,50,50);
        ui->bt_6->setGeometry(165-a,400,50,50);
    }
}

void PopupWin1::set_bt_path()//工艺选择一级菜单
{
    ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_waiyuan_off.png);}");
    ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_duanmian_off.png);}");
    ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_likong_off.png);}");
    ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_zhuimian_off.png);}");
    ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_luowen_off.png);}");
    ui->bt_5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_daojiao_off.png);}");
    ui->bt_6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_dingzhi_off.png);}");


    switch (work_path)
    {
        case WAIYUAN:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_waiyuan_on.png);}");
        set_workmode();
        break;
        case DUANMIAN:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_duanmian_on.png);}");
        set_workmode();
        break;
        case LIKONG:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_likong_on.png);}");
        set_workmode();
        break;
        case ZHUIMIAN:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_zhuimian_on.png);}");
        set_workmode();
        break;
        case LUOWEN:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_luowen_on.png);}");
        set_workmode();
        break;
        case DAOJIAO:
        ui->bt_5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_daojiao_on.png);}");
        set_workmode();
        break;
        case DINGZHI:
        ui->bt_6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_mod_dingzhi_on.png);}");
        set_workmode();
        break;
        default:
        break;
    }

}

void PopupWin1::DealSlot()
{
    connect(ui->bt_return,SIGNAL(clicked()),this,SLOT(close_popwin1_solt()));
    connect(ui->bt_mod,SIGNAL(clicked()),this,SLOT(set_workmode_solt()));
    connect(ui->bt_mod_1,SIGNAL(clicked()),this,SLOT(set_workmode_solt1()));
    connect(ui->bt_mod_2,SIGNAL(clicked()),this,SLOT(set_workmode_solt2()));
    connect(ui->bt_mod_3,SIGNAL(clicked()),this,SLOT(set_workmode_solt3()));
    connect(ui->bt_mod_4,SIGNAL(clicked()),this,SLOT(set_workmode_solt4()));

    connect(ui->bt_0,SIGNAL(clicked()),this,SLOT(set_bt_path_solt()));
    connect(ui->bt_1,SIGNAL(clicked()),this,SLOT(set_bt_path_solt1()));
    connect(ui->bt_2,SIGNAL(clicked()),this,SLOT(set_bt_path_solt2()));
    connect(ui->bt_3,SIGNAL(clicked()),this,SLOT(set_bt_path_solt3()));
    connect(ui->bt_4,SIGNAL(clicked()),this,SLOT(set_bt_path_solt4()));
    connect(ui->bt_5,SIGNAL(clicked()),this,SLOT(set_bt_path_solt5()));
    connect(ui->bt_6,SIGNAL(clicked()),this,SLOT(set_bt_path_solt6()));
}

void PopupWin1::close_popwin1()
{
    this->hide();
    //popupwin_flg1 = 0;
    update();
}

void PopupWin1::close_popwin1_solt()
{
    close_popwin1();
}

void PopupWin1::set_workmode()//工艺选择二级菜单
{
//    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_bt_off.png);}");
//    ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_bt1_off.png);}");
//    ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_bt2_off.png);}");
//    ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_bt3_off.png);}");

    ui->bt_mod->show();
    ui->bt_mod_1->show();
    ui->bt_mod_2->show();
    ui->bt_mod_3->show();
    ui->bt_mod_4->show();

    switch (work_path)
    {
        case WAIYUAN:
        set_WaiYuan_pic();
        break;
        case DUANMIAN:
        set_DuanMian_pic();
        break;
        case LIKONG:
        set_LiKong_pic();
        break;
        case ZHUIMIAN:
        set_ZhuiMian_pic();
        break;
        case LUOWEN:
        set_LuoWen_pic();
        break;
        case DAOJIAO:
        set_DaoJiao_pic();
        break;
        case DINGZHI:
        set_DingZhi_pic();
        break;
        default:
        break;
    }
    //close_popwin1();
}

void PopupWin1::set_WaiYuan_pic()
{
    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_off.png);}");
    ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_off.png);}");
    ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_off.png);}");
    ui->bt_mod_3->hide();
    ui->bt_mod_4->hide();

    switch (work_mod)
    {
        case 0:
        if(cur_mod[0]!=0)
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_off.png);}");
        }
        else
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_on.png);}");
        }
        break;
        case 1:
		if(cur_mod[0]!=0)
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_off.png);}");
        }
        else
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_on.png);}");
        }
        break;
        case 2:
        if(cur_mod[0]!=0)
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_off.png);}");
        }
        else
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_on.png);}");
        }
        break;
        default:
        break;
    }
}

void PopupWin1::set_DuanMian_pic()
{
    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_off.png);}");
    ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_off.png);}");
    ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_off.png);}");
    ui->bt_mod_3->hide();
    ui->bt_mod_4->hide();

    switch (work_mod)
    {
        case 0:
        if(cur_mod[0]!=1)
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_off.png);}");
        }
        else
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_on.png);}");
        }
        break;
        case 1:
        if(cur_mod[0]!=1)
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_off.png);}");
        }
        else
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_on.png);}");
        }
        break;
        case 2:
        if(cur_mod[0]!=1)
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_off.png);}");
        }
        else
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_on.png);}");
        }
        break;
        default:
        break;
    }
}

void PopupWin1::set_LiKong_pic()
{
    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_off.png);}");
    ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_off.png);}");
    ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_off.png);}");
    ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_off.png);}");
    ui->bt_mod_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_off.png);}");

    switch (work_mod)
    {
        case 0:
        if(cur_mod[0]!=2)
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_off.png);}");
        }
        else
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_on.png);}");
        }
        break;
        case 1:
        if(cur_mod[0]!=2)
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_off.png);}");
        }
        else
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_on.png);}");
        }
        break;
        case 2:
        if(cur_mod[0]!=2)
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_off.png);}");
        }
        else
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_on.png);}");
        }
        break;
        case 3:
        if(cur_mod[0]!=2)
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_off.png);}");
        }
        else
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_on.png);}");
        }
        break;
        case 4:
        if(cur_mod[0]!=2)
        {
            ui->bt_mod_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_off.png);}");
        }
        else
        {
            ui->bt_mod_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_on.png);}");
        }
        break;
        default:
        break;
    }
}

void PopupWin1::set_ZhuiMian_pic()
{
    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_off.png);}");
    ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_off.png);}");
    ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_off.png);}");
    ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_off.png);}");
    ui->bt_mod_4->hide();

    switch (work_mod)
    {
        case 0:
        if(cur_mod[0]!=3)
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_off.png);}");
        }
        else
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_on.png);}");
        }

        break;
        case 1:
        if(cur_mod[0]!=3)
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_off.png);}");
        }
        else
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_on.png);}");
        }
        break;
        case 2:
        if(cur_mod[0]!=3)
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_off.png);}");
        }
        else
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_on.png);}");
        }
        break;
        case 3:
        if(cur_mod[0]!=3)
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_off.png);}");
        }
        else
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_on.png);}");
        }
        break;
        default:
        break;
    }
}

void PopupWin1::set_LuoWen_pic()
{
    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_off.png);}");
    ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_off.png);}");
    ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_off.png);}");
    ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_off.png);}");
    ui->bt_mod_4->hide();

    switch (work_mod)
    {
        case 0:
        if(cur_mod[0]!=4)
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_off.png);}");
        }
        else
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_on.png);}");
        }
        break;
        case 1:
        if(cur_mod[0]!=4)
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_off.png);}");
        }
        else
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_on.png);}");
        }
        break;
        case 2:
        if(cur_mod[0]!=4)
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_off.png);}");
        }
        else
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_on.png);}");
        }
        break;
        case 3:
        if(cur_mod[0]!=4)
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_off.png);}");
        }
        else
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_on.png);}");
        }
        break;
        default:
        break;
    }
}

void PopupWin1::set_DaoJiao_pic()
{
    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_off.png);}");
    ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_off.png);}");
    ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_off.png);}");
    ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_off.png);}");
    ui->bt_mod_4->hide();

    switch (work_mod)
    {
        case 0:
        if(cur_mod[0]!=5)
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_on.png);}");
        }
        else
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_on.png);}");
        }

        break;
        case 1:
        if(cur_mod[0]!=5)
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_off.png);}");
        }
        else
        {
            ui->bt_mod_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_on.png);}");
        }

        break;
        case 2:
        if(cur_mod[0]!=5)
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_off.png);}");
        }
        else
        {
            ui->bt_mod_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_on.png);}");
        }
        break;
        case 3:
        if(cur_mod[0]!=5)
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_off.png);}");
        }
        else
        {
            ui->bt_mod_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_on.png);}");
        }
        break;
        default:
        break;
    }
}

void PopupWin1::set_DingZhi_pic()
{
    ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_dingzhi1_off.png);}");
    ui->bt_mod_1->hide();
    ui->bt_mod_2->hide();
    ui->bt_mod_3->hide();
    ui->bt_mod_4->hide();

    switch (work_mod)
    {
        case 0:
        if(cur_mod[0]!=6)
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_dingzhi1_of.png);}");
        }
        else
        {
            ui->bt_mod->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_dingzhi1_on.png);}");
        }
        break;
        default:
        break;
    }
}

void PopupWin1::Deal_cur_wormod()
{
    last_work_mod = cur_work_mod;
    if(work_path==WAIYUAN)
    {
        switch(work_mod)
        {
            case 0:
            cur_work_mod = waiyuan1;
            break;
            case 1:
            cur_work_mod = waiyuan2;
            break;
            case 2:
            cur_work_mod = waiyuan3;
            break;
            default:
            break;
        }

    }
    else if(work_path==DUANMIAN)
    {
        switch(work_mod)
        {
            case 0:
            cur_work_mod = duanmian1;
            break;
            case 1:
            cur_work_mod = duanmian2;
            break;
            case 2:
            cur_work_mod = duanmian3;
            break;
            default:
            break;
        }
    }
    else if(work_path==LIKONG)
    {
        switch(work_mod)
        {
            case 0:
            cur_work_mod = likong1;
            break;
            case 1:
            cur_work_mod = likong2;
            break;
            case 2:
            cur_work_mod = likong3;
            break;
            case 3:
            cur_work_mod = likong4;
            break;
            case 4:
            cur_work_mod = likong5;
            break;
            default:
            break;
        }
    }
    else if(work_path==ZHUIMIAN)
    {
        switch(work_mod)
        {
            case 0:
            cur_work_mod = zhuimian1;
            break;
            case 1:
            cur_work_mod = zhuimian2;
            break;
            case 2:
            cur_work_mod = zhuimian3;
            break;
            case 3:
            cur_work_mod = zhuimian4;
            break;
            default:
            break;
        }
    }
    else if(work_path==LUOWEN)
    {
        switch(work_mod)
        {
            case 0:
            cur_work_mod = luowen1;
            break;
            case 1:
            cur_work_mod = luowen2;
            break;
            case 2:
            cur_work_mod = luowen3;
            break;
            case 3:
            cur_work_mod = luowen4;
            break;
            default:
            break;
        }
    }
    else if(work_path==DAOJIAO)
    {
        switch(work_mod)
        {
            case 0:
            cur_work_mod = daojiao1;
            break;
            case 1:
            cur_work_mod = daojiao2;
            break;
            case 2:
            cur_work_mod = daojiao3;
            break;
            case 3:
            cur_work_mod = daojiao4;
            break;
            default:
            break;
        }
    }
}

void PopupWin1::set_workmode_solt()
{
    work_mod = 0;
    cur_mod[0] = work_path;
    cur_mod[1] = work_mod;
    set_workmode();
    Deal_cur_wormod();
    emit change_work_signal();
    close_popwin1();
}

void PopupWin1::set_workmode_solt1()
{
    work_mod = 1;
    cur_mod[0] = work_path;
    cur_mod[1] = work_mod;
    set_workmode();
    Deal_cur_wormod();
    emit change_work_signal();
    close_popwin1();
}

void PopupWin1::set_workmode_solt2()
{
    work_mod = 2;
    cur_mod[0] = work_path;
    cur_mod[1] = work_mod;
    set_workmode();
    Deal_cur_wormod();
    emit change_work_signal();
    close_popwin1();
}

void PopupWin1::set_workmode_solt3()
{
    work_mod = 3;
    cur_mod[0] = work_path;
    cur_mod[1] = work_mod;
    set_workmode();
    Deal_cur_wormod();
    emit change_work_signal();
    close_popwin1();
}

void PopupWin1::set_workmode_solt4()
{
    work_mod = 4;
    cur_mod[0] = work_path;
    cur_mod[1] = work_mod;
    set_workmode();
    Deal_cur_wormod();
    emit change_work_signal();
    close_popwin1();
}

void PopupWin1::set_bt_path_solt()
{
    work_path = 0;
    set_bt_path();
}
void PopupWin1::set_bt_path_solt1()
{
    work_path = 1;
    set_bt_path();
}
void PopupWin1::set_bt_path_solt2()
{
    work_path = 2;
    set_bt_path();
}
void PopupWin1::set_bt_path_solt3()
{
    work_path = 3;
    set_bt_path();
}
void PopupWin1::set_bt_path_solt4()
{
    work_path = 4;
    set_bt_path();
}

void PopupWin1::set_bt_path_solt5()
{
    work_path = 5;
    set_bt_path();
}

void PopupWin1::set_bt_path_solt6()
{
    work_path = 6;
    set_bt_path();
}
