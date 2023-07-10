/********************************************************************************
** Form generated from reading UI file 'popupwin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPWIN_H
#define UI_POPUPWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopupWin
{
public:
    QPushButton *pop_bt;
    QPushButton *pop_bt_1;
    QPushButton *pop_bt_2;
    QPushButton *pop_bt_3;
    QPushButton *pop_bt_4;
    QPushButton *pop_bt_5;

    void setupUi(QWidget *PopupWin)
    {
        if (PopupWin->objectName().isEmpty())
            PopupWin->setObjectName(QString::fromUtf8("PopupWin"));
        PopupWin->resize(100, 280);
        pop_bt = new QPushButton(PopupWin);
        pop_bt->setObjectName(QString::fromUtf8("pop_bt"));
        pop_bt->setGeometry(QRect(5, 10, 50, 47));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pop_bt->sizePolicy().hasHeightForWidth());
        pop_bt->setSizePolicy(sizePolicy);
        pop_bt_1 = new QPushButton(PopupWin);
        pop_bt_1->setObjectName(QString::fromUtf8("pop_bt_1"));
        pop_bt_1->setGeometry(QRect(5, 62, 50, 47));
        sizePolicy.setHeightForWidth(pop_bt_1->sizePolicy().hasHeightForWidth());
        pop_bt_1->setSizePolicy(sizePolicy);
        pop_bt_2 = new QPushButton(PopupWin);
        pop_bt_2->setObjectName(QString::fromUtf8("pop_bt_2"));
        pop_bt_2->setGeometry(QRect(5, 113, 50, 47));
        sizePolicy.setHeightForWidth(pop_bt_2->sizePolicy().hasHeightForWidth());
        pop_bt_2->setSizePolicy(sizePolicy);
        pop_bt_3 = new QPushButton(PopupWin);
        pop_bt_3->setObjectName(QString::fromUtf8("pop_bt_3"));
        pop_bt_3->setGeometry(QRect(5, 165, 50, 47));
        sizePolicy.setHeightForWidth(pop_bt_3->sizePolicy().hasHeightForWidth());
        pop_bt_3->setSizePolicy(sizePolicy);
        pop_bt_4 = new QPushButton(PopupWin);
        pop_bt_4->setObjectName(QString::fromUtf8("pop_bt_4"));
        pop_bt_4->setGeometry(QRect(5, 218, 50, 47));
        sizePolicy.setHeightForWidth(pop_bt_4->sizePolicy().hasHeightForWidth());
        pop_bt_4->setSizePolicy(sizePolicy);
        pop_bt_5 = new QPushButton(PopupWin);
        pop_bt_5->setObjectName(QString::fromUtf8("pop_bt_5"));
        pop_bt_5->setGeometry(QRect(60, 105, 30, 70));
        sizePolicy.setHeightForWidth(pop_bt_5->sizePolicy().hasHeightForWidth());
        pop_bt_5->setSizePolicy(sizePolicy);

        retranslateUi(PopupWin);

        QMetaObject::connectSlotsByName(PopupWin);
    } // setupUi

    void retranslateUi(QWidget *PopupWin)
    {
        PopupWin->setWindowTitle(QCoreApplication::translate("PopupWin", "Form", nullptr));
        pop_bt->setText(QString());
        pop_bt_1->setText(QString());
        pop_bt_2->setText(QString());
        pop_bt_3->setText(QString());
        pop_bt_4->setText(QString());
        pop_bt_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PopupWin: public Ui_PopupWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPWIN_H
