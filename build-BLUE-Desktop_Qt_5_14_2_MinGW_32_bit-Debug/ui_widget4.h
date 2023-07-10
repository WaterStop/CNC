/********************************************************************************
** Form generated from reading UI file 'widget4.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET4_H
#define UI_WIDGET4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget4
{
public:
    QFrame *frame;
    QLabel *label_2;
    QPushButton *bt_MAxisStop;
    QPushButton *bt_MAxisForw;
    QPushButton *bt_switch;
    QPushButton *bt_down;
    QPushButton *bt_switch_2;
    QLabel *label;
    QPushButton *bt_fastmove;
    QLabel *label_3;
    QPushButton *bt_right;
    QPushButton *bt_MAxisRev;
    QPushButton *bt_left;
    QPushButton *bt_up;
    QLabel *label_f;
    QPushButton *bt_switch_3;

    void setupUi(QWidget *widget4)
    {
        if (widget4->objectName().isEmpty())
            widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->resize(644, 206);
        frame = new QFrame(widget4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 644, 206));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(23, 53, 83, 25));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_MAxisStop = new QPushButton(frame);
        bt_MAxisStop->setObjectName(QString::fromUtf8("bt_MAxisStop"));
        bt_MAxisStop->setGeometry(QRect(559, 80, 45, 43));
        sizePolicy.setHeightForWidth(bt_MAxisStop->sizePolicy().hasHeightForWidth());
        bt_MAxisStop->setSizePolicy(sizePolicy);
        bt_MAxisStop->setFocusPolicy(Qt::NoFocus);
        bt_MAxisForw = new QPushButton(frame);
        bt_MAxisForw->setObjectName(QString::fromUtf8("bt_MAxisForw"));
        bt_MAxisForw->setGeometry(QRect(559, 19, 43, 34));
        sizePolicy.setHeightForWidth(bt_MAxisForw->sizePolicy().hasHeightForWidth());
        bt_MAxisForw->setSizePolicy(sizePolicy);
        bt_MAxisForw->setFocusPolicy(Qt::NoFocus);
        bt_switch = new QPushButton(frame);
        bt_switch->setObjectName(QString::fromUtf8("bt_switch"));
        bt_switch->setGeometry(QRect(130, 42, 66, 26));
        sizePolicy.setHeightForWidth(bt_switch->sizePolicy().hasHeightForWidth());
        bt_switch->setSizePolicy(sizePolicy);
        bt_switch->setFocusPolicy(Qt::NoFocus);
        bt_down = new QPushButton(frame);
        bt_down->setObjectName(QString::fromUtf8("bt_down"));
        bt_down->setGeometry(QRect(265, 129, 46, 47));
        sizePolicy.setHeightForWidth(bt_down->sizePolicy().hasHeightForWidth());
        bt_down->setSizePolicy(sizePolicy);
        bt_down->setFocusPolicy(Qt::NoFocus);
        bt_switch_2 = new QPushButton(frame);
        bt_switch_2->setObjectName(QString::fromUtf8("bt_switch_2"));
        bt_switch_2->setGeometry(QRect(130, 101, 66, 26));
        sizePolicy.setHeightForWidth(bt_switch_2->sizePolicy().hasHeightForWidth());
        bt_switch_2->setSizePolicy(sizePolicy);
        bt_switch_2->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(23, 20, 83, 25));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_fastmove = new QPushButton(frame);
        bt_fastmove->setObjectName(QString::fromUtf8("bt_fastmove"));
        bt_fastmove->setGeometry(QRect(264, 81, 46, 47));
        sizePolicy.setHeightForWidth(bt_fastmove->sizePolicy().hasHeightForWidth());
        bt_fastmove->setSizePolicy(sizePolicy);
        bt_fastmove->setFocusPolicy(Qt::NoFocus);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(23, 87, 83, 25));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_right = new QPushButton(frame);
        bt_right->setObjectName(QString::fromUtf8("bt_right"));
        bt_right->setGeometry(QRect(314, 81, 46, 47));
        sizePolicy.setHeightForWidth(bt_right->sizePolicy().hasHeightForWidth());
        bt_right->setSizePolicy(sizePolicy);
        bt_right->setFocusPolicy(Qt::NoFocus);
        bt_MAxisRev = new QPushButton(frame);
        bt_MAxisRev->setObjectName(QString::fromUtf8("bt_MAxisRev"));
        bt_MAxisRev->setGeometry(QRect(559, 150, 43, 34));
        sizePolicy.setHeightForWidth(bt_MAxisRev->sizePolicy().hasHeightForWidth());
        bt_MAxisRev->setSizePolicy(sizePolicy);
        bt_MAxisRev->setFocusPolicy(Qt::NoFocus);
        bt_left = new QPushButton(frame);
        bt_left->setObjectName(QString::fromUtf8("bt_left"));
        bt_left->setGeometry(QRect(216, 81, 46, 47));
        sizePolicy.setHeightForWidth(bt_left->sizePolicy().hasHeightForWidth());
        bt_left->setSizePolicy(sizePolicy);
        bt_left->setFocusPolicy(Qt::NoFocus);
        bt_up = new QPushButton(frame);
        bt_up->setObjectName(QString::fromUtf8("bt_up"));
        bt_up->setGeometry(QRect(264, 32, 46, 47));
        sizePolicy.setHeightForWidth(bt_up->sizePolicy().hasHeightForWidth());
        bt_up->setSizePolicy(sizePolicy);
        bt_up->setFocusPolicy(Qt::NoFocus);
        label_f = new QLabel(frame);
        label_f->setObjectName(QString::fromUtf8("label_f"));
        label_f->setGeometry(QRect(274, 45, 130, 85));
        sizePolicy.setHeightForWidth(label_f->sizePolicy().hasHeightForWidth());
        label_f->setSizePolicy(sizePolicy);
        bt_switch_3 = new QPushButton(frame);
        bt_switch_3->setObjectName(QString::fromUtf8("bt_switch_3"));
        bt_switch_3->setGeometry(QRect(130, 160, 66, 26));
        sizePolicy.setHeightForWidth(bt_switch_3->sizePolicy().hasHeightForWidth());
        bt_switch_3->setSizePolicy(sizePolicy);
        bt_switch_3->setFocusPolicy(Qt::NoFocus);

        retranslateUi(widget4);

        QMetaObject::connectSlotsByName(widget4);
    } // setupUi

    void retranslateUi(QWidget *widget4)
    {
        widget4->setWindowTitle(QCoreApplication::translate("widget4", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("widget4", "10h 15m 26s", nullptr));
        bt_MAxisStop->setText(QString());
        bt_MAxisForw->setText(QString());
        bt_switch->setText(QString());
        bt_down->setText(QString());
        bt_switch_2->setText(QString());
        label->setText(QCoreApplication::translate("widget4", "10h 15m 26s", nullptr));
        bt_fastmove->setText(QString());
        label_3->setText(QCoreApplication::translate("widget4", "999", nullptr));
        bt_right->setText(QString());
        bt_MAxisRev->setText(QString());
        bt_left->setText(QString());
        bt_up->setText(QString());
        label_f->setText(QString());
        bt_switch_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widget4: public Ui_widget4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET4_H
