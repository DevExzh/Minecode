#ifndef MCEDITORTOOLBOXSPLITTER_H
#define MCEDITORTOOLBOXSPLITTER_H

#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QMap>
#include <QList>

#include "mceditortoolbox.h"

class mcEditorToolBoxSplitter : public QWidget
{
    Q_OBJECT
public:
    explicit mcEditorToolBoxSplitter(QWidget *parent = nullptr);
    void addTool(mcEditorToolBox *tool);
    void addTool(const QList<mcEditorToolBox*> &tools);

private:
    QWidget* registerToolWidget(mcEditorToolBox *tool);

protected:
    QSplitter *_toolSplitter;
    QMap<int,mcEditorToolBox*> _toolBox_indexMap;
    QMap<QString,QPushButton*> _button_resources;
};

#endif // MCEDITORTOOLBOXSPLITTER_H
