﻿#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private slots:
    void on_ButtonOK_clicked();

    void on_ButtonDonate_clicked();

    void on_ButtonBack_clicked();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H