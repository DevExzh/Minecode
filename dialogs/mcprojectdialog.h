#ifndef MCPROJECTDIALOG_H
#define MCPROJECTDIALOG_H

#include <QWidget>
#include <QStandardItemModel>
#include <QCompleter>
#include <QStringListModel>

#include <Qsci/qscilexercpp.h>

#include "models/mcprojectdialogprivate.h"
#include "../editor/mceditor.h"
#include "mcbusywindow.h"

namespace Ui {
class mcProjectDialog;
}

class mcProjectDialog : public QWidget
{
    Q_OBJECT

public:
    explicit mcProjectDialog(QWidget *parent = 0);
    void setLanguageCompleterList(const QStringList &list);
    void setRecentLanguageList(const QList<QStandardItem *> &items);
    ~mcProjectDialog();

private:
    Ui::mcProjectDialog *ui;
    QStandardItem *pLanguageModel_Recent;
    QStringList completerList;
    QCompleter *languageCompleter;

    void createProject(const QString &fileName);

protected:
    mcProjectDialogPrivate *privateModels;

private slots:
    void on_viewportButton_List_clicked();
    void on_viewportButton_Icon_clicked();
};

#endif // MCPROJECTDIALOG_H
