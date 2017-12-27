#ifndef __FULLSCREENNOTYFICATION_H__
#define __FULLSCREENNOTYFICATION_H__

#include <QLabel>

class FullScreenNotification : public QLabel
{
    Q_OBJECT
public:
    FullScreenNotification(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *event) override;

signals:
    void shown();

private:
    bool m_previouslyVisible;
};

#endif // !__FULLSCREENNOTYFICATION_H__
