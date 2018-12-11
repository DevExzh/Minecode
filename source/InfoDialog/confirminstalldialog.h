#ifndef CONFIRMINSTALLDIALOG_H
#define CONFIRMINSTALLDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmInstallDialog;
}

class ConfirmInstallDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmInstallDialog(QWidget *parent = 0);
    ~ConfirmInstallDialog();

private:
    Ui::ConfirmInstallDialog *ui;
};

#endif // CONFIRMINSTALLDIALOG_H
