/********************************************************************************
** Form generated from reading UI file 'QtSnakeTest.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSNAKETEST_H
#define UI_QTSNAKETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtSnakeTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtSnakeTestClass)
    {
        if (QtSnakeTestClass->objectName().isEmpty())
            QtSnakeTestClass->setObjectName(QStringLiteral("QtSnakeTestClass"));
        QtSnakeTestClass->resize(600, 400);
        menuBar = new QMenuBar(QtSnakeTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtSnakeTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtSnakeTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtSnakeTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtSnakeTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtSnakeTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtSnakeTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtSnakeTestClass->setStatusBar(statusBar);

        retranslateUi(QtSnakeTestClass);

        QMetaObject::connectSlotsByName(QtSnakeTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtSnakeTestClass)
    {
        QtSnakeTestClass->setWindowTitle(QApplication::translate("QtSnakeTestClass", "QtSnakeTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtSnakeTestClass: public Ui_QtSnakeTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSNAKETEST_H
