#include "fixedval_widget.h"
#include "ui_fixedval_widget.h"


static int cur_page = 0;
static int bt_press = 0;

FixedVal_widget::FixedVal_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FixedVal_widget)
{
    ui->setupUi(this);
    set_background();
    set_button();
    Deal_bt_val(fixedval_mod);
    DealSlot();
}

FixedVal_widget::~FixedVal_widget()
{
    delete ui;
}

void FixedVal_widget::set_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/fixedval_bk.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}

void FixedVal_widget::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/fixedval_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void FixedVal_widget::set_button()
{
    ui->bt_lastpage->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/fixedval_lastpg.png);}");
    ui->bt_nextpage->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/fixedval_nextpg.png);}");

    ui->bt_lastpage->setGeometry(0,0,40,70);
    ui->bt_val_0->setGeometry(41,0,70,70);
    ui->bt_val_1->setGeometry(112,0,70,70);
    ui->bt_val_2->setGeometry(183,0,70,70);
    ui->bt_nextpage->setGeometry(253,0,40,70);

    ui->bt_val_0->setFlat(true);//按钮透明
    ui->bt_val_1->setFlat(true);
    ui->bt_val_2->setFlat(true);

    ui->bt_val_0->setFont(weiruanyahei6);
    ui->bt_val_1->setFont(weiruanyahei6);
    ui->bt_val_2->setFont(weiruanyahei6);
}

void FixedVal_widget::DealSlot()
{
    connect(ui->bt_lastpage,SIGNAL(clicked()),this,SLOT(bt_lastpg_slot()));
    connect(ui->bt_val_0,SIGNAL(clicked()),this,SLOT(bt0_val_slot()));
    connect(ui->bt_val_1,SIGNAL(clicked()),this,SLOT(bt1_val_slot()));
    connect(ui->bt_val_2,SIGNAL(clicked()),this,SLOT(bt2_val_slot()));
    connect(ui->bt_nextpage,SIGNAL(clicked()),this,SLOT(bt_nextpg_slot()));
}

void FixedVal_widget::bt0_val_slot()
{
    bt_press = 0;
    set_fixval();
    emit bt0_signal();
}
void FixedVal_widget::bt1_val_slot()
{
    bt_press = 1;
    set_fixval();
    emit bt1_signal();
}
void FixedVal_widget::bt2_val_slot()
{
    bt_press = 2;
    set_fixval();
    emit bt2_signal();
}
void FixedVal_widget::bt_lastpg_slot()
{
    cur_page--;
    Deal_bt_val(fixedval_mod);
}
void FixedVal_widget::bt_nextpg_slot()
{
    cur_page++;
    Deal_bt_val(fixedval_mod);
}

void FixedVal_widget::Deal_bt_val_slot()
{
    cur_page = 0;
    Deal_bt_val(fixedval_mod);
}

void FixedVal_widget::Deal_bt_val(int index)
{
    switch (index)
    {
        case fix_luowen:
        show_luowen_val();
        break;
        case fix_zhuiluowen:
        show_zhuiluowen_val();
        break;
        case fix_feed:
        show_feed_val();
        break;
        default:
        break;
    }
}

