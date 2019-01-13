#include "mcaboutdialog.h"
#include "ui_mcaboutdialog.h"

mcAboutDialog::mcAboutDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcAboutDialog)
{
    ui->setupUi(this);
    ui->label_components_minecode_BuildDate->setText(MinecodeBuildDate);
}

mcAboutDialog::~mcAboutDialog()
{
    delete ui;
}
