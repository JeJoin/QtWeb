#ifndef __FULLSCREENWINDOW_H__
#define __FULLSCREENWINDOW_H__

#include <QWidget>

QT_BEGIN_NAMESPACE
class QWebEngineView;
QT_END_NAMESPACE

class FullScreenNotification;

class FullScreenWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FullScreenWindow(QWebEngineView *oldView, QWidget *parent = nullptr);
    ~FullScreenWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QWebEngineView *m_view;
    FullScreenNotification *m_notification;
    QWebEngineView *m_oldView;
    QRect m_oldGeometry;
};
#endif // !__FULLSCREENWINDOW_H__
