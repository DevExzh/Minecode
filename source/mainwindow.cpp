#include "mainwindow.h"
#include "ui_mainwindow.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    coe(new QsciScintilla),
    codingswBox(new QComboBox),
    quickBarButtonGrp(new QButtonGroup),
    codeEditorContainerLayout(new QVBoxLayout),
    statusLabel(new QLabel),
    pbod(new ProjectBuildOptionDialog(this)),
    designer(new MinecodeDesigner(ui->arDesigner)),
    fileExplorerView_DirModel(new QFileSystemModel),
    pNewProjectDialog(new NewProjectDialog),
    pScd(new StudioConfigDialog),
    msgW(new MsgWindow)
{
    ui->setupUi(this);

    fileExplorerMenu_Actions_Rename=new QAction(tr("Rename"));
    fileExplorerMenu_Actions_Delete=new QAction(tr("Delete"));

    ui->verticalLayout_arDesigner->addWidget(designer);
    designer->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    designer->removeAll();
    connectionInitialize();
    codeEditorInitialize();
    statusBarInitialize();
    quickBarInitialize();
    setCodeEditorTextToReadMe();
    coe->setAttribute(Qt::WA_DeleteOnClose);
    codingswBox->setAttribute(Qt::WA_DeleteOnClose);
    statusLabel->setAttribute(Qt::WA_DeleteOnClose);
    setUnifiedTitleAndToolBarOnMac(true);
    unEditorMode();

    ui->comboBox_lineEdit_codeEditor_topToolBox_FilterBox->addItem(tr("No Filter"));
    ui->comboBox_lineEdit_codeEditor_topToolBox_FilterBox->addItem(tr("Files"));
    ui->comboBox_lineEdit_codeEditor_topToolBox_FilterBox->addItem(tr("Drives"));
    ui->comboBox_lineEdit_codeEditor_topToolBox_FilterBox->addItem(tr("Directories"));
    ui->comboBox_lineEdit_codeEditor_topToolBox_FilterBox->addItem(tr("System"));
    ui->comboBox_lineEdit_codeEditor_topToolBox_FilterBox->addItem(tr("Hidden"));
    ui->fileExplorerView->setModel(fileExplorerView_DirModel);
    fileExplorerView_DirModel->setRootPath(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    fileExplorerView_DirModel->setNameFilters(fileExplorerNameFilter);
    fileExplorerView_DirModel->setReadOnly(false);
    ui->fileExplorerView->header()->setSectionsClickable(true);
    //ui->fileExplorerView->header()->setSortIndicator(0, Qt::AscendingOrder);
}

void MainWindow::quickBarInitialize()
{
    quickBarButtonGrp->addButton(ui->qbButton_Welcome);
    quickBarButtonGrp->addButton(ui->qbButton_Editor);
    quickBarButtonGrp->addButton(ui->qbButton_Designer);
    quickBarButtonGrp->addButton(ui->qbButton_Project);
    quickBarButtonGrp->addButton(ui->qbButton_Help);
    quickBarButtonGrp->setExclusive(true);
}

void MainWindow::quickBarActivedButtonChanged(QAbstractButton* button,bool checked)
{
    Q_UNUSED(checked);
    if(button->objectName()=="qbButton_Welcome")
    {
        ui->codeArea->setCurrentIndex(0);
        unEditorMode();
    }
    if(button->objectName()=="qbButton_Editor")
    {
        ui->codeArea->setCurrentIndex(1);
        updateStatusLabelText(0,0);
        this->codingswBox->show();
        ui->mainToolBar->show();
    }
    if(button->objectName()=="qbButton_Designer")
    {
        ui->codeArea->setCurrentIndex(2);
        unEditorMode();
    }
    if(button->objectName()=="qbButton_Project")
    {
        ui->codeArea->setCurrentIndex(3);
        unEditorMode();
    }
    if(button->objectName()=="qbButton_Help")
    {
        ui->codeArea->setCurrentIndex(4);
        unEditorMode();
    }
}

inline void MainWindow::unEditorMode()
{
    ui->mainToolBar->hide();
    this->codingswBox->hide();
    this->statusLabel->setText(tr("  Exzh Minecode Studio  "));
}

void MainWindow::setCodeEditorTextToReadMe()
{
    QFile readmeFile(qApp->applicationDirPath()+"/Readme");
    if(!readmeFile.open(QFile::ReadOnly|QFile::Text))
    {
        statusBar()->showMessage(tr("Exception happened while reading \"Readme\" File"),10000);
    }
    else
    {
        QTextStream tst(&readmeFile);
        //QApplication::setOverrideCursor(Qt::WaitCursor);
        coe->setText(tst.readAll());
        //QApplication::restoreOverrideCursor();
        ui->codeEditor_multiDocSwitch->addTab(new QWidget,"Readme");
    }
}

void MainWindow::connectionInitialize()
{
    QPointer<MinecodeDesigner> pmd=new MinecodeDesigner();
    connect(ui->actionMinecode_Layer_Designer,SIGNAL(triggered()),pmd,SLOT(show()));
    connect(ui->actionExit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(ui->actionOptions,SIGNAL(triggered()),pScd,SLOT(exec()));
    connect(pScd,SIGNAL(SetMainWindowStyle(QString)),this,SLOT(SetFormStyleFromSignal(QString)));
    connect(pScd,SIGNAL(SetFontBySignal(QFont)),this,SLOT(SetFormFontFromSignal(QFont)));
    connect(pScd,SIGNAL(SetLanguage()),this,SLOT(UIRetranslate()));
    connect(pScd,SIGNAL(SetLanguage()),designer,SLOT(UIRetranslate()));
    connect(pScd,SIGNAL(SetCodeEditorFont(QFont)),this,SLOT(SetCodeEditorFont(QFont)));
    connect(codingswBox,SIGNAL(currentTextChanged(QString)),this,SLOT(charsetSelectionChange(QString)));
    connect(coe,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(updateStatusLabelText(int,int)));
    connect(coe,SIGNAL(SCN_ZOOM()),this,SLOT(zoomChanged()));
    connect(coe,SIGNAL(selectionChanged()),this,SLOT(codeEditorSelectionChanged()));
    connect(quickBarButtonGrp,SIGNAL(buttonToggled(QAbstractButton*,bool)),this,SLOT(quickBarActivedButtonChanged(QAbstractButton*,bool)));
    connect(pbod,SIGNAL(buildTypeChanged(QString)),this,SLOT(modifyBuildType(QString)));
    //connect(pbod,SIGNAL(buildKitChanged(QString)),this,SLOT(modifyBuildKit(QString)));
    connect(pbod,SIGNAL(formClosing()),this,SLOT(qbBuildOptionButtonStateChange()));
    connect(pNewProjectDialog,SIGNAL(projectCreated()),this,SLOT(doActionsAfterProjectHasBeenCreated()));
    connect(fileExplorerMenu_Actions_Rename,SIGNAL(triggered(bool)),this,SLOT(fileExplorerViewItemRenameRequest(bool)));
    connect(fileExplorerMenu_Actions_Delete,SIGNAL(triggered(bool)),this,SLOT(fileExplorerViewItemDeleteRequest(bool)));
    connect(msgW,SIGNAL(yes()),this,SLOT(deleteFileExplorerViewItem()));
}

/*
void MainWindow::modifyBuildKit(QString str)
{

}*/

void MainWindow::modifyBuildType(QString str)
{
    ui->qbButton_ProjectOption->setText(str);
}

void MainWindow::statusBarInitialize()
{
    statusLabel->setStyleSheet("color: white;");
    QFont defaultUIFont("方正黑体简体",9);
    statusLabel->setFont(defaultUIFont);
    statusLabel->setText(tr("Minecode Code Editor"));

    codingswBox->addItem("ANSI");
    codingswBox->addItem("UTF-8");

    ui->statusBar->addPermanentWidget(statusLabel);
    ui->statusBar->addPermanentWidget(codingswBox);
    statusBar()->showMessage(tr("Ready"),10000);
}

void MainWindow::codeEditorInitialize()
{
    QFont codefont("Source Code Pro",10);

    //CBPPLexer *coelexer=new CBPPLexer;
    //coelexer->setColor(QColor(30, 144, 255),QsciLexerCPP::Keyword);
    //coelexer->setColor(QColor(0, 128, 0),QsciLexerCPP::CommentLine);
    //coelexer->setColor(QColor(240, 248, 255),QsciLexerCPP::Number);

    //行号显示区域
    coe->setMarginType(1, QsciScintilla::NumberMargin);
    coe->setMarginLineNumbers(1, true);
    coe->setMarginWidth(1,54);
    coe->setMarginSensitivity(1, true);
    //断点设置区域
    coe->setMarginType(0, QsciScintilla::SymbolMargin);
    coe->setMarginLineNumbers(0, false);
    coe->setMarginWidth(0,10);
    coe->setMarginSensitivity(0, true);    //设置是否可以显示断点
    coe->setMarginsBackgroundColor(QColor("#f0f0f0"));
    coe->setMarginMarkerMask(0, QsciScintilla::SC_MASK_FOLDERS);
    connect(coe, SIGNAL(marginClicked(int, int, Qt::KeyboardModifiers)),this,
            SLOT(coe_margin_clicked(int, int, Qt::KeyboardModifiers)));
    coe->markerDefine(QsciScintilla::MarkerSymbol::Circle, 0);
    coe->setMarkerBackgroundColor(QColor("#f44336"), 0);
    coe->setMarkerForegroundColor(QColor(Qt::transparent),0);
    //单步执行显示区域
    coe->setMarginType(2, QsciScintilla::SymbolMargin);
    coe->setMarginLineNumbers(2, false);
    coe->setMarginWidth(2, 20);
    coe->setMarginSensitivity(2, false);
    coe->setMarginMarkerMask(2, 0x04);
    coe->markerDefine(QsciScintilla::RightArrow, 2);
    coe->setMarkerBackgroundColor(QColor("#eaf593"), 2);
    //自动折叠区域
    coe->setMarginType(3, QsciScintilla::SymbolMargin);
    coe->setMarginLineNumbers(3, false);
    coe->setMarginWidth(3, 15);
    coe->setMarginSensitivity(3, true);

    coe->setFont(codefont);
    coe->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CHARSET_ANSI);
    coe->setScrollWidthTracking(true);
    coe->setScrollWidth(1);
    //coe->setLexer(coelexer);

    codeEditorContainerLayout->addWidget(coe);
    codeEditorContainerLayout->setMargin(0);
    ui->codeEditorContainer->setLayout(codeEditorContainerLayout);
}

void MainWindow::coe_margin_clicked(int margin, int line, Qt::KeyboardModifiers state)
{
    Q_UNUSED(state);

    if (margin == 0) {
        if (coe->markersAtLine(line) != 0) {
            coe->markerDelete(line, 0);
//            做一些去掉断点的逻辑程序
        } else {
            coe->markerAdd(line, 0);
//            做一些增加断点的逻辑程序
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete frd;
}

void MainWindow::updateStatusLabelText(int a,int b)
{
    Q_UNUSED(a);
    Q_UNUSED(b);
    if(coe->selectedText().length()==0)
    {
        statusLabel->setText(
                    tr("Line: %1").arg((coe->SendScintilla(coe->SCI_LINEFROMPOSITION,coe->SCI_GETCURRENTPOS))+1L)+
                    +"  "
                    +tr("Column: %1").arg(coe->SendScintilla(coe->SCI_GETCOLUMN,coe->SendScintilla(coe->SCI_GETCURRENTPOS)))+
                    +"  <font color=gray>|</font>  "
                    +tr("All: %1 Lines").arg(coe->SendScintilla(coe->SCI_GETLINECOUNT))
                    +"  <font color=gray>|</font>  "
                    );
    }
}

void MainWindow::zoomChanged()
{
    statusBar()->showMessage((tr("Zoom: %1%").arg(coe->SendScintilla(coe->SCI_GETZOOM))),2000);
}

void MainWindow::codeEditorSelectionChanged()
{
    if(coe->selectedText().length()>0)
    statusBar()->showMessage((tr("Selected: %1 Characters").arg(coe->selectedText().length())),2000);
}

void MainWindow::SetFormStyleFromSignal(QString data)
{
    this->setStyleSheet(data);
}

void MainWindow::SetFormFontFromSignal(QFont font)
{
    this->setFont(font);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    QSettings *appSettings=new QSettings(qApp->applicationDirPath()+"/Config/ApplicationGlobal.mccf",QSettings::IniFormat);
    appSettings->setValue("MinecodeUI/Size",QString::number(this->width())+"w,"+QString::number(this->height())+"h");
    delete appSettings;
    qApp->quit();
}

void MainWindow::UIRetranslate()
{
    this->ui->retranslateUi(this);
}

void MainWindow::on_actionMinecode_Layer_Designer_triggered()
{

}

void MainWindow::charsetSelectionChange(QString input)
{
    if(input=="ANSI") coe->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CHARSET_ANSI);
    if(input=="UTF-8") coe->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);
}

void MainWindow::SetCodeEditorFont(QFont font)
{
    coe->setFont(font);
    coe->setMarginsFont(font);
}

void MainWindow::on_qbButton_ProjectOption_toggled(bool checked)
{
    if(checked)
    {
        pbod->move(this->x()+ui->qbButton_ProjectOption->width()+7,
                   this->y()+(ui->quickBar->height()-3*ui->qbButton_ProjectOption->height()));
        connect(pbod,SIGNAL(formClosing()),this,SLOT(setBuildOptionButtonCheckStateToFalse()));
        pbod->show();
    }
    else
    {
        pbod->close();
    }
}

void MainWindow::setBuildOptionButtonCheckStateToFalse()
{
    ui->qbButton_ProjectOption->setChecked(false);
}

void MainWindow::qbBuildOptionButtonStateChange()
{
    if(pbod->isVisible()) pbod->close();
    if(ui->qbButton_ProjectOption->isChecked()) ui->qbButton_ProjectOption->setChecked(false);
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type()!=QEvent::WindowStateChange) return;
    if(event->type()==QEvent::WindowDeactivate||QEvent::WindowActivate)
    {
        qbBuildOptionButtonStateChange();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton||Qt::RightButton||Qt::MidButton)
    {
        qbBuildOptionButtonStateChange();
    }
    event->ignore();
}

