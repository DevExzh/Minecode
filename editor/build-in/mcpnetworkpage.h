#ifndef MCPNETWORKPAGE_H
#define MCPNETWORKPAGE_H

#include <QWidget>

namespace Ui {
class mcpNetworkPage;
}

class mcpNetworkPage : public QWidget
{
    Q_OBJECT

public:
    explicit mcpNetworkPage(QWidget *parent = 0);
    ~mcpNetworkPage();

private:
    Ui::mcpNetworkPage *ui;
};

#endif // MCPNETWORKPAGE_H
