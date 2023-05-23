#include "myprogressbar.h"
#include "ui_myprogressbar.h"

MyProgressBar::MyProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyProgressBar)
{
    ui->setupUi(this);
    INFO_init();
}

MyProgressBar::~MyProgressBar()
{
    delete ui;
}

void MyProgressBar::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    image.load(":/new/blue_pic/bar_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void MyProgressBar::INFO_init()
{
    ui->label_value->setStyleSheet("QLabel{border-image:url(:/new/blue_pic/bar_input.png);}");
    ui->label_value->setGeometry(1,0,35,350);
}

void MyProgressBar::set_BarValue(int index)
{
    int y=350-(345*index/100);
    int hight =350-y-4;
    ui->label_value->setGeometry(1,y,35,hight);
}
