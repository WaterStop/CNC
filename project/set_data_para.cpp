#include "set_data_para.h"
#include "ui_set_data_para.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

static QStringList file_List;
static int first_line = 1;//首行行号
static QString para_list[PARA_NUM][8];
static QString para_reallist[PARA_NUM][8];//可见列表
static int cur_row = 0;//当前行
static int cur_col = 0;//当前列
static int visible_num = 0;//可见数量
static bool seach_flg = 0;//查找功能 0：关闭  1：开启
static int func_page = 0;//工具栏当前页数
static int last_limt_lev;//之前的权限等级
#if debug_on ==0
QString csvFile = "/home/root/hunhegongye/File/para.csv";
#elif debug_on==1
QString csvFile = "E:\\QT\\program\\BLUE\\File\\para.csv";
#endif

set_data_para::set_data_para(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_data_para)
{
    ui->setupUi(this);
    Init();
}

set_data_para::~set_data_para()
{
    delete ui;
}

void set_data_para::resizeEvent(QResizeEvent *event)
{

}

void set_data_para::Init()
{

    table_init();
    button_set();
    read_file();
    keyboard = new key_board_2(ui->frame);
    //keyboard->setGeometry(10,370,680,240);
    keyboard->setGeometry(315,455,561,240);
    keyboard->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);//设为弹窗
    keyboard->hide();

    lab_tip = new QLabel(ui->frame);
    lab_tip->setGeometry(60,550,150,30);
    lab_tip->setFont(weiruanyahei6);
    lab_tip->setStyleSheet("color:white;");
    Deal_slot();

    load_para_info();

    update_info();

//    qDebug()<<"strlist"<<strlist[0];
}

