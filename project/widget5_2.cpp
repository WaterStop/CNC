#include "widget5_2.h"
#include "ui_widget5_2.h"

static int cur_type =0;

widget5_2::widget5_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget5_2)
{
    ui->setupUi(this);
    set_background();
    set_button();
    set_curnum();
    Deal_Slot();
    INFO_init();
}

widget5_2::~widget5_2()
{
    delete ui;
}

void widget5_2::set_background()
{
    //ui->label_bk->setPixmap(QPixmap(":/new_pic/blue_pic/wg5_bk.png"));
//    setAutoFillBackground(true);//做子窗口要设置，否则不显示
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new_pic/blue_pic/wg5_bk_2.png")));
//    setPalette(pal);

    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/wg5_bk_2.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}

void widget5_2::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new_pic/blue_pic/wg5_bk_2.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void widget5_2::set_button()
{
    ui->textEdit_0->setFont(weiruanyahei4);
    ui->textEdit_1->setFont(weiruanyahei4);
    ui->textEdit_2->setFont(weiruanyahei4);
    if(scr_size==0)
    {
        ui->bt_type1->setGeometry(23,31,25,25);
        ui->bt_type2->setGeometry(101,31,25,25);
        ui->bt_type3->setGeometry(101,105,25,25);
        ui->bt_type4->setGeometry(23,105,25,25);
        ui->textEdit_0->setGeometry(182,32,23,15);
        ui->textEdit_1->setGeometry(182,32,23,15);
        ui->textEdit_2->setGeometry(182,113,23,15);
    }
    else if(scr_size==1)
    {

        ui->bt_type1->setGeometry(30,40,32,32);
        ui->bt_type2->setGeometry(130,40,32,32);
        ui->bt_type3->setGeometry(130,135,32,32);
        ui->bt_type4->setGeometry(30,135,32,32);
        ui->textEdit_0->setGeometry(230,42,30,20);
        ui->textEdit_1->setGeometry(230,93,30,20);
        ui->textEdit_2->setGeometry(230,146,30,20);
    }
}

void widget5_2::INFO_init()
{
    ui->textEdit_0->setText("99");
    ui->textEdit_1->setText("99");
    ui->textEdit_2->setText("99");
}

void widget5_2::Deal_Slot()
{
    connect(ui->bt_type1,SIGNAL(clicked()),this,SLOT(set_curtype1_solt()));
    connect(ui->bt_type2,SIGNAL(clicked()),this,SLOT(set_curtype2_solt()));
    connect(ui->bt_type3,SIGNAL(clicked()),this,SLOT(set_curtype3_solt()));
    connect(ui->bt_type4,SIGNAL(clicked()),this,SLOT(set_curtype4_solt()));
}

void widget5_2::set_curnum()
{
    ui->bt_type1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_2_type1_off.png);}");
    //ui->bt_type1->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/wg5_2_type1_off.png);}");
    ui->bt_type2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_2_type2_off.png);}");
    ui->bt_type3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_2_type3_off.png);}");
    ui->bt_type4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_2_type4_off.png);}");
    switch(cur_type)
    {
        case 0:
        ui->bt_type1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_num1_on.png);}");
        break;
        case 1:
        ui->bt_type2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_num2_on.png);}");
        break;
        case 2:
        ui->bt_type3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_num3_on.png);}");
        break;
        case 3:
        ui->bt_type4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg5_num4_on.png);}");
        break;
        default:
        break;
    }
}

void  widget5_2::set_curtype1_solt()
{
    cur_type =0;
    set_curnum();
}
void  widget5_2::set_curtype2_solt()
{
    cur_type =1;
    set_curnum();
}

void  widget5_2::set_curtype3_solt()
{
    cur_type =2;
    set_curnum();
}
void  widget5_2::set_curtype4_solt()
{
    cur_type =3;
    set_curnum();
}
