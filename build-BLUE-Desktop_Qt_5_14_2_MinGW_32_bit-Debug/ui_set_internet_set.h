/********************************************************************************
** Form generated from reading UI file 'set_internet_set.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_INTERNET_SET_H
#define UI_SET_INTERNET_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_internet_set
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_internet_set)
    {
        if (set_internet_set->objectName().isEmpty())
            set_internet_set->setObjectName(QString::fromUtf8("set_internet_set"));
        set_internet_set->resize(400, 300);
        frame = new QFrame(set_internet_set);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 401, 301));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);

        retranslateUi(set_internet_set);

        QMetaObject::connectSlotsByName(set_internet_set);
    } // setupUi

    void retranslateUi(QWidget *set_internet_set)
    {
        set_internet_set->setWindowTitle(QCoreApplication::translate("set_internet_set", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_internet_set: public Ui_set_internet_set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_INTERNET_SET_H
