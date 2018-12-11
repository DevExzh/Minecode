#ifndef MSGWINDOW_H
#define MSGWINDOW_H

#include <QDialog>

namespace Ui {
class MsgWindow;
}

class MsgWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MsgWindow(QWidget *parent = 0);
    ~MsgWindow();

signals:
    void yes();

private slots:
    void on_yesButton_clicked();

private:
    Ui::MsgWindow *ui;
};

#endif // MSGWINDOW_H
