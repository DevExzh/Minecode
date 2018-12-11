#include "exsplashscreen.h"

exSplashScreen::exSplashScreen(const QPixmap& pixmap)
{
    QSplashScreen::setPixmap(pixmap);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
}

exSplashScreen::~exSplashScreen(){}

void exSplashScreen::drawContents(QPainter *painter)
{
    painter->setPen(this->color);
    painter->drawText(this->rect,this->alignement,this->message);
}

void exSplashScreen::showStatusMessage(const QString &message, const QColor &color)
{
    this->message = message;
    this->color = color;
    this->showMessage(this->message, this->alignement, this->color);
}

void exSplashScreen::setMessageRect(QRect rect, int alignement)
{
    this->rect = rect;
    this->alignement = alignement;
}
