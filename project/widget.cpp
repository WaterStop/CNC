#include "widget.h"
#include "ui_widget.h"
#include "wedget1.h"
#include "ui_wedget1.h"
#include "baseset.h"
#include <QDebug>
#include "popupwin1.h"

#if debug_on ==0
QString alm_file = "/home/root/hunhegongye/File/warn.csv";
QString run_state_file = "/home/root/hunhegongye/File/run_state.csv";
QString limit_File = "/home/root/hunhegongye/File/lim_time.csv";
#elif debug_on==1
QString alm_file = ":/new/File/warn.csv";
QString run_state_file = "E:\\QT\\program\\BLUE\\File\\run_state.csv";
QString limit_File = "E:\\QT\\program\\BLUE\\File\\lim_time.csv";
#endif
static QStringList list_time;

Widget::Widget(QWidget *parent )
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);//去掉最大化最小化关闭按钮
    Info_init();
    set_background();
    set_widget_size();
    set_widget_button();
    //show_wg_popwin();
    deal_slot();
    screen_dis();
    dealInterfaceData->textRecoverData();
    ui->widget_1->input_work_pic();
    if(dealInterfaceData->firstInsystem == true)
    {
        work_info_init();
    }

    load_warnInfo();
    load_run_state_Info();
    get_LimTime();

    connect(ui->bt_popwin,SIGNAL(clicked()),this,SLOT(show_wg_popwin_slot()));

    if(scr_size==0)
    {
        this->resize(800,600);
    }
    else if(scr_size==1)
    {
        this->resize(1024,768);
    }

    if(dealInterfaceData->m_mSeq.index.num>1)//工艺列表不为空
    {
        dealInterfaceData->recoverVariable();
        show_dis_screen_slot();
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::set_wg1()
{

}

void Widget::Info_init()//初始化
{
    ui->widget_8->hide();
    ui->widget_5->hide();
    ui->widget_23->hide();
    ui->pro_modi->hide();
    ui->widget_3->show();
    ui->widget_9->show();

    ui->widget_10->Foucus_init();
    ui->wg_popwin->hide();
    ui->widget_set->hide();

    //timer->start(20);
    tip_bk = new QLabel(ui->frame);
    tip_error = new QLabel(this);
    ui->label_warn->raise();
    timer->start(50);

    bt_tip_error = new QPushButton(this);
    bt_tip_error->setGeometry(300,0,420,40);
    bt_tip_error->setStyleSheet("background:transparent;");
    bt_tip_error->setFocusPolicy(Qt::NoFocus);

    cur_time = new QLabel(ui->frame);
    cur_time->setGeometry(930,3,80,30);
    cur_time->setStyleSheet("color:white;");
    cur_time->setFont(weiruanyahei4);

    over_limit = new set_over_limit(ui->frame);
    over_limit->setGeometry(64,75,899,643);
    over_limit->show();

}

void Widget::set_background()//widget设置背景图
{
    QPalette pal =this->palette();
    //pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/blue_pic/base_0.png")));
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/blue_pic/base_0.png")));
    setPalette(pal);

    //ui->frame->setAutoFillBackground(true);
    ui->frame->setAutoFillBackground(false);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/base_0.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}

void Widget::resizeEvent(QResizeEvent *event)//背景图片随窗口变化
{
   Q_UNUSED(event)
   QImage image;
   QPalette palette;
   image.load(":/new/blue_pic/base_0.png");
   palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
   this->setPalette(palette);
}

void Widget::load_warnInfo()
{
    QFile file(alm_file);
        if (file.open(QIODevice::ReadOnly /*| QIODevice::Text*/))
        {
            QString line;
            QTextStream in(&file);  //用文件构造流
            line = in.readLine();//读取一行放到字符串里
            while(!line.isNull())//字符串有内容
            {
                load_warn_text(line);
                line=in.readLine();//循环读取下行
            }
        }
        file.close();
}

void Widget::load_run_state_Info()
{
    QStringList strList;
    QFile file(run_state_file);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //()<<"打开文件成功";
        QString line;
        QTextStream in(&file);  //用文件构造流
        line = in.readLine();//读取一行放到字符串里
        while(!line.isNull())//字符串有内容
        {
            strList = line.split(",",QString::KeepEmptyParts );
            RUNSTATE_File_List[strList.at(0).toInt()] = strList.at(1);
            line=in.readLine();//循环读取下行
        }
    }
    file.close();
}

void Widget::get_LimTime()
{
    QStringList str_list;
    QFile file(limit_File);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        line = in.readAll();
        if(!line.isNull())//字符串有内容
        {
            list_time = line.split("\n",QString::KeepEmptyParts);
        }
    }

    limittime=list_time.at(1).toInt();
    alarmtime=list_time.at(2).toInt();
    Remainingtime = list_time.at(0).toInt()+limittime*60*60;
    User_Name = list_time.at(3);
    protect_flg = list_time.at(4).toInt();
    qDebug()<<list_time;

    file.close();
}

void Widget::load_warn_text(QString str)//载入报警内容
{
    //QStringList strList = str.split(",",QString::SkipEmptyParts);
    QStringList strList = str.split(",",QString::KeepEmptyParts );
    Warn_File_List[strList[0].toInt()] = strList[1];
    //qDebug()<<"strList[1]="<<strList[1];
    WarnNote_File_List[strList[0].toInt()] = strList[2];
}

void Widget::work_info_init()//初始化
{
    s_outerCircleMode1 tempTransver;
    tempTransver.xDir = -1;

    tempTransver.L = 0;
    tempTransver.Tr = 0;
    tempTransver.Cn = 0;
    tempTransver.Cr = 0;
    tempTransver.F = 0;

    dealInterfaceData->firstInsystem = true;

    dealInterfaceData->addNode(tempTransver);
}

