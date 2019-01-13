#include "mcnavigatorcontrolitem.h"

mcNavigatorControlItem::mcNavigatorControlItem(QWidget *parent) :
    QWidget(parent),
    controlLayout(new QHBoxLayout),
    controlButton(new QPushButton),
    arrowButton(new QPushButton),
    arrowMenu(new QMenu)
{
    // 默认的样式表
    arrowButton->setStyleSheet("QPushButton{ background-color: transparent; border: 0px; border-radius: 0px; color: #fff; padding-left: 2px; padding-right: 2px; } QPushButton:hover{ background-color: rgba(255, 255, 255, 100); }");
    controlButton->setStyleSheet("QPushButton{ background-color: transparent; border: 0px; border-radius: 0px; color: #fff; padding-left: 10px; padding-right: 10px; } QPushButton:hover{ background-color: rgba(255, 255, 255, 100); }");

    arrowButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    controlButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    // 设置箭头
    arrowButton->setText(">");

    // 连接槽函数
    connect(arrowButton,&QPushButton::clicked,[=](){
        emit controlClicked(arrowButton);
        arrowMenu->show();
        emit arrowMenuQuested(arrowMenu);
    });
    connect(controlButton,&QPushButton::clicked,[=](){
        emit controlClicked(controlButton);
    });
    controlLayout->addWidget(controlButton);
    controlLayout->addWidget(arrowButton);
    this->setLayout(controlLayout);
    controlLayout->setContentsMargins(0,0,0,0);
    controlLayout->setSpacing(0);
}

QString mcNavigatorControlItem::controlProperty(const QString &key)
{
    return propertyTable[key];
}

void mcNavigatorControlItem::setArrowMenu(QMenu *menu)
{
    safedel(arrowMenu);
    arrowMenu=menu;
}

void mcNavigatorControlItem::setControlName(const QString &name)
{
    propertyTable["Name"]=name;
    controlButton->setText(name);
}

void mcNavigatorControlItem::setControlStyleSheet(const QString &style)
{
    propertyTable["StyleSheet"]=style;
    arrowButton->setStyleSheet(style);
    controlButton->setStyleSheet(style);
}

QSize mcNavigatorControlItem::arrowButtonSize()
{
    return arrowButton->size();
}
