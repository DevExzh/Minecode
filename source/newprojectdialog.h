#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>
#include <QStandardItemModel>

#include "minecodedesigner.h"
#include "eprocesswindow.h"

class MainWindow;

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

private:
    Ui::NewProjectDialog *ui;

public slots:
    void projectTypeView_SelectNodeChanged(QModelIndex,QModelIndex);

public:
        void LoadProjectTypeData();
        void SetMinecraftPanelVisibility(bool);

private slots:
        void SetFormStyleFromSignal(QString);
        void SetFormFontFromSignal(QFont);
        void UIRetranslate();
        void on_pushButton_Create_clicked();

        void on_cancelButton_clicked();

signals:
        void projectCreated();
};

#endif // NEWPROJECTDIALOG_H
