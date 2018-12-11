#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include "mainwindow.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    NewProjectDialog::LoadProjectTypeData();
    connect(ui->projectTypeView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(projectTypeView_SelectNodeChanged(QModelIndex,QModelIndex)));
    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

void NewProjectDialog::projectTypeView_SelectNodeChanged(QModelIndex current,QModelIndex previous)
{
    Q_UNUSED(previous);
    if(current.data().toString()=="CB++" || current.parent().data().toString()=="CB++")
    {
      ui->label_NewProjectType->setText("CB++");
      NewProjectDialog::SetMinecraftPanelVisibility(true);
    }
    if(current.data().toString()=="C/C++" || current.parent().data().toString()=="C/C++")
    {
      ui->label_NewProjectType->setText("C/C++");
      NewProjectDialog::SetMinecraftPanelVisibility(false);
    }
    if(current.data().toString()=="C#")
    {
      ui->label_NewProjectType->setText("C#");
      NewProjectDialog::SetMinecraftPanelVisibility(false);
    }
    if(current.data().toString()=="Python")
    {
      ui->label_NewProjectType->setText("Python");
      NewProjectDialog::SetMinecraftPanelVisibility(false);
    }
    if(current.data().toString()=="JavaScript")
    {
      ui->label_NewProjectType->setText("JavaScript");
      NewProjectDialog::SetMinecraftPanelVisibility(false);
    }
    if(current.data().toString()=="XML")
    {
      ui->label_NewProjectType->setText("XML");
      NewProjectDialog::SetMinecraftPanelVisibility(false);
    }
    if(current.data().toString()=="HTML")
    {
      ui->label_NewProjectType->setText("HTML");
      NewProjectDialog::SetMinecraftPanelVisibility(false);
    }
}

void NewProjectDialog::SetMinecraftPanelVisibility(bool input)
{
    ui->widget_Minecraft->setVisible(input);
    if(input)
        ui->verticalSpacer_ProjectOptions->changeSize(100,0);
    else
        ui->verticalSpacer_ProjectOptions->changeSize(100,4);
}

void NewProjectDialog::LoadProjectTypeData()
{
    QStandardItemModel *pModel=new QStandardItemModel(ui->projectTypeView);
    QStandardItem *pCBPlusPlus=new QStandardItem(QIcon(QStringLiteral(":/ButtonImage/src/cb++.png")),QStringLiteral("CB++"));
    QStandardItem *pCBPlusPlus_HeadFile=new QStandardItem(QStringLiteral("CB++ Head File"));
    QStandardItem *pCBPlusPlus_SourceFile=new QStandardItem(QStringLiteral("CB++ Source File"));
    QStandardItem *pCPlusPlus=new QStandardItem(QIcon(QStringLiteral(":/ButtonImage/src/c++.png")),QStringLiteral("C/C++"));
    QStandardItem *pCPlusPlus_HeadFile=new QStandardItem(QStringLiteral("C/C++ Head File"));
    QStandardItem *pCPlusPlus_SourceFile=new QStandardItem(QStringLiteral("C/C++ Source File"));
    QStandardItem *pCSharp=new QStandardItem(QIcon(QStringLiteral(":/ButtonImage/src/csharp.png")),QStringLiteral("C#"));
    QStandardItem *pPython=new QStandardItem(QIcon(QStringLiteral(":/ButtonImage/src/python.png")),QStringLiteral("Python"));
    QStandardItem *pJavaScript=new QStandardItem(QIcon(QStringLiteral(":/ButtonImage/src/javascript.png")),QStringLiteral("JavaScript"));
    QStandardItem *pXML=new QStandardItem(QIcon(QStringLiteral(":/ButtonImage/src/xml.png")),QStringLiteral("XML"));
    QStandardItem *pHTML=new QStandardItem(QIcon(QStringLiteral(":/ButtonImage/src/html.png")),QStringLiteral("HTML"));
    pModel->appendRow(pCBPlusPlus);
    pModel->appendRow(pCPlusPlus);
    pModel->appendRow(pCSharp);
    pModel->appendRow(pPython);
    pModel->appendRow(pJavaScript);
    pModel->appendRow(pXML);
    pModel->appendRow(pHTML);
    pCBPlusPlus->appendRow(pCBPlusPlus_HeadFile);
    pCBPlusPlus->appendRow(pCBPlusPlus_SourceFile);
    pCPlusPlus->appendRow(pCPlusPlus_HeadFile);
    pCPlusPlus->appendRow(pCPlusPlus_SourceFile);
    ui->projectTypeView->setModel(pModel);
    ui->comboBox_MinecraftVersion->addItem("1.4.X");
    ui->comboBox_MinecraftVersion->addItem("1.5.X");
    ui->comboBox_MinecraftVersion->addItem("1.6.X");
    ui->comboBox_MinecraftVersion->addItem("1.7.X");
    ui->comboBox_MinecraftVersion->addItem("1.8.X");
    ui->comboBox_MinecraftVersion->addItem("1.9.X");
    ui->comboBox_MinecraftVersion->addItem("1.10.X");
    ui->comboBox_MinecraftVersion->addItem("1.11.X");
    ui->comboBox_MinecraftVersion->addItem("1.12.X");
    ui->comboBox_MinecraftVersion->addItem("1.13.X");
    ui->comboBox_Sort->addItem(tr("Default"));
    ui->comboBox_Sort->addItem(tr("Alphabet Ascending"));
    ui->comboBox_Sort->addItem(tr("Alphabet Dscending"));

#if defined(Q_OS_WIN32) || defined(Q_OS_WIN64) || defined(Q_OS_WINCE) //Windows Platform
    ui->lineEdit_ProjectLocation->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z]:(\\[^\\/<>|:*?\"]+)+$"),this));
    ui->lineEdit_SolutionLocation->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z]:(\\[^\\/<>|:*?\"]+)+$"),this));
#elif defined(Q_OS_LINUX) //Linux Platform
    ui->lineEdit_ProjectLocation->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]:(\\([0-9a-zA-Z]+))+"),this));
    ui->lineEdit_SolutionLocation->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]:(\\([0-9a-zA-Z]+))+"),this));
#elif defined(Q_OS_DARWIN) //macOS Platform
    ui->lineEdit_ProjectLocation->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]:(\\([0-9a-zA-Z]+))+"),this));
    ui->lineEdit_SolutionLocation->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]:(\\([0-9a-zA-Z]+))+"),this));
#endif
}

void NewProjectDialog::SetFormStyleFromSignal(QString data)
{
    this->setStyleSheet(data);
}

void NewProjectDialog::SetFormFontFromSignal(QFont font)
{
    this->setFont(font);
}

void NewProjectDialog::UIRetranslate()
{
    this->ui->retranslateUi(this);
}

void ShowMinecodeDesigner()
{
    MinecodeDesigner *pDesigner=new MinecodeDesigner();
    pDesigner->show();
}

void NewProjectDialog::on_pushButton_Create_clicked()
{
    emit projectCreated();
    this->close();
    QPointer<EProcessWindow> epw=new EProcessWindow;
    epw->exec();
}

void NewProjectDialog::on_cancelButton_clicked()
{
    this->close();
}
