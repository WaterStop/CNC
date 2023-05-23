#include "widget.h"
#include "ui_widget.h"
#include "wedget1.h"
#include "ui_wedget1.h"
#include "baseset.h"
#include <QDebug>
#include "popupwin1.h"

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
    work_info_init();

    load_warnInfo();

    this->startTimer(100);

    connect(ui->bt_popwin,SIGNAL(clicked()),this,SLOT(show_wg_popwin_slot()));

    if(scr_size==0)
    {
        this->resize(800,600);
    }
    else if(scr_size==1)
    {
        this->resize(1024,768);
    }
//    qDebug()<<"id=2000 内容:"<<Warn_File_List[2000];
//    qDebug()<<"id=2001 内容:"<<Warn_File_List[2001];
//    qDebug()<<"id=2002 内容:"<<Warn_File_List[2002];
    //change_warn_text_slot();
    //motion_err->size = 1;
    //motion_err->data[0].id = 2;
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
    QFile file(":/new/File/warn.csv");
        if (file.open(QIODevice::ReadOnly /*| QIODevice::Text*/))
        {
            QString line;
            QTextStream in(&file);  //用文件构造流
            line = in.readLine();//读取一行放到字符串里
            //qDebug() << line;
            while(!line.isNull())//字符串有内容
            {
                load_warn_text(line);
                line=in.readLine();//循环读取下行
                //qDebug() << line;

            }
        }
        file.close();
}

void Widget::load_warn_text(QString str)//载入报警内容
{
    //static int warn_index = 0;
    QStringList strList = str.split(",",QString::SkipEmptyParts);
    Warn_File_List[strList[0].toInt()] = strList[1];
    //Warn_File_List[warn_index] = strList[1];
    //warn_index++;

}

void Widget::work_info_init()//初始化
{
    s_outerCircleMode1 tempTransver;
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
        ui->widget_9->setGeometry(682,505,310,213);
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

    connect(ui->widget_10, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_11, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_12, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_13, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_14, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_15, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_16, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_17, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_18, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_19, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_20, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));
    connect(ui->widget_21, SIGNAL(feed_fixval_signal()), ui->widget_23, SLOT(Deal_bt_val_slot()));

    connect(ui->widget_10, SIGNAL(feed_fixval_signal()),this, SLOT(show_fixval_slot()));
    connect(ui->widget_11, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_12, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_13, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_14, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_15, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_16, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_17, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_18, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_19, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_20, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));
    connect(ui->widget_21, SIGNAL(feed_fixval_signal()), this, SLOT(show_fixval_slot()));

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
    //connect(main_timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));

    connect(ui->widget_set, SIGNAL(back_signal()), this, SLOT(set_win_back_slot()));
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
    //ui->label_warn->setText("先帝创业未半而中道崩殂，今天下三分，益州疲弊，此诚危急存亡之秋也。然侍卫之臣不懈于内，忠志之士忘身于外者，盖追先帝之殊遇，欲报之于陛下也。");

    motion_err->size = 3;
    motion_err->data[0].id = 2000;
    motion_err->data[1].id = 2001;
    motion_err->data[2].id = 2002;
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
        ui->label_warn->setText("");
        tip_error->setText("");
    }
    else
    {
        //ui->label_warn->setStyleSheet("background-color:rgb(255, 0, 0);color:blue;border-width:0;border-style:outset;");
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
        if(refresh1==30)
        {
            refresh1=0;
        }
        if(refresh1 >= 1 && refresh1<24)//设置表头“报警(i/j):”
        {
            tip_error->setText("报警");
        }
        if(refresh1 >= 24)//把报警的位置空出来
        {
            tip_error->setText(" ");
        }
//        qDebug()<<"size="<<motion_warn->size;
//        qDebug()<<"id="<<motion_warn->data[warn_num].id;
//        qDebug()<<"内容："<<Warn_File_List[motion_warn->data[warn_num].id];
        if(motion_err->data[warn_num].id>=ErrorMaxNum)
        {
            return;
        }
        if(Warn_File_List[motion_err->data[warn_num].id]==NULL)
        {
            str = QString("(%1/%2):%3").arg(warn_num+1).arg(motion_err->size).arg("");
        }
        else
        {
            str = QString("(%1/%2):%3").arg(warn_num+1).arg(motion_err->size).arg(Warn_File_List[motion_err->data[warn_num].id]);
        }
        ui->label_warn->setText(str);
        //qDebug()<<str;
        //warn_num++;
    }

}

void Widget::Timer_on_slot()
{
    //qDebug()<<"Timer_on_slot";
    show_tipInfo();
}

void Widget::set_win_back_slot()
{
    screen_dis();
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

    ui->widget_1->input_work_pic();
    input_ok_flg = 1;
    luowen_set_flg = 0;
    modify_flg = 0;
    ui->widget_22->ClearEdit();
    //ui->widget_2->set_bt_sett();

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

    if(barstock_flg==1)
    {
        ui->widget_3->show();
        ui->widget_8->hide();
        ui->widget_9->show();
        return;
    }

    if (cur_work_mod==waiyuan1)
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
}


void Widget:: main_update_slot()//界面切换调用弹窗
{
    if(barstock_flg==1)
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
    //ui->widget_2->set_bt_sett();

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
        qDebug()<<"position_index="<<position_index;
        if(dealInterfaceData->m_mSeq.index.num==1&&position_index==1)
        {
            s_outerCircleMode1 tempTransver;
            machineNode *tem_val;
            //MachineProcess *dealInterfaceData = new MachineProcess(0,0,0,0);

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
        qDebug()<<"删除节点";
        ui->widget_1->input_work_pic();
        qDebug()<<"删除节点1";
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

void Widget::addWorkInfo(int index)//向工艺列表添加图标
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
    //emit edit_input_signal(index,str);
    ui->widget_2->pic_update(index,str);
}
