#include "mceditortoolboxsplitter.h"

mcEditorToolBoxSplitter::mcEditorToolBoxSplitter(QWidget *parent) : QWidget(parent)
{
    mcEditorToolBox *projectTool=new mcEditorToolBox;
    mcEditorToolBox *openedDocTool=new mcEditorToolBox;
    _toolBox_indexMap[0]=projectTool;
    _toolBox_indexMap[1]=openedDocTool;
}

void mcEditorToolBoxSplitter::addTool(mcEditorToolBox *tool)
{
    _toolSplitter->addWidget(registerToolWidget(tool));
}

void mcEditorToolBoxSplitter::addTool(const QList<mcEditorToolBox *> &tools)
{
    for(auto tool:tools)
    {
        this->addTool(tool);
    }
}

QWidget* mcEditorToolBoxSplitter::registerToolWidget(mcEditorToolBox *tool)
{
    Q_UNUSED(tool);
    return nullptr;
}