void MainWindow::buildProject()
{
    ui->codeArea->setCurrentIndex(5);
    ui->qbButton_ProjectOption->setEnabled(false);
    ui->qbButton_Run->setEnabled(false);
    ui->qbButton_Build->setEnabled(false);
    QMovie *mov=new QMovie(":/Animation/src/Animation/Rader.gif");
    ui->label_gif->setMovie(mov);
    mov->start();
}

void MainWindow::on_qbButton_Run_clicked()
{
    buildProject();
}

void MainWindow::on_qbButton_Build_clicked()
{
    buildProject();
}

void MainWindow::showFindAndReplaceDialog()
{
    if(frd)
    {
        frd->close();
        frd=NULL;
    }
    else
    {
        frd=new FindAndReplaceDialog(this);
        frd->move(this->x()+this->width()-frd->width()+8,
                  this->y()+90);
        frd->show();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_F:
        if (event->modifiers() == Qt::ControlModifier)
        {
            if(ui->qbButton_Editor->isChecked()) showFindAndReplaceDialog();
        }
        break;
    default:
        break;
    }
}

void MainWindow::on_wcButton_ExitApp_clicked()
{
    qApp->quit();
}

void MainWindow::on_wcButton_NewProject_clicked()
{
    pNewProjectDialog->setFont(this->font());
    pNewProjectDialog->exec();
}

