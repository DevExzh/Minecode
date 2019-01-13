#ifndef MINECODE_H
#define MINECODE_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QLabel>
#include <QPointer>
#include <QScopedPointer>
#include <QDateTime>

#include "mcDialogs"
#include "mcGlobal"
#include "mcDefaultStyleSheets"
#include "editor/build-in/mcppagesmanagement.h"
#include "dialogs/widgets/mclocationnavigator.h"
#include "dialogs/widgets/mcnotification.h"

MinecodeProviders
MinecodeDialogs

#define MinecodeNotificationCall mcNotification *notification=new mcNotification; \
notification->move(ui->msgIndicator->mapToGlobal( \
QPoint(ui->actionMsgWarningButton->pos().x()-notification->width()/2 \
,ui->actionMsgWarningButton->pos().y()-notification->height()))); \
notification->show(); \

namespace Ui {
class Minecode;
}

class Minecode : public QMainWindow
{
    Q_OBJECT

public:
    explicit Minecode(QWidget *parent = 0);
    void addToolMenu(QMenu *menu);
    void addEditor(mcEditor *editor);
    ~Minecode();

private:
    Ui::Minecode *ui;
    QToolBar *mainToolBar;
    mcProjectDialog *projDlg;
    mcPreferenceDialog *preferenceDlg;
    mcEmptyCodeEditorWidget *emptyCodeEditor;

protected:
    void closeEvent(QCloseEvent *event);
    mcpPagesManagement *defaultPagesManager;
    QTimer *timeIndicatorRefreshClock;

private slots:
    void on_wcButton_NewProject_clicked();
    void on_qbButton_Welcome_clicked();
    void on_qbButton_Editor_clicked();
    void on_wcButton_LoadProject_clicked();
    void on_pageContainer_currentChanged(int arg1);
    void on_actionSwitchController_clicked();
};

#endif // MINECODE_H
