#include "key_board_2.h"
#include "ui_key_board_2.h"

static bool num_key = 0;//数字键盘是否打开0：否  1：是
static bool cap_key = 0;//大写是否打开 0:否  1：是
static int ClickCount = 0;//按键计数

key_board_2::key_board_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::key_board_2)
{
    ui->setupUi(this);
    Init();
}

key_board_2::~key_board_2()
{
    delete ui;
}

void key_board_2::resizeEvent(QResizeEvent *event)
{

}

void key_board_2::Init()
{
    int i;
    int tem = 60;
    this->setStyleSheet("background-color: rgb(7,32,79);");
    for (i=0;i<31;i++)
    {
        bt_e[i] = new QPushButton(ui->frame);
        bt_e[i]->setFont(weiruanyahei6);
        bt_e[i]->setFocusPolicy(Qt::NoFocus);
        //bt_e[i]->hide();
    }
    for (i=0;i<10;i++)
    {
        bt_e[i]->setGeometry(140+i*40-tem,40,30,40);
        bt_e[i]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    }
    for (i=10;i<19;i++)
    {
        bt_e[i]->setGeometry(160+(i-10)*40-tem,90,30,40);
        bt_e[i]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    }
    bt_e[19]->setGeometry(140-tem,140,50,40);
    bt_e[19]->setStyleSheet("border-image:url(:/new/blue_pic/key2_cap_bk.png);");
    for (i=20;i<27;i++)
    {
        bt_e[i]->setGeometry(200+(i-20)*41-tem,140,30,40);
        bt_e[i]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    }
    bt_e[27]->setGeometry(485-tem,140,50,40);
    bt_e[27]->setStyleSheet("border-image:url(:/new/blue_pic/key2_back_bk.png);color:white;");
    bt_e[28]->setGeometry(140-tem,190,50,40);
    bt_e[28]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    bt_e[29]->setGeometry(200-tem,190,240,40);
    bt_e[29]->setStyleSheet("border-image:url(:/new/blue_pic/key2_space_bk.png);color:white;");
    bt_e[30]->setGeometry(450-tem,190,80,40);
    bt_e[30]->setStyleSheet("border-image:url(:/new/blue_pic/key2_enter_bk.png);color:white;");

    for (i=0;i<30;i++)
    {
        bt_n[i] = new QPushButton(ui->frame);
        bt_n[i]->setFont(weiruanyahei6);
        bt_n[i]->setFocusPolicy(Qt::NoFocus);
        bt_n[i]->hide();
    }
    for (i=0;i<10;i++)
    {
        bt_n[i]->setGeometry(140+i*40-tem,40,30,40);
        bt_n[i]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    }
    for (i=10;i<20;i++)
    {
        bt_n[i]->setGeometry(140+(i-10)*40-tem,90,30,40);
        bt_n[i]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    }
    bt_n[20]->setGeometry(140-tem,140,50,40);
    bt_n[20]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    for (i=21;i<26;i++)
    {
        bt_n[i]->setGeometry(200+(i-21)*55-tem,140,50,40);
        bt_n[i]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    }
    bt_n[26]->setGeometry(485-tem,140,50,40);
    bt_n[26]->setStyleSheet("border-image:url(:/new/blue_pic/key2_back_bk.png);color:white;");
    bt_n[27]->setGeometry(140-tem,190,50,40);
    bt_n[27]->setStyleSheet("border-image:url(:/new/blue_pic/key2_bk.png);color:white;");
    bt_n[28]->setGeometry(200-tem,190,240,40);
    bt_n[28]->setStyleSheet("border-image:url(:/new/blue_pic/key2_space_bk.png);color:white;");
    bt_n[29]->setGeometry(450-tem,190,80,40);
    bt_n[29]->setStyleSheet("border-image:url(:/new/blue_pic/key2_enter_bk.png);color:white;");

    edit_input = new QLineEdit(ui->frame);
    edit_input->setGeometry(140-tem,0,390,30);
    edit_input->setFont(weiruanyahei6);
    edit_input->setFocus();
    edit_input->setStyleSheet("border-image:url(:/new/blue_pic/edit_bk.png);color:white;");

    lim_val = new QLabel(ui->frame);
    lim_val->setGeometry(330-tem,0,200,30);
    lim_val->setFont(weiruanyahei4);
    lim_val->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    lim_val->setStyleSheet("background-color:transparent;color:white;");

    timer = new QTimer(ui->frame);
    ClickCount = 0;

    button_set();
    Deal_slot();

}

