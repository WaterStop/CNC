#include "set_widget.h"
#include "ui_set_widget.h"

static int cur_page = 0;//功能菜单当前页数
static int menu_lv = 0;//功能菜单等级

set_widget::set_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_widget)
{
    ui->setupUi(this);
    Init();
    set_background();
    SetNavigationBar();
    //set_PLC_Lad();

    DealSlot();

    ui->listView->setGeometry(5,12,182,615);
}

set_widget::~set_widget()
{
    delete ui;
}

void set_widget::set_background()
{

}

void set_widget::Init()
{
    int i;
    //button_set();
    treewidget_info();


    set_plc = new Set_Plc_plc(ui->frame);
    set_plc->setGeometry(190,10,691,614);
    set_plc->hide();
    dgn = new set_dgn(ui->frame);
    dgn->setGeometry(190,10,691,614);
    dgn->hide();
    alarm_info = new set_alarm_info(ui->frame);
    alarm_info->setGeometry(190,10,691,614);
    alarm_info->hide();
    alarm_note = new set_alm_note(ui->frame);
    alarm_note->setGeometry(190,10,691,614);
    alarm_note->hide();
    data_para = new set_data_para(ui->frame);
    data_para->setGeometry(190,10,691,614);
    data_para->show();
    lim_and_time = new set_limit_and_time(ui->frame);
    lim_and_time->setGeometry(190,10,691,614);
    lim_and_time->hide();
    over_set = new set_over_limit_set(ui->frame);
    over_set->setGeometry(190,10,691,614);
    over_set->hide();
    net_set = new set_internet_set(ui->frame);
    net_set->setGeometry(190,10,691,614);
    net_set->hide();
    back = new set_back_up(ui->frame);
    back->setGeometry(190,10,691,614);
    back->hide();


    for (i=0;i<4;i++)
    {
        temp_but[i] = new QPushButton(ui->frame);
        temp_but[i]->setFont(weiruanyahei4);
        temp_but[i]->setGeometry(20,400+i*50,60,30);
    }
    for (i=0;i<1;i++)
    {
        temp_but2[i] = new QPushButton(ui->frame);
        temp_but2[i]->setFont(weiruanyahei4);
        temp_but2[i]->setGeometry(100,400+i*50,60,30);
    }
    temp_but[0]->setText("加工");
    temp_but[1]->setText("调试");
    temp_but[2]->setText("报警");
    temp_but[3]->setText("参数");
    temp_but2[0]->setText("报警记录");
    temp_but[1]->hide();
    temp_but[2]->hide();
    temp_but[3]->hide();
    temp_but2[0]->hide();
    temp_but[0]->setGeometry(20,600,60,30);
    //temp_but2[0]->hide();
}

