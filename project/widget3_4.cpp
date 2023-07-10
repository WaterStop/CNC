#include "widget3_4.h"
#include "ui_widget3_4.h"

static int dir_1 = -1;//L方向
static int dir_2 = 1;//Tr方向

widget3_4::widget3_4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget3_4)
{
    ui->setupUi(this);
    set_background();
    set_edit();
    set_button();
    DealSlot();
	
    //bool a=connect(ui->bt_b_0, SIGNAL(pressed()), this, SLOT(widget3_4_editDataToGCode()));
    ui->bt_close->hide();
}

widget3_4::~widget3_4()
{
    delete ui;
}

void widget3_4::set_background()
{
//    setAutoFillBackground(true);//做子窗口要设置，否则不显示
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new_pic/wg3_bk3.png")));
//    setPalette(pal);

    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg3_bk4.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget3_4::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg3_bk4.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget3_4::INFO_init()
{
    dir_1 = -1;
    dir_2 = 1;
    ClearEdit();
    Foucus_init();
    change_axisdir_icon();
}

void widget3_4::set_edit()
{

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
        ui->edit_6->setGeometry(73,235,89,24);
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

void widget3_4::set_button()
{
    ui->bt_l_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt1.png);}");
    ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt2.png);}");
    ui->bt_b_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_3_bt.png);}");
    ui->bt_close->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_bt_close.png);}");

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


void widget3_4::DealSlot()
{
    //connect(ui->edit_1, SIGNAL(clicked()), this, SLOT(show_keyboard_slot()));
    connect(ui->bt_b_0, SIGNAL(clicked()), this, SLOT(input_ok_slot()));
    connect(ui->bt_l_1, SIGNAL(clicked()), this, SLOT(change_axisdir1_slot()));
    connect(ui->bt_l_2, SIGNAL(clicked()), this, SLOT(change_axisdir2_slot()));
    connect(ui->edit_6, SIGNAL(clicked()), this, SLOT(feed_fixval_slot()));
    connect(ui->edit_1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_2, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_3, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_4, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_5, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_6, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
}

void widget3_4::show_keyboard_slot()
{
    emit edit_press_signal();
}

void widget3_4::input_ok_slot()
{
    save_flg = 0;
    widget3_4_editDataToGCode();
    emit input_ok_signal();
}

void widget3_4::Foucus_init()
{
    ClearEdit();
    ui->edit_1->setFocus();
    ui->edit_1->selectAll();
}

void widget3_4::ClearEdit()
{
    ui->edit_1->setText("0");
    ui->edit_2->setText("0");
    ui->edit_3->setText("0");
    ui->edit_4->setText("0");
    ui->edit_5->setText("0");
    ui->edit_6->setText("0");
}


void widget3_4::Focus_switch_slot()
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

void widget3_4::feed_fixval_slot()
{
    fixedval_mod = fix_feed;
    emit feed_fixval_signal();
}

void widget3_4::fixval_set()//固定值设置
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
        ui->edit_6->setText(str);
        break;
        default:
        break;
    }
}

void widget3_4::loadWorkInfo(int index)
{
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(index);
    QString str;

    if(cur_work_mod==waiyuan2)
    {
        str = QString("%1").arg(tem_val->outerCircle2.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.A);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->outerCircle2.F);
        ui->edit_6->setText(str);
        dir_1 = tem_val->outerCircle2.zDir;
        dir_2 = tem_val->outerCircle2.xDir;
        change_axisdir_icon();
    }
    else if(cur_work_mod==likong2)
    {
        str = QString("%1").arg(tem_val->innerHole2.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.A);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->innerHole2.F);
        ui->edit_6->setText(str);
        dir_1 = tem_val->innerHole2.zDir;
        dir_2 = tem_val->innerHole2.xDir;
        change_axisdir_icon();
    }
    else if(cur_work_mod==zhuimian1)
    {
        str = QString("%1").arg(tem_val->coneFace1.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.A);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->coneFace1.F);
        ui->edit_6->setText(str);
        dir_1 = tem_val->coneFace1.zDir;
        dir_2 = tem_val->coneFace1.xDir;
        change_axisdir_icon();
    }
    else if(cur_work_mod==zhuimian2)
    {
        str = QString("%1").arg(tem_val->coneFace2.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.A);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->coneFace2.F);
        ui->edit_6->setText(str);
        dir_1 = tem_val->coneFace2.zDir;
        dir_2 = tem_val->coneFace2.xDir;
        change_axisdir_icon();
    }
    else if(cur_work_mod==zhuimian3)
    {
        str = QString("%1").arg(tem_val->coneFace3.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.A);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->coneFace3.F);
        ui->edit_6->setText(str);
        dir_1 = tem_val->coneFace3.zDir;
        dir_2 = tem_val->coneFace3.xDir;
        change_axisdir_icon();
    }
    else if(cur_work_mod==zhuimian4)
    {
        str = QString("%1").arg(tem_val->coneFace4.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.A);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->coneFace4.F);
        ui->edit_6->setText(str);
        dir_1 = tem_val->coneFace4.zDir;
        dir_2 = tem_val->coneFace4.xDir;
        change_axisdir_icon();
    }
}

