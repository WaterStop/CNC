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
    set_wg3_edit_pos();
    set_wg3_label_pos();
    DisLabel_title();
    DealSlot();
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(setpoint(int)));//调整用
    UpdataTimer();
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

void widget3::set_wg3_edit_pos()
{
    //ui->edit_0->setStyleSheet("color: rgb(255, 255, 255);border-style:outset;background:transparent;");
    //ui->edit_1->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    set_edit_style();
    ui->edit_0->setFont(weiruanyahei6);
    ui->edit_1->setFont(weiruanyahei6);
    ui->edit_2->setFont(weiruanyahei6);
    ui->edit_3->setFont(weiruanyahei6);
    ui->edit_4->setFont(weiruanyahei6);
    ui->edit_5->setFont(weiruanyahei6);
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

void widget3::DealSlot()
{
    connect(ui->edit_0, SIGNAL(clicked()), this, SLOT(show_keyboard_slot()));
    connect(ui->edit_1, SIGNAL(clicked()), this, SLOT(show_keyboard_slot1()));
    connect(ui->edit_2, SIGNAL(clicked()), this, SLOT(show_keyboard_slot2()));
    connect(ui->edit_3, SIGNAL(clicked()), this, SLOT(show_keyboard_slot3()));
    connect(ui->edit_4, SIGNAL(clicked()), this, SLOT(show_keyboard_slot4()));
    connect(ui->edit_5, SIGNAL(clicked()), this, SLOT(show_keyboard_slot5()));
    connect(ui->edit_0, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_2, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_3, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_4, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_5, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
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
}

void widget3::deal_enter_slot()
{
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(cur_Node);
    if(barstock_flg==1)
    {
        qDebug()<<"棒料设置";
        barstock_width = ui->edit_0->text().toDouble();//设置棒料长
        barstock_height = ui->edit_1->text().toDouble();//设置棒料宽
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
    set_edit_style();

    painter.end();
}

void widget3::set_edit_style()
{
    if(is_work==0)
    {
        ui->edit_0->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
        ui->edit_1->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
        ui->edit_2->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
        ui->edit_3->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
        ui->edit_4->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
        ui->edit_5->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color: rgb(255, 255, 255);");
    }
    else
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

    //--------------------
    QPainter painter1(this);
    painter1.setRenderHint(QPainter::SmoothPixmapTransform, true); //平滑像素图，防止图形走样
    QPixmap disc1(":/new/blue_pic/wg2_point.png");
    // 设定旋转中心点
    painter1.translate(x1,y1);
    // 旋转的角度
    painter1.rotate(cur_angle);
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
    painter2.rotate(cur_angle);
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
    painter3.rotate(cur_angle);
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
    update();
}

void widget3::Info_dis()
{
    QString str;
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(dealInterfaceData->m_mSeq.index.num);
    ui->edit_0->setFocus();
    ui->edit_0->selectAll();
    qDebug()<<"Info_dis--cur_work_mod="<<cur_work_mod;
    switch (cur_work_mod)
    {
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
        break;
        default:
        break;
    }
}

void widget3::DisLabel_title()
{
    if(barstock_flg==0)
    {
        ui->edit_5->show();
        switch (cur_work_mod)
        {
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
        ui->edit_1->show();
        ui->edit_2->hide();
        ui->edit_5->hide();
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
    timer = new QTimer();//添加定时器
    //timer->setInterval(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_on_slot()));
    timer->start(20);

}

void widget3::Timer_on_slot()
{
    QString str;
    str = QString("%1r/min").arg(motion_internal->spin_data[0].spind_speed_set);//主轴速度
    ui->zhuzhou->setText(str);
    str = QString("%1%").arg(QString::number(motion_internal->spin_data[0].spindle_scale*100).toInt());//主轴倍率
    label_zhuzhou_per->setText(str);
    if(RadiusPrg==0)
    {
        str = QString("%1mm").arg(QString::number(motion_internal->current_pos[0]*2,'f',3));//X轴位置
        ui->pos_x0->setText(str);
    }
    else
    {
        str = QString("%1mm").arg(QString::number(motion_internal->current_pos[0],'f',3));//X轴位置
        ui->pos_x0->setText(str);
    }
    str = QString("%1mm").arg(QString::number(motion_internal->current_pos[1],'f',3));
    ui->pos_z0->setText(str);
    str = QString("%1mm").arg(0);
    ui->pos_z1->setText(str);
    str = QString("%1mm/min").arg(QString::number(motion_status->current_vel).toInt());//实时速度
    ui->speed->setText(str);
    str = QString("%1mm/min").arg(QString::number(motion_status->requested_vel).toInt());//设定速度
    label_request_speed->setText(str);
    str = QString("%1%").arg(QString::number(motion_status->feed_scale*100).toInt());//进给速率
    label_feed_per->setText(str);
}