void set_widget::resizeEvent(QResizeEvent *event)//背景随控件大小变化
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    image.load(":/new/blue_pic/set_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void set_widget::DealSlot()
{
//    connect(bt_fun_right[0],SIGNAL(pressed()),this,SLOT(RIGHT_FUN0_slot()));
//    connect(bt_fun_right[1],SIGNAL(pressed()),this,SLOT(RIGHT_FUN1_slot()));
//    connect(bt_fun_right[2],SIGNAL(pressed()),this,SLOT(RIGHT_FUN2_slot()));
//    connect(bt_fun_right[3],SIGNAL(pressed()),this,SLOT(RIGHT_FUN3_slot()));
//    connect(bt_fun_right[4],SIGNAL(pressed()),this,SLOT(RIGHT_FUN4_slot()));
//    connect(bt_fun_right[5],SIGNAL(pressed()),this,SLOT(RIGHT_FUN5_slot()));
//    connect(bt_fun_right[6],SIGNAL(pressed()),this,SLOT(RIGHT_FUN6_slot()));
//    connect(bt_fun_right[7],SIGNAL(pressed()),this,SLOT(RIGHT_FUN7_slot()));
    connect(temp_but[0],SIGNAL(clicked()),this,SLOT(goto_work_scr_slot()));
    connect(temp_but[1],SIGNAL(clicked()),this,SLOT(goto_dgn_slot()));
    connect(temp_but[2],SIGNAL(clicked()),this,SLOT(goto_alm_info_slot()));
    connect(temp_but[3],SIGNAL(clicked()),this,SLOT(goto_data_para_slot()));
    connect(dgn,SIGNAL(back_signal()),this,SLOT(back_slot()));
    connect(temp_but2[0],SIGNAL(clicked()),this,SLOT(goto_alm_note_slot()));
    connect(tree_list,SIGNAL(pressed(int, int)),this,SLOT(screen_jump_slot(int, int)));
}

void set_widget::treewidget_info()
{
    int i;
    tree = new QTreeWidget(ui->frame);
    tree->hide();
    tree->setGeometry(5,12,182,615);
    tree->setStyleSheet("background-color:transparent;");
    //tree->setStyleSheet("QTreeWidget::item{ color:white;height:40px;}background-color:transparent;");
    //设置列标题
    tree->setHeaderLabel("设置");
    //如果不想显示标题，可以隐藏
    tree->setHeaderHidden(true);
    //设置不同层次菜单的缩进
    tree->setIndentation(5);


    QTreeWidgetItem *item1 = new QTreeWidgetItem(tree,QStringList("系统状态"));
    QTreeWidgetItem *item2 = new QTreeWidgetItem(tree,QStringList("系统配置"));
    QTreeWidgetItem *item3 = new QTreeWidgetItem(tree,QStringList("补偿设置"));
    QTreeWidgetItem *item4 = new QTreeWidgetItem(tree,QStringList("PLC设置"));
    QTreeWidgetItem *item5 = new QTreeWidgetItem(tree,QStringList("权限设置"));

    QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1,QStringList("报警信息"));
    QTreeWidgetItem *item1_2 = new QTreeWidgetItem(item1,QStringList("报警记录"));
    QTreeWidgetItem *item1_3 = new QTreeWidgetItem(item1,QStringList("诊断"));
    QTreeWidgetItem *item1_4 = new QTreeWidgetItem(item1,QStringList("操作记录"));
    QTreeWidgetItem *item1_5 = new QTreeWidgetItem(item1,QStringList("加工记录"));

    item1->setIcon(0,QIcon(":/new/blue_pic/list_head_bk.png"));
    tree->setIconSize(QSize(128, 30));
    item1->setFont(0,weiruanyahei6);
    item2->setFont(0,weiruanyahei6);
    item3->setFont(0,weiruanyahei6);
    item4->setFont(0,weiruanyahei6);
    item5->setFont(0,weiruanyahei6);
    item1->setForeground(0,Qt::white);
    item2->setForeground(0,Qt::white);
    item3->setForeground(0,Qt::white);
    item4->setForeground(0,Qt::white);
    item5->setForeground(0,Qt::white);
    item1_1->setFont(0,weiruanyahei6);
    item1_2->setFont(0,weiruanyahei6);
    item1_3->setFont(0,weiruanyahei6);
    item1_4->setFont(0,weiruanyahei6);
    item1_5->setFont(0,weiruanyahei6);
    item1_1->setForeground(0,Qt::white);
    item1_2->setForeground(0,Qt::white);
    item1_3->setForeground(0,Qt::white);
    item1_4->setForeground(0,Qt::white);
    item1_5->setForeground(0,Qt::white);

    tree_list = new NavListView(ui->frame);
    tree_list->setGeometry(5,12,182,615);
    tree_list->setStyleSheet("background-color:transparent;");
    tree_list->setSeparateHeight(1);
    tree_list->setTriangleVisible(0);
    tree_list->setRightIconVisible(0);
    tree_list->setSeparateColor(QColor(40, 43, 51));

    tree_list->setChildBgNormalColor(QColor(40, 43, 51));
    tree_list->setChildBgSelectedColor(QColor(20, 20, 20));
    tree_list->setChildBgHoverColor(QColor(20, 20, 20));
    tree_list->setChildTextNormalColor(QColor(180, 180, 180));
    tree_list->setChildTextSelectedColor(QColor(250, 250, 250));
    tree_list->setChildTextHoverColor(QColor(255, 255, 255));

    tree_list->setParentBgNormalColor(QColor(57, 61, 73));
    tree_list->setParentBgSelectedColor(QColor(78, 83, 102));
    tree_list->setParentBgHoverColor(QColor(78, 83, 102));
    tree_list->setParentTextNormalColor(QColor(250, 250, 250));
    tree_list->setParentTextSelectedColor(QColor(250, 250, 250));
    tree_list->setParentTextHoverColor(QColor(250, 250, 250));

    tree_list->setExpendMode(NavListView::ExpendMode_SingleClick);
    QStringList items;
    items.append("系统状态||0||");
    items.append("报警信息|系统状态|||0xf03e");
    items.append("报警记录|系统状态|||0xf03d");
    items.append("诊断|系统状态|||0xf108");
    //items.append("调试|系统状态|||0xf108");

    items.append("系统配置||1||");
    items.append("常用参数|系统配置|||0xf0e8");
    items.append("参数配置|系统配置|||0xf060");
    items.append("IP地址|系统配置|||0xf03e");

    items.append("补偿设置||1||");
    items.append("刀具补偿|补偿设置|||0xf073");
    items.append("螺距补偿|补偿设置|||0xf03e");
    items.append("坐标设置|补偿设置|||0xf03d");
//    items.append("数据回放|补偿设置|||0xf080");

    items.append("设置||1||");
    items.append("权限和时间|设置|||0xf073");
    items.append("过期保护|设置|||0xf03e");
    items.append("文件管理|设置|||0xf03d");
    items.append("备份与恢复|设置|||0xf03d");

    tree_list->setItems(items.join(","));
    tree_list->setCurrentRow(1);
    //on_navListView_pressed(tree_list->currentIndex());



}

