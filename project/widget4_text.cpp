#include "widget4_text.h"
#include "ui_widget4_text.h"

widget4_text::widget4_text(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget4_text)
{
    ui->setupUi(this);
}

widget4_text::~widget4_text()
{
    delete ui;
}

void widget4_text::draw_prossbar(int x,int y)
{
    QPainter painter;
    QPen pen,pen1;
    QString str;
    pen = QPen(QColor(39,172,83));
    pen1.setColor(Qt::white);
    painter.begin(this);
    painter.setPen(pen);
    painter.setFont(weiruanyahei4);
    painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
    //qDebug()<<"draw_prossbar";

    //painter.drawLine(0,0,400,300);

    QPolygon t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14;
    painter.setBrush(QColor(39,172,83));

    t0<<QPoint(x,y+1)<<QPoint(x+17,y+1)<<QPoint(x+17,y-4)<<QPoint(x+1,y-7);
    t1<<QPoint(x+1,y-10)<<QPoint(x+19,y-6)<<QPoint(x+20,y-11)<<QPoint(x+3,y-18);
    t2<<QPoint(x+5,y-21)<<QPoint(x+21,y-14)<<QPoint(x+23,y-19)<<QPoint(x+9,y-29);
    t3<<QPoint(x+11,y-32)<<QPoint(x+25,y-21)<<QPoint(x+29,y-25)<<QPoint(x+16,y-38);
    t4<<QPoint(x+19,y-40)<<QPoint(x+31,y-27)<<QPoint(x+35,y-30)<<QPoint(x+25,y-45);
    t5<<QPoint(x+29,y-46)<<QPoint(x+37,y-31)<<QPoint(x+42,y-33)<<QPoint(x+36,y-50);
    t6<<QPoint(x+39,y-50)<<QPoint(x+45,y-33)<<QPoint(x+50,y-34)<<QPoint(x+47,y-52);
    t7<<QPoint(x+50,y-52)<<QPoint(x+52,y-35)<<QPoint(x+57,y-34)<<QPoint(x+58,y-52);
    //t8<<QPoint(x+60,y-52)<<QPoint(x+60,y-34)<<QPoint(x+64,y-32)<<QPoint(x+69,y-50);
    //t9<<QPoint(x+72,y-49)<<QPoint(x+67,y-32)<<QPoint(x+71,y-29)<<QPoint(x+80,y-45);
    //t10<<QPoint(x+83,y-44)<<QPoint(x+73,y-28)<<QPoint(x+77,y-25)<<QPoint(x+90,y-39);
    //t11<<QPoint(x+92,y-37)<<QPoint(x+79,y-23)<<QPoint(x+83,y-19)<<QPoint(x+98,y-31);
    //t12<<QPoint(x+99,y-29)<<QPoint(x+84,y-17)<<QPoint(x+87,y-12)<<QPoint(x+103,y-20);
    //t13<<QPoint(x+104,y-18)<<QPoint(x+88,y-10)<<QPoint(x+91,y-5)<<QPoint(x+106,y-9);
    //t14<<QPoint(x+107,y-7)<<QPoint(x+91,y-3)<<QPoint(x+91,y+2)<<QPoint(x+108,y+2);
    t8<<QPoint(x+60,y-52)<<QPoint(x+58,y-34)<<QPoint(x+62,y-33)<<QPoint(x+69,y-50);
    t9<<QPoint(x+70,y-49)<<QPoint(x+65,y-33)<<QPoint(x+70,y-31)<<QPoint(x+78,y-46);
    t10<<QPoint(x+80,y-45)<<QPoint(x+71,y-29)<<QPoint(x+76,y-26)<<QPoint(x+88,y-39);
    t11<<QPoint(x+78,y-24)<<QPoint(x+81,y-21)<<QPoint(x+96,y-31)<<QPoint(x+90,y-38);
    t12<<QPoint(x+83,y-18)<<QPoint(x+85,y-14)<<QPoint(x+101,y-22)<<QPoint(x+97,y-29);
    t13<<QPoint(x+85,y-11)<<QPoint(x+87,y-7)<<QPoint(x+105,y-11)<<QPoint(x+103,y-20);
    t14<<QPoint(x+88,y-4)<<QPoint(x+88,y+1)<<QPoint(x+107,y)<<QPoint(x+106,y-8);

    //motion_status->feed_scale = 1.5;
    double feed_per = motion_status->feed_scale;
    if(feed_per==0)
    {

    }
    if(feed_per+Minim>0.1)
    {
        painter.drawPolygon(t0);
    }
    if(feed_per+Minim>0.2)
    {
        painter.drawPolygon(t1);
    }
    if(feed_per+Minim>0.3)
    {
        painter.drawPolygon(t2);
    }
    if(feed_per+Minim>0.4)
    {
        painter.drawPolygon(t3);
    }
    if(feed_per+Minim>0.5)
    {
        painter.drawPolygon(t4);
    }
    if(feed_per+Minim>0.6)
    {
        painter.drawPolygon(t5);
    }
    if(feed_per+Minim>0.7)
    {
        painter.drawPolygon(t6);
    }
    if(feed_per+Minim>0.8)
    {
        painter.drawPolygon(t7);
    }
    if(feed_per+Minim>0.9)
    {
        painter.drawPolygon(t8);
    }
    if(feed_per+Minim>1.0)
    {
        painter.drawPolygon(t9);
    }
    if(feed_per+Minim>1.1)
    {
        painter.setPen(pen);
        painter.drawPolygon(t10);
    }
    if(feed_per+Minim>1.2)
    {
        painter.setPen(pen);
        painter.drawPolygon(t11);
    }
    if(feed_per+Minim>1.3)
    {
        painter.setPen(pen);
        painter.drawPolygon(t12);
    }
    if(feed_per+Minim>1.4)
    {
        painter.setPen(pen);
        painter.drawPolygon(t13);
    }
    if(feed_per+Minim>1.5)
    {
        painter.setPen(pen);
        painter.drawPolygon(t14);
    }

    painter.setPen(pen1);

    painter.drawLine(x+70,y-49,x+65,y-33);
    painter.drawLine(x+65,y-33,x+70,y-31);
    painter.drawLine(x+70,y-31,x+78,y-46);
    painter.drawLine(x+78,y-46,x+70,y-49);

    painter.drawText(182,117, "0");
    painter.drawText(263,117, "150");


    painter.end();
}

void widget4_text::Timer_on_slot()
{
    update();
}

void widget4_text::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPen pen;
    QString str;
    QFont font("Microsoft YaHei", 3, 50, false);

    painter.begin(this);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setFont(font);

    str = QString("%1").arg("F0");
    //painter.translate(20, 50);
    painter.translate(30, 95);      // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-65);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    str = QString("%1").arg("X0.1");
    painter.translate(48, 105);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-65);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    str = QString("%1").arg("F25");
    painter.translate(49, 69);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-35);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    str = QString("%1").arg("X1");
    painter.translate(58, 87);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(-35);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    str = QString("%1").arg("F50");
    painter.translate(84, 62);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(30);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    str = QString("%1").arg("X10");
    painter.translate(75, 80);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(30);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    str = QString("%1").arg("F100");
    painter.translate(109, 80);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(65);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();

    str = QString("%1").arg("X100");
    painter.translate(93, 88);            // 第1步：变换旋转中心到所绘制文字左下角
    painter.rotate(65);                    // 第2步： 旋转一定角度
    painter.drawText(0,0, str);      // 第3步： 绘制文字
    painter.resetMatrix();


    draw_prossbar(169,98);

    painter.end();
}
