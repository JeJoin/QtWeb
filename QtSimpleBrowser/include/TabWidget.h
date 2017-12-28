#ifndef __BROWSER_WIDGET_H__
#define __BROWSER_WIDGET_H__
#include <QTabWidget>
#include <QWebEnginePage>

#include <QTabBar>

class TabBar : public QTabBar
{
    Q_OBJECT
signals :
    void newTab();
    void cloneTab(int index);
    void closeTab(int index);
    void closeOtherTabs(int index);
    void reloadTab(int index);
    void muteTab(int index, bool mute);
    void reloadAllTabs();
    void tabMoveRequested(int fromIndex, int toIndex);

public:
    TabBar(QWidget * parent = NULL);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private slots:
    //void selectTabAction();
    //void cloneTab();
    //void closeTab();
    //void closeOtherTabs();
    //void reloadTab();
    //void muteTab();
    //void unmuteTab();
    //void contextMenuRequested(const QPoint &position);

private:
    QList<QShortcut*> m_tabShortcuts;
    friend class TabWidget;

    QPoint m_dragStartPos;
    int m_dragCurrentIndex;
};



class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget* parent = NULL);
    virtual ~TabWidget();

    void addWebAction(QAction *action, QWebEnginePage::WebAction webAction);

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
    TabBar * m_tabBar;

};


#endif // __BROWSER_WIDGET_H__
