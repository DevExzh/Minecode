#ifndef STATISTICALDATADIALOG_H
#define STATISTICALDATADIALOG_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>

namespace Ui {
class StatisticalDataDialog;
}

class StatisticalDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticalDataDialog(QWidget *parent = 0);
    ~StatisticalDataDialog();

private:
    Ui::StatisticalDataDialog *ui;

private slots:
        void SetFormStyleFromSignal(QString);
        void SetFormFontFromSignal(QFont);
        void UIRetranslate();
};

#endif // STATISTICALDATADIALOG_H
