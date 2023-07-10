#include "widget2_workpic.h"
#include "ui_widget2_workpic.h"

widget2_workpic::widget2_workpic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget2_workpic)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    //this->setPalette(pal);
    //this->setStyleSheet(0);
    setAttribute(Qt::WA_TranslucentBackground);
}

widget2_workpic::~widget2_workpic()
{
    delete ui;
}

void widget2_workpic::DealSlot()
{

}

void widget2_workpic::draw_running_pic()
{
    int canvasWidth = 400;
    int canvasHeight = 320;
    int m_barWidth = 380;
    int m_barHeight = 170;
    //设置可会绘制的窗口位置（距离左上角）及大小
    //this->setGeometry(40, 50, canvasWidth, canvasHeight);
    this->setGeometry(0, 0, canvasWidth, canvasHeight);
    QPainter painter(this);
    //逻辑坐标：距离窗口坐标系的距离
    painter.setWindow(-100, -100, this->width(), (this->height()));
    // 视口：相对于窗口坐标下要显示的区域
    painter.setViewport(0,0, this->width(), this->height());



    // 设置画笔
    QPen pen;
    pen.setWidth(1);//设置线条的宽度
    pen.setBrush(Qt::white);//设置画笔颜色
    // 设置实线
    pen.setStyle(Qt::SolidLine); //设置画笔的画线风格
    painter.setPen(pen);
    // 对象的实例化baseset.cpp的22行

    // 坐标参数
    // 移动方向参数和放缩倍数
    coordinate variation;
    variation.x = 50;
    variation.y = 50;
    double magp = 0.5;//放缩

    // 代码输出
    dealInterfaceData->outputGCode();

    // 使用QT的绘制接口进行缩放和移动
    painter.save();// 设置新的绘制状态
    QTransform transform; // 定义新画家
    transform.translate(variation.x,variation.y);  // 画家的移动
    transform.scale(magp,magp);  // 定义画的图缩放比例
    painter.setTransform(transform);

    dealInterfaceData->update_pixelArray();
    dealInterfaceData->barPaint(painter);//++++
    dealInterfaceData->tracePaint(painter);
    painter.restore();// 释放当前绘制状态
}

void widget2_workpic::Updata_Info_slot()
{
    update();
}

void widget2_workpic::paintEvent(QPaintEvent *)
{
    //qDebug()<<"draw_running_pic";
    draw_running_pic();
}
