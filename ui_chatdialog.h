/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatDialog
{
public:
    QTextBrowser *tb_chat;
    QTextEdit *te_chat;
    QPushButton *pb_send;
    QGroupBox *groupBox;
    QPushButton *pb_tool1;
    QPushButton *pb_tool2;
    QPushButton *pb_tool3;

    void setupUi(QWidget *chatDialog)
    {
        if (chatDialog->objectName().isEmpty())
            chatDialog->setObjectName(QStringLiteral("chatDialog"));
        chatDialog->resize(373, 379);
        chatDialog->setMinimumSize(QSize(373, 373));
        tb_chat = new QTextBrowser(chatDialog);
        tb_chat->setObjectName(QStringLiteral("tb_chat"));
        tb_chat->setGeometry(QRect(10, 10, 311, 211));
        te_chat = new QTextEdit(chatDialog);
        te_chat->setObjectName(QStringLiteral("te_chat"));
        te_chat->setGeometry(QRect(10, 250, 311, 91));
        pb_send = new QPushButton(chatDialog);
        pb_send->setObjectName(QStringLiteral("pb_send"));
        pb_send->setGeometry(QRect(250, 350, 75, 23));
        groupBox = new QGroupBox(chatDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 220, 101, 30));
        groupBox->setSizeIncrement(QSize(0, 0));
        pb_tool1 = new QPushButton(groupBox);
        pb_tool1->setObjectName(QStringLiteral("pb_tool1"));
        pb_tool1->setGeometry(QRect(0, 0, 30, 30));
        pb_tool2 = new QPushButton(groupBox);
        pb_tool2->setObjectName(QStringLiteral("pb_tool2"));
        pb_tool2->setGeometry(QRect(30, 0, 30, 30));
        pb_tool3 = new QPushButton(groupBox);
        pb_tool3->setObjectName(QStringLiteral("pb_tool3"));
        pb_tool3->setGeometry(QRect(60, 0, 30, 30));

        retranslateUi(chatDialog);

        QMetaObject::connectSlotsByName(chatDialog);
    } // setupUi

    void retranslateUi(QWidget *chatDialog)
    {
        chatDialog->setWindowTitle(QApplication::translate("chatDialog", "Form", 0));
        pb_send->setText(QApplication::translate("chatDialog", "\345\217\221\351\200\201", 0));
        groupBox->setTitle(QString());
        pb_tool1->setText(QString());
        pb_tool2->setText(QString());
        pb_tool3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chatDialog: public Ui_chatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
