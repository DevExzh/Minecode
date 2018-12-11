#ifndef PROJECTBUILDOPTIONDIALOG_H
#define PROJECTBUILDOPTIONDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class ProjectBuildOptionDialog;
}

class ProjectBuildOptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectBuildOptionDialog(QWidget *parent = 0);
    ~ProjectBuildOptionDialog();
    QStandardItemModel *modelBuildType = new QStandardItemModel(this);
    QStandardItemModel *modelBuildKit = new QStandardItemModel(this);

private:
    Ui::ProjectBuildOptionDialog *ui;

signals:
    void formClosing();
    void buildTypeChanged(QString);
    void buildKitChanged(QString);

protected:
    void focusOutEvent(QFocusEvent *event);

private slots:
    void on_listBuildType_activated(const QModelIndex &index);
};

#endif // PROJECTBUILDOPTIONDIALOG_H