void set_data_para::table_init()
{
    int i;
    QStringList header;
    table_info = new QTableWidget(ui->frame);
    table_info->horizontalHeader()->setFont(weiruanyahei4);
    table_info->setFont(weiruanyahei4);
    table_info->setGeometry(60,20,561,341);
    table_info->setFocusPolicy(Qt::NoFocus);
    QHeaderView* headerView = table_info->verticalHeader();//去掉初始序列号
    headerView->setHidden(true);
    table_info->setHorizontalHeaderLabels(QStringList() <<"序号"<<"注释"<<"数据");
    table_info->horizontalHeader()->setStretchLastSection(true);//使行列头自适应宽度，最后一列将会填充空白部分
    table_info->setAttribute(Qt::WA_TranslucentBackground, true);
    table_info->setStyleSheet("selection-color:black;selection-background-color:lightblue;"
                         "background-color:rgb(3,14,54);color:rgb(255,255,255);gridline-color:rgb(216, 216,216);"
                         "QTableWidget::item{border:2px solid #D8D8D8;}");
    table_info->horizontalHeader()->setStyleSheet("QHeaderView::section{"
                                                  "border-top:0px solid #D8D8D8;border-left:0px solid #D8D8D8;"
                                                  "border-right:2px solid #D8D8D8;border-bottom: 0.5px solid #D8D8D8;"
                                                  "background-color:rgb(21,96,192);color:rgb(255,255,255);padding:4px;height:30px;}" );//设置表头样式

    table_info->horizontalHeader()->setMinimumHeight(30);

    table_info->setColumnCount(3);
    table_info->setColumnWidth(0, 60);
    table_info->setColumnWidth(1, 270);
    table_info->setColumnWidth(2, 170);
    table_info->setRowCount(10);//设置行数
    table_info->setHorizontalHeaderLabels(QStringList() <<"序号"<<"注释"<<"数据");    
    table_info->setSelectionBehavior(QAbstractItemView::SelectRows);
    table_info->setSelectionMode(QAbstractItemView::SingleSelection);
    table_info->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    table_info->setFocusPolicy(Qt::NoFocus);
    table_info->setFrameShape(QFrame::NoFrame);
    for (i=0;i<10;i++)
    {
        table_info->setRowHeight(i,25);
    }
    for(i = 0;i <Row_NUM;i++)
    {
        table_info->setItem(i,0,new QTableWidgetItem(""));
        table_info->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        table_info->setItem(i,1,new QTableWidgetItem(""));
        table_info->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        table_info->setItem(i,2,new QTableWidgetItem(""));
        table_info->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
}

void set_data_para::button_set()
{
    int i;
    for (i=0;i<8;i++)
    {
        bt_fun_right[i] = new QPushButton(this);
        bt_fun_right[i]->setGeometry(640,20+i*55,40,40);
        bt_fun_right[i]->setFont(weiruanyahei4);
        bt_fun_right[i]->setStyleSheet("border-image:url(:/new/blue_pic/bt_func_bk.png);color: rgb(255, 255, 255);");
    }
    bt_fun_right[0]->setText("查找");
    bt_fun_right[5]->setText("切换");
    bt_fun_right[6]->setText("上一页");
    bt_fun_right[7]->setText("下一页");

}

void set_data_para::Deal_slot()
{
    connect(table_info,SIGNAL(cellClicked(int,int)),this,SLOT(get_item_info_slot(int,int)));
    connect(keyboard,SIGNAL(enter_signal(QString)),this,SLOT(val_input_slot(QString)));
    connect(bt_fun_right[0],SIGNAL(clicked()),this,SLOT(seacher_slot()));
    connect(bt_fun_right[1],SIGNAL(clicked()),this,SLOT(bt_fun_slot1()));
    connect(bt_fun_right[2],SIGNAL(clicked()),this,SLOT(bt_fun_slot2()));
    connect(bt_fun_right[3],SIGNAL(clicked()),this,SLOT(bt_fun_slot3()));
    connect(bt_fun_right[4],SIGNAL(clicked()),this,SLOT(bt_fun_slot4()));
    connect(bt_fun_right[5],SIGNAL(clicked()),this,SLOT(bt_fun_slot5()));
    connect(bt_fun_right[6],SIGNAL(clicked()),this,SLOT(uppage_slot()));
    connect(bt_fun_right[7],SIGNAL(clicked()),this,SLOT(downpage_slot()));
    connect(tip_timer, SIGNAL(timeout()), this, SLOT(clear_tip_slot()));
}

void set_data_para::load_para_info()//载入参数列表
{
    int i,j=0;
    QString strUnicode,str;
    QStringList strList1;
#if debug_on ==0
    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(utf8);
    QTextCodec* gbk = QTextCodec::codecForName("gbk");
#endif

//    for (i=1;i<PARA_NUM;i++)
//    //for(i=1;i<file_List.count()-12;i++)
//    {
//        para_list[i][0]=QString::number(i);//参数号
//        para_list[i][1]=QString::number(para[i].type);//类型，0：int  1：double
//        para_list[i][2]=para[i].macro_name;//对应宏名字
//        #if debug_on ==0
//        //para_list[i][3]=codec->toUnicode(para[i].comment);//参数描述说明
//        para_list[i][3] = gbk->toUnicode(para[i].comment);
//        #elif debug_on==1
//        para_list[i][3]=para[i].comment;//参数描述说明
//        #endif
//        if(para[i].visible==0)
//        {
//            para_list[i][4]="0";//是否可见
//        }
//        else if(para[i].visible==1)
//        {
//            para_list[i][4]="1";//是否可见
//        }
//        if(para[i].type==0)
//        {
//            //para_list[i][5]=para[i].min_val.int_val;//最小值
//            //para_list[i][6]=para[i].max_val.int_val;//最大值
//            //para_list[i][7]=para[i].cur_val.int_val;//当前值
//            para_list[i][5]=QString::number(para[i].min_val.int_val);//最小值
//            para_list[i][6]=QString::number(para[i].max_val.int_val);//最大值
//            para_list[i][7]=QString::number(para[i].cur_val.int_val);//当前值
//        }
//        else if(para[i].type==1)
//        {
//            //para_list[i][5]=para[i].min_val.double_val;//最小值
//            //para_list[i][6]=para[i].max_val.double_val;//最大值
//            //para_list[i][7]=para[i].cur_val.double_val;//当前值
//            para_list[i][5]=QString::number(para[i].min_val.double_val,'f',4);//最小值
//            para_list[i][6]=QString::number(para[i].max_val.double_val,'f',4);//最大值
//            para_list[i][7]=QString::number(para[i].cur_val.double_val,'f',4);//当前值
//        }
//    }
    for(i=1;i<file_List.count()-12;i++)
    {
        str = file_List.at(i);
        strList1 = str.split(",",QString::KeepEmptyParts);
        para_list[strList1.at(0).toInt()][0]=strList1.at(0);//参数号
        //qDebug()<<"参数号:"<<strList1.at(0)<<"i="<<i;
        para_list[strList1.at(0).toInt()][1]=QString::number(para[strList1.at(0).toInt()].type);//类型，0：int  1：double
        para_list[strList1.at(0).toInt()][2]=para[strList1.at(0).toInt()].macro_name;//对应宏名字
        #if debug_on ==0
        //para_list[i][3]=codec->toUnicode(para[i].comment);//参数描述说明
        para_list[strList1.at(0).toInt()][3] = gbk->toUnicode(para[strList1.at(0).toInt()].comment);
        #elif debug_on==1
        para_list[strList1.at(0).toInt()][3]=para[strList1.at(0).toInt()].comment;//参数描述说明
        #endif
        if(para[strList1.at(0).toInt()].visible==0)
        {
            para_list[strList1.at(0).toInt()][4]="0";//是否可见
        }
        else if(para[strList1.at(0).toInt()].visible==1)
        {
            para_list[strList1.at(0).toInt()][4]="1";//是否可见
        }
        if(para[strList1.at(0).toInt()].type==0)
        {
            para_list[strList1.at(0).toInt()][5]=QString::number(para[strList1.at(0).toInt()].min_val.int_val);//最小值
            para_list[strList1.at(0).toInt()][6]=QString::number(para[strList1.at(0).toInt()].max_val.int_val);//最大值
            para_list[strList1.at(0).toInt()][7]=QString::number(para[strList1.at(0).toInt()].cur_val.int_val);//当前值
        }
        else if(para[strList1.at(0).toInt()].type==1)
        {
            para_list[strList1.at(0).toInt()][5]=QString::number(para[strList1.at(0).toInt()].min_val.double_val,'f',4);//最小值
            para_list[strList1.at(0).toInt()][6]=QString::number(para[strList1.at(0).toInt()].max_val.double_val,'f',4);//最大值
            para_list[strList1.at(0).toInt()][7]=QString::number(para[strList1.at(0).toInt()].cur_val.double_val,'f',4);//当前值
        }

    }
    //for (i=1;i<PARA_NUM;i++)
    for(i=1;i<file_List.count()-12;i++)
    {
        str = file_List.at(i);
        strList1 = str.split(",",QString::KeepEmptyParts);
        if(para_list[strList1.at(0).toInt()][4].toInt()<limit_lev)//权限不够不可见
        //if(strList1.at(4).toInt()<limit_lev)//权限不够不可见
        //if(para[i].visible==0)
        {
            j++;
            //qDebug()<<"不可见:"<<"i="<<i<<"j="<<j<<i-j<<"参数号:"<<strList1.at(0)<<para_list[strList1.at(0).toInt()][4];
            continue;
        }
        para_reallist[i-j][0] = para_list[strList1.at(0).toInt()][0];//参数号
        para_reallist[i-j][1] = para_list[strList1.at(0).toInt()][1];//类型，0：int  1：double
        para_reallist[i-j][2] = para_list[strList1.at(0).toInt()][2];//对应宏名字
        para_reallist[i-j][3] = para_list[strList1.at(0).toInt()][3];//参数描述说明
        para_reallist[i-j][4] = para_list[strList1.at(0).toInt()][4];//是否可见
        para_reallist[i-j][5] = para_list[strList1.at(0).toInt()][5];//最小值
        para_reallist[i-j][6] = para_list[strList1.at(0).toInt()][6];//最大值
        para_reallist[i-j][7] = para_list[strList1.at(0).toInt()][7];//当前值
        //qDebug()<<"可见:"<<i-j<<"参数号:"<<strList1.at(0);
    }
    //visible_num = PARA_NUM-j;//可见数
    visible_num = file_List.count()-12-j;//可见数
    qDebug()<<"可见数="<<visible_num;
}

void set_data_para::updata_para_info()//更新参数文件
{
    int i;
    QString msg;

    QFile file(csvFile);
    QTextStream out(&file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        for (i=0;i<PARA_NUM;i++)
        {
            if(para[i].type==0)//int
            {
                out<<QString("%1,").arg(para_list[i][0])<<QString("%1,").arg(para_list[i][1])<<QString("%1,").arg(para_list[i][2])<<QString("%1,").arg(para_list[i][3])<<QString("%1,").arg(para_list[i][4])<<QString("%1,").arg(para_list[i][5])<<QString("%1,").arg(para_list[i][6])<<QString("%1,\n").arg(para_list[i][7]);

            }
            else if(para[i].type==1)//double
            {
                out<<QString("%1,").arg(para_list[i][0])<<QString("%1,").arg(para_list[i][1])<<QString("%1,").arg(para_list[i][2])<<QString("%1,").arg(para_list[i][3])<<QString("%1,").arg(para_list[i][4])<<QString("%1,").arg(para_list[i][5])<<QString("%1,").arg(para_list[i][6])<<QString("%1,\n").arg(para_list[i][7]);
            }
        }
    }
    file.close();

}

void set_data_para::update_info()
{
    int i,j;
    j = 0;
    //load_para_info();
    table_info->clearContents();
    //table_info->setHorizontalHeaderLabels(QStringList() <<"序号"<<"注释"<<"数据");
    for(i = 0;i <Row_NUM;i++)
    {
        //if(i+first_line+j>=PARA_NUM)
        if(i+first_line>=visible_num)
        {
            break;
        }
        //table_info->setItem(i,0,new QTableWidgetItem(QString::number(first_line+i+j+1)));
        table_info->setItem(i,0,new QTableWidgetItem(para_reallist[i+first_line][0]));
        table_info->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        {
            //table_info->setItem(i,1,new QTableWidgetItem(strlist_col1[first_line+i]));
            //table_info->setItem(i,1,new QTableWidgetItem(QString::fromUtf8(para[i+first_line+j].comment)));
            table_info->setItem(i,1,new QTableWidgetItem((para_reallist[i+first_line][3])));
        }
        table_info->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //table_info->setItem(i,1,new QTableWidgetItem(strlist[first_line+i].at(1)));
        //table_info->setItem(i,0,new QTableWidgetItem(strlist_col1.at(first_line+i)));/
        //if(strlist_col2[first_line+i].isEmpty()==1)
        if(para[first_line+i].type==0)
        {
            //table_info->setItem(i,2,new QTableWidgetItem(QString::number(para[first_line+i+j].cur_val.int_val)));
            table_info->setItem(i,2,new QTableWidgetItem((para_reallist[i+first_line][7])));
        }
        else
        {
            //table_info->setItem(i,2,new QTableWidgetItem(QString::number(para[first_line+i+j].cur_val.double_val,'f',4)));
            table_info->setItem(i,2,new QTableWidgetItem((para_reallist[i+first_line][7])));
        }
        table_info->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //table_info->setItem(i,2,new QTableWidgetItem(strlist[first_line+i].at(2)));
        //table_info->setItem(i,0,new QTableWidgetItem(strlist_col2[first_line+i]));/
    }
    if(func_page==0)
    {
        bt_fun_right[1]->setText("进给轴");
        bt_fun_right[2]->setText("第一主轴");
        bt_fun_right[3]->setText("第二主轴");
        bt_fun_right[4]->setText("速度");
    }
    else if(func_page==1)
    {
        bt_fun_right[1]->setText("加减速");
        bt_fun_right[2]->setText("螺距补偿");
        bt_fun_right[3]->setText("反向间隙");
        bt_fun_right[4]->setText("回零参数");
    }
    else if(func_page==2)
    {
        bt_fun_right[1]->setText("手轮");
        bt_fun_right[2]->setText("刀架刀补");
        bt_fun_right[3]->setText("急停限位");
        bt_fun_right[4]->setText("程序工艺");
    }
    else if(func_page==3)
    {
        bt_fun_right[1]->setText("螺纹");
        bt_fun_right[2]->setText("攻丝");
        bt_fun_right[3]->setText("固定循环");
        bt_fun_right[4]->setText("常规配置");
    }
    else if(func_page==4)
    {
        bt_fun_right[1]->setText("总线配置");
        bt_fun_right[2]->setText("");
        bt_fun_right[3]->setText("");
        bt_fun_right[4]->setText("");
    }

}

void set_data_para::set_line_info(QString str)
{
    int i,j;
    j = 0;
    for (i=0;i<PARA_NUM;i++)
    {
        if(para_reallist[i][0]==str)
        {
            first_line = i;
            break;
        }
    }


}

void set_data_para::get_item_info_slot(int row,int col)//获取单元格信息
{
    //qDebug()<<"row"<<row<<"col"<<col;
    cur_row = row;
    cur_col = col;
    keyboard->focus_init();
    keyboard->show();
    keyboard->limit_set(para_reallist[cur_row+first_line][5],para_reallist[cur_row+first_line][6]);
    table_info->selectRow(cur_row);
    //qDebug()<<"val="<<para_reallist[cur_row+first_line][7]<<para[para_reallist[cur_row+first_line][0].toInt()-1].cur_val.int_val;
    //qDebug()<<"cur_row"<<cur_row<<"cur_col"<<cur_col;
}

void set_data_para::set_line_num(QString str)//设定首行行号
{
    set_line_info(str);
}

void set_data_para::Timer_on_slot()
{
    //update_info();
    if(last_limt_lev != limit_lev)
    {
        load_para_info();
        update_info();
        last_limt_lev = limit_lev;
    }

}

void set_data_para::val_input_slot(QString str)
{
    //qDebug()<<"str="<<str<<"first_line="<<first_line<<"cur_row="<<cur_row;
    qDebug()<<"参数号"<<para_reallist[first_line+cur_row][0];
    if(seach_flg==0)
    {
        if(para_reallist[first_line+cur_row][1].toInt()==0)
        {
            if((str.toInt()<para_reallist[first_line+cur_row][5].toInt())||(str.toInt()>para_reallist[first_line+cur_row][6].toInt()))//超出范围
            {
                keyboard->hide();
                tip_set("输入值超出范围");
                return;
            }
            //table_info->setItem(cur_row,2,new QTableWidgetItem(QString::number(para[first_line+cur_row].cur_val.int_val)));
            para[para_reallist[first_line+cur_row][0].toInt()].cur_val.int_val = str.toInt();
            para_reallist[first_line+cur_row][7] = str;

        }
        else if(para_reallist[first_line+cur_row][1].toInt()==1)
        {
            if((str.toDouble()<para_reallist[first_line+cur_row][5].toDouble())||(str.toDouble()>para_reallist[first_line+cur_row][6].toDouble()))//超出范围
            {
                keyboard->hide();
                tip_set("输入值超出范围");
                return;
            }
            //table_info->setItem(cur_row,2,new QTableWidgetItem(QString::number(para[cur_row].cur_val.double_val)));
            para[para_reallist[first_line+cur_row][0].toInt()].cur_val.double_val = str.toDouble();
            para_reallist[first_line+cur_row][7] = str;
        }
        //load_para_info();
        //updata_para_info();
        save_file();
    }
    else
    {
        set_line_num(str);
        seach_flg = 0;
    }


    //table_info->setItem(cur_row,2,new QTableWidgetItem(strlist_col2[first_line+cur_row]));
    //updata_para_info();

    update_info();
    keyboard->hide();
}

void set_data_para::read_file()
{
#if debug_on ==0
    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForLocale(utf8);
    QTextCodec* gbk = QTextCodec::codecForName("gbk");
#endif
    QFile file(csvFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        //in.setCodec("gbk");
        line = in.readAll();
        //line = utf8->toUnicode(string(in.readAll().toStdString()).c_str());
        if(!line.isNull())//字符串有内容
        {
            file_List = line.split("\n",QString::KeepEmptyParts);
        }
    }

    file.close();
}

void set_data_para::save_file()
{
    QElapsedTimer timer;
    timer.start();
    QFile file(csvFile);
    QStringList strList,strList1;
    QString str,str1;
    int i = 0;
//#if debug_on ==0
    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(utf8);
    QTextCodec* gbk = QTextCodec::codecForName("gbk");
//#endif

        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QString line;
            QTextStream out(&file);  //用文件构造流

            //strList = line.split("\n",QString::KeepEmptyParts);
            qDebug()<<"can shu hao："<<para_reallist[first_line+cur_row][0].toInt();
//            for (i=0;i<2000;i++)
//            {
//                para[i].visible = 0;
//            }

            for(i=1;i<file_List.count()-12;i++)
            {
                str = file_List.at(i);
                strList1 = str.split(",",QString::KeepEmptyParts);
                if(strList1.at(0).toInt()==para_reallist[first_line+cur_row][0].toInt())
                {
                    qDebug()<<"str="<<str<<"i="<<i<<"first_line+cur_row="<<para_reallist[first_line+cur_row][0].toInt();
                    qDebug()<<"para="<<para[para_reallist[first_line+cur_row][0].toInt()].cur_val.int_val<<para[para_reallist[first_line+cur_row][0].toInt()-1].cur_val.int_val<<para[para_reallist[first_line+cur_row][0].toInt()+1].cur_val.int_val;
                    if(para_reallist[first_line+cur_row][1].toInt()==0)
                    {
                        strList1.replace(7,QString::number(para[para_reallist[first_line+cur_row][0].toInt()].cur_val.int_val));
                    }
                    else if(para_reallist[first_line+cur_row][1].toInt()==1)
                    {
                        strList1.replace(7,QString::number(para[para_reallist[first_line+cur_row][0].toInt()].cur_val.double_val,'f',4));
                    }
                    str1 = strList1.at(0)+","+strList1.at(1)+","+strList1.at(2)+","+utf8->fromUnicode(para_list[para_reallist[first_line+cur_row][0].toInt()][3])+","+strList1.at(4)+","+strList1.at(5)+","+strList1.at(6)+","+strList1.at(7);
                    file_List.replace(i,str1);
                    //break;
                }
                else
                {
                    str1 = strList1.at(0)+","+strList1.at(1)+","+strList1.at(2)+","+utf8->fromUnicode(para_list[strList1.at(0).toInt()][3])+","+strList1.at(4)+","+strList1.at(5)+","+strList1.at(6)+","+strList1.at(7);
                    file_List.replace(i,str1);
                }
                //para[strList1.at(0).toInt()].visible = 1;
                //strList1.replace(3,utf8->fromUnicode(para_list[i][3]));
            }
            out<<utf8->fromUnicode("序号,类型(0:int;1:double),对应的宏变量,描述,界面是否可见（1:可见;0:不可见）,最小值,最大值,当前值\n");
            for(i=1;i<file_List.count()-12;i++)
            {

//                if(i==file_List.count()-1)
//                {
//                    out<<file_List.at(i);
//                    //out<<utf8->toUnicode(string(file_List.at(i).toStdString()).c_str());
////                    QByteArray byte;
////                    byte=utf8->fromUnicode(file_List.at(i));
////                    out<<byte;
//                }
//                else
                {
                    out<<file_List.at(i)<<"\n";
                    //out<<utf8->toUnicode(string(file_List.at(i).toStdString()).c_str())<<"\n";
//                    QByteArray byte;
//                    byte=utf8->fromUnicode(file_List.at(i));
//                    out<<byte<<"\n";
                    //out<<utf8->fromUnicode(para_list[4][3]);
                }
            }
//            QString tt = QString::fromLocal8Bit("控制轴数");
//            QByteArray byte;
//            QByteArray ba = tt.toLatin1();
//            strcpy(para[1].comment,ba.data());
            //byte=utf8->fromUnicode(tt);
            //out<<byte<<utf8->fromUnicode(para_list[4][3]);
            out<<utf8->fromUnicode("end,,,,1,0,5,0\n")<<utf8->fromUnicode(",,,,,,,\n")<<utf8->fromUnicode(",,,,,,,\n")<<utf8->fromUnicode("类型：0是整数的数参，1是有小数点的数参,,,,,,,\n");
            out<<utf8->fromUnicode(",,,,,,,\n")<<utf8->fromUnicode(",,,,,,,\n")<<utf8->fromUnicode("end表示文件结尾,,,,,,,\n")<<utf8->fromUnicode(",,,,,,,\n")<<utf8->fromUnicode("存取都已序号为索引，顺序读取即可，提高初始化速度，序号就是数组下标,,,,,,,\n");
            out<<utf8->fromUnicode(",,,,,,,\n")<<utf8->fromUnicode("描述中不可以使用‘，’逗号，包括英文的逗号和中文的逗号,,,,,,,\n");
        }
        file.close();
        system("sync");
}

