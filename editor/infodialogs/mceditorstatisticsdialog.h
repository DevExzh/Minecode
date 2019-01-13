#ifndef MCEDITORSTATISTICSDIALOG_H
#define MCEDITORSTATISTICSDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

#include "../mceditor.h"

class mcEditorStatisticsDialog : public QWidget
{
    Q_OBJECT
public:
    explicit mcEditorStatisticsDialog(QWidget *parent = nullptr);
    void setEditor(const mcEditor *editor);

protected:
    mcEditor *_editor;
    QVBoxLayout *infoLabelLayout;
    QHBoxLayout *infoLabelLayout_LineCount;
};

#endif // MCEDITORSTATISTICSDIALOG_H
