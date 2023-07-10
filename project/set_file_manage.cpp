#include "set_file_manage.h"
#include "ui_set_file_manage.h"

#if debug_on ==0
QString loc_path = "/home/root";
QString usb_path = "/run/media/sda1";
#elif debug_on==1
QString loc_path = "E:/QT/program/BLUE";
QString usb_path = "F:";
#endif
static QString oper_loc_path;
static QString oper_usb_path;
static bool oper_flg = 0;//操作方向，0：本地->U盘 1：U盘->本地
static QString cur_file_name;

set_file_manage::set_file_manage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_file_manage)
{
    ui->setupUi(this);
    this->setGeometry(0,0,691,614);
    ui->frame->setGeometry(0,0,691,614);
    Init();
}

set_file_manage::~set_file_manage()
{
    delete ui;
}

void set_file_manage::Init()
{
    label_set();
    edit_set();
    button_set();
    load_loc_file();
    load_usb_file();
    Deal_slot();
}

void set_file_manage::label_set()
{

}

void set_file_manage::edit_set()
{

}

void set_file_manage::button_set()
{
    int i;
    for (i=0;i<2;i++)
    {
        bt[i] = new QPushButton(ui->frame);
        bt[i]->setFont(weiruanyahei4);
        bt[i]->setGeometry(620,40+i*40,50,30);

    }
    bt[0]->setText("复制");
    bt[1]->setText("删除");

}

void set_file_manage::load_loc_file()
{
    QString rootpath=loc_path;
    tree = new QTreeWidget(ui->frame);
    tree->setGeometry(10,10,300,600);
    tree->setStyleSheet("background:transparent;color:white;");
    tree->setSelectionMode(QAbstractItemView::SingleSelection);
    tree->setSelectionBehavior(QAbstractItemView::SelectRows);
    tree->setIconSize (QSize (30, 30));
    tree->setFont(weiruanyahei6);
    tree->setHeaderHidden(true);
    //tree->setVerticalScrollBar();

//    //QString rootpath=LocalPath;
//    QTreeWidgetItem* root = new QTreeWidgetItem(tree);
//    //root->setIcon(0, QIcon("../GJ306/pic/folder.png"));
//    //root->setCheckState(0, Qt::Checked);
//    root->setText(0,"本地");
//    QFileInfoList lists= LoadAllFile(root,rootpath);        //遍历文件夹
    load_loc_item();
}

void set_file_manage::load_usb_file()
{
    QString rootpath=usb_path;
    tree2 = new QTreeWidget(ui->frame);
    tree2->setGeometry(310,10,300,600);
    tree2->setStyleSheet("background:transparent;color:white;");
    tree2->setSelectionMode(QAbstractItemView::SingleSelection);
    tree2->setSelectionBehavior(QAbstractItemView::SelectRows);
    tree2->setIconSize (QSize (30, 30));
    tree2->setFont(weiruanyahei6);
    tree2->setHeaderHidden(true);
    //tree->setVerticalScrollBar();

//    //QString rootpath=LocalPath;
//    QTreeWidgetItem* root = new QTreeWidgetItem(tree2);
//    //root->setIcon(0, QIcon("../GJ306/pic/folder.png"));
//    //root->setCheckState(0, Qt::Checked);
//    root->setText(0,"U盘");
//    QFileInfoList lists= LoadAllFile(root,rootpath);        //遍历文件夹
    load_usb_item();
}


void set_file_manage::load_loc_item()
{
    QTreeWidgetItem* root = new QTreeWidgetItem(tree);
    //root->setIcon(0, QIcon("../GJ306/pic/folder.png"));
    //root->setCheckState(0, Qt::Checked);//复选框
    root->setText(0,"本地");
    tree->expandItem(root);
    QFileInfoList lists= LoadAllFile(root,loc_path);        //遍历文件夹
}

