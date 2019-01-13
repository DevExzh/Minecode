#include "mcmessagelabel.h"

mcMessageLabel::mcMessageLabel(QWidget *parent) :
    QLabel(parent),
    msgTimer(new QTimer(this)),
    effect(new QGraphicsOpacityEffect(this)),
    animation(new QPropertyAnimation(effect,"opacity",this))
{
    this->setVisible(false);
}

void mcMessageLabel::showMessage(const QString &msg, int time, int lastTime)
{
    this->setText(msg);
    msgTimer->stop();
    connect(msgTimer,&QTimer::timeout,[=](){
        effect->setOpacity(1.0);
        animation->setDuration(time);
        animation->setStartValue(1.0);
        animation->setEndValue(0);
        animation->start();
    });

    this->setVisible(true);
    effect->setOpacity(0);
    animation->setDuration(time);
    animation->setStartValue(0);
    animation->setEndValue(1.0);
    animation->start();

    connect(animation,&QPropertyAnimation::finished,[=](){
        if(effect->opacity()==1.0)
        {
            msgTimer->start(lastTime);
        }
        else if(effect->opacity()==0.0)
        {
            this->setVisible(false);
        }
    });
}