void key_board_2::button_set()
{
    bt_e[0]->setText("Q");
    bt_e[1]->setText("W");
    bt_e[2]->setText("E");
    bt_e[3]->setText("R");
    bt_e[4]->setText("T");
    bt_e[5]->setText("Y");
    bt_e[6]->setText("U");
    bt_e[7]->setText("I");
    bt_e[8]->setText("O");
    bt_e[9]->setText("P");
    bt_e[10]->setText("A");
    bt_e[11]->setText("S");
    bt_e[12]->setText("D");
    bt_e[13]->setText("F");
    bt_e[14]->setText("G");
    bt_e[15]->setText("H");
    bt_e[16]->setText("J");
    bt_e[17]->setText("K");
    bt_e[18]->setText("L");
    bt_e[20]->setText("Z");
    bt_e[21]->setText("X");
    bt_e[22]->setText("C");
    bt_e[23]->setText("V");
    bt_e[24]->setText("B");
    bt_e[25]->setText("N");
    bt_e[26]->setText("M");
    bt_e[28]->setText("123");
    bt_e[29]->setText("space");
    bt_e[30]->setText("enter");

    bt_n[0]->setText("1");
    bt_n[1]->setText("2");
    bt_n[2]->setText("3");
    bt_n[3]->setText("4");
    bt_n[4]->setText("5");
    bt_n[5]->setText("6");
    bt_n[6]->setText("7");
    bt_n[7]->setText("8");
    bt_n[8]->setText("9");
    bt_n[9]->setText("0");
    bt_n[10]->setText("-");
    bt_n[11]->setText("/");
    bt_n[12]->setText(":");
    bt_n[13]->setText(";");
    bt_n[14]->setText("(");
    bt_n[15]->setText(")");
    bt_n[16]->setText("$");
    bt_n[17]->setText("&&");
    bt_n[18]->setText("@");
    bt_n[19]->setText("\"");
    bt_n[20]->setText("#+=");
    bt_n[21]->setText(".");
    bt_n[22]->setText(",");
    bt_n[23]->setText("?");
    bt_n[24]->setText("!");
    bt_n[25]->setText("'");
    bt_n[26]->setText("");
    bt_n[27]->setText("ABC");
    bt_n[28]->setText("space");
    bt_n[29]->setText("enter");

}

void key_board_2::key_press_deal(int ket_num,QString str)
{
   //QWidget *receiver = QApplication::focusWidget();
    QWidget *receiver = edit_input;
    QKeyEvent keyPress(QEvent::KeyPress, ket_num, Qt::NoModifier, str);
    QKeyEvent keyRelease(QEvent::KeyRelease, ket_num, Qt::NoModifier, str);
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}

void key_board_2::Deal_slot()
{
    QSignalMapper * myMapper;
    myMapper = new QSignalMapper(ui->frame);
    QSignalMapper * myMapper1;
    myMapper1 = new QSignalMapper(ui->frame);
    int i;
    //connect(bt_e[0],SIGNAL(pressed()),this,SLOT(press_deal_slot()));
    for (i=0;i<31;i++)
    {
        connect(bt_e[i],SIGNAL(pressed()),myMapper,SLOT(map()));//给槽自定义参数
        myMapper->setMapping(bt_e[i], i);
    }
    for (i=0;i<30;i++)
    {
        connect(bt_n[i],SIGNAL(pressed()),myMapper1,SLOT(map()));//给槽自定义参数
        myMapper1->setMapping(bt_n[i], i);
    }

    connect(myMapper, SIGNAL(mapped(int)), this, SLOT(press_deal_slot(int)));
    connect(myMapper1, SIGNAL(mapped(int)), this, SLOT(press_deal_slot1(int)));

    connect(bt_n[20], SIGNAL(clicked()), this, SLOT(KeyOneClick_slot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_out_slot()));
}

