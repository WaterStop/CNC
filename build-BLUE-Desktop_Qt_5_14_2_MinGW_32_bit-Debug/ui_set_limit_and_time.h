/********************************************************************************
** Form generated from reading UI file 'set_limit_and_time.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_LIMIT_AND_TIME_H
#define UI_SET_LIMIT_AND_TIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_limit_and_time
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_limit_and_time)
    {
        if (set_limit_and_time->objectName().isEmpty())
            set_limit_and_time->setObjectName(QString::fromUtf8("set_limit_and_time"));
        set_limit_and_time->resize(691, 614);
        frame = new QFrame(set_limit_and_time);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 691, 614));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);

        retranslateUi(set_limit_and_time);

        QMetaObject::connectSlotsByName(set_limit_and_time);
    } // setupUi

    void retranslateUi(QWidget *set_limit_and_time)
    {
        set_limit_and_time->setWindowTitle(QCoreApplication::translate("set_limit_and_time", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_limit_and_time: public Ui_set_limit_and_time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_LIMIT_AND_TIME_H
