#include "set_over_limit_set.h"
#include "ui_set_over_limit_set.h"

static bool has_protect = 0;//是否进行过期保护 0否  1是

static QStringList list_time;
#if debug_on ==0
QString lim_Fil = "/home/root/hunhegongye/File/lim_time.csv";
#elif debug_on==1
QString lim_Fil = "E:\\QT\\program\\BLUE\\File\\lim_time.csv";
#endif

set_over_limit_set::set_over_limit_set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_over_limit_set)
{
    ui->setupUi(this);
    Init();
}

set_over_limit_set::~set_over_limit_set()
{
    delete ui;
}


void set_over_limit_set::Init()
{
    int i;

    label_set();
    edit_set();
    button_set();



    keyboard = new key_board_2(ui->frame);
    keyboard->setGeometry(315,455,561,240);
    keyboard->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);//设为弹窗
    keyboard->hide();


    Deal_slot();
}

void set_over_limit_set::label_set()
{
    int i;
    QFont font("Microsoft YaHei", 8, 75, false);
    for (i=0;i<9;i++)
    {
        lab[i] = new QLabel(ui->frame);
        lab[i]->setFont(weiruanyahei4);
        lab[i]->setStyleSheet("color:white");
        lab[i]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        lab[i]->setWordWrap(true);//自动换行
    }
    lab[0]->setText("客户编码");
    lab[0]->setGeometry(20,80,100,30);
    lab[1]->setText("停机时间");
    lab[1]->setGeometry(20,150,100,30);
    lab[2]->setText("报警时间");
    lab[2]->setGeometry(20,220,100,30);
    lab[3]->setText("/天");
    lab[3]->setGeometry(200,150,100,30);
    lab[4]->setText("/天");
    lab[4]->setGeometry(200,220,100,30);
    lab[5]->setGeometry(20,300,250,60);
    lab[6]->setText("提示");
    lab[6]->setFont(font);
    lab[6]->setGeometry(300,40,100,60);
    lab[7]->setText("1.设置停机时间后，系统时间的设置将受到限制，所以请先校准时间。如果你确认时间是准确的，请继续。\n2.客户编码是解除限时保护的唯一凭证，请妥善保管，严防泄露、丢失。\n3.如果不需要报警时间，请设置报警时间与停机时间相同");
    lab[7]->setGeometry(300,40,320,300);
    lab[8]->setGeometry(300,300,320,50);
    if(limit_lev>2)
    {
        lab[8]->setText("权限不足,无法进行限时保护设置,请使用2级或2级以上权限。");
    }

    lab_end_time = new QLabel(ui->frame);
    lab_end_time->setFont(weiruanyahei4);
    lab_end_time->setStyleSheet("color:white");
    lab_end_time->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    lab_end_time->setWordWrap(true);//自动换行
    lab_end_time->setGeometry(20,400,250,50);


}

void set_over_limit_set::edit_set()
{
    int i;

    ui->edit_0->setFont(weiruanyahei4);
    ui->edit_0->setAlignment(Qt::AlignCenter);
    ui->edit_0->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");

    ui->edit_1->setFont(weiruanyahei4);
    ui->edit_1->setAlignment(Qt::AlignCenter);
    ui->edit_1->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");

    ui->edit_2->setFont(weiruanyahei4);
    ui->edit_2->setAlignment(Qt::AlignCenter);
    ui->edit_2->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");

    ui->edit_0->setGeometry(80,80,150,30);
    ui->edit_1->setGeometry(80,150,100,30);
    ui->edit_2->setGeometry(80,220,100,30);
}

void set_over_limit_set::button_set()
{
    bt_save = new QPushButton(ui->frame);
    bt_save->setStyleSheet("color:black;");
    bt_save->setFont(weiruanyahei4);
    bt_save->setGeometry(400,500,60,30);
    bt_save->setText("保存");

}

void set_over_limit_set::Deal_slot()
{
    connect(keyboard,SIGNAL(enter_signal(QString)),this,SLOT(val_input_slot(QString)));
    connect(ui->edit_0,SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(ui->edit_1,SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(ui->edit_2,SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(bt_save,SIGNAL(clicked()),this,SLOT(set_LimTime_slot()));
}


void set_over_limit_set::set_LimTime()
{
    QDateTime timeT = QDateTime::currentDateTime();   //获取当前时间
    uint secondsT = timeT.toTime_t();//返回当前自1970-01-01 00:00:00经过了多少秒

    QFile file(lim_Fil);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        protect_flg =1;
        has_set_protect = 0;
        out<<QString::number(secondsT)<<"\n"<<QString::number(limittime)<<"\n"<<QString::number(alarmtime)<<"\n"<<User_Name<<"\n"<<protect_flg;

    }
    file.close();
    system("sync");

}

void set_over_limit_set::Timer_on_slot()
{
    QString str;
    QDateTime timeT = QDateTime::currentDateTime();   //获取当前时间
    uint secondsT = timeT.toTime_t();

    if(protect_flg==0)
    {
        lab[5]->setText("此设备未进行限时保护设置");
        lab_end_time->setText("");
    }
    else
    {
        lab[5]->setText("此设备已进行过限时保护设置，无法重复设置限时保护");
        str = QString("截止日期为:%1\n还剩余%2小时").arg(QDateTime::fromTime_t(Remainingtime).toString("yyyy-MM-dd hh:mm:ss")).arg((Remainingtime-secondsT)/3600);
        lab_end_time->setText(str);
    }
    if(limit_lev>2)
    {
        lab[8]->setText("权限不足,无法进行限时保护设置,请使用2级或2级以上权限。");
    }
    else
    {
        lab[8]->setText("");
    }
}

void set_over_limit_set::keyboard_show_slot()
{
    if(limit_lev>2)
    {
        return;
    }
    keyboard->show();
    keyboard->focus_init();
}

void set_over_limit_set::val_input_slot(QString str)
{
    bool ok;
    str.toInt(&ok);//判断是否为纯数字

    if(ui->edit_0->hasFocus()==1)
    {
        if(str.length()!=6)
        {
            return;
        }
        User_Name = str;
        ui->edit_0->setText(str);
    }
    if(ui->edit_1->hasFocus()==1)
    {
        if(ok==0)
        {
            return;
        }
        limittime = str.toInt()*24;
        ui->edit_1->setText(str);
    }
    if(ui->edit_2->hasFocus()==1)
    {
        if(ok==0)
        {
            return;
        }
        alarmtime = str.toInt();
        ui->edit_2->setText(str);
    }
    keyboard->hide();
}

void set_over_limit_set::set_LimTime_slot()
{
    set_LimTime();
}
