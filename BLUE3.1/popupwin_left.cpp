#include "popupwin_left.h"
#include "ui_popupwin_left.h"

popupwin_left::popupwin_left(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::popupwin_left)
{
    ui->setupUi(this);
}

popupwin_left::~popupwin_left()
{
    delete ui;
}

void popupwin_left::set_wg2_background()
{
    ui->frame->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/blue_pic/popwin_left_back.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->frame->setPalette(palette);
    ui->frame->show();
}
