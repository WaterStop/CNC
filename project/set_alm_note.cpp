#include "set_alm_note.h"
#include "ui_set_alm_note.h"

static int max_error_note = 200;
static int first_line = 0;//首行行号
static int cur_page = 0;//当前页数
static int max_page = 0;//最大页数
static int cur_line = 0;//已保存的行
static int cur_row = 0;//当前行
static int cur_col = 0;//当前列
static bool time_ord = 1;//时间排序方式 0：顺序 1：倒序
#if debug_on ==0
static QString path = "/home/root/hunhegongye/File";
#elif debug_on==1
static QString path = "E:\\QT\\program\\BLUE\\File";
#endif
static QString hisalmnote = "HISALM_NOTE.csv";



struct CNC_ALMNOTE_LIST
{
    int alm_no;
    int alm_type;
    QString alm_cont;
    QString alm_time;
};
CNC_ALMNOTE_LIST almnote_list[200];

set_alm_note::set_alm_note(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_alm_note)
{
    ui->setupUi(this);
    Init();
}

set_alm_note::~set_alm_note()
{
    delete ui;
}

void set_alm_note::resizeEvent(QResizeEvent *event)
{

}

void set_alm_note::Init()
{
    int i;
    QString str;

    for (i=0;i<4;i++)
    {
        label_text[i] = new QLabel(ui->frame);

        label_text[i]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        label_text[i]->setStyleSheet("color: rgb(255, 255, 255);");
    }
    //label_text[0]->setGeometry(70,430,561,60);
    //label_text[0]->setText("报警具体注释");
    edit_note = new QTextEdit(ui->frame);
    edit_note->setFont(weiruanyahei4);
    edit_note->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    edit_note->setGeometry(60,430,561,100);
    edit_note->setStyleSheet("background:transparent;color:white;border:2px solid #D8D8D8;");

    table_init();
    read_file();
    button_set();
    Deal_slot();
    max_page = cur_line/row_num+1;

}

void set_alm_note::table_init()
{
    int i;
    QStringList header;
    table = new QTableWidget(ui->frame);
    //table->setSliderDir(DIR_VERI);
    //table->horizontalHeader()->setHidden(true);//去掉表头
    header<<"报警号"<<"报警类型"<<"报警内容";
    table->setHorizontalHeaderLabels(header);

    table->horizontalHeader()->setFont(weiruanyahei4);
    table->setFont(weiruanyahei4);
    QHeaderView* headerView = table->verticalHeader();//去掉初始序列号
    headerView->setHidden(true);
    //table->horizontalHeader()->setStretchLastSection(true);//使行列头自适应宽度，最后一列将会填充空白部分
    table->setAttribute(Qt::WA_TranslucentBackground, true);
    table->horizontalHeader()->setAttribute(Qt::WA_TranslucentBackground, true);
//    table->setStyleSheet("QTableWidget{ background-color:transparent;color:rgb(255,255,255);gridline-color:rgb(216, 216,216);}"
//                         "QTableWidget::item{border-left:2px solid #D8D8D8;}");
    table->setStyleSheet("selection-color:black;selection-background-color:lightblue;"
                         "background-color:rgb(3,14,54);color:rgb(255,255,255);gridline-color:rgb(216, 216,216);"
                         "QTableWidget::item{border-left:4px solid #D8D8D8;}");
    table->horizontalHeader()->setStyleSheet("QHeaderView::section{"
                "border-top:0px solid #D8D8D8;border-left:0px solid #D8D8D8;"
                "border-right:2px solid #D8D8D8;border-bottom: 0.5px solid #D8D8D8;"
                "background-color:rgb(21,96,192);color:rgb(255,255,255);padding:4px;height:30px;}" );//设置表头样式
    table->horizontalHeader()->setMinimumHeight(25);
    //table->horizontalHeader()->setDefaultSectionSize(200);
    //table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->setGeometry(60,60,561,340);
    table->setColumnCount(4);
    table->setColumnWidth(0, 60);
    table->setColumnWidth(1, 107);
    table->setColumnWidth(2, 220);
    table->setColumnWidth(3, 170);
    table->setRowCount(row_num);//设置行数    
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    table->setFocusPolicy(Qt::NoFocus);
    table->setHorizontalHeaderLabels(QStringList() <<"报警号"<<"报警类型"<<"报警内容"<<"报警时间");
    table->setFrameShape(QFrame::NoFrame);
    for (i=0;i<row_num;i++)
    {
        table->setRowHeight(i,25);
    }
    //set_info();

}

