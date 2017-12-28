#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSimpleBrowser.h"



class TabWidget;

class QtSimpleBrowser : public QMainWindow
{
    Q_OBJECT

public:
    QtSimpleBrowser(QWidget *parent = Q_NULLPTR);

public slots:
    void slotNewFile();

    
private:
    void _initBrowserLayout();
    void _initWebEngine();

    void _setupMune();
    void _initFileMenu();
    void _initEditMenu();
    void _initViewMenu();

    void _updateBookmarksToolbarActionText(bool visible);
    void _updateNavigationBarActionText(bool visible);

private:
    Ui::QtSimpleBrowserClass ui;
    TabWidget *     m_tabWidget;

    QAction *       m_historyBack;
    QAction *       m_hideBookmarkBar;
    QAction *       m_hideNavigationBar;
    QAction *       m_stop;
    QAction *       m_reload;


};
