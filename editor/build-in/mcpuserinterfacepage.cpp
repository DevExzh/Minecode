#include "mcpuserinterfacepage.h"
#include "ui_mcpuserinterfacepage.h"

mcpUserInterfacePage::mcpUserInterfacePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcpUserInterfacePage)
{
    ui->setupUi(this);
}

mcpUserInterfacePage::~mcpUserInterfacePage()
{
    delete ui;
}
