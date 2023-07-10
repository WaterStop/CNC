#include "widget2.h"
#include "ui_widget2.h"

static int work_mode = 0;
static int top_mode = 0;
static int pic_ischanged =0;//工艺图是否经过变换，0为否，1为是
static bool bar_pic = 0;//棒料工艺图是否可见 0：否 1：是

widget2::widget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget2)
{
    ui->setupUi(this);
    //set_wg2_background();
    Info_init();
    //set_wg2_button();
    show_wg2_popwin();
    DealSlot();
    ui->l_but->hide();
    clear_str_info();
    //processData = new MachineProcess(0,0,0,0);


}

widget2::~widget2()
{
    delete ui;
}

void widget2::set_wg2_background()
{
    //ui->label_bk->setPixmap(QPixmap(":/new/blue_pic/wg2_bk.png"));
//    setAutoFillBackground(true);//做子窗口要设置，否则不显示
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/blue_pic/wg2_bk.png")));
//    setPalette(pal);

    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg2_bk.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}

void widget2::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg2_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);


}

void widget2::Info_init()
{
    int i;
    for (i=0;i<9;i++)
    {
        bt_showindex[i] = new QPushButton(this);
        bt_showindex[i]->setGeometry(0,0,50,30);
        bt_showindex[i]->raise();
        bt_showindex[i]->hide();
        bt_showindex[i]->setStyleSheet("background:transparent;");
    }
    set_wg2_button();
    work_pic = new widget2_workpic(ui->frame);
    work_pic->setGeometry(100,100,400,320);
    work_pic->hide();
    bt_barpic = new QPushButton(ui->frame);
    bt_barpic->setGeometry(420,20,30,30);
    bt_barpic->setStyleSheet("background:transparent;");
    bt_barpic->setFocusPolicy(Qt::NoFocus);


}

void widget2::set_wg2_button()
{
    ui->l_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_l_bt.png);}");
    ui->knife_dir->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/knife_dir.png);}");
    work_mode = gui_ctl->current_mode;
    if(gui_ctl->request_g96==0)
    {
        ui->b_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt_off.png);}");

    }
    else if(gui_ctl->request_g96==1)
    {
        ui->b_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt_on.png);}");
    }
    set_wg2_t_button();
    set_wg2_b_button();

    if(scr_size==0)
    {
        ui->t_but->setGeometry(19,15,30,18);
        ui->t_but2->setGeometry(50,15,30,18);
        ui->t_but3->setGeometry(82,15,30,18);
        ui->t_but4->setGeometry(113,15,30,18);
        ui->t_but5->setGeometry(144,15,30,18);

        ui->l_but->setGeometry(5,187,25,57);

        ui->b_but->setGeometry(67,307,29,25);
        ui->b_but2->setGeometry(135,307,29,25);
        ui->b_but3->setGeometry(200,307,29,25);
        ui->b_but4->setGeometry(264,307,29,25);

        ui->widget->setGeometry(7,46,78,265);
    }
    else if(scr_size==1)
    {
        ui->t_but->setGeometry(22,20,25,25);
        ui->t_but2->setGeometry(65,20,25,25);
        ui->t_but3->setGeometry(105,20,25,25);
        ui->t_but4->setGeometry(152,20,25,25);
        ui->t_but5->setGeometry(192,20,25,25);
        ui->t_but6->setGeometry(235,20,25,25);


        ui->l_but->setGeometry(7,240,32,73);

        ui->b_but->setGeometry(90,393,38,32);
        ui->b_but2->setGeometry(140,393,38,32);
        ui->b_but3->setGeometry(190,393,38,32);
        ui->b_but4->setGeometry(240,393,38,32);

        ui->widget->setGeometry(10,60,100,340);
        ui->knife_dir->setGeometry(350,280,90,90);
    }

}

void widget2::DealSlot()
{
    connect(ui->b_but,SIGNAL(clicked()),this,SLOT(set_wg2_workmode_slot()));
    connect(ui->b_but2,SIGNAL(clicked()),this,SLOT(set_wg2_workmod1_slot()));
    connect(ui->b_but3,SIGNAL(clicked()),this,SLOT(set_wg2_workmode2_slot()));
    connect(ui->b_but4,SIGNAL(clicked()),this,SLOT(set_wg2_workmode3_slot()));
    connect(ui->l_but,SIGNAL(clicked()),this,SLOT(show_wg2_popwin_slot()));
//    connect(ui->t_but,SIGNAL(clicked()),this,SLOT(set_wg2_t_button_slot()));
//    connect(ui->t_but2,SIGNAL(clicked()),this,SLOT(set_wg2_t_button_slot1()));
//    connect(ui->t_but3,SIGNAL(clicked()),this,SLOT(set_wg2_t_button_slot2()));
//    connect(ui->t_but4,SIGNAL(clicked()),this,SLOT(set_wg2_t_button_slot3()));
//    connect(ui->t_but5,SIGNAL(clicked()),this,SLOT(set_wg2_t_button_slot4()));
//    connect(ui->t_but6,SIGNAL(clicked()),this,SLOT(set_wg2_t_button_slot5()));

    connect(bt_showindex[0],SIGNAL(clicked()),this,SLOT(jump_bt_slot()));
    connect(bt_showindex[1],SIGNAL(clicked()),this,SLOT(jump_bt_slot1()));
    connect(bt_showindex[2],SIGNAL(clicked()),this,SLOT(jump_bt_slot2()));
    connect(bt_showindex[3],SIGNAL(clicked()),this,SLOT(jump_bt_slot3()));
    connect(bt_showindex[4],SIGNAL(clicked()),this,SLOT(jump_bt_slot4()));
    connect(bt_showindex[5],SIGNAL(clicked()),this,SLOT(jump_bt_slot5()));
    connect(bt_showindex[6],SIGNAL(clicked()),this,SLOT(jump_bt_slot6()));
    connect(bt_showindex[7],SIGNAL(clicked()),this,SLOT(jump_bt_slot7()));
    connect(bt_showindex[8],SIGNAL(clicked()),this,SLOT(jump_bt_slot8()));

    connect(bt_barpic,SIGNAL(clicked()),this,SLOT(deal_barpic_slot()));


}

void widget2::set_wg2_workmode_slot()
{
    //work_mode = 0;
    //set_wg2_b_button();
    if(gui_ctl->request_g96==0)
    {
        gui_ctl->request_g96 = 1;
        ui->b_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt_on.png);}");

    }
    else if(gui_ctl->request_g96==1)
    {
        gui_ctl->request_g96 = 0;
        ui->b_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt_off.png);}");
    }

}

void widget2::set_wg2_workmod1_slot()//手动
{
    work_mode = 2;
    gui_ctl->current_mode = 2;
    set_wg2_b_button();
}
void widget2::set_wg2_workmode2_slot()//单循环
{
    work_mode = 1;
    gui_ctl->current_mode = 1;
    set_wg2_b_button();
}
void widget2::set_wg2_workmode3_slot()//自动
{
    work_mode = 0;
    gui_ctl->current_mode = 0;
    set_wg2_b_button();
}

void widget2::on_b_but2_clicked()
{
    //work_mode = 1;
    set_wg2_b_button();
}

void widget2::show_wg2_popwin()
{
    popupwin_flg = 0;
    ui->widget->hide();
    //ui->l_but->show();

}

void widget2::show_wg2_popwin_slot()
{
    popupwin_flg = 1-popupwin_flg;
    if(popupwin_flg)
    {
        ui->widget->show();
        //ui->l_but->hide();
    }
    else
    {
        ui->widget->hide();
        //ui->l_but->show();
    }
}


void widget2::jump_bt_slot()
{    
    emit page_jump_signal(0);
}

void widget2::jump_bt_slot1()
{    
    emit page_jump_signal(1);
}

void widget2::jump_bt_slot2()
{
    if(input_ok_flg==1)
    {
        emit page_jump_signal(2);
    }
}

void widget2::jump_bt_slot3()
{
    if(input_ok_flg==1)
    {
        emit page_jump_signal(3);
    }
}

void widget2::jump_bt_slot4()
{
    if(input_ok_flg==1)
    {
        emit page_jump_signal(4);
    }
}

void widget2::jump_bt_slot5()
{
    if(input_ok_flg==1)
    {
        emit page_jump_signal(5);
    }
}

void widget2::jump_bt_slot6()
{
    if(input_ok_flg==1)
    {
        emit page_jump_signal(6);
    }
}

void widget2::jump_bt_slot7()
{
    if(input_ok_flg==1)
    {
        emit page_jump_signal(7);
    }
}

void widget2::jump_bt_slot8()
{
    if(input_ok_flg==1)
    {
        emit page_jump_signal(8);
    }
}

void widget2::deal_barpic_slot()
{
    bar_pic = 1-bar_pic;
    if(bar_pic)
    {
        work_pic->show();
    }
    else
    {
        work_pic->hide();
    }
    update();
}

void widget2::set_wg2_b_button()
{
    //ui->b_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt_off.png);}");
    ui->b_but2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt2_off.png);}");
    ui->b_but3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt3_off.png);}");
    ui->b_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt4_off.png);}");

    switch(work_mode)
    {
        case 0:
        ui->b_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt4_on.png);}");
        break;
        case 1:
        ui->b_but3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt3_on.png);}");
        break;
        case 2:
        ui->b_but2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_b_bt2_on.png);}");
        break;
        default:
        break;
    }
}

void widget2::set_wg2_t_button()
{
    ui->t_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt.png);}");
    ui->t_but2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt2.png);}");
    ui->t_but3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt3.png);}");
    ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4.png);}");
    ui->t_but5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt5.png);}");
    ui->t_but6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt6.png);}");


    switch(top_mode)
    {
        case 1:
        ui->t_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt_on.png);}");
        break;
        case 2:
        ui->t_but2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt2_on.png);}");
        break;
        case 3:
        ui->t_but3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt3_on.png);}");
        break;
        case 4:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_on.png);}");
        break;
        case 5:
        ui->t_but5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt5_on.png);}");
        break;
        case 6:
        ui->t_but6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt6_on.png);}");
        break;
        default:
        break;
    }
}

void widget2::set_wg2_t_button_slot()
{
    top_mode = 1;
    set_wg2_t_button();
}

void widget2::set_wg2_t_button_slot1()
{
    top_mode = 2;
    set_wg2_t_button();
}

void widget2::set_wg2_t_button_slot2()
{
    top_mode = 3;
    set_wg2_t_button();
}

void widget2::set_wg2_t_button_slot3()
{
    top_mode = 4;
    set_wg2_t_button();
}

void widget2::set_wg2_t_button_slot4()
{
    top_mode = 5;
    set_wg2_t_button();
}

void widget2::set_wg2_t_button_slot5()
{
    top_mode = 6;
    set_wg2_t_button();
}

void widget2::set_wg2_t_button_slot6()
{
    top_mode = 7;
    set_wg2_t_button();
}
//bool widget2::eventFilter(QObject *watched, QEvent *event)
//{
//    if(((watched == ui->b_but)) && event->type() == QEvent::Paint)
//        {
//            magicTime();
//        }
//        return QWidget::eventFilter(watched,event);
//}

//void widget2::magicTime()
//{
//    ui->b_but->installEventFilter(this);
//    QPainter painter(ui->b_but);
//    painter.setPen(Qt::gray);
//    painter.setBrush(Qt::green);
//    painter.drawRect(0,0,10,10);

//    QPen pen;
//    pen.setColor(Qt::red);
//    painter.drawLine(0, 20, 0, 20);
//}

void widget2::DrawKnife()//刀具图，固定位置
{
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);

    painter.drawLine(350,310,375,320);
    pen.setWidth(10);
    int a,b,c,d,h;
    a=311;
    b=313;
    c=315;
    d=317;
    h=6;
    painter.drawLine(350,a,365,a+h);
    painter.drawLine(350,b,365,b+h);
    painter.drawLine(350,c,365,c+h);
    painter.drawLine(350,d,365,d+h);
    //painter.drawLine(350,322,360,329);
    pen.setWidth(2);
    painter.drawLine(350,310,350,325);
    painter.drawLine(350,325,355,327);
    painter.drawLine(355,327,375,320);
    painter.drawLine(355,327,355,360);
    painter.drawLine(375,320,375,360);
    painter.drawLine(355,360,375,360);
    painter.end();
}

void widget2::DrawKnife3(int x,int y)//刀具图，可设坐标值
{
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);

    pen.setWidth(10);
    int h;
    h=6;
    painter.drawLine(x,y+2,x+13,y+2+h);
    painter.drawLine(x,y+4,x+13,y+4+h);
    painter.drawLine(x,y+6,x+13,y+6+h);
    painter.drawLine(x,y+8,x+13,y+8+h);
    pen.setWidth(2);

    painter.drawLine(x,y,x,y+16);
    painter.drawLine(x,y+16,x+4,y+19);
    painter.drawLine(x+4,y+19,x+22,y+13);
    painter.drawLine(x+22,y+13,x,y);
    painter.drawLine(x+4,y+19,x+4,y+34);
    painter.drawLine(x+22,y+13,x+22,y+34);
    painter.drawLine(x+4,y+34,x+22,y+34);

    painter.end();
}

void widget2::DrawKnife1()//钻孔刀
{
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);

    pen.setWidth(10);
    pen.setWidth(1);
    painter.drawLine(330,210,340,200);
    painter.drawLine(330,210,340,220);
    painter.drawLine(340,200,345,200);
    painter.drawLine(340,200,340,210);
    painter.drawLine(340,220,360,220);
    painter.drawLine(340,210,355,220);
    painter.drawLine(340,200,370,220);
    painter.drawLine(340,200,345,200);
    painter.drawLine(370,220,375,220);
    painter.drawLine(345,200,375,220);
    painter.drawLine(360,220,365,215);
    painter.drawLine(350,205,355,200);
    painter.drawLine(355,200,375,200);
    painter.drawLine(375,200,375,220);
    painter.drawLine(360,200,375,210);

    painter.end();
}

