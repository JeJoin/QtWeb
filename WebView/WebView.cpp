#include "WebView.h"
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qsplitter.h>
#include <QtWidgets/qtextedit.h>
#include <QtWebEngineWidgets/qwebengineview.h>
#include <QtWebEngineWidgets/qwebenginesettings.h>

WebView::WebView(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QHBoxLayout * hbox = new QHBoxLayout(this);
    QSplitter   * splitterMain = new QSplitter(Qt::Horizontal, this);

    QPushButton * pb  = new QPushButton(splitterMain);
    m_pWebEngineView  = new QWebEngineView(splitterMain);

    m_pWebEngineView->settings()->setAttribute(
        QWebEngineSettings::FullScreenSupportEnabled, true);

    //m_pWebEngineView->setUrl(QUrl(QStringLiteral("https://www.youku.com/")));
    //m_pWebEngineView->setUrl(QUrl(QStringLiteral("http://html5test.com")));
    //m_pWebEngineView->setUrl(QUrl(QStringLiteral("http://www.baidu.com")));
    m_pWebEngineView->setUrl(QUrl(QStringLiteral("https://v.youku.com/v_show/id_XMzE5MTI5NzIyMA==.html?spm=a2hww.20027244.m_250379.5~1~3~A")));


    //QTextEdit *textLeft = new QTextEdit(QObject::tr("letf"), splitterMain);
    //textLeft->setAlignment(Qt::AlignCenter);

    //QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);       //右分割窗口，并以主分割窗口作为父窗口  
    //splitterRight->setOpaqueResize(false);

    //QTextEdit *textUp = new QTextEdit(QObject::tr("up"), splitterRight);
    //textUp->setAlignment(Qt::AlignCenter);

    //QTextEdit *textMiddle = new QTextEdit(QObject::tr("middle"), splitterRight);
    //textMiddle->setAlignment(Qt::AlignCenter);

    //QTextEdit *textBottom = new QTextEdit(QObject::tr("buttom"), splitterRight);
    //textBottom->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(1, 1);
    splitterMain->setWindowTitle(QObject::tr("splitter"));
    
    pb->setText("push button");

    hbox->addWidget(splitterMain);

    this->setLayout(hbox);

    connect(pb, SIGNAL(clicked()), this, SLOT(Printf()));
    connect(m_pWebEngineView->page(), 
        SIGNAL(fullScreenRequested(QWebEngineFullScreenRequest fullScreenRequest)), 
        this, SLOT(slotFullScreenRequested()));
}

void WebView::slotFullScreenRequested(QWebEngineFullScreenRequest request)
{
    if (request.toggleOn()) {
        if (m_fullScreenWindow)
            return;
        request.accept();
        m_fullScreenWindow.reset(new FullScreenWindow(m_pWebEngineView));
    }
    else {
        if (!m_fullScreenWindow)
            return;
        request.accept();
        m_fullScreenWindow.reset();
    }
}

void WebView::Printf()
{
}