#include "set_alarm_info.h"
#include "ui_set_alarm_info.h"

static int max_error = 10;
static int first_line = 0;//首行行号
static int cur_row = 0;//当前行
static int cur_col = 0;//当前列
static int cur_page = 0;//当前页数
static int max_page = 0;//最大页数

set_alarm_info::set_alarm_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_alarm_info)
{
    ui->setupUi(this);
    Init();
    max_page = MAX_ERROR_NUM/row_num+1;

}

set_alarm_info::~set_alarm_info()
{
    delete ui;
}

void set_alarm_info::resizeEvent(QResizeEvent *event)
{

}

void set_alarm_info::Init()
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

    button_set();
    Deal_slot();
}

void set_alarm_info::table_init()
{
    int i,j;
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
//    table->setStyleSheet("QTableWidget{ background-color:rgb(3,14,54);color:rgb(255,255,255);gridline-color:rgb(216, 216,216);}"
//                         "QTableWidget::item{border-left:2px solid #D8D8D8;selection-background-color:rgb(255,209,128);}");
    table->setStyleSheet("selection-color:black;selection-background-color:lightblue;"
                         "background-color:rgb(3,14,54);color:rgb(255,255,255);gridline-color:rgb(216, 216,216);"
                         "QTableWidget::item{border-left:4px solid #D8D8D8;}");
    table->horizontalHeader()->setStyleSheet("QHeaderView::section{"
                "border-top:0px solid #D8D8D8;border-left:0px solid #D8D8D8;"
                "border-right:2px solid #D8D8D8;border-bottom: 0.5px solid #D8D8D8;"
                "background-color:rgb(21,96,192);color:rgb(255,255,255);padding:4px;height:30px;}" );//设置表头样式
    table->horizontalHeader()->setMinimumHeight(head_height);
    //table->horizontalHeader()->setDefaultSectionSize(200);
    //table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->horizontalHeader()->setHighlightSections(false);//点击表时不对表头行光亮（获取焦点）
    table->setGeometry(60,60,561,340);
    table->setColumnCount(3);
    table->setColumnWidth(0, 80);
    table->setColumnWidth(1, 147);
    table->setColumnWidth(2, 330);
    table->setRowCount(row_num);//设置行数
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    table->setFocusPolicy(Qt::NoFocus);
    table->setHorizontalHeaderLabels(QStringList() <<"报警号"<<"报警类型"<<"报警内容");
    table->setFrameShape(QFrame::NoFrame);
    //table->setSelectionMode(QAbstractItemView::NoSelection);//取消高亮
    for (i=0;i<row_num;i++)
    {
        table->setRowHeight(i,row_height);
    }
}

void set_alarm_info::button_set()
{
    int i;
    for (i=0;i<8;i++)
    {
        bt_fun_right[i] = new QPushButton(this);
        bt_fun_right[i]->setGeometry(640,20+i*55,40,40);
        bt_fun_right[i]->setFont(weiruanyahei4);
        bt_fun_right[i]->setStyleSheet("border-image:url(:/new/blue_pic/bt_func_bk.png);color: rgb(255, 255, 255);");
    }
    for (i=0;i<6;i++)
    {
        bt_fun_right[i]->hide();
    }
    bt_fun_right[6]->setText("上一页");
    bt_fun_right[7]->setText("下一页");
}

void set_alarm_info::Deal_slot()
{
    connect(bt_fun_right[6],SIGNAL(clicked()),this,SLOT(pageup_slot()));
    connect(bt_fun_right[7],SIGNAL(clicked()),this,SLOT(pagedown_slot()));
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(get_item_info_slot(int,int)));
}

void set_alarm_info::pageup_slot()
{
    first_line = first_line-10;
    if(first_line<0)
    {
        first_line = 0;
    }
    cur_page--;
    if(cur_page<0)
    {
        cur_page = 0;
    }
    cur_row = 0;
    update_info();
}

void set_alarm_info::pagedown_slot()
{
    if(cur_page>=(motion_err->size/row_num))
    {
        return;
    }
    first_line = first_line+10;
//    if(first_line>=MAX_ERROR_NUM-row_num)
//    {
//         = MAX_ERROR_NUM-row_num;
//    }
    if(first_line<0)
    {
        first_line = 0;
    }

    cur_page++;
    if(cur_page>max_page)
    {
        cur_page = max_page-1;
    }
    cur_row = 0;
    update_info();
    qDebug()<<"first_line"<<first_line;
}

