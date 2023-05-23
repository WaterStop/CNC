#include "widget3_12.h"
#include "ui_widget3_12.h"

static int dir_1 = -1;//L方向
static int dir_2 = 1;//Tr方向

widget3_12::widget3_12(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget3_12)
{
    ui->setupUi(this);
    set_background();
    set_edit();
    set_button();
    DealSlot();
    //connect(ui->bt_b_0, SIGNAL(pressed()), this, SLOT(widget3_12_editDataToGCode()));
    ui->bt_close->hide();

}

widget3_12::~widget3_12()
{
    delete ui;
}


void widget3_12::set_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg3_bk15.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget3_12::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg3_bk15.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget3_12::INFO_init()
{
    dir_1 = -1;
    dir_2 = 1;
    ClearEdit();
    Foucus_init();
}

void widget3_12::set_edit()
{
    //set_left_button();
    ui->edit_1->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_2->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_3->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_4->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_5->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_6->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");
    ui->edit_7->setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset;background:transparent;");

    ui->edit_1->setFont(weiruanyahei6);
    ui->edit_2->setFont(weiruanyahei6);
    ui->edit_3->setFont(weiruanyahei6);
    ui->edit_4->setFont(weiruanyahei6);
    ui->edit_5->setFont(weiruanyahei6);
    ui->edit_6->setFont(weiruanyahei6);
    ui->edit_7->setFont(weiruanyahei6);


    if(scr_size==0)
    {
        ui->edit_1->setGeometry(73,73,89,24);
        ui->edit_2->setGeometry(73,105,89,24);
        ui->edit_3->setGeometry(73,139,89,24);
        ui->edit_4->setGeometry(73,174,89,24);
        ui->edit_5->setGeometry(73,209,89,24);
        ui->edit_6->setGeometry(73,235,89,24);
        ui->edit_7->setGeometry(73,265,89,24);
    }
    else if(scr_size==1)
    {
        ui->edit_1->setGeometry(94,62,110,31);
        ui->edit_2->setGeometry(94,105,110,31);
        ui->edit_3->setGeometry(94,149,110,31);
        ui->edit_4->setGeometry(94,193,110,31);
        ui->edit_5->setGeometry(94,238,110,31);
        ui->edit_6->setGeometry(94,280,110,31);
        ui->edit_7->setGeometry(94,320,110,31);
        ui->bt_next_pg->setGeometry(248,387,20,20);
    }
}

void widget3_12::set_button()
{
    ui->bt_l_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt1.png);}");
    ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt2.png);}");
    ui->bt_b_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_3_bt.png);}");    
    ui->bt_close->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_bt_close.png);}");
    ui->bt_next_pg->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_nextpage.png);}");

    if(scr_size==0)
    {

        ui->bt_l_1->setGeometry(47,139,24,24);
        ui->bt_l_2->setGeometry(47,174,24,24);
        ui->bt_b_0->setGeometry(61,105,31,31);
        ui->bt_close->setGeometry(248,17,20,20);
    }
    else if(scr_size==1)
    {
        ui->bt_l_1->setGeometry(61,62,31,31);
        ui->bt_l_2->setGeometry(61,105,31,31);
        ui->bt_b_0->setGeometry(114,387,65,29);
        ui->bt_close->setGeometry(248,17,20,20);
    }

}

void widget3_12::DealSlot()
{
    //connect(ui->edit_1, SIGNAL(clicked()), this, SLOT(show_keyboard_slot()));
    connect(ui->bt_b_0, SIGNAL(clicked()), this, SLOT(input_ok_slot()));
    connect(ui->bt_l_1, SIGNAL(clicked()), this, SLOT(change_axisdir1_slot()));
    connect(ui->bt_l_2, SIGNAL(clicked()), this, SLOT(change_axisdir2_slot()));
    connect(ui->edit_5, SIGNAL(clicked()), this, SLOT(zhuiluowen_fixval_slot()));
    connect(ui->edit_7, SIGNAL(clicked()), this, SLOT(feed_fixval_slot()));
    connect(ui->bt_next_pg, SIGNAL(clicked()), this, SLOT(goto_LuowenSet_slot()));
    connect(ui->edit_1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_2, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_3, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_4, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_5, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_6, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_7, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
}

void widget3_12::show_keyboard_slot()
{
    emit edit_press_signal();
}

void widget3_12::input_ok_slot()
{
    save_flg = 0;
    widget3_12_editDataToGCode();
    emit input_ok_signal();
}

void widget3_12::Foucus_init()
{
    if(luowen_set_flg == 0)
    {
        ClearEdit();
    }
    ui->edit_1->setFocus();
    ui->edit_1->selectAll();
}

void widget3_12::ClearEdit()
{
    ui->edit_1->setText("0");
    ui->edit_2->setText("0");
    ui->edit_3->setText("0");
    ui->edit_4->setText("0");
    ui->edit_5->setText("0");
    ui->edit_6->setText("0");
    ui->edit_7->setText("0");
}

void widget3_12::Focus_switch_slot()
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
        ui->edit_7->setFocus();
        ui->edit_7->selectAll();
    }
    else if(ui->edit_7->hasFocus())
    {
        ui->edit_1->setFocus();
        ui->edit_1->selectAll();
    }
}

void widget3_12::change_axisdir_icon()
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

