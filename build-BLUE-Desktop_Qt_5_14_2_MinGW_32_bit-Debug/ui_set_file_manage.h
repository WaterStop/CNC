/********************************************************************************
** Form generated from reading UI file 'set_file_manage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_FILE_MANAGE_H
#define UI_SET_FILE_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_file_manage
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_file_manage)
    {
        if (set_file_manage->objectName().isEmpty())
            set_file_manage->setObjectName(QString::fromUtf8("set_file_manage"));
        set_file_manage->resize(400, 300);
        frame = new QFrame(set_file_manage);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 401, 301));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);

        retranslateUi(set_file_manage);

        QMetaObject::connectSlotsByName(set_file_manage);
    } // setupUi

    void retranslateUi(QWidget *set_file_manage)
    {
        set_file_manage->setWindowTitle(QCoreApplication::translate("set_file_manage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_file_manage: public Ui_set_file_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_FILE_MANAGE_H
