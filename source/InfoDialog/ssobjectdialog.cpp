#include "ssobjectdialog.h"
#include "ui_ssobjectdialog.h"

SSObjectDialog::SSObjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SSObjectDialog)
{
    ui->setupUi(this);
}

SSObjectDialog::~SSObjectDialog()
{
    delete ui;
}
