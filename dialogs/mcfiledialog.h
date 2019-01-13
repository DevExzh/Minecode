#ifndef MCFILEDIALOG_H
#define MCFILEDIALOG_H

#include <QWidget>
#include <QFileSystemModel>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include <QCompleter>

#include "delegate/nofocusdelegate.h"

namespace Ui {
class mcFileDialog;
}

class mcFileDialog : public QWidget
{
    Q_OBJECT

public:
    explicit mcFileDialog(QWidget *parent = 0);
    ~mcFileDialog();

private slots:
    void on_rightFileView_doubleClicked(const QModelIndex &index);

    void on_addressBox_currentTextChanged(const QString &arg1);

private:
    Ui::mcFileDialog *ui;
    QFileSystemModel *dirModel;
    NoFocusDelegate *delegate;
    QCompleter *addressCompleter;
};

#endif // MCFILEDIALOG_H