void MainWindow::on_wcButton_GetStarted_clicked()
{
    ui->codeArea->setCurrentIndex(4);
    unEditorMode();
    ui->qbButton_Help->setChecked(true);
}

QStringList MainWindow::loadMinecodeProject()
{
    QPointer<QFileDialog> fDialog=new QFileDialog(this);
    fDialog->setWindowTitle(tr("Load..."));
    fDialog->setDirectory(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    fDialog->setNameFilters(QStringList()
                            <<"Minecode Project File (*.mcpf)"
                            <<"Minecode Designer File (*.mcdf)"
                            <<"Minecraft (*.mcfunction)"
                            <<"CB++ File (*.cbpp *.cbh)"
                            <<"C/C++ File (*.c++ *.c *.cc *.cp *.cpp *.cxx *.h)"
                            <<"C# File (*.cs)"
                            <<"Python File (*.py)"
                            <<"Java Script File (*.js)"
                            <<"Json (*.json)"
                            <<"XML (*.xml)"
                            <<"HTML (*.html)");
    fDialog->setFileMode(QFileDialog::ExistingFiles);
    fDialog->setViewMode(QFileDialog::Detail);
    if(fDialog->exec()==QFileDialog::Accept)
    {
        this->raise();
        return fDialog->selectedFiles();
    }
    else
    {
        this->raise();
        return QStringList()<<"(none)";
    }
}

void MainWindow::on_wcButton_LoadProject_clicked()
{
    loadMinecodeProject();
}

void MainWindow::on_wcButton_CodeExample_clicked()
{
    ui->codeArea->setCurrentIndex(1);
    updateStatusLabelText(0,0);
    this->codingswBox->show();
    ui->mainToolBar->show();
    setCodeEditorTextToReadMe();
    ui->qbButton_Editor->setChecked(true);
}

void MainWindow::on_actionFindAndReplace_triggered()
{
    if(ui->qbButton_Editor->isChecked()) showFindAndReplaceDialog();
}

void MainWindow::on_action_Undo_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->undo();
}

