#include "projectbuildoptiondialog.h"
#include "ui_projectbuildoptiondialog.h"

class MainWindow;

ProjectBuildOptionDialog::ProjectBuildOptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectBuildOptionDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);

    QStandardItem *itemDebug=new QStandardItem("Debug");
    QStandardItem *itemRelease=new QStandardItem("Release");
    modelBuildType->appendRow(itemDebug);
    modelBuildType->appendRow(itemRelease);

    QModelIndex itemDebugindex=itemDebug->index();

    ui->listBuildType->setModel(modelBuildType);
    ui->listBuildType->setCurrentIndex(itemDebugindex);
}

ProjectBuildOptionDialog::~ProjectBuildOptionDialog()
{
    delete ui;
}

void ProjectBuildOptionDialog::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    emit formClosing();
    this->close();
}

void ProjectBuildOptionDialog::on_listBuildType_activated(const QModelIndex &index)
{
    QStandardItem *tmpitem=modelBuildType->itemFromIndex(index);
    emit buildTypeChanged(tmpitem->text());
    ui->label_7->setText(tmpitem->text());
}
