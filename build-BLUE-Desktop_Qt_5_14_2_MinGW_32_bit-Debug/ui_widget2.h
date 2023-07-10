/********************************************************************************
** Form generated from reading UI file 'widget2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET2_H
#define UI_WIDGET2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <popupwin.h>

QT_BEGIN_NAMESPACE

class Ui_widget2
{
public:
    QFrame *frame;
    QPushButton *b_but4;
    QLabel *label;
    PopupWin *widget;
    QPushButton *b_but3;
    QPushButton *t_but3;
    QPushButton *b_but;
    QPushButton *t_but4;
    QPushButton *t_but2;
    QPushButton *t_but5;
    QLabel *label_2;
    QPushButton *t_but;
    QPushButton *b_but2;
    QPushButton *l_but;
    QWidget *widget_2;
    QPushButton *t_but6;
    QLabel *knife_dir;

    void setupUi(QWidget *widget2)
    {
        if (widget2->objectName().isEmpty())
            widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->resize(464, 440);
        frame = new QFrame(widget2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 464, 440));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        b_but4 = new QPushButton(frame);
        b_but4->setObjectName(QString::fromUtf8("b_but4"));
        b_but4->setGeometry(QRect(348, 382, 38, 32));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(b_but4->sizePolicy().hasHeightForWidth());
        b_but4->setSizePolicy(sizePolicy);
        b_but4->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(17, 32, 16, 16));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        widget = new PopupWin(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 40, 100, 280));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        b_but3 = new QPushButton(frame);
        b_but3->setObjectName(QString::fromUtf8("b_but3"));
        b_but3->setGeometry(QRect(267, 382, 38, 32));
        sizePolicy.setHeightForWidth(b_but3->sizePolicy().hasHeightForWidth());
        b_but3->setSizePolicy(sizePolicy);
        b_but3->setFocusPolicy(Qt::NoFocus);
        t_but3 = new QPushButton(frame);
        t_but3->setObjectName(QString::fromUtf8("t_but3"));
        t_but3->setGeometry(QRect(140, 20, 30, 24));
        sizePolicy.setHeightForWidth(t_but3->sizePolicy().hasHeightForWidth());
        t_but3->setSizePolicy(sizePolicy);
        t_but3->setMinimumSize(QSize(30, 19));
        t_but3->setMaximumSize(QSize(39, 25));
        t_but3->setFocusPolicy(Qt::NoFocus);
        b_but = new QPushButton(frame);
        b_but->setObjectName(QString::fromUtf8("b_but"));
        b_but->setGeometry(QRect(97, 382, 38, 32));
        sizePolicy.setHeightForWidth(b_but->sizePolicy().hasHeightForWidth());
        b_but->setSizePolicy(sizePolicy);
        b_but->setFocusPolicy(Qt::NoFocus);
        t_but4 = new QPushButton(frame);
        t_but4->setObjectName(QString::fromUtf8("t_but4"));
        t_but4->setGeometry(QRect(180, 20, 39, 24));
        sizePolicy.setHeightForWidth(t_but4->sizePolicy().hasHeightForWidth());
        t_but4->setSizePolicy(sizePolicy);
        t_but4->setMinimumSize(QSize(30, 19));
        t_but4->setMaximumSize(QSize(39, 25));
        t_but4->setFocusPolicy(Qt::NoFocus);
        t_but2 = new QPushButton(frame);
        t_but2->setObjectName(QString::fromUtf8("t_but2"));
        t_but2->setGeometry(QRect(100, 20, 30, 24));
        sizePolicy.setHeightForWidth(t_but2->sizePolicy().hasHeightForWidth());
        t_but2->setSizePolicy(sizePolicy);
        t_but2->setMinimumSize(QSize(30, 19));
        t_but2->setMaximumSize(QSize(39, 25));
        t_but2->setFocusPolicy(Qt::NoFocus);
        t_but5 = new QPushButton(frame);
        t_but5->setObjectName(QString::fromUtf8("t_but5"));
        t_but5->setGeometry(QRect(220, 20, 39, 24));
        sizePolicy.setHeightForWidth(t_but5->sizePolicy().hasHeightForWidth());
        t_but5->setSizePolicy(sizePolicy);
        t_but5->setMinimumSize(QSize(30, 19));
        t_but5->setMaximumSize(QSize(39, 25));
        t_but5->setFocusPolicy(Qt::NoFocus);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(17, 99, 16, 16));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        t_but = new QPushButton(frame);
        t_but->setObjectName(QString::fromUtf8("t_but"));
        t_but->setGeometry(QRect(60, 20, 30, 24));
        sizePolicy.setHeightForWidth(t_but->sizePolicy().hasHeightForWidth());
        t_but->setSizePolicy(sizePolicy);
        t_but->setMinimumSize(QSize(30, 19));
        t_but->setMaximumSize(QSize(39, 25));
        t_but->setFocusPolicy(Qt::NoFocus);
        b_but2 = new QPushButton(frame);
        b_but2->setObjectName(QString::fromUtf8("b_but2"));
        b_but2->setGeometry(QRect(183, 382, 38, 32));
        sizePolicy.setHeightForWidth(b_but2->sizePolicy().hasHeightForWidth());
        b_but2->setSizePolicy(sizePolicy);
        b_but2->setFocusPolicy(Qt::NoFocus);
        l_but = new QPushButton(frame);
        l_but->setObjectName(QString::fromUtf8("l_but"));
        l_but->setGeometry(QRect(40, 220, 20, 55));
        sizePolicy.setHeightForWidth(l_but->sizePolicy().hasHeightForWidth());
        l_but->setSizePolicy(sizePolicy);
        l_but->setMinimumSize(QSize(20, 55));
        l_but->setMaximumSize(QSize(24, 66));
        l_but->setFocusPolicy(Qt::NoFocus);
        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(80, 60, 331, 261));
        t_but6 = new QPushButton(frame);
        t_but6->setObjectName(QString::fromUtf8("t_but6"));
        t_but6->setGeometry(QRect(260, 20, 39, 24));
        sizePolicy.setHeightForWidth(t_but6->sizePolicy().hasHeightForWidth());
        t_but6->setSizePolicy(sizePolicy);
        t_but6->setMinimumSize(QSize(30, 19));
        t_but6->setMaximumSize(QSize(39, 25));
        t_but6->setFocusPolicy(Qt::NoFocus);
        knife_dir = new QLabel(frame);
        knife_dir->setObjectName(QString::fromUtf8("knife_dir"));
        knife_dir->setGeometry(QRect(400, 340, 54, 12));
        b_but4->raise();
        label->raise();
        b_but3->raise();
        t_but3->raise();
        b_but->raise();
        t_but4->raise();
        t_but2->raise();
        t_but5->raise();
        label_2->raise();
        t_but->raise();
        b_but2->raise();
        l_but->raise();
        widget_2->raise();
        widget->raise();
        t_but6->raise();
        knife_dir->raise();

        retranslateUi(widget2);

        QMetaObject::connectSlotsByName(widget2);
    } // setupUi

    void retranslateUi(QWidget *widget2)
    {
        widget2->setWindowTitle(QCoreApplication::translate("widget2", "Form", nullptr));
        b_but4->setText(QString());
        label->setText(QString());
        b_but3->setText(QString());
        t_but3->setText(QString());
        b_but->setText(QString());
        t_but4->setText(QString());
        t_but2->setText(QString());
        t_but5->setText(QString());
        label_2->setText(QString());
        t_but->setText(QString());
        b_but2->setText(QString());
        l_but->setText(QString());
        t_but6->setText(QString());
        knife_dir->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widget2: public Ui_widget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET2_H
