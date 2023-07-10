/********************************************************************************
** Form generated from reading UI file 'widget3_2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET3_2_H
#define UI_WIDGET3_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget3_2
{
public:
    QFrame *frame;
    QPushButton *bt_t_1;
    QPushButton *bt_t_2;
    QLineEdit *edit_4;
    QPushButton *bt_l_1;
    QLineEdit *edit_6;
    QPushButton *bt_l_2;
    QLineEdit *edit_3;
    QLineEdit *edit_1;
    QLineEdit *edit_5;
    QLineEdit *edit_7;
    QLineEdit *edit_2;
    QPushButton *bt_close;

    void setupUi(QWidget *widget3_2)
    {
        if (widget3_2->objectName().isEmpty())
            widget3_2->setObjectName(QString::fromUtf8("widget3_2"));
        widget3_2->resize(293, 430);
        frame = new QFrame(widget3_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 293, 430));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        bt_t_1 = new QPushButton(frame);
        bt_t_1->setObjectName(QString::fromUtf8("bt_t_1"));
        bt_t_1->setGeometry(QRect(70, 20, 55, 37));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bt_t_1->sizePolicy().hasHeightForWidth());
        bt_t_1->setSizePolicy(sizePolicy);
        bt_t_2 = new QPushButton(frame);
        bt_t_2->setObjectName(QString::fromUtf8("bt_t_2"));
        bt_t_2->setGeometry(QRect(120, 20, 55, 37));
        sizePolicy.setHeightForWidth(bt_t_2->sizePolicy().hasHeightForWidth());
        bt_t_2->setSizePolicy(sizePolicy);
        edit_4 = new QLineEdit(frame);
        edit_4->setObjectName(QString::fromUtf8("edit_4"));
        edit_4->setGeometry(QRect(70, 190, 113, 31));
        sizePolicy.setHeightForWidth(edit_4->sizePolicy().hasHeightForWidth());
        edit_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        edit_4->setFont(font);
        edit_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_l_1 = new QPushButton(frame);
        bt_l_1->setObjectName(QString::fromUtf8("bt_l_1"));
        bt_l_1->setGeometry(QRect(40, 150, 31, 31));
        sizePolicy.setHeightForWidth(bt_l_1->sizePolicy().hasHeightForWidth());
        bt_l_1->setSizePolicy(sizePolicy);
        edit_6 = new QLineEdit(frame);
        edit_6->setObjectName(QString::fromUtf8("edit_6"));
        edit_6->setGeometry(QRect(70, 280, 113, 31));
        sizePolicy.setHeightForWidth(edit_6->sizePolicy().hasHeightForWidth());
        edit_6->setSizePolicy(sizePolicy);
        edit_6->setFont(font);
        edit_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_l_2 = new QPushButton(frame);
        bt_l_2->setObjectName(QString::fromUtf8("bt_l_2"));
        bt_l_2->setGeometry(QRect(40, 190, 31, 31));
        sizePolicy.setHeightForWidth(bt_l_2->sizePolicy().hasHeightForWidth());
        bt_l_2->setSizePolicy(sizePolicy);
        edit_3 = new QLineEdit(frame);
        edit_3->setObjectName(QString::fromUtf8("edit_3"));
        edit_3->setGeometry(QRect(70, 150, 113, 31));
        sizePolicy.setHeightForWidth(edit_3->sizePolicy().hasHeightForWidth());
        edit_3->setSizePolicy(sizePolicy);
        edit_3->setFont(font);
        edit_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_1 = new QLineEdit(frame);
        edit_1->setObjectName(QString::fromUtf8("edit_1"));
        edit_1->setGeometry(QRect(70, 60, 113, 31));
        sizePolicy.setHeightForWidth(edit_1->sizePolicy().hasHeightForWidth());
        edit_1->setSizePolicy(sizePolicy);
        edit_1->setFont(font);
        edit_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_5 = new QLineEdit(frame);
        edit_5->setObjectName(QString::fromUtf8("edit_5"));
        edit_5->setGeometry(QRect(70, 230, 113, 31));
        sizePolicy.setHeightForWidth(edit_5->sizePolicy().hasHeightForWidth());
        edit_5->setSizePolicy(sizePolicy);
        edit_5->setFont(font);
        edit_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_7 = new QLineEdit(frame);
        edit_7->setObjectName(QString::fromUtf8("edit_7"));
        edit_7->setGeometry(QRect(70, 330, 113, 31));
        sizePolicy.setHeightForWidth(edit_7->sizePolicy().hasHeightForWidth());
        edit_7->setSizePolicy(sizePolicy);
        edit_7->setFont(font);
        edit_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_2 = new QLineEdit(frame);
        edit_2->setObjectName(QString::fromUtf8("edit_2"));
        edit_2->setGeometry(QRect(70, 110, 113, 31));
        sizePolicy.setHeightForWidth(edit_2->sizePolicy().hasHeightForWidth());
        edit_2->setSizePolicy(sizePolicy);
        edit_2->setFont(font);
        edit_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 86, 129);"));
        edit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_close = new QPushButton(frame);
        bt_close->setObjectName(QString::fromUtf8("bt_close"));
        bt_close->setGeometry(QRect(260, 0, 30, 30));
        sizePolicy.setHeightForWidth(bt_close->sizePolicy().hasHeightForWidth());
        bt_close->setSizePolicy(sizePolicy);

        retranslateUi(widget3_2);

        QMetaObject::connectSlotsByName(widget3_2);
    } // setupUi

    void retranslateUi(QWidget *widget3_2)
    {
        widget3_2->setWindowTitle(QCoreApplication::translate("widget3_2", "Form", nullptr));
        bt_t_1->setText(QString());
        bt_t_2->setText(QString());
        bt_l_1->setText(QString());
        bt_l_2->setText(QString());
        bt_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widget3_2: public Ui_widget3_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET3_2_H