void Widget::set_widget_size()//界面大小位置设置
{

    ui->wg_popwin->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    ui->pro_modi->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    ui->widget_23->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    if(scr_size==0)
    {
        ui->widget_1->setGeometry(32,62,133,336);
        ui->widget_2->setGeometry(172,62,363,336);
        ui->widget_3->setGeometry(539,62,235,336);
        ui->widget_4->setGeometry(32,401,510,160);
        ui->widget_5->setGeometry(540,401,231,160);
        ui->wg_popwin->setGeometry(645,93,171,470);
        ui->widget_6->setGeometry(539,62,235,336);
        ui->widget_7->setGeometry(539,62,235,336);
        ui->widget_8->setGeometry(540,401,231,160);
        ui->widget_9->setGeometry(540,401,231,160);
        ui->widget_10->setGeometry(539,62,235,336);
        ui->widget_11->setGeometry(539,62,235,336);
        ui->widget_12->setGeometry(539,62,235,336);
        ui->widget_13->setGeometry(539,62,235,336);
        ui->widget_14->setGeometry(539,62,235,336);
        ui->widget_15->setGeometry(539,62,235,336);
        ui->widget_16->setGeometry(539,62,235,336);
        ui->widget_17->setGeometry(539,62,235,336);
        ui->widget_18->setGeometry(539,62,235,336);
        ui->widget_19->setGeometry(539,62,235,336);
        ui->widget_20->setGeometry(539,62,235,336);
        ui->widget_21->setGeometry(539,62,235,336);
        ui->pro_modi->setGeometry(70,70,143,311);
    }
    else if(scr_size==1)
    {
        ui->widget_1->setGeometry(42,80,171,431);
        ui->widget_2->setGeometry(221,80,465,431);
        ui->widget_3->setGeometry(691,80,301,431);
        ui->widget_4->setGeometry(42,514,654,205);
        ui->widget_5->setGeometry(691,514,301,205);
        ui->wg_popwin->setGeometry(800,120,189,470);
        ui->widget_6->setGeometry(691,80,301,431);
        ui->widget_7->setGeometry(691,80,301,431);
        ui->widget_8->setGeometry(691,514,301,205);
        ui->widget_9->setGeometry(688,505,310,213);
        ui->widget_10->setGeometry(691,80,301,431);
        ui->widget_11->setGeometry(691,80,301,431);
        ui->widget_12->setGeometry(691,80,301,431);
        ui->widget_13->setGeometry(691,80,301,431);
        ui->widget_14->setGeometry(691,80,301,431);
        ui->widget_15->setGeometry(691,80,301,431);
        ui->widget_16->setGeometry(691,80,301,431);
        ui->widget_17->setGeometry(691,80,301,431);
        ui->widget_18->setGeometry(691,80,301,431);
        ui->widget_19->setGeometry(691,80,301,431);
        ui->widget_20->setGeometry(691,80,301,431);
        ui->widget_21->setGeometry(691,80,301,431);
        ui->widget_22->setGeometry(691,80,301,431);
        ui->widget_23->setGeometry(691,433,293,70);
        ui->pro_modi->setGeometry(70,70,143,311);
        ui->widget_set->setGeometry(64,75,899,643);

    }

}

