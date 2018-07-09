/********************************************************************************
** Form generated from reading UI file 'PinBallv05b0001.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINBALLV05B0001_H
#define UI_PINBALLV05B0001_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PinBallv05b0001Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PinBallv05b0001Class)
    {
        if (PinBallv05b0001Class->objectName().isEmpty())
            PinBallv05b0001Class->setObjectName(QStringLiteral("PinBallv05b0001Class"));
        PinBallv05b0001Class->resize(600, 400);
        menuBar = new QMenuBar(PinBallv05b0001Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PinBallv05b0001Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PinBallv05b0001Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PinBallv05b0001Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(PinBallv05b0001Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PinBallv05b0001Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PinBallv05b0001Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PinBallv05b0001Class->setStatusBar(statusBar);

        retranslateUi(PinBallv05b0001Class);

        QMetaObject::connectSlotsByName(PinBallv05b0001Class);
    } // setupUi

    void retranslateUi(QMainWindow *PinBallv05b0001Class)
    {
        PinBallv05b0001Class->setWindowTitle(QApplication::translate("PinBallv05b0001Class", "PinBallv05b0001", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PinBallv05b0001Class: public Ui_PinBallv05b0001Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINBALLV05B0001_H