void widget2::DrawKnife2(int x,int y)//横向刀
{
    int a;
    a = 2;
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);

//    painter.drawLine(320,210,345,185);
//    painter.drawLine(320,210,350,210);
//    painter.drawLine(350,210,355,208);
//    painter.drawLine(355,208,345,185);
//    painter.drawLine(345,185,385,185);
//    painter.drawLine(385,185,385,208);
//    painter.drawLine(385,208,345,208);
//    painter.drawLine(330,200,350,200);
//    painter.drawLine(328,202,347,202);
//    painter.drawLine(326,204,345,204);
//    painter.drawLine(324,206,343,206);
//    painter.drawLine(322,208,340,208);
//    painter.drawLine(320,210,337,210);

    painter.drawLine(x,y,x+13,y-23);
    painter.drawLine(x+13,y-23,x+44,y-23);
    painter.drawLine(x+44,y-23,x+44,y-4);
    painter.drawLine(x+44,y-4,x+18,y-4);
    painter.drawLine(x+18,y-4,x+16,y);
    painter.drawLine(x+16,y,x,y);
    painter.drawLine(x+12,y-19,x+18,y-4);
    painter.drawLine(x,y,x+8,y-13);
    painter.drawLine(x+a,y,x+8+a,y-13);
    painter.drawLine(x+2*a,y,x+8+2*a,y-13);
    painter.drawLine(x+3*a,y,x+8+3*a,y-13);
    painter.drawLine(x+4*a,y,x+8+4*a,y-13);

    painter.end();
}

void widget2::DrawKnife4(int x,int y)//端面2刀
{
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);

    painter.drawLine(x,y,x+10,y);
    painter.drawLine(x+10,y,x+10,y+15);
    painter.drawLine(x+10,y+15,x,y+15);
    painter.drawLine(x,y,x,y+40);
    painter.drawLine(x,y+40,x+19,y+40);
    painter.drawLine(x+19,y+40,x+19,y+15);
    painter.drawLine(x+19,y+15,x,y+15);
    painter.drawLine(x,y+2,x+10,y+2);
    painter.drawLine(x,y+4,x+10,y+4);
    painter.drawLine(x,y+6,x+10,y+6);
    painter.drawLine(x,y+8,x+10,y+8);
    painter.drawLine(x,y+10,x+10,y+10);
    painter.drawLine(x,y+12,x+10,y+12);
    painter.drawLine(x,y+14,x+10,y+14);


    painter.end();
}


void widget2::DrawWork1()
{
    QPainter painter;
    //QPixmap pixmap(":/new/blue_pic/wg2_bk.png");
    //painter.drawPixmap(rect(),pixmap,QRect());
    QPen pen,pen1,pen2;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);


    //painter.drawLine(0, 100, 0, 100);
    QRectF rectangle(57, 150, 25, 70);//
    int startAngle = 100 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 160 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(50, 220, 25, 70);
    int startAngle1 = 80 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -160 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(57, 220, 25, 70);
    int startAngle2 = 100 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 160 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(70,150,330,150);
    painter.drawLine(70,290,330,290);
    painter.drawLine(330,150,330,290);
    painter.drawLine(60,240,70,230);
    painter.drawLine(57,260,75,245);
    painter.drawLine(60,280,73,270);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(50,220,350,220);

    painter.setPen(pen2);
    painter.drawLine(70,135,330,135);
    painter.drawLine(70,135,70,150);
    painter.drawLine(330,135,330,150);
    painter.drawText(180,130,"L0=2000.000");
    painter.drawLine(345,150,345,290);
    painter.drawLine(330,150,345,150);
    painter.drawLine(330,290,345,290);
    QString rotateText = "D0=80.000";
    painter.translate(360, 240);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, rotateText);      // 第3步： 绘制文字
    painter.resetMatrix();                  // 第4步： 恢复坐标旋转

    //painter.drawLine(50,50,200,50);
    painter.end();
}

void widget2::DrawWaiYuan1()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);    
    //painter.setFont(weiruanyahei10);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 100, 40, 110);//
    int startAngle = 100 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 160 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(71, 210, 40, 110);
    int startAngle1 = 80 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -160 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 210, 40, 110);
    int startAngle2 = 100 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 160 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(95,100,130,100);
    painter.drawLine(95,320,130,320);
    painter.drawLine(130,100,130,320);
    painter.drawLine(130,190,300,190);
    painter.drawLine(130,230,300,230);
    painter.drawLine(300,190,300,230);
    painter.drawLine(82,230,100,220);
    painter.drawLine(77,270,108,255);
    painter.drawLine(85,310,105,300);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    painter.drawLine(135,235,305,235);
    painter.drawLine(135,235,135,325);
    pen4.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen4);
    painter.drawLine(135,325,305,325);
    painter.drawLine(305,235,305,325);
    pen4.setStyle(Qt::SolidLine);//实线
    pen4.setWidth(1);
    painter.setPen(pen4);
    //画箭头
    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(200,236);
    QPoint p0_2(205,231);
    QPoint p0_3(205,241);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(213,325);
    QPoint p1_2(208,320);
    QPoint p1_3(208,330);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(136,290);
    QPoint p2_2(131,285);
    QPoint p2_3(141,285);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(306,275);
    QPoint p3_2(301,280);
    QPoint p3_3(311,280);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);    
    painter.drawConvexPolygon(t0);//填充颜色
    painter.drawConvexPolygon(t1);

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(130,100,300,100);
    painter.drawLine(300,100,300,190);

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(300,80,300,95);
    painter.drawLine(130,87,300,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->outerCircle1.L);
    }
    else
    {
        //str = QString("L=%1").arg(0);
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(210,82,str);

    painter.drawLine(305,100,320,100);
    painter.drawLine(305,190,320,190);
    painter.drawLine(312,100,312,190);
    QString text_cr ;
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->outerCircle1.Cr);
    }
    else
    {
        //str = QString("Cr=%1").arg(0);
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(325, 145);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(305,315,320,315);
    painter.drawLine(305,325,320,325);
    painter.drawLine(312,315,312,325);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->outerCircle1.Tr);
    }
    else
    {
        //str = QString("Tr=%1").arg(0);
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(320, 313);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);
    QPoint p8_2(135,92);
    QPoint p8_3(135,82);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,87);
    QPoint p9_2(295,92);
    QPoint p9_3(295,82);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(312,100);
    QPoint p10_2(317,105);
    QPoint p10_3(307,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(312,190);
    QPoint p11_2(307,185);
    QPoint p11_3(317,185);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    painter.drawConvexPolygon(t8);//填充颜色

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    str = QString("D0=%1").arg(barstock_height);
    QString text_D0 = "D0=80.000";
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    //DrawKnife();
    DrawKnife3(305,328);
    //dealInterfaceData->barPaint(painter);

    painter.end();
}

void widget2::DrawWaiYuan2()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(90,100,125,100);
    painter.drawLine(90,320,125,320);
    painter.drawLine(125,100,125,320);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);
    painter.drawLine(125,100,315,155);
    painter.drawLine(125,320,315,265);
    painter.drawLine(315,155,315,265);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,335,210);

    painter.setPen(pen4);
    painter.drawLine(130,325,320,270);
    painter.drawLine(130,325,130,335);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(320,270,320,335);
    painter.drawLine(130,335,320,335);
    //画箭头
    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(209,303);
    QPoint p0_2(214,296);
    QPoint p0_3(218,306);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(130,335);
    QPoint p1_2(125,330);
    QPoint p1_3(135,330);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(320,300);
    QPoint p2_2(315,305);
    QPoint p2_3(325,305);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(240,335);
    QPoint p3_2(235,340);
    QPoint p3_3(235,330);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色
    painter.drawConvexPolygon(t1);

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(125,100,315,100);
    painter.drawLine(315,100,315,155);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(315,60,315,77);
    painter.drawLine(70,68,315,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(315,68);
    QPoint p5_2(310,63);
    QPoint p5_3(310,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(315,80,315,95);
    painter.drawLine(130,87,315,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->outerCircle2.L);
    }
    else
    {
        //str = QString("L=%1").arg(0);
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(215,82,str);

    //painter.drawLine(220,100,215,122);
    QRectF rectangle3(135, 65, 70, 70);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = -30 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(225,116,"A");

    painter.drawLine(320,100,335,100);
    painter.drawLine(320,155,335,155);
    painter.drawLine(327,100,327,155);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->outerCircle2.Cr);
    }
    else
    {
        //str = QString("Cr=%1").arg(0);
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(340, 140);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(320,325,335,325);
    painter.drawLine(320,335,335,335);
    painter.drawLine(327,325,327,335);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->outerCircle2.Tr);
    }
    else
    {
        //str = QString("Tr=%1").arg(0);
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(335, 323);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);
    QPoint p8_2(135,92);
    QPoint p8_3(135,82);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(315,87);
    QPoint p9_2(310,92);
    QPoint p9_3(310,82);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(327,100);
    QPoint p10_2(322,105);
    QPoint p10_3(332,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(327,155);
    QPoint p11_2(322,150);
    QPoint p11_3(332,150);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(322,335);

    painter.end();
}

void widget2::DrawWaiYuan3()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);

    painter.drawLine(90,100,220,100);
    painter.drawLine(90,320,220,320);
    painter.drawLine(220,100,220,320);
    painter.drawLine(300,150,300,280);
    QRectF rectangle3(215, -10, 165, 160);//
    int startAngle3 = 202 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = 68 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    QRectF rectangle14(210,280, 165, 160);
    int startAngle14 = 85 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle14 = 65 * 16;
    painter.drawArc(rectangle14, startAngle14, spanAngle14);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);


    painter.setPen(pen4);
    QRectF rectangle15(215,285, 160, 155);
    int startAngle15 = 85 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle15 = 65 * 16;
    painter.drawArc(rectangle15, startAngle15, spanAngle15);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(220,320,300,320);
    painter.drawLine(300,285,300,320);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(253,296);
    QPoint p0_2(259,287);
    QPoint p0_3(263,297);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(270,320);
    QPoint p1_2(265,315);
    QPoint p1_3(265,325);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(300,300);
    QPoint p2_2(305,305);
    QPoint p2_3(295,305);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    painter.drawConvexPolygon(t0);//填充颜色

    painter.setPen(pen5);
    painter.drawLine(220,100,300,100);
    painter.drawLine(300,150,300,100);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(220,80,220,95);
    painter.drawLine(300,80,300,95);
    painter.drawLine(220,87,300,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->outerCircle3.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(255,82,str);

    painter.drawLine(280,100,260,120);
    painter.drawLine(260,110,260,120);
    painter.drawLine(260,110,240,129);

    QString text_r = "R";
    painter.translate(270, 130);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-45);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, text_r);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(305,100,320,100);
    painter.drawLine(305,145,320,145);
    painter.drawLine(312,100,312,145);
    QString text_c = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->outerCircle3.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(325, 135);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(305,310,320,310);
    painter.drawLine(305,320,320,320);
    painter.drawLine(312,310,312,320);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->outerCircle3.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(320, 307);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(220,87);
    QPoint p8_2(225,92);
    QPoint p8_3(225,82);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,87);
    QPoint p9_2(295,92);
    QPoint p9_3(295,82);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(312,100);
    QPoint p10_2(317,105);
    QPoint p10_3(307,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(312,145);
    QPoint p11_2(317,140);
    QPoint p11_3(307,140);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(241,128);
    QPoint p12_2(245,117);
    QPoint p12_3(253,126);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(302,323);

    painter.end();
}

