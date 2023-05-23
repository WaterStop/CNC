#include "widget3_14.h"
#include "ui_widget3_14.h"

static int dir_1 = -1;//L方向
static int dir_2 = 1;//Tr方向

widget3_14::widget3_14(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget3_14)
{
    ui->setupUi(this);
    set_background();
    set_edit();
    set_button();
    DealSlot();
    //connect(ui->bt_b_0, SIGNAL(pressed()), this, SLOT(widget3_14_editDataToGCode()));
    ui->bt_close->hide();

}

widget3_14::~widget3_14()
{
    delete ui;
}


void widget3_14::set_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg3_bk4.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget3_14::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg3_bk4.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget3_14::INFO_init()
{
    dir_1 = -1;
    dir_2 = 1;
    ClearEdit();
    Foucus_init();
}

void widget3_14::set_edit()
{
    set_left_button();
    ui->edit_1->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_2->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_3->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_4->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_5->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_6->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_1->setFont(weiruanyahei6);
    ui->edit_2->setFont(weiruanyahei6);
    ui->edit_3->setFont(weiruanyahei6);
    ui->edit_4->setFont(weiruanyahei6);
    ui->edit_5->setFont(weiruanyahei6);
    ui->edit_6->setFont(weiruanyahei6);
    if(scr_size==0)
    {
        ui->edit_1->setGeometry(73,73,89,24);
        ui->edit_2->setGeometry(73,105,89,24);
        ui->edit_3->setGeometry(73,139,89,24);
        ui->edit_4->setGeometry(73,174,89,24);
        ui->edit_5->setGeometry(73,209,89,24);
    }
    else if(scr_size==1)
    {
        ui->edit_1->setGeometry(94,62,110,31);
        ui->edit_2->setGeometry(94,105,110,31);
        ui->edit_3->setGeometry(94,149,110,31);
        ui->edit_4->setGeometry(94,193,110,31);
        ui->edit_5->setGeometry(94,238,110,31);
        ui->edit_6->setGeometry(94,280,110,31);

    }
}

void widget3_14::set_button()
{
    set_left_button();

    if(scr_size==0)
    {

        ui->bt_l_1->setGeometry(47,139,24,24);
        ui->bt_l_2->setGeometry(47,174,24,24);
        ui->bt_b_0->setGeometry(61,105,31,31);
    }
    else if(scr_size==1)
    {
        ui->bt_l_1->setGeometry(61,62,31,31);
        ui->bt_l_2->setGeometry(61,105,31,31);
        ui->bt_b_0->setGeometry(114,387,65,29);
        ui->bt_close->setGeometry(248,17,20,20);
    }
}

void widget3_14::set_left_button()
{
    ui->bt_l_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt1.png);}");
    ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt2.png);}");
    ui->bt_b_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_3_bt.png);}");
    ui->bt_close->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_bt_close.png);}");
}

void widget3_14::DealSlot()
{
    //connect(ui->edit_1, SIGNAL(clicked()), this, SLOT(show_keyboard_slot()));
    connect(ui->bt_b_0, SIGNAL(clicked()), this, SLOT(input_ok_slot()));
    connect(ui->bt_l_1, SIGNAL(clicked()), this, SLOT(change_axisdir1_slot()));
    connect(ui->bt_l_2, SIGNAL(clicked()), this, SLOT(change_axisdir2_slot()));
    connect(ui->edit_5, SIGNAL(clicked()), this, SLOT(feed_fixval_slot()));
    connect(ui->edit_1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_2, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_3, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_4, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_5, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
}

void widget3_14::show_keyboard_slot()
{
    emit edit_press_signal();
}

void widget3_14::input_ok_slot()
{
    save_flg = 0;
    widget3_14_editDataToGCode();
    emit input_ok_signal();
}

void widget3_14::Foucus_init()
{
    ClearEdit();
    ui->edit_1->setFocus();
    ui->edit_1->selectAll();
}

void widget3_14::ClearEdit()
{
    ui->edit_1->setText("0");
    ui->edit_2->setText("0");
    ui->edit_3->setText("0");
    ui->edit_4->setText("0");
    ui->edit_5->setText("0");
    ui->edit_6->setText("0");
}


void widget3_14::Focus_switch_slot()
{
    if(ui->edit_1->hasFocus())
    {
        ui->edit_2->setFocus();
        ui->edit_2->selectAll();
    }
    else if(ui->edit_2->hasFocus())
    {
        ui->edit_3->setFocus();
        ui->edit_3->selectAll();
    }
    else if(ui->edit_3->hasFocus())
    {
        ui->edit_4->setFocus();
        ui->edit_4->selectAll();
    }
    else if(ui->edit_4->hasFocus())
    {
        ui->edit_5->setFocus();
        ui->edit_5->selectAll();
    }
    else if(ui->edit_5->hasFocus())
    {
        ui->edit_6->setFocus();
        ui->edit_6->selectAll();
    }
    else if(ui->edit_6->hasFocus())
    {
        ui->edit_1->setFocus();
        ui->edit_1->selectAll();
    }
}

void widget3_14::change_axisdir_icon()
{
    if(dir_1==-1)
    {
        ui->bt_l_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt1.png);}");
    }
    else if(dir_1==1)
    {
        ui->bt_l_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt3.png);}");
    }
    if(dir_2==1)
    {
        ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt2.png);}");
    }
    else if(dir_2==-1)
    {
        ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt4.png);}");
    }
}

