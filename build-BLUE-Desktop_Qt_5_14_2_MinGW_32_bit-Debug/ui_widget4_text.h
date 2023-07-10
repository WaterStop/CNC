/********************************************************************************
** Form generated from reading UI file 'widget4_text.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET4_TEXT_H
#define UI_WIDGET4_TEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget4_text
{
public:
    QFrame *frame;

    void setupUi(QWidget *widget4_text)
    {
        if (widget4_text->objectName().isEmpty())
            widget4_text->setObjectName(QString::fromUtf8("widget4_text"));
        widget4_text->resize(459, 206);
        frame = new QFrame(widget4_text);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 459, 206));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);

        retranslateUi(widget4_text);

        QMetaObject::connectSlotsByName(widget4_text);
    } // setupUi

    void retranslateUi(QWidget *widget4_text)
    {
        widget4_text->setWindowTitle(QCoreApplication::translate("widget4_text", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget4_text: public Ui_widget4_text {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET4_TEXT_H
