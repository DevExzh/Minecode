#include "mcpgeneralpage.h"
#include "ui_mcpgeneralpage.h"

mcpGeneralPage::mcpGeneralPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcpGeneralPage)
{
    ui->setupUi(this);
}

mcpGeneralPage::~mcpGeneralPage()
{
    delete ui;
}
