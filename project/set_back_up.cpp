#include "set_back_up.h"
#include "ui_set_back_up.h"

#if debug_on ==0
QString zip_path = "/home/root";
QString res_path = "/run/media/sda1";
#elif debug_on==1
QString zip_path = "E:/QT/program/BLUE";
QString res_path = "F:";
#endif

set_back_up::set_back_up(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_back_up)
{
    ui->setupUi(this);
    this->setGeometry(0,0,691,614);
    ui->frame->setGeometry(0,0,691,614);
    Init();
}

set_back_up::~set_back_up()
{
    delete ui;
}

void set_back_up::Init()
{
    label_set();
    edit_set();
    button_set();
}

void set_back_up::label_set()
{

}

void set_back_up::edit_set()
{

}

void set_back_up::button_set()
{
    int i;
    for (i=0;i<2;i++)
    {
        bt[i] = new QPushButton(ui->frame);
        bt[i]->setFont(weiruanyahei4);
        bt[i]->setGeometry(620,40+i*40,50,30);

    }

    bt[0]->setText("备份");
    bt[1]->setText("恢复");
}

void set_back_up::Deal_slot()
{
    connect(bt[0],SIGNAL(clicked()),this,SLOT(back_up_slot()));
    connect(bt[1],SIGNAL(clicked()),this,SLOT(restore_slot()));
}

void set_back_up::Timer_on_slot()
{

}

void set_back_up::back_up_slot()//备份
{
    QDir dir(zip_path);
    QFileInfoList file_list=dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    zipWriter(res_path+"/back_up.zip",file_list);
}

void set_back_up::restore_slot()//恢复
{

}

bool set_back_up::zipReader(QString zipPath, QString zipDir)//zip包解压缩
{
    QDir tempDir;
    if(!tempDir.exists(zipDir))
    {
        tempDir.mkpath(zipDir);
    }
    QZipReader reader(zipPath);
    return reader.extractAll(zipDir);
}

void set_back_up::zipWriter(QString zipPath, QFileInfoList fileList)//压缩zip包
{
    QZipWriter *writer = new QZipWriter(zipPath);

    // 遍历文件列表
    foreach (QFileInfo fileInfo, fileList)
    {
        //添加需要压缩的文件
        QFile file(fileInfo.filePath());
        if (!file.exists()) continue;
        file.open(QIODevice::ReadOnly);
        writer->addFile(fileInfo.fileName(), file.readAll());
        file.close();
    }
    writer->close();
    if(writer)
    {
        delete writer;
        writer = nullptr;
    }
}