void widget2::DrawDuanMian1()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,200,100);
    painter.drawLine(95,320,200,320);
    painter.drawLine(200,100,200,320);
    painter.drawLine(200,180,250,180);
    painter.drawLine(200,240,250,240);
    painter.drawLine(250,180,250,240);

    painter.setPen(pen4);
    painter.drawLine(205,245,255,245);
    painter.drawLine(205,245,205,325);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(205,325,255,325);
    painter.drawLine(255,245,255,325);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(230,245);
    QPoint p0_2(225,240);
    QPoint p0_3(225,250);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(225,325);
    QPoint p1_2(230,330);
    QPoint p1_3(230,320);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(205,280);
    QPoint p2_2(200,285);
    QPoint p2_3(210,285);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(255,285);
    QPoint p3_2(250,280);
    QPoint p3_3(260,280);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(75,210,280,210);

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(200,100,250,100);
    painter.drawLine(250,100,250,180);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(250,60,250,77);
    painter.drawLine(70,68,250,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(140,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(250,68);
    QPoint p5_2(245,63);
    QPoint p5_3(245,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(205,80,205,95);
    painter.drawLine(250,80,250,95);
    painter.drawLine(205,87,250,87);
    if(val_change==0)
    {
        str = QString("CT=%1").arg(tem_val->endFace1.CT);
    }
    else
    {
        str = QString("CT=%1").arg(edit_str[3]);
    }
    painter.drawText(210,82,str);


    painter.drawLine(255,100,270,100);
    painter.drawLine(255,180,270,180);
    painter.drawLine(263,100,263,180);
    QString text_lr = "Lr";
    if(val_change==0)
    {
        str = QString("Lr=%1").arg(tem_val->endFace1.Lr);
    }
    else
    {
        str = QString("Lr=%1").arg(edit_str[0]);
    }
    painter.translate(275, 145);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    int t_y=15;
    painter.drawLine(245,325-t_y,245,335-t_y);
    painter.drawLine(255,325-t_y,255,335-t_y);
    painter.drawLine(245,330-t_y,255,330-t_y);
    if(val_change==0)
    {
        str = QString("△T=%1").arg(tem_val->endFace1.deltaT);
    }
    else
    {
        str = QString("△T=%1").arg(edit_str[1]);
    }
    painter.drawText(269,310,str);

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(205,87);
    QPoint p8_2(210,92);
    QPoint p8_3(210,82);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(250,87);
    QPoint p9_2(245,92);
    QPoint p9_3(245,82);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(263,100);
    QPoint p10_2(268,105);
    QPoint p10_3(258,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(263,180);
    QPoint p11_2(268,175);
    QPoint p11_3(258,175);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(245,330-t_y);
    QPoint p12_2(240,325-t_y);
    QPoint p12_3(240,335-t_y);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(255,330-t_y);
    QPoint p13_2(260,325-t_y);
    QPoint p13_3(260,335-t_y);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(254,325);

    painter.end();
}

void widget2::DrawDuanMian2()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,200,100);
    painter.drawLine(95,320,200,320);
    painter.drawLine(200,100,200,320);
    painter.drawLine(200,180,250,180);
    painter.drawLine(200,240,250,240);
    painter.drawLine(250,180,250,240);
    painter.drawLine(250,100,290,100);
    painter.drawLine(250,320,290,320);
    painter.drawLine(250,100,250,320);
    painter.drawLine(290,100,290,320);

    painter.setPen(pen4);
    painter.drawLine(205,245,245,245);
    painter.drawLine(205,245,205,325);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(205,325,245,325);
    painter.drawLine(245,245,245,325);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(205,265);
    QPoint p0_2(200,270);
    QPoint p0_3(210,270);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(205,285);
    QPoint p1_2(200,290);
    QPoint p1_3(210,290);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(245,270);
    QPoint p2_2(240,265);
    QPoint p2_3(250,265);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(245,290);
    QPoint p3_2(240,285);
    QPoint p3_3(250,285);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(75,210,280,210);

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(200,100,250,100);
    painter.drawLine(250,100,250,180);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(250,60,250,77);
    painter.drawLine(70,68,250,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(140,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(250,68);
    QPoint p5_2(245,63);
    QPoint p5_3(245,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(205,80,205,95);
    painter.drawLine(250,80,250,95);
    painter.drawLine(205,87,250,87);
    if(val_change==0)
    {
        str = QString("W=%1").arg(tem_val->endFace2.W);
    }
    else
    {
        str = QString("W=%1").arg(edit_str[3]);
    }
    painter.drawText(215,82,str);


    painter.drawLine(255,100,270,100);
    painter.drawLine(255,180,270,180);
    painter.drawLine(263,100,263,180);
    QString text_lr = "Lr";
    if(val_change==0)
    {
        str = QString("Lr=%1").arg(tem_val->endFace2.Lr);
    }
    else
    {
        str = QString("Lr=%1").arg(edit_str[0]);
    }
    painter.translate(275, 145);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(205,325,205,335);
    painter.drawLine(215,325,215,335);
    painter.drawLine(205,330,215,330);
    painter.drawText(185,340,"Tw");

    painter.drawLine(205,315,215,315);
    painter.drawLine(205,325,215,325);
    painter.drawLine(210,315,210,325);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->endFace2.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(220, 310);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(205,87);
    QPoint p8_2(210,92);
    QPoint p8_3(210,82);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(250,87);
    QPoint p9_2(245,92);
    QPoint p9_3(245,82);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(263,100);
    QPoint p10_2(268,105);
    QPoint p10_3(258,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(263,180);
    QPoint p11_2(268,175);
    QPoint p11_3(258,175);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife3(220,330);
    DrawKnife4(205,330);

    painter.end();
}

void widget2::DrawDuanMian3()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    painter.drawLine(95,100,300,100);
    painter.drawLine(95,320,300,320);
    painter.drawLine(95,100,95,320);
    painter.drawLine(300,100,300,320);
    painter.drawLine(200,130,300,130);
    painter.drawLine(200,130,200,290);
    painter.drawLine(200,290,300,290);

    painter.drawLine(95,120,120,100);
    painter.drawLine(95,150,150,100);
    painter.drawLine(95,180,180,100);
    painter.drawLine(95,210,210,100);
    painter.drawLine(95,240,200,135);
    painter.drawLine(95,270,200,165);
    painter.drawLine(95,300,200,195);
    painter.drawLine(115,320,200,235);
    painter.drawLine(150,320,200,270);
    painter.drawLine(200,320,230,290);
    painter.drawLine(240,320,265,290);
    painter.drawLine(220,130,250,100);
    painter.drawLine(250,130,280,100);
    painter.drawLine(280,130,300,110);

    painter.setPen(pen4);
    painter.drawLine(205,215,295,215);
    painter.drawLine(205,215,205,285);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(295,285,295,215);
    painter.drawLine(295,285,205,285);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(245,215);
    QPoint p0_2(250,210);
    QPoint p0_3(252,220);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(250,285);
    QPoint p1_2(245,290);
    QPoint p1_3(245,280);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(205,255);
    QPoint p2_2(210,250);
    QPoint p2_3(200,250);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(295,250);
    QPoint p3_2(290,255);
    QPoint p3_3(300,255);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(75,210,310,210);

    painter.setPen(pen2);
    painter.drawLine(95,60,95,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(95,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(160,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(95,68);
    QPoint p4_2(100,63);
    QPoint p4_3(100,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(205,160,205,170);
    painter.drawLine(295,160,295,170);
    painter.drawLine(205,165,295,165);
    if(val_change==0)
    {
        str = QString("CT=%1").arg(tem_val->endFace3.CT);
    }
    else
    {
        str = QString("CT=%1").arg(edit_str[3]);
    }
    painter.drawText(240,180,str);

    painter.drawLine(320,210,330,210);
    painter.drawLine(320,290,330,290);
    painter.drawLine(325,210,325,290);
    QString text_lr = "Lr";
    if(val_change==0)
    {
        str = QString("Lr=%1").arg(tem_val->endFace3.Lr);
    }
    else
    {
        str = QString("Lr=%1").arg(edit_str[0]);
    }
    painter.translate(340, 250);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(285,220,285,230);
    painter.drawLine(295,220,295,230);
    painter.drawLine(285,225,295,225);
    if(val_change==0)
    {
        str = QString("△T=%1").arg(tem_val->endFace3.deltaT);
    }
    else
    {
        str = QString("△T=%1").arg(edit_str[1]);
    }
    painter.drawText(255,240,str);

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(205,165);
    QPoint p8_2(210,160);
    QPoint p8_3(210,170);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(295,165);
    QPoint p9_2(290,160);
    QPoint p9_3(290,170);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(325,210);
    QPoint p10_2(320,215);
    QPoint p10_3(330,215);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(325,290);
    QPoint p11_2(320,285);
    QPoint p11_3(330,285);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(285,225);
    QPoint p12_2(280,220);
    QPoint p12_3(280,230);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(295,225);
    QPoint p13_2(300,220);
    QPoint p13_3(300,230);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(295,215);

    painter.end();
}

void widget2::DrawLiKong1()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,120,100);
    painter.drawLine(95,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(120,100,300,100);
    painter.drawLine(120,320,300,320);
    painter.drawLine(120,130,300,130);
    painter.drawLine(120,290,300,290);
    painter.drawLine(300,100,300,320);
    painter.drawLine(150,100,120,130);
    painter.drawLine(190,100,160,130);
    painter.drawLine(230,100,200,130);
    painter.drawLine(270,100,240,130);
    painter.drawLine(300,100,270,130);
    painter.drawLine(150,290,120,320);
    painter.drawLine(190,290,160,320);
    painter.drawLine(230,290,200,320);
    painter.drawLine(270,290,240,320);
    painter.drawLine(300,290,270,320);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    painter.drawLine(125,285,305,285);
    painter.drawLine(125,240,125,285);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(125,240,305,240);
    painter.drawLine(305,240,305,285);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(215,240);
    QPoint p0_2(210,235);
    QPoint p0_3(210,245);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(210,285);
    QPoint p1_2(215,290);
    QPoint p1_3(215,280);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(125,260);
    QPoint p2_2(120,265);
    QPoint p2_3(130,265);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(305,265);
    QPoint p3_2(300,260);
    QPoint p3_3(310,260);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(130,180,300,180);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(120,80,120,95);
    painter.drawLine(300,80,300,95);
    painter.drawLine(120,87,300,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->innerHole1.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(210,82,str);


    painter.drawLine(305,130,320,130);
    painter.drawLine(305,180,320,180);
    painter.drawLine(312,130,312,180);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->innerHole1.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(325, 128);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    int a=15;
    painter.drawLine(305-a,240,320-a,240);
    painter.drawLine(305-a,250,320-a,250);
    painter.drawLine(312-a,240,312-a,250);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->innerHole1.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(290-a, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(120,87);
    QPoint p8_2(125,82);
    QPoint p8_3(125,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,87);
    QPoint p9_2(295,82);
    QPoint p9_3(295,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(312,130);
    QPoint p10_2(317,135);
    QPoint p10_3(307,135);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(312,180);
    QPoint p11_2(317,175);
    QPoint p11_3(307,175);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(312-a,240);
    QPoint p12_2(317-a,235);
    QPoint p12_3(307-a,235);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(312-a,250);
    QPoint p13_2(317-a,255);
    QPoint p13_3(307-a,255);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(305,240);

    painter.end();
}

void widget2::DrawLiKong2()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,120,100);
    painter.drawLine(95,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(120,100,300,100);
    painter.drawLine(120,320,300,320);
    painter.drawLine(120,170,300,130);
    painter.drawLine(120,250,300,290);
    painter.drawLine(300,100,300,320);

    painter.drawLine(120,120,145,100);
    painter.drawLine(120,150,160,100);
    painter.drawLine(150,164,180,100);
    painter.drawLine(180,157,210,100);
    painter.drawLine(210,150,240,100);
    painter.drawLine(240,143,270,100);
    painter.drawLine(270,136,300,100);
    painter.drawLine(120,270,130,254);
    painter.drawLine(120,300,170,263);
    painter.drawLine(140,320,190,268);
    painter.drawLine(180,320,220,273);
    painter.drawLine(210,320,240,278);
    painter.drawLine(240,320,270,283);
    painter.drawLine(270,320,300,290);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    painter.drawLine(125,245,305,285);
    painter.drawLine(125,240,125,245);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(125,240,305,240);
    painter.drawLine(305,240,305,285);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(215,240);
    QPoint p0_2(210,235);
    QPoint p0_3(210,245);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(213,264);
    QPoint p1_2(222,260);
    QPoint p1_3(219,274);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p3_1(305,265);
    QPoint p3_2(300,260);
    QPoint p3_3(310,260);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(130,180,300,180);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(120,80,120,95);
    painter.drawLine(300,80,300,95);
    painter.drawLine(120,87,300,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->innerHole2.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(210,82,str);


    painter.drawLine(305,130,320,130);
    painter.drawLine(305,180,320,180);
    painter.drawLine(312,130,312,180);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->innerHole2.L);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(325, 128);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    int a=15;
    painter.drawLine(305-a,240,320-a,240);
    painter.drawLine(305-a,250,320-a,250);
    painter.drawLine(312-a,240,312-a,250);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->innerHole2.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(310, 225);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    //painter.drawLine(250,145,255,180);
    QRectF rectangle3(170, 140, 80, 80);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = 60 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(260,165,"A");

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(120,87);//
    QPoint p8_2(125,82);
    QPoint p8_3(125,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,87);
    QPoint p9_2(295,82);
    QPoint p9_3(295,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);//
    QPoint p10_1(312,130);
    QPoint p10_2(317,135);
    QPoint p10_3(307,135);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(312,180);
    QPoint p11_2(317,175);
    QPoint p11_3(307,175);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);//
    QPoint p12_1(312-a,240);
    QPoint p12_2(317-a,235);
    QPoint p12_3(307-a,235);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(312-a,250);
    QPoint p13_2(317-a,255);
    QPoint p13_3(307-a,255);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(321-a,240);

    painter.end();
}

void widget2::DrawLiKong3()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,120,100);
    painter.drawLine(95,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(120,100,300,100);
    painter.drawLine(120,320,300,320);
    painter.drawLine(300,100,300,320);
    painter.drawLine(120,150,210,150);
    painter.drawLine(120,270,210,270);
    painter.drawLine(260,150,300,150);
    painter.drawLine(260,270,300,270);

    painter.drawLine(210,130,260,130);
    painter.drawLine(210,290,260,290);
    painter.drawLine(210,130,210,290);
    painter.drawLine(260,130,260,290);

    painter.drawLine(120,110,130,100);
    painter.drawLine(120,130,150,100);
    painter.drawLine(120,150,170,100);
    painter.drawLine(150,150,200,100);
    painter.drawLine(180,150,230,100);
    painter.drawLine(230,130,260,100);
    painter.drawLine(260,150,300,100);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    painter.drawLine(215,240,215,285);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(215,240,305,240);
    painter.drawLine(255,265,255,285);
    painter.drawLine(215,285,255,285);
    painter.drawLine(305,240,305,265);
    painter.drawLine(255,265,305,265);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(275,240);
    QPoint p0_2(280,235);
    QPoint p0_3(280,245);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(280,265);
    QPoint p1_2(275,260);
    QPoint p1_3(275,270);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(255,275);
    QPoint p2_2(250,280);
    QPoint p2_3(260,280);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(215,280);
    QPoint p3_2(210,275);
    QPoint p3_3(220,275);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(210,80,210,130);
    painter.drawLine(260,80,260,130);
    painter.drawLine(210,87,300,87);
    if(val_change==0)
    {
        str = QString("W=%1").arg(tem_val->innerHole3.W);
    }
    else
    {
        str = QString("W=%1").arg(edit_str[3]);
    }
    painter.drawText(220,82,str);
    painter.drawLine(300,80,300,95);
    if(val_change==0)
    {
        str = QString("W1=%1").arg(tem_val->innerHole3.W1);
    }
    else
    {
        str = QString("W1=%1").arg(edit_str[4]);
    }
    painter.drawText(265,82,str);


    painter.drawLine(260,130,320,130);
    painter.drawLine(305,150,320,150);
    painter.drawLine(312,130,312,150);
    QString text_cr = "Lr";
    if(val_change==0)
    {
        str = QString("Lr=%1").arg(tem_val->innerHole3.Lr);
    }
    else
    {
        str = QString("Lr=%1").arg(edit_str[0]);
    }
    painter.translate(325, 128);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(305,270,320,270);
    painter.drawLine(305,280,320,280);
    painter.drawLine(312,270,312,280);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->innerHole3.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(330, 305);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

//    painter.drawLine(315,255,315,265);
//    painter.drawLine(325,255,325,265);
    painter.drawLine(305,250,335,250);
    if(val_change==0)
    {
        str = QString("Tw=%1").arg(tem_val->innerHole3.Tw);
    }
    else
    {
        str = QString("Tw=%1").arg(edit_str[5]);
    }
    painter.drawText(335,260,str);

    QPolygon t8,t9,t10,t11,t12,t13,t15,t16,t17,t18;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(210,87);//
    QPoint p8_2(215,82);
    QPoint p8_3(215,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(260,87);
    QPoint p9_2(255,82);
    QPoint p9_3(255,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(260,87);//
    QPoint p10_2(265,82);
    QPoint p10_3(265,92);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(300,87);
    QPoint p11_2(295,82);
    QPoint p11_3(295,92);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(312,130);//
    QPoint p12_2(317,135);
    QPoint p12_3(307,135);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(312,150);
    QPoint p13_2(317,145);
    QPoint p13_3(307,145);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);

    QPoint p15_1(315,250);//
    QPoint p15_2(310,245);
    QPoint p15_3(310,255);
    t15<<p15_1<<p15_2<<p15_3;
    painter.drawPolygon(t15);
    QPoint p16_1(325,250);
    QPoint p16_2(330,255);
    QPoint p16_3(330,245);
    t16<<p16_1<<p16_2<<p16_3;
    painter.drawPolygon(t16);

    QPoint p17_1(312,270);//
    QPoint p17_2(317,265);
    QPoint p17_3(307,265);
    t17<<p17_1<<p17_2<<p17_3;
    painter.drawPolygon(t17);
    QPoint p18_1(312,280);
    QPoint p18_2(317,285);
    QPoint p18_3(307,285);
    t18<<p18_1<<p18_2<<p18_3;
    painter.drawPolygon(t18);
    painter.drawConvexPolygon(t8);//填充颜色

    //painter.setPen(pen);
    //painter.drawLine(305,240,305,265);
//    painter.drawLine(315,240,315,265);
//    painter.drawLine(325,240,325,265);
//    painter.drawLine(315,240,325,240);
//    painter.drawLine(315,265,325,265);

    QPolygon t14;
    painter.setBrush(Qt::white);

    QPoint p14_1(315,240);//
    QPoint p14_2(315,265);
    QPoint p14_3(325,265);
    QPoint p14_4(325,240);
    t14<<p14_1<<p14_2<<p14_3<<p14_4;
    painter.drawPolygon(t14);


    DrawKnife2(315,240);

    painter.end();
}

void widget2::DrawLiKong4()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,120,100);
    painter.drawLine(95,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(120,100,300,100);
    painter.drawLine(120,320,300,320);
    painter.drawLine(120,180,225,180);
    painter.drawLine(120,240,225,240);
    painter.drawLine(300,100,300,320);

    QRectF rectangle3(140, 20, 160, 160);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = -90 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    QRectF rectangle4(140, 240, 160, 160);//
    int startAngle4 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle4 = 90 * 16;
    painter.drawArc(rectangle4, startAngle4, spanAngle4);

    painter.drawLine(120,115,135,100);
    painter.drawLine(120,135,150,100);
    painter.drawLine(120,160,180,100);
    painter.drawLine(135,180,210,100);
    painter.drawLine(165,180,240,100);
    painter.drawLine(195,180,270,100);
    painter.drawLine(225,180,300,100);//
    painter.drawLine(120,260,135,240);
    painter.drawLine(120,285,155,240);
    painter.drawLine(120,310,180,240);
    painter.drawLine(150,320,210,240);
    painter.drawLine(180,320,240,243);
    painter.drawLine(210,320,270,258);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    QRectF rectangle5(145, 235, 160, 160);//
    int startAngle5 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle5 = 90 * 16;
    painter.drawArc(rectangle5, startAngle5, spanAngle5);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(245,235,305,235);
    painter.drawLine(305,235,305,320);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(280,235);
    QPoint p0_2(275,230);
    QPoint p0_3(275,240);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(305,275);
    QPoint p1_2(300,270);
    QPoint p1_3(310,270);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(280,258);
    QPoint p2_2(288,258);
    QPoint p2_3(280,266);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    painter.drawConvexPolygon(t0);//填充颜色

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(240,80,240,177);
    painter.drawLine(300,80,300,95);
    painter.drawLine(240,87,300,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->innerHole4.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(260,82,str);


    painter.drawLine(305,100,320,100);
    painter.drawLine(240,180,320,180);
    painter.drawLine(312,100,312,180);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->innerHole4.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(325, 150);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(270,160,280,170);
    painter.drawLine(270,170,280,170);
    painter.drawLine(270,170,280,180);
    QString text_r = "R";
    painter.translate(285, 165);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-45);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, text_r);      // 第3步： 绘制文字
    painter.resetMatrix();

    int a = 15;
    painter.drawLine(305-a,235,320-a,235);
    painter.drawLine(305-a,245,320-a,245);
    painter.drawLine(312-a,235,312-a,245);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->innerHole4.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(290, 225);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(240,87);//
    QPoint p8_2(245,82);
    QPoint p8_3(245,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,87);
    QPoint p9_2(295,82);
    QPoint p9_3(295,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(312,100);//
    QPoint p10_2(317,105);
    QPoint p10_3(307,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(312,180);
    QPoint p11_2(317,175);
    QPoint p11_3(307,175);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(312-a,235);//
    QPoint p12_2(317-a,230);
    QPoint p12_3(307-a,230);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(312-a,245);
    QPoint p13_2(317-a,250);
    QPoint p13_3(307-a,250);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(320-a,235);


    painter.end();
}

void widget2::DrawLiKong5()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,120,100);
    painter.drawLine(95,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(120,100,300,100);
    painter.drawLine(120,320,300,320);
    painter.drawLine(300,100,300,320);

    painter.drawLine(220,180,300,180);
    painter.drawLine(220,240,300,240);
    painter.drawLine(200,210,220,180);
    painter.drawLine(200,210,220,240);

    painter.drawLine(120,130,150,100);
    painter.drawLine(120,160,180,100);
    painter.drawLine(120,190,210,100);
    painter.drawLine(120,220,240,100);
    painter.drawLine(120,250,270,100);
    painter.drawLine(120,280,300,100);
    painter.drawLine(120,310,210,230);
    painter.drawLine(150,320,235,240);
    painter.drawLine(180,320,265,240);
    painter.drawLine(210,320,295,240);
    painter.drawLine(240,320,300,270);
    painter.drawLine(260,180,300,140);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    painter.drawLine(217,185,300,185);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(217,235,300,235);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(240,185);
    QPoint p0_2(245,180);
    QPoint p0_3(245,190);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(275,185);
    QPoint p1_2(280,180);
    QPoint p1_3(280,190);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(245,235);
    QPoint p2_2(240,230);
    QPoint p2_3(240,240);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(280,235);
    QPoint p3_2(275,230);
    QPoint p3_3(275,240);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, text_D0);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(220,80,220,180);
    painter.drawLine(300,80,300,95);
    painter.drawLine(220,87,300,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->innerHole5.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(260,82,str);


    painter.drawLine(280,170,280,180);
    painter.drawLine(298,170,298,180);
    painter.drawLine(280,175,298,175);
    if(val_change==0)
    {
        str = QString("△T=%1").arg(tem_val->innerHole5.deltaT);
    }
    else
    {
        str = QString("△T=%1").arg(edit_str[1]);
    }
    painter.drawText(310,180,str);

    painter.drawLine(305,240,305,250);
    painter.drawLine(320,240,320,250);
    painter.drawLine(305,245,320,245);
    if(val_change==0)
    {
        str = QString("BT=%1").arg(tem_val->innerHole5.BT);
    }
    else
    {
        str = QString("BT=%1").arg(edit_str[3]);
    }
    painter.drawText(330,250,str);

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(220,87);//
    QPoint p8_2(225,82);
    QPoint p8_3(225,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,87);
    QPoint p9_2(295,82);
    QPoint p9_3(295,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(280,175);//
    QPoint p10_2(275,170);
    QPoint p10_3(275,180);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(300,175);
    QPoint p11_2(305,170);
    QPoint p11_3(305,180);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(305,245);//
    QPoint p12_2(300,250);
    QPoint p12_3(300,240);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(320,245);
    QPoint p13_2(325,250);
    QPoint p13_3(325,240);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife1();

    painter.end();
}

void widget2::DrawZhuiMian2()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(90,100,125,100);
    painter.drawLine(90,320,125,320);
    painter.drawLine(125,100,125,320);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);

    painter.drawLine(125,170,315,100);
    painter.drawLine(125,250,315,320);
    painter.drawLine(315,100,315,320);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,335,210);

    painter.setPen(pen4);
    painter.drawLine(130,335,320,335);
    painter.drawLine(130,260,130,335);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(320,325,320,335);
    painter.drawLine(130,260,320,330);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(225,293);
    QPoint p0_2(221,285);
    QPoint p0_3(219,300);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(130,295);
    QPoint p1_2(135,300);
    QPoint p1_3(125,300);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(220,335);
    QPoint p2_2(225,330);
    QPoint p2_3(225,340);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(125,100,315,100);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(315,60,315,77);
    painter.drawLine(70,68,315,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(315,68);
    QPoint p5_2(310,63);
    QPoint p5_3(310,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(315,80,315,95);
    painter.drawLine(130,87,315,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->coneFace2.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(215,82,str);

    //painter.drawLine(240,100,235,125);
    QRectF rectangle3(250, 65, 70, 70);//
    int startAngle3 = 180 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = 30 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(225,116,"A");

    painter.drawLine(110,100,125,100);
    painter.drawLine(110,170,125,170);
    painter.drawLine(117,100,117,170);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->coneFace2.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(105, 145);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(320,325,335,325);
    painter.drawLine(320,335,335,335);
    painter.drawLine(327,325,327,335);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->coneFace2.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(335, 315);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);//
    QPoint p8_2(135,82);
    QPoint p8_3(135,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(315,87);
    QPoint p9_2(310,82);
    QPoint p9_3(310,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(117,100);//
    QPoint p10_2(112,105);
    QPoint p10_3(122,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(117,170);
    QPoint p11_2(112,165);
    QPoint p11_3(122,165);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(327,325);//
    QPoint p12_2(322,320);
    QPoint p12_3(332,320);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(327,335);
    QPoint p13_2(322,340);
    QPoint p13_3(332,340);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(320,335);

    painter.end();
}

void widget2::DrawZhuiMian3()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(90,100,125,100);
    painter.drawLine(90,320,125,320);
    painter.drawLine(125,100,125,320);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);
    painter.drawLine(125,100,315,155);
    painter.drawLine(125,320,315,265);
    painter.drawLine(315,155,315,265);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,335,210);

    painter.setPen(pen4);
    painter.drawLine(130,325,320,270);
    painter.drawLine(130,325,130,345);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(320,270,320,290);
    painter.drawLine(130,345,320,290);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(220,300);
    QPoint p0_2(222,291);
    QPoint p0_3(227,304);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(232,315);
    QPoint p1_2(223,312);
    QPoint p1_3(227,325);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(130,335);
    QPoint p2_2(125,330);
    QPoint p2_3(135,330);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(320,280);
    QPoint p3_2(315,285);
    QPoint p3_3(325,285);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(125,100,315,100);
    painter.drawLine(315,100,315,155);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(315,60,315,77);
    painter.drawLine(70,68,315,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(315,68);
    QPoint p5_2(310,63);
    QPoint p5_3(310,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(315,80,315,95);
    painter.drawLine(130,87,315,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->coneFace3.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(215,82,str);

    //painter.drawLine(220,100,215,122);
    QRectF rectangle3(135, 65, 70, 70);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = -30 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(225,116,"A");

    painter.drawLine(320,100,335,100);
    painter.drawLine(320,155,335,155);
    painter.drawLine(327,100,327,155);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->coneFace3.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(340, 140);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(325,280,340,280);
    painter.drawLine(325,290,340,290);
    painter.drawLine(332,280,332,290);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->coneFace3.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(335, 270);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);//
    QPoint p8_2(135,82);
    QPoint p8_3(135,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(315,87);
    QPoint p9_2(310,82);
    QPoint p9_3(310,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(327,100);//
    QPoint p10_2(322,105);
    QPoint p10_3(332,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(327,155);
    QPoint p11_2(322,150);
    QPoint p11_3(332,150);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(332,280);//
    QPoint p12_2(337,275);
    QPoint p12_3(327,275);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(332,290);
    QPoint p13_2(337,295);
    QPoint p13_3(327,295);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(320,295);

    painter.end();
}

void widget2::DrawZhuiMian4()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(90,100,125,100);
    painter.drawLine(90,320,125,320);
    painter.drawLine(125,100,125,320);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);

    painter.drawLine(125,170,315,100);
    painter.drawLine(125,250,315,320);
    painter.drawLine(315,100,315,320);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,335,210);

    painter.setPen(pen4);
    painter.drawLine(130,260,320,330);
    painter.drawLine(130,260,130,280);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(320,330,320,350);
    painter.drawLine(130,280,320,350);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(213,291);
    QPoint p0_2(222,286);
    QPoint p0_3(217,299);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(212,311);
    QPoint p1_2(211,300);
    QPoint p1_3(204,316);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(130,275);
    QPoint p2_2(125,270);
    QPoint p2_3(135,270);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(320,335);
    QPoint p3_2(315,340);
    QPoint p3_3(325,340);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(125,100,315,100);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(315,60,315,77);
    painter.drawLine(70,68,315,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(315,68);
    QPoint p5_2(310,63);
    QPoint p5_3(310,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(315,80,315,95);
    painter.drawLine(130,87,315,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->coneFace4.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(215,82,str);

    //painter.drawLine(240,100,235,125);
    QRectF rectangle3(250, 65, 70, 70);//
    int startAngle3 = 180 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = 30 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(225,116,"A");

    painter.drawLine(110,100,125,100);
    painter.drawLine(110,170,125,170);
    painter.drawLine(117,100,117,170);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->coneFace4.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(105, 150);          // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    int a = -5;
    painter.drawLine(320,325-a,335,325-a);
    painter.drawLine(320,335-a,335,335-a);
    painter.drawLine(327,325-a,327,335-a);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->coneFace4.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(335, 317);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);//
    QPoint p8_2(135,82);
    QPoint p8_3(135,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(315,87);
    QPoint p9_2(310,82);
    QPoint p9_3(310,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(117,100);//
    QPoint p10_2(112,105);
    QPoint p10_3(122,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(117,170);
    QPoint p11_2(112,165);
    QPoint p11_3(122,165);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(327,325-a);//
    QPoint p12_2(322,320-a);
    QPoint p12_3(332,320-a);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(327,335-a);
    QPoint p13_2(322,340-a);
    QPoint p13_3(332,340-a);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(320,350);

    painter.end();
}

void widget2::DrawLuoWen1()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(79, 129, 30, 70);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(67,195, 30, 70);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(78, 195, 30, 70);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(78,220,95,210);
    painter.drawLine(80,240,97,230);
    painter.drawLine(85,255,95,245);

    painter.drawLine(88,133,120,133);
    painter.drawLine(88,265,120,265);
    painter.drawLine(120,135,120,265);

    painter.drawLine(120,133,135,163);
    painter.drawLine(135,163,150,133);
    painter.drawLine(150,133,165,163);
    painter.drawLine(165,163,180,133);
    painter.drawLine(180,133,195,163);
    painter.drawLine(195,163,210,133);
    painter.drawLine(210,133,225,163);
    painter.drawLine(225,163,240,133);
    painter.drawLine(240,133,255,163);
    painter.drawLine(255,163,270,133);
    painter.drawLine(270,133,285,163);
    painter.drawLine(120,265,135,265);
    painter.drawLine(135,265,150,235);
    painter.drawLine(150,235,165,265);
    painter.drawLine(165,265,180,235);
    painter.drawLine(180,235,195,265);
    painter.drawLine(195,265,210,235);
    painter.drawLine(210,235,225,265);
    painter.drawLine(225,265,240,235);
    painter.drawLine(240,235,255,265);
    painter.drawLine(255,265,270,235);
    painter.drawLine(270,235,285,265);
    painter.drawLine(285,163,285,265);

    painter.drawLine(135,163,150,235);
    painter.drawLine(165,163,180,235);
    painter.drawLine(195,163,210,235);
    painter.drawLine(225,163,240,235);
    painter.drawLine(255,163,270,235);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(75,198,300,198);

    painter.setPen(pen4);
    painter.drawLine(125,270,290,270);
    painter.drawLine(125,270,125,305);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(125,305,290,305);
    painter.drawLine(290,270,290,305);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(200,270);
    QPoint p0_2(205,275);
    QPoint p0_3(205,265);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(205,305);
    QPoint p1_2(200,310);
    QPoint p1_3(200,300);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(125,290);
    QPoint p2_2(120,285);
    QPoint p2_3(120,295);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(290,285);
    QPoint p3_2(285,290);
    QPoint p3_3(295,290);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(120,133,285,133);

    painter.setPen(pen2);
    painter.drawLine(80,85,80,95);
    painter.drawLine(285,85,285,95);
    painter.drawLine(80,90,285,90);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,80,str);

    painter.drawLine(60,133,75,133);
    painter.drawLine(60,265,75,265);
    painter.drawLine(67,133,67,265);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(80,90);
    QPoint p4_2(85,85);
    QPoint p4_3(85,95);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(285,90);
    QPoint p5_2(280,85);
    QPoint p5_3(280,95);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,133);
    QPoint p6_2(62,138);
    QPoint p6_3(72,138);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,265);
    QPoint p7_2(62,260);
    QPoint p7_3(72,260);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(120,107,120,133);
    painter.drawLine(285,107,285,163);
    painter.drawLine(120,107,285,107);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->screwThread1.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(210,105,str);

    painter.drawLine(210,120,210,133);
    painter.drawLine(240,120,240,133);
    painter.drawLine(210,120,240,120);
    if(val_change==0)
    {
        str = QString("Tp=%1").arg(tem_val->screwThread1.Tp);
    }
    else
    {
        str = QString("Tp=%1").arg(edit_str[4]);
    }
    painter.drawText(220,117,str);

    painter.drawLine(295,305,310,305);
    painter.drawLine(295,285,310,285);
    painter.drawLine(300,285,300,305);
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->screwThread1.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(320,305);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(285,133,295,133);
    painter.drawLine(285,163,295,163);
    painter.drawLine(295,133,295,163);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->screwThread1.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(310, 158);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(120,107);//
    QPoint p8_2(125,102);
    QPoint p8_3(125,112);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(285,107);
    QPoint p9_2(280,102);
    QPoint p9_3(280,112);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(210,120);//
    QPoint p10_2(215,115);
    QPoint p10_3(215,125);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(240,120);
    QPoint p11_2(235,125);
    QPoint p11_3(235,115);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(295,133);//
    QPoint p12_2(290,128);
    QPoint p12_3(300,128);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(295,163);
    QPoint p13_2(300,168);
    QPoint p13_3(290,168);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(293,308);


    painter.end();
}

void widget2::DrawLuoWen2()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(90,100,125,100);
    painter.drawLine(90,320,125,320);
    painter.drawLine(125,100,125,320);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);
    painter.drawLine(125,100,142,130);
    painter.drawLine(142,130,159,115);
    painter.drawLine(159,115,176,145);
    painter.drawLine(176,145,193,130);
    painter.drawLine(193,130,210,160);
    painter.drawLine(210,160,227,145);
    painter.drawLine(227,145,244,175);
    painter.drawLine(244,175,261,160);
    painter.drawLine(261,160,278,190);
    painter.drawLine(278,190,295,175);
    painter.drawLine(295,175,315,200);

    painter.drawLine(125,320,142,310);
    painter.drawLine(142,310,159,290);
    painter.drawLine(159,290,176,305);
    painter.drawLine(176,305,193,275);
    painter.drawLine(193,275,210,290);
    painter.drawLine(210,290,227,260);
    painter.drawLine(227,260,244,275);
    painter.drawLine(244,275,261,245);
    painter.drawLine(261,245,278,260);
    painter.drawLine(278,260,295,230);
    painter.drawLine(295,230,315,245);

    painter.drawLine(315,200,315,245);

    painter.drawLine(142,130,159,290);
    painter.drawLine(176,145,193,275);
    painter.drawLine(210,160,227,260);
    painter.drawLine(244,175,261,245);
    painter.drawLine(278,190,295,230);


    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,335,210);

    painter.setPen(pen4);
    painter.drawLine(130,330,315,250);
    painter.drawLine(130,330,130,370);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(315,250,315,290);
    painter.drawLine(130,370,315,290);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(223,289);
    QPoint p0_2(230,278);
    QPoint p0_3(235,294);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(245,319);
    QPoint p1_2(234,315);
    QPoint p1_3(241,330);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(130,355);
    QPoint p2_2(125,350);
    QPoint p2_3(135,350);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(315,265);
    QPoint p3_2(310,270);
    QPoint p3_3(320,270);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(125,100,315,180);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(315,60,315,77);
    painter.drawLine(70,68,315,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(315,68);
    QPoint p5_2(310,63);
    QPoint p5_3(310,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(315,80,315,200);
    painter.drawLine(130,87,315,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->screwThread2.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(215,82,str);

    painter.drawLine(193,130,200,115);
    painter.drawLine(227,145,235,130);
    painter.drawLine(200,115,235,130);
    if(val_change==0)
    {
        str = QString("Tp=%1").arg(tem_val->screwThread2.Tp);
    }
    else
    {
        str = QString("Tp=%1").arg(edit_str[4]);
    }
    painter.drawText(222,110,str);

    painter.drawLine(130,330,210,330);
    //painter.drawLine(198,300,190,330);
    QRectF rectangle3(130, 295, 70, 70);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = 40 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(210,320,"A");

    painter.drawLine(315,180,345,190);
    painter.drawLine(315,200,340,210);
    painter.drawLine(345,190,340,210);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->screwThread2.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(360, 215);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(320,280,335,280);
    painter.drawLine(320,290,335,290);
    painter.drawLine(327,280,327,290);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->screwThread2.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(335, 275);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);//
    QPoint p8_2(135,82);
    QPoint p8_3(135,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(315,87);
    QPoint p9_2(310,82);
    QPoint p9_3(310,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(200,115);//
    QPoint p10_2(204,123);
    QPoint p10_3(208,113);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(235,130);
    QPoint p11_2(230,122);
    QPoint p11_3(227,132);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(345,191);//
    QPoint p12_2(339,196);
    QPoint p12_3(348,197);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(339,209);
    QPoint p13_2(336,203);
    QPoint p13_3(346,208);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(317,292);

    painter.end();
}

void widget2::DrawLuoWen3()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(90,100,120,100);
    painter.drawLine(90,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);
    painter.drawLine(120,100,285,100);
    painter.drawLine(120,320,285,320);
    painter.drawLine(285,100,285,320);

    painter.drawLine(120,133,135,163);
    painter.drawLine(135,163,150,133);
    painter.drawLine(150,133,165,163);
    painter.drawLine(165,163,180,133);
    painter.drawLine(180,133,195,163);
    painter.drawLine(195,163,210,133);
    painter.drawLine(210,133,225,163);
    painter.drawLine(225,163,240,133);
    painter.drawLine(240,133,255,163);
    painter.drawLine(255,163,270,133);
    painter.drawLine(270,133,285,163);
    painter.drawLine(120,265,135,265);
    painter.drawLine(135,265,150,235);
    painter.drawLine(150,235,165,265);
    painter.drawLine(165,265,180,235);
    painter.drawLine(180,235,195,265);
    painter.drawLine(195,265,210,235);
    painter.drawLine(210,235,225,265);
    painter.drawLine(225,265,240,235);
    painter.drawLine(240,235,255,265);
    painter.drawLine(255,265,270,235);
    painter.drawLine(270,235,285,265);
    painter.drawLine(285,163,285,265);

    painter.drawLine(120,135,150,100);
    painter.drawLine(128,150,170,100);
    painter.drawLine(158,150,200,100);
    painter.drawLine(188,150,230,100);
    painter.drawLine(218,150,260,100);
    painter.drawLine(248,150,285,110);
    painter.drawLine(120,280,135,265);
    painter.drawLine(120,310,160,262);
    painter.drawLine(145,320,190,262);
    painter.drawLine(175,320,220,262);
    painter.drawLine(205,320,250,262);
    painter.drawLine(235,320,280,262);


    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,295,210);

    painter.setPen(pen4);
    painter.drawLine(130,215,315,215);
    painter.drawLine(130,215,130,235);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(315,215,315,235);
    painter.drawLine(130,235,315,235);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(220,215);
    QPoint p0_2(215,210);
    QPoint p0_3(215,220);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(215,235);
    QPoint p1_2(220,230);
    QPoint p1_3(220,240);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(130,225);
    QPoint p2_2(125,230);
    QPoint p2_3(135,230);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(315,230);
    QPoint p3_2(310,225);
    QPoint p3_3(320,225);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(125,170,285,170);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(285,60,285,77);
    painter.drawLine(70,68,285,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(285,68);
    QPoint p5_2(280,63);
    QPoint p5_3(280,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(285,80,285,95);
    painter.drawLine(130,87,285,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->screwThread3.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(215,82,str);

    painter.drawLine(165,170,165,190);
    painter.drawLine(195,170,195,190);
    painter.drawLine(165,180,195,180);
    if(val_change==0)
    {
        str = QString("Tp=%1").arg(tem_val->screwThread3.Tp);
    }
    else
    {
        str = QString("Tp=%1").arg(edit_str[4]);
    }
    painter.drawText(175,200,str);

    painter.drawLine(290,133,310,133);
    painter.drawLine(290,170,310,170);
    painter.drawLine(300,133,300,170);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->screwThread3.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(330, 155);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(320,215,335,215);
    painter.drawLine(320,235,335,235);
    painter.drawLine(327,215,327,235);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->screwThread3.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(345, 255);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);//
    QPoint p8_2(135,82);
    QPoint p8_3(135,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(285,87);
    QPoint p9_2(280,82);
    QPoint p9_3(280,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(165,180);//
    QPoint p10_2(170,175);
    QPoint p10_3(170,185);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(195,180);
    QPoint p11_2(190,175);
    QPoint p11_3(190,185);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(300,133);//
    QPoint p12_2(295,138);
    QPoint p12_3(305,138);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(300,170);
    QPoint p13_2(295,165);
    QPoint p13_3(305,165);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(316,215);

    painter.end();
}

void widget2::DrawLuoWen4()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(77, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(57,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(77, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);

    painter.drawLine(90,100,125,100);
    painter.drawLine(90,320,125,320);
    painter.drawLine(125,100,125,320);
    painter.drawLine(83,230,97,220);
    painter.drawLine(77,270,105,255);
    painter.drawLine(85,310,100,300);
    painter.drawLine(125,100,315,100);
    painter.drawLine(125,320,315,320);
    painter.drawLine(315,100,315,320);

    painter.drawLine(125,160,142,180);
    painter.drawLine(142,180,159,150);
    painter.drawLine(159,150,176,170);
    painter.drawLine(176,170,193,140);
    painter.drawLine(193,140,210,160);
    painter.drawLine(210,160,227,130);
    painter.drawLine(227,130,244,150);
    painter.drawLine(244,150,261,120);
    painter.drawLine(261,120,278,140);
    painter.drawLine(278,140,295,110);
    painter.drawLine(295,110,315,100);

    painter.drawLine(125,260,142,240);
    painter.drawLine(142,240,159,270);
    painter.drawLine(159,270,176,250);
    painter.drawLine(176,250,193,280);
    painter.drawLine(193,280,210,260);
    painter.drawLine(210,260,227,290);
    painter.drawLine(227,290,244,270);
    painter.drawLine(244,270,261,300);
    painter.drawLine(261,300,278,280);
    painter.drawLine(278,280,295,310);
    painter.drawLine(295,310,315,320);

    painter.drawLine(125,130,160,100);
    painter.drawLine(125,160,190,100);
    painter.drawLine(165,155,215,100);
    painter.drawLine(200,147,240,100);
    painter.drawLine(235,138,265,100);
    painter.drawLine(270,130,290,100);
    painter.drawLine(125,280,150,255);
    painter.drawLine(125,320,180,260);
    painter.drawLine(155,320,195,280);
    painter.drawLine(190,320,223,285);
    painter.drawLine(220,320,250,287);
    painter.drawLine(260,320,283,291);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,335,210);

    painter.setPen(pen4);
    painter.drawLine(130,200,320,255);
    painter.drawLine(130,200,130,225);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(320,255,320,280);
    painter.drawLine(130,225,320,280);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(244,234);
    QPoint p0_2(239,224);
    QPoint p0_3(235,237);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(231,254);
    QPoint p1_2(241,249);
    QPoint p1_3(236,264);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(130,210);
    QPoint p2_2(125,215);
    QPoint p2_3(135,215);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(320,275);
    QPoint p3_2(315,270);
    QPoint p3_3(325,270);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);//虚线
    painter.setPen(pen5);
    painter.drawLine(125,190,315,130);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(315,60,315,77);
    painter.drawLine(70,68,315,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(170,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(315,68);
    QPoint p5_2(310,63);
    QPoint p5_3(310,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(130,80,130,95);
    painter.drawLine(315,80,315,200);
    painter.drawLine(130,87,315,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->screwThread4.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(215,82,str);

    painter.drawLine(210,160,220,180);
    painter.drawLine(245,150,252,162);
    painter.drawLine(220,180,252,162);
    if(val_change==0)
    {
        str = QString("Tp=%1").arg(tem_val->screwThread4.Tp);
    }
    else
    {
        str = QString("Tp=%1").arg(edit_str[4]);
    }
    painter.drawText(235,188,str);

    painter.drawLine(130,225,210,225);
    //painter.drawLine(180,237,190,225);
    QRectF rectangle3(130, 190, 70, 70);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = -30 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(210,240,"A");

    painter.drawLine(315,100,330,95);
    painter.drawLine(315,130,340,122);
    painter.drawLine(330,95,340,122);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->screwThread4.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(345, 110);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(320,255,335,255);
    painter.drawLine(320,265,335,265);
    painter.drawLine(327,255,327,265);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->screwThread4.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(345, 285);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(130,87);//
    QPoint p8_2(135,82);
    QPoint p8_3(135,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(315,87);
    QPoint p9_2(310,82);
    QPoint p9_3(310,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(220,180);//
    QPoint p10_2(222,170);
    QPoint p10_3(229,183);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(252,162);
    QPoint p11_2(241,159);
    QPoint p11_3(249,171);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(330,95);//
    QPoint p12_2(325,103);
    QPoint p12_3(336,99);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(340,122);
    QPoint p13_2(332,119);
    QPoint p13_3(341,115);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(336,255);

    painter.end();
}

void widget2::DrawDaoJiao1()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,250,100);
    painter.drawLine(95,320,250,320);
    painter.drawLine(250,100,250,320);

    QRectF rectangle3(210, 100, 80, 80);//
    int startAngle3 = 90 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = -90 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    QRectF rectangle4(210,240, 80, 80);
    int startAngle4 = -90 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle4 = 90 * 16;
    painter.drawArc(rectangle4, startAngle4, spanAngle4);
    painter.drawLine(290,140,290,280);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(80,210,310,210);

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(250,100,290,100);
    painter.drawLine(290,100,290,140);

    painter.setPen(pen4);
    QRectF rectangle5(210,240, 85, 85);
    int startAngle5 = -90 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle5 = 90 * 16;
    painter.drawArc(rectangle5, startAngle5, spanAngle5);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(255,325,295,325);
    painter.drawLine(295,285,295,325);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(280,325);
    QPoint p0_2(275,320);
    QPoint p0_3(275,330);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(295,310);
    QPoint p1_2(290,315);
    QPoint p1_3(300,315);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(281,314);
    QPoint p2_2(282,309);
    QPoint p2_3(289,315);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    painter.drawConvexPolygon(t0);//填充颜色

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(290,60,290,77);
    painter.drawLine(70,68,290,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(145,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(290,68);
    QPoint p5_2(285,63);
    QPoint p5_3(285,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(250,80,250,95);
    painter.drawLine(290,80,290,95);
    painter.drawLine(250,87,290,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->chamfer1.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(265,82,str);

    painter.drawLine(290,100,310,100);
    painter.drawLine(290,140,310,140);
    painter.drawLine(300,100,300,140);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->chamfer1.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(315, 120);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(295,305,315,305);
    painter.drawLine(295,325,315,325);
    painter.drawLine(305,305,305,325);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->chamfer1.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(308, 295);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(279,112,263,128);
    QString text_R = "R";
    painter.translate(276, 131);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-45);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, text_R);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(250,87);//
    QPoint p8_2(255,82);
    QPoint p8_3(255,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(290,87);
    QPoint p9_2(285,82);
    QPoint p9_3(285,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(300,100);//
    QPoint p10_2(295,105);
    QPoint p10_3(305,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(300,140);
    QPoint p11_2(295,135);
    QPoint p11_3(305,135);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(305,305);//
    QPoint p12_2(300,310);
    QPoint p12_3(310,310);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(305,325);
    QPoint p13_2(300,320);
    QPoint p13_3(310,320);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(295,326);

    painter.end();
}

void widget2::DrawDaoJiao2()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,250,100);
    painter.drawLine(95,320,250,320);
    painter.drawLine(250,100,250,320);

    painter.drawLine(250,100,290,140);
    painter.drawLine(290,140,290,280);
    painter.drawLine(290,280,250,320);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(80,210,310,210);

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(250,100,290,100);
    painter.drawLine(290,100,290,140);

    painter.setPen(pen4);
    painter.drawLine(255,325,295,285);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(255,325,295,325);
    painter.drawLine(295,285,295,325);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(280,325);
    QPoint p0_2(275,320);
    QPoint p0_3(275,330);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(295,310);
    QPoint p1_2(290,315);
    QPoint p1_3(300,315);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(270,310);
    QPoint p2_2(270,303);
    QPoint p2_3(277,310);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    painter.drawConvexPolygon(t0);//填充颜色

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(290,60,290,77);
    painter.drawLine(70,68,290,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(145,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, text_D0);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(290,68);
    QPoint p5_2(285,63);
    QPoint p5_3(285,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(250,80,250,95);
    painter.drawLine(290,80,290,95);
    painter.drawLine(250,87,290,87);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->chamfer2.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(265,82,str);

    painter.drawLine(290,100,310,100);
    painter.drawLine(290,140,310,140);
    painter.drawLine(300,100,300,140);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->chamfer2.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(315, 120);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(295,305,315,305);
    painter.drawLine(295,325,315,325);
    painter.drawLine(305,305,305,325);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->chamfer2.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(308, 295);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    //painter.drawLine(270,100,266,115);
    //painter.drawLine(295,325,315,325);
    QRectF rectangle3(200, 65, 70, 70);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = -25 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    painter.drawText(270,117,"A");

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(250,87);//
    QPoint p8_2(255,82);
    QPoint p8_3(255,92);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(290,87);
    QPoint p9_2(285,82);
    QPoint p9_3(285,92);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(300,100);//
    QPoint p10_2(295,105);
    QPoint p10_3(305,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(300,140);
    QPoint p11_2(295,135);
    QPoint p11_3(305,135);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(305,305);//
    QPoint p12_2(300,310);
    QPoint p12_3(310,310);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(305,325);
    QPoint p13_2(300,320);
    QPoint p13_3(310,320);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    //DrawKnife();
    DrawKnife3(295,326);

    painter.end();
}

void widget2::DrawDaoJiao3()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,120,100);
    painter.drawLine(95,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(120,100,300,100);
    painter.drawLine(120,320,300,320);
    painter.drawLine(120,180,225,180);
    painter.drawLine(120,240,225,240);
    painter.drawLine(300,100,300,320);

    QRectF rectangle3(140, 20, 160, 160);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = -90 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    QRectF rectangle4(140, 240, 160, 160);//
    int startAngle4 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle4 = 90 * 16;
    painter.drawArc(rectangle4, startAngle4, spanAngle4);

    painter.drawLine(120,115,135,100);
    painter.drawLine(120,135,150,100);
    painter.drawLine(120,160,180,100);
    painter.drawLine(135,180,210,100);
    painter.drawLine(165,180,240,100);
    painter.drawLine(195,180,270,100);
    painter.drawLine(225,180,300,100);//
    painter.drawLine(120,260,135,240);
    painter.drawLine(120,285,155,240);
    painter.drawLine(120,310,180,240);
    painter.drawLine(150,320,210,240);
    painter.drawLine(180,320,240,243);
    painter.drawLine(210,320,270,258);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    QRectF rectangle5(145, 235, 160, 160);//
    int startAngle5 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle5 = 90 * 16;
    painter.drawArc(rectangle5, startAngle5, spanAngle5);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(245,235,305,235);
    painter.drawLine(305,235,305,320);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(275,235);
    QPoint p0_2(280,230);
    QPoint p0_3(280,240);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(305,270);
    QPoint p1_2(300,275);
    QPoint p1_3(310,275);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(279,258);
    QPoint p2_2(272,258);
    QPoint p2_3(278,251);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(240,180,300,180);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(240,180,240,190);
    painter.drawLine(300,180,300,190);
    painter.drawLine(240,185,300,185);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->chamfer3.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(260,195,str);


    painter.drawLine(305,100,320,100);
    painter.drawLine(305,180,320,180);
    painter.drawLine(312,100,312,180);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->chamfer3.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(325, 150);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(261,141,277,156);
    QString text_r = "R";
    painter.translate(280, 142);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-45);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, text_r);      // 第3步： 绘制文字
    painter.resetMatrix();

    int a = 15;
    painter.drawLine(305-a,235,320-a,235);
    painter.drawLine(305-a,245,320-a,245);
    painter.drawLine(312-a,235,312-a,245);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->chamfer3.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(305-a, 225);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(240,185);//
    QPoint p8_2(245,180);
    QPoint p8_3(245,190);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,185);
    QPoint p9_2(295,180);
    QPoint p9_3(295,190);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(312,100);//
    QPoint p10_2(317,105);
    QPoint p10_3(307,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(312,180);
    QPoint p11_2(317,175);
    QPoint p11_3(307,175);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(312-a,235);//
    QPoint p12_2(317-a,230);
    QPoint p12_3(307-a,230);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(312-a,245);
    QPoint p13_2(317-a,250);
    QPoint p13_3(307-a,250);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(305,235);

    painter.end();
}

void widget2::DrawDaoJiao4()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(82, 92, 50, 120);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(62,203, 50, 120);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(82, 206, 50, 120);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(88,230,102,220);
    painter.drawLine(82,270,110,255);
    painter.drawLine(90,310,105,300);

    painter.drawLine(95,100,120,100);
    painter.drawLine(95,320,120,320);
    painter.drawLine(120,100,120,320);
    painter.drawLine(120,100,300,100);
    painter.drawLine(120,320,300,320);
    painter.drawLine(120,180,225,180);
    painter.drawLine(120,240,225,240);
    painter.drawLine(300,100,300,320);
    painter.drawLine(225,240,300,320);

    painter.drawLine(120,115,135,100);
    painter.drawLine(120,135,150,100);
    painter.drawLine(120,160,180,100);
    painter.drawLine(135,180,210,100);
    painter.drawLine(165,180,240,100);
    painter.drawLine(195,180,270,100);
    painter.drawLine(225,180,300,100);
    painter.drawLine(120,260,135,240);
    painter.drawLine(120,285,155,240);
    painter.drawLine(120,310,180,240);
    painter.drawLine(150,320,210,240);
    painter.drawLine(180,320,233,251);
    painter.drawLine(210,320,250,268);
    painter.drawLine(250,320,273,294);

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(70,210,320,210);

    painter.setPen(pen4);
    painter.drawLine(230,240,305,320);
    pen4.setStyle(Qt::DashLine);
    painter.setPen(pen4);
    painter.drawLine(230,240,305,240);
    painter.drawLine(305,240,305,320);

    pen4.setStyle(Qt::SolidLine);
    painter.setPen(pen4);
    QPolygon t0,t1,t2,t3;
    painter.setBrush(Qt::green);

    QPoint p0_1(275,240);
    QPoint p0_2(280,235);
    QPoint p0_3(280,245);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(305,270);
    QPoint p1_2(300,275);
    QPoint p1_3(310,275);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(267,280);
    QPoint p2_2(266,274);
    QPoint p2_3(260,280);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    painter.drawConvexPolygon(t0);//填充颜色

    pen5.setStyle(Qt::DashLine);
    painter.setPen(pen5);
    painter.drawLine(225,180,300,180);

    painter.setPen(pen2);
    painter.drawLine(70,60,70,77);
    painter.drawLine(300,60,300,77);
    painter.drawLine(70,68,300,68);
    str = QString("L0=%1").arg(barstock_width);
    painter.drawText(155,63,str);

    painter.drawLine(60,100,75,100);
    painter.drawLine(60,320,75,320);
    painter.drawLine(67,100,67,320);
    QString text_D0 = "D0=80.000";
    str = QString("D0=%1").arg(barstock_height);
    painter.translate(60, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t4,t5,t6,t7;
    painter.setBrush(QColor(21,246,231));

    QPoint p4_1(70,68);
    QPoint p4_2(75,63);
    QPoint p4_3(75,73);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(300,68);
    QPoint p5_2(295,63);
    QPoint p5_3(295,73);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    QPoint p6_1(67,100);
    QPoint p6_2(62,105);
    QPoint p6_3(72,105);
    t6<<p6_1<<p6_2<<p6_3;
    painter.drawPolygon(t6);
    QPoint p7_1(67,320);
    QPoint p7_2(62,315);
    QPoint p7_3(72,315);
    t7<<p7_1<<p7_2<<p7_3;
    painter.drawPolygon(t7);
    painter.drawConvexPolygon(t4);//填充颜色

    painter.setPen(pen3);
    painter.drawLine(225,180,225,190);
    painter.drawLine(300,180,300,190);
    painter.drawLine(225,185,300,185);
    if(val_change==0)
    {
        str = QString("L=%1").arg(tem_val->chamfer4.L);
    }
    else
    {
        str = QString("L=%1").arg(edit_str[0]);
    }
    painter.drawText(260,195,str);


    painter.drawLine(305,100,320,100);
    painter.drawLine(305,180,320,180);
    painter.drawLine(312,100,312,180);
    QString text_cr = "Cr";
    if(val_change==0)
    {
        str = QString("Cr=%1").arg(tem_val->chamfer4.Cr);
    }
    else
    {
        str = QString("Cr=%1").arg(edit_str[3]);
    }
    painter.translate(325, 150);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QRectF rectangle3(190, 140, 75, 75);//
    int startAngle3 = 0 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle3 = 45 * 16;
    painter.drawArc(rectangle3, startAngle3, spanAngle3);
    QString text_r = "A";
    painter.translate(270, 165);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-45);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, text_r);      // 第3步： 绘制文字
    painter.resetMatrix();

    int a = 15;
    painter.drawLine(305-a,240,320-a,240);
    painter.drawLine(305-a,250,320-a,250);
    painter.drawLine(312-a,240,312-a,250);
    QString text_Tr = "Tr";
    if(val_change==0)
    {
        str = QString("Tr=%1").arg(tem_val->chamfer4.Tr);
    }
    else
    {
        str = QString("Tr=%1").arg(edit_str[1]);
    }
    painter.translate(320-a, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    QPolygon t8,t9,t10,t11,t12,t13;
    painter.setBrush(Qt::yellow);

    QPoint p8_1(225,185);//
    QPoint p8_2(230,180);
    QPoint p8_3(230,190);
    t8<<p8_1<<p8_2<<p8_3;
    painter.drawPolygon(t8);
    QPoint p9_1(300,185);
    QPoint p9_2(295,180);
    QPoint p9_3(295,190);
    t9<<p9_1<<p9_2<<p9_3;
    painter.drawPolygon(t9);
    QPoint p10_1(312,100);//
    QPoint p10_2(317,105);
    QPoint p10_3(307,105);
    t10<<p10_1<<p10_2<<p10_3;
    painter.drawPolygon(t10);
    QPoint p11_1(312,180);
    QPoint p11_2(317,175);
    QPoint p11_3(307,175);
    t11<<p11_1<<p11_2<<p11_3;
    painter.drawPolygon(t11);
    QPoint p12_1(312-a,240);//
    QPoint p12_2(317-a,235);
    QPoint p12_3(307-a,235);
    t12<<p12_1<<p12_2<<p12_3;
    painter.drawPolygon(t12);
    QPoint p13_1(312-a,250);
    QPoint p13_2(317-a,255);
    QPoint p13_3(307-a,255);
    t13<<p13_1<<p13_2<<p13_3;
    painter.drawPolygon(t13);
    painter.drawConvexPolygon(t8);//填充颜色

    DrawKnife2(305,240);

    painter.end();
}

void widget2::DrawBangLiao()
{
    QPainter painter;
    QPen pen,pen1,pen2,pen3,pen4,pen5;
    pen.setColor(Qt::white);
    pen1.setColor(Qt::red);
    pen2=QPen(QColor(21,246,231));
    pen3.setColor(Qt::yellow);
    pen4.setColor(Qt::green);
    pen5=QPen(QColor(179,22,201));//紫色
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);

    QRectF rectangle(79, 129, 30, 70);//
    int startAngle = 120 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle = 130 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    QRectF rectangle1(67,195, 30, 70);
    int startAngle1 = 60 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle1 = -130 * 16;
    painter.drawArc(rectangle1, startAngle1, spanAngle1);
    QRectF rectangle2(78, 195, 30, 70);
    int startAngle2 = 110 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = 135 * 16;
    painter.drawArc(rectangle2, startAngle2, spanAngle2);
    painter.drawLine(78,220,95,210);
    painter.drawLine(80,240,97,230);
    painter.drawLine(85,255,95,245);

    painter.drawLine(88,133,300,133);
    painter.drawLine(88,265,300,265);
    painter.drawLine(300,135,300,265);

    painter.setPen(pen2);
    painter.drawLine(88,120,88,130);
    painter.drawLine(300,120,300,130);
    painter.drawLine(88,125,300,125);
    //str = QString("L0=%1").arg(barstock_width);
    if(val_change==0)
    {
        str = QString("L0=%1").arg(barstock_width);
    }
    else
    {
        str = QString("L0=%1").arg(edit_str[0]);
    }
    painter.drawText(170,110,str);

    painter.drawLine(315,133,325,133);
    painter.drawLine(315,265,325,265);
    painter.drawLine(320,133,320,265);
    QString text_D0 = "D0=80.000";
    //str = QString("D0=%1").arg(barstock_height);
    if(val_change==0)
    {
        str = QString("D0=%1").arg(barstock_height);
    }
    else
    {
        str = QString("D0=%1").arg(edit_str[1]);
    }
    painter.translate(335, 230);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-90);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    painter.drawLine(310,275,270,275);
    painter.drawLine(310,275,310,235);
    painter.drawText(314,250,"D1");
    painter.drawText(285,285,"L1");

//    pen2.setStyle(Qt::SolidLine);
//    painter.setPen(pen2);
    QPolygon t0,t1,t2,t3,t4,t5;
    painter.setBrush(QColor(21,246,231));

    QPoint p0_1(88,125);
    QPoint p0_2(93,120);
    QPoint p0_3(93,130);
    t0<<p0_1<<p0_2<<p0_3;
    painter.drawPolygon(t0);
    QPoint p1_1(300,125);
    QPoint p1_2(295,120);
    QPoint p1_3(295,130);
    t1<<p1_1<<p1_2<<p1_3;
    painter.drawPolygon(t1);
    QPoint p2_1(320,133);
    QPoint p2_2(315,138);
    QPoint p2_3(325,138);
    t2<<p2_1<<p2_2<<p2_3;
    painter.drawPolygon(t2);
    QPoint p3_1(320,265);
    QPoint p3_2(315,260);
    QPoint p3_3(325,260);
    t3<<p3_1<<p3_2<<p3_3;
    painter.drawPolygon(t3);
    QPoint p4_1(270,275);
    QPoint p4_2(275,270);
    QPoint p4_3(275,280);
    t4<<p4_1<<p4_2<<p4_3;
    painter.drawPolygon(t4);
    QPoint p5_1(310,235);
    QPoint p5_2(315,240);
    QPoint p5_3(305,240);
    t5<<p5_1<<p5_2<<p5_3;
    painter.drawPolygon(t5);
    painter.drawConvexPolygon(t0);//填充颜色

    pen1.setStyle(Qt::DashLine);
    painter.setPen(pen1);
    painter.drawLine(75,198,310,198);

    DrawKnife3(300,265);

    painter.end();


}

void widget2::DateUpdate_slot()
{
    //pic_ischanged = 1-pic_ischanged;
    clear_str_info();
    work_pic->Updata_Info_slot();
    update();
}

void widget2::Timer_on_slot()
{
//    static int i=0;

//    if(i==20)//删掉
//    {
//        i=0;
//        motion_internal->spin_data[0].spind_speed_ctrl++;
//        motion_status->current_val_axis[0]++;
//        motion_status->current_val_axis[1]++;
//        if(motion_internal->spin_data[0].spind_speed_ctrl>1)
//        {
//            motion_internal->spin_data[0].spind_speed_ctrl=-1;
//            motion_status->current_val_axis[0]=-1;
//            motion_status->current_val_axis[1]=-1;
//        }
//    }
//    i++;

    if(motion_internal->spin_data[0].spind_speed_ctrl==1)//正转
    {
        ui->t_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt_on.png);}");
        ui->t_but2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt2.png);}");
    }
    else if(motion_internal->spin_data[0].spind_speed_ctrl==-1)//反转
    {
        ui->t_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt.png);}");
        ui->t_but2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt2_on.png);}");
    }
    else if(motion_internal->spin_data[0].spind_speed_ctrl==0)
    {
        ui->t_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt.png);}");
        ui->t_but2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt2.png);}");
    }

    if((plc_shm->y[0]&1)==0)//照明
    {
        ui->t_but5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt5.png);}");
    }
    else
    {
        ui->t_but5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt5_on.png);}");
    }

    if((plc_shm->y[0]&2)==0)//润滑
    {
        ui->t_but6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt6.png);}");
    }
    else
    {
        ui->t_but6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt6_on.png);}");
    }

    if((plc_shm->y[0]&4)==0)//清洗
    {
        ui->t_but3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt3.png);}");
    }
    else
    {
        ui->t_but3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt3_on.png);}");
    }

    switch (motion_status->CurTCode)
    {
        case 0:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num0.png);}");
        break;
        case 1:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num1.png);}");
        break;
        case 2:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num2.png);}");
        break;
        case 3:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num3.png);}");
        break;
        case 4:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num4.png);}");
        break;
        case 5:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num5.png);}");
        break;
        case 6:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num6.png);}");
        break;
        case 7:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num7.png);}");
        break;
        case 8:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num8.png);}");
        break;
        case 9:
        ui->t_but4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_t_bt4_num9.png);}");
        break;
        default:
        break;
    }

    update();
}

