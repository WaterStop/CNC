#include "plc_fun_cmd.h"
#include "ui_plc_fun_cmd.h"

plc_fun_cmd::plc_fun_cmd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plc_fun_cmd)
{
    ui->setupUi(this);
    ui->TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置表格内容不可编辑
    this->setWindowFlags(Qt::Popup);
    Init_set();
    Deal_solt();
}

plc_fun_cmd::~plc_fun_cmd()
{
    delete ui;
}

void plc_fun_cmd::Init_set()
{
    //QWidget widget;
    //widget.setGeometry(0,0,225,120);
    //QTableWidget TableWidget;
    this->resize(225,157);
    ui->TableWidget->setColumnCount(5);
    //ui->TableWidget->resize(225,120);
    ui->TableWidget->setGeometry(0,0,225,157);
    ui->TableWidget->setColumnCount(5);
    ui->TableWidget->setRowCount(7);
    ui->TableWidget->setFont(weiruanyahei4);
    ui->TableWidget->horizontalHeader()->resizeSection(0,44);
    ui->TableWidget->horizontalHeader()->resizeSection(1,44);
    ui->TableWidget->horizontalHeader()->resizeSection(2,45);
    ui->TableWidget->horizontalHeader()->resizeSection(3,45);
    ui->TableWidget->horizontalHeader()->resizeSection(4,45);
    ui->TableWidget->verticalHeader()->setDefaultSectionSize(20); //设置行高
    ui->TableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见
    ui->TableWidget->horizontalHeader()->setHidden(true);//设置表头不可见

//    QList<QString> itemline0{"CTR", "TMR", "ROT", "COMP", "MOVN"};
//    QList<QString> itemline1{"DSCH", "COIN", "CALL", "SP", "SPE"};
//    QList<QString> itemline2{"END1", "END2", "ADD", "SUB", "XMOV"};
//    QList<QString> itemline3{"DEC", "COD", "DIFU", "DIFD", "EOR"};
//    QList<QString> itemline4{"ANDF", "ORF", "NOT", "JMPB", "LBL"};
//    QList<QString> itemline5{"RST", "SET", "SFT", "COM", "COME"};
//    QList<QString> itemline6{"TMRB", "TMRC", "CALLU", "MOVB", "MOVW"};

    ui->TableWidget->setItem(0,0,new QTableWidgetItem("CTR"));
    ui->TableWidget->setItem(0,1,new QTableWidgetItem("TMR"));
    ui->TableWidget->setItem(0,2,new QTableWidgetItem("ROT"));
    ui->TableWidget->setItem(0,3,new QTableWidgetItem("COMP"));
    ui->TableWidget->setItem(0,4,new QTableWidgetItem("MOVN"));
    ui->TableWidget->setItem(1,0,new QTableWidgetItem("DSCH"));
    ui->TableWidget->setItem(1,1,new QTableWidgetItem("COIN"));
    ui->TableWidget->setItem(1,2,new QTableWidgetItem("CALL"));
    ui->TableWidget->setItem(1,3,new QTableWidgetItem("SP"));
    ui->TableWidget->setItem(1,4,new QTableWidgetItem("SPE"));
    ui->TableWidget->setItem(2,0,new QTableWidgetItem("END1"));
    ui->TableWidget->setItem(2,1,new QTableWidgetItem("END2"));
    ui->TableWidget->setItem(2,2,new QTableWidgetItem("ADD"));
    ui->TableWidget->setItem(2,3,new QTableWidgetItem("SUB"));
    ui->TableWidget->setItem(2,4,new QTableWidgetItem("XMOV"));
    ui->TableWidget->setItem(3,0,new QTableWidgetItem("DEC"));
    ui->TableWidget->setItem(3,1,new QTableWidgetItem("COD"));
    ui->TableWidget->setItem(3,2,new QTableWidgetItem("DIFU"));
    ui->TableWidget->setItem(3,3,new QTableWidgetItem("DIFD"));
    ui->TableWidget->setItem(3,4,new QTableWidgetItem("EOR"));
    ui->TableWidget->setItem(4,0,new QTableWidgetItem("ANDF"));
    ui->TableWidget->setItem(4,1,new QTableWidgetItem("ORF"));
    ui->TableWidget->setItem(4,2,new QTableWidgetItem("NOT"));
    ui->TableWidget->setItem(4,3,new QTableWidgetItem("JMPB"));
    ui->TableWidget->setItem(4,4,new QTableWidgetItem("LBL"));
    ui->TableWidget->setItem(5,0,new QTableWidgetItem("RST"));
    ui->TableWidget->setItem(5,1,new QTableWidgetItem("SET"));
    ui->TableWidget->setItem(5,2,new QTableWidgetItem("SFT"));
    ui->TableWidget->setItem(5,3,new QTableWidgetItem("COM"));
    ui->TableWidget->setItem(5,4,new QTableWidgetItem("COME"));
    ui->TableWidget->setItem(6,0,new QTableWidgetItem("TMRB"));
    ui->TableWidget->setItem(6,1,new QTableWidgetItem("TMRC"));
    ui->TableWidget->setItem(6,2,new QTableWidgetItem("CALLU"));
    ui->TableWidget->setItem(6,3,new QTableWidgetItem("MOVB"));
    ui->TableWidget->setItem(6,4,new QTableWidgetItem("MOVW"));

}

void plc_fun_cmd::Deal_solt()
{
    connect(ui->TableWidget,SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(itemClicked_slot(QTableWidgetItem*)));
    connect(ui->TableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(show_iteminfo_slot(int,int)));
}

void plc_fun_cmd::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        //sendMsg();
        this->close();
    }
}

void plc_fun_cmd::itemClicked_slot(QTableWidgetItem* item)
{
    if(item->text()=="CTR")
    {
        qDebug()<<"CTR";
    }
    else if(item->text()=="TMR")
    {

    }
}

void plc_fun_cmd::show_iteminfo_slot(int row,int col)
{

}
