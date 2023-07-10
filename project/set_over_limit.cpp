#include "set_over_limit.h"
#include "ui_set_over_limit.h"

static int radom;//随机数
int code_array[10][MAX_CODE_NUM] =  {{6,14,13,15,0,16,7,17,1,18,8,19,2,9,20,10,4,11,5,12,21,3},
                                     {13,12,7,1,5,3,0,8,14,4,19,2,16,18,11,17,20,21,10,9,15,6},
                                     {16,4,0,11,10,21,20,13,2,5,19,18,14,17,15,6,1,12,3,9,7,8},
                                     {17,15,6,16,8,2,12,5,11,21,14,9,7,18,19,3,13,4,0,10,1,20},
                                     {19,4,10,11,17,12,3,2,5,18,8,0,20,13,15,14,1,6,16,7,21,9},
                                     {7,16,2,15,14,6,8,1,21,17,18,13,11,20,10,0,19,12,5,9,4,3},
                                     {20,2,19,7,10,12,1,21,15,6,4,16,18,11,17,9,5,13,0,3,8,14},
                                     {2,9,0,12,4,1,13,7,16,20,18,21,11,19,3,8,14,10,15,5,6,17},
                                     {7,10,0,13,15,6,17,14,9,8,1,4,21,11,19,3,12,2,20,18,5,16},
                                     {6,15,18,7,11,13,5,17,10,9,12,2,16,14,4,0,1,8,20,21,3,19}};/*数组用于打乱明文注册码的顺序*/
const char* charArray = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int encode_array[MAX_CODE_NUM] = {18,3,1,0,12,11,14,5,13,15,16,8,20,4,2,21,19,6,7,9,10,17};
char ulock_code[10]={0};//限时保护检查码
char date_code[10]={0};//时间设置DDDHH,前3位表示天，后两位表示小时
char state_code[10]={0};//解锁状态，0：延时/ 1：永久
char getManufacturer[10]={0};//客户编码
#if debug_on ==0
QString lim_File = "/home/root/hunhegongye/File/lim_time.csv";
#elif debug_on==1
QString lim_File = "E:\\QT\\program\\BLUE\\File\\lim_time.csv";
#endif

set_over_limit::set_over_limit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_over_limit)
{
    ui->setupUi(this);
    Init();
}

set_over_limit::~set_over_limit()
{
    delete ui;
}

void set_over_limit::set_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/protect_bk.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}

void set_over_limit::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    image.load(":/new/blue_pic/protect_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void set_over_limit::Init()
{
    label_set();
    edit_set();
    button_set();
    creat_radom();

    keyboard = new key_board_2(ui->frame);
    keyboard->setGeometry(315,455,561,240);
    keyboard->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);//设为弹窗
    keyboard->hide();

    Deal_slot();
}

void set_over_limit::label_set()
{
    int i;
    for (i=0;i<5;i++)
    {
        lab[i] = new QLabel(ui->frame);
        lab[i]->setFont(weiruanyahei6);
        lab[i]->setStyleSheet("color:white");
        lab[i]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        lab[i]->setWordWrap(true);//自动换行
    }
    lab[0]->setText("检测码");
    lab[0]->setGeometry(150,100,100,30);
    lab[1]->setGeometry(250,100,100,30);
    lab[2]->setText("解锁密码");
    lab[2]->setGeometry(150,170,100,30);
    lab[3]->setText("提示:\n系统使用时间已经超过了设定的期限，当前处于停机状态。解除限制请联系经销商。输入经销商提供的密码后，按输入按键后即可解除停机，返回正常状态。");
    lab[3]->setGeometry(150,210,300,150);
    lab[4]->setGeometry(150,350,300,30);
}

void set_over_limit::edit_set()
{
    edit_val = new MyLineEdit(ui->frame);
    edit_val->setFont(weiruanyahei4);
    edit_val->setAlignment(Qt::AlignCenter);
    edit_val->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    edit_val->setGeometry(250,170,200,30);

}

void set_over_limit::button_set()
{

}