void widget2::DrawDirection()//画刀具行进方向
{
    QPainter painter;
    QPen pen,pen1;
    pen.setColor(Qt::white);
    pen1.setColor(QColor(21,246,231));
    pen.setWidth(1); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);

    painter.drawText(338,102,"Z-");
    painter.drawText(412,73,"X-");
    painter.drawText(429,102,"Z+");
    painter.drawText(350,133,"X+");

    QPolygon t0,t1,t2,t3;

    QPoint p0_1(356,103);//
    QPoint p0_2(370,95);
    QPoint p0_3(367,100);
    QPoint p0_4(387,100);
    QPoint p0_5(390,105);
    QPoint p0_6(380,108);
    QPoint p0_7(362,107);
    QPoint p0_8(360,110);
    t0<<p0_1<<p0_2<<p0_3<<p0_4<<p0_5<<p0_6<<p0_7<<p0_8;
    painter.drawPolygon(t0);
    QPoint p1_1(416,78);//
    QPoint p1_2(418,86);
    QPoint p1_3(413,86);
    QPoint p1_4(400,100);
    QPoint p1_5(390,105);
    QPoint p1_6(390,100);
    QPoint p1_7(405,85);
    QPoint p1_8(400,85);
    t1<<p1_1<<p1_2<<p1_3<<p1_4<<p1_5<<p1_6<<p1_7<<p1_8;
    painter.drawPolygon(t1);
    QPoint p2_1(426,105);//
    QPoint p2_2(412,112);
    QPoint p2_3(414,108);
    QPoint p2_4(394,108);
    QPoint p2_5(390,105);
    QPoint p2_6(400,100);
    QPoint p2_7(421,100);
    QPoint p2_8(422,95);
    t2<<p2_1<<p2_2<<p2_3<<p2_4<<p2_5<<p2_6<<p2_7<<p2_8;
    painter.drawPolygon(t2);
    QPoint p3_1(366,130);//
    QPoint p3_2(363,122);
    QPoint p3_3(368,122);
    QPoint p3_4(381,108);
    QPoint p3_5(390,105);
    QPoint p3_6(391,109);
    QPoint p3_7(377,123);
    QPoint p3_8(381,125);
    t3<<p3_1<<p3_2<<p3_3<<p3_4<<p3_5<<p3_6<<p3_7<<p3_8;
    painter.drawPolygon(t3);

    cur_dir = Zneg;
    PaintDirection();

    painter.end();
}

