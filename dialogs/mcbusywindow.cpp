#include "mcbusywindow.h"
#include "ui_mcbusywindow.h"

mcBusyWindow::mcBusyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mcBusyWindow),
    marqueeClock(new QTimer(this)),
    isLeft(false)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);

    connect(marqueeClock,&QTimer::timeout,[=](){
        if(ui->marqueeProgressBar->x()>=ui->marqueeProgressBarContainer->width()-ui->marqueeProgressBar->width() && isLeft==false)
            isLeft=true;
        else if(ui->marqueeProgressBar->x()<=0 && isLeft==true) isLeft=false;

        if(isLeft)
            ui->marqueeProgressBar->setGeometry(ui->marqueeProgressBar->x()-12,0,ui->marqueeProgressBar->width(),20);
        else
            ui->marqueeProgressBar->setGeometry(ui->marqueeProgressBar->x()+12,0,ui->marqueeProgressBar->width(),20);
    });

    marqueeClock->start(32);
}

mcBusyWindow::~mcBusyWindow()
{
    delete ui;
}

void mcBusyWindow::setMessage(const QString &msg)
{
    if(!msg.isEmpty())
        ui->messageDisplay->setText(msg);
    else
        ui->messageDisplay->setText(QStringLiteral("Processing background... Please wait"));
}

void mcBusyWindow::setTitle(const QString &title)
{
    if(!title.isEmpty())
        ui->titleDisplay->setText(title);
}
