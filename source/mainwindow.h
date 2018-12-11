#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QCloseEvent>
#include <QDockWidget>
#include <QComboBox>
#include <QSpacerItem>
#include <QGridLayout>
#include <QThread>
#include <QString>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QApplication>
#include <Qsci/qsciscintilla.h>
#include <QMessageBox>
#include <QButtonGroup>
#include <QMovie>
#include <QTimer>
#include <QStandardPaths>
#include <QFileSystemModel>

#include "newprojectdialog.h"
#include "studioconfigdialog.h"
#include "minecodedesigner.h"
#include "definition.h"
#include "Frameless/projectbuildoptiondialog.h"
#include "Frameless/findandreplacedialog.h"
#include "Frameless/aboutdialog.h"
#include "InfoDialog/msgwindow.h"
#include "ManagerDialog/pluginmanagerdialog.h"
#include "Helper/minecodestringhelper.h"

#include <Qsci/qscilexerjava.h>
#include <Qsci/qscilexercsharp.h>
#include <Qsci/qscilexerjavascript.h>
#include <Qsci/qscilexerjson.h>
#include <Qsci/qscilexercpp.h>

class ExzhDockWidgetTitle;

namespace Ui {
class MainWindow;
}

class StudioConfigDialog;

using namespace MinecodeHelper::StringHelper;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    /*
private:
    void QMainWindow::addDockWidget(Qt::DockWidgetArea area, QDockWidget * dockwidget, Qt::Orientation orientation);
    void QMainWindow::splitDockWidget(QDockWidget * first, QDockWidget * second, Qt::Orientation orientation);
    */

private:
    Ui::MainWindow *ui;

    //移除并隐藏所有dock
    void removeAllDock();
    //显示dock窗口
    void showDock(const QList<int>& index = QList<int>());
    QPointer<QsciScintilla> coe;
    QPointer<QComboBox> codingswBox;
    QPointer<QButtonGroup> quickBarButtonGrp;
    QPointer<QVBoxLayout> codeEditorContainerLayout;
    QPointer<QLabel> statusLabel;
    QPointer<ProjectBuildOptionDialog> pbod;
    QPointer<MinecodeDesigner> designer;
    QPointer<FindAndReplaceDialog> frd=NULL;
    void quitApp();
    void InitializeApp();
    void menuWindows_triggered(QAction* action);
    void setCodeEditorTextToReadMe();
    void connectionInitialize();
    void statusBarInitialize();
    void codeEditorInitialize();
    void quickBarInitialize();
    void buildProject();
    inline void unEditorMode();
    QStringList loadMinecodeProject();
    void showFindAndReplaceDialog();
    void newFileExplorerMenu(QString fileName, const QPoint &pos);

    MainWindow(const MainWindow &) = delete;
    MainWindow & operator = (const MainWindow &) = delete;
    #define gEStyle MainWindow::moGetInstance()

    QPointer<QFileSystemModel> fileExplorerView_DirModel;
    QStringList fileExplorerNameFilter;
    QPointer<QMenu> fileExplorerMenu;

    QAction *fileExplorerMenu_Actions_Delete;
    QAction *fileExplorerMenu_Actions_Rename;

public slots:
    void SetCodeEditorFont(QFont font);
    void doActionsAfterProjectHasBeenCreated();
    void UIRetranslate();

public:
        QPointer<NewProjectDialog> pNewProjectDialog;
        QPointer<StudioConfigDialog> pScd;
        QPointer<MsgWindow> msgW;

        static MainWindow &moGetInstance()
        {
            static MainWindow op_inst;
            return op_inst;
        }

private slots:
        void SetFormStyleFromSignal(QString);
        void SetFormFontFromSignal(QFont);
        void on_actionMinecode_Layer_Designer_triggered();
        void charsetSelectionChange(QString);
        void updateStatusLabelText(int a, int b);
        void zoomChanged();
        void codeEditorSelectionChanged();
        void quickBarActivedButtonChanged(QAbstractButton* button,bool checked);
        void on_qbButton_ProjectOption_toggled(bool checked);
        void setBuildOptionButtonCheckStateToFalse();
        void coe_margin_clicked(int, int, Qt::KeyboardModifiers);
        void modifyBuildType(QString str);
        //void modifyBuildKit(QString str);
        void qbBuildOptionButtonStateChange();
        void on_qbButton_Run_clicked();
        void on_qbButton_Build_clicked();
        void on_wcButton_ExitApp_clicked();
        void on_wcButton_NewProject_clicked();
        void on_wcButton_GetStarted_clicked();
        void on_wcButton_LoadProject_clicked();
        void on_wcButton_CodeExample_clicked();
        void on_actionFindAndReplace_triggered();
        void on_action_Undo_triggered();
        void on_action_Redo_triggered();
        void on_actionUndo_triggered();
        void on_actionRedo_triggered();
        void on_actionCut_triggered();
        void on_actionCopy_triggered();
        void on_actionPaste_triggered();
        void on_actionDelete_triggered();
        void on_actionSelectAll_triggered();
        void on_actionGenerateSolution_triggered();
        void on_actionStatistics_triggered();
        void on_actionSetLanguage_triggered();
        void on_actionCheckVersion_triggered();
        void on_actionAbout_triggered();
        void on_actionAddinManager_triggered();
        void on_action_NewFile_triggered();
        void fileExplorerViewItemRenameRequest(bool);
        void fileExplorerViewItemDeleteRequest(bool);
        void on_lineEdit_codeEditor_topToolBox_SearchBox_textChanged(const QString &arg1);
        void on_fileExplorerView_customContextMenuRequested(const QPoint &pos);
        void deleteFileExplorerViewItem();

        void on_comboBox_lineEdit_codeEditor_topToolBox_FilterBox_currentIndexChanged(int index);

        void on_treeView_SolutionView_customContextMenuRequested(const QPoint &pos);

signals:
        void GetCodeEditorFont(QFont);
};

#endif // MAINWINDOW_H
