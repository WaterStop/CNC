/********************************************************************************
** Form generated from reading UI file 'set_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_WIDGET_H
#define UI_SET_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_widget
{
public:
    QFrame *frame;
    QListView *listView;

    void setupUi(QWidget *set_widget)
    {
        if (set_widget->objectName().isEmpty())
            set_widget->setObjectName(QString::fromUtf8("set_widget"));
        set_widget->resize(899, 643);
        frame = new QFrame(set_widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 899, 643));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        listView = new QListView(frame);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(5, 5, 195, 630));

        retranslateUi(set_widget);

        QMetaObject::connectSlotsByName(set_widget);
    } // setupUi

    void retranslateUi(QWidget *set_widget)
    {
        set_widget->setWindowTitle(QCoreApplication::translate("set_widget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_widget: public Ui_set_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_WIDGET_H
