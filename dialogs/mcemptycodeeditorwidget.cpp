#include "mcemptycodeeditorwidget.h"
#include "ui_mcemptycodeeditorwidget.h"

mcEmptyCodeEditorWidget::mcEmptyCodeEditorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcEmptyCodeEditorWidget)
{
    ui->setupUi(this);
}

mcEmptyCodeEditorWidget::~mcEmptyCodeEditorWidget()
{
    delete ui;
}

void mcEmptyCodeEditorWidget::closeEvent(QCloseEvent *event)
{
    if(!parentWidget()->isHidden())
        event->ignore();
}
