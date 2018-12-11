#include "studioconfigdialog.h"
#include "ui_studioconfigdialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

QTranslator *minecode_translator = new QTranslator();

StudioConfigDialog::StudioConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudioConfigDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton_General,SIGNAL(clicked()),this,SLOT(switchPage_General()));
    connect(ui->pushButton_UI,SIGNAL(clicked()),this,SLOT(switchPage_UI()));
    connect(ui->pushButton_Generate,SIGNAL(clicked()),this,SLOT(switchPage_Generate()));
    connect(ui->pushButton_DevelopmentKit,SIGNAL(clicked()),this,SLOT(switchPage_DevelopmentKit()));
    connect(ui->pushButton_CodeEditor,SIGNAL(clicked()),this,SLOT(switchPage_CodeEditor()));
    connect(ui->pushButton_Console,SIGNAL(clicked()),this,SLOT(switchPage_Console()));
    connect(ui->pushButton_Notices,SIGNAL(clicked()),this,SLOT(switchPage_Notices()));
    connect(ui->pushButton_Document,SIGNAL(clicked()),this,SLOT(switchPage_Document()));
    connect(ui->pushButton_IODevices,SIGNAL(clicked()),this,SLOT(switchPage_IODevices()));
    connect(ui->pushButton_Advanced,SIGNAL(clicked()),this,SLOT(switchPage_Advanced()));
    connect(ui->radioButton_StyleSheet_Software,SIGNAL(clicked()),this,SLOT(StyleSheetModeChanged()));
    connect(ui->radioButton_StyleSheet_User,SIGNAL(clicked()),this,SLOT(StyleSheetModeChanged()));
    connect(ui->radioButton_StyleSheet_System,SIGNAL(clicked()),this,SLOT(StyleSheetModeChanged()));
    //connect(this,SIGNAL(SetLanguage()),pEProcessWindow,SLOT(UIRetranslate()));
    //connect(this,SIGNAL(SetLanguage()),pNewProjectDialog,SLOT(UIRetranslate()));
    //connect(this,SIGNAL(SetLanguage()),pStatisticalDataDialog,SLOT(UIRetranslate()));
    //connect(this,SIGNAL(SetLanguage()),pMinecodeDesigner,SLOT(UIRetranslate()));
    ui->fontComboBox->setCurrentFont(this->font());
    SetLanguageComboBoxData();
    ui->pageWidget->setCurrentIndex(page);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
}

StudioConfigDialog::~StudioConfigDialog()
{
    delete ui;
}

void StudioConfigDialog::SetLanguageComboBoxData()
{
    ui->comboBox_Language->addItem("English");
    ui->comboBox_Language->addItem("简体中文");
}

void StudioConfigDialog::StyleSheetModeChanged()
{
    if(ui->radioButton_StyleSheet_User->isChecked())
    {
        ui->pushButton_StyleSheet_User_BrowseFile->setEnabled(true);
        ui->checkBox_AutoReloadStyleSheetWhenFileChanged->setEnabled(true);
    }
    else
    {
        ui->pushButton_StyleSheet_User_BrowseFile->setEnabled(false);
        ui->checkBox_AutoReloadStyleSheetWhenFileChanged->setEnabled(false);
    }

    if(ui->radioButton_StyleSheet_Software->isChecked())
    {
        QFile mainWindowStyle(qApp->applicationDirPath()+"/Style/Default/mainwindow.css");
        mainWindowStyle.open(QFile::ReadOnly);
        styleMainWindow=mainWindowStyle.readAll();
        emit SetEProcessWindowStyle(styleEProcessWindow);
        emit SetMainWindowStyle(styleMainWindow);
        emit SetNewProjectDialogStyle(styleNewProjectDialog);
        emit SetStatisticalDataDialogStyle(styleStatisticalDataDialog);
    }

    if(ui->radioButton_StyleSheet_System->isChecked())
    {
        emit SetEProcessWindowStyle("");
        emit SetMainWindowStyle("");
        emit SetNewProjectDialogStyle("");
        emit SetStatisticalDataDialogStyle("");
    }
}

void StudioConfigDialog::LoadCustomStyleSheet(QString styleSheetFile)
{
    QFile file(styleSheetFile);
    file.open(QFile::ReadOnly);
    if(file.isOpen())
    {
        QString ss=file.readAll();
        qApp->setStyleSheet(ss);
        file.close();
    }
}

void StudioConfigDialog::styleSheetFileChanged()
{
    StudioConfigDialog::LoadCustomStyleSheet("");
}

void StudioConfigDialog::switchPage_General()
{
    ui->pageWidget->setCurrentIndex(1);
}

void StudioConfigDialog::switchPage_UI()
{
    ui->pageWidget->setCurrentIndex(2);
}

void StudioConfigDialog::switchPage_Generate()
{
    ui->pageWidget->setCurrentIndex(3);
}

void StudioConfigDialog::switchPage_DevelopmentKit()
{
    ui->pageWidget->setCurrentIndex(4);
}

void StudioConfigDialog::switchPage_CodeEditor()
{
    ui->pageWidget->setCurrentIndex(5);
}