void MainWindow::on_action_Redo_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->redo();
}

void MainWindow::on_actionCut_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->paste();
}

void MainWindow::on_actionDelete_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->removeSelectedText();
}

void MainWindow::on_actionSelectAll_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    coe->selectAll();
}

void MainWindow::on_actionGenerateSolution_triggered()
{
    buildProject();
}

void MainWindow::on_actionStatistics_triggered()
{
    if(ui->qbButton_Editor->isChecked())
    {
        QPointer<StatisticalDataDialog> sdd=new StatisticalDataDialog(this);
        sdd->exec();
    }
}

void MainWindow::on_actionSetLanguage_triggered()
{
    pScd->page=SettingPanel::UI;
    pScd->exec();
}

void MainWindow::on_actionCheckVersion_triggered()
{
    pScd->page=SettingPanel::General;
    pScd->exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QPointer<AboutDialog> pAd=new AboutDialog;
    pAd->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    pAd->exec();
}

void MainWindow::on_actionAddinManager_triggered()
{
    QPointer<PluginManagerDialog> plugdialog=new PluginManagerDialog();
    plugdialog->exec();
}

void MainWindow::on_action_NewFile_triggered()
{
    pNewProjectDialog->setFont(this->font());
    pNewProjectDialog->exec();
}

