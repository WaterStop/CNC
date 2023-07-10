/********************************************************************************
** Form generated from reading UI file 'widget3.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET3_H
#define UI_WIDGET3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget3
{
public:
    QFrame *frame;
    QSlider *horizontalSlider;
    QLineEdit *edit_4;
    QLineEdit *edit_3;
    QLineEdit *edit_5;
    QLineEdit *edit_0;
    QLineEdit *edit_1;
    QLabel *zhuzhou;
    QLabel *pos_x0;
    QLabel *pos_z0;
    QLabel *pos_z1;
    QLabel *speed;
    QLabel *label_0;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *edit_2;

    void setupUi(QWidget *widget3)
    {
        if (widget3->objectName().isEmpty())
            widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->resize(293, 430);
        frame = new QFrame(widget3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 293, 430));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(170, 260, 80, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("AcadEref"));
        horizontalSlider->setFont(font);
        horizontalSlider->setMaximum(180);
        horizontalSlider->setValue(45);
        horizontalSlider->setOrientation(Qt::Horizontal);
        edit_4 = new QLineEdit(frame);
        edit_4->setObjectName(QString::fromUtf8("edit_4"));
        edit_4->setGeometry(QRect(170, 340, 112, 30));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edit_4->sizePolicy().hasHeightForWidth());
        edit_4->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        edit_4->setFont(font1);
        edit_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        edit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_3 = new QLineEdit(frame);
        edit_3->setObjectName(QString::fromUtf8("edit_3"));
        edit_3->setGeometry(QRect(170, 300, 112, 30));
        sizePolicy.setHeightForWidth(edit_3->sizePolicy().hasHeightForWidth());
        edit_3->setSizePolicy(sizePolicy);
        edit_3->setFont(font1);
        edit_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        edit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_5 = new QLineEdit(frame);
        edit_5->setObjectName(QString::fromUtf8("edit_5"));
        edit_5->setGeometry(QRect(170, 380, 112, 30));
        sizePolicy.setHeightForWidth(edit_5->sizePolicy().hasHeightForWidth());
        edit_5->setSizePolicy(sizePolicy);
        edit_5->setFont(font1);
        edit_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        edit_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_0 = new QLineEdit(frame);
        edit_0->setObjectName(QString::fromUtf8("edit_0"));
        edit_0->setGeometry(QRect(30, 300, 101, 30));
        sizePolicy.setHeightForWidth(edit_0->sizePolicy().hasHeightForWidth());
        edit_0->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("AcadEref"));
        font2.setPointSize(12);
        edit_0->setFont(font2);
        edit_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        edit_0->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_1 = new QLineEdit(frame);
        edit_1->setObjectName(QString::fromUtf8("edit_1"));
        edit_1->setGeometry(QRect(29, 340, 101, 30));
        sizePolicy.setHeightForWidth(edit_1->sizePolicy().hasHeightForWidth());
        edit_1->setSizePolicy(sizePolicy);
        edit_1->setFont(font1);
        edit_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        edit_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        zhuzhou = new QLabel(frame);
        zhuzhou->setObjectName(QString::fromUtf8("zhuzhou"));
        zhuzhou->setGeometry(QRect(40, 20, 85, 20));
        zhuzhou->setFont(font1);
        zhuzhou->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        zhuzhou->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pos_x0 = new QLabel(frame);
        pos_x0->setObjectName(QString::fromUtf8("pos_x0"));
        pos_x0->setGeometry(QRect(40, 60, 85, 20));
        pos_x0->setFont(font1);
        pos_x0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pos_x0->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pos_z0 = new QLabel(frame);
        pos_z0->setObjectName(QString::fromUtf8("pos_z0"));
        pos_z0->setGeometry(QRect(40, 100, 85, 20));
        pos_z0->setFont(font1);
        pos_z0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pos_z0->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pos_z1 = new QLabel(frame);
        pos_z1->setObjectName(QString::fromUtf8("pos_z1"));
        pos_z1->setGeometry(QRect(40, 140, 85, 20));
        pos_z1->setFont(font1);
        pos_z1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pos_z1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        speed = new QLabel(frame);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setGeometry(QRect(40, 180, 85, 20));
        speed->setFont(font1);
        speed->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        speed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_0 = new QLabel(frame);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setGeometry(QRect(0, 304, 31, 20));
        label_0->setFont(font1);
        label_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_0->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_1 = new QLabel(frame);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(0, 340, 31, 20));
        label_1->setFont(font1);
        label_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 390, 31, 20));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 300, 31, 20));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 340, 31, 20));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 390, 31, 20));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_2 = new QLineEdit(frame);
        edit_2->setObjectName(QString::fromUtf8("edit_2"));
        edit_2->setGeometry(QRect(30, 380, 101, 30));
        sizePolicy.setHeightForWidth(edit_2->sizePolicy().hasHeightForWidth());
        edit_2->setSizePolicy(sizePolicy);
        edit_2->setFont(font1);
        edit_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(60, 72, 102);"));
        edit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        horizontalSlider->raise();
        edit_4->raise();
        edit_5->raise();
        edit_0->raise();
        edit_1->raise();
        edit_3->raise();
        zhuzhou->raise();
        pos_x0->raise();
        pos_z0->raise();
        pos_z1->raise();
        speed->raise();
        label_0->raise();
        label_1->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        edit_2->raise();

        retranslateUi(widget3);

        QMetaObject::connectSlotsByName(widget3);
    } // setupUi

    void retranslateUi(QWidget *widget3)
    {
        widget3->setWindowTitle(QCoreApplication::translate("widget3", "Form", nullptr));
        zhuzhou->setText(QCoreApplication::translate("widget3", "2000mm", nullptr));
        pos_x0->setText(QCoreApplication::translate("widget3", "-2000.13mm", nullptr));
        pos_z0->setText(QCoreApplication::translate("widget3", "-40.14mm", nullptr));
        pos_z1->setText(QCoreApplication::translate("widget3", "-40.1522inch", nullptr));
        speed->setText(QCoreApplication::translate("widget3", "0.3mm/min", nullptr));
        label_0->setText(QString());
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widget3: public Ui_widget3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET3_H
