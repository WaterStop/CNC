#include "widget5_2.h"
#include "ui_widget5_2.h"

static int cur_type =0;

widget5_2::widget5_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget5_2)
{
    ui->setupUi(this);
    set_background();
    INFO_init();
    set_button();
    set_curnum();
    Deal_Slot();
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
    ui->textEdit_0->hide();
    ui->textEdit_1->hide();
    ui->textEdit_2->hide();
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
    int i;
//    ui->textEdit_0->setText("99");
//    ui->textEdit_1->setText("99");
//    ui->textEdit_2->setText("99");
    for (i=0;i<3;i++)
    {
        lab[i] = new QLabel(ui->frame);
        lab[i]->setGeometry(180,30+i*50,91,42);
    }
    lab[0]->setStyleSheet("border-image:url(:/new/blue_pic/wg5_mod1_on.png);");
    lab[1]->setStyleSheet("border-image:url(:/new/blue_pic/wg5_mod2_off.png);");
    lab[2]->setStyleSheet("border-image:url(:/new/blue_pic/wg5_mod3_off.png);");

    for (i=0;i<2;i++)
    {
        cur_tcode[i] = new QLabel(ui->frame);
        cur_tcode[i]->setStyleSheet("color:white;");
    }
    cur_tcode[0]->setGeometry(80,85,41,15);
    cur_tcode[0]->setFont(weiruanyahei6);
    cur_tcode[1]->setGeometry(86,105,40,15);
    cur_tcode[1]->setFont(weiruanyahei4);

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

void widget5_2::Timer_on_slot()
{
    QString str;
    str = QString("T%1").arg(motion_status->CurTCode,2,10,QLatin1Char('0'));
    cur_tcode[0]->setText(str);
    str = QString("%1").arg(motion_status->CurTCode,2,10,QLatin1Char('0'));
    cur_tcode[1]->setText(str);
}
