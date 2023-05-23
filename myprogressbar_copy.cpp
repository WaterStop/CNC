#include "myprogressbar.h"

MyProgressBar::MyProgressBar(QWidget *parent)
{
    //setOrientation(Qt::Vertical);
}

void MyProgressBar::paintEvent(QPaintEvent *paintEvent)
{
        QPixmap m_progressPixmap;
        m_progressPixmap.load(":/new/blue_pic/bar_input.png");
        Q_UNUSED(paintEvent);
        //504是进度条图片的宽度；108是背景图中起始进度条的宽度；
        //计算当前进度条的宽度；m_count初始化为UPPERLIMIT(100)；从UPPERLIMIT减小到0时，加载完成；
        //因此(UPPERLIMIT-m_count)表示的是当前的加载进度；根据图像换算出对应的宽度；
        int progressWidth = (UPPERLIMIT - m_count) * (315-0) / UPPERLIMIT + 0;
        //计算百分比
        float percent = (UPPERLIMIT - m_count) * 100 / UPPERLIMIT;
        //copy进度条样式的一小段作为绘制使用
        QPixmap tempPixmap = m_progressPixmap.copy(10, 40, 15, 35);

        QPainterPath progressPath;
        //QPainterPath,可以绘制自定义路径。这里将其处理为圆角矩形；
        //5个参数分别为x, y, w, h, roundness；
        //可以注意到这里的w是变量，即加载时的进度变化；
        progressPath.addRoundRect(0, 0, 35, progressWidth, 99);

        QPainter painter(this);
        //设置为无笔画，这里貌似写不写都无所谓；
        painter.setPen(Qt::NoPen);
        //设置Brush为上面的tempPixmap,即每次绘制出来都是进度条的样式；
        painter.setBrush(QBrush(tempPixmap));
        //设置抗锯齿
        painter.setRenderHints(QPainter::Antialiasing, true);
        //绘制前面定义好的QPainterPath，至此进度条绘制结束；
        painter.drawPath(progressPath);
        //在这里顺便把百分比显示出来，设置为蓝色笔画
        painter.setPen(QPen(Qt::blue));
        //设置字体大小
        painter.setFont(QFont("Helvetica", 30));
        //绘制文本可以采用drawText，指定x, y, QString即可；
        painter.drawText(380, 240, QString("%1\%").arg(percent));
}
