/********************************************************************************
** Form generated from reading UI file 'set_alm_note.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_ALM_NOTE_H
#define UI_SET_ALM_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_alm_note
{
public:
    QFrame *frame;

    void setupUi(QWidget *set_alm_note)
    {
        if (set_alm_note->objectName().isEmpty())
            set_alm_note->setObjectName(QString::fromUtf8("set_alm_note"));
        set_alm_note->resize(691, 614);
        frame = new QFrame(set_alm_note);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 691, 614));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);

        retranslateUi(set_alm_note);

        QMetaObject::connectSlotsByName(set_alm_note);
    } // setupUi

    void retranslateUi(QWidget *set_alm_note)
    {
        set_alm_note->setWindowTitle(QCoreApplication::translate("set_alm_note", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_alm_note: public Ui_set_alm_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_ALM_NOTE_H
