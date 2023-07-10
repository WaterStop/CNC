#include "widget3.h"
#include "ui_widget3.h"
#include "shm.h"
#include "motion.h"

int cur_angle;
static int cur_edit_No = 0;//当前调用编辑框序号

widget3::widget3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget3)
{
    ui->setupUi(this);
    //set_wg3_background();
    info_init();


    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(setpoint(int)));//调整用
    ui->horizontalSlider->hide();//调整用

}

widget3::~widget3()
{
    delete ui;
}

void widget3::set_wg3_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg3_bk7.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget3::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg3_bk7.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget3::info_init()
{
    int i;
    set_wg3_edit_pos();
    set_wg3_label_pos();

    set_button();
    QFont font("Microsoft YaHei", 6, 75, false);

    for (i=0;i<3;i++)
    {
        lab_pro[i] = new QLabel(ui->frame);
        lab_pro[i]->setFont(weiruanyahei4);
        lab_pro[i]->setAlignment(Qt::AlignCenter);
        lab_pro[i]->setStyleSheet("color: rgb(255, 255, 255);");
    }
    lab_pro[0]->setGeometry(186,65,100,30);
    lab_pro[1]->setGeometry(186,115,100,30);
    lab_pro[2]->setGeometry(186,165,100,30);
    for (i=0;i<5;i++)
    {
        lab_val[i] = new QLabel(ui->frame);
        lab_val[i]->setFont(font);
        lab_val[i]->setAlignment(Qt::AlignRight);
        lab_val[i]->setStyleSheet("color: rgb(255, 255, 255);");
    }
        lab_val[0]->setGeometry(22,35,95,23);
        lab_val[1]->setGeometry(42,90,95,23);
        lab_val[2]->setGeometry(42,145,95,23);
        lab_val[3]->setGeometry(42,195,95,23);
        lab_val[4]->setGeometry(15,240,95,23);

   for (i=0;i<2;i++)
   {
       lab_dir[i] = new QLabel(ui->frame);
       lab_dir[i]->setGeometry(45+i*140,305,20,20);
   }

    DisLabel_title();
    DealSlot();

}

void widget3::set_wg3_edit_pos()
{
    //ui->edit_0->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
    //ui->edit_1->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    set_edit_style_slot();
    ui->edit_0->setFont(weiruanyahei4);
    ui->edit_1->setFont(weiruanyahei4);
    ui->edit_2->setFont(weiruanyahei4);
    ui->edit_3->setFont(weiruanyahei4);
    ui->edit_4->setFont(weiruanyahei4);
    ui->edit_5->setFont(weiruanyahei4);

    ui->edit_0->hide();
    ui->edit_1->hide();
    ui->edit_2->hide();
    ui->edit_3->hide();
    ui->edit_4->hide();
    ui->edit_5->hide();

    edit_L0 = new MyLineEdit(ui->frame);
    edit_D0 = new MyLineEdit(ui->frame);
    edit_L1 = new MyLineEdit(ui->frame);
    edit_D1 = new MyLineEdit(ui->frame);
    edit_L0->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    edit_D0->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    edit_L1->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");
    edit_D1->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");

    ui->edit_0->setFocusPolicy(Qt::NoFocus);
    ui->edit_1->setFocusPolicy(Qt::NoFocus);
    ui->edit_2->setFocusPolicy(Qt::NoFocus);
    ui->edit_3->setFocusPolicy(Qt::NoFocus);
    ui->edit_4->setFocusPolicy(Qt::NoFocus);
    ui->edit_5->setFocusPolicy(Qt::NoFocus);
//    ui->edit_0->setStyleSheet("color: rgb(255, 255, 255);");
//    ui->edit_1->setStyleSheet("color: rgb(255, 255, 255);");
//    ui->edit_2->setStyleSheet("color: rgb(255, 255, 255);");
//    ui->edit_3->setStyleSheet("color: rgb(255, 255, 255);");
//    ui->edit_4->setStyleSheet("color: rgb(255, 255, 255);");
//    ui->edit_5->setStyleSheet("color: rgb(255, 255, 255);");
    if(scr_size==0)
    {
        ui->edit_0->setGeometry(20,300,85,20);
        ui->edit_1->setGeometry(45,342,85,20);
        ui->edit_2->setGeometry(45,342,85,20);
        ui->edit_3->setGeometry(150,300,85,20);
        ui->edit_4->setGeometry(45,342,85,20);
        ui->edit_5->setGeometry(45,342,85,20);

    }
    else if(scr_size==1)
    {
        ui->edit_0->setGeometry(48,305,87,23);
        ui->edit_1->setGeometry(48,335,87,23);
        ui->edit_2->setGeometry(48,365,87,23);
        ui->edit_3->setGeometry(190,305,87,23);
        ui->edit_4->setGeometry(190,335,87,23);
        ui->edit_5->setGeometry(190,365,87,23);
    }

    edit_L0->setGeometry(48,305,87,23);
    edit_D0->setGeometry(48,335,87,23);
    edit_L1->setGeometry(190,305,87,23);
    edit_D1->setGeometry(190,335,87,23);
    edit_L0->setFont(weiruanyahei4);
    edit_D0->setFont(weiruanyahei4);
    edit_L1->setFont(weiruanyahei4);
    edit_D1->setFont(weiruanyahei4);
    edit_L0->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    edit_D0->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    edit_L1->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    edit_D1->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
}

