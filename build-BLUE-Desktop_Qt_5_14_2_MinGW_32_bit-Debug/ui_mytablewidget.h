/********************************************************************************
** Form generated from reading UI file 'mytablewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTABLEWIDGET_H
#define UI_MYTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTableWidget
{
public:

    void setupUi(QWidget *MyTableWidget)
    {
        if (MyTableWidget->objectName().isEmpty())
            MyTableWidget->setObjectName(QString::fromUtf8("MyTableWidget"));
        MyTableWidget->resize(400, 300);

        retranslateUi(MyTableWidget);

        QMetaObject::connectSlotsByName(MyTableWidget);
    } // setupUi

    void retranslateUi(QWidget *MyTableWidget)
    {
        MyTableWidget->setWindowTitle(QCoreApplication::translate("MyTableWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTableWidget: public Ui_MyTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTABLEWIDGET_H
