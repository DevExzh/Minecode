#include "findandreplacedialog.h"
#include "ui_findandreplacedialog.h"

FindAndReplaceDialog::FindAndReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindAndReplaceDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
}

FindAndReplaceDialog::~FindAndReplaceDialog()
{
    delete ui;
}
