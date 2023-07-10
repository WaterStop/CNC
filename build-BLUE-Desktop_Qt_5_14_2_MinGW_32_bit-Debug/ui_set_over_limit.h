/********************************************************************************
** Form generated from reading UI file 'set_over_limit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_OVER_LIMIT_H
#define UI_SET_OVER_LIMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_over_limit
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_over_limit)
    {
        if (set_over_limit->objectName().isEmpty())
            set_over_limit->setObjectName(QString::fromUtf8("set_over_limit"));
        set_over_limit->resize(899, 643);
        frame = new QFrame(set_over_limit);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 899, 643));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);

        retranslateUi(set_over_limit);

        QMetaObject::connectSlotsByName(set_over_limit);
    } // setupUi

    void retranslateUi(QWidget *set_over_limit)
    {
        set_over_limit->setWindowTitle(QCoreApplication::translate("set_over_limit", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_over_limit: public Ui_set_over_limit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_OVER_LIMIT_H
