#ifndef __WEB_VIEW_H__
#define __WEB_VIEW_H__
#include <QWebEngineView>

class WebView : public QWebEngineView
{
    Q_OBJECT

public: 
    WebView(QWidget * parent = NULL);
    virtual ~WebView();


};

#endif // !__WEB_VIEW_H__
