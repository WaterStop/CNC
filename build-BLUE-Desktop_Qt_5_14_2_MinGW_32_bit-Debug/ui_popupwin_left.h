/********************************************************************************
** Form generated from reading UI file 'popupwin_left.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPWIN_LEFT_H
#define UI_POPUPWIN_LEFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_popupwin_left
{
public:
    QFrame *frame;

    void setupUi(QWidget *popupwin_left)
    {
        if (popupwin_left->objectName().isEmpty())
            popupwin_left->setObjectName(QString::fromUtf8("popupwin_left"));
        popupwin_left->resize(239, 42);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(popupwin_left->sizePolicy().hasHeightForWidth());
        popupwin_left->setSizePolicy(sizePolicy);
        frame = new QFrame(popupwin_left);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 239, 42));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(popupwin_left);

        QMetaObject::connectSlotsByName(popupwin_left);
    } // setupUi

    void retranslateUi(QWidget *popupwin_left)
    {
        popupwin_left->setWindowTitle(QCoreApplication::translate("popupwin_left", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class popupwin_left: public Ui_popupwin_left {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPWIN_LEFT_H
