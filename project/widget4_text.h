#ifndef WIDGET4_TEXT_H
#define WIDGET4_TEXT_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class widget4_text;
}

class widget4_text : public QWidget
{
    Q_OBJECT

public:
    explicit widget4_text(QWidget *parent = nullptr);
    ~widget4_text();

private:
    Ui::widget4_text *ui;    
    void draw_prossbar(int x,int y);
    void paintEvent(QPaintEvent *);
public slots:
    void Timer_on_slot();
};

#endif // WIDGET4_TEXT_H
