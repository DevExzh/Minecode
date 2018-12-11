#ifndef SSOBJECTDIALOG_H
#define SSOBJECTDIALOG_H

#include <QDialog>

namespace Ui {
class SSObjectDialog;
}

class SSObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SSObjectDialog(QWidget *parent = 0);
    ~SSObjectDialog();

private:
    Ui::SSObjectDialog *ui;
};

#endif // SSOBJECTDIALOG_H
