#include "set_dgn.h"
#include "ui_set_dgn.h"

#define MAXpage 2
static int cur_page =0;
static int first_line = 0;//首行行号
static int x_signal[48],y_signal[48];

set_dgn::set_dgn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_dgn)
{
    ui->setupUi(this);
    Init();
    set_background();
    Deal_slot();
    load_info();
    set_info();
}

set_dgn::~set_dgn()
{
    delete ui;
}

void set_dgn::set_background()
{

}

void set_dgn::Init()
{
    int i,j;
    QString str;
    button_set();
    table_init();
    for (i=0;i<48;i++)
    {
        label_Xsignal[i] = new QLabel(ui->frame);
        label_Ysignal[i] = new QLabel(ui->frame);
        label_Xtitle[i] = new QLabel(ui->frame);
        label_Ytitle[i] = new QLabel(ui->frame);
        label_Xsignal[i]->setFont(weiruanyahei4);
        label_Ysignal[i]->setFont(weiruanyahei4);
        label_Xtitle[i]->setFont(weiruanyahei4);
        label_Ytitle[i]->setFont(weiruanyahei4);
        //label_Xsignal[i]->setStyleSheet("color:white");
        //label_Xsignal[i]->setStyleSheet("color:white");
        label_Xtitle[i]->setStyleSheet("color:white");
        label_Ytitle[i]->setStyleSheet("color:white");

        label_Xtitle[i]->setGeometry(20+(i%8)*70,20+(i/8)*30,95,20);
        label_Ytitle[i]->setGeometry(20+(i%8)*70,210+(i/8)*30,95,20);
        label_Xsignal[i]->setGeometry(60+(i%8)*70,20+(i/8)*30,20,20);
        label_Ysignal[i]->setGeometry(60+(i%8)*70,210+(i/8)*30,20,20);
        label_Xsignal[i]->hide();
        label_Ysignal[i]->hide();
    }
    lab_mdi = new QLabel(ui->frame);
    lab_mdi->setFont(weiruanyahei4);
    lab_mdi->setStyleSheet("color:white");
    lab_mdi->setGeometry(60,505,60,20);
    lab_mdi->setText("MDI");

    lab_G98G99 = new QLabel(ui->frame);
    lab_G98G99->setFont(weiruanyahei4);
    lab_G98G99->setStyleSheet("color:white");
    lab_G98G99->setGeometry(80,450,50,30);

    edit_mdi = new MyLineEdit(ui->frame);
    edit_mdi->setFont(weiruanyahei6);
    edit_mdi->setStyleSheet("background:transparent;color:white;border:2px solid #D8D8D8;");
    edit_mdi->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    edit_mdi->setGeometry(120,500,400,30);

    keyboard = new key_board_2(ui->frame);
    keyboard->setGeometry(315,455,561,240);
    keyboard->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);//设为弹窗
    keyboard->hide();

    set_table_info();

}

void set_dgn::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    //image.load(":/new/blue_pic/set_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void set_dgn::button_set()
{
    int i;
//    for (i=0;i<8;i++)
//    {
//        bt_fun[i] = new QPushButton(this);
//        bt_fun[i]->setGeometry(30+i*70,460,40,40);
//        bt_fun_right[i] = new QPushButton(this);
//        bt_fun_right[i]->setGeometry(630,20+i*55,40,40);
//    }
    bt_back = new QPushButton(this);
    bt_back->setFont(weiruanyahei4);
    bt_back->setGeometry(550,440,50,30);
    bt_back->setText("返回");
    bt_back->hide();
    bt_up = new QPushButton(this);
    bt_up->setFont(weiruanyahei4);
    bt_up->setGeometry(630,420,50,30);
    bt_up->setText("上页");
    bt_down = new QPushButton(this);
    bt_down->setFont(weiruanyahei4);
    bt_down->setGeometry(630,460,50,30);
    bt_down->setText("下页");

    for (i=0;i<2;i++)
    {
        bt_page[i] = new QPushButton(ui->frame);
        bt_page[i]->setFont(weiruanyahei4);
        bt_page[i]->setStyleSheet("color:black");
        bt_page[i]->setGeometry(630,50+i*50,50,30);
    }
    bt_page[0]->setText("上一页");
    bt_page[1]->setText("下一页");

    bt_G98G99 = new QPushButton(ui->frame);
    bt_G98G99->setFont(weiruanyahei4);
    bt_G98G99->setStyleSheet("color:black");
    bt_G98G99->setGeometry(60,410,70,30);

    if(gui_ctl->request_g99==0)
    {
        bt_G98G99->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }
    else if(gui_ctl->request_g99==1)
    {
        bt_G98G99->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");
    }


    //bt_back->setStyleSheet("color: rgb(255, 255, 255);");

}

