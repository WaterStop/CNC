/********************************************************************************
** Form generated from reading UI file 'process_modify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS_MODIFY_H
#define UI_PROCESS_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Process_modify
{
public:
    QFrame *frame;
    QPushButton *bt_cut;
    QPushButton *bt_move;
    QPushButton *bt_copy;
    QPushButton *bt_del;
    QPushButton *bt_stick;
    QPushButton *bt_edit;
    QPushButton *bt_add;

    void setupUi(QWidget *Process_modify)
    {
        if (Process_modify->objectName().isEmpty())
            Process_modify->setObjectName(QString::fromUtf8("Process_modify"));
        Process_modify->resize(143, 311);
        frame = new QFrame(Process_modify);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 143, 311));
        frame->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        bt_cut = new QPushButton(frame);
        bt_cut->setObjectName(QString::fromUtf8("bt_cut"));
        bt_cut->setGeometry(QRect(40, 10, 65, 35));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bt_cut->sizePolicy().hasHeightForWidth());
        bt_cut->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        bt_cut->setFont(font);
        bt_cut->setFocusPolicy(Qt::NoFocus);
        bt_cut->setAutoRepeat(false);
        bt_cut->setAutoRepeatDelay(500);
        bt_move = new QPushButton(frame);
        bt_move->setObjectName(QString::fromUtf8("bt_move"));
        bt_move->setGeometry(QRect(40, 50, 65, 35));
        sizePolicy.setHeightForWidth(bt_move->sizePolicy().hasHeightForWidth());
        bt_move->setSizePolicy(sizePolicy);
        bt_move->setFont(font);
        bt_move->setFocusPolicy(Qt::NoFocus);
        bt_copy = new QPushButton(frame);
        bt_copy->setObjectName(QString::fromUtf8("bt_copy"));
        bt_copy->setGeometry(QRect(40, 90, 65, 35));
        sizePolicy.setHeightForWidth(bt_copy->sizePolicy().hasHeightForWidth());
        bt_copy->setSizePolicy(sizePolicy);
        bt_copy->setFont(font);
        bt_copy->setFocusPolicy(Qt::NoFocus);
        bt_del = new QPushButton(frame);
        bt_del->setObjectName(QString::fromUtf8("bt_del"));
        bt_del->setGeometry(QRect(40, 130, 65, 35));
        sizePolicy.setHeightForWidth(bt_del->sizePolicy().hasHeightForWidth());
        bt_del->setSizePolicy(sizePolicy);
        bt_del->setFont(font);
        bt_del->setFocusPolicy(Qt::NoFocus);
        bt_stick = new QPushButton(frame);
        bt_stick->setObjectName(QString::fromUtf8("bt_stick"));
        bt_stick->setGeometry(QRect(40, 170, 65, 35));
        sizePolicy.setHeightForWidth(bt_stick->sizePolicy().hasHeightForWidth());
        bt_stick->setSizePolicy(sizePolicy);
        bt_stick->setFont(font);
        bt_stick->setFocusPolicy(Qt::NoFocus);
        bt_edit = new QPushButton(frame);
        bt_edit->setObjectName(QString::fromUtf8("bt_edit"));
        bt_edit->setGeometry(QRect(40, 210, 65, 35));
        sizePolicy.setHeightForWidth(bt_edit->sizePolicy().hasHeightForWidth());
        bt_edit->setSizePolicy(sizePolicy);
        bt_edit->setFont(font);
        bt_edit->setFocusPolicy(Qt::NoFocus);
        bt_add = new QPushButton(frame);
        bt_add->setObjectName(QString::fromUtf8("bt_add"));
        bt_add->setGeometry(QRect(40, 250, 65, 35));
        sizePolicy.setHeightForWidth(bt_add->sizePolicy().hasHeightForWidth());
        bt_add->setSizePolicy(sizePolicy);
        bt_add->setFont(font);
        bt_add->setFocusPolicy(Qt::NoFocus);

        retranslateUi(Process_modify);

        QMetaObject::connectSlotsByName(Process_modify);
    } // setupUi

    void retranslateUi(QWidget *Process_modify)
    {
        Process_modify->setWindowTitle(QCoreApplication::translate("Process_modify", "Form", nullptr));
        bt_cut->setText(QString());
        bt_move->setText(QString());
        bt_copy->setText(QString());
        bt_del->setText(QString());
        bt_stick->setText(QString());
        bt_edit->setText(QString());
        bt_add->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Process_modify: public Ui_Process_modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_MODIFY_H
