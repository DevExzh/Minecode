#ifndef MCNAVIGATORCONTROLITEM_H
#define MCNAVIGATORCONTROLITEM_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenu>
#include <QHash>

#include "../../exglobal.h"

import MinecodeCore;

class mcNavigatorControlItem : public QWidget
{
    Q_OBJECT
public:
    explicit mcNavigatorControlItem(QWidget *parent = nullptr);
    QString controlProperty(const QString &key);

signals:
    void nameChanged(const QString &name);
    void arrowMenuQuested(QMenu *menu);
    void controlClicked(QPushButton *button);

public slots:
    void setControlStyleSheet(const QString &style);
    void setControlName(const QString &name);
    void setArrowMenu(QMenu *menu);
    QSize arrowButtonSize();

protected:
    QHBoxLayout *controlLayout;
    QPushButton *controlButton;
    QPushButton *arrowButton;
    QMenu *arrowMenu;
    QHash<QString,QString> propertyTable;
};

#endif // MCNAVIGATORCONTROLITEM_H