void set_over_limit::Deal_slot()
{
    connect(keyboard,SIGNAL(enter_signal(QString)),this,SLOT(val_input_slot(QString)));
    connect(edit_val,SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(tip_timer, SIGNAL(timeout()), this, SLOT(clear_tip_slot()));
}

void set_over_limit::creat_radom()//生成随机数
{
    radom=QRandomGenerator::global()->bounded(1000,9999);
    lab[1]->setText(QString::number(radom));
}

void set_over_limit::tip_set(QString str)
{
    lab[4]->setText(str);
    tip_timer->start(3000);
}

void set_over_limit::keyboard_show_slot()
{
    if(limit_lev>2)
    {
        return;
    }
    keyboard->show();
    keyboard->focus_init();
}

void set_over_limit::val_input_slot(QString str)
{
    int i;
    bool ok;
    QString tem;
    for (i=0;i<str.length();i++)
    {
        tem = str.at(i);
        tem.toInt(&ok);//判断是否为纯数字-
        if(ok==0)
        {
            qDebug()<<"不为纯数字";
            return;
        }
    }
    //str.toInt(&ok);//判断是否为纯数字-


    if(edit_val->hasFocus()==1)
    {
//        if(str.length()!=22)
//        {
//            tip_set("密码位数不正确");
//            keyboard->hide();
//            return;
//        }
        char*  ch;
        QByteArray ba = str.toLatin1(); // must
        ch=ba.data();
        if(limit_decode(ch)==1)
        {
            deal_time();
            edit_val->setText(str);
        }
        else if(limit_decode(ch)==-1)
        {
            tip_set("密码位数不对");
            keyboard->hide();
        }

    }
    keyboard->hide();
}

void set_over_limit::clear_tip_slot()
{
    lab[4]->setText("");
}

int set_over_limit::limit_decode(char *unlockCode)//解码函数
{
    QString str,tmp_str;
    char tmpStr[25];
    int sum = 0;
    char manufacturer_code[15]={0};//客户编码的中间变量
    sum =0;
    memset(tmpStr,0,sizeof(tmpStr));
    memcpy(tmpStr,unlockCode,strlen(unlockCode));
    if(strlen(tmpStr)!=22)
    //if(unlockCode.length()!=22)
    {
        return -1;
    }
    for(int i = 0;i<strlen(tmpStr);i++)
    //for(int i = 0;i <unlockCode.length();i++)
    {
        sum += (int)(unlockCode[i]);
//        str = unlockCode.at(i);
//        sum += str.toInt();
    }
    int index ;
    index = sum % 10;

    for(int i=0;i<MAX_CODE_NUM;i++)
    {
        for(int j=0;j<MAX_CODE_NUM;j++)
        {
            if(i == code_array[index][j])
            {
                tmpStr[i] = unlockCode[j];
                //tmpStr[i] = unlockCode.at(j).toLatin1();
                break;
            }else;
        }
    }

    memcpy(ulock_code,&tmpStr[0],4);
    ulock_code[4]=0;

    memcpy(manufacturer_code,&tmpStr[4],12);
    manufacturer_code[12]=0;

    memcpy(date_code,&tmpStr[16],5);
    date_code[5]=0;

    memcpy(state_code,&tmpStr[21],1);
    state_code[1]=0;

    for(int i=0;i<MAX_MANUFACTURER_LENGTH;i++)
    {
        int m_index;
        m_index = manufacturer_code[i*2+1]-'0' + (manufacturer_code[i*2]-'0')*10;

        getManufacturer[i] = charArray[m_index];
    }
    qDebug()<<"ulock_code="<<ulock_code<<"date_code"<<date_code<<"state_code="<<state_code<<"getManufacturer="<<getManufacturer;
    return 1;
}

void set_over_limit::deal_time()//处理延长时间
{
    QString str;
    int ex_day,ex_hour;
    uint end_sec;
    QDateTime timeT = QDateTime::currentDateTime();   //获取当前时间
    uint secondsT = timeT.toTime_t();//返回当前自1970-01-01 00:00:00经过了多少秒

    str = QString(QLatin1String(date_code));
    ex_day = str.toInt()/100;
    ex_hour = str.toInt()%100;
    end_sec = ex_day*24*60*60+ex_hour*60*60+secondsT;

    str = QString(QLatin1String(getManufacturer));
    if((User_Name==QString(QLatin1String(getManufacturer)))&&(radom==QString(QLatin1String(ulock_code)).toInt()))//客户编码和检测码都通过
    {
        QFile file(lim_File);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            limittime = ex_day*24+ex_hour;
            if(QString(QLatin1String(state_code)).toInt()==1)
            {
                protect_flg =0;
            }
            else
            {
                protect_flg =1;
            }
            has_set_protect = 0;
            out<<QString::number(secondsT)<<"\n"<<QString::number(limittime)<<"\n"<<QString::number(alarmtime)<<"\n"<<User_Name<<"\n"<<protect_flg;

        }
        file.close();
    }
    else if(User_Name!=QString(QLatin1String(getManufacturer)))
    {
        tip_set("客户编码不正确");
    }
    else if(radom!=QString(QLatin1String(ulock_code)).toInt())
    {
        tip_set("检测码不正确");
    }
}
