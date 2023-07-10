/********************************************************************************
** Form generated from reading UI file 'plc_plc_pic.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLC_PLC_PIC_H
#define UI_PLC_PLC_PIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PLC_plc_pic
{
public:
    QFrame *frame;
    QPushButton *bt_up;
    QPushButton *bt_down;
    QPushButton *bt_u;
    QPushButton *bt_d;
    QPushButton *bt_l;
    QPushButton *bt_r;
    QPushButton *bt_fun;

    void setupUi(QWidget *PLC_plc_pic)
    {
        if (PLC_plc_pic->objectName().isEmpty())
            PLC_plc_pic->setObjectName(QString::fromUtf8("PLC_plc_pic"));
        PLC_plc_pic->resize(620, 450);
        PLC_plc_pic->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(PLC_plc_pic);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 620, 450));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        bt_up = new QPushButton(frame);
        bt_up->setObjectName(QString::fromUtf8("bt_up"));
        bt_up->setGeometry(QRect(560, 220, 41, 31));
        bt_down = new QPushButton(frame);
        bt_down->setObjectName(QString::fromUtf8("bt_down"));
        bt_down->setGeometry(QRect(560, 280, 41, 31));
        bt_u = new QPushButton(frame);
        bt_u->setObjectName(QString::fromUtf8("bt_u"));
        bt_u->setGeometry(QRect(540, 80, 41, 31));
        bt_d = new QPushButton(frame);
        bt_d->setObjectName(QString::fromUtf8("bt_d"));
        bt_d->setGeometry(QRect(540, 140, 41, 31));
        bt_l = new QPushButton(frame);
        bt_l->setObjectName(QString::fromUtf8("bt_l"));
        bt_l->setGeometry(QRect(500, 110, 41, 31));
        bt_r = new QPushButton(frame);
        bt_r->setObjectName(QString::fromUtf8("bt_r"));
        bt_r->setGeometry(QRect(580, 110, 41, 31));
        bt_fun = new QPushButton(frame);
        bt_fun->setObjectName(QString::fromUtf8("bt_fun"));
        bt_fun->setGeometry(QRect(550, 340, 41, 31));

        retranslateUi(PLC_plc_pic);

        QMetaObject::connectSlotsByName(PLC_plc_pic);
    } // setupUi

    void retranslateUi(QWidget *PLC_plc_pic)
    {
        PLC_plc_pic->setWindowTitle(QCoreApplication::translate("PLC_plc_pic", "Form", nullptr));
        bt_up->setText(QString());
        bt_down->setText(QString());
        bt_u->setText(QString());
        bt_d->setText(QString());
        bt_l->setText(QString());
        bt_r->setText(QString());
        bt_fun->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PLC_plc_pic: public Ui_PLC_plc_pic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLC_PLC_PIC_H
