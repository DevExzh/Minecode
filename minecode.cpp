#include "minecode.h"
#include "ui_minecode.h"

Minecode::Minecode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Minecode),
    projDlg(new mcProjectDialog),
    emptyCodeEditor(new mcEmptyCodeEditorWidget),
    defaultPagesManager(new mcpPagesManagement),
    timeIndicatorRefreshClock(new QTimer(this))
{
    ui->setupUi(this);
    QHBoxLayout *toolBarLayout=new QHBoxLayout;
    toolBarLayout->addWidget(ui->mainToolBar);
    toolBarLayout->setContentsMargins(0,0,0,0);
    toolBarLayout->setSpacing(0);
    ui->toolBarContainer->setLayout(toolBarLayout);
    ui->toolBarContainer->setFixedHeight(ui->mainToolBar->height()-4);
    ui->quickActionWidget->setFixedHeight(ui->mainToolBar->height()-4);

    //按钮互斥
    QButtonGroup *quickBarButtonGrp=new QButtonGroup(this);
    quickBarButtonGrp->addButton(ui->qbButton_Designer);
    quickBarButtonGrp->addButton(ui->qbButton_Editor);
    quickBarButtonGrp->addButton(ui->qbButton_Help);
    quickBarButtonGrp->addButton(ui->qbButton_Project);
    quickBarButtonGrp->addButton(ui->qbButton_Welcome);
    quickBarButtonGrp->setExclusive(true);

    ui->codeEditorContainer->setViewMode(QMdiArea::TabbedView);
    ui->codeEditorContainer->setTabsMovable(true);
    ui->codeEditorContainer->setTabsClosable(true);
    ui->codeEditorContainer->addSubWindow(emptyCodeEditor);
    emptyCodeEditor->showMaximized();

    QStringList languageList;
    languageList<<"c"<<"cpp"<<"c++"<<"cplusplus"<<"c#"<<"csharp"<<"js"
               <<"javascript"<<"py"<<"python"<<"html"<<"css";
    projDlg->setLanguageCompleterList(languageList);

    on_pageContainer_currentChanged(0);

    connect(ui->actionPreference,&QAction::triggered,[=](){
        preferenceDlg=new mcPreferenceDialog;
        preferenceDlg->addPage(defaultPagesManager->pageGeneral());
        preferenceDlg->addPage(defaultPagesManager->pageEditor());
        preferenceDlg->addPage(defaultPagesManager->pageEnvironment());
        preferenceDlg->addPage(defaultPagesManager->pageNetwork());
        preferenceDlg->addPage(defaultPagesManager->pageUserinterface());
        preferenceDlg->setStyleSheet(StylePureWhite);
        preferenceDlg->show();
    });

    connect(ui->navigator,&mcLocationNavigator::itemMenuQuested,[=](QMenu *menu,const QPoint &pos){
        menu->move(ui->navigator->mapToGlobal(pos));
    });

    connect(ui->actionAbout_Exzh_Minecode_Studio,&QAction::triggered,[=](){
        mcAboutDialog *aboutDlg=new mcAboutDialog;
        aboutDlg->setAttribute(Qt::WA_DeleteOnClose);
        aboutDlg->setWindowModality(Qt::WindowModal);
        aboutDlg->show();
    });

    connect(ui->actionMsgErrorButton,&QPushButton::clicked,[=](){
        MinecodeNotificationCall
        notification->switchPage("Error");
    });

    connect(ui->actionMsgWarningButton,&QPushButton::clicked,[=](){
        MinecodeNotificationCall
        notification->switchPage("Warning");
    });

    connect(ui->actionMsgInfoButton,&QPushButton::clicked,[=](){
        MinecodeNotificationCall
        notification->switchPage("Information");
    });

    ui->navigator->setCurrentLocation("Main/Minecode/");
    ui->msgLabel->setPalette([=]()->QPalette{
      QPalette msgPalette;
      msgPalette.setColor(QPalette::WindowText,QColor(255,255,255));
      return msgPalette;
    }());

    timeIndicatorRefreshClock->start(1000);
    connect(timeIndicatorRefreshClock,&QTimer::timeout,[=](){
        ui->timeIndicator->setText(tr("Current Time: ")+QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    });

    ui->msgLabel->showMessage("Ready",2550,10000);
}

Minecode::~Minecode()
{
    delete ui;
}

void Minecode::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    QTimer::singleShot(0,qApp,&QApplication::quit);
}

void Minecode::on_wcButton_NewProject_clicked()
{
    projDlg->setWindowModality(Qt::WindowModal);
    projDlg->show();
}

void Minecode::on_qbButton_Welcome_clicked()
{
    ui->pageContainer->setCurrentWidget(ui->pageWelcome);
}

void Minecode::on_qbButton_Editor_clicked()
{
    ui->pageContainer->setCurrentWidget(ui->pageEditor);
}

void Minecode::on_wcButton_LoadProject_clicked()
{
    mcFileDialog *dlg=new mcFileDialog(this);
    dlg->setWindowModality(Qt::WindowModal);
    dlg->show();
}

void Minecode::on_pageContainer_currentChanged(int arg1)
{
    if(arg1==1)
    {
        ui->mainToolBar->show();
        ui->toolBarContainer->setVisible(true);
        ui->codeEditorStatusLabel->setText("Exzh Minecode Studio");
    }
    else
    {
        ui->mainToolBar->hide();
        ui->toolBarContainer->setVisible(false);
    }
}

void Minecode::addToolMenu(QMenu *menu)
{
    ui->menuTools_T->addMenu(menu);
}

void Minecode::addEditor(mcEditor *editor)
{
    ui->codeEditorContainer->addSubWindow(editor);

    connect(editor,&mcEditor::statusChanged,[=](const QString &status){
        ui->codeEditorStatusLabel->setText(status);
    });
}

void Minecode::on_actionSwitchController_clicked()
{
    if(ui->actionControlContainer->currentIndex()==ui->actionControlContainer->count()-1)
    {
        ui->actionControlContainer->setCurrentIndex(0);
    }
    else
    {
        ui->actionControlContainer->setCurrentIndex(ui->actionControlContainer->currentIndex()+1);
    }
}
