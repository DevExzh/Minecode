#ifndef EXFONTPROVIDER_H
#define EXFONTPROVIDER_H

#include <QMap>
#include <QApplication>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QFontDatabase>
#include <QIODevice>

#include <QDebug>

#include "exglobal.h"

class exFontProvider : public QObject
{
    Q_OBJECT
public:
    explicit exFontProvider(QObject *parent = nullptr);
    QFont registeredFont(const QString &family);
    void registerFont(const QString &family,const QString &file);
    QString fontFamily(const QString &file);
    void setFontFolder(const QString &dir);
    QStringList searchFontFiles(const QString &dir);
    void initialize();

protected:
    QMap<QString,QString> _font_map;
    QString _font_dir;
};

#endif // EXFONTPROVIDER_H
