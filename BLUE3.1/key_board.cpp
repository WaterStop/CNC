#include "key_board.h"
#include "ui_key_board.h"

static int key_id = 0;

key_board::key_board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::key_board)
{
    ui->setupUi(this);
    set_background();
    set_key_bk();
    key_pressed();
    //ui->bt_num_0->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/num_0_on.png);}");
    ui->bt_num_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_0.png);}");

}

key_board::~key_board()
{
    delete ui;
}

void key_board::set_background()
{
//    setAutoFillBackground(true);//做子窗口要设置，否则不显示
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/new/blue_pic/key_board_bk.png")));
//    setPalette(pal);

    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/key_board_bk.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}


void key_board::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    image.load(":/new_pic/blue_pic/key_board_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void key_board::set_key_bk()
{
    set_key_release();

    if(scr_size==0)
    {
        ui->bt_num_0->setGeometry(5,118,108,37);
        ui->bt_num_1->setGeometry(5,80,53,37);
        ui->bt_num_2->setGeometry(60,80,53,37);
        ui->bt_num_3->setGeometry(114,80,53,37);
        ui->bt_num_4->setGeometry(5,42,53,37);
        ui->bt_num_5->setGeometry(60,42,53,37);
        ui->bt_num_6->setGeometry(114,42,53,37);
        ui->bt_num_7->setGeometry(5,4,53,37);
        ui->bt_num_8->setGeometry(60,4,53,37);
        ui->bt_num_9->setGeometry(114,4,53,37);
        ui->bt_num_point->setGeometry(114,118,53,37);
        ui->bt_back->setGeometry(169,4,53,75);
        ui->bt_enter->setGeometry(169,80,53,75);
    }
    else if(scr_size==1)
    {
        ui->bt_num_0->setGeometry(7,152,139,48);
        ui->bt_num_1->setGeometry(7,103,69,48);
        ui->bt_num_2->setGeometry(77,103,69,48);
        ui->bt_num_3->setGeometry(147,103,69,48);
        ui->bt_num_4->setGeometry(7,55,69,48);
        ui->bt_num_5->setGeometry(77,55,69,48);
        ui->bt_num_6->setGeometry(147,55,69,48);
        ui->bt_num_7->setGeometry(7,6,69,48);
        ui->bt_num_8->setGeometry(77,6,69,48);
        ui->bt_num_9->setGeometry(147,6,69,48);
        ui->bt_num_point->setGeometry(147,152,69,48);
        ui->bt_back->setGeometry(217,6,69,97);
        ui->bt_enter->setGeometry(217,103,69,97);

    }
}

void key_board::set_key_release()
{
    ui->bt_num_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_0.png);}");
    ui->bt_num_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_1.png);}");
    ui->bt_num_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_2.png);}");
    ui->bt_num_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_3.png);}");
    ui->bt_num_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_4.png);}");
    ui->bt_num_5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_5.png);}");
    ui->bt_num_6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_6.png);}");
    ui->bt_num_7->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_7.png);}");
    ui->bt_num_8->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_8.png);}");
    ui->bt_num_9->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_9.png);}");
    ui->bt_num_point->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/key_point.png);}");
    ui->bt_back->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/key_back.png);}");
    ui->bt_enter->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/key_enter.png);}");

    //ui->bt_num_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_0.png);}");

}

void key_board::set_key_press()
{
    switch(key_id)
    {
        case 0:
        //ui->bt_num_0->setStyleSheet("QPushButton{border-image:url(:/new_pic/blue_pic/num_0_on.png);}");
        ui->bt_num_0->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_0_on.png);}");
        //ui->l_but->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/wg2_l_bt.png);}");
        break;
        case 1:
        //ui->bt_num_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_1_on.png);}");
        ui->bt_num_1->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_1_on.png);}");
        break;
        case 2:
        ui->bt_num_2->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_2_on.png);}");
        break;
        case 3:
        ui->bt_num_3->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_3_on.png);}");
        break;
        case 4:
        ui->bt_num_4->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_4_on.png);}");
        break;
        case 5:
        ui->bt_num_5->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_5_on.png);}");
        break;
        case 6:
        ui->bt_num_6->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_6_on.png);}");
        break;
        case 7:
        ui->bt_num_7->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_7_on.png);}");
        break;
        case 8:
        ui->bt_num_8->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_8_on.png);}");
        break;
        case 9:
        ui->bt_num_9->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/num_9_on.png);}");
        break;
        case 10:
        ui->bt_num_point->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/key_point_on.png);}");
        break;
        case 11:
        ui->bt_back->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/key_back_on.png);}");
        break;
        case 12:
        ui->bt_enter->setStyleSheet("QPushButton{border-image:url(:/new/blue_pic/key_enter_on.png);}");
        break;
        default:
        break;
    }
}

