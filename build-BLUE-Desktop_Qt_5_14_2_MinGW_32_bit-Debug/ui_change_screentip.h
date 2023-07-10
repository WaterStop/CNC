/********************************************************************************
** Form generated from reading UI file 'change_screentip.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_SCREENTIP_H
#define UI_CHANGE_SCREENTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_change_screentip
{
public:
    QFrame *frame;
    QPushButton *bt_ok;
    QLabel *label_tip;
    QPushButton *bt_cancel;

    void setupUi(QDialog *change_screentip)
    {
        if (change_screentip->objectName().isEmpty())
            change_screentip->setObjectName(QString::fromUtf8("change_screentip"));
        change_screentip->resize(300, 150);
        frame = new QFrame(change_screentip);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 300, 150));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        bt_ok = new QPushButton(frame);
        bt_ok->setObjectName(QString::fromUtf8("bt_ok"));
        bt_ok->setGeometry(QRect(30, 102, 75, 41));
        label_tip = new QLabel(frame);
        label_tip->setObjectName(QString::fromUtf8("label_tip"));
        label_tip->setGeometry(QRect(5, 10, 290, 60));
        label_tip->setAlignment(Qt::AlignCenter);
        bt_cancel = new QPushButton(frame);
        bt_cancel->setObjectName(QString::fromUtf8("bt_cancel"));
        bt_cancel->setGeometry(QRect(180, 102, 75, 41));

        retranslateUi(change_screentip);

        QMetaObject::connectSlotsByName(change_screentip);
    } // setupUi

    void retranslateUi(QDialog *change_screentip)
    {
        change_screentip->setWindowTitle(QCoreApplication::translate("change_screentip", "Dialog", nullptr));
        bt_ok->setText(QString());
        label_tip->setText(QString());
        bt_cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class change_screentip: public Ui_change_screentip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_SCREENTIP_H
