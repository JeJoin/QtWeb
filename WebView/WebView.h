#pragma once

#include "ui_WebView.h"
#include <fullscreenwindow.h>
#include <QtWidgets/QWidget>
#include <QtWebEngineWidgets/qwebengineview.h>
#include <QtWebEngineWidgets/qwebenginefullscreenrequest.h>

class QLabel;
class QWebEngineView;

class WebView : public QWidget
{
    Q_OBJECT

public:
    WebView(QWidget *parent = Q_NULLPTR);

public slots:
    void Printf();
    void slotFullScreenRequested(QWebEngineFullScreenRequest request);

private:
    Ui::WebViewClass ui;
    QLabel * m_pLabel;
    QWebEngineView* m_pWebEngineView;
    QScopedPointer<FullScreenWindow> m_fullScreenWindow;
};
