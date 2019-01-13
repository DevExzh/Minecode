#ifndef MCPREFERENCEDIALOG_H
#define MCPREFERENCEDIALOG_H

#include <QWidget>
#include <QStandardItemModel>
#include <QHash>
#include <QPointer>

#include "delegate/nofocusdelegate.h"
#include "../services/exstyleprovider.h"
#include "../mcDefaultStyleSheets"

namespace Ui {
class mcPreferenceDialog;
}

class mcPreferenceDialog : public QWidget
{
    Q_OBJECT

public:
    explicit mcPreferenceDialog(QWidget *parent = 0);
    void setWhetherForceEnableStyle(bool boolean);
    ~mcPreferenceDialog();

public slots:
    void addPage(QWidget *page);
    void removePage(QWidget *page);

signals:
    void pageAdded(QWidget *page);
    void pageRemoved(QWidget *page);

private:
    Ui::mcPreferenceDialog *ui;
    NoFocusDelegate *itemDelegate;

protected:
    QStandardItemModel *preferenceModel;
    bool _isForceEnableStyleSheet;
};

#endif // MCPREFERENCEDIALOG_H