void MainWindow::doActionsAfterProjectHasBeenCreated()
{
    ui->qbButton_Editor->setChecked(true);
    ui->codeEditor_bottomToolBox->setCurrentIndex(0);
}

void MainWindow::on_lineEdit_codeEditor_topToolBox_SearchBox_textChanged(const QString &arg1)
{
    if(arg1.length()>=0)
    {
        if(fileExplorerNameFilter.count()!=0)
            fileExplorerNameFilter.clear();
        fileExplorerNameFilter<<arg1;
    }
}

void MainWindow::newFileExplorerMenu(const QString fileName,const QPoint &pos)
{
    fileExplorerMenu=new QMenu(this);
    if(!fileName.isEmpty() && !fileExplorerView_DirModel->isDir(ui->fileExplorerView->indexAt(pos)))
    {
        QAction *fileExplorerMenu_Actions_OpenFile=new QAction(tr("Open \"%1\"").arg(QString::fromStdWString(stringCut(fileName.toStdWString(),16U,true))));
        fileExplorerMenu->addAction(fileExplorerMenu_Actions_OpenFile);
        QAction *fileExplorerMenu_Actions_OpenInEditor=new QAction(tr("Open in Editor"));
        fileExplorerMenu->addAction(fileExplorerMenu_Actions_OpenInEditor);
        fileExplorerMenu->addSeparator();

        fileExplorerMenu_Actions_OpenFile->setIcon(QIcon(":/ToolIcon/src/ToolBar/openfile.png"));
        fileExplorerMenu_Actions_OpenInEditor->setIcon(QIcon(":/ToolIcon/src/ToolBar/openfile.png"));
    }
    QAction *fileExplorerMenu_Actions_Cut=new QAction(tr("Cut"));
    QAction *fileExplorerMenu_Actions_Copy=new QAction(tr("Copy"));
    QAction *fileExplorerMenu_Actions_Clone=new QAction(tr("Clone"));
    QAction *fileExplorerMenu_Actions_Paste=new QAction(tr("Paste"));
    QList<QAction*> tmpListF;
    tmpListF<<fileExplorerMenu_Actions_Clone
           <<fileExplorerMenu_Actions_Copy
          <<fileExplorerMenu_Actions_Cut
         <<fileExplorerMenu_Actions_Paste;
    fileExplorerMenu->addActions(tmpListF);
    fileExplorerMenu->addSeparator();
    QList<QAction*> tmpListS;
    tmpListS<<fileExplorerMenu_Actions_Delete
           <<fileExplorerMenu_Actions_Rename;
    fileExplorerMenu->addActions(tmpListS);

    fileExplorerMenu_Actions_Cut->setIcon(QIcon(":/ToolIcon/src/ToolBar/cut.png"));
    fileExplorerMenu_Actions_Copy->setIcon(QIcon(":/ToolIcon/src/ToolBar/copy.png"));
    fileExplorerMenu_Actions_Clone->setIcon(QIcon(":/ToolIcon/src/ToolBar/copy.png"));
    fileExplorerMenu_Actions_Paste->setIcon(QIcon(":/ToolIcon/src/ToolBar/paste.png"));
    fileExplorerMenu_Actions_Rename->setIcon(QIcon(":/SubWindow/src/ToolBar/SubWindow/Rename.png"));
    fileExplorerMenu_Actions_Delete->setIcon(QIcon(":/ToolIcon/src/ToolBar/delete.png"));

    fileExplorerMenu->exec(ui->fileExplorerView->mapToGlobal(pos));
}

