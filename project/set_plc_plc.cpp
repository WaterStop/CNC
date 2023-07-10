#include "set_plc_plc.h"
#include "ui_set_plc_plc.h"

static int cur_page = 0;//功能菜单当前页数
static int menu_lv = 0;//功能菜单等级

Set_Plc_plc::Set_Plc_plc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set_Plc_plc)
{
    ui->setupUi(this);
    Init();
    set_background();
    set_PLC_Lad();
    DealSlot();
}

Set_Plc_plc::~Set_Plc_plc()
{
    delete ui;
}

void Set_Plc_plc::set_background()
{

}

void Set_Plc_plc::Init()
{
    button_set();
}

void Set_Plc_plc::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    //image.load(":/new/blue_pic/set_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void Set_Plc_plc::DealSlot()
{
    connect(bt_fun_right[0],SIGNAL(pressed()),this,SLOT(RIGHT_FUN0_slot()));
    connect(bt_fun_right[1],SIGNAL(pressed()),this,SLOT(RIGHT_FUN1_slot()));
    connect(bt_fun_right[2],SIGNAL(pressed()),this,SLOT(RIGHT_FUN2_slot()));
    connect(bt_fun_right[3],SIGNAL(pressed()),this,SLOT(RIGHT_FUN3_slot()));
    connect(bt_fun_right[4],SIGNAL(pressed()),this,SLOT(RIGHT_FUN4_slot()));
    connect(bt_fun_right[5],SIGNAL(pressed()),this,SLOT(RIGHT_FUN5_slot()));
    connect(bt_fun_right[6],SIGNAL(pressed()),this,SLOT(RIGHT_FUN6_slot()));
    connect(bt_fun_right[7],SIGNAL(pressed()),this,SLOT(RIGHT_FUN7_slot()));
}

void Set_Plc_plc::button_set()
{
    int i;
    for (i=0;i<8;i++)
    {
        bt_fun[i] = new QPushButton(this);
        bt_fun[i]->setGeometry(30+i*70,460,40,40);
        bt_fun_right[i] = new QPushButton(this);
        bt_fun_right[i]->setGeometry(630,20+i*55,40,40);
    }

    menuRight_info_show(0);

}

void Set_Plc_plc::set_PLC_Lad()
{
    plc_w = new PLC_plc_pic(ui->frame);
    plc_w->setGeometry(2,5,620,450);
}

void Set_Plc_plc::UpdataTimer()
{

}

void Set_Plc_plc::RIGHT_FUN0_slot()
{
    if(menu_lv==0)
    {
        BaseCmd();
    }
    else if(menu_lv==1)
    {
        if(cur_page==0)
        {
            menu_lv = 0;
            SonMenuNo = -1;
        }
        else if(cur_page==1)
        {
            cur_page = 0;
        }
        menuRight_info_show(0);
    }
}

void Set_Plc_plc::RIGHT_FUN1_slot()
{
    if(menu_lv==0)
    {
        FuncCmd();
    }
    else if(menu_lv==1)
    {
        if(cur_page==0)
        {
            //SonMenuNo = 0;
            plc_w->LadViewMenuKeyDeal(SoftFuncKey0);
        }
        else if(cur_page==1)
        {
            //cur_page = 0;
        }
        menuRight_info_show(0);

    }
}

void Set_Plc_plc::RIGHT_FUN2_slot()
{if(menu_lv==0)
    {
        EditCmd();
    }
}

void Set_Plc_plc::RIGHT_FUN3_slot()
{

}

void Set_Plc_plc::RIGHT_FUN4_slot()
{

}

void Set_Plc_plc::RIGHT_FUN5_slot()
{

}
void Set_Plc_plc::RIGHT_FUN6_slot()
{

}

void Set_Plc_plc::RIGHT_FUN7_slot()
{
    if(menu_lv==0)
    {

    }
    else if(menu_lv==1)
    {
        if(cur_page==0)
        {
            cur_page = 1;
        }
        menuRight_info_show(0);
    }
}

void Set_Plc_plc::FUN0_slot()
{

}

void Set_Plc_plc::FUN1_slot()
{

}
void Set_Plc_plc::FUN2_slot()
{

}

void Set_Plc_plc::FUN3_slot()
{

}

void Set_Plc_plc::FUN4_slot()
{

}

void Set_Plc_plc::FUN5_slot()
{

}
void Set_Plc_plc::FUN6_slot()
{

}
void Set_Plc_plc::FUN7_slot()
{

}

void Set_Plc_plc::fun_pageup_slot()
{

}

