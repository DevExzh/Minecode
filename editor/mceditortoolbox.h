#ifndef MCEDITORTOOLBOX_H
#define MCEDITORTOOLBOX_H

#include <QWidget>
#include <QTreeView>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QMap>

#include "../exglobal.h"

import MinecodeCore;

enum mcEditorTools
{
    Project,
    OpenedDocument,
    Bookmark,
    FileSystem,
    ClassView,
    Dependence
};

class mcEditorToolBox : public QWidget
{
    Q_OBJECT
public:
    explicit mcEditorToolBox(QWidget *parent = nullptr);
    void switchToolBoxMode(mcEditorTools view);
    void setEditorLocation(const QString &dir){_location=dir;}
    bool setCurrentModel(QStandardItemModel *model);
    void setCurrentStyleSheet(const QString &style);

    QWidget* getToolBoxPointer(){return _toolBoxWidget;}

signals:
    void currentModeChanged(mcEditorTools toolMode);

protected:
    QWidget *_toolBoxWidget;
    QStandardItemModel *_current_model;
    QString _style,_location;
    QMap<mcEditorTools,QMap<QString,QWidget*> > _viewMap;
    mcEditorTools mode;
};

#endif // MCEDITORTOOLBOX_H