void widget2::PaintDirection()
{
    QPainter painter;
    QPen pen,pen1;
    int tem_x,tem_z;
    pen.setColor(Qt::white);
    pen1.setColor(QColor(21,246,231));
    pen.setWidth(1); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);

    QPolygon t0,t1,t2,t3;
    painter.setBrush(QColor(21,246,231));

    if(para[MOTION_DIRECTION_X].cur_val.int_val == 0)
    {
        tem_x = -1;
    }
    else
    {
        tem_x = 1;
    }
    if(para[MOTION_DIRECTION_Z].cur_val.int_val == 0)
    {
        tem_z = -1;
    }
    else
    {
        tem_z = 1;
    }

    if(motion_status->current_val_axis[1]*tem_z<0)//Z-
    {
        QPoint p0_1(356,103);//
        QPoint p0_2(370,95);
        QPoint p0_3(367,100);
        QPoint p0_4(387,100);
        QPoint p0_5(390,105);
        QPoint p0_6(380,108);
        QPoint p0_7(362,107);
        QPoint p0_8(360,110);
        t0<<p0_1<<p0_2<<p0_3<<p0_4<<p0_5<<p0_6<<p0_7<<p0_8;
        painter.drawPolygon(t0);
    }
    if(motion_status->current_val_axis[0]*tem_x<0)//X-
    {
        QPoint p1_1(416,78);//
        QPoint p1_2(418,86);
        QPoint p1_3(413,86);
        QPoint p1_4(400,100);
        QPoint p1_5(390,105);
        QPoint p1_6(390,100);
        QPoint p1_7(405,85);
        QPoint p1_8(400,85);
        t1<<p1_1<<p1_2<<p1_3<<p1_4<<p1_5<<p1_6<<p1_7<<p1_8;
        painter.drawPolygon(t1);
    }
    if(motion_status->current_val_axis[1]*tem_z>0)//Z+
    {
        QPoint p2_1(426,105);//
        QPoint p2_2(412,112);
        QPoint p2_3(414,108);
        QPoint p2_4(394,108);
        QPoint p2_5(390,105);
        QPoint p2_6(400,100);
        QPoint p2_7(421,100);
        QPoint p2_8(422,95);
        t2<<p2_1<<p2_2<<p2_3<<p2_4<<p2_5<<p2_6<<p2_7<<p2_8;
        painter.drawPolygon(t2);
    }
    if(motion_status->current_val_axis[0]*tem_x>0)//X+
    {
        QPoint p3_1(366,130);//
        QPoint p3_2(363,122);
        QPoint p3_3(368,122);
        QPoint p3_4(381,108);
        QPoint p3_5(390,105);
        QPoint p3_6(391,109);
        QPoint p3_7(377,123);
        QPoint p3_8(381,125);
        t3<<p3_1<<p3_2<<p3_3<<p3_4<<p3_5<<p3_6<<p3_7<<p3_8;
        painter.drawPolygon(t3);
    }


    painter.end();
}

