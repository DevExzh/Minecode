#ifndef MCPUSERINTERFACEPAGE_H
#define MCPUSERINTERFACEPAGE_H

#include <QWidget>

namespace Ui {
class mcpUserInterfacePage;
}

class mcpUserInterfacePage : public QWidget
{
    Q_OBJECT

public:
    explicit mcpUserInterfacePage(QWidget *parent = 0);
    ~mcpUserInterfacePage();

private:
    Ui::mcpUserInterfacePage *ui;
};

#endif // MCPUSERINTERFACEPAGE_H
