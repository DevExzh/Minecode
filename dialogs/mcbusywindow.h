#ifndef MCBUSYWINDOW_H
#define MCBUSYWINDOW_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class mcBusyWindow;
}

class mcBusyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mcBusyWindow(QWidget *parent = 0);
    ~mcBusyWindow();

    void setMessage(const QString &msg);
    void setTitle(const QString &title);

private:
    Ui::mcBusyWindow *ui;

protected:
    QTimer *marqueeClock;
    bool isLeft;
};

#endif // MCBUSYWINDOW_H