void set_widget::button_set()
{
    int i;
//    for (i=0;i<8;i++)
//    {
//        bt_fun[i] = new QPushButton(this);
//        bt_fun[i]->setGeometry(220+i*70,475,40,40);
//        bt_fun_right[i] = new QPushButton(this);
//        bt_fun_right[i]->setGeometry(820,20+i*55,40,40);
//    }

//    menuRight_info_show_plcpic(0);

}

void set_widget::SetNavigationBar()
{
    CNavModel* pNavModel = new CNavModel(this);
    CNavDelegate* pDelegate = new CNavDelegate(this);
    pNavModel->ReadConfig(QCoreApplication::applicationDirPath() += "/config/navigation.xml");
    ui->listView->setModel(pNavModel);
    ui->listView->setItemDelegate(pDelegate);
    connect(ui->listView, SIGNAL(doubleClicked(const QModelIndex &)), pNavModel, SLOT(Collapse(const QModelIndex &)));
    ui->listView->hide();
}

void set_widget::change_screen(int index)
{
    //currect_screen = index;
    dgn->hide();
    alarm_info->hide();
    alarm_note->hide();
    data_para->hide();
    lim_and_time->hide();
    over_set->hide();
    net_set->hide();
    file_manage->hide();
    back->hide();

    switch (index)
    {
    case scr_alminfo:
        alarm_info->show();
        break;
    case scr_almnote:
        alarm_note->show();
        break;
    case scr_datapara:
        data_para->show();
        break;
    case scr_dgn:
        dgn->show();
        break;
    case scr_lim_and_time:
        lim_and_time->show();
        break;
    case scr_over_lim_set:
        over_set->show();
        break;
    case scr_internet_set:
        net_set->show();
        break;
    case scr_file_manage:
        file_manage->show();
        break;
    case scr_back_up:
        back->show();
        break;
    default:
        break;
    }
}

void set_widget::back_slot()
{
    emit back_signal();
}

void set_widget::screen_jump_slot(int index, int parentIndex)
{
    qDebug()<<"screen_jump="<<index<<parentIndex;
    switch (index)
    {
    case alm_info:
        //goto_alm_info_slot();
        change_screen(scr_alminfo);
        break;
    case alm_note:
        change_screen(scr_almnote);
        break;
    case dgn_:
        change_screen(scr_dgn);
        break;
    case para_set:
        change_screen(scr_datapara);
        break;
    case time_lev:
        change_screen(scr_lim_and_time);
        break;
    case over_pro:
        change_screen(scr_over_lim_set);
        break;
    case IP_addr:
        change_screen(scr_internet_set);
        break;
    case file_mag:
        change_screen(scr_file_manage);
        break;
    case back_up:
        change_screen(scr_back_up);
        break;

    default:
        break;
    }
}

void set_widget::show_alminfo_scr()
{
    goto_alm_info_slot();
}

void set_widget::goto_work_scr_slot()
{
    emit back_signal();
}

void set_widget::goto_dgn_slot()
{
    dgn->show();
    alarm_info->hide();
    alarm_note->hide();
    data_para->hide();
}

void set_widget::goto_alm_info_slot()
{
    dgn->hide();
    alarm_info->show();
    alarm_note->hide();
    data_para->hide();
}

void set_widget::goto_alm_note_slot()
{
    dgn->hide();
    alarm_info->hide();
    alarm_note->show();
    data_para->hide();
}

void set_widget::goto_data_para_slot()
{
    dgn->hide();
    alarm_info->hide();
    alarm_note->hide();
    data_para->show();
}

void set_widget::Timer_on_slot()
{
    dgn->Timer_on_slot();
    set_plc->Timer_on_slot();
    alarm_info->Timer_on_slot();
    data_para->Timer_on_slot();
    lim_and_time->Timer_on_slot();
    over_set->Timer_on_slot();
    file_manage->Timer_on_slot();
}

void set_widget::paintEvent(QPaintEvent *)
{
    QPainter painter( this);
    QPen pen;
}
