/********************************************************************************
** Form generated from reading UI file 'set_alarm_info.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_ALARM_INFO_H
#define UI_SET_ALARM_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_alarm_info
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_alarm_info)
    {
        if (set_alarm_info->objectName().isEmpty())
            set_alarm_info->setObjectName(QString::fromUtf8("set_alarm_info"));
        set_alarm_info->resize(691, 614);
        frame = new QFrame(set_alarm_info);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 691, 614));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);

        retranslateUi(set_alarm_info);

        QMetaObject::connectSlotsByName(set_alarm_info);
    } // setupUi

    void retranslateUi(QWidget *set_alarm_info)
    {
        set_alarm_info->setWindowTitle(QCoreApplication::translate("set_alarm_info", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_alarm_info: public Ui_set_alarm_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_ALARM_INFO_H