void FixedVal_widget::show_luowen_val()
{
    if(cur_luowen_unit==mode_mm)
    {
        if(cur_page>mm_max_pg-1)
        {
            cur_page = 0;
        }
        if(cur_page<0)
        {
            cur_page = mm_max_pg-1;
        }
        switch (cur_page)
        {
            case 0:
            ui->bt_val_0->setText("0.50");
            ui->bt_val_1->setText("0.70");
            ui->bt_val_2->setText("0.75");
            break;
            case 1:
            ui->bt_val_0->setText("0.80");
            ui->bt_val_1->setText("1.00");
            ui->bt_val_2->setText("1.25");
            break;
            case 2:
            ui->bt_val_0->setText("1.50");
            ui->bt_val_1->setText("1.75");
            ui->bt_val_2->setText("2.00");
            break;
            case 3:
            ui->bt_val_0->setText("2.50");
            ui->bt_val_1->setText("3.00");
            ui->bt_val_2->setText("3.50");
            break;
            case 4:
            ui->bt_val_0->setText("4.00");
            ui->bt_val_1->setText("4.50");
            ui->bt_val_2->setText("5.00");
            break;
            case 5:
            ui->bt_val_0->setText("5.50");
            ui->bt_val_1->setText("6.00");
            ui->bt_val_2->setText("7.00");
            break;
            case 6:
            ui->bt_val_0->setText("8.00");
            ui->bt_val_1->setText("9.00");
            ui->bt_val_2->setText("10.0");
            break;
            case 7:
            ui->bt_val_0->setText("11.0");
            ui->bt_val_1->setText("12.0");
            ui->bt_val_2->setText("14.0");
            break;
            case 8:
            ui->bt_val_0->setText("16.0");
            ui->bt_val_1->setText("18.0");
            ui->bt_val_2->setText("20.0");
            break;
            case 9:
            ui->bt_val_0->setText("22.0");
            ui->bt_val_1->setText("24.0");
            ui->bt_val_2->setText("28.0");
            break;
            case 10:
            ui->bt_val_0->setText("40.0");
            ui->bt_val_1->setText("");
            ui->bt_val_2->setText("");
            break;
            default:
            break;
        }
    }
    else if(cur_luowen_unit==mode_inch)
    {
        if(cur_page>inch_max_pg-1)
        {
            cur_page = 0;
        }
        if(cur_page<0)
        {
            cur_page = inch_max_pg-1;
        }
        switch (cur_page)
        {
            case 0:
            ui->bt_val_0->setText("1");
            ui->bt_val_1->setText("1½");
            ui->bt_val_2->setText("1⅝");
            break;
            case 1:
            ui->bt_val_0->setText("1¹¹/₁₆");
            ui->bt_val_1->setText("1¾");
            ui->bt_val_2->setText("2");
            break;
            case 2:
            ui->bt_val_0->setText("2¼");
            ui->bt_val_1->setText("2³/₈");
            ui->bt_val_2->setText("2½");
            break;
            case 3:
            ui->bt_val_0->setText("2¾");
            ui->bt_val_1->setText("2⁷/₈");
            ui->bt_val_2->setText("3");
            break;
            case 4:
            ui->bt_val_0->setText("3¼");
            ui->bt_val_1->setText("3³/₈");
            ui->bt_val_2->setText("3½");
            break;
            case 5:
            ui->bt_val_0->setText("4");
            ui->bt_val_1->setText("4½");
            ui->bt_val_2->setText("4¾");
            break;
            case 6:
            ui->bt_val_0->setText("5");
            ui->bt_val_1->setText("5½");
            ui->bt_val_2->setText("5¾");
            break;
            case 7:
            ui->bt_val_0->setText("6");
            ui->bt_val_1->setText("6½");
            ui->bt_val_2->setText("6¾");
            break;
            case 8:
            ui->bt_val_0->setText("7");
            ui->bt_val_1->setText("8");
            ui->bt_val_2->setText("9");
            break;
            case 9:
            ui->bt_val_0->setText("9½");
            ui->bt_val_1->setText("10");
            ui->bt_val_2->setText("11");
            break;
            case 10:
            ui->bt_val_0->setText("11½");
            ui->bt_val_1->setText("12");
            ui->bt_val_2->setText("13");
            break;
            case 11:
            ui->bt_val_0->setText("13½");
            ui->bt_val_1->setText("14");
            ui->bt_val_2->setText("16");
            break;
            case 12:
            ui->bt_val_0->setText("18");
            ui->bt_val_1->setText("19");
            ui->bt_val_2->setText("20");
            break;
            case 13:
            ui->bt_val_0->setText("22");
            ui->bt_val_1->setText("23");
            ui->bt_val_2->setText("24");
            break;
            case 14:
            ui->bt_val_0->setText("26");
            ui->bt_val_1->setText("27");
            ui->bt_val_2->setText("28");
            break;
            case 15:
            ui->bt_val_0->setText("32");
            ui->bt_val_1->setText("36");
            ui->bt_val_2->setText("38");
            break;
            case 16:
            ui->bt_val_0->setText("40");
            ui->bt_val_1->setText("44");
            ui->bt_val_2->setText("46");
            break;
            case 17:
            ui->bt_val_0->setText("48");
            ui->bt_val_1->setText("56");
            ui->bt_val_2->setText("80");
            break;
            default:
            break;
        }
    }
    else if(cur_luowen_unit==mode_MOD)
    {
        if(cur_page>MOD_max_pg-1)
        {
            cur_page = 0;
        }
        if(cur_page<0)
        {
            cur_page = MOD_max_pg-1;
        }
        switch (cur_page)
        {
            case 0:
            ui->bt_val_0->setText("0.25");
            ui->bt_val_1->setText("0.50");
            ui->bt_val_2->setText("0.75");
            break;
            case 1:
            ui->bt_val_0->setText("1.00");
            ui->bt_val_1->setText("1.25");
            ui->bt_val_2->setText("1.50");
            break;
            case 2:
            ui->bt_val_0->setText("1.75");
            ui->bt_val_1->setText("2.00");
            ui->bt_val_2->setText("2.25");
            break;
            case 3:
            ui->bt_val_0->setText("2.50");
            ui->bt_val_1->setText("2.75");
            ui->bt_val_2->setText("3.00");
            break;
            case 4:
            ui->bt_val_0->setText("3.50");
            ui->bt_val_1->setText("4.00");
            ui->bt_val_2->setText("4.50");
            break;
            case 5:
            ui->bt_val_0->setText("5.00");
            ui->bt_val_1->setText("5.50");
            ui->bt_val_2->setText("6.00");
            break;
            case 6:
            ui->bt_val_0->setText("7.00");
            ui->bt_val_1->setText("8.00");
            ui->bt_val_2->setText("9.00");
            break;
            case 7:
            ui->bt_val_0->setText("10.0");
            ui->bt_val_1->setText("11.0");
            ui->bt_val_2->setText("12.0");
            break;
            case 8:
            ui->bt_val_0->setText("14.0");
            ui->bt_val_1->setText("20.0");
            ui->bt_val_2->setText("");
            break;
            default:
            break;
        }
    }
    else if(cur_luowen_unit==mode_DP)
    {
        if(cur_page>DP_max_pg-1)
        {
            cur_page = 0;
        }
        if(cur_page<0)
        {
            cur_page = DP_max_pg-1;
        }
        switch (cur_page)
        {
            case 0:
            ui->bt_val_0->setText("2");
            ui->bt_val_1->setText("2¼");
            ui->bt_val_2->setText("2¾");
            break;
            case 1:
            ui->bt_val_0->setText("3");
            ui->bt_val_1->setText("3½");
            ui->bt_val_2->setText("4");
            break;
            case 2:
            ui->bt_val_0->setText("4½");
            ui->bt_val_1->setText("5");
            ui->bt_val_2->setText("5½");
            break;
            case 3:
            ui->bt_val_0->setText("6");
            ui->bt_val_1->setText("7");
            ui->bt_val_2->setText("8");
            break;
            case 4:
            ui->bt_val_0->setText("9");
            ui->bt_val_1->setText("10");
            ui->bt_val_2->setText("11");
            break;
            case 5:
            ui->bt_val_0->setText("12");
            ui->bt_val_1->setText("15");
            ui->bt_val_2->setText("16");
            break;
            case 6:
            ui->bt_val_0->setText("18");
            ui->bt_val_1->setText("20");
            ui->bt_val_2->setText("22");
            break;
            case 7:
            ui->bt_val_0->setText("24");
            ui->bt_val_1->setText("28");
            ui->bt_val_2->setText("32");
            break;
            case 8:
            ui->bt_val_0->setText("36");
            ui->bt_val_1->setText("40");
            ui->bt_val_2->setText("44");
            break;
            case 9:
            ui->bt_val_0->setText("48");
            ui->bt_val_1->setText("56");
            ui->bt_val_2->setText("64");
            break;
            case 10:
            ui->bt_val_0->setText("72");
            ui->bt_val_1->setText("");
            ui->bt_val_2->setText("");
            break;
            default:
            break;
        }
    }
}

