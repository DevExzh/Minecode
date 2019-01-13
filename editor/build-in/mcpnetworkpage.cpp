#include "mcpnetworkpage.h"
#include "ui_mcpnetworkpage.h"

mcpNetworkPage::mcpNetworkPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcpNetworkPage)
{
    ui->setupUi(this);
}

mcpNetworkPage::~mcpNetworkPage()
{
    delete ui;
}
