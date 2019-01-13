#include "mcpreferencedialog.h"
#include "ui_mcpreferencedialog.h"

mcPreferenceDialog::mcPreferenceDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcPreferenceDialog),
    itemDelegate(new NoFocusDelegate),
    preferenceModel(new QStandardItemModel)
{
    ui->setupUi(this);
    ui->preferenceTypeView->setModel(preferenceModel);
    ui->preferenceTypeView->setItemDelegate(itemDelegate);

    connect(ui->preferenceTypeView,&QListView::clicked,[=](const QModelIndex &index){
        ui->pageContainer->setCurrentIndex(index.row()+1);
    });
}

mcPreferenceDialog::~mcPreferenceDialog()
{
    delete ui;
}

void mcPreferenceDialog::addPage(QWidget *page)
{
    preferenceModel->appendRow(new QStandardItem(page->windowIcon(),page->windowTitle()));
    ui->pageContainer->addWidget(page);
    if(_isForceEnableStyleSheet)
    {
        page->setStyleSheet(StylePureWhite);
    }
    emit pageAdded(page);
}

void mcPreferenceDialog::removePage(QWidget *page)
{
     ui->pageContainer->removeWidget(page);
     emit pageRemoved(page);
}

void mcPreferenceDialog::setWhetherForceEnableStyle(bool boolean)
{
    _isForceEnableStyleSheet=boolean;
}
