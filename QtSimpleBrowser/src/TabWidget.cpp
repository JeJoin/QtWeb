#include <TabWidget.h>
#include <QMouseEvent>
#include <QApplication>
#include <QMimeData>
#include <QDrag>
#include <QShortcut>


TabBar::TabBar(QWidget * parent)
    : QTabBar(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setAcceptDrops(true);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(contextMenuRequested(QPoint)));

    QString ctrl = QLatin1String("Ctrl+%1");
    for (int i = 1; i < 10; ++i) {
        QShortcut *shortCut = new QShortcut(ctrl.arg(i), this);
        m_tabShortcuts.append(shortCut);
        connect(shortCut, SIGNAL(activated()), this, SLOT(selectTabAction()));
    }
    setMovable(true);
    setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);

    setTabsClosable(true);
    connect(this, SIGNAL(tabCloseRequested(int)), this, SIGNAL(closeTab(int)));
}
    
void TabBar::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->pos();
    }

    QTabBar::mousePressEvent(event);

    // Middle click on tab should close it.
    if (event->button() == Qt::MiddleButton) {
        const QPoint pos = event->pos();
        int index = tabAt(pos);
        if (index != -1) {
            emit closeTab(index);
        }
    }
}

void TabBar::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton) {
        int diffX = event->pos().x() - m_dragStartPos.x();
        int diffY = event->pos().y() - m_dragStartPos.y();
        int manhattLen = (event->pos() - m_dragStartPos).manhattanLength();
        if (manhattLen > QApplication::startDragDistance()
            && diffX < 3 && diffX > -3
            && diffY < -10) {
            QDrag *drag = new QDrag(this);
            QMimeData *mimeData = new QMimeData;
            QList<QUrl> urls;
            int index = tabAt(event->pos());
            QUrl url = tabData(index).toUrl();
            urls.append(url);
            mimeData->setUrls(urls);
            mimeData->setText(tabText(index));
            mimeData->setData(QLatin1String("action"), "tab-reordering");
            drag->setMimeData(mimeData);
            drag->exec();
        }
    }
    QTabBar::mouseMoveEvent(event);
}


TabWidget::TabWidget(QWidget* parent)
    :QTabWidget(parent)
    , m_tabBar(new TabBar(this))
{

}

TabWidget::~TabWidget()
{

}

void TabWidget::setUrl(const QUrl & url)
{

}

void TabWidget::triggerWebPageAction(QWebEnginePage::WebAction action)
{
}

void TabWidget::addWebAction(QAction *action, QWebEnginePage::WebAction webAction)
{

}

