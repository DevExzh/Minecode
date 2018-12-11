#ifndef FINDANDREPLACEDIALOG_H
#define FINDANDREPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class FindAndReplaceDialog;
}

class FindAndReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindAndReplaceDialog(QWidget *parent = 0);
    ~FindAndReplaceDialog();

private:
    Ui::FindAndReplaceDialog *ui;
};

#endif // FINDANDREPLACEDIALOG_H