void FixedVal_widget::show_zhuiluowen_val()
{
    if(cur_page>zhuiluowen_max_pg-1)
    {
        cur_page = 0;
    }
    if(cur_page<0)
    {
        cur_page = zhuiluowen_max_pg-1;
    }
    switch (cur_page)
    {
        case 0:
        ui->bt_val_0->setText("5");
        ui->bt_val_1->setText("8");
        ui->bt_val_2->setText("10");
        break;
        case 1:
        ui->bt_val_0->setText("11");
        ui->bt_val_1->setText("11½");
        ui->bt_val_2->setText("14");
        break;
        case 2:
        ui->bt_val_0->setText("18");
        ui->bt_val_1->setText("19");
        ui->bt_val_2->setText("27");
        break;
        case 3:
        ui->bt_val_0->setText("28");
        ui->bt_val_1->setText("");
        ui->bt_val_2->setText("");
        break;
        default:
        break;
    }
}

void FixedVal_widget::show_feed_val()
{
    if(cur_page>feed_max_pg-1)
    {
        cur_page = 0;
    }
    if(cur_page<0)
    {
        cur_page = feed_max_pg-1;
    }
    if(language==0)
    {
        switch (cur_page)
        {
            case 0:
            ui->bt_val_0->setText("0.05");
            ui->bt_val_1->setText("0.07");
            ui->bt_val_2->setText("0.08");
            break;
            case 1:
            ui->bt_val_0->setText("0.09");
            ui->bt_val_1->setText("0.11");
            ui->bt_val_2->setText("0.12");
            break;
            case 2:
            ui->bt_val_0->setText("0.14");
            ui->bt_val_1->setText("0.16");
            ui->bt_val_2->setText("0.18");
            break;
            case 3:
            ui->bt_val_0->setText("0.20");
            ui->bt_val_1->setText("0.22");
            ui->bt_val_2->setText("0.24");
            break;
            case 4:
            ui->bt_val_0->setText("0.28");
            ui->bt_val_1->setText("0.32");
            ui->bt_val_2->setText("0.36");
            break;
            case 5:
            ui->bt_val_0->setText("0.40");
            ui->bt_val_1->setText("0.44");
            ui->bt_val_2->setText("0.48");
            break;
            case 6:
            ui->bt_val_0->setText("0.56");
            ui->bt_val_1->setText("0.64");
            ui->bt_val_2->setText("0.72");
            break;
            case 7:
            ui->bt_val_0->setText("0.80");
            ui->bt_val_1->setText("0.88");
            ui->bt_val_2->setText("0.96");
            break;
            case 8:
            ui->bt_val_0->setText("1.22");
            ui->bt_val_1->setText("1.28");
            ui->bt_val_2->setText("1.44");
            break;
            case 9:
            ui->bt_val_0->setText("1.60");
            ui->bt_val_1->setText("1.76");
            ui->bt_val_2->setText("1.92");
            break;
            case 10:
            ui->bt_val_0->setText("2.24");
            ui->bt_val_1->setText("2.56");
            ui->bt_val_2->setText("2.88");
            break;
            case 11:
            ui->bt_val_0->setText("3.20");
            ui->bt_val_1->setText("3.52");
            ui->bt_val_2->setText("3.84");
            break;
            case 12:
            ui->bt_val_0->setText("4.48");
            ui->bt_val_1->setText("6.40");
            ui->bt_val_2->setText("");
            break;
            default:
            break;
        }
    }
    else if(language==1)
    {
        switch (cur_page)
        {
            case 0:
            ui->bt_val_0->setText("0.002");
            ui->bt_val_1->setText("0.003");
            ui->bt_val_2->setText("0.004");
            break;
            case 1:
            ui->bt_val_0->setText("0.005");
            ui->bt_val_1->setText("0.006");
            ui->bt_val_2->setText("0.007");
            break;
            case 2:
            ui->bt_val_0->setText("0.008");
            ui->bt_val_1->setText("0.009");
            ui->bt_val_2->setText("0.010");
            break;
            case 3:
            ui->bt_val_0->setText("0.011");
            ui->bt_val_1->setText("0.012");
            ui->bt_val_2->setText("0.013");
            break;
            case 4:
            ui->bt_val_0->setText("0.014");
            ui->bt_val_1->setText("0.015");
            ui->bt_val_2->setText("0.016");
            break;
            case 5:
            ui->bt_val_0->setText("0.018");
            ui->bt_val_1->setText("0.019");
            ui->bt_val_2->setText("0.022");
            break;
            case 6:
            ui->bt_val_0->setText("0.024");
            ui->bt_val_1->setText("0.027");
            ui->bt_val_2->setText("0.032");
            break;
            case 7:
            ui->bt_val_0->setText("0.035");
            ui->bt_val_1->setText("0.039");
            ui->bt_val_2->setText("0.043");
            break;
            case 8:
            ui->bt_val_0->setText("0.049");
            ui->bt_val_1->setText("0.055");
            ui->bt_val_2->setText("0.065");
            break;
            case 9:
            ui->bt_val_0->setText("0.071");
            ui->bt_val_1->setText("0.078");
            ui->bt_val_2->setText("0.086");
            break;
            case 10:
            ui->bt_val_0->setText("0.097");
            ui->bt_val_1->setText("0.110");
            ui->bt_val_2->setText("0.130");
            break;
            case 11:
            ui->bt_val_0->setText("0.142");
            ui->bt_val_1->setText("0.169");
            ui->bt_val_2->setText("0.173");
            break;
            case 12:
            ui->bt_val_0->setText("0.195");
            ui->bt_val_1->setText("0.242");
            ui->bt_val_2->setText("0");
            break;
            default:
            break;
        }
    }
}

