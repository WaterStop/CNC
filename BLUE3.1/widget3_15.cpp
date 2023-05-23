#include "widget3_15.h"
#include "ui_widget3_15.h"

static bool shuaiwei = 0;
static bool cuoweijiagong = 0;

widget3_15::widget3_15(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget3_15)
{
    ui->setupUi(this);
    set_background();
    set_edit();
    set_button();
    DealSlot();
    ui->bt_close->hide();
}

widget3_15::~widget3_15()
{
    delete ui;
}

void widget3_15::set_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg3_bk18.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void widget3_15::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new/blue_pic/wg3_bk18.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget3_15::set_edit()
{
    ui->edit_1->setFont(weiruanyahei6);
    ui->edit_2->setFont(weiruanyahei6);
    ui->edit_3->setFont(weiruanyahei6);
    if(scr_size==0)
    {
        ui->edit_1->setGeometry(73,73,89,24);
        ui->edit_2->setGeometry(73,105,89,24);
        ui->edit_3->setGeometry(73,139,89,24);
    }
    else if(scr_size==1)
    {
        ui->edit_1->setGeometry(125,45,80,30);
        ui->edit_2->setGeometry(125,90,80,30);
        ui->edit_3->setGeometry(125,220,80,30);

    }
}

void widget3_15::set_button()
{
    //ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    //ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    dis_switch();
    ui->bt_lastpage->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_lastpage.png);}");
    ui->bt_close->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg3_bt_close.png);}");

    if(scr_size==0)
    {
        ui->bt_1->setGeometry(73,73,89,24);
        ui->bt_2->setGeometry(73,105,89,24);
        ui->bt_close->setGeometry(248,17,20,20);
        ui->bt_lastpage->setGeometry(73,105,89,24);
    }
    else if(scr_size==1)
    {
        ui->bt_1->setGeometry(125,133,66,26);
        ui->bt_2->setGeometry(125,180,66,26);
        ui->bt_close->setGeometry(248,17,20,20);
        ui->bt_lastpage->setGeometry(25,380,20,20);

    }

}

void widget3_15::DealSlot()
{
     connect(ui->bt_1,SIGNAL(clicked()),this,SLOT(shuaiwei_slot()));
     connect(ui->bt_2,SIGNAL(clicked()),this,SLOT(cuoweijiagong_slot()));
     connect(ui->bt_lastpage,SIGNAL(clicked()),this,SLOT(goback_lastpage_slot()));
}

void widget3_15::dis_switch()
{
    if(shuaiwei == 0)
    {
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }
    else
    {
        ui->bt_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");
    }
    if(cuoweijiagong == 0)
    {
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_off.png);}");
    }
    else
    {
        ui->bt_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg4_bt_on.png);}");
    }
}

void widget3_15::shuaiwei_slot()
{
    shuaiwei = 1-shuaiwei;
    dis_switch();
}

void widget3_15::cuoweijiagong_slot()
{
    cuoweijiagong = 1-cuoweijiagong;
    dis_switch();
}

void widget3_15::goback_lastpage_slot()
{
    st_lw.duotou = ui->edit_1->text().toInt();
    st_lw.qishijiaodu = ui->edit_1->text().toDouble();
    emit back_lastpage();
}

void widget3_15::Foucus_init()
{
    //ClearEdit();
    ui->edit_1->setFocus();
    ui->edit_1->selectAll();
}

void widget3_15::ClearEdit()
{
    ui->edit_1->setText("0");
    ui->edit_2->setText("0");
    ui->edit_3->setText("0");
}

void widget3_15::Focus_switch_slot()
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
        ui->edit_1->setFocus();
        ui->edit_1->selectAll();
    }
}

void widget3_15::getInfo( s_screwThreadMode1* screwThread1)
{
    qDebug()<<"ui->edit_1->text()="<<ui->edit_1->text();
    screwThread1->multi_head = ui->edit_1->text().toInt();
    qDebug()<<"screwThread1->multi_head"<<screwThread1->multi_head;
}
