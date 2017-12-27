/********************************************************************************
** Form generated from reading UI file 'QtSimpleBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSIMPLEBROWSER_H
#define UI_QTSIMPLEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtSimpleBrowserClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtSimpleBrowserClass)
    {
        if (QtSimpleBrowserClass->objectName().isEmpty())
            QtSimpleBrowserClass->setObjectName(QStringLiteral("QtSimpleBrowserClass"));
        QtSimpleBrowserClass->resize(600, 400);
        menuBar = new QMenuBar(QtSimpleBrowserClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtSimpleBrowserClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtSimpleBrowserClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtSimpleBrowserClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtSimpleBrowserClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtSimpleBrowserClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtSimpleBrowserClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtSimpleBrowserClass->setStatusBar(statusBar);

        retranslateUi(QtSimpleBrowserClass);

        QMetaObject::connectSlotsByName(QtSimpleBrowserClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtSimpleBrowserClass)
    {
        QtSimpleBrowserClass->setWindowTitle(QApplication::translate("QtSimpleBrowserClass", "QtSimpleBrowser", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtSimpleBrowserClass: public Ui_QtSimpleBrowserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSIMPLEBROWSER_H
