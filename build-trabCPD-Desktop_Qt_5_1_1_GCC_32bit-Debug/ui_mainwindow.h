/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QComboBox *sortA;
    QComboBox *sortB;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *arrayConfig;
    QPushButton *compareButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 202);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 381, 94));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        sortA = new QComboBox(groupBox);
        sortA->setObjectName(QStringLiteral("sortA"));

        verticalLayout->addWidget(sortA);

        sortB = new QComboBox(groupBox);
        sortB->setObjectName(QStringLiteral("sortB"));

        verticalLayout->addWidget(sortB);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 381, 61));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        arrayConfig = new QComboBox(groupBox_2);
        arrayConfig->setObjectName(QStringLiteral("arrayConfig"));

        verticalLayout_2->addWidget(arrayConfig);

        compareButton = new QPushButton(centralWidget);
        compareButton->setObjectName(QStringLiteral("compareButton"));
        compareButton->setGeometry(QRect(160, 170, 80, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "trabCPD", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Sorts:", 0));
        sortA->clear();
        sortA->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Insertion Sort", 0)
         << QApplication::translate("MainWindow", "Shell Sort", 0)
         << QApplication::translate("MainWindow", "Bubble Sort", 0)
         << QApplication::translate("MainWindow", "Heap Sort", 0)
        );
        sortB->clear();
        sortB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Insertion Sort", 0)
         << QApplication::translate("MainWindow", "Shell Sort", 0)
         << QApplication::translate("MainWindow", "Bubble Sort", 0)
         << QApplication::translate("MainWindow", "Heap Sort", 0)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\243o do Array:", 0));
        arrayConfig->clear();
        arrayConfig->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Aleat\303\263rio", 0)
         << QApplication::translate("MainWindow", "Ordenado", 0)
         << QApplication::translate("MainWindow", "Invertido", 0)
         << QApplication::translate("MainWindow", "Pr\303\251-definido", 0)
        );
        compareButton->setText(QApplication::translate("MainWindow", "Comparar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