void widget3::loadWorkInfo(int index)
{
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(index);
    QString str;

    if(cur_work_mod==bangliao)
    {
        str = QString("%1").arg(barstock_width);
        //ui->edit_0->setText(str);
        edit_L0->setText(str);
        str = QString("%1").arg(barstock_height);
        //ui->edit_1->setText(str);
        edit_D0->setText(str);
        str = QString("%1").arg("");
        ui->edit_2->setText(str);
        str = QString("%1").arg(barstock_L1);
       // ui->edit_3->setText(str);
        edit_L1->setText(str);
        str = QString("%1").arg(barstock_D1);
        //ui->edit_4->setText(str);
        edit_L1->setText(str);
        str = QString("%1").arg("");
        ui->edit_5->setText(str);
    }
}

void widget3::set_wg3_label_pos()
{
    QFont ft;
    //QLabel label_zhuzhou_per,label_feed_per;
    label_zhuzhou_per->setStyleSheet("color: rgb(255, 255, 255);");
    label_feed_per->setStyleSheet("color: rgb(255, 255, 255);");
    label_request_speed->setStyleSheet("color: rgb(255, 255, 255);");
    label_request_speed->setAlignment(Qt::AlignRight);

    if(scr_size==0)
    {
        ui->zhuzhou->setGeometry(75,35,95,23);
        ui->pos_x0->setGeometry(75,90,95,23);
        ui->pos_z0->setGeometry(75,145,95,23);
        ui->pos_z1->setGeometry(75,195,95,23);
        ui->speed->setGeometry(75,240,95,23);

        ft.setPointSize(9);
        ui->zhuzhou->setFont(ft);
        ui->pos_x0->setFont(ft);
        ui->pos_z0->setFont(ft);
        ui->pos_z1->setFont(ft);
        ui->speed->setFont(ft);
    }
    else if(scr_size==1)
    {
        ui->zhuzhou->setGeometry(75,35,95,23);
        ui->pos_x0->setGeometry(75,90,95,23);
        ui->pos_z0->setGeometry(75,145,95,23);
        ui->pos_z1->setGeometry(75,195,95,23);
        ui->speed->setGeometry(75,240,95,23);
        label_request_speed->setGeometry(75,230,95,23);
        label_request_speed->hide();
//        lab_val[0]->setGeometry(55,35,95,23);
//        lab_val[1]->setGeometry(55,90,95,23);
//        lab_val[2]->setGeometry(55,145,95,23);
//        lab_val[3]->setGeometry(55,195,95,23);
//        lab_val[4]->setGeometry(55,240,95,23);

        ui->label_0->setGeometry(12,300,30,30);
        ui->label_1->setGeometry(12,330,30,30);
        ui->label_2->setGeometry(12,360,30,30);
        ui->label_3->setGeometry(155,300,30,30);
        ui->label_4->setGeometry(155,330,30,30);
        ui->label_5->setGeometry(155,360,30,30);
        label_zhuzhou_per->setGeometry(20,57,40,20);
        label_feed_per->setGeometry(220,265,100,20);

        ft.setPointSize(12);
        ui->zhuzhou->setFont(weiruanyahei4);
        ui->pos_x0->setFont(weiruanyahei4);
        ui->pos_z0->setFont(weiruanyahei4);
        ui->pos_z1->setFont(weiruanyahei4);
        ui->speed->setFont(weiruanyahei4);
        label_request_speed->setFont(weiruanyahei4);


        ft.setPointSize(14);
        ui->label_0->setFont(weiruanyahei4);
        ui->label_1->setFont(weiruanyahei4);
        ui->label_2->setFont(weiruanyahei4);
        ui->label_3->setFont(weiruanyahei4);
        ui->label_4->setFont(weiruanyahei4);
        ui->label_5->setFont(weiruanyahei4);
        label_zhuzhou_per->setFont(weiruanyahei4);
        label_feed_per->setFont(weiruanyahei4);
    }

}

void widget3::set_wg3_label_point(int angle)
{
    QMatrix matrix;
    matrix.rotate(angle);
}

