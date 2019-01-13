#ifndef MCPEDITORPAGE_H
#define MCPEDITORPAGE_H

#include <QWidget>

namespace Ui {
class mcpEditorPage;
}

class mcpEditorPage : public QWidget
{
    Q_OBJECT

public:
    explicit mcpEditorPage(QWidget *parent = 0);
    ~mcpEditorPage();

private:
    Ui::mcpEditorPage *ui;
};

#endif // MCPEDITORPAGE_H
