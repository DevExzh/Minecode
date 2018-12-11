#include "statisticaldatadialog.h"
#include "ui_statisticaldatadialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

StatisticalDataDialog::StatisticalDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticalDataDialog)
{
    ui->setupUi(this);
}

StatisticalDataDialog::~StatisticalDataDialog()
{
    delete ui;
}

void StatisticalDataDialog::SetFormStyleFromSignal(QString data)
{
    this->setStyleSheet(data);
}

void StatisticalDataDialog::SetFormFontFromSignal(QFont font)
{
    this->setFont(font);
}

void StatisticalDataDialog::UIRetranslate()
{
    this->ui->retranslateUi(this);
}
