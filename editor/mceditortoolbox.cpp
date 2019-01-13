#include "mceditortoolbox.h"

mcEditorToolBox::mcEditorToolBox(QWidget *parent) : QWidget(parent)
{

}

// 切换工具箱模式
void mcEditorToolBox::switchToolBoxMode(mcEditorTools view)
{
    mode=view;
    emit currentModeChanged(view);
    _viewMap.clear(); // 清空指针映射，节约内存
    switch (view) {
    case mcEditorTools::Project:
    {
        if(_toolBoxWidget != nullptr) safedel(_toolBoxWidget);
        _toolBoxWidget=new QWidget;
        if(!_viewMap[view].contains("layout"))
        {
            QVBoxLayout *layout=new QVBoxLayout;
            _viewMap[view][QStringLiteral("layout")]=dynamic_cast<QWidget*>(layout);
        }

        QVBoxLayout *projectLayout=dynamic_cast<QVBoxLayout*>(_viewMap[view][QStringLiteral("layout")]);
        safedel(projectLayout);
        projectLayout=new QVBoxLayout;
        QTreeView *projectTree=new QTreeView;
        projectLayout->addWidget(projectTree);
        _toolBoxWidget->setLayout(projectLayout);
        break;
    }
    case mcEditorTools::FileSystem:
    {
        break;
    }
    default:
        break;
    }
}

bool mcEditorToolBox::setCurrentModel(QStandardItemModel *model)
{
    if(_viewMap.isEmpty())
        return false;

    switch (mode) {
    case mcEditorTools::Project:
    {
        dynamic_cast<QTreeView*>(_viewMap[mode][QStringLiteral("treeView")])->setModel(model);
        break;
    }
    case mcEditorTools::FileSystem:
        return false;
    default:
        break;
    }

    return true;
}