void FixedVal_widget::set_fixval()
{
    switch (fixedval_mod)
    {
        case fix_luowen:
        set_luowen_val();
        break;
        case fix_zhuiluowen:
        set_zhuiluowen_val();
        break;
        case fix_feed:
        set_feed_val();
        break;
        default:
        break;
    }
}


void FixedVal_widget::set_luowen_val()
{
    if(cur_luowen_unit==mode_mm)
    {
        switch (cur_page)
        {
            case 0:
            if(bt_press == 0)
            {
                tmp_fixval = 0.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.7;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.75;
            }
            break;
            case 1:
            if(bt_press == 0)
            {
                tmp_fixval = 0.8;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 1;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 1.25;
            }
            break;
            case 2:
            if(bt_press == 0)
            {
                tmp_fixval = 1.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 1.75;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 2;
            }
            break;
            case 3:
            if(bt_press == 0)
            {
                tmp_fixval = 2.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 3;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 3.5;
            }
            break;
            case 4:
            if(bt_press == 0)
            {
                tmp_fixval = 4;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 4.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 5;
            }
            break;
            case 5:
            if(bt_press == 0)
            {
                tmp_fixval = 5.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 6;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 7;
            }
            break;
            case 6:
            if(bt_press == 0)
            {
                tmp_fixval = 8;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 9;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 10;
            }
            break;
            case 7:
            if(bt_press == 0)
            {
                tmp_fixval = 11;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 12;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 14;
            }
            break;
            case 8:
            if(bt_press == 0)
            {
                tmp_fixval = 16;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 18;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 20;
            }
            break;
            case 9:
            if(bt_press == 0)
            {
                tmp_fixval = 22;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 24;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 28;
            }
            break;
            case 10:
            if(bt_press == 0)
            {
                tmp_fixval = 40;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0;
            }
            break;
            default:
            break;
        }
    }
    else if(cur_luowen_unit==mode_inch)
    {
        switch (cur_page)
        {
            case 0:
            if(bt_press == 0)
            {
                tmp_fixval = 1;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 1.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 1.625;
            }
            break;
            case 1:
            if(bt_press == 0)
            {
                tmp_fixval = 1.6857;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 1.75;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 2;
            }
            break;
            case 2:
            if(bt_press == 0)
            {
                tmp_fixval = 2.25;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 2.375;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 2.5;
            }
            break;
            case 3:
            if(bt_press == 0)
            {
                tmp_fixval = 2.75;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 2.875;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 3;
            }
            break;
            case 4:
            if(bt_press == 0)
            {
                tmp_fixval = 3.25;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 3.375;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 3.5;
            }
            break;
            case 5:
            if(bt_press == 0)
            {
                tmp_fixval = 4;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 4.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 4.75;
            }
            break;
            case 6:
            if(bt_press == 0)
            {
                tmp_fixval = 5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 5.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 5.75;
            }
            break;
            case 7:
            if(bt_press == 0)
            {
                tmp_fixval = 6;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 6.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 6.75;
            }
            break;
            case 8:
            if(bt_press == 0)
            {
                tmp_fixval = 7;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 8;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 9;
            }
            break;
            case 9:
            if(bt_press == 0)
            {
                tmp_fixval = 9.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 10;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 11;
            }
            break;
            case 10:
            if(bt_press == 0)
            {
                tmp_fixval = 11.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 12;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 13;
            }
            break;
            case 11:
            if(bt_press == 0)
            {
                tmp_fixval = 13.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 14;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 16;
            }
            break;
            case 12:
            if(bt_press == 0)
            {
                tmp_fixval = 18;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 19;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 20;
            }
            break;
            case 13:
            if(bt_press == 0)
            {
                tmp_fixval = 22;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 23;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 24;
            }
            break;
            case 14:
            if(bt_press == 0)
            {
                tmp_fixval = 26;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 27;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 28;
            }
            break;
            case 15:
            if(bt_press == 0)
            {
                tmp_fixval = 32;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 36;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 38;
            }
            break;
            case 16:
            if(bt_press == 0)
            {
                tmp_fixval = 40;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 44;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 46;
            }
            break;
            case 17:
            if(bt_press == 0)
            {
                tmp_fixval = 48;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 56;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 80;
            }
            break;
            default:
            break;
        }
    }
    else if(cur_luowen_unit==mode_MOD)
    {
        switch (cur_page)
        {
            case 0:
            if(bt_press == 0)
            {
                tmp_fixval = 0.25;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.75;
            }
            break;
            case 1:
            if(bt_press == 0)
            {
                tmp_fixval = 1;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 1.25;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 1.5;
            }
            break;
            case 2:
            if(bt_press == 0)
            {
                tmp_fixval = 1.75;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 2;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 2.25;
            }
            break;
            case 3:
            if(bt_press == 0)
            {
                tmp_fixval = 2.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 2.75;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 3;
            }
            break;
            case 4:
            if(bt_press == 0)
            {
                tmp_fixval = 3.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 4;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 4.5;
            }
            break;
            case 5:
            if(bt_press == 0)
            {
                tmp_fixval = 5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 5.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 6;
            }
            break;
            case 6:
            if(bt_press == 0)
            {
                tmp_fixval = 7;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 8;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 9;
            }
            break;
            case 7:
            if(bt_press == 0)
            {
                tmp_fixval = 10;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 11;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 12;
            }
            break;
            case 8:
            if(bt_press == 0)
            {
                tmp_fixval = 14;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 20;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0;
            }
            break;
            default:
            break;
        }
    }
    else if(cur_luowen_unit==mode_DP)
    {
        switch (cur_page)
        {
            case 0:
            if(bt_press == 0)
            {
                tmp_fixval = 2;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 2.25;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 2.75;
            }
            break;
            case 1:
            if(bt_press == 0)
            {
                tmp_fixval = 3;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 3.5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 4;
            }
            break;
            case 2:
            if(bt_press == 0)
            {
                tmp_fixval = 4.5;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 5;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 5.5;
            }
            break;
            case 3:
            if(bt_press == 0)
            {
                tmp_fixval = 6;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 7;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 8;
            }
            break;
            case 4:
            if(bt_press == 0)
            {
                tmp_fixval = 9;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 10;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 11;
            }
            break;
            case 5:
            if(bt_press == 0)
            {
                tmp_fixval = 12;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 15;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 16;
            }
            break;
            case 6:
            if(bt_press == 0)
            {
                tmp_fixval = 18;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 20;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 22;
            }
            break;
            case 7:
            if(bt_press == 0)
            {
                tmp_fixval = 24;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 28;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 32;
            }
            break;
            case 8:
            if(bt_press == 0)
            {
                tmp_fixval = 36;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 40;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 44;
            }
            break;
            case 9:
            if(bt_press == 0)
            {
                tmp_fixval = 48;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 56;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 64;
            }
            break;
            case 10:
            if(bt_press == 0)
            {
                tmp_fixval = 72;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0;
            }
            break;
            default:
            break;
        }
    }
}

