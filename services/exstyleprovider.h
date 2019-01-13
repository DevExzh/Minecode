#ifndef EXSTYLEPROVIDER_H
#define EXSTYLEPROVIDER_H

#include <QObject>
#include <QHash>
#include <QFile>
#include <QDir>
#include <QThread>
#include <QDirIterator>
#include <QFileInfo>
#include <QApplication>
#include <QDebug>
#include <QPointer>

#include "../exglobal.h"

#define styleService exStyleProvider::instance()

class exStyleProvider : public QObject
{
    Q_OBJECT
public:
    explicit exStyleProvider(QObject *parent = nullptr);
    QStringList searchStyleSheetFiles(const QString &path);
    QString getStyleSheetFromName(const QString &name);
    int styleSheetCounts();
    void registerStyleSheet(const QString &name,const QString &style);
    void registerStyleSheet(const QString &file);
    void registerStyleSheet(QFile &file);

    static exStyleProvider* instance(){return self;}

private:
    static exStyleProvider *self;

private:
    void initialize();

protected:
    QHash<QString,QString> styleMap;
};

#endif // EXSTYLEPROVIDER_H
