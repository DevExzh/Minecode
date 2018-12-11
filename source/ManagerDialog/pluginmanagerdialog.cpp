#include "pluginmanagerdialog.h"
#include "ui_pluginmanagerdialog.h"

//#include <QDebug>

PluginManagerDialog::PluginManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PluginManagerDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowMaximizeButtonHint|Qt::WindowCloseButtonHint);
    setPluginSettingPanelVisible(false);
    // 初始化列表
    pluginListModel->setColumnCount(5);
    // 设置表头
    pluginListModel->setHeaderData(0,Qt::Horizontal,tr("Name"));
    pluginListModel->setHeaderData(1,Qt::Horizontal,tr("Author"));
    pluginListModel->setHeaderData(2,Qt::Horizontal,tr("Build Date"));
    pluginListModel->setHeaderData(3,Qt::Horizontal,tr("Version"));
    pluginListModel->setHeaderData(4,Qt::Horizontal,tr("Description"));

    pluginListModel->setItem(0,0,new QStandardItem("Minecode Studio"));
    pluginListModel->setItem(0,1,new QStandardItem("Exzh_PMGI"));
    pluginListModel->setItem(0,2,new QStandardItem("2018/10/03 21:16"));
    pluginListModel->setItem(0,3,new QStandardItem("Beta 1276"));
    pluginListModel->setItem(0,4,new QStandardItem("Minecode Studio Main Program"));

    pluginListModel->setItem(1,0,new QStandardItem("Minecode Designer"));
    pluginListModel->setItem(1,1,new QStandardItem("Exzh_PMGI"));
    pluginListModel->setItem(1,2,new QStandardItem("2018/10/03 21:16"));
    pluginListModel->setItem(1,3,new QStandardItem("Beta 1276"));
    pluginListModel->setItem(1,4,new QStandardItem("The Designer Tool of Minecode Studio"));

    ui->pluginListWidget->setModel(pluginListModel);
    ui->pluginListWidget->setItemDelegate(new NoFocusDelegate());

    for(int i=0;i<ui->pluginListWidget->horizontalHeader()->count()-1;++i)
    {
        ui->pluginListWidget->resizeColumnToContents(i);
        for(int j=0;j<pluginListModel->rowCount();j++)
        {
            pluginListModel->item(j,i)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

PluginManagerDialog::~PluginManagerDialog()
{
    delete ui;
}

/*
void PluginManagerDialog::addPluginInfoToList()
{
    pluginListModel->setItem(0,0,new QStandardItem());
}
*/

void PluginManagerDialog::on_pushButton_PluginSettingPanel_HideOrShow_clicked(bool checked)
{
    setPluginSettingPanelVisible(checked);
}

void PluginManagerDialog::setPluginSettingPanelVisible(bool boolean)
{
    ui->pluginInfoPanel->setVisible(boolean);
    if(boolean) ui->pushButton_PluginSettingPanel_HideOrShow->setText(tr("▼ Hide"));
    else ui->pushButton_PluginSettingPanel_HideOrShow->setText(tr("▲ Detail"));
}

inline void PluginManagerDialog::setPluginSettingPanelDataFromRow(int row)
{
    ui->label_PluginSettingPanel_Name->setText(pluginListModel->index(row,0).data().toString());
    ui->label_PluginSettingPanel_Author->setText(pluginListModel->index(row,1).data().toString());
    ui->label_PluginSettingPanel_BuildDate->setText(pluginListModel->index(row,2).data().toString());
    ui->label_PluginSettingPanel_Version->setText(pluginListModel->index(row,3).data().toString());
    ui->label_PluginSettingPanel_UUID->setText("< Unknown >");
    ui->label_PluginSettingPanel_Description->setText(pluginListModel->index(row,4).data().toString());
}

void PluginManagerDialog::on_pluginListWidget_clicked(const QModelIndex &index)
{
    setPluginSettingPanelDataFromRow(pluginListModel->itemFromIndex(index)->row());
    /*
    if(pluginListModel==nullptr)
        qDebug()<<"Pointer is NULL";
    else
        qDebug()<<"Pointer is not NULL";
*/
}
