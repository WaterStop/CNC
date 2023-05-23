#include "popupwin.h"
#include "ui_popupwin.h"

static int work_path = 0;

PopupWin::PopupWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupWin)
{
    ui->setupUi(this);
    set_popupwin_background();
    set_popupwin_button();
    connect(ui->pop_bt_5,SIGNAL(clicked()),this,SLOT(show_popwin_slot()));
    connect(ui->pop_bt,SIGNAL(clicked()),this,SLOT(set_workpath_slot()));
    connect(ui->pop_bt_1,SIGNAL(clicked()),this,SLOT(set_workpath_slot1()));
    connect(ui->pop_bt_2,SIGNAL(clicked()),this,SLOT(set_workpath_slot2()));
    connect(ui->pop_bt_3,SIGNAL(clicked()),this,SLOT(set_workpath_slot3()));
    connect(ui->pop_bt_4,SIGNAL(clicked()),this,SLOT(set_workpath_slot4()));
}

PopupWin::~PopupWin()
{
    delete ui;
}

void PopupWin::set_popupwin_background()
{
    setAutoFillBackground(true);//做子窗口要设置，否则不显示
    QPalette pal =this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap("../BLUE/blue_pic/PopupWin_1.png")));
    setPalette(pal);
}

void PopupWin::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load("../BLUE/blue_pic/PopupWin_1.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);

    //set_wg2_button();
}

void PopupWin::set_popupwin_button()
{

    ui->pop_bt_5->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt5.png);}");
    set_workpath();

    if(scr_size==0)
    {
        ui->pop_bt->setGeometry(1,7,39,39);
        ui->pop_bt_1->setGeometry(1,54,39,39);
        ui->pop_bt_2->setGeometry(1,101,39,39);
        ui->pop_bt_3->setGeometry(1,148,39,39);
        ui->pop_bt_4->setGeometry(1,195,39,39);
        ui->pop_bt_5->setGeometry(46,78,25,57);
    }
    else if(scr_size==1)
    {
        ui->pop_bt->setGeometry(2,10,50,50);
        ui->pop_bt_1->setGeometry(2,70,50,50);
        ui->pop_bt_2->setGeometry(2,130,50,50);
        ui->pop_bt_3->setGeometry(2,190,50,50);
        ui->pop_bt_4->setGeometry(2,250,50,50);
        ui->pop_bt_5->setGeometry(60,100,32,73);
    }
}

void PopupWin::set_workpath()
{
    ui->pop_bt->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt_off.png);}");
    ui->pop_bt_1->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt1_off.png);}");
    ui->pop_bt_2->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt2_off.png);}");
    ui->pop_bt_3->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt3_off.png);}");
    ui->pop_bt_4->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt4_off.png);}");

    switch (work_path)
    {
        case 0:
        ui->pop_bt->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt_on.png);}");
        break;
        case 1:
        ui->pop_bt_1->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt1_on.png);}");
        break;
        case 2:
        ui->pop_bt_2->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt2_on.png);}");
        break;
        case 3:
        ui->pop_bt_3->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt3_on.png);}");
        break;
        case 4:
        ui->pop_bt_4->setStyleSheet("QPushButton{border-image:url(../BLUE/blue_pic/pop_l_bt4_on.png);}");
        break;
        default:
        break;
    }
}

void PopupWin::show_popwin_slot()
{
    this->hide();
    //Widget2->show_wg2_popwin();
    popupwin_flg =0;
    //update();
}

void PopupWin::set_workpath_slot()
{
    work_path = 0;
    set_workpath();
}

void PopupWin::set_workpath_slot1()
{
    work_path = 1;
    set_workpath();
}

void PopupWin::set_workpath_slot2()
{
    work_path = 2;
    set_workpath();
}

void PopupWin::set_workpath_slot3()
{
    work_path = 3;
    set_workpath();
}

void PopupWin::set_workpath_slot4()
{
    work_path = 4;
    set_workpath();
}
