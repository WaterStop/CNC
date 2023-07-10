#include "widget.h"
#include "wedget1.h"
#include "baseset.h"

#include <QApplication>
#include <QTextCodec>
#include "shm.h"

int main(int argc, char *argv[])
{
    QTextCodec *codec=QTextCodec::codecForName("utf-8");//修复读中文乱码
    QTextCodec::setCodecForLocale(codec);//修复读中文乱码
#if debug_on == 0
    shm_init();
#endif
    QApplication a(argc, argv);
    Widget w;
    //wedget1 w;
    w.show();
    return a.exec();
}
