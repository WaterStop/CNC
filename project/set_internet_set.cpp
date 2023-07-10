#include "set_internet_set.h"
#include "ui_set_internet_set.h"

#if debug_on ==0
QString IP_File = "/home/root/hunhegongye/File/ip_add.csv";
#elif debug_on==1
QString IP_File = "E:\\QT\\program\\BLUE\\File\\ip_add.csv";
#endif
static QString str_IP,str_mask,str_bcast,str_mac;//ip地址，子网掩码，网关，Mac地址

set_internet_set::set_internet_set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_internet_set)
{
    ui->setupUi(this);
    this->setGeometry(0,0,691,614);
    ui->frame->setGeometry(0,0,691,614);
    Init();

}

set_internet_set::~set_internet_set()
{
    delete ui;
}

void set_internet_set::Init()
{
    label_set();
    edit_set();
    button_set();

    keyboard = new key_board_2(ui->frame);
    keyboard->setGeometry(315,455,561,240);
    keyboard->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);//设为弹窗
    keyboard->hide();

    Deal_slot();
    read_file();
    load_info();
    //set_info();
    //update_info();

}

void set_internet_set::label_set()
{
    int i,j;
    for (i =0;i<4;i++)
    {
        lab_title[i] = new QLabel(ui->frame);
        lab_title[i]->setFont(weiruanyahei4);
        lab_title[i]->setStyleSheet("color:white");
        lab_title[i]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        lab_title[i]->setWordWrap(true);//自动换行
        lab_title[i]->setGeometry(130,180+i*50,100,30);
    }
    for(j =0;j<9;j++)
    {
        lab_p[j] = new QLabel(ui->frame);
        lab_p[j]->setFont(weiruanyahei4);
        lab_p[j]->setStyleSheet("color:white");
        lab_p[j]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        lab_p[j]->setWordWrap(true);//自动换行
        lab_p[j]->setGeometry(250+(j%3)*70,180+(j/3)*50,10,30);
        //QString str = ".";
        lab_p[j]->setText(" .");
    }
    lab_title[0]->setText("IP地址");
    lab_title[1]->setText("子网掩码");
    lab_title[2]->setText("默认网关");
    lab_title[3]->setText("MAC地址");
}

void set_internet_set::edit_set()
{
    int i;
    for (i =0;i<12;i++)
    {
        edit[i] = new MyLineEdit(ui->frame);
        edit[i]->setFont(weiruanyahei4);
        edit[i]->setAlignment(Qt::AlignCenter);
        edit[i]->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    }
    for (i =0;i<12;i++)
    {
        edit[i]->setGeometry(190+(i%4)*70,180+(i/4)*50,60,30);
    }
    edit_mac = new MyLineEdit(ui->frame);
    edit_mac->setFont(weiruanyahei4);
    edit_mac->setAlignment(Qt::AlignCenter);
    edit_mac->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    edit_mac->setGeometry(190,330,270,30);
}

void set_internet_set::button_set()
{
    bt_set = new QPushButton(ui->frame);
    bt_set->setFont(weiruanyahei4);
    bt_set->setGeometry(250,450,100,30);
    bt_set->setText("保存");

}

void set_internet_set::Deal_slot()
{
    connect(keyboard,SIGNAL(enter_signal(QString)),this,SLOT(val_input_slot(QString)));
    connect(edit[0],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[1],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[2],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[3],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[4],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[5],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[6],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[7],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[8],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[9],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[10],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(edit[11],SIGNAL(clicked()),this,SLOT(keyboard_show_slot()));
    connect(bt_set,SIGNAL(clicked()),this,SLOT(save_slot()));

}

void set_internet_set::update_info()
{
    QString str;
    QStringList str_list;
    int i;
    str = getHostIpAddress();
    qDebug()<<"ip="<<str;
    str_list = str.split(".",QString::KeepEmptyParts);
    for (i= 0;i<4;i++)
    {
        edit[i]->setText(str_list.at(i));
    }
    str = getMAC();
    edit_mac->setText(str);
    get_info();

}

QString set_internet_set::getHostIpAddress()
{
    QString strIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // 获取第一个本主机的IPv4地址
    int nListSize = ipAddressesList.size();
    for (int i = 0; i < nListSize; ++i)
    {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               strIpAddress = ipAddressesList.at(i).toString();
               break;
           }
     }
     // 如果没有找到，则以本地IP地址为IP
     if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
     return strIpAddress;
}

QString set_internet_set::getMAC()
{
  QString myMAC;
  auto interfaces = QNetworkInterface::allInterfaces();
  for (int i = 0; i < interfaces.size(); i++)
   {
      if (interfaces.at(i).isValid())
      {
          myMAC= interfaces.at(i).hardwareAddress();
          break;
      }
  }
  return myMAC;
}

