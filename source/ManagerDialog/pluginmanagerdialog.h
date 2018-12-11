#ifndef PLUGINMANAGERDIALOG_H
#define PLUGINMANAGERDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QUuid>
#include "Support/nofocusdelegate.h"

namespace Ui {
class PluginManagerDialog;
}

class PluginManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PluginManagerDialog(QWidget *parent = 0);
    ~PluginManagerDialog();
    QStandardItemModel *pluginListModel=new QStandardItemModel();

private slots:
    void on_pushButton_PluginSettingPanel_HideOrShow_clicked(bool checked);

    void on_pluginListWidget_clicked(const QModelIndex &index);

private:
    Ui::PluginManagerDialog *ui;
    void setPluginSettingPanelVisible(bool);
    void setPluginSettingPanelDataFromRow(int row);
};

#endif // PLUGINMANAGERDIALOG_H
