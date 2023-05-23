#include "widget3_6.h"
#include "ui_widget3_6.h"

static int unit_flag = 0;//单位选择
static int dir_1 = -1;//L方向
static int dir_2 = 1;//Tr方向

widget3_6::widget3_6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget3_6)
{
    ui->setupUi(this);
    set_background();
    set_edit();
    set_button();
    set_comboBox();
    DealSlot();
    //connect(ui->bt_b_0, SIGNAL(pressed()), this, SLOT(widget3_6_editDataToGCode()));
    ui->bt_close->hide();
}

widget3_6::~widget3_6()
{
    delete ui;
}

void widget3_6::set_background()
{

    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg3_bk9.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget3_6::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg3_bk9.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget3_6::INFO_init()
{
    dir_1 = -1;
    dir_2 = 1;
    ClearEdit();
    Foucus_init();
}

void widget3_6::set_edit()
{
    //set_left_button();
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
        ui->edit_1->setGeometry(94,48,110,25);
        ui->edit_2->setGeometry(94,92,110,25);
        ui->edit_3->setGeometry(94,136,110,25);
        ui->edit_4->setGeometry(94,180,110,25);
        ui->edit_5->setGeometry(140,224,65,25);
        ui->edit_6->setGeometry(94,266,110,25);

    }
}

void widget3_6::set_button()
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
    }
    else if(scr_size==1)
    {
        ui->bt_l_1->setGeometry(62,47,28,28);
        ui->bt_l_2->setGeometry(62,90,28,28);
        ui->bt_b_0->setGeometry(114,387,65,29);
        ui->bt_close->setGeometry(248,17,20,20);
        ui->bt_next_pg->setGeometry(248,387,20,20);
    }

}

void widget3_6::set_comboBox()
{
    ui->comboBox->setGeometry(62,224,70,25);
    ui->label_unit->setGeometry(224,224,30,25);
    ui->label_unit->setText("mm");
    ui->comboBox->addItems({"mm","inch","MOD","DP"});
    ui->label_unit->setFont(weiruanyahei4);
    ui->comboBox->setFont(weiruanyahei4);
}

void widget3_6::show_unit_slot(int index)
{
    switch (index)
    {
        case 0:
        ui->label_unit->setText("mm");
        ui->edit_5->setText("0");
        ui->edit_5->setFocus();
        ui->edit_5->selectAll();
        cur_luowen_unit =mode_mm;
        break;
        case 1:
        ui->label_unit->setText("inch");
        ui->edit_5->setText("0");
        ui->edit_5->setFocus();
        ui->edit_5->selectAll();
        cur_luowen_unit =mode_inch;
        break;
        case 2:
        ui->label_unit->setText("");
        ui->edit_5->setText("0");
        ui->edit_5->setFocus();
        ui->edit_5->selectAll();
        cur_luowen_unit =mode_MOD;
        break;
        case 3:
        ui->label_unit->setText("");
        ui->edit_5->setText("0");
        ui->edit_5->setFocus();
        ui->edit_5->selectAll();
        cur_luowen_unit =mode_DP;
        break;
        default:
        break;
    }
    fixedval_mod = fix_luowen;
    emit mode_changed_signal();

}

void widget3_6::DealSlot()
{
    connect(ui->bt_b_0, SIGNAL(clicked()), this, SLOT(input_ok_slot()));
    connect(ui->bt_next_pg, SIGNAL(clicked()), this, SLOT(goto_LuowenSet_slot()));
    connect(ui->bt_l_1, SIGNAL(clicked()), this, SLOT(change_axisdir1_slot()));
    connect(ui->bt_l_2, SIGNAL(clicked()), this, SLOT(change_axisdir2_slot()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(show_unit_slot(int)));
    connect(ui->edit_5, SIGNAL(clicked()), this, SLOT(luowen_fixval_slot()));
    connect(ui->edit_6, SIGNAL(clicked()), this, SLOT(feed_fixval_slot()));
    connect(ui->edit_1, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_2, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_3, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_4, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_5, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
    connect(ui->edit_6, SIGNAL(textChanged(QString)), this, SLOT(edit_input_slot(QString)));
}


void widget3_6::show_keyboard_slot()
{
    emit edit_press_signal();
}

void widget3_6::input_ok_slot()
{
    save_flg = 0;
    widget3_6_editDataToGCode();
    emit input_ok_signal();
}

void widget3_6::goto_LuowenSet_slot()
{
    emit goto_LuowenSet_signal();
}

void widget3_6::Foucus_init()
{
    if(luowen_set_flg == 0)
    {
        ClearEdit();
    }
    ui->edit_1->setFocus();
    ui->edit_1->selectAll();
}

void widget3_6::ClearEdit()
{
    ui->edit_1->setText("0");
    ui->edit_2->setText("0");
    ui->edit_3->setText("0");
    ui->edit_4->setText("0");
    ui->edit_5->setText("0");
    ui->edit_6->setText("0");
}

void widget3_6::Focus_switch_slot()
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

void widget3_6::change_axisdir_icon()
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

void widget3_6::change_axisdir1_slot()
{
    dir_1 = dir_1*-1;
    change_axisdir_icon();
}

void widget3_6::change_axisdir2_slot()
{
    dir_2 = dir_2*-1;
    change_axisdir_icon();
}

void widget3_6::feed_fixval_slot()
{
    fixedval_mod = fix_feed;
    emit feed_fixval_signal();
}

void widget3_6::luowen_fixval_slot()
{
    fixedval_mod = fix_luowen;
    emit luowen_fixval_signal();
}

void widget3_6::fixval_set()//固定值设置
{
    QString str;
    str = QString("%1").arg(tmp_fixval);
    switch (fixedval_mod)
    {
        case fix_luowen:
        ui->edit_5->setText(str);
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

void widget3_6::loadWorkInfo(int index)
{
    machineNode *tem_val;
    tem_val = dealInterfaceData->findNode(index);
    QString str;

    if(cur_work_mod==luowen1)
    {
        str = QString("%1").arg(tem_val->screwThread1.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.Tp);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->screwThread1.F);
        ui->edit_6->setText(str);
    }
    else if(cur_work_mod==luowen3)
    {
        str = QString("%1").arg(tem_val->screwThread3.L);
        ui->edit_1->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Tr);
        ui->edit_2->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Cn);
        ui->edit_3->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Cr);
        ui->edit_4->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.Tp);
        ui->edit_5->setText(str);
        str = QString("%1").arg(tem_val->screwThread3.F);
        ui->edit_6->setText(str);
    }
}