void set_data_para::tip_set(QString str)
{
    lab_tip->setText(str);
    tip_timer->start(3000);
}

void set_data_para::uppage_slot()
{
    first_line = first_line-10;
    if(first_line<1)
    {
        first_line=1;
    }
    update_info();
}

void set_data_para::downpage_slot()
{
    if(first_line>visible_num-10)
    {
        //first_line=visible_num-10;
        return;
    }
    first_line = first_line+10;
    //if(first_line>PARA_NUM-10)

    update_info();
}

void set_data_para::seacher_slot()
{
    seach_flg = 1;
    keyboard->show();
    keyboard->focus_init();
    //set_line_num(0);
}

void set_data_para::clear_tip_slot()
{
    lab_tip->setText("");
}

void set_data_para::bt_fun_slot1()
{
    switch (func_page)
    {
        case 0:
        quick_jump(1);
        break;
        case 1:
        quick_jump(407);
        break;
        case 2:
        quick_jump(802);
        break;
        case 3:
        quick_jump(1201);
        break;
        case 4:
        quick_jump(1601);
        break;
        default:
        break;
    }
    update_info();
}

void set_data_para::bt_fun_slot2()
{
    switch (func_page)
    {
        case 0:
        quick_jump(101);
        break;
        case 1:
        quick_jump(501);
        break;
        case 2:
        quick_jump(901);
        break;
        case 3:
        quick_jump(1301);
        break;
        default:
        break;
    }
    update_info();
}

void set_data_para::bt_fun_slot3()
{
    switch (func_page)
    {
        case 0:
        quick_jump(201);
        break;
        case 1:
        quick_jump(601);
        break;
        case 2:
        quick_jump(1010);
        break;
        case 3:
        quick_jump(1401);
        break;
        default:
        break;
    }
    update_info();
}

void set_data_para::bt_fun_slot4()
{
    switch (func_page)
    {
        case 0:
        quick_jump(302);
        break;
        case 1:
        quick_jump(701);
        break;
        case 2:
        quick_jump(1107);
        break;
        case 3:
        quick_jump(1511);
        break;
        default:
        break;
    }
    update_info();
}

void set_data_para::bt_fun_slot5()
{
    func_page++;
    if(func_page>4)
    {
        func_page = 0;
    }
    update_info();
}

void set_data_para::quick_jump(int num)
{
    set_line_num(QString::number(num));
}

void set_data_para::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPen pen;
    pen.setColor(QColor(216,216,216));
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.drawLine(table_info->pos().rx(),table_info->pos().ry(),table_info->pos().rx(),table_info->size().height()+5);
    painter.end();

}
