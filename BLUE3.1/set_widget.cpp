#include "set_widget.h"
#include "ui_set_widget.h"

static int cur_page = 0;//功能菜单当前页数
static int menu_lv = 0;//功能菜单等级

set_widget::set_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_widget)
{
    ui->setupUi(this);
    Init();
    set_background();
    SetNavigationBar();
    //set_PLC_Lad();

    DealSlot();

    ui->listView->setGeometry(5,12,182,615);
}

set_widget::~set_widget()
{
    delete ui;
}

void set_widget::set_background()
{

}

void set_widget::Init()
{
    //button_set();
    set_plc = new Set_Plc_plc(ui->frame);
    set_plc->setGeometry(190,10,691,614);
    set_plc->hide();
    dgn = new set_dgn(ui->frame);
    dgn->setGeometry(190,10,691,614);
    dgn->show();
}

void set_widget::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    image.load(":/new/blue_pic/set_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void set_widget::DealSlot()
{
//    connect(bt_fun_right[0],SIGNAL(pressed()),this,SLOT(RIGHT_FUN0_slot()));
//    connect(bt_fun_right[1],SIGNAL(pressed()),this,SLOT(RIGHT_FUN1_slot()));
//    connect(bt_fun_right[2],SIGNAL(pressed()),this,SLOT(RIGHT_FUN2_slot()));
//    connect(bt_fun_right[3],SIGNAL(pressed()),this,SLOT(RIGHT_FUN3_slot()));
//    connect(bt_fun_right[4],SIGNAL(pressed()),this,SLOT(RIGHT_FUN4_slot()));
//    connect(bt_fun_right[5],SIGNAL(pressed()),this,SLOT(RIGHT_FUN5_slot()));
//    connect(bt_fun_right[6],SIGNAL(pressed()),this,SLOT(RIGHT_FUN6_slot()));
//    connect(bt_fun_right[7],SIGNAL(pressed()),this,SLOT(RIGHT_FUN7_slot()));
    connect(dgn,SIGNAL(back_signal()),this,SLOT(back_slot()));
}

void set_widget::button_set()
{
    int i;
//    for (i=0;i<8;i++)
//    {
//        bt_fun[i] = new QPushButton(this);
//        bt_fun[i]->setGeometry(220+i*70,475,40,40);
//        bt_fun_right[i] = new QPushButton(this);
//        bt_fun_right[i]->setGeometry(820,20+i*55,40,40);
//    }

//    menuRight_info_show_plcpic(0);

}

void set_widget::SetNavigationBar()
{
    CNavModel* pNavModel = new CNavModel(this);
    CNavDelegate* pDelegate = new CNavDelegate(this);
    pNavModel->ReadConfig(QCoreApplication::applicationDirPath() += "/config/navigation.xml");
    ui->listView->setModel(pNavModel);
    ui->listView->setItemDelegate(pDelegate);
    connect(ui->listView, SIGNAL(doubleClicked(const QModelIndex &)), pNavModel, SLOT(Collapse(const QModelIndex &)));
}

void set_widget::back_slot()
{
    emit back_signal();
}

//void set_widget::set_PLC_Lad()
//{
//    PLC_plc_pic *plc_w = new PLC_plc_pic(ui->frame);
//    plc_w->setGeometry(190,20,620,450);
//}

//void set_widget::UpdataTimer()
//{

//}

//void set_widget::RIGHT_FUN0_slot()
//{
//    if(menu_lv==0)
//    {
//        basic_ins();
//    }
//    else if(menu_lv==1)
//    {
//        if(cur_page==0)
//        {
//            menu_lv = 0;
//        }
//        else if(cur_page==1)
//        {
//            cur_page = 0;
//        }
//        menuRight_info_show_plcpic(0);
//    }
//}

//void set_widget::RIGHT_FUN1_slot()
//{

//}

//void set_widget::RIGHT_FUN2_slot()
//{if(menu_lv==0)
//    {
//        edit_ins();
//    }
//}

//void set_widget::RIGHT_FUN3_slot()
//{

//}

//void set_widget::RIGHT_FUN4_slot()
//{

//}

//void set_widget::RIGHT_FUN5_slot()
//{

//}
//void set_widget::RIGHT_FUN6_slot()
//{

//}

//void set_widget::RIGHT_FUN7_slot()
//{
//    if(menu_lv==0)
//    {

//    }
//    else if(menu_lv==1)
//    {
//        if(cur_page==0)
//        {
//            cur_page = 1;
//        }
//        menuRight_info_show_plcpic(0);
//    }
//}

//void set_widget::FUN0_slot()
//{

//}

//void set_widget::FUN1_slot()
//{

//}
//void set_widget::FUN2_slot()
//{

//}

//void set_widget::FUN3_slot()
//{

//}

//void set_widget::FUN4_slot()
//{

//}

//void set_widget::FUN5_slot()
//{

//}
//void set_widget::FUN6_slot()
//{

//}
//void set_widget::FUN7_slot()
//{

//}

//void set_widget::fun_pageup_slot()
//{

//}

//void set_widget::fun_pagedown_slot()
//{

//}

//void set_widget::menuRight_info_show_plcpic(int index)//右侧菜单内容显示
//{
//    if(menu_lv==0)
//    {
//        bt_fun_right[0]->setText("基本\n指令");
//        bt_fun_right[1]->setText("功能\n指令");
//        bt_fun_right[2]->setText("编辑\n指令");
//        bt_fun_right[3]->setText("向上\n查找");
//        bt_fun_right[4]->setText("向下\n查找");
//        bt_fun_right[5]->setText("首行");
//        bt_fun_right[6]->setText("名称\n注释");
//        bt_fun_right[7]->setText("");
//        bt_fun_right[0]->setStyleSheet(0);
//        bt_fun_right[1]->setStyleSheet(0);
//        bt_fun_right[2]->setStyleSheet(0);
//        bt_fun_right[3]->setStyleSheet(0);
//        bt_fun_right[4]->setStyleSheet(0);
//        bt_fun_right[5]->setStyleSheet(0);
//        bt_fun_right[6]->setStyleSheet(0);
//        bt_fun_right[7]->setStyleSheet(0);
//    }
//    switch (index)
//    {
//    case 0:
//    if(menu_lv==1)
//    {
//        bt_fun_right[0]->setText("");
//        bt_fun_right[1]->setText("");
//        bt_fun_right[2]->setText("");
//        bt_fun_right[3]->setText("");
//        bt_fun_right[4]->setText("");
//        bt_fun_right[5]->setText("");
//        bt_fun_right[6]->setText("");
//        bt_fun_right[7]->setText("");

//        if(cur_page==0)
//        {
//            bt_fun_right[0]->setText("▲");
//            bt_fun_right[1]->setStyleSheet("border-image:url(:/new/blue_pic/fun_rd.png);");
//            bt_fun_right[2]->setStyleSheet("border-image:url(:/new/blue_pic/fun_rdnot.png);");
//            bt_fun_right[3]->setStyleSheet("border-image:url(:/new/blue_pic/fun_wrt.png);");
//            bt_fun_right[4]->setStyleSheet("border-image:url(:/new/blue_pic/fun_wrtnot.png);");
//            bt_fun_right[5]->setStyleSheet("border-image:url(:/new/blue_pic/fun_horizon.png);");
//            bt_fun_right[6]->setStyleSheet("border-image:url(:/new/blue_pic/fun_downlink.png);");
//            bt_fun_right[7]->setText("▼");
//        }
//        else if(cur_page==1)
//        {
//            bt_fun_right[0]->setText("▲");
//            bt_fun_right[1]->setStyleSheet("border-image:url(:/new/blue_pic/fun_downlinknot.png);");
//            bt_fun_right[2]->setStyleSheet(0);
//            bt_fun_right[3]->setStyleSheet(0);
//            bt_fun_right[4]->setStyleSheet(0);
//            bt_fun_right[5]->setStyleSheet(0);
//            bt_fun_right[6]->setStyleSheet(0);
//            bt_fun_right[7]->setText("");
//        }
//    }
//    break;
//    case 1:

//    break;
//    case 2:
//        if(menu_lv==1)
//        {
//            if(cur_page==0)
//            {
//                bt_fun_right[0]->setText("▲");
//                bt_fun_right[1]->setText("插入行");
//                bt_fun_right[2]->setText("删除行");
//                bt_fun_right[3]->setText("保存");
//                bt_fun_right[4]->setText("注释");
//                bt_fun_right[5]->setText("子程序");
//                bt_fun_right[6]->setText("");
//                bt_fun_right[7]->setText("");
//            }
//        }
//    break;
//    case 3:

//    break;
//    case 4:

//    break;
//    case 5:

//    break;
//    case 6:

//    break;
//    case 7:

//    break;
//    default:
//        break;
//    }

//}

//void set_widget::basic_ins()
//{
//    menu_lv = 1;
//    menuRight_info_show_plcpic(0);
//}

//void set_widget::edit_ins()
//{
//    menu_lv = 1;
//    menuRight_info_show_plcpic(2);
//}
void set_widget::paintEvent(QPaintEvent *)
{
    QPainter painter( this);
    QPen pen;
}
