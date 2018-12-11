#ifndef EXTAPPCONFIG_H
#define EXTAPPCONFIG_H

#include <QThread>
#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "Helper/minecodestringhelper.h"

using namespace MinecodeHelper::StringHelper;

class extAppConfig : public QThread
{
    Q_OBJECT
public:
    explicit extAppConfig(QObject *parent=0);
    void run();
    void stop();
};

#endif // EXTAPPCONFIG_H
