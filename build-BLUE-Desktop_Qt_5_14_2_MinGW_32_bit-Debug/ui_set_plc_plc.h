/********************************************************************************
** Form generated from reading UI file 'set_plc_plc.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_PLC_PLC_H
#define UI_SET_PLC_PLC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Set_Plc_plc
{
public:
    QFrame *frame;

    void setupUi(QWidget *Set_Plc_plc)
    {
        if (Set_Plc_plc->objectName().isEmpty())
            Set_Plc_plc->setObjectName(QString::fromUtf8("Set_Plc_plc"));
        Set_Plc_plc->resize(691, 614);
        frame = new QFrame(Set_Plc_plc);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 691, 614));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);

        retranslateUi(Set_Plc_plc);

        QMetaObject::connectSlotsByName(Set_Plc_plc);
    } // setupUi

    void retranslateUi(QWidget *Set_Plc_plc)
    {
        Set_Plc_plc->setWindowTitle(QCoreApplication::translate("Set_Plc_plc", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Set_Plc_plc: public Ui_Set_Plc_plc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_PLC_PLC_H