void set_file_manage::load_usb_item()
{
    QTreeWidgetItem* root = new QTreeWidgetItem(tree2);
    //root->setIcon(0, QIcon("../GJ306/pic/folder.png"));
    //root->setCheckState(0, Qt::Checked);//复选框
    root->setText(0,"U盘");
    tree2->expandItem(root);
    QFileInfoList lists= LoadAllFile(root,usb_path);        //遍历文件夹
}

QFileInfoList set_file_manage::LoadAllFile(QTreeWidgetItem *root,QString path)
{
#if debug_on ==0
    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(utf8);
    QTextCodec* gbk = QTextCodec::codecForName("gbk");
#endif
    QDir dir(path);          //遍历各级子目录 "D:/first"
    QDir dir_file(path);    //遍历子目录中所有文件
    //先遍历文件夹 添加进widget
    QFileInfoList file_list=dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);   //获取当前所有目录 QDir::Dirs 0x001 列出目录；


    for(int i = 0; i != folder_list.size(); i++)         //自动递归添加各目录到上一级目录
    {
         QString namepath = folder_list.at(i).absoluteFilePath();    //获取路径
         QFileInfo folderinfo= folder_list.at(i);
         #if debug_on ==0
         QString name=gbk->toUnicode(folderinfo.fileName());      //获取目录名
         #elif debug_on==1
         QString name=folderinfo.fileName();      //获取目录名
         #endif
         if(path==loc_path)
         {
             if((limit_lev>1)&&(name!="nc"))
             {
                 continue;
             }
         }
         QTreeWidgetItem* childroot = new QTreeWidgetItem(QStringList()<<name);
         root->addChild(childroot);
         childroot->setIcon(0, QIcon(":/new/blue_pic/folder.png"));  //这里只是用了D盘下一张图片 可以随意更改 注意斜杠
         //childroot->setCheckState(1, Qt::Checked);
         childroot->setText(0,name);
         root->addChild(childroot);              //将当前目录添加成path的子项
         QFileInfoList child_file_list = LoadAllFile(childroot,namepath);          //进行递归 递归这个文件夹
         file_list.append(child_file_list);
         file_list.append(name);

     }
    /*添加path路径文件*/

    dir_file.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);        //获取当前所有文件
    dir_file.setSorting(QDir::Name);//
    QFileInfoList list_file = dir_file.entryInfoList();
    for (int i = 0; i < list_file.size(); ++i)  //将当前目录中所有文件添加到treewidget中
    {
        QFileInfo fileInfo = list_file.at(i);
        if((fileInfo.fileName().endsWith(".png")==0)&&(fileInfo.fileName().endsWith(".h")==0)&&((fileInfo.fileName().endsWith(".cpp")==0)&&(fileInfo.fileName().endsWith(".ui")==0)&&\
          (fileInfo.fileName().endsWith(".c")==0)&&(fileInfo.fileName().endsWith(".qrc")==0)&&(fileInfo.fileName().endsWith(".user")==0)&&(fileInfo.fileName().endsWith(".pro")==0)))
        {

            #if debug_on ==0
            QString name2=gbk->toUnicode(fileInfo.fileName());      //获取目录名
            #elif debug_on==1
            QString name2=fileInfo.fileName();      //获取目录名
            #endif
            QTreeWidgetItem* child = new QTreeWidgetItem(QStringList()<<name2);
            child->setIcon(0, QIcon(":/new/blue_pic/file.png"));	//这里只是用了D盘下一张图片 可以随意更改
            //child->setCheckState(1, Qt::Checked);
            child->setText(0,name2);
            root->addChild(child);  //allfile传入的root下面加入

        }

    }
    return file_list;

}

void set_file_manage::update_info()
{
    tree->clear();
    tree2->clear();
    load_loc_item();
    load_usb_item();
}