void widget3_6::edit_input_slot(QString str)
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
}

bool widget3_6::wedget3_6ToProcessList(MachineProcess* dealInterfaceData, s_screwThreadMode1* screwThread1, Ui::widget3_6* ui)
{
    widget15 = new widget3_15();
    screwThread1->xDir = dir_2;
    screwThread1->zDir = dir_1;
    screwThread1->L = ui->edit_1->text().toDouble();
    screwThread1->Tr = ui->edit_2->text().toDouble();
    screwThread1->Cn = ui->edit_3->text().toInt();
    screwThread1->Cr = ui->edit_4->text().toDouble();
    screwThread1->Tp = ui->edit_5->text().toDouble();
    screwThread1->F = ui->edit_6->text().toDouble();
    screwThread1->unit = cur_luowen_unit;
    screwThread1->multi_head = st_lw.duotou;
    screwThread1->startA = st_lw.qishijiaodu;
    screwThread1->tailFlick = st_lw.shuaiwei;
    screwThread1->filingProcessing = st_lw.cuoweijiagong;
    screwThread1->filingDistance = st_lw.cuoweijuli;
    qDebug()<<"screwThread1->multi_head"<<screwThread1->multi_head;
    //widget15->getInfo(screwThread1);

    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *screwThread1);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if (false == dealInterfaceData->addNode(*screwThread1))
        {
            return false;
        }
    }
    return true;
}

bool widget3_6::wedget3_6ToProcessList(MachineProcess* dealInterfaceData, s_screwThreadMode3* screwThread3, Ui::widget3_6* ui)
{
    screwThread3->L = ui->edit_1->text().toDouble();
    screwThread3->Tr = ui->edit_2->text().toDouble();
    screwThread3->Cn = ui->edit_3->text().toInt();
    screwThread3->Cr = ui->edit_4->text().toDouble();
    screwThread3->Tp = ui->edit_5->text().toDouble();
    screwThread3->F = ui->edit_6->text().toDouble();
    screwThread3->unit = cur_luowen_unit;
    screwThread3->multi_head = st_lw.duotou;
    screwThread3->startA = st_lw.qishijiaodu;
    screwThread3->tailFlick = st_lw.shuaiwei;
    screwThread3->filingProcessing = st_lw.cuoweijiagong;
    screwThread3->filingDistance = st_lw.cuoweijuli;
    if(true == dealInterfaceData->firstInsystem)
    {
        dealInterfaceData->changeNode(1, *screwThread3);
        dealInterfaceData->firstInsystem = false;
    }
    else
    {
        if (false == dealInterfaceData->addNode(*screwThread3))
        {
            return false;
        }
    }
    return true;
}


void widget3_6::widget3_6_editDataToGCode()
{
    s_screwThreadMode1 screwThread1;
    s_screwThreadMode3 screwThread3;
    if(save_flg==0)
    {
        switch (cur_work_mod)
        {
            case luowen1:
            {
                wedget3_6ToProcessList(dealInterfaceData, &screwThread1, ui);
                break;
            }
            case luowen3:
            {
                wedget3_6ToProcessList(dealInterfaceData, &screwThread3, ui);
                break;
            }
        }
    }
    else
    {
        switch (last_work_mod)
        {
            case luowen1:
            {
                wedget3_6ToProcessList(dealInterfaceData, &screwThread1, ui);
                break;
            }
            case luowen3:
            {
                wedget3_6ToProcessList(dealInterfaceData, &screwThread3, ui);
                break;
            }
        }
        save_flg = 0;
    }
    dealInterfaceData->outputGCode();
    dealInterfaceData->textRecordData();
}
