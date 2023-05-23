#include "mylineedit.h"

//MyLineEdit::MyLineEdit()
//{

//}
MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{
    //setStyleSheet("background: rgb(64, 86, 129);color: rgb(255, 255, 255);border-width:0;border-style:outset");
}
MyLineEdit::~MyLineEdit()
{}

//重写mousePressEvent事件,检测事件类型是不是点击了鼠标左键
void MyLineEdit::mousePressEvent(QMouseEvent *e) {
    //如果单击了就触发clicked信号
    if (e->button() == Qt::LeftButton)
    {
        //触发clicked信号
        selectAll();
        emit clicked();
    }
    //将该事件传给父类处理
    // QLineEdit::mousePressEvent(e);
}
