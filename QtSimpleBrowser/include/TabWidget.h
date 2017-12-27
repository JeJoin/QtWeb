#ifndef __BROWSER_WIDGET_H__
#define __BROWSER_WIDGET_H__
#include <QTabWidget>
#include <QWebEnginePage>

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget* parent = NULL);
    virtual ~TabWidget();

signals:
    void loadProgress(int progress);
    void urlChanged(const QUrl & url);
    void linkHovered(const QString & link);
    void favIconChanged(const QIcon & icon);
    void titleChanged(const QString & title);
    void webActionEnabledChanged(QWebEnginePage::WebAction action, bool enabled);

public slots:
    void setUrl(const QUrl & url);
    void triggerWebPageAction(QWebEnginePage::WebAction action);

private:


};


#endif // __BROWSER_WIDGET_H__
