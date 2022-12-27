/********************************************************************************
** Form generated from reading UI file 'feiq.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEIQ_H
#define UI_FEIQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_FeiQ
{
public:
    QTableWidget *tw_friend;

    void setupUi(QDialog *FeiQ)
    {
        if (FeiQ->objectName().isEmpty())
            FeiQ->setObjectName(QStringLiteral("FeiQ"));
        FeiQ->resize(239, 445);
        FeiQ->setMaximumSize(QSize(239, 445));
        tw_friend = new QTableWidget(FeiQ);
        if (tw_friend->columnCount() < 2)
            tw_friend->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tw_friend->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tw_friend->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tw_friend->rowCount() < 1)
            tw_friend->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tw_friend->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tw_friend->setItem(0, 1, __qtablewidgetitem3);
        tw_friend->setObjectName(QStringLiteral("tw_friend"));
        tw_friend->setGeometry(QRect(10, 10, 221, 421));
        tw_friend->setMaximumSize(QSize(221, 421));
        tw_friend->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tw_friend->setRowCount(1);
        tw_friend->setColumnCount(2);
        tw_friend->horizontalHeader()->setDefaultSectionSize(150);
        tw_friend->horizontalHeader()->setStretchLastSection(true);
        tw_friend->verticalHeader()->setVisible(false);

        retranslateUi(FeiQ);

        QMetaObject::connectSlotsByName(FeiQ);
    } // setupUi

    void retranslateUi(QDialog *FeiQ)
    {
        FeiQ->setWindowTitle(QApplication::translate("FeiQ", "FeiQ", 0));
        QTableWidgetItem *___qtablewidgetitem = tw_friend->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FeiQ", "ip\345\234\260\345\235\200", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tw_friend->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FeiQ", "\344\270\273\346\234\272\345\220\215", 0));

        const bool __sortingEnabled = tw_friend->isSortingEnabled();
        tw_friend->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = tw_friend->item(0, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("FeiQ", "192.168.1.1", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tw_friend->item(0, 1);
        ___qtablewidgetitem3->setText(QApplication::translate("FeiQ", "\345\260\244\346\262\273\344\274\237", 0));
        tw_friend->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class FeiQ: public Ui_FeiQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEIQ_H