void widget2::pic_update(int index,QString str)
{
    switch (index)
    {
        case 1:
        edit_str[0] = str;
        break;
        case 2:
        edit_str[1] = str;
        break;
        case 3:
        edit_str[2] = str;
        break;
        case 4:
        edit_str[3] = str;
        break;
        case 5:
        edit_str[4] = str;
        break;
        case 6:
        edit_str[5] = str;
        break;
        case 7:
        edit_str[6] = str;
        break;
    }
    update();
}

void widget2::clear_str_info()
{
    edit_str[0] = "0";
    edit_str[1] = "0";
    edit_str[2] = "0";
    edit_str[3] = "0";
    edit_str[4] = "0";
    edit_str[5] = "0";
    edit_str[6] = "0";
}

void widget2::UPdate_scr()
{
    update();
}

void widget2::set_bt_jump()//设定按钮坐标
{
    int i;
    for (i=0;i<9;i++)
    {
        bt_showindex[i]->hide();
    }
    switch (cur_work_mod)
    {
        case waiyuan1:
        {
            for (i=0;i<5;i++)
            {
                bt_showindex[i]->show();
            }
            bt_showindex[0]->setGeometry(165,50,50,25);//L0
            bt_showindex[1]->setGeometry(50,200,25,50);//D0
            bt_showindex[2]->setGeometry(205,75,50,25);//L
            bt_showindex[3]->setGeometry(315,125,25,50);//cr
            bt_showindex[4]->setGeometry(310,290,25,50);//Tr
        }
        break;
    case waiyuan2:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(210,75,50,25);//L
        bt_showindex[3]->setGeometry(335,120,25,50);//cr
        bt_showindex[4]->setGeometry(330,305,25,50);//Tr
        bt_showindex[5]->setGeometry(220,110,50,25);//A
    }
    break;
    case waiyuan3:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(248,75,50,25);//L
        bt_showindex[3]->setGeometry(316,113,25,50);//cr
        bt_showindex[4]->setGeometry(309,287,25,50);//Tr
        bt_showindex[5]->setGeometry(260,115,50,25);//R
    }
    break;
    case duanmian1:
    {
        for (i=0;i<5;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(265,125,25,50);//Lr
        bt_showindex[3]->setGeometry(206,74,50,25);//cT
        bt_showindex[4]->setGeometry(216,339,50,25);//Tr
    }
    break;
    case duanmian2:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(212,75,50,25);//W
        bt_showindex[3]->setGeometry(266,128,25,50);//Lr
        bt_showindex[4]->setGeometry(178,331,50,25);//TW
        bt_showindex[5]->setGeometry(213,291,50,25);//TR
    }
    break;
    case duanmian3:
    {
        for (i=0;i<5;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(155,55,50,25);//L0
        //bt_showindex[0]->setGeometry(232,174,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(232,174,50,25);//CT
        bt_showindex[3]->setGeometry(332,234,25,50);//Lr
        bt_showindex[4]->setGeometry(250,234,50,25);//△T
    }
    break;
    case likong1:
    {
        for (i=0;i<5;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(155,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(203,75,50,25);//L
        bt_showindex[3]->setGeometry(317,110,25,50);//Cr
        bt_showindex[4]->setGeometry(313,294,50,25);//Tr
    }
    break;
    case likong2:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(155,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(205,75,50,25);//L
        bt_showindex[3]->setGeometry(317,110,25,50);//Cr
        bt_showindex[4]->setGeometry(313,294,25,50);//Tr
        bt_showindex[5]->setGeometry(255,156,50,25);//A
    }
    break;
    case likong3:
    {
        for (i=0;i<7;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(155,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(217,74,50,25);//W
        bt_showindex[3]->setGeometry(264,74,50,25);//W1
        bt_showindex[4]->setGeometry(318,111,25,50);//Lr
        bt_showindex[5]->setGeometry(323,288,50,25);//Tr
        bt_showindex[6]->setGeometry(333,254,50,25);//Tw
    }
    break;
    case likong4:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(155,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(255,74,50,25);//L
        bt_showindex[3]->setGeometry(317,131,25,50);//Cr
        bt_showindex[4]->setGeometry(313,211,25,50);//Tr
        bt_showindex[5]->setGeometry(276,152,50,25);//R
    }
    break;
    case likong5:
    {
        for (i=0;i<5;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(155,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(255,74,50,25);//L
        bt_showindex[3]->setGeometry(310,174,25,50);//△T
        bt_showindex[4]->setGeometry(328,242,25,50);//BT
    }
    break;
    case zhuimian1:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(209,74,50,25);//L
        bt_showindex[3]->setGeometry(334,120,25,50);//Cr
        bt_showindex[4]->setGeometry(327,304,25,50);//Tr
        bt_showindex[5]->setGeometry(218,107,50,25);//A
    }
    break;
    case zhuimian2:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(210,74,50,25);//L
        bt_showindex[3]->setGeometry(96,127,25,50);//Cr
        bt_showindex[4]->setGeometry(327,298,25,50);//Tr
        bt_showindex[5]->setGeometry(218,107,50,25);//A
    }
    break;
    case zhuimian3:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(210,74,50,25);//L
        bt_showindex[3]->setGeometry(332,121,25,50);//Cr
        bt_showindex[4]->setGeometry(327,251,25,50);//Tr
        bt_showindex[5]->setGeometry(218,107,50,25);//A
    }
    break;
    case zhuimian4:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(210,74,50,25);//L
        bt_showindex[3]->setGeometry(96,127,25,50);//Cr
        bt_showindex[4]->setGeometry(327,298,25,50);//Tr
        bt_showindex[5]->setGeometry(218,107,50,25);//A
    }
    break;
    case luowen1:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(150,60,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(200,92,50,25);//L
        bt_showindex[3]->setGeometry(216,112,50,25);//Tp
        bt_showindex[4]->setGeometry(302,139,25,50);//Cr
        bt_showindex[5]->setGeometry(312,271,25,50);//Tr
    }
    break;
    case luowen2:
    {
        for (i=0;i<7;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(211,73,50,25);//L
        bt_showindex[3]->setGeometry(218,102,50,25);//Tp
        bt_showindex[4]->setGeometry(353,197,25,50);//Cr
        bt_showindex[5]->setGeometry(325,256,25,50);//Tr
        bt_showindex[6]->setGeometry(202,310,50,25);//A
    }
    break;
    case luowen3:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(211,73,50,25);//L
        bt_showindex[3]->setGeometry(168,191,50,25);//Tp
        bt_showindex[4]->setGeometry(319,133,25,50);//Cr
        bt_showindex[5]->setGeometry(338,235,25,50);//Tr
    }
    break;
    case luowen4:
    {
        for (i=0;i<7;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(211,73,50,25);//L
        bt_showindex[3]->setGeometry(230,177,50,25);//Tp
        bt_showindex[4]->setGeometry(338,87,25,50);//Cr
        bt_showindex[5]->setGeometry(335,267,25,50);//Tr
        bt_showindex[6]->setGeometry(204,231,50,25);//A
    }
    break;
    case daojiao1:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(258,73,50,25);//L
        bt_showindex[3]->setGeometry(306,100,25,50);//Cr
        bt_showindex[4]->setGeometry(298,270,25,50);//Tr
        bt_showindex[5]->setGeometry(258,119,25,50);//R
    }
    break;
    case daojiao2:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(258,73,50,25);//L
        bt_showindex[3]->setGeometry(306,100,25,50);//Cr
        bt_showindex[4]->setGeometry(298,270,25,50);//Tr
        bt_showindex[5]->setGeometry(258,100,25,50);//A
    }
    case daojiao3:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(258,73,50,25);//L
        bt_showindex[3]->setGeometry(306,100,25,50);//Cr
        bt_showindex[4]->setGeometry(298,270,25,50);//Tr
        bt_showindex[5]->setGeometry(258,119,25,50);//R
    }
    break;
    case daojiao4:
    {
        for (i=0;i<6;i++)
        {
            bt_showindex[i]->show();
        }
        bt_showindex[0]->setGeometry(165,55,50,25);//L0
        bt_showindex[1]->setGeometry(50,200,25,50);//D0
        bt_showindex[2]->setGeometry(258,73,50,25);//L
        bt_showindex[3]->setGeometry(306,100,25,50);//Cr
        bt_showindex[4]->setGeometry(298,270,25,50);//Tr
        bt_showindex[5]->setGeometry(258,119,25,50);//A
    }
    break;
    default:
        break;

    }
}