void set_alm_note::button_set()
{
    int i;
    for (i=0;i<8;i++)
    {
        bt_fun_right[i] = new QPushButton(this);
        bt_fun_right[i]->setGeometry(640,20+i*55,40,40);
        bt_fun_right[i]->setFont(weiruanyahei4);
        bt_fun_right[i]->setStyleSheet("border-image:url(:/new/blue_pic/bt_func_bk.png);color: rgb(255, 255, 255);");
    }
    for (i=2;i<6;i++)
    {
        bt_fun_right[i]->hide();
    }
    bt_fun_right[0]->setText("保存");
    bt_fun_right[1]->setText("清空");
    bt_fun_right[2]->setText("时间排序");
    bt_fun_right[3]->setText("类型排序");
    bt_fun_right[6]->setText("上一页");
    bt_fun_right[7]->setText("下一页");
}

void set_alm_note::Deal_slot()
{
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(get_item_info_slot(int,int)));
    connect(bt_fun_right[0],SIGNAL(clicked()),this,SLOT(save_func_slot()));
    connect(bt_fun_right[1],SIGNAL(clicked()),this,SLOT(del_almnote_slot()));
    connect(bt_fun_right[6],SIGNAL(clicked()),this,SLOT(pageup_slot()));
    connect(bt_fun_right[7],SIGNAL(clicked()),this,SLOT(pagedown_slot()));
}

void set_alm_note::update_info()
{
    int i;
    {
        table->clearContents();//清除表格数据
        for(i = 0;i <row_num;i++)
        {
            if(i+first_line<max_error_note)
            {
                //if(almnote_list[i+first_line].alm_cont.isEmpty()==0)
//                if(cur_line-(i+first_line)-1<0)
//                {
//                    break;
//                }
                if(time_ord==1)
                {
                    if(almnote_list[i+first_line].alm_no==0)
                    {
                        break;
                    }
                    table->setItem(i,0,new QTableWidgetItem(tr("%1").arg(almnote_list[cur_line-(i+first_line)-1].alm_no)));
                    table->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    if(almnote_list[cur_line-(i+first_line)-1].alm_type==0)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("系统报警")));
                    }
                    else if(almnote_list[cur_line-(i+first_line)-1].alm_type==1)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("任务报警")));
                    }
                    else if(almnote_list[cur_line-(i+first_line)-1].alm_type==2)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("解释器报警")));
                    }
                    else if(almnote_list[cur_line-(i+first_line)-1].alm_type==3)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("运动报警")));
                    }
                    else if(almnote_list[cur_line-(i+first_line)-1].alm_type==4)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("PLC报警")));
                    }
                    else if(almnote_list[cur_line-(i+first_line)-1].alm_type==5)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("总线报警")));
                    }
                    else if(almnote_list[cur_line-(i+first_line)-1].alm_type==6)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("GUI报警")));
                    }
                    else if(almnote_list[cur_line-(i+first_line)-1].alm_type==7)
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("伺服报警")));
                    }
                    table->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(i,2,new QTableWidgetItem(tr("%1").arg(almnote_list[cur_line-(i+first_line)-1].alm_cont)));
                    table->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(i,3,new QTableWidgetItem(tr("%1").arg(almnote_list[cur_line-(i+first_line)-1].alm_time)));
                    table->item(i,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }
                edit_update();
            }

        }
    }
}

