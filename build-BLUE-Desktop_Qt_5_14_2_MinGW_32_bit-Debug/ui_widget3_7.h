/********************************************************************************
** Form generated from reading UI file 'widget3_7.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET3_7_H
#define UI_WIDGET3_7_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_widget3_7
{
public:
    QFrame *frame;
    MyLineEdit *edit_4;
    MyLineEdit *edit_2;
    QPushButton *bt_l_2;
    MyLineEdit *edit_3;
    MyLineEdit *edit_5;
    QPushButton *bt_l_1;
    MyLineEdit *edit_1;
    QPushButton *bt_b_0;
    QPushButton *bt_close;
    QPushButton *bt_clock;
    QPushButton *bt_anticlock;
    MyLineEdit *edit_6;

    void setupUi(QWidget *widget3_7)
    {
        if (widget3_7->objectName().isEmpty())
            widget3_7->setObjectName(QString::fromUtf8("widget3_7"));
        widget3_7->resize(293, 430);
        frame = new QFrame(widget3_7);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 293, 430));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        edit_4 = new MyLineEdit(frame);
        edit_4->setObjectName(QString::fromUtf8("edit_4"));
        edit_4->setGeometry(QRect(70, 180, 113, 31));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edit_4->sizePolicy().hasHeightForWidth());
        edit_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        edit_4->setFont(font);
        edit_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_2 = new MyLineEdit(frame);
        edit_2->setObjectName(QString::fromUtf8("edit_2"));
        edit_2->setGeometry(QRect(70, 80, 113, 31));
        sizePolicy.setHeightForWidth(edit_2->sizePolicy().hasHeightForWidth());
        edit_2->setSizePolicy(sizePolicy);
        edit_2->setFont(font);
        edit_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_l_2 = new QPushButton(frame);
        bt_l_2->setObjectName(QString::fromUtf8("bt_l_2"));
        bt_l_2->setGeometry(QRect(40, 80, 31, 31));
        sizePolicy.setHeightForWidth(bt_l_2->sizePolicy().hasHeightForWidth());
        bt_l_2->setSizePolicy(sizePolicy);
        edit_3 = new MyLineEdit(frame);
        edit_3->setObjectName(QString::fromUtf8("edit_3"));
        edit_3->setGeometry(QRect(70, 130, 113, 31));
        sizePolicy.setHeightForWidth(edit_3->sizePolicy().hasHeightForWidth());
        edit_3->setSizePolicy(sizePolicy);
        edit_3->setFont(font);
        edit_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_5 = new MyLineEdit(frame);
        edit_5->setObjectName(QString::fromUtf8("edit_5"));
        edit_5->setGeometry(QRect(70, 230, 113, 31));
        sizePolicy.setHeightForWidth(edit_5->sizePolicy().hasHeightForWidth());
        edit_5->setSizePolicy(sizePolicy);
        edit_5->setFont(font);
        edit_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_l_1 = new QPushButton(frame);
        bt_l_1->setObjectName(QString::fromUtf8("bt_l_1"));
        bt_l_1->setGeometry(QRect(40, 30, 31, 31));
        sizePolicy.setHeightForWidth(bt_l_1->sizePolicy().hasHeightForWidth());
        bt_l_1->setSizePolicy(sizePolicy);
        edit_1 = new MyLineEdit(frame);
        edit_1->setObjectName(QString::fromUtf8("edit_1"));
        edit_1->setGeometry(QRect(70, 30, 113, 31));
        sizePolicy.setHeightForWidth(edit_1->sizePolicy().hasHeightForWidth());
        edit_1->setSizePolicy(sizePolicy);
        edit_1->setFont(font);
        edit_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_b_0 = new QPushButton(frame);
        bt_b_0->setObjectName(QString::fromUtf8("bt_b_0"));
        bt_b_0->setGeometry(QRect(80, 350, 65, 35));
        sizePolicy.setHeightForWidth(bt_b_0->sizePolicy().hasHeightForWidth());
        bt_b_0->setSizePolicy(sizePolicy);
        bt_close = new QPushButton(frame);
        bt_close->setObjectName(QString::fromUtf8("bt_close"));
        bt_close->setGeometry(QRect(260, 20, 20, 20));
        sizePolicy.setHeightForWidth(bt_close->sizePolicy().hasHeightForWidth());
        bt_close->setSizePolicy(sizePolicy);
        bt_clock = new QPushButton(frame);
        bt_clock->setObjectName(QString::fromUtf8("bt_clock"));
        bt_clock->setGeometry(QRect(125, 310, 31, 31));
        sizePolicy.setHeightForWidth(bt_clock->sizePolicy().hasHeightForWidth());
        bt_clock->setSizePolicy(sizePolicy);
        bt_clock->setFocusPolicy(Qt::NoFocus);
        bt_anticlock = new QPushButton(frame);
        bt_anticlock->setObjectName(QString::fromUtf8("bt_anticlock"));
        bt_anticlock->setGeometry(QRect(75, 310, 31, 31));
        sizePolicy.setHeightForWidth(bt_anticlock->sizePolicy().hasHeightForWidth());
        bt_anticlock->setSizePolicy(sizePolicy);
        bt_anticlock->setFocusPolicy(Qt::NoFocus);
        edit_6 = new MyLineEdit(frame);
        edit_6->setObjectName(QString::fromUtf8("edit_6"));
        edit_6->setGeometry(QRect(70, 270, 113, 31));
        sizePolicy.setHeightForWidth(edit_6->sizePolicy().hasHeightForWidth());
        edit_6->setSizePolicy(sizePolicy);
        edit_6->setFont(font);
        edit_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(widget3_7);

        QMetaObject::connectSlotsByName(widget3_7);
    } // setupUi

    void retranslateUi(QWidget *widget3_7)
    {
        widget3_7->setWindowTitle(QCoreApplication::translate("widget3_7", "Form", nullptr));
        bt_l_2->setText(QString());
        bt_l_1->setText(QString());
        bt_b_0->setText(QString());
        bt_close->setText(QString());
        bt_clock->setText(QString());
        bt_anticlock->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widget3_7: public Ui_widget3_7 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET3_7_H