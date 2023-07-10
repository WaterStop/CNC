/********************************************************************************
** Form generated from reading UI file 'set_back_up.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_BACK_UP_H
#define UI_SET_BACK_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_back_up
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_back_up)
    {
        if (set_back_up->objectName().isEmpty())
            set_back_up->setObjectName(QString::fromUtf8("set_back_up"));
        set_back_up->resize(400, 300);
        frame = new QFrame(set_back_up);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 401, 301));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);

        retranslateUi(set_back_up);

        QMetaObject::connectSlotsByName(set_back_up);
    } // setupUi

    void retranslateUi(QWidget *set_back_up)
    {
        set_back_up->setWindowTitle(QCoreApplication::translate("set_back_up", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_back_up: public Ui_set_back_up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_BACK_UP_H
