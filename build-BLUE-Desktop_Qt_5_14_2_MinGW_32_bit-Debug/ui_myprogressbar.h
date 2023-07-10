/********************************************************************************
** Form generated from reading UI file 'myprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPROGRESSBAR_H
#define UI_MYPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyProgressBar
{
public:
    QFrame *frame;
    QLabel *label_value;

    void setupUi(QWidget *MyProgressBar)
    {
        if (MyProgressBar->objectName().isEmpty())
            MyProgressBar->setObjectName(QString::fromUtf8("MyProgressBar"));
        MyProgressBar->resize(35, 315);
        frame = new QFrame(MyProgressBar);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 35, 350));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        label_value = new QLabel(frame);
        label_value->setObjectName(QString::fromUtf8("label_value"));
        label_value->setGeometry(QRect(0, 0, 35, 350));

        retranslateUi(MyProgressBar);

        QMetaObject::connectSlotsByName(MyProgressBar);
    } // setupUi

    void retranslateUi(QWidget *MyProgressBar)
    {
        MyProgressBar->setWindowTitle(QCoreApplication::translate("MyProgressBar", "Form", nullptr));
        label_value->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyProgressBar: public Ui_MyProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPROGRESSBAR_H
