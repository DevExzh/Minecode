#ifndef EXCONFIGPROVIDER_H
#define EXCONFIGPROVIDER_H

#include <QObject>
#include <QVector>
#include <QDir>
#include <QMap>
#include <QFile>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>

#include "../exglobal.h"

import MinecodeCore;

class exConfigProvider : public QObject
{
    Q_OBJECT
public:
    explicit exConfigProvider(QObject *parent = nullptr);

public slots:
    void updateMinecodeDirs();
    QMap<QString,QString> readMapfromSettingFile(const QString &dir);
    QVector<QJsonObject> readVectorfromSettingFile(const QString &dir);
    //void writeSettingFile(const QString &fileName);

protected:
    QMap<QString,QString> _valueMap;
};

#endif // EXCONFIGPROVIDER_H
