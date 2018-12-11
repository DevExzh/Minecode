#ifndef SWITCHPLDIALOG_H
#define SWITCHPLDIALOG_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>

namespace Ui {
class SwitchPLDialog;
}

class SwitchPLDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SwitchPLDialog(QWidget *parent = 0);
    ~SwitchPLDialog();

private slots:
    void on_searchBox_textChanged(const QString &arg1);

private:
    Ui::SwitchPLDialog *ui;
};

#endif // SWITCHPLDIALOG_H