void set_alm_note::set_info()
{
    int i;
    //max_error_note = motion_err->size;
    if(max_error_note<10)
    {
        table->setRowCount(10);//设置行数
        for(i = 0;i <max_error_note;i++)
        {
            table->setRowHeight(i,30);
            table->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
            //内容水平垂直居中,注意一定要先设置内容，此属性才会有效
            table->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            //静态数据列,static_data是在头文件中定义的常量
            table->setItem(i,1,new QTableWidgetItem(tr("驱动器报警 %1").arg(i + 1)));
            table->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            //table->item(0, 0)->setBackground(QColor(0x00,0xff,0x00,0x00));
        }
        for(i = max_error_note;i <10;i++)
        {
            table->setRowHeight(i,30);
            table->setItem(i,0,new QTableWidgetItem(""));
            //内容水平垂直居中,注意一定要先设置内容，此属性才会有效
            table->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            //静态数据列,static_data是在头文件中定义的常量
            table->setItem(i,1,new QTableWidgetItem(""));
            table->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        }
    }
    else
    {
        table->setRowCount(max_error_note);//设置行数
        for(i = 0;i <max_error_note;i++)
        {
            table->setRowHeight(i,30);
            table->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
            //内容水平垂直居中,注意一定要先设置内容，此属性才会有效
            table->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            //静态数据列,static_data是在头文件中定义的常量
            table->setItem(i,1,new QTableWidgetItem(tr("驱动器报警 %1").arg(i + 1)));
            table->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            table->setItem(i,2,new QTableWidgetItem(tr("报警 %1").arg(i + 1)));
            table->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            table->setItem(i,3,new QTableWidgetItem(tr("时间 %1").arg(i + 1)));
            table->item(i,3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        }
    }
    save_file();
}

void set_alm_note::read_file()
{
    QStringList strList;
    int i=0;
    //QString path = ":/new/File";
    QFile file(path+"/"+hisalmnote);
        if (file.open(QIODevice::ReadOnly /*| QIODevice::Text*/))
        {
            QString line;
            QTextStream in(&file);  //用文件构造流
            line = in.readLine();//读取一行放到字符串里
            while(!line.isNull())//字符串有内容
            {
                strList = line.split(",",QString::KeepEmptyParts);
                almnote_list[i].alm_no = strList[0].toUInt();
                almnote_list[i].alm_type = strList[1].toUInt();
                almnote_list[i].alm_cont = strList[2];
                almnote_list[i].alm_time = strList[3];
                line=in.readLine();//循环读取下行
                i++;
            }
            cur_line = i;//获取文件行数
            //qDebug()<<"cur_line="<<cur_line;
            qDebug()<<"成功";
        }
        file.close();
        update_info();
}

bool set_alm_note::save_file()
{
    //QString path = ":/new/File";
    //QString path = "E:\\QT\\program\\BLUE\\File";
    QFile file(path+"/"+hisalmnote);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        //1.选择导出的csv文件保存路径
        //qDebug()<<"文件打开成功";
        //2.文件名采用系统时间戳生成唯一的文件
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yy-mm-dd hh:mm:ss");
        QTextStream out(&file);

        if(cur_line==0)
        {
            out<<"";
        }
        for (int i=0;i<cur_line;i++)
        {
            if(QString(almnote_list[i].alm_cont).isEmpty()==1)
            {
                out<<QString("%1,").arg(almnote_list[i].alm_no)<<QString("%1,").arg(almnote_list[i].alm_type)<<QString("%1,").arg(" ")<<QString("%1,\n").arg(almnote_list[i].alm_time);
            }
            else
            {
                out<<QString("%1,").arg(almnote_list[i].alm_no)<<QString("%1,").arg(almnote_list[i].alm_type)<<QString("%1,").arg(almnote_list[i].alm_cont)<<QString("%1,\n").arg(almnote_list[i].alm_time);
            }
        }

        //其他数据可按照这种方式进行添加即可

        //5.写完数据需要关闭文件
    }
    else
    {
        qDebug()<<"文件打开失败";
    }
    file.close();
    read_file();
    update_info();
    max_page = cur_line/row_num+1;
    return 1;
}

void set_alm_note::save_func_slot()
{
    static bool save_flg = 1;//保存标志位 0：不可保存 1：可保存
    if(save_flg==1)
    {
        if(motion_err->size+cur_line>=max_error_note)
        {
            //qDebug()<<"满队列处理"<<max_error_note-(motion_err->size-(max_error_note-cur_line));
            //cur_line = ((motion_err->size+cur_line)-max_error_note);
            update_notelist();
            cur_line = max_error_note-motion_err->size;
            //del_almnote_slot();
            //qDebug()<<"cur_line="<<cur_line;

        }
        for (int i=0;i<motion_err->size;i++)
        {

            almnote_list[i+cur_line].alm_no = motion_err->data[i].id;
            if((motion_err->data[i].id>=ERROR_NO_ERROR)&&(motion_err->data[i].id<ERROR_TASK))
            {
                almnote_list[i+cur_line].alm_type = 0;
            }
            else if((motion_err->data[i].id>=ERROR_TASK)&&(motion_err->data[i].id<ERROR_DECODE))
            {
                almnote_list[i+cur_line].alm_type = 1;
            }
            else if((motion_err->data[i].id>=ERROR_DECODE)&&(motion_err->data[i].id<ERROR_MOTION))
            {
                almnote_list[i+cur_line].alm_type = 2;
            }
            else if((motion_err->data[i].id>=ERROR_MOTION)&&(motion_err->data[i].id<ERROR_PLC))
            {
                almnote_list[i+cur_line].alm_type = 3;
            }
            else if((motion_err->data[i+first_line].id>=ERROR_PLC)&&(motion_err->data[i+first_line].id<ERROR_BUS))
            {
                almnote_list[i+cur_line].alm_type = 4;
            }
            else if((motion_err->data[i+first_line].id>=ERROR_BUS)&&(motion_err->data[i+first_line].id<ERROR_GUI))
            {
                almnote_list[i+cur_line].alm_type = 5;
            }
            else if((motion_err->data[i+first_line].id>=ERROR_GUI)&&(motion_err->data[i+first_line].id<ERROR_SERVO))
            {
                almnote_list[i+cur_line].alm_type = 6;
            }
            else if((motion_err->data[i+first_line].id>=ERROR_SERVO))
            {
                almnote_list[i+cur_line].alm_type = 7;
            }
            almnote_list[i+cur_line].alm_cont = Warn_File_List[motion_err->data[i].id];
            almnote_list[i+cur_line].alm_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            //cur_line++;
        }
        cur_line = cur_line+motion_err->size;
        if(cur_line>=max_error_note)
        {
            cur_line = max_error_note-1;
        }
        save_file();
        save_flg = 0;
    }
}

 void set_alm_note::del_almnote_slot()
 {
     int i;
     for (i=0;i<max_error_note;i++)
     {
         almnote_list[i].alm_no = 0;
         almnote_list[i].alm_type = 0;
         almnote_list[i].alm_cont = "";
         almnote_list[i].alm_time = "";
     }
     cur_line = 0;
     save_file();
 }

