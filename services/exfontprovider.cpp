#include "exfontprovider.h"

exFontProvider::exFontProvider(QObject *parent) :
    QObject(parent)
{
}

void exFontProvider::initialize()
{
    for(QString fontFile:searchFontFiles(_font_dir))
    {
        registerFont(fontFamily(fontFile),fontFile);
    }
}

void exFontProvider::setFontFolder(const QString &dir)
{
    _font_dir=dir;
}

void exFontProvider::registerFont(const QString &family, const QString &file)
{
    _font_map[family]=file;
}

// 重复的代码，将在 Minecode Studio Release 4 时由基类 exProvider 实现
QStringList exFontProvider::searchFontFiles(const QString &dir)
{
    QStringList _result_list;
    QDirIterator iter(QDir(dir),QDirIterator::Subdirectories);
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

QFont exFontProvider::registeredFont(const QString &family)
{
    if(!family.isEmpty())
    {
        if(!_font_map.isEmpty())
            return QFont(family);
        else return QFont();
    }
    else return QFont();
}

QString exFontProvider::fontFamily(const QString &file)
{
    QFile fontFile(file);
    if(fontFile.open(QIODevice::ReadOnly))
    {
        int registeredFontID=QFontDatabase::addApplicationFont(file);
        QStringList fontList=QFontDatabase::applicationFontFamilies(registeredFontID);
        if(!fontList.isEmpty())
        {
            fontFile.close();
            return fontList.at(0);
        }
    }
    return QString();
}
