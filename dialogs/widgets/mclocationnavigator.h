#ifndef MCLOCATIONNAVIGATOR_H
#define MCLOCATIONNAVIGATOR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QHash>

#include "mcnavigatorcontrolitem.h"

class mcLocationNavigator : public QWidget
{
    Q_OBJECT
public:
    explicit mcLocationNavigator(QWidget *parent = nullptr);

signals:
    void locationEntered(const QString &path);
    void itemMenuQuested(QMenu *menu,const QPoint &itemPos);

public slots:
    void setCurrentLocation(const QString &path);
    //void cd(const QString &path);

protected:
    QHBoxLayout *controlContainer;
    QHash<QString,mcNavigatorControlItem*> itemTable;
    QHash<int,QString> itemTableIndex;
    void addController(const QString &name);
    int itemsWidth;
};

#endif // MCLOCATIONNAVIGATOR_H
