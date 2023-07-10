/********************************************************************************
** Form generated from reading UI file 'key_board_2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEY_BOARD_2_H
#define UI_KEY_BOARD_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_key_board_2
{
public:
    QFrame *frame;

    void setupUi(QWidget *key_board_2)
    {
        if (key_board_2->objectName().isEmpty())
            key_board_2->setObjectName(QString::fromUtf8("key_board_2"));
        key_board_2->resize(561, 230);
        frame = new QFrame(key_board_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 680, 230));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);

        retranslateUi(key_board_2);

        QMetaObject::connectSlotsByName(key_board_2);
    } // setupUi

    void retranslateUi(QWidget *key_board_2)
    {
        key_board_2->setWindowTitle(QCoreApplication::translate("key_board_2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class key_board_2: public Ui_key_board_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEY_BOARD_2_H