void set_dgn::Deal_slot()
{
    //connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));
    connect(bt_back,SIGNAL(clicked()),this,SLOT(back_slot()));
    connect(bt_up,SIGNAL(clicked()),this,SLOT(uppage_slot()));
    connect(bt_down,SIGNAL(clicked()),this,SLOT(downpage_slot()));
    connect(bt_page[0],SIGNAL(pressed()),this,SLOT(uppage_slot1()));
    connect(bt_page[1],SIGNAL(pressed()),this,SLOT(downpage_slot1()));
    connect(edit_mdi,SIGNAL(clicked()),this,SLOT(keyboard_show()));
    connect(keyboard,SIGNAL(enter_signal(QString)),this,SLOT(val_input_slot(QString)));
    connect(bt_G98G99,SIGNAL(pressed()),this,SLOT(change_g98g99()));
}

void set_dgn::load_info()
{
    int i,j,k;
    for (i=0;i<32;i++)
    {
        label_in[i] = new QLabel(ui->frame);
        label_out[i] = new QLabel(this);
        label_in[i]->setGeometry(20+(i/7)*110,20+(i%7)*20,95,20);
        label_out[i]->setGeometry(20+(i/7)*110,190+(i%7)*20,95,20);
        label_in[i]->setFont(weiruanyahei4);
        label_out[i]->setFont(weiruanyahei4);
        label_in[i]->setStyleSheet("color: rgb(255, 255, 255);");
        label_out[i]->setStyleSheet("color: rgb(255, 255, 255);");
        label_in[i]->hide();
        label_out[i]->hide();
    }
    for (j=0;j<5;j++)
    {
        label_handwheel[j] = new QLabel(ui->frame);
        label_handwheel[j]->setFont(weiruanyahei4);
        label_handwheel[j]->setGeometry(20,390+j*20,250,20);
        label_handwheel[j]->setStyleSheet("color: rgb(255, 255, 255);");
    }
    for (k=0;k<400;k++)
    {
        label_tem[k] = new QLabel(ui->frame);
        label_tem[k]->setFont(weiruanyahei4);
        label_tem[k]->setAlignment(Qt::AlignJustify);
        label_tem[k]->setStyleSheet("color: rgb(255, 255, 255);");
        label_tem[k]->hide();
    }
    temp_dgn_load();
//    label_handwheel[0] = new QLabel(this);
//    label_handwheel[1] = new QLabel(this);
//    label_handwheel[0]->setFont(weiruanyahei4);
//    label_handwheel[1]->setFont(weiruanyahei4);
//    label_handwheel[0]->setGeometry(20,370,95,20);
//    label_handwheel[1]->setGeometry(20,390,95,20);
//    label_handwheel[0]->setStyleSheet("color: rgb(255, 255, 255);");
//    label_handwheel[1]->setStyleSheet("color: rgb(255, 255, 255);");
}