void widget3::set_button()
{
    int i;
    for (i=0;i<3;i++)
    {
        axis_zero[i] = new QPushButton(ui->frame);
        axis_zero[i]->setGeometry(18,80+i*55,40,40);
        axis_zero[i]->setStyleSheet("background:transparent;");
        axis_zero[i]->setFocusPolicy(Qt::NoFocus);//无焦点设置
    }
}

void widget3::DealSlot()
{
    int i;
//    connect(ui->edit_0, SIGNAL(clicked()), this, SLOT(show_keyboard_slot()));
//    connect(ui->edit_1, SIGNAL(clicked()), this, SLOT(show_keyboard_slot1()));
//    connect(ui->edit_2, SIGNAL(clicked()), this, SLOT(show_keyboard_slot2()));
//    connect(ui->edit_3, SIGNAL(clicked()), this, SLOT(show_keyboard_slot3()));
//    connect(ui->edit_4, SIGNAL(clicked()), this, SLOT(show_keyboard_slot4()));
//    connect(ui->edit_5, SIGNAL(clicked()), this, SLOT(show_keyboard_slot5()));
//    connect(ui->edit_0, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
//    connect(ui->edit_1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
//    connect(ui->edit_2, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
//    connect(ui->edit_3, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
//    connect(ui->edit_4, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
//    connect(ui->edit_5, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(axis_zero[0], SIGNAL(released()), this, SLOT(return_zero_slot_X()));
    connect(axis_zero[1], SIGNAL(released()), this, SLOT(return_zero_slot_Z()));
    connect(edit_L0, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(edit_D0, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(edit_L1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(edit_D1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(edit_L0, SIGNAL(clicked()), this, SLOT(show_keyboard_slot()));
    connect(edit_D0, SIGNAL(clicked()), this, SLOT(show_keyboard_slot1()));
    connect(edit_L1, SIGNAL(clicked()), this, SLOT(show_keyboard_slot3()));
    connect(edit_D1, SIGNAL(clicked()), this, SLOT(show_keyboard_slot4()));
}

void widget3::show_keyboard_slot()
{
    cur_edit_No =0;
    if(is_work==0)
    {
        emit edit_press_signal(0);
    }
}

void widget3::show_keyboard_slot1()
{
    cur_edit_No =1;
    if(is_work==0)
    {
        emit edit_press_signal(1);
    }
}

void widget3::show_keyboard_slot2()
{
    cur_edit_No =2;
    if(is_work==0)
    {
        emit edit_press_signal(2);
    }
}

void widget3::show_keyboard_slot3()
{
    cur_edit_No =3;
    if(is_work==0)
    {
        emit edit_press_signal(3);
    }
}

void widget3::show_keyboard_slot4()
{
    cur_edit_No =4;
    if(is_work==0)
    {
        emit edit_press_signal(4);
    }
}

void widget3::show_keyboard_slot5()
{
    cur_edit_No =5;
    if(is_work==0)
    {
        emit edit_press_signal(5);
    }
}

void widget3::edit_input_slot(QString str)
{

    if(ui->edit_0->hasFocus())
    {
        emit edit_input_signal(1,str);
    }
    else if(ui->edit_1->hasFocus())
    {
        emit edit_input_signal(2,str);
    }
    else if(ui->edit_2->hasFocus())
    {
        emit edit_input_signal(3,str);
    }
    else if(ui->edit_3->hasFocus())
    {
        emit edit_input_signal(4,str);
    }
    else if(ui->edit_4->hasFocus())
    {
        emit edit_input_signal(5,str);
    }
    else if(ui->edit_5->hasFocus())
    {
        emit edit_input_signal(6,str);
    }

    if(edit_L0->hasFocus())
    {
        emit edit_input_signal(1,str);
    }
    else if(edit_D0->hasFocus())
    {
        emit edit_input_signal(2,str);
    }
    else if(edit_L1->hasFocus())
    {
        emit edit_input_signal(4,str);
    }
    else if(edit_D1->hasFocus())
    {
        emit edit_input_signal(5,str);
    }
}

void widget3::return_zero_slot_X()//回零
{
    gui_ctl->request_mac_home[0]=1;
}

void widget3::return_zero_slot_Z()//回零
{
    gui_ctl->request_mac_home[1]=1;
}

void widget3::deal_enter_slot()
{
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(cur_Node);
    if(barstock_flg==1)
    {
//        barstock_width = ui->edit_0->text().toDouble();//设置棒料长
//        barstock_height = ui->edit_1->text().toDouble();//设置棒料宽
        barstock_width = edit_L0->text().toInt();//设置棒料长
        barstock_height = edit_D0->text().toInt();//设置棒料宽
        barstock_L1 = edit_L1->text().toInt();//设置起刀点z
        barstock_D1 = edit_D1->text().toInt();//设置起刀点x
        qDebug()<<"barstock_width="<<barstock_width;
        barstock_set_signal();
        emit close_keyboard_signal();
        return;
    }
    switch (tem_val->type)
    {
        case OUTER_CIRCLE_ONE:
        if(cur_edit_No==0)
        {
            tem_val->outerCircle1.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->outerCircle1.F = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {

        }
        else if(cur_edit_No==3)
        {
            tem_val->outerCircle1.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->outerCircle1.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->outerCircle1.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case OUTER_CIRCLE_TWO:
        if(cur_edit_No==0)
        {
            tem_val->outerCircle2.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->outerCircle2.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->outerCircle2.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->outerCircle2.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->outerCircle2.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->outerCircle2.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case OUTER_CIRCLE_THREE:
        if(cur_edit_No==0)
        {
            tem_val->outerCircle3.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->outerCircle3.R = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->outerCircle3.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->outerCircle3.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->outerCircle3.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->outerCircle3.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case END_FACE_ONE:
        if(cur_edit_No==0)
        {
            tem_val->endFace1.Lr = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->endFace1.F = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {

        }
        else if(cur_edit_No==3)
        {
            tem_val->endFace1.deltaT = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->endFace1.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->endFace1.CT = ui->edit_5->text().toDouble();
        }
        break;
        case END_FACE_TWO:
        if(cur_edit_No==0)
        {
            tem_val->endFace2.Lr = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->endFace2.Tw = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->endFace2.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->endFace2.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->endFace2.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->endFace2.W = ui->edit_5->text().toDouble();
        }
        break;
        case END_FACE_THREE:
        if(cur_edit_No==0)
        {
            tem_val->endFace3.Lr = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->endFace3.F = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {

        }
        else if(cur_edit_No==3)
        {
            tem_val->endFace3.deltaT = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->endFace3.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->endFace3.CT = ui->edit_5->text().toDouble();
        }
        break;
        case INNER_HOLE_ONE:
        if(cur_edit_No==0)
        {
            tem_val->innerHole1.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->innerHole1.F = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {

        }
        else if(cur_edit_No==3)
        {
            tem_val->innerHole1.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->innerHole1.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->innerHole1.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case INNER_HOLE_TWO:
        if(cur_edit_No==0)
        {
            tem_val->innerHole2.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->innerHole2.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->innerHole2.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->innerHole2.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->innerHole2.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->innerHole2.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case INNER_HOLE_THREE:
        if(cur_edit_No==0)
        {
            tem_val->innerHole3.Lr = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->innerHole3.W = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->innerHole3.W1 = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->innerHole3.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->innerHole3.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->innerHole3.Tw = ui->edit_5->text().toDouble();
        }
        break;
        case INNER_HOLE_FOUR:
        if(cur_edit_No==0)
        {
            tem_val->innerHole4.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->innerHole4.R = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->innerHole4.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->innerHole4.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->innerHole4.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->innerHole4.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case INNER_HOLE_FIVE:
        if(cur_edit_No==0)
        {
            tem_val->innerHole5.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->innerHole5.F = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {

        }
        else if(cur_edit_No==3)
        {
            tem_val->innerHole5.deltaT = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->innerHole5.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->innerHole5.BT = ui->edit_5->text().toDouble();
        }
        break;
        case CONE_FACE_ONE:
        if(cur_edit_No==0)
        {
            tem_val->coneFace1.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->coneFace1.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->coneFace1.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->coneFace1.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->coneFace1.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->coneFace1.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case CONE_FACE_TWO:
        if(cur_edit_No==0)
        {
            tem_val->coneFace2.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->coneFace2.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->coneFace2.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->coneFace2.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->coneFace2.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->coneFace2.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case CONE_FACE_THREE:
        if(cur_edit_No==0)
        {
            tem_val->coneFace3.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->coneFace3.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->coneFace3.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->coneFace3.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->coneFace3.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->coneFace3.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case CONE_FACE_FOUR:
        if(cur_edit_No==0)
        {
            tem_val->coneFace4.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->coneFace4.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->coneFace4.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->coneFace4.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->coneFace4.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->coneFace4.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case SCREW_THREAD_ONE:
        if(cur_edit_No==0)
        {
            tem_val->screwThread1.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->screwThread1.Tp = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->screwThread1.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->screwThread1.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->screwThread1.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->screwThread1.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case SCREW_THREAD_TWO:
        if(cur_edit_No==0)
        {
            tem_val->screwThread2.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->screwThread2.Tp = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->screwThread2.A = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->screwThread2.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->screwThread2.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->screwThread2.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case SCREW_THREAD_THREE:
        if(cur_edit_No==0)
        {
            tem_val->screwThread3.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->screwThread3.Tp = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->screwThread3.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->screwThread3.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->screwThread3.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->screwThread3.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case SCREW_THREAD_FOUR:
        if(cur_edit_No==0)
        {
            tem_val->screwThread4.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->screwThread4.Tp = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->screwThread4.A = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->screwThread4.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->screwThread4.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->screwThread4.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case CHAMFER_ONE:
        if(cur_edit_No==0)
        {
            tem_val->chamfer1.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->chamfer1.R = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->chamfer1.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->chamfer1.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->chamfer1.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->chamfer1.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case CHAMFER_TWO:
        if(cur_edit_No==0)
        {
            tem_val->chamfer2.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->chamfer2.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->chamfer2.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->chamfer2.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->chamfer2.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->chamfer2.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case CHAMFER_THREE:
        if(cur_edit_No==0)
        {
            tem_val->chamfer3.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->chamfer3.R = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->chamfer3.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->chamfer3.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->chamfer3.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->chamfer3.Cr = ui->edit_5->text().toDouble();
        }
        break;
        case CHAMFER_FOUR:
        if(cur_edit_No==0)
        {
            tem_val->chamfer4.L = ui->edit_0->text().toDouble();
        }
        else if(cur_edit_No==1)
        {
            tem_val->chamfer4.A = ui->edit_1->text().toDouble();
        }
        else if(cur_edit_No==2)
        {
            tem_val->chamfer4.F = ui->edit_2->text().toDouble();
        }
        else if(cur_edit_No==3)
        {
            tem_val->chamfer4.Tr = ui->edit_3->text().toDouble();
        }
        else if(cur_edit_No==4)
        {
            tem_val->chamfer4.Cn = ui->edit_4->text().toInt();
        }
        else if(cur_edit_No==5)
        {
            tem_val->chamfer4.Cr = ui->edit_5->text().toDouble();
        }
        break;
        default:
        break;
    }
    emit close_keyboard_signal();
}

void widget3::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QPixmap pixmap(":/new/blue_pic/wg3_bk7.png");

    painter.begin(this);
    painter.drawPixmap(rect(),pixmap,QRect());

    deal_point();

    painter.end();
}

void widget3::set_edit_style_slot()
{
//    if(is_work==0)
//    {
//        ui->edit_0->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
//        ui->edit_1->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
//        ui->edit_2->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
//        ui->edit_3->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
//        ui->edit_4->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
//        ui->edit_5->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
//    }
//    else
    {
        ui->edit_0->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
        ui->edit_1->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
        ui->edit_2->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
        ui->edit_3->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
        ui->edit_4->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
        ui->edit_5->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
    }
}

void widget3::deal_point()
{
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int length,weigth;//长宽
    if(scr_size==0)
    {
        x1 = 182;
        y1 = 52;
        x2 = 182;
        y2 = 93;
        x3 = 182;
        y3 = 135;
        length =34;
        weigth = 17;
    }
    else if(scr_size==1)
    {
        x1 = 237;
        y1 = 67;
        x2 = 236;
        y2 = 117;
        x3 = 236;
        y3 = 167;
        length =30;
        weigth = 20;
    }
//    motion_status->spind_to_st[0]=3;
//    motion_status->axis_to_st[0] =1;
//    motion_status->axis_to_st[1] =2;
    //--------------------
    QPainter painter1(this);
    painter1.setRenderHint(QPainter::SmoothPixmapTransform, true); //平滑像素图，防止图形走样
    QPixmap disc1(":/new/blue_pic/wg2_point.png");
    // 设定旋转中心点
    painter1.translate(x1,y1);
    // 旋转的角度
    painter1.rotate(qAbs(motion_status->tor_ref[motion_status->spind_to_st[0]])*180/100);//主轴
    // 恢复中心点
    painter1.translate(-x1,-y1);
    // 画图操作
    painter1.drawPixmap(x1-(length/3)*2,y1-weigth/2,length,weigth, disc1);

    //---------------
    QPainter painter2(this);
    painter2.setRenderHint(QPainter::SmoothPixmapTransform, true); //平滑像素图，防止图形走样
    QPixmap disc2(":/new/blue_pic/wg2_point.png");
    // 设定旋转中心点
    painter2.translate(x2,y2);
    // 旋转的角度
    painter2.rotate(qAbs(motion_status->tor_ref[motion_status->axis_to_st[0]])*180/100);//X轴
    // 恢复中心点
    painter2.translate(-x2,-y2);
    // 画图操作
    painter2.drawPixmap(x2-(length/3)*2,y2-weigth/2,length,weigth, disc2);


    //-------------------
    QPainter painter3(this);
    painter3.setRenderHint(QPainter::SmoothPixmapTransform, true); //平滑像素图，防止图形走样
    QPixmap disc3(":/new/blue_pic/wg2_point.png");
    // 设定旋转中心点
    painter3.translate(x3,y3);
    // 旋转的角度
    painter3.rotate(qAbs(motion_status->tor_ref[motion_status->axis_to_st[1]])*180/100);//Z轴
    // 恢复中心点
    painter3.translate(-x3,-y3);
    // 画图操作
    painter3.drawPixmap(x3-(length/3)*2,y3-weigth/2,length,weigth, disc3);
}

void widget3::setpoint(int value)
{
    cur_angle = value;
    if(value>90)//测试
    {
        is_work = 1;
    }
    else
    {
        is_work = 0;
    }
    set_edit_style_slot();
    //update();
}

void widget3::Info_dis()
{
    QString str;
    int X_dir,Z_dir;
    machineNode *tem_val;
    //tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);
    tem_val = dealInterfaceData->findNode(cur_Node);
    //ui->edit_0->setFocus();
    //ui->edit_0->selectAll();
    switch (cur_work_mod)
    {
        case bangliao:
        str = QString("%1").arg(barstock_width);
        //ui->edit_0->setText(str);
        edit_L0->setText(str);
        str = QString("%1").arg(barstock_height);
        ui->edit_1->setText(str);
        edit_D0->setText(str);
        str = QString("%1").arg(barstock_L1);
        ui->edit_3->setText(str);
        edit_L1->setText(str);
        str = QString("%1").arg(barstock_D1);
        ui->edit_4->setText(str);
        edit_D1->setText(str);
        break;
        case waiyuan1:
        str = QString("%1").arg(tem_val->outerCircle1.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->outerCircle1.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->outerCircle1.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->outerCircle1.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->outerCircle1.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->outerCircle1.xDir;
        Z_dir = tem_val->outerCircle1.zDir;
        break;
        case waiyuan2:
        str = QString("%1").arg(tem_val->outerCircle2.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->outerCircle2.xDir;
        Z_dir = tem_val->outerCircle2.zDir;
        break;
        case waiyuan3:
        str = QString("%1").arg(tem_val->outerCircle3.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->outerCircle3.R);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->outerCircle3.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->outerCircle3.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->outerCircle3.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->outerCircle3.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->outerCircle3.xDir;
        Z_dir = tem_val->outerCircle3.zDir;
        break;
        case duanmian1:
        str = QString("%1").arg(tem_val->endFace1.Lr);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->endFace1.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->endFace1.deltaT);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->endFace1.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->endFace1.CT);
        ui->edit_5->setText(str);
        X_dir = tem_val->endFace1.xDir;
        Z_dir = tem_val->endFace1.zDir;
        break;
        case duanmian2:
        str = QString("%1").arg(tem_val->endFace2.Lr);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->endFace2.Tw);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->endFace2.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->endFace2.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->endFace2.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->endFace2.W);
        ui->edit_5->setText(str);
        X_dir = tem_val->endFace2.xDir;
        Z_dir = tem_val->endFace2.zDir;
        break;
        case duanmian3:
        str = QString("%1").arg(tem_val->endFace3.Lr);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->endFace3.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->endFace3.deltaT);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->endFace3.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->endFace3.CT);
        ui->edit_5->setText(str);
        X_dir = tem_val->endFace3.xDir;
        Z_dir = tem_val->endFace3.zDir;
        break;
        case likong1:
        str = QString("%1").arg(tem_val->innerHole1.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->innerHole1.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->innerHole1.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->innerHole1.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->innerHole1.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->innerHole1.xDir;
        Z_dir = tem_val->innerHole1.zDir;
        break;
        case likong2:
        str = QString("%1").arg(tem_val->innerHole2.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->innerHole2.xDir;
        Z_dir = tem_val->innerHole2.zDir;
        break;
        case likong3:
        str = QString("%1").arg(tem_val->innerHole3.Lr);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->innerHole3.W);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->innerHole3.W1);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->innerHole3.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->innerHole3.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->innerHole3.Tw);
        ui->edit_5->setText(str);
        X_dir = tem_val->innerHole3.xDir;
        Z_dir = tem_val->innerHole3.zDir;
        break;
        case likong4:
        str = QString("%1").arg(tem_val->innerHole4.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->innerHole4.R);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->innerHole4.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->innerHole4.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->innerHole4.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->innerHole4.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->innerHole4.xDir;
        Z_dir = tem_val->innerHole4.zDir;
        break;
        case likong5:
        str = QString("%1").arg(tem_val->innerHole5.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->innerHole5.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->innerHole5.deltaT);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->innerHole5.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->innerHole5.BT);
        ui->edit_5->setText(str);
        X_dir = tem_val->innerHole5.xDir;
        Z_dir = tem_val->innerHole5.zDir;
        break;
        case zhuimian1:
        str = QString("%1").arg(tem_val->coneFace1.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->coneFace1.xDir;
        Z_dir = tem_val->coneFace1.zDir;
        break;
        case zhuimian2:
        str = QString("%1").arg(tem_val->coneFace2.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->coneFace2.xDir;
        Z_dir = tem_val->coneFace2.zDir;
        break;
        case zhuimian3:
        str = QString("%1").arg(tem_val->coneFace3.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->coneFace3.xDir;
        Z_dir = tem_val->coneFace3.zDir;
        break;
        case zhuimian4:
        str = QString("%1").arg(tem_val->coneFace4.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->coneFace4.xDir;
        Z_dir = tem_val->coneFace4.zDir;
        break;
        case luowen1:
        str = QString("%1").arg(tem_val->screwThread1.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Tp);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->screwThread1.xDir;
        Z_dir = tem_val->screwThread1.zDir;
        break;
        case luowen2:
        str = QString("%1").arg(tem_val->screwThread2.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Tp);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.A);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->screwThread2.xDir;
        Z_dir = tem_val->screwThread2.zDir;
        break;
        case luowen3:
        str = QString("%1").arg(tem_val->screwThread3.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Tp);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.F);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->screwThread3.xDir;
        Z_dir = tem_val->screwThread3.zDir;
        break;
        case luowen4:
        str = QString("%1").arg(tem_val->screwThread4.L);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Tp);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.A);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->screwThread4.xDir;
        Z_dir = tem_val->screwThread4.zDir;
        break;
        case daojiao1:
        str = QString("%1").arg(tem_val->chamfer1.R);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->chamfer1.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->chamfer1.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->chamfer1.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->chamfer1.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->chamfer1.xDir;
        Z_dir = tem_val->chamfer1.zDir;
        break;
        case daojiao2:
        str = QString("%1").arg(tem_val->chamfer2.A);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->chamfer2.xDir;
        Z_dir = tem_val->chamfer2.zDir;
        break;
        case daojiao3:
        str = QString("%1").arg(tem_val->chamfer3.R);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->chamfer3.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->chamfer3.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->chamfer3.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->chamfer3.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->chamfer3.xDir;
        Z_dir = tem_val->chamfer3.zDir;
        break;
        case daojiao4:
        str = QString("%1").arg(tem_val->chamfer4.A);
        ui->edit_0->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.F);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.Tr);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.Cn);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.Cr);
        ui->edit_5->setText(str);
        X_dir = tem_val->chamfer4.xDir;
        Z_dir = tem_val->chamfer4.zDir;
        break;
        default:
        break;
    }
    if(X_dir==-1)
    {
        lab_dir[1]->setStyleSheet("border-image:url(:/new/blue_pic/wg3_edit_up.png);");
    }
    else if(X_dir==1)
    {
        lab_dir[1]->setStyleSheet("border-image:url(:/new/blue_pic/wg3_edit_down.png);");
    }
    if(Z_dir==-1)
    {
        lab_dir[0]->setStyleSheet("border-image:url(:/new/blue_pic/wg3_edit_left.png);");
    }
    else if(Z_dir==1)
    {
        lab_dir[0]->setStyleSheet("border-image:url(:/new/blue_pic/wg3_edit_right.png);");
    }
    //qDebug()<<"X_dir="<<X_dir<<"Z_dir"<<Z_dir;
}

void widget3::DisLabel_title()
{
    if(barstock_flg==0)
    {
        ui->edit_0->show();
        ui->edit_1->show();
        ui->edit_2->show();
        ui->edit_3->show();
        ui->edit_4->show();
        ui->edit_5->show();
        edit_L0->hide();
        edit_D0->hide();
        edit_L1->hide();
        edit_D1->hide();
        for (int i=0;i<2;i++)
        {
            lab_dir[i]->show();
        }
        switch (cur_work_mod)
        {
            case bangliao:
            ui->edit_0->hide();
            ui->edit_1->hide();
            ui->edit_2->hide();
            ui->edit_3->hide();
            ui->edit_4->hide();
            ui->edit_5->hide();            
            edit_L0->show();
            edit_D0->show();
            edit_L1->show();
            edit_D1->show();
            lab_dir[0]->show();
            lab_dir[1]->show();
            ui->label_0->setText("L0");
            ui->label_1->setText("D0");
            ui->label_2->setText("");
            ui->label_3->setText("L1");
            ui->label_4->setText("D1");
            ui->label_5->setText("");
            break;
            case waiyuan1:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("L");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case waiyuan2:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("A");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case waiyuan3:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("R");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case duanmian1:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("Lr");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("△T");
            ui->label_4->setText("Cn");
            ui->label_5->setText("CT");
            break;
            case duanmian2:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("Lr");
            ui->label_1->setText("Tw");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("W");
            break;
            case duanmian3:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("Lr");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("△T");
            ui->label_4->setText("Cn");
            ui->label_5->setText("CT");
            break;
            case likong1:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("L");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case likong2:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("A");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case likong3:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("Lr");
            ui->label_1->setText("W");
            ui->label_2->setText("W1");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Tw");
            break;
            case likong4:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("R");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case likong5:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("L");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("△T");
            ui->label_4->setText("Cn");
            ui->label_5->setText("BT");
            break;
            case zhuimian1:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("A");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case zhuimian2:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("R");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case zhuimian3:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("R");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case zhuimian4:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("R");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case luowen1:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("Tp");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case luowen2:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("Tp");
            ui->label_2->setText("A");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case luowen3:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("Tp");
            ui->label_2->setText("F");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case luowen4:
            ui->edit_1->show();
            ui->edit_2->show();
            ui->label_0->setText("L");
            ui->label_1->setText("Tp");
            ui->label_2->setText("A");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case daojiao1:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("R");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case daojiao2:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("A");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case daojiao3:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("R");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            case daojiao4:
            ui->edit_1->show();
            ui->edit_2->hide();
            ui->label_0->setText("A");
            ui->label_1->setText("F");
            ui->label_2->setText("");
            ui->label_3->setText("Tr");
            ui->label_4->setText("Cn");
            ui->label_5->setText("Cr");
            break;
            default:
            break;
        }
    }
    else
    {
        ui->edit_0->hide();
        ui->edit_1->hide();
        ui->edit_2->hide();
        ui->edit_3->hide();
        ui->edit_4->hide();
        ui->edit_5->hide();
        edit_L0->show();
        edit_D0->show();
        edit_L1->show();
        edit_D1->show();
        lab_dir[0]->hide();
        lab_dir[1]->hide();
        ui->label_0->setText("L0");
        ui->label_1->setText("D0");
        ui->label_2->setText("");
        ui->label_3->setText("L1");
        ui->label_4->setText("D1");
        ui->label_5->setText("");
    }

}

void widget3::UpdataTimer()
{
    //timer = new QTimer();//添加定时器
    //timer->setInterval(200);
    //connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));
    //timer->start(20);

}

void widget3::Timer_on_slot()
{
    QString str;
    int tmp;
    str = QString("%1").arg(motion_internal->spin_data[0].CncViewSSpeed);//主轴速度
    ui->zhuzhou->setText("rpm/min");
    lab_val[0]->setText(str);
    //tmp_int = motion_internal->spin_data[0].spindle_scale*100;
    //str = QString("%1%").arg(QString::number(motion_internal->spin_data[0].spindle_scale*100).toInt());//主轴倍率
    //str = QString("%1%").arg(tmp_int);//主轴倍率
    //label_zhuzhou_per->setText(str);

    if(RadiusPrg==0)
    {
        str = QString("%1").arg(QString::number(motion_internal->current_pos[0]*2,'f',3));//X轴位置
        ui->pos_x0->setText("mm");
        lab_val[1]->setText(str);
    }
    else
    {
        str = QString("%1").arg(QString::number(motion_internal->current_pos[0],'f',3));//X轴位置
        ui->pos_x0->setText("mm");
        lab_val[1]->setText(str);
    }
    str = QString("%1").arg(QString::number(motion_internal->current_pos[1],'f',3));
    ui->pos_z0->setText("mm");
    lab_val[2]->setText(str);
    str = QString("%1").arg(0);
    ui->pos_z1->setText("mm");
    lab_val[3]->setText(str);
    tmp = motion_status->current_val_axis_compound;//实时速度
    str = QString("%1").arg(QString::number(tmp));
    ui->speed->setText("mm/min");
    lab_val[4]->setText(str);
//    str = QString("%1mm/min").arg(QString::number(motion_status->requested_vel).toInt());//设定速度
//    label_request_speed->setText(str);
//    str = QString("%1%").arg(QString::number(motion_status->feed_scale*100).toInt());//进给速率
//    label_feed_per->setText(str);

    str = QString("%1%").arg(qAbs(motion_status->tor_ref[motion_status->spind_to_st[0]]));
    lab_pro[0]->setText(str);
    str = QString("%1%").arg(qAbs(motion_status->tor_ref[motion_status->axis_to_st[0]]));
    lab_pro[1]->setText(str);
    str = QString("%1%").arg(qAbs(motion_status->tor_ref[motion_status->axis_to_st[1]]));
    lab_pro[2]->setText(str);
    update();
}

