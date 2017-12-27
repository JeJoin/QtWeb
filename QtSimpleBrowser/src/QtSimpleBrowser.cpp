#include "QtSimpleBrowser.h"
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qdebug.h>
#include <qwebenginepage.h>


QtSimpleBrowser::QtSimpleBrowser(QWidget *parent)
    : QMainWindow(parent)
    , m_menuBar(NULL)
    , m_toolBar(NULL)
{
    ui.setupUi(this);
    _initBrowserLayout();
}

void QtSimpleBrowser::_setupMune()
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

    // Edit
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    QAction *m_undo = editMenu->addAction(tr("&Undo"));
    m_undo->setShortcuts(QKeySequence::Undo);
    //m_tabWidget->addWebAction(m_undo, QWebEnginePage::Undo);
    QAction *m_redo = editMenu->addAction(tr("&Redo"));
    m_redo->setShortcuts(QKeySequence::Redo);
    //m_tabWidget->addWebAction(m_redo, QWebEnginePage::Redo);
    editMenu->addSeparator();
    QAction *m_cut = editMenu->addAction(tr("Cu&t"));
    m_cut->setShortcuts(QKeySequence::Cut);
    //m_tabWidget->addWebAction(m_cut, QWebEnginePage::Cut);
    QAction *m_copy = editMenu->addAction(tr("&Copy"));
    m_copy->setShortcuts(QKeySequence::Copy);
    //m_tabWidget->addWebAction(m_copy, QWebEnginePage::Copy);
    QAction *m_paste = editMenu->addAction(tr("&Paste"));
    m_paste->setShortcuts(QKeySequence::Paste);
    //m_tabWidget->addWebAction(m_paste, QWebEnginePage::Paste);
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

void QtSimpleBrowser::_initBrowserLayout()
{
    _setupMune();

}

void QtSimpleBrowser::_initWebEngine()
{
}

void QtSimpleBrowser::slotNewFile()
{
}
