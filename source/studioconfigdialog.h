#ifndef STUDIOCONFIGDIALOG_H
#define STUDIOCONFIGDIALOG_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>
#include <QFileSystemWatcher>
#include <QFileDialog>
#include <QTranslator>
#include <QSettings>

// All forms' header file
#include "eprocesswindow.h"
#include "mainwindow.h"
#include "newprojectdialog.h"
#include "statisticaldatadialog.h"
#include "minecodedesigner.h"
#include "definition.h"

namespace Ui {
class StudioConfigDialog;
}

class StudioConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudioConfigDialog(QWidget *parent = 0);
    ~StudioConfigDialog();
    int page;

private:
    Ui::StudioConfigDialog *ui;
    void SetLanguageComboBoxData();
    void LoadCustomStyleSheet(QString);
    void closeEvent(QCloseEvent *event);

// Form Pointer Definition
private:
    QPointer<EProcessWindow> pEProcessWindow;
    QPointer<NewProjectDialog> pNewProjectDialog;
    QPointer<StatisticalDataDialog> pStatisticalDataDialog;
    QPointer<MinecodeDesigner> pMinecodeDesigner;

// Style Sheets of Forms
private:
    QString styleStudioConfigDialog;
    QString styleEProcessWindow;
    QString styleMainWindow;
    QString styleNewProjectDialog;
    QString styleStatisticalDataDialog;
    QString styleSheetFileLocation;

private:
    QFileSystemWatcher styleSheetFileChangedEventWatcher;
    QStringList fileDialogHistroyList;

public slots:
    void switchPage_General();
    void switchPage_UI();
    void switchPage_Generate();
    void switchPage_DevelopmentKit();
    void switchPage_CodeEditor();
    void switchPage_Console();
    void switchPage_Notices();
    void switchPage_Document();
    void switchPage_IODevices();
    void switchPage_Advanced();
    void ReceiveCodeEditorFont(QFont);

private slots:
    void StyleSheetModeChanged();
    void styleSheetFileChanged();
    void on_pushButton_StyleSheet_User_BrowseFile_clicked();
    void on_checkBox_EnableStyleSheet_toggled(bool checked);
    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_comboBox_Language_currentTextChanged(const QString &arg1);
    void on_pushButton_UIFont_BrowseFile_clicked();
    void on_pushButton_CodeFont_BrowseFile_clicked();
    void on_codeFontSpinBox_valueChanged(int arg1);
    void on_codefontComboBox_currentFontChanged(const QFont &f);

signals:
    void SetMainWindowStyle(QString);
    void SetEProcessWindowStyle(QString);
    void SetNewProjectDialogStyle(QString);
    void SetStatisticalDataDialogStyle(QString);
    void SetFontBySignal(QFont);
    void SetLanguage();
    void SetCodeEditorFont(QFont);
};

#endif // STUDIOCONFIGDIALOG_H
