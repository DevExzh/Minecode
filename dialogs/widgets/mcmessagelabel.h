#ifndef MCMESSAGELABEL_H
#define MCMESSAGELABEL_H

#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QGraphicsEffect>
#include <QPropertyAnimation>

class mcMessageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit mcMessageLabel(QWidget *parent = nullptr);
    void showMessage(const QString &msg, int time, int lastTime);

protected:
    QTimer *msgTimer;
    QGraphicsOpacityEffect *effect;
    QPropertyAnimation *animation;
};

#endif // MCMESSAGELABEL_H