void set_dgn::table_init()
{
    int i;
    QStringList header;
    table_info = new QTableWidget(ui->frame);
    table_info->horizontalHeader()->setFont(weiruanyahei4);
    table_info->setFont(weiruanyahei4);
    table_info->setGeometry(60,20,561,581);
    table_info->setFocusPolicy(Qt::NoFocus);
    QHeaderView* headerView = table_info->verticalHeader();//去掉初始序列号
    headerView->setHidden(true);
    table_info->setHorizontalHeaderLabels(QStringList() <<"序号"<<"注释"<<"数据");
    table_info->horizontalHeader()->setStretchLastSection(true);//使行列头自适应宽度，最后一列将会填充空白部分
    table_info->setAttribute(Qt::WA_TranslucentBackground, true);
    table_info->setStyleSheet("selection-color:black;selection-background-color:lightblue;"
                         "background-color:rgb(3,14,54);color:rgb(255,255,255);gridline-color:rgb(216, 216,216);"
                         "QTableWidget::item{border:2px solid #D8D8D8;}");
    table_info->horizontalHeader()->setStyleSheet("QHeaderView::section{"
                                                  "border-top:0px solid #D8D8D8;border-left:0px solid #D8D8D8;"
                                                  "border-right:2px solid #D8D8D8;border-bottom: 0.5px solid #D8D8D8;"
                                                  "background-color:rgb(21,96,192);color:rgb(255,255,255);padding:4px;height:30px;}" );//设置表头样式

    table_info->horizontalHeader()->setMinimumHeight(30);

    table_info->setColumnCount(3);
    table_info->setColumnWidth(0, 60);
    table_info->setColumnWidth(1, 270);
    table_info->setColumnWidth(2, 170);
    table_info->setRowCount(Row_NUM);//设置行数
    table_info->setHorizontalHeaderLabels(QStringList() <<"序号"<<"描述"<<"值");
    table_info->setSelectionBehavior(QAbstractItemView::SelectRows);
    table_info->setSelectionMode(QAbstractItemView::SingleSelection);
    table_info->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    table_info->setFocusPolicy(Qt::NoFocus);
    table_info->setFrameShape(QFrame::NoFrame);
    for (i=0;i<Row_NUM;i++)
    {
        table_info->setRowHeight(i,25);
    }
//    for(i = 0;i <Row_NUM;i++)
//    {
//        table_info->setItem(i,0,new QTableWidgetItem(""));
//        table_info->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
//        table_info->setItem(i,1,new QTableWidgetItem(""));
//        table_info->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
//        table_info->setItem(i,2,new QTableWidgetItem(""));
//        table_info->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
//    }

}

void set_dgn::temp_dgn_load()
{
    int i,j,k;

    for (i=0;i<400;i++)
    {
        label_tem[i]->hide();
    }
    table_info->hide();

    if(cur_page==1)
    {
//        for (j=0;j<100;j++)
//        {
//            label_tem[j]->setGeometry(20+(j/20)*130,20+(j%20)*20,120,20);
//            label_tem[j]->show();
//        }
//        for (j=0;j<40;j++)
//        {
//            label_tem[j]->setGeometry(20+((j)/20)*330,20+((j)%20)*20,300,20);
//            label_tem[j]->show();
//        }
        table_info->show();
    }
    else if(cur_page==2)
    {
//        for (j=100;j<200;j++)
//        {
//            label_tem[j]->setGeometry(20+((j-100)/20)*130,20+((j-100)%20)*20,120,20);
//            label_tem[j]->show();
//        }
        for (j=40;j<80;j++)
        {
            label_tem[j]->setGeometry(20+((j-40)/20)*300,20+((j-40)%20)*20,300,20);
            label_tem[j]->show();
        }
    }
    else if(cur_page==3)
    {
//        for (j=200;j<300;j++)
//        {
//            label_tem[j]->setGeometry(20+((j-200)/20)*130,40+((j-200)%20)*20,250,40);
//            label_tem[j]->show();
//        }
        for (j=80;j<100;j++)
        {
            label_tem[j]->setGeometry(20+((j-80)/20)*300,40+((j-80)%20)*20,250,40);
            label_tem[j]->show();
        }
    }
//    else if(cur_page==4)
//    {
//        for (j=300;j<400;j++)
//        {
//            label_tem[j]->setGeometry(20+((j-300)/20)*130,40+((j-300)%20)*20,250,40);
//            label_tem[j]->show();
//        }
//    }
}