void StudioConfigDialog::switchPage_Console()
{
    ui->pageWidget->setCurrentIndex(6);
}

void StudioConfigDialog::switchPage_Notices()
{
    ui->pageWidget->setCurrentIndex(7);
}

void StudioConfigDialog::switchPage_Document()
{
    ui->pageWidget->setCurrentIndex(8);
}

void StudioConfigDialog::switchPage_IODevices()
{
    ui->pageWidget->setCurrentIndex(9);
}

void StudioConfigDialog::switchPage_Advanced()
{
    ui->pageWidget->setCurrentIndex(10);
}

void StudioConfigDialog::on_pushButton_StyleSheet_User_BrowseFile_clicked()
{
    QFileDialog fileDialog;
    QStringList filters;
    filters << tr("Style Sheet File (*.css)");
    fileDialog.setNameFilters(filters);
    fileDialog.setHistory(fileDialogHistroyList);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Exzh Minecode Studio Style Sheet File"));
    fileDialog.setViewMode(QFileDialog::List);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setDefaultSuffix("css");
    if(fileDialog.exec()==QFileDialog::Accepted)
    {
        LoadCustomStyleSheet((fileDialog.selectedFiles()[0]));
        fileDialogHistroyList<<fileDialog.directory().absolutePath();
    }
}

void StudioConfigDialog::on_checkBox_EnableStyleSheet_toggled(bool checked)
{
    ui->groupBox_StyleSheet->setEnabled(checked);
}

void StudioConfigDialog::on_fontComboBox_currentFontChanged(const QFont &f)
{
    this->setFont(f);
    emit SetFontBySignal(f);
}

void StudioConfigDialog::on_comboBox_Language_currentTextChanged(const QString &arg1)
{
    if(arg1=="简体中文")
    {
        minecode_translator->load(QCoreApplication::applicationDirPath()+"\\Language\\minecode_zh-CN.qm");
        qApp->installTranslator(minecode_translator);
        this->ui->retranslateUi(this);
        emit SetLanguage();
    }
    if(arg1=="English")
    {
        QApplication::removeTranslator(minecode_translator);
        this->ui->retranslateUi(this);
        emit SetLanguage();
    }
}

void StudioConfigDialog::on_pushButton_UIFont_BrowseFile_clicked()
{
    QFileDialog fileDialog;
    QStringList filters;
    filters << tr("TrueType Font File (*.ttf)")<< tr("OpenType Font File (*.otf)");
    fileDialog.setNameFilters(filters);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Font File"));
    fileDialog.setViewMode(QFileDialog::List);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    if(fileDialog.exec()==QFileDialog::Accepted)
    {
        int fontId=QFontDatabase::addApplicationFont(fileDialog.selectedFiles()[0]);
        QString mf=QFontDatabase::applicationFontFamilies(fontId).at(0);
        this->setFont(QFont(mf));
        emit SetFontBySignal(QFont(mf));
    }
}

void StudioConfigDialog::on_pushButton_CodeFont_BrowseFile_clicked()
{
    QFileDialog fileDialog;
    QStringList filters;
    filters << tr("TrueType Font File (*.ttf)")<< tr("OpenType Font File (*.otf)");
    fileDialog.setNameFilters(filters);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Font File"));
    fileDialog.setViewMode(QFileDialog::List);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    if(fileDialog.exec()==QFileDialog::Accepted)
    {
        int fontId=QFontDatabase::addApplicationFont(fileDialog.selectedFiles()[0]);
        QString mf=QFontDatabase::applicationFontFamilies(fontId).at(0);
        emit SetCodeEditorFont(QFont(mf));
        ui->codefontComboBox->setCurrentFont(QFont(mf));
    }
}

void StudioConfigDialog::ReceiveCodeEditorFont(QFont font)
{
    ui->codefontComboBox->setCurrentFont(font);
    ui->codeFontSpinBox->setValue(font.pointSize());
}

void StudioConfigDialog::on_codeFontSpinBox_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    QFont f=ui->codefontComboBox->currentFont();
    f.setPointSize(ui->codeFontSpinBox->value());
    emit SetCodeEditorFont(f);
}

void StudioConfigDialog::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    QSettings *appSettings=new QSettings(qApp->applicationDirPath()+"/Config/ApplicationGlobal.mccf",QSettings::IniFormat);
    appSettings->setValue("MinecodeUI/Language",ui->comboBox_Language->currentIndex());
    appSettings->setValue("MinecodeUI/DefaultPage","");
    appSettings->setValue("MinecodeUI/StyleSheet","");
    appSettings->setValue("MinecodeUI/UIFont",ui->fontComboBox->currentFont().family()+","+QString::number(ui->fontComboBox->currentFont().pointSize())+"pt");
    appSettings->setValue("MinecodeUI/CodeFont",ui->codefontComboBox->currentFont().family()+","+QString::number(ui->codefontComboBox->currentFont().pointSize())+"pt");
    delete appSettings;
}

void StudioConfigDialog::on_codefontComboBox_currentFontChanged(const QFont &f)
{
    QFont tmpfont;
    tmpfont=f;
    tmpfont.setPointSize(ui->codeFontSpinBox->value());
    emit SetCodeEditorFont(tmpfont);
}
