#ifndef NEWLAYERDIALOG_H
#define NEWLAYERDIALOG_H

#include <QDialog>
//#include "minecodedesigner.h"

namespace Ui {
class NewLayerDialog;
}

class NewLayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewLayerDialog(QWidget *parent = 0);
    ~NewLayerDialog();

private slots:
    void on_checkBox_UnlimitedSpace_clicked(bool checked);

    void on_checkBox_EnableOpenGL_clicked(bool checked);

    void on_pushButton_Create_clicked();

private:
    Ui::NewLayerDialog *ui;
};

#endif // NEWLAYERDIALOG_H
