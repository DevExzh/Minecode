#include "mcfiledialog.h"
#include "ui_mcfiledialog.h"

mcFileDialog::mcFileDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcFileDialog),
    dirModel(new QFileSystemModel),
    delegate(new NoFocusDelegate)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::Dialog);

    dirModel->setRootPath(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
    ui->leftFileView->setModel(dirModel);
    ui->leftFileView->setColumnHidden(1,true);
    ui->leftFileView->setColumnHidden(2,true);
    ui->leftFileView->setColumnHidden(3,true);
    ui->rightFileView->setModel(dirModel);
    ui->rightFileView->setRootIndex(dirModel->index(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)));

    connect(ui->leftFileView,&QTreeView::clicked,[=](const QModelIndex &index){
        if(dirModel->fileInfo(index).isFile())
        {
            ui->rightFileView->setRootIndex(dirModel->index(dirModel->fileInfo(index).absoluteDir().path()));
            ui->addressBox->setCurrentText(dirModel->fileInfo(index).path());
        }
        else if(dirModel->isDir(index))
        {
            ui->rightFileView->setRootIndex(index);
            ui->addressBox->setCurrentText(dirModel->fileInfo(index).path());
        }
    });

    addressCompleter=new QCompleter(dirModel);
    ui->addressBox->setCompleter(addressCompleter);
    ui->rightFileView->setItemDelegate(delegate);

    connect(addressCompleter,&QCompleter::destroyed,[=](){
        if(QFileInfo(ui->addressBox->currentText()).exists())
        {
            ui->leftFileView->selectionModel()->select(dirModel->index(ui->addressBox->currentText()),QItemSelectionModel::Select);
        }
    });
}

mcFileDialog::~mcFileDialog()
{
    delete ui;
}

void mcFileDialog::on_rightFileView_doubleClicked(const QModelIndex &index)
{
    if(dirModel->isDir(index))
    {
        ui->leftFileView->selectionModel()->select(index,QItemSelectionModel::Select);
    }
    else if(dirModel->fileInfo(index).isFile())
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(dirModel->fileInfo(index).absoluteFilePath()));
    }
}

void mcFileDialog::on_addressBox_currentTextChanged(const QString &arg1)
{
    if(QFileInfo(arg1).exists())
        ui->leftFileView->setCurrentIndex(dirModel->index(arg1));
}