void key_board_2::press_deal_slot(int index)
{
    if(cap_key==1)
    {
        switch(index)
        {
            case 0:
            key_press_deal(Qt::Key_Q,"Q");
            break;
            case 1:
            key_press_deal(Qt::Key_W,"W");
            break;
            case 2:
            key_press_deal(Qt::Key_E,"E");
            break;
            case 3:
            key_press_deal(Qt::Key_R,"R");
            break;
            case 4:
            key_press_deal(Qt::Key_T,"T");
            break;
            case 5:
            key_press_deal(Qt::Key_Y,"Y");
            break;
            case 6:
            key_press_deal(Qt::Key_U,"U");
            break;
            case 7:
            key_press_deal(Qt::Key_I,"I");
            break;
            case 8:
            key_press_deal(Qt::Key_O,"O");
            break;
            case 9:
            key_press_deal(Qt::Key_P,"P");
            break;
            case 10:
            key_press_deal(Qt::Key_A,"A");
            break;
            case 11:
            key_press_deal(Qt::Key_S,"S");
            break;
            case 12:
            key_press_deal(Qt::Key_D,"D");
            break;
            case 13:
            key_press_deal(Qt::Key_F,"F");
            break;
            case 14:
            key_press_deal(Qt::Key_G,"G");
            break;
            case 15:
            key_press_deal(Qt::Key_H,"H");
            break;
            case 16:
            key_press_deal(Qt::Key_J,"J");
            break;
            case 17:
            key_press_deal(Qt::Key_K,"K");
            break;
            case 18:
            key_press_deal(Qt::Key_L,"L");
            break;
            case 19://大写
            change_cap();
            break;
            case 20:
            key_press_deal(Qt::Key_Z,"Z");
            break;
            case 21:
            key_press_deal(Qt::Key_X,"X");
            break;
            case 22:
            key_press_deal(Qt::Key_C,"C");
            break;
            case 23:
            key_press_deal(Qt::Key_V,"V");
            break;
            case 24:
            key_press_deal(Qt::Key_B,"B");
            break;
            case 25:
            key_press_deal(Qt::Key_N,"N");
            break;
            case 26:
            key_press_deal(Qt::Key_M,"M");
            break;
            case 27:
            key_press_deal(Qt::Key_Backspace,"");
            break;
            case 28://数字
            change_key();
            break;
            case 29://空格
            key_press_deal(Qt::Key_Space," ");
            break;
            case 30://回车
            emit enter_signal(edit_input->text());
            edit_input->setText("");
            break;
            default:
            break;
        }
    }
    else
    {
        switch(index)
        {
            case 0:
            key_press_deal(Qt::Key_Q,"q");
            break;
            case 1:
            key_press_deal(Qt::Key_W,"w");
            break;
            case 2:
            key_press_deal(Qt::Key_E,"e");
            break;
            case 3:
            key_press_deal(Qt::Key_R,"r");
            break;
            case 4:
            key_press_deal(Qt::Key_T,"t");
            break;
            case 5:
            key_press_deal(Qt::Key_Y,"y");
            break;
            case 6:
            key_press_deal(Qt::Key_U,"u");
            break;
            case 7:
            key_press_deal(Qt::Key_I,"i");
            break;
            case 8:
            key_press_deal(Qt::Key_O,"o");
            break;
            case 9:
            key_press_deal(Qt::Key_P,"p");
            break;
            case 10:
            key_press_deal(Qt::Key_A,"a");
            break;
            case 11:
            key_press_deal(Qt::Key_S,"s");
            break;
            case 12:
            key_press_deal(Qt::Key_D,"d");
            break;
            case 13:
            key_press_deal(Qt::Key_F,"f");
            break;
            case 14:
            key_press_deal(Qt::Key_G,"g");
            break;
            case 15:
            key_press_deal(Qt::Key_H,"h");
            break;
            case 16:
            key_press_deal(Qt::Key_J,"j");
            break;
            case 17:
            key_press_deal(Qt::Key_K,"k");
            break;
            case 18:
            key_press_deal(Qt::Key_L,"l");
            break;
            case 19://大写
            change_cap();
            break;
            case 20:
            key_press_deal(Qt::Key_Z,"z");
            break;
            case 21:
            key_press_deal(Qt::Key_X,"x");
            break;
            case 22:
            key_press_deal(Qt::Key_C,"c");
            break;
            case 23:
            key_press_deal(Qt::Key_V,"v");
            break;
            case 24:
            key_press_deal(Qt::Key_B,"b");
            break;
            case 25:
            key_press_deal(Qt::Key_N,"n");
            break;
            case 26:
            key_press_deal(Qt::Key_M,"m");
            break;
            case 27:
            key_press_deal(Qt::Key_Backspace,"");
            break;
            case 28://数字
            change_key();
            break;
            case 29://空格
            key_press_deal(Qt::Key_Space," ");
            break;
            case 30://回车
            emit enter_signal(edit_input->text());
            edit_input->setText("");
            break;
            default:
            break;
        }
    }
}

