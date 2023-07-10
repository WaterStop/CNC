#include "set_limit_and_time.h"
#include "ui_set_limit_and_time.h"

static QString limit_key;//权限密码
static bool para_swt = 0;//参数开关
static bool time_set_flg = 1;//用于刷新时间 为1刷新
static QString month[12] = {"一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
static QString week[7] = {"一","二","三","四","五","六","七"};
QStringList key_list;//密码列表
#if debug_on ==0
QString keyFile = "/home/root/hunhegongye/File/keboard.csv";
#elif debug_on==1
QString keyFile = "E:\\QT\\program\\BLUE\\File\\keboard.csv";
#endif

set_limit_and_time::set_limit_and_time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_limit_and_time)
{
    ui->setupUi(this);
    Init();
}

set_limit_and_time::~set_limit_and_time()
{
    delete ui;
}

void set_limit_and_time::set_background()
{

}

void set_limit_and_time::Init()
{
    int i,j;
    QString str;
    read_file();
    label_set();
    edit_set();
    button_set();

    keyboard = new key_board_2(ui->frame);
    keyboard->setGeometry(315,455,561,240);
    keyboard->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);//设为弹窗
    keyboard->hide();

    Deal_slot();
}

void set_limit_and_time::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    //image.load(":/new/blue_pic/set_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void set_limit_and_time::read_file()//读密码用，后续改铁电
{
    QStringList str_list;
    QFile file(keyFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        line = in.readAll();
        if(!line.isNull())//字符串有内容
        {
            key_list = line.split("\n",QString::KeepEmptyParts);
        }
    }

    file.close();
}

void set_limit_and_time::label_set()
{
    int i;
    QString str;

    for (i=0;i<4;i++)
    {
        lab_title[i] = new QLabel(ui->frame);
        lab_title[i]->setFont(weiruanyahei4);
        lab_title[i]->setStyleSheet("color:white");
        lab_title[i]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        lab_title[i]->setGeometry(30+(i%3)*200,30+(i/3)*40,100,30);
    }
    lab_title[0]->setText("权限等级:");
    lab_title[1]->setText("输入密码:");
    lab_title[2]->setText("修改密码:");
    lab_title[3]->setText("参数开关:");

    for (i=0;i<6;i++)
    {
        lab_time[i] = new QLabel(ui->frame);
        lab_time[i]->setFont(weiruanyahei4);
        lab_time[i]->setStyleSheet("color:white");
        lab_time[i]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        lab_time[i]->setGeometry(150+(i%3)*140,500+(i/3)*40,100,30);
    }
    lab_time[0]->setText("年");
    lab_time[1]->setText("月");
    lab_time[2]->setText("日");
    lab_time[3]->setText("时");
    lab_time[4]->setText("分");
    lab_time[5]->setText("秒");

    for (i=0;i<10;i++)
    {
        lab_calendar_title[i] = new QLabel(ui->frame);
        lab_calendar_title[i]->setFont(weiruanyahei4);
        lab_calendar_title[i]->setStyleSheet("background-color:rgb(51, 144, 255);color:white");
        lab_calendar_title[i]->setAlignment(Qt::AlignCenter);
    }
    lab_calendar_title[0]->setGeometry(80,130,200,30);
    lab_calendar_title[1]->setGeometry(285,130,200,30);
    //lab_calendar_title[2]->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
    //lab_calendar_title[2]->setText("七  一  二  三  四  五  六");
    lab_calendar_title[2]->setGeometry(80,165,405,30);
    for (i=3;i<10;i++)
    {
        lab_calendar_title[i]->setGeometry(80+((i-3)%7)*59,165,50,30);
        lab_calendar_title[i]->setText(week[i-3]);
    }

    for (i=0;i<42;i++)
    {
        lab_calendar[i] = new QLabel(ui->frame);
        lab_calendar[i]->setFont(weiruanyahei4);
        lab_calendar[i]->setStyleSheet("color:white");
        lab_calendar[i]->setAlignment(Qt::AlignCenter);
        lab_calendar[i]->setGeometry(80+(i%7)*59,200+(i/7)*30,50,30);
    }


}