void widget3_14::change_axisdir1_slot()
{
    dir_1 = dir_1*-1;
    change_axisdir_icon();
}

void widget3_14::change_axisdir2_slot()
{
    dir_2 = dir_2*-1;
    change_axisdir_icon();
}

void widget3_14::feed_fixval_slot()
{
    fixedval_mod = fix_feed;
    emit feed_fixval_signal();
}

void widget3_14::fixval_set()//固定值设置
{
    QString str;
    str = QString("%1").arg(tmp_fixval);
    switch (fixedval_mod)
    {
        case fix_luowen:

        break;
        case fix_zhuiluowen:

        break;
        case fix_feed:
        ui->edit_5->setText(str);
        break;
        default:
        break;
    }
}

void widget3_14::loadWorkInfo(int index)
{
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(index);
    QString str;

    if(cur_work_mod==daojiao2)
    {
        str = QString("%1").arg(tem_val->chamfer2.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->chamfer2.F);
        ui->edit_5->setText(str);
    }
    else if(cur_work_mod==daojiao4)
    {
        str = QString("%1").arg(tem_val->chamfer4.A);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->chamfer4.F);
        ui->edit_5->setText(str);
    }
}

void widget3_14::edit_input_slot(QString str)
{
    if(ui->edit_1->hasFocus())
    {
        emit edit_input_signal(1,str);
    }
    else if(ui->edit_2->hasFocus())
    {
        emit edit_input_signal(2,str);
    }
    else if(ui->edit_3->hasFocus())
    {
        emit edit_input_signal(3,str);
    }
    else if(ui->edit_4->hasFocus())
    {
        emit edit_input_signal(4,str);
    }
    else if(ui->edit_5->hasFocus())
    {
        emit edit_input_signal(5,str);
    }
}

bool widget3_14::wedget3_14ToProcessList(MachineProcess* dealInterfaceData, s_chamferMode2* chamfer2, Ui::widget3_14* ui)
{
    chamfer2->xDir = dir_2;
    chamfer2->zDir = dir_1;
    chamfer2->L = ui->edit_1->text().toDouble();
    chamfer2->Tr = ui->edit_2->text().toDouble();
    chamfer2->Cn = ui->edit_3->text().toInt();
    chamfer2->Cr = ui->edit_4->text().toDouble();
    chamfer2->A = ui->edit_5->text().toDouble();
    chamfer2->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *chamfer2);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if (false == dealInterfaceData->addNode(*chamfer2))
        {
            return false;
        }
    }
    return true;
}

bool widget3_14::wedget3_14ToProcessList(MachineProcess* dealInterfaceData, s_chamferMode4* chamfer4, Ui::widget3_14* ui)
{
    chamfer4->xDir = dir_2;
    chamfer4->zDir = dir_1;
    chamfer4->L = ui->edit_1->text().toDouble();
    chamfer4->Tr = ui->edit_2->text().toDouble();
    chamfer4->Cn = ui->edit_3->text().toInt();
    chamfer4->Cr = ui->edit_4->text().toDouble();
    chamfer4->A = ui->edit_5->text().toDouble();
    chamfer4->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *chamfer4);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if (false == dealInterfaceData->addNode(*chamfer4))
        {
            return false;
        }
    }
    return true;
}

void widget3_14::widget3_14_editDataToGCode()
{
    s_chamferMode2 chamfer2;
    s_chamferMode4 chamfer4;
    if(save_flg==0)
    {
        switch (cur_work_mod)
        {
            case daojiao2:
            {
                wedget3_14ToProcessList(dealInterfaceData, &chamfer2, ui);
                break;
            }
            case daojiao4:
            {
                wedget3_14ToProcessList(dealInterfaceData, &chamfer4, ui);
                break;
            }
        }
    }
    else
    {
        switch (last_work_mod)
        {
            case daojiao2:
            {
                wedget3_14ToProcessList(dealInterfaceData, &chamfer2, ui);
                break;
            }
            case daojiao4:
            {
                wedget3_14ToProcessList(dealInterfaceData, &chamfer4, ui);
                break;
            }
        }
        save_flg = 0;
    }
    dealInterfaceData->outputGCode();
    dealInterfaceData->textRecordData();
}