void key_board_2::press_deal_slot1(int index)
{
    switch(index)
    {
        case 0:
        key_press_deal(Qt::Key_1,"1");
        break;
        case 1:
        key_press_deal(Qt::Key_2,"2");
        break;
        case 2:
        key_press_deal(Qt::Key_3,"3");
        break;
        case 3:
        key_press_deal(Qt::Key_4,"4");
        break;
        case 4:
        key_press_deal(Qt::Key_5,"5");
        break;
        case 5:
        key_press_deal(Qt::Key_6,"6");
        break;
        case 6:
        key_press_deal(Qt::Key_7,"7");
        break;
        case 7:
        key_press_deal(Qt::Key_8,"8");
        break;
        case 8:
        key_press_deal(Qt::Key_9,"9");
        break;
        case 9:
        key_press_deal(Qt::Key_0,"0");
        break;
        case 10:
        key_press_deal(Qt::Key_Minus,"-");
        break;
        case 11:
        key_press_deal(Qt::Key_Slash,"/");
        break;
        case 12:
        key_press_deal(Qt::Key_Colon,":");
        break;
        case 13:
        key_press_deal(Qt::Key_Semicolon,";");
        break;
        case 14:
        key_press_deal(Qt::Key_ParenLeft,"(");
        break;
        case 15:
        key_press_deal(Qt::Key_ParenRight,")");
        break;
        case 16:
        key_press_deal(Qt::Key_Dollar,"$");
        break;
        case 17:
        key_press_deal(Qt::Key_Ampersand,"&");
        break;
        case 18:
        key_press_deal(Qt::Key_At,"@");
        break;
        case 19:
        key_press_deal(Qt::Key_QuoteDbl,"\"");
        break;
        case 20://#+=

        break;
        case 21:
        key_press_deal(Qt::Key_Period,".");
        break;
        case 22:
        key_press_deal(Qt::Key_Comma,",");
        break;
        case 23:
        key_press_deal(Qt::Key_Question,"?");
        break;
        case 24:
        key_press_deal(Qt::Key_Exclam,"!");
        break;
        case 25:
        key_press_deal(Qt::Key_Apostrophe,"'");
        break;
        case 26:
        key_press_deal(Qt::Key_Backspace,"");
        break;
        case 27://字母
        change_key();
        break;
        case 28://空格
        key_press_deal(Qt::Key_Space," ");
        break;
        case 29://回车
        emit enter_signal(edit_input->text());
        edit_input->setText("");
        break;
        default:
        break;
    }

}

void key_board_2::change_key()//键盘转换
{
    int i;
    num_key = 1-num_key;
    if(num_key)
    {
        for (i=0;i<31;i++)
        {
            bt_e[i]->hide();
        }
        for (i=0;i<30;i++)
        {
            bt_n[i]->show();
        }
    }
    else
    {
        for (i=0;i<31;i++)
        {
            bt_e[i]->show();
        }
        for (i=0;i<30;i++)
        {
            bt_n[i]->hide();
        }

    }
}

void key_board_2::change_cap()//大小写转换
{
    cap_key = 1-cap_key;
    if(cap_key)
    {
        bt_e[19]->setStyleSheet("border-image:url(:/new/blue_pic/key2_cap_bk_on.png);");
    }
    else
    {
        bt_e[19]->setStyleSheet("border-image:url(:/new/blue_pic/key2_cap_bk.png);");
    }
}

void key_board_2::limit_set(QString str1,QString str2)
{
    QString tem = QString("[%1~%2] ").arg(str1).arg(str2);
    lim_val->setText(tem);
}

void key_board_2::KeyOneClick_slot()//单击
{
    if(ClickCount==0)
    {
        timer->start(800);
        key_press_deal(Qt::Key_NumberSign,"#");
        ClickCount++;
    }
    else if(ClickCount==1)
    {
        key_press_deal(Qt::Key_Backspace,"");
        key_press_deal(Qt::Key_Plus,"+");
        ClickCount++;
    }
    else if(ClickCount==2)
    {
        key_press_deal(Qt::Key_Backspace,"");
        key_press_deal(Qt::Key_Equal,"=");
        ClickCount = 0;
        timer->stop();
    }
}

void key_board_2::timer_out_slot()
{
    ClickCount = 0;
    timer->stop();
}

void key_board_2::change_init()//切换界面刷新
{
    ClickCount = 0;
    edit_input->setText("");
    lim_val->setText("");
}

void key_board_2::focus_init()
{
    //edit_input->setFocus();
    change_init();
}

void key_board_2::paintEvent(QPaintEvent *)
{

}
