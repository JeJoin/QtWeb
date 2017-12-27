/********************************************************************************
** Form generated from reading UI file 'WebView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBVIEW_H
#define UI_WEBVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebViewClass
{
public:

    void setupUi(QWidget *WebViewClass)
    {
        if (WebViewClass->objectName().isEmpty())
            WebViewClass->setObjectName(QStringLiteral("WebViewClass"));
        WebViewClass->resize(600, 400);

        retranslateUi(WebViewClass);

        QMetaObject::connectSlotsByName(WebViewClass);
    } // setupUi

    void retranslateUi(QWidget *WebViewClass)
    {
        WebViewClass->setWindowTitle(QApplication::translate("WebViewClass", "WebView", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WebViewClass: public Ui_WebViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBVIEW_H