void Set_Plc_plc::fun_pagedown_slot()
{

}

void Set_Plc_plc::menuRight_info_show(int index)//右侧菜单内容显示
{
    if(menu_lv==0)
    {
        bt_fun_right[0]->setText("基本\n指令");
        bt_fun_right[1]->setText("功能\n指令");
        bt_fun_right[2]->setText("编辑\n指令");
        bt_fun_right[3]->setText("向上\n查找");
        bt_fun_right[4]->setText("向下\n查找");
        bt_fun_right[5]->setText("首行");
        bt_fun_right[6]->setText("名称\n注释");
        bt_fun_right[7]->setText("");
        bt_fun_right[0]->setStyleSheet(0);
        bt_fun_right[1]->setStyleSheet(0);
        bt_fun_right[2]->setStyleSheet(0);
        bt_fun_right[3]->setStyleSheet(0);
        bt_fun_right[4]->setStyleSheet(0);
        bt_fun_right[5]->setStyleSheet(0);
        bt_fun_right[6]->setStyleSheet(0);
        bt_fun_right[7]->setStyleSheet(0);
    }
    switch (index)
    {
    case 0:
    if(menu_lv==1)
    {
        bt_fun_right[0]->setText("");
        bt_fun_right[1]->setText("");
        bt_fun_right[2]->setText("");
        bt_fun_right[3]->setText("");
        bt_fun_right[4]->setText("");
        bt_fun_right[5]->setText("");
        bt_fun_right[6]->setText("");
        bt_fun_right[7]->setText("");

        if(cur_page==0)
        {
            bt_fun_right[0]->setText("▲");
            bt_fun_right[1]->setStyleSheet("border-image:url(:/new/blue_pic/fun_rd.png);");
            bt_fun_right[2]->setStyleSheet("border-image:url(:/new/blue_pic/fun_rdnot.png);");
            bt_fun_right[3]->setStyleSheet("border-image:url(:/new/blue_pic/fun_wrt.png);");
            bt_fun_right[4]->setStyleSheet("border-image:url(:/new/blue_pic/fun_wrtnot.png);");
            bt_fun_right[5]->setStyleSheet("border-image:url(:/new/blue_pic/fun_horizon.png);");
            bt_fun_right[6]->setStyleSheet("border-image:url(:/new/blue_pic/fun_downlink.png);");
            bt_fun_right[7]->setText("▼");
        }
        else if(cur_page==1)
        {
            bt_fun_right[0]->setText("▲");
            bt_fun_right[1]->setStyleSheet("border-image:url(:/new/blue_pic/fun_downlinknot.png);");
            bt_fun_right[2]->setStyleSheet(0);
            bt_fun_right[3]->setStyleSheet(0);
            bt_fun_right[4]->setStyleSheet(0);
            bt_fun_right[5]->setStyleSheet(0);
            bt_fun_right[6]->setStyleSheet(0);
            bt_fun_right[7]->setText("");
        }
    }
    break;
    case 1:

    break;
    case 2:
        if(menu_lv==1)
        {
            if(cur_page==0)
            {
                bt_fun_right[0]->setText("▲");
                bt_fun_right[1]->setText("插入行");
                bt_fun_right[2]->setText("删除行");
                bt_fun_right[3]->setText("保存");
                bt_fun_right[4]->setText("注释");
                bt_fun_right[5]->setText("子程序");
                bt_fun_right[6]->setText("");
                bt_fun_right[7]->setText("");
            }
        }
    break;
    case 3:

    break;
    case 4:

    break;
    case 5:

    break;
    case 6:

    break;
    case 7:

    break;
    default:
        break;
    }

}

void Set_Plc_plc::BaseCmd()//基本指令
{
    menu_lv = 1;
    SonMenuNo = 0;
    menuRight_info_show(0);
}

void Set_Plc_plc::FuncCmd()//功能指令
{
    //menu_lv = 1;
    SonMenuNo = 1;
    func_popwin = new plc_fun_cmd();
    func_popwin->setGeometry(400,265,225,120);
    //func_popwin->
    int a = func_popwin->exec();
    delete func_popwin;
    if(a == 1)
    {

    }

}

void Set_Plc_plc::EditCmd()//编辑指令
{
    menu_lv = 1;
    SonMenuNo = 2;
    menuRight_info_show(2);
}

void Set_Plc_plc::Timer_on_slot()
{

}

void Set_Plc_plc::paintEvent(QPaintEvent *)
{
    QPainter painter( this);
    QPen pen;
}