void set_dgn::set_info()
{
    int i,j,k;
    int x[48],y[48];
    static int last_x[48],last_y[48];
    QString str,str1;

    for (i=0;i<32;i++)
    {
        label_in[i]->hide();
        label_out[i]->hide();
    }
    for (i=0;i<48;i++)
    {
        label_Xsignal[i]->hide();
        label_Ysignal[i]->hide();
        label_Xtitle[i]->hide();
        label_Ytitle[i]->hide();
    }
    bt_page[0]->hide();
    bt_page[1]->hide();
    bt_G98G99->hide();
    lab_G98G99->hide();
    lab_mdi->hide();
    edit_mdi->hide();
    if(cur_page==0)//第一页
    {
        for (i=0;i<32;i++)
        {
            str = QString("X%1 %2").arg(i).arg(plc_shm->xl[i]);
            label_in[i]->setText(str);
            str = QString("Y%1 %2").arg(i).arg(plc_shm->y[i]);
            label_out[i]->setText(str);
            label_in[i]->hide();
            label_out[i]->hide();
        }
        for (i=0;i<48;i++)
        {
            label_Xsignal[i]->show();
            label_Ysignal[i]->show();
            label_Xtitle[i]->show();
            label_Ytitle[i]->show();
            str = QString("%1 %2.%3").arg("X").arg(i/8).arg(i%8);
            label_Xtitle[i]->setText(str);
            str = QString("%1 %2.%3").arg("Y").arg(i/8).arg(i%8);
            label_Ytitle[i]->setText(str);
        }
        bt_G98G99->show();
        lab_G98G99->show();
        lab_mdi->show();
        edit_mdi->show();
        for (i=0;i<6;i++)
        {
            str = plc_shm->xl[i];
            str1 = plc_shm->y[i];
            for (j=0;j<8;j++)
            {                
                //str = "10";
                //str1="6";
                if(((str.toInt()&(1<<j))>>j)==1)
                {
                    x_signal[i*8+j]=1;
                    //label_Xsignal[i*8+j]->setStyleSheet("background-color:green;");
                }
                else
                {
                    x_signal[i*8+j] = 0;
                    //label_Xsignal[i*8+j]->setStyleSheet("background-color:rgb(194,222,239);");
                }

                if(((str1.toInt()&(1<<j))>>j)==1)
                {
                    y_signal[i*8+j] = 1;
                    //label_Ysignal[i*8+j]->setStyleSheet("background-color:green;");
                }
                else
                {
                    y_signal[i*8+j] = 0;
                    //label_Ysignal[i*8+j]->setStyleSheet("background-color:rgb(194,222,239);");
                }
            }
        }
//        for (i=0;i<48;i++)
//        {
//            if(last_x[i]!=x[i])
//            {
//                if(x[i]==1)
//                {
//                    label_Xsignal[i]->setStyleSheet("background-color:green;");
//                }
//                else
//                {
//                    label_Xsignal[i]->setStyleSheet("background-color:rgb(194,222,239);");
//                }
//            }
//            if(last_y[i]!=y[i])
//            {
//                if(y[i]==1)
//                {
//                    label_Ysignal[i]->setStyleSheet("background-color:green;");
//                }
//                else
//                {
//                    label_Ysignal[i]->setStyleSheet("background-color:rgb(194,222,239);");
//                }
//            }
//        }


        str = QString("MPG手轮:local_data[68]  %1 ").arg(motion_status->local_data[68]);
        label_handwheel[0]->setText(str);
        str = QString("操作站手轮:local_data[66]  %1 ").arg(motion_status->local_data[66]);
        label_handwheel[1]->setText(str);
        str = QString("附加面板手轮:local_data[70]  %1 ").arg(motion_status->local_data[70]);
        label_handwheel[2]->setText(str);
        str = QString("编码器1：local_data[50]  %1 ").arg(motion_status->local_data[50]);
        label_handwheel[3]->setText(str);
        str = QString("编码器2：local_data[51]  %1 ").arg(motion_status->local_data[51]);
        label_handwheel[4]->setText(str);
        label_handwheel[0]->hide();
        label_handwheel[1]->hide();
        label_handwheel[2]->hide();
        label_handwheel[3]->hide();
        label_handwheel[4]->hide();
    }
    else if(cur_page==1)//第2页
    {
//        for (j=0;j<100;j++)
//        {
//            str = QString("%1 %2").arg(motion_status->temp_char[j]).arg(motion_status->temp_int[j], 5, 10, QLatin1Char('0'));
//            label_tem[j]->setText(str);
//        }
        for (j=0;j<40;j++)
        {
            str = QString("%1 %2").arg(gui_ctl->temp_char[j]).arg(QString::number(gui_ctl->temp_dou[j],'f',4));
            label_tem[j]->setText(str);
        }
        bt_page[0]->show();
        bt_page[1]->show();
        label_handwheel[0]->hide();
        label_handwheel[1]->hide();
        label_handwheel[2]->hide();
        label_handwheel[3]->hide();
        label_handwheel[4]->hide();


    }
    else if(cur_page==2)//第3页
    {
//        for (j=100;j<200;j++)
//        {
//            str = QString("%1 %2").arg(motion_status->temp_char[j-100]).arg(QString::number(motion_status->temp_dou[j-100],'f',4));
//            label_tem[j]->setText(str);
//        }
        for (j=40;j<80;j++)
        {
            str = QString("%1 %2").arg(gui_ctl->temp_char[j]).arg(QString::number(gui_ctl->temp_dou[j],'f',4));
            label_tem[j]->setText(str);
        }
        label_handwheel[0]->hide();
        label_handwheel[1]->hide();
        label_handwheel[2]->hide();
        label_handwheel[3]->hide();
        label_handwheel[4]->hide();
    }
    else if(cur_page==3)//第4页
    {
//        for (j=200;j<300;j++)
//        {
//            str = QString("char%1 %2").arg(j-200).arg(motion_status->temp_char[j-200]);
//            label_tem[j]->setText(str);
//        }
        for (j=80;j<100;j++)
        {
            str = QString("%1 %2").arg(gui_ctl->temp_char[j]).arg(QString::number(gui_ctl->temp_dou[j],'f',4));
            label_tem[j]->setText(str);
        }
        label_handwheel[0]->hide();
        label_handwheel[1]->hide();
        label_handwheel[2]->hide();
        label_handwheel[3]->hide();
        label_handwheel[4]->hide();
    }
//    else if(cur_page==4)//第5页
//    {
//        for (j=300;j<400;j++)
//        {
//            str = QString("char%1 %2").arg(j-200).arg(motion_status->temp_char[j-300]);
//            label_tem[j]->setText(str);
//        }
//        label_handwheel[0]->hide();
//        label_handwheel[1]->hide();
//        label_handwheel[2]->hide();
//        label_handwheel[3]->hide();
//        label_handwheel[4]->hide();
//    }
}