void MainWindow::on_fileExplorerView_customContextMenuRequested(const QPoint &pos)
{
    newFileExplorerMenu(fileExplorerView_DirModel->itemData(
                            ui->fileExplorerView->indexAt(pos).
                            sibling(ui->fileExplorerView->indexAt(pos).row(),0)).
                        values()[0].toString(),pos);
}

void MainWindow::fileExplorerViewItemRenameRequest(bool checked)
{
    Q_UNUSED(checked);
    if(ui->fileExplorerView->currentIndex().column()==0 && fileExplorerView_DirModel->type(ui->fileExplorerView->currentIndex())!="Drive")
        ui->fileExplorerView->edit(ui->fileExplorerView->currentIndex());
}

void MainWindow::fileExplorerViewItemDeleteRequest(bool checked)
{
    Q_UNUSED(checked);
    if(ui->fileExplorerView->currentIndex().column()==0 && fileExplorerView_DirModel->type(ui->fileExplorerView->currentIndex())!="Drive")
        msgW->exec();
}

void MainWindow::deleteFileExplorerViewItem()
{
    fileExplorerView_DirModel->remove(ui->fileExplorerView->currentIndex());
}

void MainWindow::on_comboBox_lineEdit_codeEditor_topToolBox_FilterBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        fileExplorerView_DirModel->setFilter(QDir::AllEntries|QDir::NoDotAndDotDot);
        break;
    case 1:
        fileExplorerView_DirModel->setFilter(QDir::Files);
        break;
    case 2:
        fileExplorerView_DirModel->setFilter(QDir::Drives);
        break;
    case 3:
        fileExplorerView_DirModel->setFilter(QDir::Dirs);
        break;
    case 4:
        fileExplorerView_DirModel->setFilter(QDir::System);
        break;
    case 5:
        fileExplorerView_DirModel->setFilter(QDir::Hidden);
        break;
    }
}

