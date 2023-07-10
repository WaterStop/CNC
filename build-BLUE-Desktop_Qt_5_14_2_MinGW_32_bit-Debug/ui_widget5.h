/********************************************************************************
** Form generated from reading UI file 'widget5.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET5_H
#define UI_WIDGET5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget5
{
public:
    QFrame *frame;
    QPushButton *bt_num_4;
    QPushButton *bt_num_1;
    QPushButton *bt_num_3;
    QLineEdit *ed_1;
    QPushButton *bt_lock;
    QLineEdit *ed_2;
    QPushButton *bt_num_2;
    QLineEdit *ed_3;

    void setupUi(QWidget *widget5)
    {
        if (widget5->objectName().isEmpty())
            widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->resize(291, 205);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget5->sizePolicy().hasHeightForWidth());
        widget5->setSizePolicy(sizePolicy);
        frame = new QFrame(widget5);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 291, 205));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        bt_num_4 = new QPushButton(frame);
        bt_num_4->setObjectName(QString::fromUtf8("bt_num_4"));
        bt_num_4->setGeometry(QRect(180, 140, 34, 34));
        sizePolicy.setHeightForWidth(bt_num_4->sizePolicy().hasHeightForWidth());
        bt_num_4->setSizePolicy(sizePolicy);
        bt_num_1 = new QPushButton(frame);
        bt_num_1->setObjectName(QString::fromUtf8("bt_num_1"));
        bt_num_1->setGeometry(QRect(30, 20, 34, 34));
        sizePolicy.setHeightForWidth(bt_num_1->sizePolicy().hasHeightForWidth());
        bt_num_1->setSizePolicy(sizePolicy);
        bt_num_3 = new QPushButton(frame);
        bt_num_3->setObjectName(QString::fromUtf8("bt_num_3"));
        bt_num_3->setGeometry(QRect(30, 140, 34, 34));
        sizePolicy.setHeightForWidth(bt_num_3->sizePolicy().hasHeightForWidth());
        bt_num_3->setSizePolicy(sizePolicy);
        ed_1 = new QLineEdit(frame);
        ed_1->setObjectName(QString::fromUtf8("ed_1"));
        ed_1->setGeometry(QRect(220, 50, 22, 20));
        sizePolicy.setHeightForWidth(ed_1->sizePolicy().hasHeightForWidth());
        ed_1->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        ed_1->setFont(font);
        ed_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        bt_lock = new QPushButton(frame);
        bt_lock->setObjectName(QString::fromUtf8("bt_lock"));
        bt_lock->setGeometry(QRect(90, 60, 79, 70));
        sizePolicy.setHeightForWidth(bt_lock->sizePolicy().hasHeightForWidth());
        bt_lock->setSizePolicy(sizePolicy);
        ed_2 = new QLineEdit(frame);
        ed_2->setObjectName(QString::fromUtf8("ed_2"));
        ed_2->setGeometry(QRect(220, 80, 22, 20));
        sizePolicy.setHeightForWidth(ed_2->sizePolicy().hasHeightForWidth());
        ed_2->setSizePolicy(sizePolicy);
        ed_2->setFont(font);
        ed_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        bt_num_2 = new QPushButton(frame);
        bt_num_2->setObjectName(QString::fromUtf8("bt_num_2"));
        bt_num_2->setGeometry(QRect(180, 20, 34, 34));
        sizePolicy.setHeightForWidth(bt_num_2->sizePolicy().hasHeightForWidth());
        bt_num_2->setSizePolicy(sizePolicy);
        ed_3 = new QLineEdit(frame);
        ed_3->setObjectName(QString::fromUtf8("ed_3"));
        ed_3->setGeometry(QRect(220, 110, 22, 20));
        sizePolicy.setHeightForWidth(ed_3->sizePolicy().hasHeightForWidth());
        ed_3->setSizePolicy(sizePolicy);
        ed_3->setFont(font);
        ed_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));

        retranslateUi(widget5);

        QMetaObject::connectSlotsByName(widget5);
    } // setupUi

    void retranslateUi(QWidget *widget5)
    {
        widget5->setWindowTitle(QCoreApplication::translate("widget5", "Form", nullptr));
        bt_num_4->setText(QString());
        bt_num_1->setText(QString());
        bt_num_3->setText(QString());
        bt_lock->setText(QString());
        bt_num_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widget5: public Ui_widget5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET5_H