void FixedVal_widget::set_zhuiluowen_val()
{
    switch (cur_page)
    {
        case 0:
        if(bt_press == 0)
        {
            tmp_fixval = 5;
        }
        else if(bt_press == 1)
        {
            tmp_fixval = 8;
        }
        else if(bt_press == 2)
        {
            tmp_fixval = 10;
        }
        break;
        case 1:
        if(bt_press == 0)
        {
            tmp_fixval = 11;
        }
        else if(bt_press == 1)
        {
            tmp_fixval = 11.5;
        }
        else if(bt_press == 2)
        {
            tmp_fixval = 14;
        }
        break;
        case 2:
        if(bt_press == 0)
        {
            tmp_fixval = 18;
        }
        else if(bt_press == 1)
        {
            tmp_fixval = 19;
        }
        else if(bt_press == 2)
        {
            tmp_fixval = 27;
        }
        break;
        case 3:
        if(bt_press == 0)
        {
            tmp_fixval = 28;
        }
        else if(bt_press == 1)
        {
            tmp_fixval = 0;
        }
        else if(bt_press == 2)
        {
            tmp_fixval = 0;
        }
        break;
        default:
        break;
    }
}

void FixedVal_widget::set_feed_val()
{
    if(language==0)
    {
        switch (cur_page)
        {
            case 0:
            if(bt_press == 0)
            {
                tmp_fixval = 0.05;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.07;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.08;
            }
            break;
            case 1:
            if(bt_press == 0)
            {
                tmp_fixval = 0.09;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.11;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.12;
            }
            break;
            case 2:
            if(bt_press == 0)
            {
                tmp_fixval = 0.14;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.16;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.18;
            }
            break;
            case 3:
            if(bt_press == 0)
            {
                tmp_fixval = 0.20;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.22;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.24;
            }
            break;
            case 4:
            if(bt_press == 0)
            {
                tmp_fixval = 0.28;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.32;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.36;
            }
            break;
            case 5:
            if(bt_press == 0)
            {
                tmp_fixval = 0.4;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.44;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.48;
            }
            break;
            case 6:
            if(bt_press == 0)
            {
                tmp_fixval = 0.56;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.64;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.72;
            }
            break;
            case 7:
            if(bt_press == 0)
            {
                tmp_fixval = 0.8;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.88;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.96;
            }
            break;
            case 8:
            if(bt_press == 0)
            {
                tmp_fixval = 1.12;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 1.28;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 1.44;
            }
            break;
            case 9:
            if(bt_press == 0)
            {
                tmp_fixval = 1.60;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 1.76;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 1.92;
            }
            break;
            case 10:
            if(bt_press == 0)
            {
                tmp_fixval = 2.24;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 2.56;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 2.88;
            }
            break;
            case 11:
            if(bt_press == 0)
            {
                tmp_fixval = 3.2;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 3.52;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 3.84;
            }
            break;
            case 12:
            if(bt_press == 0)
            {
                tmp_fixval = 4.48;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 6.4;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0;
            }
            break;
            default:
            break;
        }
    }
    else if(language==1)
    {
        switch (cur_page)
        {
            case 0:
            if(bt_press == 0)
            {
                tmp_fixval = 0.002;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.003;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.004;
            }
            break;
            case 1:
            if(bt_press == 0)
            {
                tmp_fixval =0.005;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.006;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.007;
            }
            break;
            case 2:
            if(bt_press == 0)
            {
                tmp_fixval = 0.008;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.009;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.010;
            }
            break;
            case 3:
            if(bt_press == 0)
            {
                tmp_fixval = 0.011;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.012;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.013;
            }
            break;
            case 4:
            if(bt_press == 0)
            {
                tmp_fixval = 0.014;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.015;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.016;
            }
            break;
            case 5:
            if(bt_press == 0)
            {
                tmp_fixval = 0.018;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.019;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.022;
            }
            break;
            case 6:
            if(bt_press == 0)
            {
                tmp_fixval = 0.024;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.027;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.032;
            }
            break;
            case 7:
            if(bt_press == 0)
            {
                tmp_fixval = 0.035;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.039;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.043;
            }
            break;
            case 8:
            if(bt_press == 0)
            {
                tmp_fixval = 0.049;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.055;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.065;
            }
            break;
            case 9:
            if(bt_press == 0)
            {
                tmp_fixval = 0.071;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.078;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.086;
            }
            break;
            case 10:
            if(bt_press == 0)
            {
                tmp_fixval = 0.097;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.110;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.130;
            }
            break;
            case 11:
            if(bt_press == 0)
            {
                tmp_fixval = 0.142;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.169;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0.173;
            }
            break;
            case 12:
            if(bt_press == 0)
            {
                tmp_fixval = 0.195;
            }
            else if(bt_press == 1)
            {
                tmp_fixval = 0.242;
            }
            else if(bt_press == 2)
            {
                tmp_fixval = 0;
            }
            break;
            default:
            break;
        }
    }

}

void FixedVal_widget::mousePressEvent(QMouseEvent *e)
{
    setAttribute(Qt::WA_NoMouseReplay);
    QWidget::mousePressEvent(e);
}
