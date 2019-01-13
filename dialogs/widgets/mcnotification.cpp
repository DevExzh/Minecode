#include "mcnotification.h"
#include "ui_mcnotification.h"

mcNotification::mcNotification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcNotification)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::Popup|Qt::FramelessWindowHint);
}

mcNotification::~mcNotification()
{
    delete ui;
}

void mcNotification::switchPage(const QString &page)
{
    if(page=="Warning")
    {
        ui->pageContainer->setCurrentIndex(0);
    }
    else if(page=="Error")
    {
        ui->pageContainer->setCurrentIndex(1);
    }
    else if(page=="Information")
    {
        ui->pageContainer->setCurrentIndex(2);
    }
}
