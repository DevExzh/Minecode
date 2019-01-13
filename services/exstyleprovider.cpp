#include "exstyleprovider.h"

exStyleProvider::exStyleProvider(QObject *parent) : QObject(parent)
{
    if(self!=0) return; else self=this;
    initialize();
}

// 重复的代码，将在 Minecode Studio Release 4 时由基类 exProvider 实现
QStringList exStyleProvider::searchStyleSheetFiles(const QString &path)
{
    QStringList _result_list;
    QDirIterator iter(QDir(path),QDirIterator::Subdirectories);
    while(iter.hasNext())
    {
        iter.next();
        QFileInfo info=iter.fileInfo();
        if(info.isFile())
        {
            _result_list.append(info.absoluteFilePath());
        }
    }
    return _result_list;
}

QString exStyleProvider::getStyleSheetFromName(const QString &name)
{
#ifdef EXTOOLKIT_DEBUG
    qDebug()<<"exStyleProvider::getStyleSheetFromName -> styleMap[name] = "<<styleMap[name];
    qDebug()<<"exStyleProvider::getStyleSheetFromName -> name = "<<name;
#endif
    return styleMap[name];
}

int exStyleProvider::styleSheetCounts()
{
    return styleMap.count();
}

void exStyleProvider::registerStyleSheet(const QString &name, const QString &style)
{
    styleMap[name]=style;
}

void exStyleProvider::registerStyleSheet(QFile &file)
{
    if(file.open(QIODevice::ReadOnly))
    {
        QString fileDetail=file.readAll();
#ifdef EXTOOLKIT_DEBUG
        qDebug()<<"exStyleProvider::registerStyleSheet -> file = "<<file.fileName();
        if(QFileInfo(file).suffix()==QStringLiteral(".mccs"))
        {
            qDebug()<<"QFileInfo(file).suffix()==QStringLiteral(\".mccs\") -> boolean : true";
        }
        else
        {
            qDebug()<<"QFileInfo(file).suffix()==QStringLiteral(\".mccs\") -> boolean : false";
        }
        qDebug()<<"fileDetail.startsWith(QStringLiteral(\"[Exzh Minecode Studio Style Sheet File]\")) -> boolean : "<<fileDetail.startsWith(QStringLiteral("[Exzh Minecode Studio Style Sheet File]"));
#endif
        if(fileDetail.startsWith(QStringLiteral("[Exzh Minecode Studio Style Sheet File]")) &&
                QFileInfo(file).suffix()==QStringLiteral("mccs"))
        {
            styleMap[QFileInfo(file).fileName().remove(QStringLiteral(".mccs"))]=fileDetail.remove(QStringLiteral("[Exzh Minecode Studio Style Sheet File]\n"))
                    .remove(QStringLiteral("[Exzh Minecode Studio Style Sheet File]\r\n"));
#ifdef EXTOOLKIT_DEBUG
            qDebug()<<"exStyleProvider::registerStyleSheet -> styleMap[file] = "<<styleMap[QFileInfo(file).fileName().remove(QStringLiteral(".mccs"))];
#endif
        }
        else return;
    }
}

void exStyleProvider::registerStyleSheet(const QString &file)
{
    QFile tmpFile(file);
    registerStyleSheet(tmpFile);
}

void exStyleProvider::initialize()
{
    for(auto file:searchStyleSheetFiles(qApp->applicationDirPath()+QStringLiteral("/styles")))
    {
#ifdef EXTOOLKIT_DEBUG
        qDebug()<<"exStyleProvider::initialize -> file"<<file->fileName();
#endif
        registerStyleSheet(file);
    }
}

exStyleProvider* exStyleProvider::self=0;
