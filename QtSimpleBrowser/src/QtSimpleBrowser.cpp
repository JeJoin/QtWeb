#include "QtSimpleBrowser.h"
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qdebug.h>
#include <qwebenginepage.h>
#include <TabWidget.h>


QtSimpleBrowser::QtSimpleBrowser(QWidget *parent)
    : QMainWindow(parent)
    , m_tabWidget(new TabWidget(this))
    , m_hideBookmarkBar(NULL)
    , m_hideNavigationBar(NULL)
    , m_stop(NULL)
    , m_reload(NULL)
{
    ui.setupUi(this);
    _initBrowserLayout();
}

void QtSimpleBrowser::_setupMune()
{
    _initFileMenu();
    _initEditMenu();
    _initViewMenu();
}

void QtSimpleBrowser::_initBrowserLayout()
{
    setToolButtonStyle(Qt::ToolButtonFollowStyle);
    //setAttribute(Qt::WA_DeleteOnClose, true);
    statusBar()->setSizeGripEnabled(true);
    _setupMune();
}

void QtSimpleBrowser::_initWebEngine()
{
}

void QtSimpleBrowser::_updateBookmarksToolbarActionText(bool visible)
{
    m_hideBookmarkBar->setText(!visible ? tr("Show Bookmarks bar") 
                                        : tr("Hide Bookmarks bar"));
}

void QtSimpleBrowser::_updateNavigationBarActionText(bool visible)
{
    m_hideNavigationBar->setText(!visible ? tr("Show Navigation bar")
                                          : tr("Hide Navigation bar"));
}

void QtSimpleBrowser::_initEditMenu()
{
    // Edit
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    QAction *m_undo = editMenu->addAction(tr("&Undo"));
    m_undo->setShortcuts(QKeySequence::Undo);
    m_tabWidget->addWebAction(m_undo, QWebEnginePage::Undo);
    QAction *m_redo = editMenu->addAction(tr("&Redo"));
    m_redo->setShortcuts(QKeySequence::Redo);
    m_tabWidget->addWebAction(m_redo, QWebEnginePage::Redo);

    editMenu->addSeparator();

    QAction *m_cut = editMenu->addAction(tr("Cu&t"));
    m_cut->setShortcuts(QKeySequence::Cut);
    m_tabWidget->addWebAction(m_cut, QWebEnginePage::Cut);
    QAction *m_copy = editMenu->addAction(tr("&Copy"));
    m_copy->setShortcuts(QKeySequence::Copy);
    m_tabWidget->addWebAction(m_copy, QWebEnginePage::Copy);
    QAction *m_paste = editMenu->addAction(tr("&Paste"));
    m_paste->setShortcuts(QKeySequence::Paste);
    m_tabWidget->addWebAction(m_paste, QWebEnginePage::Paste);

    editMenu->addSeparator();

    QAction *m_find = editMenu->addAction(tr("&Find"));
    m_find->setShortcuts(QKeySequence::Find);
    connect(m_find, SIGNAL(triggered()), this, SLOT(slotEditFind()));

    QAction *m_findNext = editMenu->addAction(tr("&Find Next"));
    m_findNext->setShortcuts(QKeySequence::FindNext);
    connect(m_findNext, SIGNAL(triggered()), this, SLOT(slotEditFindNext()));

    QAction *m_findPrevious = editMenu->addAction(tr("&Find Previous"));
    m_findPrevious->setShortcuts(QKeySequence::FindPrevious);
    connect(m_findPrevious, SIGNAL(triggered()), this, SLOT(slotEditFindPrevious()));

    editMenu->addSeparator();

    editMenu->addAction(tr("&Preferences"), this, SLOT(slotPreferences()), tr("Ctrl+,"));
}

void QtSimpleBrowser::_initFileMenu()
{
    // File
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(tr("&New Window..."), 
        this, SLOT(slotFileNew()), 
        QKeySequence::New);

    fileMenu->addAction(tr("&Open File..."), 
        this, SLOT(slotFileOpen()),
        QKeySequence::Open);

    fileMenu->addAction(tr("Open &Location..."), 
        this, SLOT(slotSelectLineEdit()),
        QKeySequence(Qt::ControlModifier + Qt::Key_L));
    fileMenu->addSeparator();

    fileMenu->addAction(tr("&Save As..."), 
        this,SLOT(slotFileSaveAs()),
        QKeySequence(QKeySequence::Save));
    fileMenu->addSeparator();

    fileMenu->addAction(tr("&Print to PDF..."), 
        this, SLOT(slotFilePrintToPDF()));
    fileMenu->addSeparator();

    fileMenu->addAction(tr("&Quit"), 
        this, SLOT(close()), 
        QKeySequence(Qt::CTRL | Qt::Key_Q));
}
    
void QtSimpleBrowser::_initViewMenu()
{
    // View
    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    m_hideBookmarkBar = new QAction(this);
    _updateBookmarksToolbarActionText(true);
    m_hideBookmarkBar->setShortcut(tr("Shift+Ctrl+B"));
    viewMenu->addAction(m_hideBookmarkBar);

    connect(m_hideBookmarkBar, SIGNAL(triggered()), 
        this, SLOT(slotViewBookmarksBar()));

    m_hideNavigationBar = new QAction(this);
    _updateNavigationBarActionText(true);
    m_hideNavigationBar->setShortcut(tr("Ctrl+|"));
    viewMenu->addAction(m_hideNavigationBar);

    connect(m_hideNavigationBar, SIGNAL(triggered()), 
        this, SLOT(slotViewToolbar()));

    viewMenu->addSeparator();

    m_stop = viewMenu->addAction(tr("&Stop"));
    QList<QKeySequence> shortcuts;
    shortcuts.append(QKeySequence(Qt::CTRL | Qt::Key_Period));
    shortcuts.append(Qt::Key_Escape);
    m_stop->setShortcuts(shortcuts);
    m_tabWidget->addWebAction(m_stop, QWebEnginePage::Stop);

    m_reload = viewMenu->addAction(tr("Reload Page"));
    m_reload->setShortcuts(QKeySequence::Refresh);
    m_tabWidget->addWebAction(m_reload, QWebEnginePage::Reload);

    viewMenu->addAction(tr("Zoom &In"), 
        this, SLOT(slotViewZoomIn()), QKeySequence(Qt::CTRL | Qt::Key_Plus));
    viewMenu->addAction(tr("Zoom &Out"), 
        this, SLOT(slotViewZoomOut()), QKeySequence(Qt::CTRL | Qt::Key_Minus));
    viewMenu->addAction(tr("Reset &Zoom"),
        this, SLOT(slotViewResetZoom()), QKeySequence(Qt::CTRL | Qt::Key_0));

    viewMenu->addSeparator();

    QAction *pageSource = viewMenu->addAction(tr("Page S&ource"));
    pageSource->setShortcut(QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_U));
    m_tabWidget->addWebAction(pageSource, QWebEnginePage::ViewSource);

    QAction *fullScreen = viewMenu->addAction(tr("&Full Screen"), 
        this, SLOT(slotViewFullScreen(bool)), Qt::Key_F11);

    fullScreen->setCheckable(true);
}

void QtSimpleBrowser::slotNewFile()
{
}
