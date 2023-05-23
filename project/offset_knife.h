#ifndef OFFSET_KNIFE_H
#define OFFSET_KNIFE_H

#include <QWidget>
#include "baseset.h"

namespace Ui {
class Offset_knife;
}

class Offset_knife : public QWidget
{
    Q_OBJECT

public:
    explicit Offset_knife(QWidget *parent = nullptr);
    ~Offset_knife();

private:
    Ui::Offset_knife *ui;
    void set_background();
    void resizeEvent(QResizeEvent *event);
    void set_combobox();
};

#endif // OFFSET_KNIFE_H
