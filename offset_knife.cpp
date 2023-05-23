#include "offset_knife.h"
#include "ui_offset_knife.h"

Offset_knife::Offset_knife(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Offset_knife)
{
    ui->setupUi(this);
    set_background();
    set_combobox();
}

Offset_knife::~Offset_knife()
{
    delete ui;
}

void Offset_knife::set_background()
{
    setAutoFillBackground(true);//做子窗口要设置，否则不显示
    QPalette pal =this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap("../blue_pic/oft_hd.png")));
    setPalette(pal);
}


void Offset_knife::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load("../BLUE/blue_pic/oft_hd.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void Offset_knife::set_combobox()
{
    if(scr_size==0)
    {
        ui->comboBox_l_1->setGeometry(70,96,62,21);
        ui->comboBox_l_2->setGeometry(70,129,62,21);
        ui->comboBox_l_3->setGeometry(70,162,62,21);
        ui->comboBox_l_4->setGeometry(70,195,62,21);
        ui->comboBox_l_5->setGeometry(70,228,62,21);
        ui->comboBox_l_6->setGeometry(70,260,62,21);

        ui->comboBox_r_1->setGeometry(179,96,39,21);
        ui->comboBox_r_2->setGeometry(179,129,39,21);
        ui->comboBox_r_3->setGeometry(179,162,39,21);
        ui->comboBox_r_4->setGeometry(179,195,39,21);
        ui->comboBox_r_5->setGeometry(179,228,39,21);
        ui->comboBox_r_6->setGeometry(179,260,39,21);
    }
    else if(scr_size==1)
    {
        ui->comboBox_l_1->setGeometry(90,124,80,27);
        ui->comboBox_l_2->setGeometry(90,166,80,27);
        ui->comboBox_l_3->setGeometry(90,208,80,27);
        ui->comboBox_l_4->setGeometry(90,250,80,27);
        ui->comboBox_l_5->setGeometry(90,292,80,27);
        ui->comboBox_l_6->setGeometry(90,334,80,27);

        ui->comboBox_r_1->setGeometry(230,124,50,27);
        ui->comboBox_r_2->setGeometry(230,166,50,27);
        ui->comboBox_r_3->setGeometry(230,208,50,27);
        ui->comboBox_r_4->setGeometry(230,250,50,27);
        ui->comboBox_r_5->setGeometry(230,292,50,27);
        ui->comboBox_r_6->setGeometry(230,334,50,27);

    }
}
