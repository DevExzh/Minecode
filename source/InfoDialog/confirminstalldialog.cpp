#include "confirminstalldialog.h"
#include "ui_confirminstalldialog.h"

ConfirmInstallDialog::ConfirmInstallDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmInstallDialog)
{
    ui->setupUi(this);
}

ConfirmInstallDialog::~ConfirmInstallDialog()
{
    delete ui;
}
