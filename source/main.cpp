#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QRect>
#include "Inherit/exsplashscreen.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setFont(QFont("方正黑体简体",9,QFont::Normal));
    QPixmap pixmap(":/SplashScr/src/SplashScr/SplashScr.png");
    exSplashScreen *splashscr=new exSplashScreen(pixmap);
    splashscr->show();
    //a.processEvents();
    MainWindow w;
    w.show();
    splashscr->finish(&w);
    return a.exec();
}
