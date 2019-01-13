#ifndef MCPENVIRONMENTPAGE_H
#define MCPENVIRONMENTPAGE_H

#include <QWidget>

namespace Ui {
class mcpEnvironmentPage;
}

class mcpEnvironmentPage : public QWidget
{
    Q_OBJECT

public:
    explicit mcpEnvironmentPage(QWidget *parent = 0);
    ~mcpEnvironmentPage();

private:
    Ui::mcpEnvironmentPage *ui;
};

#endif // MCPENVIRONMENTPAGE_H
