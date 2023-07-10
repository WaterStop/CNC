/********************************************************************************
** Form generated from reading UI file 'set_data_para.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_DATA_PARA_H
#define UI_SET_DATA_PARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_data_para
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_data_para)
    {
        if (set_data_para->objectName().isEmpty())
            set_data_para->setObjectName(QString::fromUtf8("set_data_para"));
        set_data_para->resize(691, 614);
        frame = new QFrame(set_data_para);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 691, 614));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);

        retranslateUi(set_data_para);

        QMetaObject::connectSlotsByName(set_data_para);
    } // setupUi

    void retranslateUi(QWidget *set_data_para)
    {
        set_data_para->setWindowTitle(QCoreApplication::translate("set_data_para", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_data_para: public Ui_set_data_para {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_DATA_PARA_H
