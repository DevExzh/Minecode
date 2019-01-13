#include "exconfigprovider.h"

exConfigProvider::exConfigProvider(QObject *parent) : QObject(parent)
{
}

void exConfigProvider::updateMinecodeDirs()
{
    QDir *minecodeDir=new QDir;
    minecodeDir->setPath(qApp->applicationDirPath()+QStringLiteral("/.minecode"));
    QFile *indexFile=new QFile;
    indexFile->setFileName(minecodeDir->path()+QStringLiteral("/MinecodeDataIndex"));

    if(!indexFile->exists())
    {
        indexFile->open(QIODevice::WriteOnly);
        indexFile->close();
    }

    if(!minecodeDir->exists())
        minecodeDir->mkdir(minecodeDir->path());

    minecodeDir->cd(QStringLiteral("logs"));
    if(!minecodeDir->exists())
        minecodeDir->mkdir(minecodeDir->path());

    minecodeDir->cdUp();
    minecodeDir->cd(QStringLiteral("settings"));
    if(!minecodeDir->exists())
        minecodeDir->mkdir(minecodeDir->path());

    minecodeDir->cdUp();
    minecodeDir->cd(QStringLiteral("userdata"));
    if(!minecodeDir->exists())
        minecodeDir->mkdir(minecodeDir->path());

    safedel(minecodeDir);
    safedel(indexFile);
}

QMap<QString,QString> exConfigProvider::readMapfromSettingFile(const QString &dir)
{
    if(dir.isEmpty())
        return QMap<QString,QString>();

    if(dir.endsWith(QStringLiteral(".mccf")))
    {
        QMap<QString,QString> configDocValue;
        QFile configFile(dir);
        QJsonParseError errorJson;
        if(configFile.exists() && configFile.open(QFile::ReadOnly))
        {
            QJsonDocument configDoc=QJsonDocument::fromJson(configFile.readAll(),&errorJson);
            if(errorJson.error==QJsonParseError::NoError)
            {
                if(configDoc.isNull()||configDoc.isEmpty()) return QMap<QString,QString>();
                else if(configDoc.isObject())
                {
                    QJsonObject mainConfigObj=configDoc.object();
                    configDocValue[QLatin1String("Version")]=mainConfigObj[QLatin1String("Version")].toVariant().toString();
                    configDocValue[QLatin1String("LastDateTimeLaunched")]=mainConfigObj[QLatin1String("LastDateTimeLaunched")].toVariant().toString();

                    QJsonObject position=mainConfigObj.value(QLatin1String("Position")).toObject();
                    for(auto key:position.keys())
                    {
                        configDocValue[key]=position[key].toVariant().toString();
                    }
                }
            }
        }
        return configDocValue;
    }

    return QMap<QString,QString>();
}

QVector<QJsonObject> exConfigProvider::readVectorfromSettingFile(const QString &dir)
{
    if(dir.isEmpty())
        return QVector<QJsonObject>();

    if(dir.endsWith(QStringLiteral(".json")))
    {
        QVector<QJsonObject> _recentProjectList;
        QFileInfoList projectInfoList=QDir(dir).entryInfoList(QStringList("*.json"),QDir::AllDirs|QDir::Files);
        for(QFileInfo recentProjectFile:projectInfoList)
        {
            if(recentProjectFile.fileName()=="."||recentProjectFile.fileName()=="..")
                continue;
            if(recentProjectFile.isFile())
            {
                QJsonParseError errorRecentProjJson;
                QJsonDocument recentProjDoc=QJsonDocument::fromJson(QFile(recentProjectFile.filePath()).readAll(),&errorRecentProjJson);
                if(errorRecentProjJson.error==QJsonParseError::NoError)
                {
                    if(recentProjDoc.isNull()||recentProjDoc.isEmpty()) return QVector<QJsonObject>();
                    else if(recentProjDoc.isObject())
                    {
                        _recentProjectList[_recentProjectList.count()]=recentProjDoc.object();
                    }
                }
            }
        }
        return _recentProjectList;
    }

    return QVector<QJsonObject>();
}
