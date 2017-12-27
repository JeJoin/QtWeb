#include "QtSimpleBrowser.h"
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qdebug.h>


QtSimpleBrowser::QtSimpleBrowser(QWidget *parent)
    : QMainWindow(parent)
    , m_menuBar(NULL)
    , m_toolBar(NULL)
{
    ui.setupUi(this);
    _initBrowserLayout();
}

void QtSimpleBrowser::_initBrowserLayout()
{
    m_menuBar = menuBar();

    // &File
    QMenu * pMenuFile = new QMenu(tr("File"), m_menuBar);
    pMenuFile->addAction(QIcon(""), tr("New File"));
    pMenuFile->addAction(QIcon(""), tr("Open"));
    pMenuFile->addAction(QIcon(""), tr("Save"));
    pMenuFile->addAction(QIcon(""), tr("Close"));

    // &Edit
    QMenu * pMenuEdit = new QMenu(tr("Edit"));
    pMenuEdit->addAction(QIcon(""), tr("Option"));

    // &Windows
    QMenu * pMenuWin = new QMenu(tr("Windows"));
    pMenuWin->addAction(QIcon(""), tr(""));

    // &Help
    QMenu * pMenuHelp = new QMenu(tr("Help"));
    pMenuHelp->addAction(QIcon(""), tr("About Us"));

    m_menuBar->addMenu(pMenuFile);
    m_menuBar->addMenu(pMenuEdit);
    m_menuBar->addMenu(pMenuWin);
    m_menuBar->addMenu(pMenuHelp);


}

void QtSimpleBrowser::_initWebEngine()
{

}
