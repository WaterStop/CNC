/********************************************************************************
** Form generated from reading UI file 'key_board.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEY_BOARD_H
#define UI_KEY_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_key_board
{
public:
    QFrame *frame;
    QPushButton *bt_num_2;
    QPushButton *bt_num_7;
    QPushButton *bt_num_0;
    QPushButton *bt_num_point;
    QPushButton *bt_num_5;
    QPushButton *bt_num_3;
    QPushButton *bt_num_6;
    QPushButton *bt_num_9;
    QPushButton *bt_num_4;
    QPushButton *bt_enter;
    QPushButton *bt_num_1;
    QPushButton *bt_num_8;
    QPushButton *bt_back;

    void setupUi(QWidget *key_board)
    {
        if (key_board->objectName().isEmpty())
            key_board->setObjectName(QString::fromUtf8("key_board"));
        key_board->resize(291, 205);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(key_board->sizePolicy().hasHeightForWidth());
        key_board->setSizePolicy(sizePolicy);
        frame = new QFrame(key_board);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 291, 205));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        bt_num_2 = new QPushButton(frame);
        bt_num_2->setObjectName(QString::fromUtf8("bt_num_2"));
        bt_num_2->setGeometry(QRect(75, 103, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_2->sizePolicy().hasHeightForWidth());
        bt_num_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        bt_num_2->setFont(font);
        bt_num_2->setFocusPolicy(Qt::NoFocus);
        bt_num_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_7 = new QPushButton(frame);
        bt_num_7->setObjectName(QString::fromUtf8("bt_num_7"));
        bt_num_7->setGeometry(QRect(5, 3, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_7->sizePolicy().hasHeightForWidth());
        bt_num_7->setSizePolicy(sizePolicy);
        bt_num_7->setFont(font);
        bt_num_7->setFocusPolicy(Qt::NoFocus);
        bt_num_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(6, 22, 64);\n"
"border:1px solid #505b7a;"));
        bt_num_0 = new QPushButton(frame);
        bt_num_0->setObjectName(QString::fromUtf8("bt_num_0"));
        bt_num_0->setGeometry(QRect(5, 153, 141, 48));
        sizePolicy.setHeightForWidth(bt_num_0->sizePolicy().hasHeightForWidth());
        bt_num_0->setSizePolicy(sizePolicy);
        bt_num_0->setFont(font);
        bt_num_0->setFocusPolicy(Qt::NoFocus);
        bt_num_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_point = new QPushButton(frame);
        bt_num_point->setObjectName(QString::fromUtf8("bt_num_point"));
        bt_num_point->setGeometry(QRect(145, 153, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_point->sizePolicy().hasHeightForWidth());
        bt_num_point->setSizePolicy(sizePolicy);
        bt_num_point->setFont(font);
        bt_num_point->setFocusPolicy(Qt::NoFocus);
        bt_num_point->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_5 = new QPushButton(frame);
        bt_num_5->setObjectName(QString::fromUtf8("bt_num_5"));
        bt_num_5->setGeometry(QRect(75, 53, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_5->sizePolicy().hasHeightForWidth());
        bt_num_5->setSizePolicy(sizePolicy);
        bt_num_5->setFont(font);
        bt_num_5->setFocusPolicy(Qt::NoFocus);
        bt_num_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_3 = new QPushButton(frame);
        bt_num_3->setObjectName(QString::fromUtf8("bt_num_3"));
        bt_num_3->setGeometry(QRect(145, 103, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_3->sizePolicy().hasHeightForWidth());
        bt_num_3->setSizePolicy(sizePolicy);
        bt_num_3->setFont(font);
        bt_num_3->setFocusPolicy(Qt::NoFocus);
        bt_num_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_6 = new QPushButton(frame);
        bt_num_6->setObjectName(QString::fromUtf8("bt_num_6"));
        bt_num_6->setGeometry(QRect(145, 53, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_6->sizePolicy().hasHeightForWidth());
        bt_num_6->setSizePolicy(sizePolicy);
        bt_num_6->setFont(font);
        bt_num_6->setFocusPolicy(Qt::NoFocus);
        bt_num_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_9 = new QPushButton(frame);
        bt_num_9->setObjectName(QString::fromUtf8("bt_num_9"));
        bt_num_9->setGeometry(QRect(145, 3, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_9->sizePolicy().hasHeightForWidth());
        bt_num_9->setSizePolicy(sizePolicy);
        bt_num_9->setFont(font);
        bt_num_9->setFocusPolicy(Qt::NoFocus);
        bt_num_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_4 = new QPushButton(frame);
        bt_num_4->setObjectName(QString::fromUtf8("bt_num_4"));
        bt_num_4->setGeometry(QRect(5, 53, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_4->sizePolicy().hasHeightForWidth());
        bt_num_4->setSizePolicy(sizePolicy);
        bt_num_4->setFont(font);
        bt_num_4->setFocusPolicy(Qt::NoFocus);
        bt_num_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_enter = new QPushButton(frame);
        bt_enter->setObjectName(QString::fromUtf8("bt_enter"));
        bt_enter->setGeometry(QRect(215, 103, 69, 101));
        bt_enter->setFocusPolicy(Qt::NoFocus);
        bt_num_1 = new QPushButton(frame);
        bt_num_1->setObjectName(QString::fromUtf8("bt_num_1"));
        bt_num_1->setGeometry(QRect(5, 103, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_1->sizePolicy().hasHeightForWidth());
        bt_num_1->setSizePolicy(sizePolicy);
        bt_num_1->setFont(font);
        bt_num_1->setFocusPolicy(Qt::NoFocus);
        bt_num_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_num_8 = new QPushButton(frame);
        bt_num_8->setObjectName(QString::fromUtf8("bt_num_8"));
        bt_num_8->setGeometry(QRect(75, 3, 69, 48));
        sizePolicy.setHeightForWidth(bt_num_8->sizePolicy().hasHeightForWidth());
        bt_num_8->setSizePolicy(sizePolicy);
        bt_num_8->setFont(font);
        bt_num_8->setFocusPolicy(Qt::NoFocus);
        bt_num_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_back = new QPushButton(frame);
        bt_back->setObjectName(QString::fromUtf8("bt_back"));
        bt_back->setGeometry(QRect(215, 3, 69, 101));
        sizePolicy.setHeightForWidth(bt_back->sizePolicy().hasHeightForWidth());
        bt_back->setSizePolicy(sizePolicy);
        bt_back->setFocusPolicy(Qt::NoFocus);

        retranslateUi(key_board);

        QMetaObject::connectSlotsByName(key_board);
    } // setupUi

    void retranslateUi(QWidget *key_board)
    {
        key_board->setWindowTitle(QCoreApplication::translate("key_board", "Form", nullptr));
        bt_num_2->setText(QString());
        bt_num_7->setText(QString());
        bt_num_0->setText(QString());
        bt_num_point->setText(QString());
        bt_num_5->setText(QString());
        bt_num_3->setText(QString());
        bt_num_6->setText(QString());
        bt_num_9->setText(QString());
        bt_num_4->setText(QString());
        bt_enter->setText(QString());
        bt_num_1->setText(QString());
        bt_num_8->setText(QString());
        bt_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class key_board: public Ui_key_board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEY_BOARD_H
