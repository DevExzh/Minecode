#include "mcpeditorpage.h"
#include "ui_mcpeditorpage.h"

mcpEditorPage::mcpEditorPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcpEditorPage)
{
    ui->setupUi(this);
}

mcpEditorPage::~mcpEditorPage()
{
    delete ui;
}
