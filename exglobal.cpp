#include "exglobal.h"

bool MinecodeCore::converseBoolean(bool boolean)
{
    if(boolean) return false;
    else return true;
}

QDir* MinecodeCore::autoDir(const QString &dir)
{
    QDir *operatorDir=new QDir(dir);
    if(!operatorDir->exists())
        operatorDir->mkpath(dir);
    return operatorDir;
}

QFile* MinecodeCore::autoFile(const QString &file)
{
    QFile *operatorFile=new QFile(file);
    if(!operatorFile->exists())
    {
        QFileInfo *info=new QFileInfo(*operatorFile);
        if(!QDir(info->path()).exists())
        {
            QDir(info->path()).mkdir(info->path());
        }

        if(!operatorFile->open(QIODevice::WriteOnly|QIODevice::Text))
        {
            qWarning("Cannot open the file :"+file.toLocal8Bit());
        }
        safedel(info);
    }
    return operatorFile;
}

QString MinecodeCore::appendSpaces(int length)
{
    QString _result;
    for(int i=0;i<length;++i)
    {
        _result+=QString(" ");
    }
    return _result;
}

bool MinecodeCore::isLetter(const QString &input, CaseSensitive sensitive)
{
    bool boolean=false;
    for(int i=0;i<input.length();++i)
    {
        if(sensitive==CaseSensitive::Sensitive)
        {
            if(input[i]>="a"&&input[i]<="z")
            {
                boolean=true;
            }
            else boolean=false;
        }
        else if(sensitive==CaseSensitive::Insensitive)
        {
            if((input[i]>="a"&&input[i]<="z") || (input[i]>="A"&&input[i]<="Z"))
            {
                boolean=true;
            }
            else boolean=false;
        }
    }
    return boolean;
}
