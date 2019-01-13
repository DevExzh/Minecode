#include "mcprojectdialog.h"
#include "ui_mcprojectdialog.h"

mcProjectDialog::mcProjectDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcProjectDialog),
    languageCompleter(new QCompleter(completerList)),
    privateModels(new mcProjectDialogPrivate)
{
    ui->setupUi(this);

    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.4.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.5.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.6.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.7.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.8.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.9.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.10.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.11.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.12.X");
    ui->comboBox_MinecraftVersion->addItem(QIcon(QStringLiteral(":/misc/resources/misc/minecraft.svg")),"1.13.X");

    ui->comboBox_Sort->addItem(tr("Default"));
    ui->comboBox_Sort->addItem(tr("Alphabet Ascending"));
    ui->comboBox_Sort->addItem(tr("Alphabet Dscending"));

    QStandardItemModel *pLanguageModel=new QStandardItemModel;
    pLanguageModel_Recent=new QStandardItem(tr("Recent"));
    QStandardItem *pLanguageModel_Available=new QStandardItem(tr("Available"));
    pLanguageModel->appendRow(pLanguageModel_Recent);
    pLanguageModel->appendRow(pLanguageModel_Available);
    QStandardItem *pLanguageModel_Available_Template=new QStandardItem(tr("Templates"));
    QStandardItem *pLanguageModel_Available_OtherProjectTypes=new QStandardItem(tr("Other Project Types"));
    pLanguageModel_Available->appendRow(pLanguageModel_Available_Template);
    pLanguageModel_Available->appendRow(pLanguageModel_Available_OtherProjectTypes);
    pLanguageModel_Available_Template->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-cpp.svg")),QLatin1String("C/C++")));
    pLanguageModel_Available_Template->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-csharp.svg")),QLatin1String("C#")));
    pLanguageModel_Available_Template->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-css3.svg")),QLatin1String("CSS")));
    pLanguageModel_Available_Template->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-html5.svg")),QLatin1String("HTML")));
    pLanguageModel_Available_Template->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-javascript.svg")),QLatin1String("JavaScript")));
    pLanguageModel_Available_Template->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-python.svg")),QLatin1String("Python")));
    pLanguageModel_Available_OtherProjectTypes->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/solution.svg")),QLatin1String("Empty Minecode Solution")));
    ui->projectTypeView->setModel(pLanguageModel);
    ui->projectTypeView->expandAll();
    ui->projectTypeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->projectTypeView->header()->stretchLastSection();

    languageCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_LanguageSearch->setCompleter(languageCompleter);

    QButtonGroup *viewportButtonGrp=new QButtonGroup;
    viewportButtonGrp->addButton(ui->viewportButton_Icon);
    viewportButtonGrp->addButton(ui->viewportButton_List);
    viewportButtonGrp->setExclusive(true);

    connect(ui->projectTypeView->selectionModel(),&QItemSelectionModel::currentRowChanged,[=](const QModelIndex &current,const QModelIndex &previous)
    {
        Q_UNUSED(previous);
        auto model=privateModels->modelFromString(pLanguageModel->itemFromIndex(current)->text());
        ui->projectTypeList->setModel(model);
    });
}

mcProjectDialog::~mcProjectDialog()
{
    delete ui;
}

void mcProjectDialog::setLanguageCompleterList(const QStringList &list)
{
    if(!list.isEmpty())
    {
        for(auto filter:list)
        {
            if(completerList.contains(filter))
            {
                completerList.append(filter);
                languageCompleter->setModel(new QStringListModel(completerList,this));
            }
        }
    }
}

void mcProjectDialog::setRecentLanguageList(const QList<QStandardItem *> &items)
{
    if(!items.isEmpty())
    {
        pLanguageModel_Recent->appendRows(items);
    }
}

void mcProjectDialog::on_viewportButton_List_clicked()
{
    ui->projectTypeList->setViewMode(QListView::ListMode);
}

void mcProjectDialog::on_viewportButton_Icon_clicked()
{
    ui->projectTypeList->setViewMode(QListView::IconMode);
}

void mcProjectDialog::createProject(const QString &fileName)
{
    mcBusyWindow *busyWindow=new mcBusyWindow(this);
    busyWindow->setWindowModality(Qt::WindowModal);
    mcEditor *editor=new mcEditor;
    editor->setLexer(new QsciLexerCPP);
    editor->setWindowTitle(fileName);
}