void set_alm_note::update_notelist()//队列满之后
{
    int i,temp_val;
    temp_val = motion_err->size-(max_error_note-cur_line);
    //qDebug()<<"motion_err->size="<<motion_err->size<<"需要上移:"<<motion_err->size-(max_error_note-cur_line);
    for (i=0;i<(max_error_note-temp_val);i++)
    {
//        almnote_list[i].alm_no = almnote_list[motion_err->size+i].alm_no;
//        almnote_list[i].alm_type = almnote_list[motion_err->size+i].alm_type;
//        almnote_list[i].alm_cont = almnote_list[motion_err->size+i].alm_cont;
//        almnote_list[i].alm_time = almnote_list[motion_err->size+i].alm_time;
        almnote_list[i].alm_no = almnote_list[motion_err->size-(max_error_note-cur_line)+i].alm_no;
        almnote_list[i].alm_type = almnote_list[motion_err->size-(max_error_note-cur_line)+i].alm_type;
        almnote_list[i].alm_cont = almnote_list[motion_err->size-(max_error_note-cur_line)+i].alm_cont;
        almnote_list[i].alm_time = almnote_list[motion_err->size-(max_error_note-cur_line)+i].alm_time;
        //qDebug()<<"alm_no["<<i<<"]"<<almnote_list[i].alm_no;
        //qDebug()<<"i="<<i<<"i^="<<motion_err->size-(max_error_note-cur_line)+i;
    }
}

void set_alm_note::pageup_slot()
{
    first_line = first_line-row_num;
    if(first_line<0)
    {
        first_line = 0;
    }
    cur_page--;
    if(cur_page<0)
    {
        cur_page = 0;
    }
    update_info();
}

void set_alm_note::pagedown_slot()
{
    if(cur_page>=(cur_line/row_num))
    {
        return;
    }
    first_line = first_line+row_num;

    if(first_line<0)
    {
        first_line = 0;
    }

    cur_page++;
    if(cur_page>max_page)
    {
        cur_page = max_page-1;
    }
    update_info();
}

void set_alm_note::edit_update()
{
    //table->setItem(i,0,new QTableWidgetItem(tr("%1").arg(almnote_list[cur_line-(i+first_line)-1].alm_no)));
    edit_note->setText(WarnNote_File_List[almnote_list[cur_line-(cur_row+first_line)-1].alm_no].replace("\\n","\n"));//替换换行符，让其正常换行
    //qDebug()<<"WarnNote_File_List"<<WarnNote_File_List[motion_err->data[first_line+cur_row].id]<<motion_err->data[first_line+cur_row].id;
}

void set_alm_note::get_item_info_slot(int row,int col)//获取单元格信息
{
    qDebug()<<"row"<<row<<"col"<<col;
    cur_row = row;
    cur_col = col;
    edit_update();
    table->selectRow(cur_row);
    qDebug()<<"cur_row"<<cur_row<<"cur_col"<<cur_col;
}

void set_alm_note::Timer_on_slot()
{
    static int last_almnum = 0;
    if(last_almnum != motion_err->size)
    {
        last_almnum = motion_err->size;
        save_flg = 1;
        save_func_slot();
        update_info();
    }
}

void set_alm_note::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPen pen;
    pen.setColor(QColor(216,216,216));
    pen.setWidth(2); //设置线宽
    painter.begin(this);
    painter.setPen(pen);
    painter.drawLine(table->pos().rx(),table->pos().ry(),table->pos().rx(),390);
    painter.end();
}
