/********************************************************************************
** Form generated from reading UI file 'set_dgn.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_DGN_H
#define UI_SET_DGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_dgn
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_dgn)
    {
        if (set_dgn->objectName().isEmpty())
            set_dgn->setObjectName(QString::fromUtf8("set_dgn"));
        set_dgn->resize(691, 614);
        frame = new QFrame(set_dgn);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 691, 614));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);

        retranslateUi(set_dgn);

        QMetaObject::connectSlotsByName(set_dgn);
    } // setupUi

    void retranslateUi(QWidget *set_dgn)
    {
        set_dgn->setWindowTitle(QCoreApplication::translate("set_dgn", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_dgn: public Ui_set_dgn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_DGN_H
