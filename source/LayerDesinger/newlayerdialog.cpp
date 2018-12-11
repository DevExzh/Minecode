#include "newlayerdialog.h"
#include "ui_newlayerdialog.h"

NewLayerDialog::NewLayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLayerDialog)
{
    ui->setupUi(this);
}

NewLayerDialog::~NewLayerDialog()
{
    delete ui;
}

void NewLayerDialog::on_checkBox_UnlimitedSpace_clicked(bool checked)
{
    ui->LayerSettingLayout->setEnabled(checked);
}

void NewLayerDialog::on_checkBox_EnableOpenGL_clicked(bool checked)
{
    ui->radioButton_3D->setEnabled(checked);
}

void NewLayerDialog::on_pushButton_Create_clicked()
{
    //MinecodeDesigner *md=new MinecodeDesigner();
    //md->setBaseSize(QSize(ui->spinBox_Width->value(),ui->spinBox_Height->value()));
}