void key_board::press_num_0_slot()
{
    key_id =0;
    set_key_press();
//    edit_val  = edit_val +"0";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_0, Qt::NoModifier, QString("0"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_0, Qt::NoModifier, QString("0"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_1_slot()
{
    key_id =1;
    set_key_press();
//    edit_val  = edit_val +"1";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_1, Qt::NoModifier, QString("1"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_1, Qt::NoModifier, QString("1"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_2_slot()
{
    key_id =2;
    set_key_press();
//    edit_val  = edit_val +"2";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_2, Qt::NoModifier, QString("2"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_2, Qt::NoModifier, QString("2"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_3_slot()
{
    key_id =3;
    set_key_press();
//    edit_val  = edit_val +"3";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_3, Qt::NoModifier, QString("3"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_3, Qt::NoModifier, QString("3"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_4_slot()
{
    key_id =4;
    set_key_press();
//    edit_val  = edit_val +"4";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_4, Qt::NoModifier, QString("4"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_4, Qt::NoModifier, QString("4"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_5_slot()
{
    key_id =5;
    set_key_press();
//    edit_val  = edit_val +"5";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_5, Qt::NoModifier, QString("5"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_5, Qt::NoModifier, QString("5"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_6_slot()
{
    key_id =6;
    set_key_press();
//    edit_val  = edit_val +"6";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_6, Qt::NoModifier, QString("6"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_6, Qt::NoModifier, QString("6"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_7_slot()
{
    key_id =7;
    set_key_press();
//    edit_val  = edit_val +"7";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_7, Qt::NoModifier, QString("7"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_7, Qt::NoModifier, QString("7"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_8_slot()
{
    key_id =8;
    set_key_press();
//    edit_val  = edit_val +"8";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_8, Qt::NoModifier, QString("8"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_8, Qt::NoModifier, QString("8"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_num_9_slot()
{
    key_id =9;
    set_key_press();
//    edit_val  = edit_val +"9";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_9, Qt::NoModifier, QString("9"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_9, Qt::NoModifier, QString("9"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_key_point_slot()
{
    key_id =10;
    set_key_press();
//    edit_val  = edit_val +".";
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Period, Qt::NoModifier, QString("."));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Period, Qt::NoModifier, QString("."));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);

}
void key_board::press_key_back_slot()
{
    key_id =11;
    set_key_press();
//    edit_val.chop(1);
//    emit keyPress();
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, QString(""));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier, QString(""));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}
void key_board::press_key_enter_slot()
{
    key_id =12;
    set_key_press();
    Deal_enter_fun();

}

void key_board::set_key_release_slot()
{
    set_key_release();
}

void key_board::key_pressed()
{
    connect(ui->bt_num_0,SIGNAL(pressed()),this,SLOT(press_num_0_slot()));
    connect(ui->bt_num_0,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_1,SIGNAL(pressed()),this,SLOT(press_num_1_slot()));
    connect(ui->bt_num_1,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_2,SIGNAL(pressed()),this,SLOT(press_num_2_slot()));
    connect(ui->bt_num_2,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_3,SIGNAL(pressed()),this,SLOT(press_num_3_slot()));
    connect(ui->bt_num_3,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_4,SIGNAL(pressed()),this,SLOT(press_num_4_slot()));
    connect(ui->bt_num_4,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_5,SIGNAL(pressed()),this,SLOT(press_num_5_slot()));
    connect(ui->bt_num_5,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_6,SIGNAL(pressed()),this,SLOT(press_num_6_slot()));
    connect(ui->bt_num_6,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_7,SIGNAL(pressed()),this,SLOT(press_num_7_slot()));
    connect(ui->bt_num_7,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_8,SIGNAL(pressed()),this,SLOT(press_num_8_slot()));
    connect(ui->bt_num_8,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_9,SIGNAL(pressed()),this,SLOT(press_num_9_slot()));
    connect(ui->bt_num_9,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_num_point,SIGNAL(pressed()),this,SLOT(press_key_point_slot()));
    connect(ui->bt_num_point,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_back,SIGNAL(pressed()),this,SLOT(press_key_back_slot()));
    connect(ui->bt_back,SIGNAL(released()),this,SLOT(set_key_release_slot()));
    connect(ui->bt_enter,SIGNAL(pressed()),this,SLOT(press_key_enter_slot()));
    connect(ui->bt_enter,SIGNAL(released()),this,SLOT(set_key_release_slot()));
}

void key_board::Deal_enter_fun()
{
    qDebug()<<"按回车";
    if(barstock_flg==1)
    {
        emit output_enter_signak();
        return;
    }
    switch (cur_work_mod)
    {
        case waiyuan1:
        emit waiyuan1_enter_signal();
        break;
        case waiyuan2:
        emit waiyuan2_enter_signal();
        break;
        case waiyuan3:
        emit waiyuan3_enter_signal();
        break;
        case duanmian1:
        emit duanmian1_enter_signal();
        break;
        case duanmian2:
        emit duanmian2_enter_signal();
        break;
        case duanmian3:
        emit duanmian3_enter_signal();
        break;
        case likong1:
        emit likong1_enter_signal();
        break;
        case likong2:
        emit likong2_enter_signal();
        break;
        case likong3:
        emit likong3_enter_signal();
        break;
        case likong4:
        emit likong4_enter_signal();
        break;
        case likong5:
        emit likong5_enter_signal();
        break;
        case zhuimian1:
        emit zhuimian1_enter_signal();
        break;
        case zhuimian2:
        emit zhuimian2_enter_signal();
        break;
        case zhuimian3:
        emit zhuimian3_enter_signal();
        break;
        case zhuimian4:
        emit zhuimian4_enter_signal();
        break;
        case luowen1:
        if(luowen_set_flg==0)
        {
            emit luowen1_enter_signal();
        }
        else
        {
            emit luowenset_enter_signal();
        }
        break;
        case luowen2:
        if(luowen_set_flg==0)
        {
            emit luowen2_enter_signal();
        }
        else
        {
            emit luowenset_enter_signal();
        }
        break;
        case luowen3:
        if(luowen_set_flg==0)
        {
            emit luowen3_enter_signal();
        }
        else
        {
            emit luowenset_enter_signal();
        }
        break;
        case luowen4:
        if(luowen_set_flg==0)
        {
            emit luowen4_enter_signal();
        }
        else
        {
            emit luowenset_enter_signal();
        }
        break;
        case daojiao1:
        emit daojiao1_enter_signal();
        break;
        case daojiao2:
        emit daojiao2_enter_signal();
        break;
        case daojiao3:
        emit daojiao3_enter_signal();
        break;
        case daojiao4:
        emit daojiao4_enter_signal();
        break;
        default:
        break;
    }
}
