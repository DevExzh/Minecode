#ifndef AUTOHIDETABWIDGET_H
#define AUTOHIDETABWIDGET_H

#include <QTabWidget>
#include <QTabBar>

class AutoHideTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit AutoHideTabWidget(QWidget *parent = 0);

private slots:
    void onTabBarClicked(int);
};

#endif // AUTOHIDETABWIDGET_H