void set_internet_set::get_info()
{
//    QList<QNetworkInterface> listNetworkInterface =
//            QNetworkInterface::allInterfaces();

//        foreach (auto item, listNetworkInterface)
//        {
//            //qInfo() << tr("设备：") + item.name();
//            // MAC
//            qInfo() << tr("硬件地址：") + item.hardwareAddress();
//            edit[12]->setText(item.hardwareAddress());

//            foreach (auto item2, item.addressEntries())
//            {
//                qInfo() << "    " + tr("ip地址：") + item2.ip().toString();
//                qInfo() << "    " + tr("子网掩码：") + item2.netmask().toString();
//                qInfo() << "    " + tr("广播地址：") + item2.broadcast().toString();
//            }
//        }

        QList<QNetworkInterface> interfaceList = QNetworkInterface::allInterfaces();
        qDebug()<<"interfaceList.count="<<interfaceList.count();
            for (int i = 0; i < interfaceList.count(); i++)
            {
                QNetworkInterface interf = interfaceList.at(i);
                interf.humanReadableName(); //接口名称（网卡）
                QList<QNetworkAddressEntry> entryList = interf.addressEntries(); // 读取一个IP地址列表
                for(int j = 0; j < entryList.count(); j++)
                {
                    QNetworkAddressEntry entry = entryList.at(j);
                    QString ip = entry.ip().toString();                   //IP地址
                    QString mask = entry.netmask().toString();            //子网掩码
                    QString bcast = entry.broadcast().toString();         //广播地址
                    qDebug()<<"j"<<j<<ip<<mask<<bcast;
                }
            }
}

void set_internet_set::read_file()
{
    QStringList str_list;
    QFile file(IP_File);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        line = in.readAll();
        if(!line.isNull())//字符串有内容
        {
            str_list = line.split("\n",QString::KeepEmptyParts);
            line=in.readLine();//循环读取下行
        }
        str_IP = str_list.at(0);
        str_mask = str_list.at(1);
        str_bcast = str_list.at(2);
    }
    else
    {
        str_IP = "192.168.0.0";
        str_mask = "255.255.0.0";
        str_bcast = "192.168.0.10";
        set_info();
    }

    file.close();
}

void set_internet_set::load_info()
{
    int i;
    QString str;
    for (i=0;i<4;i++)
    {
        edit[i]->setText(str_IP.split(".",QString::KeepEmptyParts).at(i));
        edit[i+4]->setText(str_mask.split(".",QString::KeepEmptyParts).at(i));
        edit[i+8]->setText(str_bcast.split(".",QString::KeepEmptyParts).at(i));
    }
    //str = getMAC();
    str = macAddress("eth0");
    qDebug()<<"str="<<str;
    edit_mac->setText(str);
}

void set_internet_set::set_info()
{
    QString str,str2;
    str = QString("ifconfig eth0 %1 netmask %2").arg(str_IP).arg(str_mask);
    str2 = QString("route add default gw %1").arg(str_bcast);
    system(str.toLatin1().data());
    system(str2.toLatin1().data());
    //ifconfig eth0 192.168.6.8 netmask 255.255.255.0

    QFile file(IP_File);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out<<str_IP<<"\n"<<str_mask<<"\n"<<str_bcast;
    }
    file.close();
    system("sync");

}

QString set_internet_set::macAddress(QString network)
{
    QList<QNetworkInterface> netList;
    int netCount;
    int neti;
    QNetworkInterface myNet;
    netList = QNetworkInterface::allInterfaces();
    netCount = netList.count();

    for (neti = 0; neti < netCount; neti ++)
    {
        if (netList.at(neti).isValid() && netList.at(neti).name() == network)
        {
            myNet = netList.at(neti);
            break;
        }
    }
    return (myNet.hardwareAddress());
}

void set_internet_set::keyboard_show_slot()
{
    keyboard->show();
    keyboard->focus_init();
}

void set_internet_set::val_input_slot(QString str)
{
    bool ok;
    str.toInt(&ok);//判断是否为纯数字
    if(ok==0)
    {
        keyboard->hide();
        return;
    }

    if(edit[0]->hasFocus()==1)//
    {
        edit[0]->setText(str);
    }
    if(edit[1]->hasFocus()==1)//
    {
        edit[1]->setText(str);
    }
    if(edit[2]->hasFocus()==1)//
    {
        edit[2]->setText(str);
    }
    if(edit[3]->hasFocus()==1)//
    {
        edit[3]->setText(str);
    }
    if(edit[4]->hasFocus()==1)//
    {
        edit[4]->setText(str);
    }
    if(edit[5]->hasFocus()==1)//
    {
        edit[5]->setText(str);
    }
    if(edit[6]->hasFocus()==1)//
    {
        edit[6]->setText(str);
    }
    if(edit[7]->hasFocus()==1)//
    {
        edit[7]->setText(str);
    }
    if(edit[8]->hasFocus()==1)//
    {
        edit[8]->setText(str);
    }
    if(edit[9]->hasFocus()==1)//
    {
        edit[9]->setText(str);
    }
    if(edit[10]->hasFocus()==1)//
    {
        edit[10]->setText(str);
    }
    if(edit[11]->hasFocus()==1)//
    {
        edit[11]->setText(str);
    }

    keyboard->hide();
}

void set_internet_set::save_slot()
{
    str_IP = QString("%1.%2.%3.%4").arg(edit[0]->text()).arg(edit[1]->text()).arg(edit[2]->text()).arg(edit[3]->text());
    str_mask = QString("%1.%2.%3.%4").arg(edit[4]->text()).arg(edit[5]->text()).arg(edit[6]->text()).arg(edit[7]->text());
    str_bcast = QString("%1.%2.%3.%4").arg(edit[8]->text()).arg(edit[9]->text()).arg(edit[10]->text()).arg(edit[11]->text());
    set_info();
}

void set_internet_set::Timer_on_slot()
{

}
