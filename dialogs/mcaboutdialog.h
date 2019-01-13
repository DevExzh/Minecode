#ifndef MCABOUTDIALOG_H
#define MCABOUTDIALOG_H

#include <QWidget>
#include "exglobal.h"

namespace Ui {
class mcAboutDialog;
}

class mcAboutDialog : public QWidget
{
    Q_OBJECT

public:
    explicit mcAboutDialog(QWidget *parent = 0);
    ~mcAboutDialog();

private:
    Ui::mcAboutDialog *ui;
};

#endif // MCABOUTDIALOG_H
