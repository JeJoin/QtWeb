#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSimpleBrowser.h"


class QToolBar;
class QMenuBar;

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

private:
    Ui::QtSimpleBrowserClass ui;

    QMenuBar *      m_menuBar;
    QToolBar *      m_toolBar;

    QAction *       m_historyBack;


};
