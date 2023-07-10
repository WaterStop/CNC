#include "wedget1.h"
#include "ui_wedget1.h"

bool PressFlag =false;
bool press_long = 0;

wedget1::wedget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wedget1)
{
    ui->setupUi(this);
    set_wg1_background();
    set_proBar();
    set_proBar_value();
    set_button();
    DealSlot();
    //connect(ui->progressBar,SIGNAL(valueChanged(int)),this,SLOT(set_proBar_value_solt(int)));
    //machineinfo = new MachineSequene();
    ui->progressBar->hide();

}

wedget1::~wedget1()
{
    delete ui;
}



void wedget1::set_wg1_background()
{
//    setAutoFillBackground(true);//做子窗口要设置，否则不显示
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/blue_pic/wg1.png")));
//    setPalette(pal);

    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg1.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void wedget1::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
   Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg1.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void wedget1::paintEvent(QPaintEvent *event)
{
    /*Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    ui->label_bk->resize(this->size());*/



}

void wedget1::set_button()
{
    set_bt_pic();
    ui->bt_0->setGeometry(67,325,84,70);
    ui->bt_1->setGeometry(67,255,84,70);
    ui->bt_2->setGeometry(67,185,84,70);
    ui->bt_3->setGeometry(67,115,84,70);
    ui->bt_4->setGeometry(67,45,84,70);
}

void wedget1::set_proBar()
{
    ui->label_val->setGeometry(25,15,35,30);
    ui->progressBar->setGeometry(25,70,35,315);
    ui->widget_bar->setGeometry(25,45,35,350);
}

void wedget1::set_proBar_value()
{
    QFont ft;
    int value;
    value = 100;
    ui->widget_bar->set_BarValue(value);
    //value = ui->progressBar->value();
    QString str1 = QString::number(value,10);
    QString str = QString("%1%2").arg(str1).arg("%");
    //ui->label_val->setText(QString::number(value,10));//十进制
    ui->label_val->setText(str);//十进制


    if(scr_size==0)
    {
        ft.setPointSize(8);
        ui->label_val->setFont(ft);
    }
    else if(scr_size==1)
    {
        ft.setPointSize(10);
        ui->label_val->setFont(weiruanyahei4);
    }

}


void wedget1::set_proBar_value_solt(int value)
{
    QString str1 = QString::number(value,10);
    QString str = QString("%1%2").arg(str1).arg("%");
    ui->label_val->setText(str);//十进制
}

void wedget1::set_bt_pic()
{
    ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");

}

void wedget1::DealSlot()
{
    connect(ui->bt_0, SIGNAL(released()), this, SLOT(bt_0_slot()));
    connect(ui->bt_1, SIGNAL(released()), this, SLOT(bt_1_slot()));
    connect(ui->bt_2, SIGNAL(released()), this, SLOT(bt_2_slot()));
    connect(ui->bt_3, SIGNAL(released()), this, SLOT(bt_3_slot()));
    connect(ui->bt_4, SIGNAL(released()), this, SLOT(bt_4_slot()));

    connect(ui->bt_0, SIGNAL(pressed()), this, SLOT(bt_0_slot_l()));
    connect(ui->bt_1, SIGNAL(pressed()), this, SLOT(bt_1_slot_l()));
    connect(ui->bt_2, SIGNAL(pressed()), this, SLOT(bt_2_slot_l()));
    connect(ui->bt_3, SIGNAL(pressed()), this, SLOT(bt_3_slot_l()));
    connect(ui->bt_4, SIGNAL(pressed()), this, SLOT(bt_4_slot_l()));
    connect(timer, SIGNAL(timeout()), this, SLOT(long_press_slot()));

}

void wedget1::bt_0_slot_l()
{
    cur_Node = 1;
    press_long = 0;
    timer->start(500);
}

void wedget1::bt_1_slot_l()
{
    cur_Node = 2;
    press_long = 0;
    timer->start(500);
}
void wedget1::bt_2_slot_l()
{
    cur_Node = 3;
    press_long = 0;
    timer->start(500);
}

void wedget1::bt_3_slot_l()
{
    cur_Node = 4;
    press_long = 0;
    timer->start(500);
}

void wedget1::bt_4_slot_l()
{
    cur_Node = 5;
    press_long = 0;
    timer->start(500);
}

void wedget1::long_press_slot()
{
    press_long =1;
    timer->stop();
    emit long_press_signal(cur_Node);
}

void wedget1::bt_0_slot()
{
    if(press_long==0)
    {
        modify_flg = 1;
        timer->stop();
        emit bt_signal(cur_Node);
    }
}

void wedget1::bt_1_slot()
{
    if(press_long==0)
    {
        modify_flg = 1;
        timer->stop();
        emit bt_signal(cur_Node);
    }
}

void wedget1::bt_2_slot()
{
    if(press_long==0)
    {
        modify_flg = 1;
        timer->stop();
        emit bt_signal(cur_Node);
    }
}

void wedget1::bt_3_slot()
{
    if(press_long==0)
    {
        modify_flg = 1;
        timer->stop();
        emit bt_signal(cur_Node);
    }
}

void wedget1::bt_4_slot()
{
    if(press_long==0)
    {
        modify_flg = 1;
        timer->stop();
        emit bt_signal(cur_Node);
    }
}

void wedget1::UpDate_Screen()
{
    update();
}

void wedget1::input_work_pic()
{
    ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");
    ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg1_btbk.png);}");

    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(1);

    if(dealInterfaceData->m_mSeq.index.num<1)return;
    switch (tem_val->type)
    {
        case OUTER_CIRCLE_ONE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_on.png);}");
        break;
        case OUTER_CIRCLE_TWO:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_on.png);}");
        break;
        case OUTER_CIRCLE_THREE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_on.png);}");
        break;
        case END_FACE_ONE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_on.png);}");
        break;
        case END_FACE_TWO:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_on.png);}");
        break;
        case END_FACE_THREE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_on.png);}");
        break;
        case INNER_HOLE_ONE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_on.png);}");
        break;
        case INNER_HOLE_TWO:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_on.png);}");
        break;
        case INNER_HOLE_THREE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_on.png);}");
        break;
        case INNER_HOLE_FOUR:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_on.png);}");
        break;
        case INNER_HOLE_FIVE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_on.png);}");
        break;
        case CONE_FACE_ONE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_on.png);}");
        break;
        case CONE_FACE_TWO:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_on.png);}");
        break;
        case CONE_FACE_THREE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_on.png);}");
        break;
        case CONE_FACE_FOUR:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_on.png);}");
        break;
        case SCREW_THREAD_ONE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_on.png);}");
        break;
        case SCREW_THREAD_TWO:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_on.png);}");
        break;
        case SCREW_THREAD_THREE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_on.png);}");
        break;
        case SCREW_THREAD_FOUR:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_on.png);}");
        break;
        case CHAMFER_ONE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_on.png);}");
        break;
        case CHAMFER_TWO:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_on.png);}");
        break;
        case CHAMFER_THREE:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_on.png);}");
        break;
        case CHAMFER_FOUR:
        ui->bt_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_on.png);}");
        break;
        default:
        break;
    }

    tem_val = dealInterfaceData->findNode(2);
    if(dealInterfaceData->m_mSeq.index.num<2)return;
    switch (tem_val->type)
    {
        case OUTER_CIRCLE_ONE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_on.png);}");
        break;
        case OUTER_CIRCLE_TWO:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_on.png);}");
        break;
        case OUTER_CIRCLE_THREE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_on.png);}");
        break;
        case END_FACE_ONE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_on.png);}");
        break;
        case END_FACE_TWO:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_on.png);}");
        break;
        case END_FACE_THREE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_on.png);}");
        break;
        case INNER_HOLE_ONE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_on.png);}");
        break;
        case INNER_HOLE_TWO:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_on.png);}");
        break;
        case INNER_HOLE_THREE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_on.png);}");
        break;
        case INNER_HOLE_FOUR:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_on.png);}");
        break;
        case INNER_HOLE_FIVE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_on.png);}");
        break;
        case CONE_FACE_ONE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_on.png);}");
        break;
        case CONE_FACE_TWO:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_on.png);}");
        break;
        case CONE_FACE_THREE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_on.png);}");
        break;
        case CONE_FACE_FOUR:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_on.png);}");
        break;
        case SCREW_THREAD_ONE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_on.png);}");
        break;
        case SCREW_THREAD_TWO:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_on.png);}");
        break;
        case SCREW_THREAD_THREE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_on.png);}");
        break;
        case SCREW_THREAD_FOUR:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_on.png);}");
        break;
        case CHAMFER_ONE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_on.png);}");
        break;
        case CHAMFER_TWO:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_on.png);}");
        break;
        case CHAMFER_THREE:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_on.png);}");
        break;
        case CHAMFER_FOUR:
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_on.png);}");
        break;
        default:
        break;
    }

    tem_val = dealInterfaceData->findNode(3);
    if(dealInterfaceData->m_mSeq.index.num<3)return;
    switch (tem_val->type)
    {
        case OUTER_CIRCLE_ONE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_on.png);}");
        break;
        case OUTER_CIRCLE_TWO:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_on.png);}");
        break;
        case OUTER_CIRCLE_THREE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_on.png);}");
        break;
        case END_FACE_ONE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_on.png);}");
        break;
        case END_FACE_TWO:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_on.png);}");
        break;
        case END_FACE_THREE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_on.png);}");
        break;
        case INNER_HOLE_ONE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_on.png);}");
        break;
        case INNER_HOLE_TWO:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_on.png);}");
        break;
        case INNER_HOLE_THREE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_on.png);}");
        break;
        case INNER_HOLE_FOUR:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_on.png);}");
        break;
        case INNER_HOLE_FIVE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_on.png);}");
        break;
        case CONE_FACE_ONE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_on.png);}");
        break;
        case CONE_FACE_TWO:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_on.png);}");
        break;
        case CONE_FACE_THREE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_on.png);}");
        break;
        case CONE_FACE_FOUR:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_on.png);}");
        break;
        case SCREW_THREAD_ONE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_on.png);}");
        break;
        case SCREW_THREAD_TWO:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_on.png);}");
        break;
        case SCREW_THREAD_THREE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_on.png);}");
        break;
        case SCREW_THREAD_FOUR:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_on.png);}");
        break;
        case CHAMFER_ONE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_on.png);}");
        break;
        case CHAMFER_TWO:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_on.png);}");
        break;
        case CHAMFER_THREE:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_on.png);}");
        break;
        case CHAMFER_FOUR:
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_on.png);}");
        break;
        default:
        break;
    }

    tem_val = dealInterfaceData->findNode(4);
    if(dealInterfaceData->m_mSeq.index.num<4)return;
    switch (tem_val->type)
    {
        case OUTER_CIRCLE_ONE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_on.png);}");
        break;
        case OUTER_CIRCLE_TWO:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_on.png);}");
        break;
        case OUTER_CIRCLE_THREE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_on.png);}");
        break;
        case END_FACE_ONE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_on.png);}");
        break;
        case END_FACE_TWO:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_on.png);}");
        break;
        case END_FACE_THREE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_on.png);}");
        break;
        case INNER_HOLE_ONE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_on.png);}");
        break;
        case INNER_HOLE_TWO:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_on.png);}");
        break;
        case INNER_HOLE_THREE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_on.png);}");
        break;
        case INNER_HOLE_FOUR:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_on.png);}");
        break;
        case INNER_HOLE_FIVE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_on.png);}");
        break;
        case CONE_FACE_ONE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_on.png);}");
        break;
        case CONE_FACE_TWO:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_on.png);}");
        break;
        case CONE_FACE_THREE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_on.png);}");
        break;
        case CONE_FACE_FOUR:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_on.png);}");
        break;
        case SCREW_THREAD_ONE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_on.png);}");
        break;
        case SCREW_THREAD_TWO:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_on.png);}");
        break;
        case SCREW_THREAD_THREE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_on.png);}");
        break;
        case SCREW_THREAD_FOUR:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_on.png);}");
        break;
        case CHAMFER_ONE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_on.png);}");
        break;
        case CHAMFER_TWO:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_on.png);}");
        break;
        case CHAMFER_THREE:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_on.png);}");
        break;
        case CHAMFER_FOUR:
        ui->bt_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_on.png);}");
        break;
        default:
        break;
    }

    tem_val = dealInterfaceData->findNode(5);
    if(dealInterfaceData->m_mSeq.index.num<5)return;
    switch (tem_val->type)
    {
        case OUTER_CIRCLE_ONE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan1_on.png);}");
        break;
        case OUTER_CIRCLE_TWO:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan2_on.png);}");
        break;
        case OUTER_CIRCLE_THREE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_waiyuan3_on.png);}");
        break;
        case END_FACE_ONE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian1_on.png);}");
        break;
        case END_FACE_TWO:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian2_on.png);}");
        break;
        case END_FACE_THREE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_duanmian3_on.png);}");
        break;
        case INNER_HOLE_ONE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong1_on.png);}");
        break;
        case INNER_HOLE_TWO:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong2_on.png);}");
        break;
        case INNER_HOLE_THREE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong3_on.png);}");
        break;
        case INNER_HOLE_FOUR:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong4_on.png);}");
        break;
        case INNER_HOLE_FIVE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_likong5_on.png);}");
        break;
        case CONE_FACE_ONE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian1_on.png);}");
        break;
        case CONE_FACE_TWO:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian2_on.png);}");
        break;
        case CONE_FACE_THREE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian3_on.png);}");
        break;
        case CONE_FACE_FOUR:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_zhuimian4_on.png);}");
        break;
        case SCREW_THREAD_ONE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen1_on.png);}");
        break;
        case SCREW_THREAD_TWO:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen2_on.png);}");
        break;
        case SCREW_THREAD_THREE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen3_on.png);}");
        break;
        case SCREW_THREAD_FOUR:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_luowen4_on.png);}");
        break;
        case CHAMFER_ONE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao1_on.png);}");
        break;
        case CHAMFER_TWO:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao2_on.png);}");
        break;
        case CHAMFER_THREE:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao3_on.png);}");
        break;
        case CHAMFER_FOUR:
        ui->bt_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/popwin2_daojiao4_on.png);}");
        break;
        default:
        break;
    }
    if(dealInterfaceData->m_mSeq.index.num>5)return;
}