void widget3_4::edit_input_slot(QString str)
{
    if(ui->edit_1->hasFocus())
    {
        emit edit_input_signal(1,str);
    }
    else if(ui->edit_2->hasFocus())
    {
        updateTrCnCr();
        emit edit_input_signal(2,str);
    }
    else if(ui->edit_3->hasFocus())
    {
        updateTrCnCr();
        emit edit_input_signal(3,str);
    }
    else if(ui->edit_4->hasFocus())
    {
        updateTrCnCr();
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
}

void widget3_4::updateTrCnCr()
{
    double feed;
    double depth;
    int times;
    double Tr;
    double Cr;
    int Cn;
    static double beforeTr;
    static double beforeCr;
    static int beforeCn;
    QString str;
    Tr = ui->edit_2->text().toDouble();
    Cn = ui->edit_3->text().toInt();
    Cr = ui->edit_4->text().toDouble();

    feed = Cr / (double)Cn;
    times = Cr / Tr;
    depth = Tr * (double)Cn;

    if(beforeTr != Tr)
    {
        str = QString("%1").arg(depth);
        ui->edit_4->setText(str);
        beforeTr = Tr;
        beforeCn = Cn;
        beforeCr = depth;
    }
    else if(beforeCn != Cn)
    {
        str = QString("%1").arg(depth);
        ui->edit_4->setText(str);
        beforeTr = Tr;
        beforeCn = Cn;
        beforeCr = depth;
    }
    else if(beforeCr != Cr && Cn != 0)
    {
        str = QString("%1").arg(feed);
        ui->edit_2->setText(str);
        beforeTr = feed;
        beforeCn = Cn;
        beforeCr = Cr;
    }
}

bool widget3_4::wedget3_4ToProcessList(MachineProcess* dealInterfaceData, s_outerCircleMode2* outerCircle2, Ui::widget3_4* ui)
{
    outerCircle2->xDir = dir_2;
    outerCircle2->zDir = dir_1;
    outerCircle2->L = ui->edit_1->text().toDouble();
    outerCircle2->Tr = ui->edit_2->text().toDouble();
    outerCircle2->Cn = ui->edit_3->text().toInt();
    outerCircle2->Cr = ui->edit_4->text().toDouble();
    outerCircle2->A = ui->edit_5->text().toDouble();
    outerCircle2->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *outerCircle2);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if(modify_flg==1)
        {
            dealInterfaceData->changeNode(cur_Node, *outerCircle2);
        }
        else  if (false == dealInterfaceData->addNode(*outerCircle2))
        {
            return false;
        }
    }
    return true;
}

bool widget3_4::wedget3_4ToProcessList(MachineProcess* dealInterfaceData, s_innerHoleMode2* innerHole2, Ui::widget3_4* ui)
{
    innerHole2->xDir = dir_2;
    innerHole2->zDir = dir_1;
    innerHole2->L = ui->edit_1->text().toDouble();
    innerHole2->Tr = ui->edit_2->text().toDouble();
    innerHole2->Cn = ui->edit_3->text().toInt();
    innerHole2->Cr = ui->edit_4->text().toDouble();
    innerHole2->A = ui->edit_5->text().toDouble();
    innerHole2->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *innerHole2);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if(modify_flg==1)
        {
            dealInterfaceData->changeNode(cur_Node, *innerHole2);
        }
        else  if (false == dealInterfaceData->addNode(*innerHole2))
        {
            return false;
        }
    }
    return true;
}

bool widget3_4::wedget3_4ToProcessList(MachineProcess* dealInterfaceData, s_coneFaceMode1* coneFace1, Ui::widget3_4* ui)
{
    coneFace1->xDir = dir_2;
    coneFace1->zDir = dir_1;
    coneFace1->L = ui->edit_1->text().toDouble();
    coneFace1->Tr = ui->edit_2->text().toDouble();
    coneFace1->Cn = ui->edit_3->text().toInt();
    coneFace1->Cr = ui->edit_4->text().toDouble();
    coneFace1->A = ui->edit_5->text().toDouble();
    coneFace1->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *coneFace1);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if(modify_flg==1)
        {
            dealInterfaceData->changeNode(cur_Node, *coneFace1);
        }
        else  if (false == dealInterfaceData->addNode(*coneFace1))
        {
            return false;
        }
    }
    return true;
}

