#include "widget.h"
#include "wedget1.h"
#include "baseset.h"

#include <QApplication>
#include <QTextCodec>
#include "shm.h"
#include "MachineFusion.h"

int main(int argc, char *argv[])
{


    MachineFusion mf ;
    QTextCodec *codec=QTextCodec::codecForName("utf-8");//修复读中文乱码
    QTextCodec::setCodecForLocale(codec);//修复读中文乱码
    //shm_init();
    QApplication a(argc, argv);
    Widget w;
    //wedget1 w;
    w.show();
    return a.exec();
}