void widget3_12::change_axisdir1_slot()
{
    dir_1 = dir_1*-1;
    change_axisdir_icon();
}

void widget3_12::change_axisdir2_slot()
{
    dir_2 = dir_2*-1;
    change_axisdir_icon();
}

void widget3_12::zhuiluowen_fixval_slot()
{
    fixedval_mod = fix_zhuiluowen;
    emit zhuiluowen_fixval_signal();
}

void widget3_12::feed_fixval_slot()
{
    fixedval_mod = fix_feed;
    emit feed_fixval_signal();
}

void widget3_12::goto_LuowenSet_slot()
{
    emit goto_LuowenSet_signal();
}

void widget3_12::fixval_set()//固定值设置
{
    QString str;
    str = QString("%1").arg(tmp_fixval);
    switch (fixedval_mod)
    {
        case fix_luowen:

        break;
        case fix_zhuiluowen:
        ui->edit_5->setText(str);
        break;
        case fix_feed:
        ui->edit_7->setText(str);
        break;
        default:
        break;
    }
}

void widget3_12::loadWorkInfo(int index)
{
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(index);
    QString str;

    if(cur_work_mod==luowen2)
    {
        str = QString("%1").arg(tem_val->screwThread2.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.Tp);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.A);
        ui->edit_6->setText(str);
        str = QString("%1").arg(tem_val->screwThread2.F);
        ui->edit_7->setText(str);
    }
    else if(cur_work_mod==luowen4)
    {
        str = QString("%1").arg(tem_val->screwThread4.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.Tp);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.A);
        ui->edit_6->setText(str);
        str = QString("%1").arg(tem_val->screwThread4.F);
        ui->edit_7->setText(str);
    }
}

void widget3_12::edit_input_slot(QString str)
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
    else if(ui->edit_6->hasFocus())
    {
        emit edit_input_signal(6,str);
    }
    else if(ui->edit_7->hasFocus())
    {
        emit edit_input_signal(7,str);
    }
}

bool widget3_12::wedget3_12ToProcessList(MachineProcess* dealInterfaceData, s_screwThreadMode2* screwThread2, Ui::widget3_12* ui)
{
    screwThread2->xDir = dir_2;
    screwThread2->zDir = dir_1;
    screwThread2->L = ui->edit_1->text().toDouble();
    screwThread2->Tr = ui->edit_2->text().toDouble();
    screwThread2->Cn = ui->edit_3->text().toInt();
    screwThread2->Cr = ui->edit_4->text().toDouble();
    screwThread2->Tp = ui->edit_5->text().toDouble();
    screwThread2->A = ui->edit_6->text().toDouble();
    screwThread2->F = ui->edit_7->text().toDouble();
    screwThread2->unit = cur_luowen_unit;
    screwThread2->multi_head = st_lw.duotou;
    screwThread2->startA = st_lw.qishijiaodu;
    screwThread2->tailFlick = st_lw.shuaiwei;
    screwThread2->filingProcessing = st_lw.cuoweijiagong;
    screwThread2->filingDistance = st_lw.cuoweijuli;
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *screwThread2);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if (false == dealInterfaceData->addNode(*screwThread2))
        {
            return false;
        }
    }
    return true;
}

bool widget3_12::wedget3_12ToProcessList(MachineProcess* dealInterfaceData, s_screwThreadMode4* screwThread4, Ui::widget3_12* ui)
{
    screwThread4->xDir = dir_2;
    screwThread4->zDir = dir_1;
    screwThread4->L = ui->edit_1->text().toDouble();
    screwThread4->Tr = ui->edit_2->text().toDouble();
    screwThread4->Cn = ui->edit_3->text().toInt();
    screwThread4->Cr = ui->edit_4->text().toDouble();
    screwThread4->Tp = ui->edit_5->text().toDouble();
    screwThread4->A = ui->edit_6->text().toDouble();
    screwThread4->F = ui->edit_7->text().toDouble();
    screwThread4->unit = cur_luowen_unit;
    screwThread4->multi_head = st_lw.duotou;
    screwThread4->startA = st_lw.qishijiaodu;
    screwThread4->tailFlick = st_lw.shuaiwei;
    screwThread4->filingProcessing = st_lw.cuoweijiagong;
    screwThread4->filingDistance = st_lw.cuoweijuli;
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *screwThread4);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if (false == dealInterfaceData->addNode(*screwThread4))
        {
            return false;
        }
    }
    return true;
}

void widget3_12::widget3_12_editDataToGCode()
{
    s_screwThreadMode2 screwThread2;
    s_screwThreadMode4 screwThread4;
    if(save_flg==0)
    {
        switch (cur_work_mod)
        {
            case luowen2:
            {
                wedget3_12ToProcessList(dealInterfaceData, &screwThread2, ui);
                break;
            }
            case luowen4:
            {
                wedget3_12ToProcessList(dealInterfaceData, &screwThread4, ui);
                break;
            }
        }
    }
    else
    {
        switch (last_work_mod)
        {
            case luowen2:
            {
                wedget3_12ToProcessList(dealInterfaceData, &screwThread2, ui);
                break;
            }
            case luowen4:
            {
                wedget3_12ToProcessList(dealInterfaceData, &screwThread4, ui);
                break;
            }
        }
        save_flg = 0;
    }
    dealInterfaceData->outputGCode();
    dealInterfaceData->textRecordData();
}