bool widget3_4::wedget3_4ToProcessList(MachineProcess* dealInterfaceData, s_coneFaceMode2* coneFace2, Ui::widget3_4* ui)
{
    coneFace2->xDir = dir_2;
    coneFace2->zDir = dir_1;
    coneFace2->L = ui->edit_1->text().toDouble();
    coneFace2->Tr = ui->edit_2->text().toDouble();
    coneFace2->Cn = ui->edit_3->text().toInt();
    coneFace2->Cr = ui->edit_4->text().toDouble();
    coneFace2->A = ui->edit_5->text().toDouble();
    coneFace2->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *coneFace2);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if(modify_flg==1)
        {
            dealInterfaceData->changeNode(cur_Node, *coneFace2);
        }
        else  if (false == dealInterfaceData->addNode(*coneFace2))
        {
            return false;
        }
    }
    return true;
}

bool widget3_4::wedget3_4ToProcessList(MachineProcess* dealInterfaceData, s_coneFaceMode3* coneFace3, Ui::widget3_4* ui)
{
    coneFace3->xDir = dir_2;
    coneFace3->zDir = dir_1;
    coneFace3->L = ui->edit_1->text().toDouble();
    coneFace3->Tr = ui->edit_2->text().toDouble();
    coneFace3->Cn = ui->edit_3->text().toInt();
    coneFace3->Cr = ui->edit_4->text().toDouble();
    coneFace3->A = ui->edit_5->text().toDouble();
    coneFace3->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *coneFace3);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if(modify_flg==1)
        {
            dealInterfaceData->changeNode(cur_Node, *coneFace3);
        }
        else  if (false == dealInterfaceData->addNode(*coneFace3))
        {
            return false;
        }
    }
    return true;
}

bool widget3_4::wedget3_4ToProcessList(MachineProcess* dealInterfaceData, s_coneFaceMode4* coneFace4, Ui::widget3_4* ui)
{
    coneFace4->xDir = dir_2;
    coneFace4->zDir = dir_1;
    coneFace4->L = ui->edit_1->text().toDouble();
    coneFace4->Tr = ui->edit_2->text().toDouble();
    coneFace4->Cn = ui->edit_3->text().toInt();
    coneFace4->Cr = ui->edit_4->text().toDouble();
    coneFace4->A = ui->edit_5->text().toDouble();
    coneFace4->F = ui->edit_6->text().toDouble();
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *coneFace4);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if(modify_flg==1)
        {
            dealInterfaceData->changeNode(cur_Node, *coneFace4);
        }
        else  if (false == dealInterfaceData->addNode(*coneFace4))
        {
            return false;
        }
    }
    return true;
}

void widget3_4::widget3_4_editDataToGCode()
{
    s_outerCircleMode2 outerCircle2;
    s_innerHoleMode2 innerHole2;
    s_coneFaceMode1 coneFace1;
    s_coneFaceMode2 coneFace2;
    s_coneFaceMode3 coneFace3;
    s_coneFaceMode4 coneFace4;

    if(save_flg==0)
    {
        switch (cur_work_mod)
        {
            case waiyuan2:
            {
                wedget3_4ToProcessList(dealInterfaceData, &outerCircle2, ui);
                break;
            }
            case likong2:
            {
                wedget3_4ToProcessList(dealInterfaceData, &innerHole2, ui);
                break;
            }
            case zhuimian1:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace1, ui);
                break;
            }
            case zhuimian2:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace2, ui);
                break;
            }
            case zhuimian3:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace3, ui);
                break;
            }
            case zhuimian4:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace4, ui);
                break;
            }

        }
    }
    else
    {
        switch (last_work_mod)
        {
            case waiyuan2:
            {
                wedget3_4ToProcessList(dealInterfaceData, &outerCircle2, ui);
                break;
            }
            case likong2:
            {
                wedget3_4ToProcessList(dealInterfaceData, &innerHole2, ui);
                break;
            }
            case zhuimian1:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace1, ui);
                break;
            }
            case zhuimian2:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace2, ui);
                break;
            }
            case zhuimian3:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace3, ui);
                break;
            }
            case zhuimian4:
            {
                wedget3_4ToProcessList(dealInterfaceData, &coneFace4, ui);
                break;
            }
        }
        save_flg = 0;
    }
    dealInterfaceData->outputGCode_auto();
    dealInterfaceData->outputGCode();
    dealInterfaceData->textRecordData();
    dealInterfaceData->recordVariable();
}


void widget3_4::change_axisdir_icon()
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
        ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt4.png);}");
    }
    else if(dir_2==-1)
    {
        ui->bt_l_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_2_l_bt2.png);}");
    }
}

void widget3_4::change_axisdir1_slot()
{
    dir_1 = dir_1*-1;
    change_axisdir_icon();
}

void widget3_4::change_axisdir2_slot()
{
    dir_2 = dir_2*-1;
    change_axisdir_icon();
}
