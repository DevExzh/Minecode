#ifndef EXSPLASHSCREEN_H
#define EXSPLASHSCREEN_H

#include <QSplashScreen>
#include <QPainter>

class exSplashScreen : public QSplashScreen
{
public:
    exSplashScreen(const QPixmap& pixmap);
    ~exSplashScreen();
    virtual void drawContents(QPainter *painter);
    void showStatusMessage(const QString &message, const QColor &color = Qt::black);
    void setMessageRect(QRect rect, int alignment = Qt::AlignLeft);

private:
    QString message;
    int alignement;
    QColor color;
    QRect rect;
};

#endif // EXSPLASHSCREEN_H