void Widget::deal_slot()
{
    connect(ui->wg_popwin, SIGNAL(change_work_signal()), this, SLOT(main_update_slot()));
    //connect(ui->wg_popwin, SIGNAL(change_work_signal()), ui->widget_2, SLOT(DateUpdate_slot()));

    connect(ui->widget_10, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_11, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_12, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_13, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_14, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_15, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_16, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_17, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_18, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_19, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_20, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
    connect(ui->widget_21, SIGNAL(input_ok_signal()), this, SLOT(show_dis_screen_slot()));
		    
    connect(ui->widget_8, SIGNAL(waiyuan1_enter_signal()), ui->widget_10, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(waiyuan2_enter_signal()), ui->widget_11, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(waiyuan3_enter_signal()), ui->widget_17, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(duanmian1_enter_signal()), ui->widget_12, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(duanmian2_enter_signal()), ui->widget_15, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(duanmian3_enter_signal()), ui->widget_12, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(likong1_enter_signal()), ui->widget_10, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(likong2_enter_signal()), ui->widget_11, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(likong3_enter_signal()), ui->widget_16, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(likong4_enter_signal()), ui->widget_17, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(likong5_enter_signal()), ui->widget_18, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(zhuimian1_enter_signal()), ui->widget_11, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(zhuimian2_enter_signal()), ui->widget_11, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(zhuimian3_enter_signal()), ui->widget_11, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(zhuimian4_enter_signal()), ui->widget_11, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(luowen1_enter_signal()), ui->widget_13, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(luowen2_enter_signal()), ui->widget_19, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(luowen3_enter_signal()), ui->widget_13, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(luowen4_enter_signal()), ui->widget_19, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(daojiao1_enter_signal()), ui->widget_14, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(daojiao2_enter_signal()), ui->widget_21, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(daojiao3_enter_signal()), ui->widget_14, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(daojiao4_enter_signal()), ui->widget_21, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(luowenset_enter_signal()), ui->widget_22, SLOT(Focus_switch_slot()));
    connect(ui->widget_8, SIGNAL(output_enter_signak()), ui->widget_3, SLOT(deal_enter_slot()));

    connect(ui->widget_13, SIGNAL(goto_LuowenSet_signal()), this, SLOT(goto_LuowenSet_slot()));
    connect(ui->widget_13, SIGNAL(mode_changed_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_19, SIGNAL(zhuiluowen_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_19, SIGNAL(goto_LuowenSet_signal()), this, SLOT(goto_LuowenSet_slot()));
    connect(ui->widget_22, SIGNAL(back_lastpage()), this, SLOT(gouback_lastpage_slot()));
    connect(ui->widget_13, SIGNAL(luowen_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_13, SIGNAL(mode_changed_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_19, SIGNAL(zhuiluowen_fixval_signal()), this, SLOT(show_fixval_slot()));

//    connect(ui->widget_10, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_11, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_12, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_13, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_14, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_15, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_16, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_17, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_18, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_19, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_20, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
//    connect(ui->widget_21, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));

//    connect(ui->widget_10, SIGNAL(feed_fixval_signal()),this, SLOT(show_fixval_slot()));
//    connect(ui->widget_11, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_12, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_13, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_14, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_15, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_16, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_17, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_18, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_19, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_20, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
//    connect(ui->widget_21, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));

    connect(ui->widget_10, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_11, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_12, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_13, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_14, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_15, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_16, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_17, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_18, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_19, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    //connect(ui->widget_20, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));
    connect(ui->widget_21, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));

    connect(ui->widget_23, SIGNAL(bt0_signal()), this, SLOT(hide_fixval_slot()));
    connect(ui->widget_23, SIGNAL(bt1_signal()), this, SLOT(hide_fixval_slot()));
    connect(ui->widget_23, SIGNAL(bt2_signal()), this, SLOT(hide_fixval_slot()));

    connect(ui->widget_1, SIGNAL(bt_signal(int)), this, SLOT(addWorkInfo_slot(int)));

    connect(ui->pro_modi, SIGNAL(bt_pressed(int)), this, SLOT(deal_pro_modi_slot(int)));
    connect(ui->widget_1, SIGNAL(long_press_signal(int)), this, SLOT(show_pro_modi_slot(int)));

    connect(ui->widget_3, SIGNAL(edit_press_signal(int)), this, SLOT(show_keybord_slot(int)));
    connect(ui->widget_3, SIGNAL(close_keyboard_signal()), this, SLOT(close_keyboard_slot()));
    connect(ui->widget_3, SIGNAL(edit_input_signal(int,QString)),this, SLOT(edit_input_slot(int,QString)));

    connect(ui->bt_set, SIGNAL(clicked()), this, SLOT(goto_setcsreen_slot()));

    connect(ui->label_warn, SIGNAL(tick_end()), this, SLOT(change_warn_text_slot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));

    connect(ui->widget_set, SIGNAL(back_signal()), this, SLOT(set_win_back_slot()));
    connect(ui->widget_2, SIGNAL(page_jump_signal(int)), this, SLOT(page_jump_slot(int)));
    connect(bt_tip_error, SIGNAL(clicked()), this, SLOT(jump_to_alm_info_slot()));

}

void Widget::set_widget_button()
{
    ui->bt_popwin->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/pop1_return.png);}");
    ui->bt_set->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/bt_set.png);}");
    ui->label_warn->setFont(weiruanyahei6);
    ui->label_warn->setStyleSheet("color: rgb(255, 255, 255);");
    tip_error->setFont(weiruanyahei6);
    tip_error->setStyleSheet("color: rgb(0, 0, 255);");
    if(scr_size==0)
    {
        ui->bt_popwin->setGeometry(773,244,21,59);
    }
    else if(scr_size==1)
    {
        //ui->bt_popwin->setGeometry(955,313,27,76);
        ui->bt_popwin->setGeometry(988,313,27,76);
        ui->bt_set->setGeometry(875,7,24,24);
        tip_bk->setGeometry(301,0,421,44);
        ui->label_warn->setGeometry(370,8,330,30);
        tip_error->setGeometry(330,8,40,30);
    }

    motion_err->size = 0;
//        for (int i=0;i<MAX_ERROR_NUM;i++)
//        {
//            motion_err->data[i].id = 2+i*50;
//        }
//    motion_err->data[0].id = 2;
//    motion_err->data[1].id = 2050;
//    motion_err->data[2].id = 3050;
//    motion_err->data[3].id = 1400;
//    motion_err->data[4].id = 4300;
//    motion_err->data[5].id = 2400;
//    motion_err->data[31].id = 12000;
//    motion_err->data[1].id = 2002;
//    motion_err->data[2].id = 2003;
}

void Widget::show_tipInfo()//顶部报警提示栏
{
    if(motion_err->size==0)
    {
        warn_flg = 0;
    }
    else
    {
        warn_flg = 1;
    }
    if(warn_flg==0)
    {
        tip_bk->setStyleSheet(0);
        ui->label_warn->setStyleSheet("color: rgb(255, 255, 255);");
        //ui->label_warn->setText("");
        ui->label_warn->setText(RUNSTATE_File_List[motion_status->run_state]);
        tip_error->setText("");

    }
    else
    {
        tip_bk->setStyleSheet("border-image:url(:/new/blue_pic/error_tip_bk.png);");
        ui->label_warn->setStyleSheet("color:blue;");
        change_warn_text_slot();
        //ui->label_warn->setText(Warn_File_List[motion_warn->data[i].id]);
    }
}

void Widget::CNC_Warning()
{
    int i;
    for (i=0;i<motion_err->size;i++)
    {
        ui->label_warn->setText(Warn_File_List[motion_err->data[i].id]);
    }
}

void Widget::show_wg_popwin()
{
    ui->wg_popwin->show();
}

void Widget::show_wg_popwin_slot()//显示弹窗
{
    //popupwin_flg1 = 1-popupwin_flg1;
    show_wg_popwin();
}

void Widget::change_warn_text_slot()//报警信息切换显示
{

    static int warn_num = 0;//当前显示的报警
    static int refresh1 = 1,refresh2 = 1;//闪烁用
    //static int showalarm=0;//当前显示的报警
    QString str;
    //qDebug()<<"显示报警 warn_flg="<<warn_flg;
    if(warn_flg==1)
    {
        if(motion_err->size==0)
        {
            return;
        }
        if(motion_err->size>=50)
        {
            return;
        }
        //报警内容循环显示
        refresh2++;
        if(refresh2 == 1)
        {
            warn_num++;
        }
        if(warn_num>=motion_err->size)
        {
            warn_num = 0;
        }
        if(refresh2==100)
        {
            refresh2=0;
        }

        //设置报警这个字闪烁和报警内容变化
        refresh1++;
        if(refresh1==20)
        {
            refresh1=0;
        }
        if(refresh1 >= 1 && refresh1<10)//设置表头“报警(i/j):”
        {
            tip_error->setText("报警");
        }
        if(refresh1 >= 10)//把报警的位置空出来
        {
            tip_error->setText(" ");
        }
//        qDebug()<<"size="<<motion_warn->size;
//        qDebug()<<"id="<<motion_warn->data[warn_num].id;
        //qDebug()<<"内容："<<Warn_File_List[motion_warn->data[warn_num].id];
        if(motion_err->data[warn_num].id>=ErrorMaxNum)
        {
            return;
        }
        //if(Warn_File_List[motion_err->data[warn_num].id]==NULL)
        if(Warn_File_List[motion_err->data[warn_num].id].isEmpty()==1)
        {
            //str = QString("(%1/%2):%3").arg(warn_num+1).arg(motion_err->size).arg("");
            str = QString("(%1/%2):%3").arg(warn_num+1).arg(motion_err->size).arg(motion_err->data[warn_num].id);
        }
        else
        {
            str = QString("(%1/%2):%3").arg(warn_num+1).arg(motion_err->size).arg(Warn_File_List[motion_err->data[warn_num].id]);
        }
        ui->label_warn->setText(str);
    };

}


void Widget::Timer_on_slot()//主定时器
{
    static int temp_i = 0;
    static int temp_p = 0;
    QDateTime timeT = QDateTime::currentDateTime();   //获取当前时间
    uint secondsT = timeT.toTime_t();//返回当前自1970-01-01 00:00:00经过了多少秒

    show_tipInfo();//顶部提示栏
    if(currect_screen>=scr_bangliao&&currect_screen<=scr_daojiao4)
    {
        ui->widget_2->Timer_on_slot();
        ui->widget_3->Timer_on_slot();
        ui->widget_4->Timer_on_slot();
        ui->widget_9->Timer_on_slot();
    }
    else if(currect_screen==scr_SET)
    {
        ui->widget_set->Timer_on_slot();
    }

    if(temp_i==0)
    {
        //decode_status->start_flag = 1;
        gui_ctl->start_bus = 1;
        qDebug()<<"start_bus="<<gui_ctl->start_bus;
        temp_i=1;
    }
    if(protect_flg==1)//开启过期保护
    {
        if(secondsT>Remainingtime)
        {
            to_protect();
            temp_p = 0;
        }
        else
        {
            if(temp_p==0)
            {
                show_dis_screen_slot();
                over_limit->hide();
                ui->bt_popwin->show();
                temp_p = 1;
            }
        }
        if(has_set_protect==0)
        {
            get_LimTime();
            has_set_protect = 1;
            qDebug()<<"Remainingtime="<<Remainingtime;
        }
    }
    else
    {
        if(temp_p==0)
        {
            show_dis_screen_slot();
            over_limit->hide();
            ui->bt_popwin->show();
            temp_p = 1;
        }
    }
    update_time();

}

void Widget::set_win_back_slot()
{
    screen_dis();
    show_dis_screen_slot();
//    ui->widget_3->show();
//    ui->widget_3->DisLabel_title();
//    ui->widget_3->Info_dis();
    currect_screen = cur_work_mod;
}


void Widget::show_keybord()
{
    ui->widget_8->show();
    ui->widget_5->hide();
    ui->widget_9->hide();
}

void Widget::close_keyboard()
{
    ui->widget_8->hide();
    ui->widget_5->hide();
    ui->widget_9->show();
}

void Widget::show_keybord_slot(int index)
{
    //barstock_flg = 1;
    show_keybord();
}

void Widget::close_keyboard_slot()
{
    close_keyboard();
}


void Widget::goto_setcsreen_slot()
{
    goto_setcsreen();
}

void Widget::goto_setcsreen()//切换至设置界面
{
    ui->widget_set->show();
    close_worklist_scr();
    currect_screen = scr_SET;
}

void Widget::close_worklist_scr()//关闭所有工作列表界面
{
    ui->widget_1->hide();
    ui->widget_2->hide();
    ui->widget_3->hide();
    ui->widget_4->hide();
    ui->widget_5->hide();
    ui->widget_6->hide();
    ui->widget_7->hide();
    ui->widget_8->hide();
    ui->widget_9->hide();
    ui->widget_10->hide();
    ui->widget_11->hide();
    ui->widget_12->hide();
    ui->widget_13->hide();
    ui->widget_14->hide();
    ui->widget_15->hide();
    ui->widget_16->hide();
    ui->widget_17->hide();
    ui->widget_18->hide();
    ui->widget_19->hide();
    ui->widget_20->hide();
    ui->widget_21->hide();
    ui->widget_22->hide();
}

void Widget::show_dis_screen_slot()//显示输出界面
{
    save_flg = 0;
    is_output_scr = 1;
    val_change = 0;
    if(modify_flg==0)
    {
        cur_Node = dealInterfaceData->m_mSeq.index.num;
    }
    barstock_flg = 0;
    cur_work_mod = dealInterfaceData->findNode(cur_Node)->type-1;
    qDebug()<<"cur_work_mod="<<cur_work_mod;
    ui->widget_1->show();
    ui->widget_2->show();
    ui->widget_4->show();
    ui->widget_3->show();
    ui->widget_3->DisLabel_title();
    ui->widget_3->Info_dis();
    ui->widget_6->hide();
    ui->widget_7->hide();
    ui->widget_8->hide();
    ui->widget_9->show();
    ui->widget_10->hide();
    ui->widget_11->hide();
    ui->widget_12->hide();
    ui->widget_13->hide();
    ui->widget_14->hide();
    ui->widget_15->hide();
    ui->widget_16->hide();
    ui->widget_17->hide();
    ui->widget_18->hide();
    ui->widget_19->hide();
    ui->widget_20->hide();
    ui->widget_21->hide();
    ui->widget_22->hide();
    ui->widget_set->hide();

    ui->widget_1->input_work_pic();
    dealInterfaceData->update_pixelArray();
    input_ok_flg = 1;
    luowen_set_flg = 0;
    modify_flg = 0;
    ui->widget_22->ClearEdit();
    currect_screen = cur_work_mod;
    ui->widget_2->set_bt_jump();

}

void Widget::goto_LuowenSet_slot()//螺纹扩展页面
{
    luowen_set_flg = 1;
    ui->widget_10->hide();
    ui->widget_11->hide();
    ui->widget_12->hide();
    ui->widget_13->hide();
    ui->widget_14->hide();
    ui->widget_15->hide();
    ui->widget_16->hide();
    ui->widget_17->hide();
    ui->widget_18->hide();
    ui->widget_19->hide();
    ui->widget_20->hide();
    ui->widget_21->hide();
    ui->widget_22->show();
    ui->widget_22->Foucus_init();
}

void Widget::gouback_lastpage_slot()//从螺纹扩展页返回
{
    ui->widget_22->hide();
    //luowen_set_flg = 0;
    if(cur_work_mod==luowen1)
    {
        ui->widget_13->show();
        ui->widget_13->Foucus_init();
    }
    else if(cur_work_mod==luowen2)
    {
        ui->widget_19->show();
        ui->widget_19->Foucus_init();
    }
    else if(cur_work_mod==luowen3)
    {
        ui->widget_13->show();
        ui->widget_13->Foucus_init();
    }
    else if(cur_work_mod==luowen4)
    {
        ui->widget_19->show();
        ui->widget_19->Foucus_init();
    }

}

void Widget::to_barstock_set()//跳转至棒料设置界面
{
    cur_work_mod = bangliao;
    screen_dis();
    ui->widget_2->DateUpdate_slot();
    ui->widget_2->set_bt_jump();
}

void Widget::update_time()
{
    QString str;
    QDateTime datetime = QDateTime::currentDateTime();
    cur_year = datetime.date().year();             //年
    cur_mon = datetime.date().month();			   //月
    cur_day = datetime.date().day();				   //日
    cur_hour = datetime.time().hour();			   //时
    cur_min = datetime.time().minute();          //分
    cur_sec = datetime.time().second();          //秒
    cur_week = datetime.date().dayOfWeek();     //星期几
    str = QString("%1:%2:%3").arg(cur_hour,2,10, QLatin1Char('0')).arg(cur_min, 2,10, QLatin1Char('0')).arg(cur_sec,2,10, QLatin1Char('0'));
    cur_time->setText(str);
}

void Widget::to_protect()//进行过期保护
{
    ui->widget_set->hide();
    close_worklist_scr();
    over_limit->show();
    ui->bt_popwin->hide();
}

void Widget::jump_to_alm_info_slot()
{
    if(motion_err->size==0)
    {
        return;
    }
    //跳转至报警信息
    goto_setcsreen_slot();
    ui->widget_set->show_alminfo_scr();
}

void Widget::screen_change(int scr_num)
{
    currect_screen = scr_num;
    if((scr_num>=scr_bangliao)&&(scr_num<scr_SET))
    {

    }
    else if(scr_num>=scr_SET)
    {
        emit set_scr_change(scr_num);
    }
}

void Widget::page_jump_slot(int index)
{
    modify_flg = 1;
    if((index==0)||(index==1))
    {
        to_barstock_set();//返回棒料设置
    }
    else
    {
//            barstock_flg = 0;
//            is_output_scr = 0;
//            input_ok_flg = 1;
        addWorkInfo(dealInterfaceData->m_mSeq.index.num);
    }
//    switch (cur_work_mod)
//    {
//        case waiyuan1:
//        if((index==0)||(index==1))
//        {
//            to_barstock_set();
//        }
//        else
//        {
//            barstock_flg = 0;
//            is_output_scr = 0;
//            input_ok_flg = 1;
//            addWorkInfo(dealInterfaceData->m_mSeq.index.num);
//        }
//        break;
//        case waiyuan2:
//        ui->widget_11->widget3_4_editDataToGCode();
//        break;
//        case waiyuan3:
//        ui->widget_17->widget3_10_editDataToGCode();
//        break;
//        case duanmian1:
//        ui->widget_12->widget3_5_editDataToGCode();
//        break;
//        case duanmian2:
//        ui->widget_15->widget3_8_editDataToGCode();
//        break;
//        case duanmian3:
//        ui->widget_18->widget3_11_editDataToGCode();
//        break;
//        case likong1:
//        ui->widget_10->widget3_3_editDataToGCode();
//        break;
//        case likong2:
//        ui->widget_11->widget3_4_editDataToGCode();
//        break;
//        case likong3:
//        ui->widget_16->widget3_9_editDataToGCode();
//        break;
//        case likong4:
//        ui->widget_17->widget3_10_editDataToGCode();
//        break;
//        case likong5:
//        ui->widget_18->widget3_11_editDataToGCode();
//        break;
//        case zhuimian1:
//        ui->widget_11->widget3_4_editDataToGCode();
//        break;
//        case zhuimian2:
//        ui->widget_11->widget3_4_editDataToGCode();
//        break;
//        case zhuimian3:
//        ui->widget_11->widget3_4_editDataToGCode();
//        break;
//        case zhuimian4:
//        ui->widget_11->widget3_4_editDataToGCode();
//        break;
//        case luowen1:
//        ui->widget_13->widget3_6_editDataToGCode();
//        break;
//        case luowen2:
//        ui->widget_19->widget3_12_editDataToGCode();
//        break;
//        case luowen3:
//        ui->widget_13->widget3_6_editDataToGCode();
//        break;
//        case luowen4:
//        ui->widget_19->widget3_12_editDataToGCode();
//        break;
//        case daojiao1:
//        ui->widget_14->widget3_7_editDataToGCode();
//        break;
//        case daojiao2:
//        ui->widget_21->widget3_14_editDataToGCode();
//        break;
//        case daojiao3:
//        ui->widget_14->widget3_7_editDataToGCode();
//        break;
//        case daojiao4:
//        ui->widget_21->widget3_14_editDataToGCode();
//        break;
//        default:
//        break;
//    }
}

void Widget::screen_dis()//切换界面时调用
{
    ui->widget_1->show();
    ui->widget_2->show();
    ui->widget_4->show();
    ui->widget_3->hide();
    ui->widget_6->hide();
    ui->widget_7->hide();
    ui->widget_8->show();
    ui->widget_9->hide();
    ui->widget_10->hide();
    ui->widget_11->hide();
    ui->widget_12->hide();
    ui->widget_13->hide();
    ui->widget_14->hide();
    ui->widget_15->hide();
    ui->widget_16->hide();
    ui->widget_17->hide();
    ui->widget_18->hide();
    ui->widget_19->hide();
    ui->widget_20->hide();
    ui->widget_21->hide();
    ui->widget_22->hide();
    ui->widget_set->hide();

    luowen_set_flg = 0;
    ui->widget_22->ClearEdit();

//    if(barstock_flg==1)
//    {
//        ui->widget_3->show();
//        ui->widget_8->hide();
//        ui->widget_9->show();
//        return;
//    }
    if (cur_work_mod==bangliao)
    {
        barstock_flg = 1;
        is_output_scr = 1;
        input_ok_flg = 0;
        //ui->widget_2->DateUpdate_slot();
        ui->widget_3->show();
        ui->widget_8->hide();
        ui->widget_9->show();
        ui->widget_3->DisLabel_title();
        ui->widget_3->Info_dis();
    }
    else if (cur_work_mod==waiyuan1)
    {
        ui->widget_10->show();
        ui->widget_10->INFO_init();
    }
    else if (cur_work_mod==waiyuan2)
    {
        ui->widget_11->show();
        ui->widget_11->INFO_init();
    }
    else if (cur_work_mod==waiyuan3)
    {
        ui->widget_17->show();
        ui->widget_17->INFO_init();
    }
    else if (cur_work_mod==duanmian1)
    {
        ui->widget_12->show();
        ui->widget_12->INFO_init();
    }
    else if (cur_work_mod==duanmian2)
    {
        ui->widget_15->show();
        ui->widget_15->INFO_init();
    }
    else if (cur_work_mod==duanmian3)
    {
        ui->widget_12->show();
        ui->widget_12->INFO_init();
    }
    else if (cur_work_mod==likong1)
    {
        ui->widget_10->show();
        ui->widget_10->INFO_init();
    }
    else if (cur_work_mod==likong2)
    {
        ui->widget_11->show();
        ui->widget_11->INFO_init();
    }
    else if (cur_work_mod==likong3)
    {
        ui->widget_16->show();
        ui->widget_16->INFO_init();
    }
    else if (cur_work_mod==likong4)
    {
        ui->widget_17->show();
        ui->widget_17->INFO_init();
    }
    else if (cur_work_mod==likong5)
    {
        ui->widget_18->show();
        ui->widget_18->INFO_init();
    }    
    else if (cur_work_mod==zhuimian1)
    {
        ui->widget_11->show();
        ui->widget_11->INFO_init();
    }
    else if (cur_work_mod==zhuimian2)
    {
        ui->widget_11->show();
        ui->widget_11->INFO_init();
    }
    else if (cur_work_mod==zhuimian3)
    {
        ui->widget_11->show();
        ui->widget_11->INFO_init();
    }
    else if (cur_work_mod==zhuimian4)
    {
        ui->widget_11->show();
        ui->widget_11->INFO_init();
    }
    else if (cur_work_mod==luowen1)
    {
        ui->widget_13->show();
        ui->widget_13->INFO_init();
    }
    else if (cur_work_mod==luowen2)
    {
        ui->widget_19->show();
        ui->widget_19->INFO_init();
    }
    else if (cur_work_mod==luowen3)
    {
        ui->widget_13->show();
        ui->widget_13->INFO_init();
    }
    else if (cur_work_mod==luowen4)
    {
        ui->widget_19->show();
        ui->widget_19->INFO_init();
    }
    else if (cur_work_mod==daojiao1)
    {
        ui->widget_14->show();
        ui->widget_14->INFO_init();
    }
    else if (cur_work_mod==daojiao2)
    {
        ui->widget_21->show();
        ui->widget_21->INFO_init();
    }
    else if (cur_work_mod==daojiao3)
    {
        ui->widget_14->show();
        ui->widget_14->INFO_init();
    }
    else if (cur_work_mod==daojiao4)
    {
        ui->widget_21->show();
        ui->widget_21->INFO_init();
    }
    ui->widget_2->UPdate_scr();
}


void Widget:: main_update_slot()//界面切换调用弹窗
{
    val_change = 0;
    if((barstock_flg==1)||((currect_screen>=scr_daojiao4)||(currect_screen<=scr_bangliao))||(input_ok_flg==1))
    {
        //save_flg = 0;
        barstock_flg = 0;
        is_output_scr = 0;
        screen_dis();
        input_ok_flg = 0;

        ui->widget_2->DateUpdate_slot();
        //return;

    }
    else
    {
        save_flg = 1;
        is_output_scr = 0;
        Tip = new change_screentip();
        Tip->set_tip("即将切换界面，是否保存参数");
        int a = Tip->exec();
        delete Tip;

        if(a == 1)
        {
            Save_Info();
            if(last_work_mod!=bangliao)
            {
                ui->widget_1->input_work_pic();
            }
            screen_dis();
        }
        else
        {
            screen_dis();
        }
        input_ok_flg = 0;
        ui->widget_2->DateUpdate_slot();
        modify_flg = 0;
    }
    ui->widget_2->set_bt_jump();
    currect_screen = cur_work_mod;

}

void Widget:: show_fixval_slot()//显示固定值弹窗
{
    ui->widget_23->show();
}

void Widget:: hide_fixval_slot()
{
    ui->widget_23->hide();
    if (cur_work_mod==waiyuan1)
    {
        ui->widget_10->fixval_set();
    }
    else if (cur_work_mod==waiyuan2)
    {
        ui->widget_11->fixval_set();
    }
    else if (cur_work_mod==waiyuan3)
    {
        ui->widget_17->fixval_set();
    }
    else if (cur_work_mod==duanmian1)
    {
        ui->widget_12->fixval_set();
    }
    else if (cur_work_mod==duanmian2)
    {
        ui->widget_15->fixval_set();
    }
    else if (cur_work_mod==duanmian3)
    {
        ui->widget_12->fixval_set();
    }
    else if (cur_work_mod==likong1)
    {
        ui->widget_10->fixval_set();
    }
    else if (cur_work_mod==likong2)
    {
        ui->widget_11->fixval_set();
    }
    else if (cur_work_mod==likong3)
    {
        ui->widget_16->fixval_set();
    }
    else if (cur_work_mod==likong4)
    {
        ui->widget_17->fixval_set();
    }
    else if (cur_work_mod==likong5)
    {
        ui->widget_18->fixval_set();
    }
    else if (cur_work_mod==zhuimian1)
    {
        ui->widget_11->fixval_set();
    }
    else if (cur_work_mod==zhuimian2)
    {
        ui->widget_11->fixval_set();
    }
    else if (cur_work_mod==zhuimian3)
    {
        ui->widget_11->fixval_set();
    }
    else if (cur_work_mod==zhuimian4)
    {
        ui->widget_11->fixval_set();
    }
    else if (cur_work_mod==luowen1)
    {
        ui->widget_13->fixval_set();
    }
    else if (cur_work_mod==luowen2)
    {
        ui->widget_19->fixval_set();
    }
    else if (cur_work_mod==luowen3)
    {
        ui->widget_13->fixval_set();
    }
    else if (cur_work_mod==luowen4)
    {
        ui->widget_19->fixval_set();
    }
    else if (cur_work_mod==daojiao1)
    {
        ui->widget_14->fixval_set();
    }
    else if (cur_work_mod==daojiao2)
    {
        ui->widget_21->fixval_set();
    }
    else if (cur_work_mod==daojiao3)
    {
        ui->widget_14->fixval_set();
    }
    else if (cur_work_mod==daojiao4)
    {
        ui->widget_21->fixval_set();
    }
}

void Widget::addWorkInfo_slot(int index)
{
    addWorkInfo(index);
}

void Widget::deal_pro_modi_slot(int index)//工艺修改菜单
{
    switch (index)
    {
        case jianqie:

        break;
        case yidong:

        break;
        case fuzhi:

        break;
        case shanchu:
        if(dealInterfaceData->m_mSeq.index.num==1&&position_index==1)
        {
            s_outerCircleMode1 tempTransver;
            machineNode *tem_val;

            tempTransver.L = 0;
            tempTransver.Tr = 0;
            tempTransver.Cn = 0;
            tempTransver.Cr = 0;
            tempTransver.F = 0;

            dealInterfaceData->firstInsystem = true;

            dealInterfaceData->changeNode(1,tempTransver);
            tem_val = dealInterfaceData->findNode(1);
            tem_val->type = 0;
        }
        else
        {
            dealInterfaceData->deleteNode(position_index);
        }
        ui->widget_1->input_work_pic();
        dealInterfaceData->textRecordData();// 保存文件
        break;
        case zhantie:

        break;
        case bianji:

        break;
        case tianjia:

        break;
        default:
        break;
    }
    ui->pro_modi->hide();
}

void Widget::show_pro_modi_slot(int index)
{
    position_index = index;
    int tmp_x,tmp_y;
    tmp_x=this->mapFromGlobal(QCursor().pos()).x();
    tmp_y=this->mapFromGlobal(QCursor().pos()).y();
    qDebug()<<"tmp_x="<<tmp_x<<"tmp_y="<<tmp_y;
    ui->pro_modi->move(tmp_x,tmp_y);
    ui->pro_modi->show();
    //deal_pro_modi_slot(index);
}

void Widget::addWorkInfo(int index)//读取点击的工艺内容
{
    machineNode *tem_val;
    if(index>dealInterfaceData->m_mSeq.index.num)
    {
        return;
    }
    tem_val = dealInterfaceData->findNode(index);

    switch (tem_val->type)
    {
        case OUTER_CIRCLE_ONE:
        cur_work_mod =waiyuan1;
        barstock_flg = 0;
        screen_dis();
        ui->widget_10->loadWorkInfo(index);
        break;
        case OUTER_CIRCLE_TWO:
        cur_work_mod =waiyuan2;
        screen_dis();
        ui->widget_11->loadWorkInfo(index);
        break;
        case OUTER_CIRCLE_THREE:
        cur_work_mod =waiyuan3;
        screen_dis();
        ui->widget_17->loadWorkInfo(index);
        break;
        case END_FACE_ONE:
        cur_work_mod =duanmian1;
        screen_dis();
        ui->widget_12->loadWorkInfo(index);
        break;
        case END_FACE_TWO:
        cur_work_mod =duanmian2;
        screen_dis();
        ui->widget_15->loadWorkInfo(index);
        break;
        case END_FACE_THREE:
        cur_work_mod =duanmian3;
        screen_dis();
        ui->widget_12->loadWorkInfo(index);
        break;
        case INNER_HOLE_ONE:
        cur_work_mod =likong1;
        screen_dis();
        ui->widget_10->loadWorkInfo(index);
        break;
        case INNER_HOLE_TWO:
        cur_work_mod =likong2;
        screen_dis();
        ui->widget_11->loadWorkInfo(index);
        break;
        case INNER_HOLE_THREE:
        cur_work_mod =likong3;
        screen_dis();
        ui->widget_16->loadWorkInfo(index);
        break;
        case INNER_HOLE_FOUR:
        cur_work_mod =likong4;
        screen_dis();
        ui->widget_17->loadWorkInfo(index);
        break;
        case INNER_HOLE_FIVE:
        cur_work_mod =likong5;
        screen_dis();
        ui->widget_18->loadWorkInfo(index);
        break;
        case CONE_FACE_ONE:
        cur_work_mod =zhuimian1;
        screen_dis();
        ui->widget_11->loadWorkInfo(index);
        break;
        case CONE_FACE_TWO:
        cur_work_mod =zhuimian2;
        screen_dis();
        ui->widget_11->loadWorkInfo(index);
        break;
        case CONE_FACE_THREE:
        cur_work_mod =zhuimian3;
        screen_dis();
        ui->widget_11->loadWorkInfo(index);
        break;
        case CONE_FACE_FOUR:
        cur_work_mod =zhuimian4;
        screen_dis();
        ui->widget_11->loadWorkInfo(index);
        break;
        case SCREW_THREAD_ONE:
        cur_work_mod =luowen1;
        screen_dis();
        ui->widget_13->loadWorkInfo(index);
        break;
        case SCREW_THREAD_TWO:
        cur_work_mod =luowen2;
        screen_dis();
        ui->widget_19->loadWorkInfo(index);
        break;
        case SCREW_THREAD_THREE:
        cur_work_mod =luowen3;
        screen_dis();
        ui->widget_13->loadWorkInfo(index);
        break;
        case SCREW_THREAD_FOUR:
        cur_work_mod =luowen4;
        screen_dis();
        ui->widget_19->loadWorkInfo(index);
        break;
        case CHAMFER_ONE:
        cur_work_mod =daojiao1;
        screen_dis();
        ui->widget_14->loadWorkInfo(index);
        break;
        case CHAMFER_TWO:
        cur_work_mod =daojiao2;
        screen_dis();
        ui->widget_21->loadWorkInfo(index);
        break;
        case CHAMFER_THREE:
        cur_work_mod =daojiao3;
        screen_dis();
        ui->widget_14->loadWorkInfo(index);
        break;
        case CHAMFER_FOUR:
        cur_work_mod =daojiao4;
        screen_dis();
        ui->widget_21->loadWorkInfo(index);
        break;
        default:
        break;
    }
}

void Widget::Save_Info()//保存当前页面数据到节点
{
    switch (last_work_mod)
    {
        case waiyuan1:
        ui->widget_10->widget3_3_editDataToGCode();
        break;
        case waiyuan2:
        ui->widget_11->widget3_4_editDataToGCode();
        break;
        case waiyuan3:
        ui->widget_17->widget3_10_editDataToGCode();
        break;
        case duanmian1:
        ui->widget_12->widget3_5_editDataToGCode();
        break;
        case duanmian2:
        ui->widget_15->widget3_8_editDataToGCode();
        break;
        case duanmian3:
        ui->widget_18->widget3_11_editDataToGCode();
        break;
        case likong1:
        ui->widget_10->widget3_3_editDataToGCode();
        break;
        case likong2:
        ui->widget_11->widget3_4_editDataToGCode();
        break;
        case likong3:
        ui->widget_16->widget3_9_editDataToGCode();
        break;
        case likong4:
        ui->widget_17->widget3_10_editDataToGCode();
        break;
        case likong5:
        ui->widget_18->widget3_11_editDataToGCode();
        break;
        case zhuimian1:
        ui->widget_11->widget3_4_editDataToGCode();
        break;
        case zhuimian2:
        ui->widget_11->widget3_4_editDataToGCode();
        break;
        case zhuimian3:
        ui->widget_11->widget3_4_editDataToGCode();
        break;
        case zhuimian4:
        ui->widget_11->widget3_4_editDataToGCode();
        break;
        case luowen1:
        ui->widget_13->widget3_6_editDataToGCode();
        break;
        case luowen2:
        ui->widget_19->widget3_12_editDataToGCode();
        break;
        case luowen3:
        ui->widget_13->widget3_6_editDataToGCode();
        break;
        case luowen4:
        ui->widget_19->widget3_12_editDataToGCode();
        break;
        case daojiao1:
        ui->widget_14->widget3_7_editDataToGCode();
        break;
        case daojiao2:
        ui->widget_21->widget3_14_editDataToGCode();
        break;
        case daojiao3:
        ui->widget_14->widget3_7_editDataToGCode();
        break;
        case daojiao4:
        ui->widget_21->widget3_14_editDataToGCode();
        break;
        default:
        break;
    }
}

void Widget::paintEvent(QPaintEvent* event)
{
    //show_tipInfo();
}

void Widget::edit_input_slot(int index,QString str)
{
    ui->widget_2->pic_update(index,str);
}