void set_alarm_info::update_info()
{
    int i;
    QStringList header;
    header<<"报警号"<<"报警类型"<<"报警内容";
    {

        //table->setRowCount(max_error);//设置行数
        table->clearContents();//清除表格数据
        table->setHorizontalHeaderLabels(header);
        for(i = 0;i <row_num;i++)
        {
            if(i+first_line<motion_err->size)
            {
                if(Warn_File_List[motion_err->data[i+first_line].id].isEmpty()==0)
                {
                    table->setItem(i,0,new QTableWidgetItem(tr("%1").arg(motion_err->data[i+first_line].id)));
                    table->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    if((motion_err->data[i+first_line].id>=ERROR_NO_ERROR)&&(motion_err->data[i+first_line].id<ERROR_TASK))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("系统报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_TASK)&&(motion_err->data[i+first_line].id<ERROR_DECODE))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("任务报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_DECODE)&&(motion_err->data[i+first_line].id<ERROR_MOTION))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("解释器报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_MOTION)&&(motion_err->data[i+first_line].id<ERROR_PLC))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("运动报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_PLC)&&(motion_err->data[i+first_line].id<ERROR_BUS))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("PLC报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_BUS)&&(motion_err->data[i+first_line].id<ERROR_GUI))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("总线报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_GUI)&&(motion_err->data[i+first_line].id<ERROR_SERVO))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("GUI报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_SERVO))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("伺服报警")));
                    }
                    //table->setItem(i,1,new QTableWidgetItem(tr("驱动器报警 %1").arg(i+first_line + 1)));
                    table->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(i,2,new QTableWidgetItem(tr("%1").arg(Warn_File_List[motion_err->data[i+first_line].id])));
                    table->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                }
                else
                {
                    table->setItem(i,0,new QTableWidgetItem(tr("%1").arg(motion_err->data[i+first_line].id)));
                    table->item(i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    if((motion_err->data[i+first_line].id>=ERROR_NO_ERROR)&&(motion_err->data[i+first_line].id<ERROR_TASK))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("系统报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_TASK)&&(motion_err->data[i+first_line].id<ERROR_DECODE))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("任务报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_DECODE)&&(motion_err->data[i+first_line].id<ERROR_MOTION))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("解释器报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_MOTION)&&(motion_err->data[i+first_line].id<ERROR_PLC))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("运动报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_PLC)&&(motion_err->data[i+first_line].id<ERROR_BUS))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("PLC报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_BUS)&&(motion_err->data[i+first_line].id<ERROR_GUI))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("总线报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_GUI)&&(motion_err->data[i+first_line].id<ERROR_SERVO))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("GUI报警")));
                    }
                    else if((motion_err->data[i+first_line].id>=ERROR_SERVO))
                    {
                        table->setItem(i,1,new QTableWidgetItem(tr("伺服报警")));
                    }
                    table->item(i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(i,2,new QTableWidgetItem(tr("%1").arg(motion_err->data[i+first_line].id)));
                    table->item(i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

                }
                edit_update();
            }
        }
    }
}

void set_alarm_info::edit_update()
{
    if(cur_row+first_line<motion_err->size)
    {
        edit_note->setText(WarnNote_File_List[motion_err->data[first_line+cur_row].id].replace("\\n","\n"));//替换换行符，让其正常换行
    }
    else
    {
        edit_note->setText("");
    }

    //qDebug()<<"cur_row"<<cur_row<<"first_line+cur_row"<<first_line+cur_row<<"WarnNote_File_List"<<WarnNote_File_List[motion_err->data[first_line+cur_row].id]<<motion_err->data[first_line+cur_row].id;
}

void set_alarm_info::get_item_info_slot(int row,int col)//获取单元格信息
{
    qDebug()<<"row"<<row<<"col"<<col;
    cur_row = row;
    cur_col = col;
    edit_update();
    table->selectRow(cur_row);
    //qDebug()<<"cur_row"<<cur_row<<"cur_col"<<cur_col;
}

void set_alarm_info::Timer_on_slot()
{
    static int last_almnum = 0;
    if(last_almnum != motion_err->size)
    {
        last_almnum = motion_err->size;
        update_info();
    }
}

void set_alarm_info::paintEvent(QPaintEvent *)
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