void set_dgn::set_table_info()
{
    int i,j;
    j = 0;
    static int cc = 0;
    if(cc==20)
    {
        cc=0;
        gui_ctl->temp_dou[0]++;
    }
    cc++;

    table_info->clearContents();
    //table_info->setHorizontalHeaderLabels(QStringList() <<"序号"<<"注释"<<"数据");
    for(i = 0;i <Row_NUM;i++)
    {
        if(i+first_line>=100)
        {
            break;
        }
        table_info->setItem(i,0,new QTableWidgetItem(QString::number(i+first_line+1)));
        table_info->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        table_info->setItem(i,1,new QTableWidgetItem(gui_ctl->temp_char[i+first_line]));
        table_info->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        table_info->setItem(i,2,new QTableWidgetItem(QString::number(gui_ctl->temp_dou[i+first_line],'f',4)));
        table_info->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    }
}

void set_dgn::Timer_on_slot()
{
    set_info();
    set_table_info();
    update();

    if(gui_ctl->request_g99==0)
    {
        //bt_G98G99->setText("G98");
        lab_G98G99->setText("G98");
    }
    else
    {
        //bt_G98G99->setText("G99");
        lab_G98G99->setText("G99");
    }
}

void set_dgn::back_slot()
{
    emit back_signal();
}