void MainWindow::on_treeView_SolutionView_customContextMenuRequested(const QPoint &pos)
{
    QPointer<QMenu> solutionView_Menu=new QMenu(this);
    QPointer<QMenu> solutionView_Menu_AddMenu=new QMenu(tr("Add"),solutionView_Menu);
    solutionView_Menu_AddMenu->setIcon(QIcon(":/ToolIcon/src/ToolBar/create_new_file.png"));
    QAction *solutionView_Menu_AddMenu_NewFile=new QAction(QIcon(":/ToolIcon/src/ToolBar/add-files.png"),tr("Add New File"));
    QAction *solutionView_Menu_AddMenu_ExistingFile=new QAction(QIcon(":/ToolIcon/src/ToolBar/add-files.png"),tr("Add Existing File"));
    QAction *solutionView_Menu_AddMenu_NewProject=new QAction(QIcon(":/ToolIcon/src/ToolBar/project.png"),tr("Add New Project"));
    QAction *solutionView_Menu_AddMenu_ExistingProject=new QAction(QIcon(":/ToolIcon/src/ToolBar/project.png"),tr("Add Existing Project"));
    QAction *solutionView_Menu_OpenInSystem=new QAction(QIcon(":/WelcomeScr/src/WelcomeScr/Folder.png"),tr("Open in System File Explorer"));
    QAction *solutionView_Menu_Properties=new QAction(QIcon(":/SubWindow/src/ToolBar/SubWindow/Properties.png"),tr("Properties"));
    QAction *solutionView_Menu_Clone=new QAction(QIcon(":/ToolIcon/src/ToolBar/copy.png"),tr("Clone"));
    QAction *solutionView_Menu_Copy=new QAction(QIcon(":/ToolIcon/src/ToolBar/copy.png"),tr("Copy"));
    QAction *solutionView_Menu_Cut=new QAction(QIcon(":/ToolIcon/src/ToolBar/cut.png"),tr("Cut"));
    QAction *solutionView_Menu_Paste=new QAction(QIcon(":/ToolIcon/src/ToolBar/paste.png"),tr("Paste"));
    QAction *solutionView_Menu_Delete=new QAction(QIcon(":/ToolIcon/src/ToolBar/delete.png"),tr("Delete"));
    QAction *solutionView_Menu_Rename=new QAction(QIcon(":/SubWindow/src/ToolBar/SubWindow/Rename.png"),tr("Rename"));
    QAction *solutionView_Menu_Statistics=new QAction(QIcon(":/ToolIcon/src/ToolBar/et-sales-statistics.png"),tr("Statistics"));
    QAction *solutionView_Menu_Close=new QAction(QIcon(":/TabBar/src/TabBar/CloseButton_normal.png"),tr("Close"));

    solutionView_Menu->addMenu(solutionView_Menu_AddMenu);
    QList<QAction*> tmpListA;
    tmpListA<<solutionView_Menu_AddMenu_ExistingFile
           <<solutionView_Menu_AddMenu_ExistingProject
          <<solutionView_Menu_AddMenu_NewFile
         <<solutionView_Menu_AddMenu_NewProject;
    solutionView_Menu_AddMenu->addActions(tmpListA);
    solutionView_Menu->addSeparator();
    QList<QAction*> tmpListB;
    tmpListB<<solutionView_Menu_Clone
           <<solutionView_Menu_Copy
          <<solutionView_Menu_Cut
         <<solutionView_Menu_Paste;
    solutionView_Menu->addActions(tmpListB);
    solutionView_Menu->addSeparator();
    QList<QAction*> tmpListC;
    tmpListC<<solutionView_Menu_Close
           <<solutionView_Menu_Delete
          <<solutionView_Menu_Rename;
    solutionView_Menu->addActions(tmpListC);
    solutionView_Menu->addSeparator();
    solutionView_Menu->addAction(solutionView_Menu_Statistics);
    solutionView_Menu->addSeparator();
    QList<QAction*> tmpListD;
    tmpListD<<solutionView_Menu_OpenInSystem
           <<solutionView_Menu_Properties;
    solutionView_Menu->addActions(tmpListD);
    solutionView_Menu->exec(ui->treeView_SolutionView->mapToGlobal(pos));
}