void set_file_manage::Deal_slot()
{
    connect(tree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(deal_item_slot(QTreeWidgetItem*)));
    connect(tree2,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(deal_item_slot2(QTreeWidgetItem*)));
    connect(tree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(get_loc_path_slot(QTreeWidgetItem*,int)));
    connect(tree2,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(get_usb_path_slot(QTreeWidgetItem*,int)));

    connect(bt[0],SIGNAL(clicked()),this,SLOT(copy_slot()));
    connect(bt[1],SIGNAL(clicked()),this,SLOT(delate_slot()));
}

void set_file_manage::Timer_on_slot()
{
    static int last_lev;
    static bool update_f = 1;
    if(last_lev!=limit_lev)
    {
        last_lev=limit_lev;
        update_info();
    }
//    #if debug_on ==0
//    if(update_f = 1)
//    {
//        if(QDir().exists(usb_path))
//        {
//            update_f =0;
//            update_info();
//        }
//        else
//        {
//            update_f =1;
//        }
//    }
//    #endif
}

void set_file_manage::deal_item_slot(QTreeWidgetItem *item)//点击展开或者收起
{
    if(item->isExpanded()==1)
    {
        tree->collapseItem(item);
    }
    else
    {
        tree->expandItem(item);
    }
    tree2->setCurrentItem(NULL);//取消另一个高亮
    oper_flg = 0;

}

void set_file_manage::deal_item_slot2(QTreeWidgetItem *item)//点击展开或者收起
{
    if(item->isExpanded()==1)
    {
        tree2->collapseItem(item);
    }
    else
    {
        tree2->expandItem(item);
    }
    tree->setCurrentItem(NULL);//取消另一个高亮
    oper_flg = 1;
}

void set_file_manage::get_loc_path_slot(QTreeWidgetItem *item ,int count)//获取点击项目路径
{

    QStringList filepath;
    QTreeWidgetItem *itemfile=item; //获取被点击的item
    while(itemfile!=NULL)
    {
        filepath<<itemfile->text(0); //获取itemfile名称
        itemfile=itemfile->parent(); //将itemfile指向父item
    }
    QString strpath;
    for(int i=(filepath.size()-1);i>=0;i--) //QStringlist类filepath反向存着初始item的路径
    { //将filepath反向输出，相应的加入’/‘
        strpath+=filepath.at(i);
        if(i!=0)
        {
            strpath+="/";
        }
    }
    strpath.replace("本地",loc_path);
    qDebug()<<"loc="<<strpath<<filepath.at(0);
    oper_loc_path = strpath;
    cur_file_name = filepath.at(0);

}

void set_file_manage::get_usb_path_slot(QTreeWidgetItem *item ,int count)//获取点击项目路径
{

    QStringList filepath;
    QTreeWidgetItem *itemfile=item; //获取被点击的item
    while(itemfile!=NULL)
    {
        filepath<<itemfile->text(0); //获取itemfile名称
        itemfile=itemfile->parent(); //将itemfile指向父item
    }
    QString strpath;
    for(int i=(filepath.size()-1);i>=0;i--) //QStringlist类filepath反向存着初始item的路径
    { //将filepath反向输出，相应的加入’/‘
        strpath+=filepath.at(i);
        if(i!=0)
        {
            strpath+="/";
        }
    }
    strpath.replace("U盘",usb_path);
    qDebug()<<"usb="<<strpath<<filepath.at(0);
    oper_usb_path = strpath;
    cur_file_name = filepath.at(0);
}

void set_file_manage::copy_slot()
{
    QDir loc_dir(oper_loc_path);
    QDir usb_dir(oper_usb_path);
    QFileInfoList list;
    if(oper_flg==0)
    {
        list = loc_dir.entryInfoList();
    }
    else
    {
        list = usb_dir.entryInfoList();
    }

    if(list.size()==0)
    {
        file_copy();
    }
    else
    {
        folder_copy();
    }
    qDebug()<<"list = "<<list.size();
    update_info();

}