void set_dgn::uppage_slot()
{
    cur_page--;
    if(cur_page<0)
    {
        cur_page = 0;
    }
    temp_dgn_load();
    update();
}

void set_dgn::downpage_slot()
{
    cur_page++;
    if(cur_page>MAXpage-1)
    {
        cur_page = MAXpage-1;
    }
    temp_dgn_load();
    update();
}

void set_dgn::uppage_slot1()
{
    first_line = first_line-Row_NUM;
    if(first_line<0)
    {
        first_line=0;
    }
    set_table_info();
}

void set_dgn::downpage_slot1()
{
    qDebug()<<"first_line="<<first_line;
    if(first_line+Row_NUM>=100)
    {
        return;
    }
    first_line = first_line+Row_NUM;
    set_table_info();

}

void set_dgn::keyboard_show()
{
    keyboard->show();
    keyboard->focus_init();
}

void set_dgn::val_input_slot(QString str)
{
    edit_mdi->setText(str);
    strcpy(gui_ctl->mdi,str.toLocal8Bit().data());
    keyboard->hide();

}

void set_dgn::change_g98g99()
{
    if(gui_ctl->request_g99==0)
    {
        gui_ctl->request_g99 = 1;
        lab_G98G99->setText("G98");
        bt_G98G99->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");
    }
    else if(gui_ctl->request_g99==1)
    {
        gui_ctl->request_g99 = 0;
        lab_G98G99->setText("G99");
        bt_G98G99->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }
}

void set_dgn::draw_signal()
{
    int i;
    int length = 20,weith = 20;
    QPainter painter;
    QPen pen_on,pen_off;
    pen_on.setColor(Qt::green);
    pen_off.setColor(QColor(194,222,239));
    //pen2=QPen(QColor(194,222,239));
    pen_on.setWidth(2); //设置线宽
    pen_off.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen_off);

    QPolygon p_x[48],p_y[48];

    for (i=0;i<48;i++)
    {
        p_x[i]<<QPoint(60+(i%8)*70,20+(i/8)*30)<<QPoint(60+(i%8)*70+length,20+(i/8)*30)<<QPoint(60+(i%8)*70+length,20+(i/8)*30+weith)<<QPoint(60+(i%8)*70,20+(i/8)*30+weith);
        p_y[i]<<QPoint(60+(i%8)*70,210+(i/8)*30)<<QPoint(60+(i%8)*70+length,210+(i/8)*30)<<QPoint(60+(i%8)*70+length,210+(i/8)*30+weith)<<QPoint(60+(i%8)*70,210+(i/8)*30+weith);
        if(x_signal[i]==1)
        {
            painter.setBrush(QColor(65,205,82));
        }
        else
        {
            painter.setBrush(QColor(241,241,241));
        }
        painter.drawPolygon(p_x[i]);
        if(y_signal[i]==1)
        {
            painter.setBrush(QColor(65,205,82));
        }
        else
        {
            painter.setBrush(QColor(241,241,241));
        }
        painter.drawPolygon(p_y[i]);
    }




    painter.end();

}

void set_dgn::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPen pen;
    pen.setColor(QColor(216,216,216));
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    if(cur_page==1)
    {
        painter.drawLine(table_info->pos().rx(),table_info->pos().ry(),table_info->pos().rx(),table_info->size().height());
    }
    if(cur_page==0)
    {
        draw_signal();
    }
    painter.end();
}
