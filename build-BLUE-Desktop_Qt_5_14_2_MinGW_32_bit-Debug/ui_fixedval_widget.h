/********************************************************************************
** Form generated from reading UI file 'fixedval_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIXEDVAL_WIDGET_H
#define UI_FIXEDVAL_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FixedVal_widget
{
public:
    QFrame *frame;
    QPushButton *bt_val_0;
    QPushButton *bt_lastpage;
    QPushButton *bt_nextpage;
    QPushButton *bt_val_1;
    QPushButton *bt_val_2;

    void setupUi(QWidget *FixedVal_widget)
    {
        if (FixedVal_widget->objectName().isEmpty())
            FixedVal_widget->setObjectName(QString::fromUtf8("FixedVal_widget"));
        FixedVal_widget->resize(293, 70);
        frame = new QFrame(FixedVal_widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 293, 70));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        bt_val_0 = new QPushButton(frame);
        bt_val_0->setObjectName(QString::fromUtf8("bt_val_0"));
        bt_val_0->setGeometry(QRect(40, 0, 70, 70));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        bt_val_0->setFont(font);
        bt_val_0->setFocusPolicy(Qt::NoFocus);
        bt_val_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_lastpage = new QPushButton(frame);
        bt_lastpage->setObjectName(QString::fromUtf8("bt_lastpage"));
        bt_lastpage->setGeometry(QRect(0, 0, 40, 70));
        bt_lastpage->setFocusPolicy(Qt::NoFocus);
        bt_nextpage = new QPushButton(frame);
        bt_nextpage->setObjectName(QString::fromUtf8("bt_nextpage"));
        bt_nextpage->setGeometry(QRect(253, 0, 40, 70));
        bt_nextpage->setFocusPolicy(Qt::NoFocus);
        bt_val_1 = new QPushButton(frame);
        bt_val_1->setObjectName(QString::fromUtf8("bt_val_1"));
        bt_val_1->setGeometry(QRect(110, 0, 70, 70));
        bt_val_1->setFont(font);
        bt_val_1->setFocusPolicy(Qt::NoFocus);
        bt_val_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_val_2 = new QPushButton(frame);
        bt_val_2->setObjectName(QString::fromUtf8("bt_val_2"));
        bt_val_2->setGeometry(QRect(180, 0, 70, 70));
        bt_val_2->setFont(font);
        bt_val_2->setFocusPolicy(Qt::NoFocus);
        bt_val_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(FixedVal_widget);

        QMetaObject::connectSlotsByName(FixedVal_widget);
    } // setupUi

    void retranslateUi(QWidget *FixedVal_widget)
    {
        FixedVal_widget->setWindowTitle(QCoreApplication::translate("FixedVal_widget", "Form", nullptr));
        bt_val_0->setText(QString());
        bt_lastpage->setText(QString());
        bt_nextpage->setText(QString());
        bt_val_1->setText(QString());
        bt_val_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FixedVal_widget: public Ui_FixedVal_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIXEDVAL_WIDGET_H