void set_limit_and_time::edit_set()
{
    int i;

    for (i=0;i<3;i++)
    {
        edit_val[i] = new MyLineEdit(ui->frame);
        edit_val[i]->setFont(weiruanyahei4);
        edit_val[i]->setAlignment(Qt::AlignCenter);
        edit_val[i]->setGeometry(110+(i%3)*200,30+(i/3)*40,100,30);
        edit_val[i]->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    }

    edit_val[0]->setText(QString::number(limit_lev));

    for (i=0;i<6;i++)
    {
        edit_time[i] = new MyLineEdit(ui->frame);
        edit_time[i]->setFont(weiruanyahei4);
        edit_time[i]->setAlignment(Qt::AlignCenter);
        edit_time[i]->setGeometry(40+(i%3)*140,500+(i/3)*40,100,30);
        edit_time[i]->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    }

}

void set_limit_and_time::button_set()
{
    int i;

    bt_para_swt = new QPushButton(ui->frame);
    bt_para_swt->setFont(weiruanyahei4);
    bt_para_swt->setGeometry(110,70,100,30);
    bt_para_swt->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");

    dis_para_switch();

}

void set_limit_and_time::Deal_slot()
{
    //connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));
//    connect(bt_back,SIGNAL(clicked()),this,SLOT(back_slot()));
    connect(keyboard,SIGNAL(enter_signal(QString)),this,SLOT(val_input_slot(QString)));
    connect(edit_val[1],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit_val[2],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(bt_para_swt,SIGNAL(clicked()),this,SLOT(change_para_swt_slot()));
    connect(edit_time[0],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit_time[1],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit_time[2],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit_time[3],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit_time[4],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit_time[5],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
}


void set_limit_and_time::dis_para_switch()
{
    if(para_swt==0)
    {
        bt_para_swt->setText("关");
    }
    else
    {
        bt_para_swt->setText("开");
    }
}

void set_limit_and_time::set_time()//时间设置
{
    QString str;

    str = QString("date -s \"%1%2%3 %4:%5:%6\"").arg(cur_year,4,10, QLatin1Char('0')).arg(cur_mon,2,10, QLatin1Char('0')).arg(cur_day,2,10, QLatin1Char('0')).arg(cur_hour,2,10, QLatin1Char('0')).arg(cur_min,2,10, QLatin1Char('0')).arg(cur_sec,2,10, QLatin1Char('0'));
    system(str.toLatin1().data());
    //强制写入到CMOS
    system("hwclock -w");
    QDateTime datetime = QDateTime::currentDateTime();
    cur_year = datetime.date().year();             //年
    cur_mon = datetime.date().month();			   //月
    cur_day = datetime.date().day();				   //日
    cur_hour = datetime.time().hour();			   //时
    cur_min = datetime.time().minute();          //分
    cur_sec = datetime.time().second();          //秒
    cur_week = datetime.date().dayOfWeek();     //星期几
    time_set_flg = 1;

    qDebug()<<"time="<<cur_year<<cur_mon<<cur_day<<cur_week;
}

bool set_limit_and_time::change_lim_lev(QString str)//修改权限等级
{
    if(str.length()!=6)
    {
        return 0;
    }
    for (int i=0;i<key_list.count();i++)
    {
        if(str==key_list.at(i))
        {
            limit_lev = i+1;
            edit_val[0]->setText(QString::number(limit_lev));
            return 1;
        }
    }
    return 0;
}

bool set_limit_and_time::modify_key(QString str)//修改密码
{
    if(str.length()!=6)
    {
        return 0;
    }

    key_list.replace(limit_lev-1,str);
    QFile file(keyFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        for (int i=0;i<key_list.count();i++)
        {
            out<<key_list.at(i)<<"\n";
        }
    }
    file.close();
    system("sync");
    return 1;
}

void set_limit_and_time::Timer_on_slot()
{
    int i;
    QString str;
    QDateTime datetime = QDateTime::currentDateTime();
    str = QString("%1").arg(cur_year,4,10, QLatin1Char('0'));
    edit_time[0]->setText(str);
    str = QString("%1").arg(cur_mon,2,10, QLatin1Char('0'));
    edit_time[1]->setText(str);
    str = QString("%1").arg(cur_day,2,10, QLatin1Char('0'));
    edit_time[2]->setText(str);
    str = QString("%1").arg(cur_hour,2,10, QLatin1Char('0'));
    edit_time[3]->setText(str);
    str = QString("%1").arg(cur_min,2,10, QLatin1Char('0'));
    edit_time[4]->setText(str);
    str = QString("%1").arg(cur_sec,2,10, QLatin1Char('0'));
    edit_time[5]->setText(str);

    lab_calendar_title[0]->setText(month[cur_mon-1]);
    str = QString("%1年").arg(cur_year,4,10, QLatin1Char('0'));
    lab_calendar_title[1]->setText(str);

    if(time_set_flg==1)
    {
        //int a=qAbs(cur_week+7-((cur_day-1)%7));
        int a;
        if(cur_week-((cur_day-1)%7)<0)
        {
            a = 7+(cur_week-((cur_day-1)%7));
        }
        else if(cur_week-((cur_day-1)%7)>0)
        {
            a = (cur_week-((cur_day-1)%7));
        }
        qDebug()<<"a="<<a<<cur_day<<cur_week<<((cur_day-1)%7);
        for (i=0;i<42;i++)
        {
            lab_calendar[i]->setText("");
            lab_calendar[i]->setStyleSheet("background-color:transparent;color:white");
        }
        
        for (i=a-1;i<datetime.date().daysInMonth()+a-1;i++)
        {
            lab_calendar[i]->setText(QString::number(i-a+2));
            if(cur_day==(i-a+2))
            {
                lab_calendar[i]->setStyleSheet("background-color:rgb(51, 144, 255);color:white");
            }
        }
        time_set_flg = 0;
    }


}

void set_limit_and_time::change_para_swt_slot()
{
    para_swt = 1-para_swt;
    dis_para_switch();
}

void set_limit_and_time::keyboard_show_slot()
{
    keyboard->show();
    keyboard->focus_init();
}

void set_limit_and_time::val_input_slot(QString str)
{
    bool ok;
    str.toInt(&ok);//判断是否为纯数字
    if(ok==0)
    {
        keyboard->hide();
        return;
    }

    if(edit_val[1]->hasFocus()==1)//输入密码
    {
        if(change_lim_lev(str)==1)
        {
            edit_val[1]->setText("******");
        }
    }
    else if(edit_val[2]->hasFocus()==1)//修改密码
    {
        if(modify_key(str)==1)
        {
            edit_val[2]->setText("******");
        }
    }
    else if(edit_time[0]->hasFocus()==1)
    {
        cur_year = str.toInt();
        set_time();
    }
    else if(edit_time[1]->hasFocus()==1)
    {
        cur_mon = str.toInt();
        set_time();
    }
    else if(edit_time[2]->hasFocus()==1)
    {
        cur_day = str.toInt();
        set_time();
    }
    else if(edit_time[3]->hasFocus()==1)
    {
        cur_hour = str.toInt();
        set_time();
    }
    else if(edit_time[4]->hasFocus()==1)
    {
        cur_min = str.toInt();
        set_time();
    }
    else if(edit_time[5]->hasFocus()==1)
    {
        cur_sec = str.toInt();
        set_time();
    }


    keyboard->hide();

}


void set_limit_and_time::paintEvent(QPaintEvent *)
{

}
