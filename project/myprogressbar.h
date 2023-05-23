#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QWidget>

namespace Ui {
class MyProgressBar;
}

class MyProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit MyProgressBar(QWidget *parent = nullptr);
    ~MyProgressBar();
    void INFO_init();
    void set_BarValue(int index);
private:
    Ui::MyProgressBar *ui;
    void resizeEvent(QResizeEvent *event);
};

#endif // MYPROGRESSBAR_H
