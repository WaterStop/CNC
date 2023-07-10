/********************************************************************************
** Form generated from reading UI file 'wedget1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEDGET1_H
#define UI_WEDGET1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "myprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_wedget1
{
public:
    QFrame *frame;
    QWidget *widget;
    QLabel *label_val;
    QProgressBar *progressBar;
    QPushButton *bt_4;
    QPushButton *bt_1;
    QPushButton *bt_3;
    QPushButton *bt_2;
    QPushButton *bt_0;
    MyProgressBar *widget_bar;

    void setupUi(QWidget *wedget1)
    {
        if (wedget1->objectName().isEmpty())
            wedget1->setObjectName(QString::fromUtf8("wedget1"));
        wedget1->resize(171, 429);
        wedget1->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(wedget1);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 171, 429));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 171, 429));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(""));
        label_val = new QLabel(widget);
        label_val->setObjectName(QString::fromUtf8("label_val"));
        label_val->setGeometry(QRect(30, 20, 28, 16));
        sizePolicy.setHeightForWidth(label_val->sizePolicy().hasHeightForWidth());
        label_val->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        label_val->setFont(font);
        label_val->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_val->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(32, 51, 16, 321));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        progressBar->setFont(font1);
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"	font:9pt;\n"
"	border-radius:7px;\n"
"	text-align:center;\n"
"	border:1px solid #E8EDF2;\n"
"	background-color: rgb(12, 66, 86);\n"
"	border-color: rgb(180, 180, 180);\n"
"}\n"
"QProgressBar:chunk{\n"
"	border-radius:3px;\n"
"	background-color:rgb(23, 175, 153);;\n"
"}"));
        progressBar->setValue(70);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        bt_4 = new QPushButton(widget);
        bt_4->setObjectName(QString::fromUtf8("bt_4"));
        bt_4->setGeometry(QRect(70, 20, 84, 70));
        sizePolicy.setHeightForWidth(bt_4->sizePolicy().hasHeightForWidth());
        bt_4->setSizePolicy(sizePolicy);
        bt_4->setFocusPolicy(Qt::NoFocus);
        bt_4->setStyleSheet(QString::fromUtf8("QButton{border:2px solid rgb(23,59, 111);}"));
        bt_1 = new QPushButton(widget);
        bt_1->setObjectName(QString::fromUtf8("bt_1"));
        bt_1->setGeometry(QRect(70, 230, 84, 70));
        sizePolicy.setHeightForWidth(bt_1->sizePolicy().hasHeightForWidth());
        bt_1->setSizePolicy(sizePolicy);
        bt_1->setFocusPolicy(Qt::NoFocus);
        bt_1->setStyleSheet(QString::fromUtf8("QButton{border:2px solid rgb(23,59, 111);}"));
        bt_3 = new QPushButton(widget);
        bt_3->setObjectName(QString::fromUtf8("bt_3"));
        bt_3->setGeometry(QRect(70, 90, 84, 70));
        sizePolicy.setHeightForWidth(bt_3->sizePolicy().hasHeightForWidth());
        bt_3->setSizePolicy(sizePolicy);
        bt_3->setFocusPolicy(Qt::NoFocus);
        bt_3->setStyleSheet(QString::fromUtf8("QButton{border:2px solid rgb(23,59, 111);}"));
        bt_2 = new QPushButton(widget);
        bt_2->setObjectName(QString::fromUtf8("bt_2"));
        bt_2->setGeometry(QRect(70, 160, 84, 70));
        sizePolicy.setHeightForWidth(bt_2->sizePolicy().hasHeightForWidth());
        bt_2->setSizePolicy(sizePolicy);
        bt_2->setFocusPolicy(Qt::NoFocus);
        bt_2->setStyleSheet(QString::fromUtf8("QButton{border:2px solid rgb(23,59, 111);}"));
        bt_0 = new QPushButton(widget);
        bt_0->setObjectName(QString::fromUtf8("bt_0"));
        bt_0->setGeometry(QRect(70, 300, 84, 70));
        sizePolicy.setHeightForWidth(bt_0->sizePolicy().hasHeightForWidth());
        bt_0->setSizePolicy(sizePolicy);
        bt_0->setFocusPolicy(Qt::NoFocus);
        bt_0->setStyleSheet(QString::fromUtf8("QButton{border:2px solid rgb(23,59, 111);}"));
        bt_0->setAutoExclusive(true);
        bt_0->setAutoRepeatDelay(500);
        widget_bar = new MyProgressBar(widget);
        widget_bar->setObjectName(QString::fromUtf8("widget_bar"));
        widget_bar->setGeometry(QRect(25, 45, 35, 350));

        retranslateUi(wedget1);

        QMetaObject::connectSlotsByName(wedget1);
    } // setupUi

    void retranslateUi(QWidget *wedget1)
    {
        wedget1->setWindowTitle(QCoreApplication::translate("wedget1", "Form", nullptr));
        label_val->setText(QCoreApplication::translate("wedget1", "100%", nullptr));
        bt_4->setText(QString());
        bt_1->setText(QString());
        bt_3->setText(QString());
        bt_2->setText(QString());
        bt_0->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class wedget1: public Ui_wedget1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEDGET1_H
