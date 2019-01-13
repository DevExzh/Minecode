#ifndef MCNOTIFICATION_H
#define MCNOTIFICATION_H

#include <QWidget>

namespace Ui {
class mcNotification;
}

class mcNotification : public QWidget
{
    Q_OBJECT

public:
    explicit mcNotification(QWidget *parent = 0);
    void switchPage(const QString &page);
    ~mcNotification();

private:
    Ui::mcNotification *ui;
};

#endif // MCNOTIFICATION_H
