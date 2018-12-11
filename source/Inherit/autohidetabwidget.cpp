#include "autohidetabwidget.h"

AutoHideTabWidget::AutoHideTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    connect(this,SIGNAL(tabBarClicked(int)),this,SLOT(onTabBarClicked(int)));
}

void AutoHideTabWidget::onTabBarClicked(int value)
{
    if(value==0)
    {
        this->setCurrentIndex(0);
        this->setMaximumWidth(26);
        this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    }
    else
    {
        this->setMaximumWidth(16777215);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
}
