#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_ButtonOK_clicked()
{
    this->close();
}

void AboutDialog::on_ButtonDonate_clicked()
{
    ui->widgetContainer->setCurrentIndex(1);
}

void AboutDialog::on_ButtonBack_clicked()
{
    ui->widgetContainer->setCurrentIndex(0);
}
