#include "switchpldialog.h"
#include "ui_switchpldialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

SwitchPLDialog::SwitchPLDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwitchPLDialog)
{
    ui->setupUi(this);
}

SwitchPLDialog::~SwitchPLDialog()
{
    delete ui;
}

void SwitchPLDialog::on_searchBox_textChanged(const QString &arg1)
{

}
