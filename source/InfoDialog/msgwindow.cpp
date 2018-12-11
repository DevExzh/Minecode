#include "msgwindow.h"
#include "ui_msgwindow.h"

MsgWindow::MsgWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MsgWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
}

MsgWindow::~MsgWindow()
{
    delete ui;
}

void MsgWindow::on_yesButton_clicked()
{
    emit yes();
    this->close();
}
