#include "mcpenvironmentpage.h"
#include "ui_mcpenvironmentpage.h"

mcpEnvironmentPage::mcpEnvironmentPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcpEnvironmentPage)
{
    ui->setupUi(this);
}

mcpEnvironmentPage::~mcpEnvironmentPage()
{
    delete ui;
}
