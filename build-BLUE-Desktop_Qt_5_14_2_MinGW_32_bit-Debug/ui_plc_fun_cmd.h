/********************************************************************************
** Form generated from reading UI file 'plc_fun_cmd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLC_FUN_CMD_H
#define UI_PLC_FUN_CMD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_plc_fun_cmd
{
public:
    QFrame *frame;
    QTableWidget *TableWidget;

    void setupUi(QDialog *plc_fun_cmd)
    {
        if (plc_fun_cmd->objectName().isEmpty())
            plc_fun_cmd->setObjectName(QString::fromUtf8("plc_fun_cmd"));
        plc_fun_cmd->resize(225, 120);
        frame = new QFrame(plc_fun_cmd);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 225, 120));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        TableWidget = new QTableWidget(frame);
        TableWidget->setObjectName(QString::fromUtf8("TableWidget"));
        TableWidget->setGeometry(QRect(0, 0, 225, 120));

        retranslateUi(plc_fun_cmd);

        QMetaObject::connectSlotsByName(plc_fun_cmd);
    } // setupUi

    void retranslateUi(QDialog *plc_fun_cmd)
    {
        plc_fun_cmd->setWindowTitle(QCoreApplication::translate("plc_fun_cmd", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plc_fun_cmd: public Ui_plc_fun_cmd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLC_FUN_CMD_H
