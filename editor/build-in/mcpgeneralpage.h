#ifndef MCPGENERALPAGE_H
#define MCPGENERALPAGE_H

#include <QWidget>

namespace Ui {
class mcpGeneralPage;
}

class mcpGeneralPage : public QWidget
{
    Q_OBJECT

public:
    explicit mcpGeneralPage(QWidget *parent = 0);
    ~mcpGeneralPage();

private:
    Ui::mcpGeneralPage *ui;
};

#endif // MCPGENERALPAGE_H
