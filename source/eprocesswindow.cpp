#include "eprocesswindow.h"
#include "ui_eprocesswindow.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

EProcessWindow::EProcessWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EProcessWindow),
    marqueeClock(new QTimer(this))
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    connect(marqueeClock,SIGNAL(timeout()),this,SLOT(MarqueeAnimation()));
    ui->progressBar->setVisible(false);
    isLeft=false;
    marqueeClock->start(32);
}

EProcessWindow::~EProcessWindow()
{
    disconnect(marqueeClock,SIGNAL(timeout()),this,SLOT(MarqueeAnimation()));
    delete ui;
}

void EProcessWindow::SetFormStyleFromSignal(QString data)
{
    this->setStyleSheet(data);
}

void EProcessWindow::SetFormFontFromSignal(QFont font)
{
    this->setFont(font);

}

void EProcessWindow::UIRetranslate()
{
    this->ui->retranslateUi(this);
}

void EProcessWindow::MarqueeAnimation()
{
    if(ui->marqueeProgressBar->x()>=ui->marqueeProgressBarContainer->width()-ui->marqueeProgressBar->width() && isLeft==false)
        isLeft=true;
    else if(ui->marqueeProgressBar->x()<=0 && isLeft==true) isLeft=false;

    if(isLeft)
        ui->marqueeProgressBar->setGeometry(ui->marqueeProgressBar->x()-12,0,ui->marqueeProgressBar->width(),20);
    else
        ui->marqueeProgressBar->setGeometry(ui->marqueeProgressBar->x()+12,0,ui->marqueeProgressBar->width(),20);
}
