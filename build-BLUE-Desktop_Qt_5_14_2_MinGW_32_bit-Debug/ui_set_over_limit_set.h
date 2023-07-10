/********************************************************************************
** Form generated from reading UI file 'set_over_limit_set.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_OVER_LIMIT_SET_H
#define UI_SET_OVER_LIMIT_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_set_over_limit_set
{
public:
    QFrame *frame;
    MyLineEdit *edit_0;
    MyLineEdit *edit_1;
    MyLineEdit *edit_2;

    void setupUi(QWidget *set_over_limit_set)
    {
        if (set_over_limit_set->objectName().isEmpty())
            set_over_limit_set->setObjectName(QString::fromUtf8("set_over_limit_set"));
        set_over_limit_set->resize(691, 614);
        frame = new QFrame(set_over_limit_set);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 691, 614));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        edit_0 = new MyLineEdit(frame);
        edit_0->setObjectName(QString::fromUtf8("edit_0"));
        edit_0->setGeometry(QRect(60, 60, 113, 20));
        edit_1 = new MyLineEdit(frame);
        edit_1->setObjectName(QString::fromUtf8("edit_1"));
        edit_1->setGeometry(QRect(60, 130, 113, 20));
        edit_2 = new MyLineEdit(frame);
        edit_2->setObjectName(QString::fromUtf8("edit_2"));
        edit_2->setGeometry(QRect(60, 200, 113, 20));

        retranslateUi(set_over_limit_set);

        QMetaObject::connectSlotsByName(set_over_limit_set);
    } // setupUi

    void retranslateUi(QWidget *set_over_limit_set)
    {
        set_over_limit_set->setWindowTitle(QCoreApplication::translate("set_over_limit_set", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_over_limit_set: public Ui_set_over_limit_set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_OVER_LIMIT_SET_H