void widget2::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPixmap pixmap(":/new/blue_pic/wg2_bk.png");

    painter.begin(this);
    painter.drawPixmap(rect(),pixmap,QRect());
    //qDebug()<<"cur_work_mod"<<cur_work_mod;
    //qDebug()<<"input_ok_flg0="<<input_ok_flg;
    if(bar_pic==0)
    {
        if(barstock_flg==0)
        {
            ui->knife_dir->hide();
            if(cur_work_mod==waiyuan1)
            {
                DrawWaiYuan1();
            }
            else if(cur_work_mod==waiyuan2)
            {
                DrawWaiYuan2();
            }
            else if(cur_work_mod==waiyuan3)
            {
                DrawWaiYuan3();
            }
            else if(cur_work_mod==duanmian1)
            {
                DrawDuanMian1();
            }
            else if(cur_work_mod==duanmian2)
            {
                DrawDuanMian2();
            }
            else if(cur_work_mod==duanmian3)
            {
                DrawDuanMian3();
            }
            else if(cur_work_mod==likong1)
            {
                DrawLiKong1();
            }
            else if(cur_work_mod==likong2)
            {
                DrawLiKong2();
            }
            else if(cur_work_mod==likong3)
            {
                DrawLiKong3();
            }
            else if(cur_work_mod==likong4)
            {
                DrawLiKong4();
            }
            else if(cur_work_mod==likong5)
            {
                DrawLiKong5();
            }
            else if(cur_work_mod==zhuimian1)
            {
                DrawWaiYuan2();
            }
            else if(cur_work_mod==zhuimian2)
            {
                DrawZhuiMian2();
            }
            else if(cur_work_mod==zhuimian3)
            {
                DrawZhuiMian3();
            }
            else if(cur_work_mod==zhuimian4)
            {
                DrawZhuiMian4();
            }
            else if(cur_work_mod==luowen1)
            {
                DrawLuoWen1();
            }
            else if(cur_work_mod==luowen2)
            {
                DrawLuoWen2();
            }
            else if(cur_work_mod==luowen3)
            {
                DrawLuoWen3();
            }
            else if(cur_work_mod==luowen4)
            {
                DrawLuoWen4();
            }
            else if(cur_work_mod==daojiao1)
            {
                DrawDaoJiao1();
            }
            else if(cur_work_mod==daojiao2)
            {
                DrawDaoJiao2();
            }
            else if(cur_work_mod==daojiao3)
            {
                DrawDaoJiao3();
            }
            else if(cur_work_mod==daojiao4)
            {
                DrawDaoJiao4();
            }

        }
        else
        {
            ui->knife_dir->show();
            DrawBangLiao();
        }
    }
    DrawDirection();
    painter.end();

    //update();
}
