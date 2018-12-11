#ifndef MINECODEDESIGNER_H
#define MINECODEDESIGNER_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QActionGroup>
#include <QTreeWidget>
#include "definition.h"
#include "layermapscence.h"
#include "minecodelayerview.h"
#include "LayerDesinger/newlayerdialog.h"

namespace Ui {
class MinecodeDesigner;
}

class MinecodeDesigner : public QMainWindow
{
    Q_OBJECT

public:
    explicit MinecodeDesigner(QWidget *parent = 0);
    ~MinecodeDesigner();

private:
    Ui::MinecodeDesigner *ui;
    //bool IsLoaded;
    QPointer<LayerMapScence> layerViewScence=NULL;
    QPointer<MinecodeLayerView> layerView=NULL;
    QMenu *newItemMenu=NULL;
    QPointer<QActionGroup> toolSelectGroup=NULL;
    QPointer<QActionGroup> dementionGroup=NULL;
    void setTreeWidgetStyle(QTreeWidget *wid);

public slots:
    void UIRetranslate();

public:
    //void LoadedStatusChanged();
    //void ReadProjectFile(QString);
    //void LoadTexturePack(QString);
    //void AddLayerViewItem(MinecodeType::CommandTextureType);
    void removeAll();
    QToolBar getToolBar();
    QMenuBar getMenuBar();

private slots:
    void on_actionMenu_Layer_triggered();
    void newItemMenu_CB_Impulse_DoAction();
    void newItemMenu_CB_Chain_DoAction();
    void newItemMenu_CB_Repeat_DoAction();
    void showNewItemMenu(const QPoint&);
    void selectToolChanged(QAction *action);
    void dementionChanged(QAction *action);
};

#endif // MINECODEDESIGNER_H
