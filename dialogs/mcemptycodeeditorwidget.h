#ifndef MCEMPTYCODEEDITORWIDGET_H
#define MCEMPTYCODEEDITORWIDGET_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class mcEmptyCodeEditorWidget;
}

class mcEmptyCodeEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mcEmptyCodeEditorWidget(QWidget *parent = 0);
    ~mcEmptyCodeEditorWidget();

private:
    Ui::mcEmptyCodeEditorWidget *ui;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MCEMPTYCODEEDITORWIDGET_H