void set_file_manage::file_copy()//文件拷贝
{
    QString str,str2;
    if(oper_flg==0)//本地->U盘
    {
        str = oper_loc_path;
        str.replace(loc_path,usb_path);
        if (!QFile::exists(oper_loc_path))
        {
            qDebug()<<"原路径不存在";
            return;
        }
        QDir *createfile     = new QDir;
        bool exist = createfile->exists(str);
        if (exist)
        {
            qDebug()<<"目标路径存在";
            //if(coverFileIfExist)//是否替换
            {
                createfile->remove(str);
            }
        }
        str2 = str;
        str2.replace("/"+cur_file_name,"");
        QDir dir;
        dir.mkpath(str2);//创建路径
        //if(!QFile::copy(oper_loc_path, "F:/File/keboard.csv"))
        if(!QFile::copy(oper_loc_path, str))
        {
            qDebug()<<"失败";
            return;
        }
    }
    else//U盘->本地
    {
        str = oper_usb_path;
        str.replace(usb_path,loc_path);
        if (!QFile::exists(oper_usb_path))
        {
            qDebug()<<"no path";
            return;
        }
        QDir *createfile     = new QDir;
        bool exist = createfile->exists(str);
        if (exist)
        {
            qDebug()<<"path exist";
            //if(coverFileIfExist)//是否替换
            {
                createfile->remove(str);
            }
        }
        str2 = str;
        str2.replace("/"+cur_file_name,"");
        QDir dir;
        dir.mkpath(str2);//创建路径
        //if(!QFile::copy(oper_loc_path, "F:/File/keboard.csv"))
        if(!QFile::copy(oper_usb_path, str))
        {
            qDebug()<<"失败";
            return;
        }
    }
    qDebug()<<"oper_loc_path = "<<oper_loc_path<<"oper_usb_path = "<<oper_usb_path<<"str="<<str;
}

void set_file_manage::folder_copy()//文件夹拷贝
{
    QString str,str2;
    if(oper_flg==0)//本地->U盘
    {
        str = oper_loc_path;
        str2 = str;
        str2.replace(loc_path,usb_path);
    }
    else
    {
        str = oper_usb_path;
        str2 = str;
        str2.replace(usb_path,loc_path);
    }

    QDir sourceDir(str);
    QDir targetDir(str2);


    if(!targetDir.exists())
    {
        if(!targetDir.mkdir(targetDir.absolutePath()))
        {
            qDebug()<<"创建路径失败";
            return;
        }
    }
    QFileInfoList list = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, list)
    {
            if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            {
                continue;
            }

            if(fileInfo.isDir())/**< 当为目录时，递归的进行copy */
            {
//                    if(!copyDirectoryFiles(fileInfo.filePath(),
//                        targetDir.filePath(fileInfo.fileName()),
//                        coverFileIfExist))
//                        return;
                folder_copy();
            }
            else
            {            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
                if(/*coverFileIfExist && */targetDir.exists(fileInfo.fileName()))
                {
                    targetDir.remove(fileInfo.fileName());
                }

                /// 进行文件copy
                /// if(!QFile::copy(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName())))
                if(!QFile::copy(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName())))
                {
                    qDebug()<<"失败";
                    return;
                }
            }
            //qDebug()<<"成功"<<fileInfo.filePath()<<targetDir.filePath(fileInfo.fileName())<<fileInfo.fileName();
    }


}

void set_file_manage::delate_slot()
{
    QString strPath;
    if(oper_flg==0)//本地
    {
        strPath = oper_loc_path;
    }
    else
    {
        strPath = oper_usb_path;
    }

    if (strPath.isEmpty() || !QDir().exists(strPath))//是否传入了空的路径||路径是否存在
    {
        return;
    }

    QFileInfo FileInfo(strPath);

    if (FileInfo.isFile())//如果是文件
    {
        QFile::remove(strPath);
    }
    else if (FileInfo.isDir())//如果是文件夹
    {
        QDir qDir(strPath);
        qDir.removeRecursively();
    }
    update_info();
}
