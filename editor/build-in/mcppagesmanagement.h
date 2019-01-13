#ifndef MCPPAGESMANAGEMENT_H
#define MCPPAGESMANAGEMENT_H

#include <QObject>
#include <QHash>
#include <QWidget>

#include "mcpeditorpage.h"
#include "mcpenvironmentpage.h"
#include "mcpgeneralpage.h"
#include "mcpnetworkpage.h"
#include "mcpuserinterfacepage.h"

#include "../../exglobal.h"

import MinecodeCore;

enum class PreferencePages : int
{
    Editor = 3,
    Environment = 2,
    General = 0,
    Network = 4,
    Userinterface = 1,
};

// 管理偏好设置页
class mcpPagesManagement : public QObject
{
    Q_OBJECT
public:
    explicit mcpPagesManagement(QObject *parent = nullptr);
    ~mcpPagesManagement();
    enum PreferencePages enumFromInt(int type);
    QWidget* pagePointer(PreferencePages type);
    mcpEditorPage* pageEditor(){return editorPage;}
    mcpEnvironmentPage* pageEnvironment(){return environPage;}
    mcpGeneralPage* pageGeneral(){return generalPage;}
    mcpNetworkPage* pageNetwork(){return networkPage;}
    mcpUserInterfacePage* pageUserinterface(){return uiPage;}

protected:
    mcpEditorPage *editorPage;
    mcpEnvironmentPage *environPage;
    mcpGeneralPage *generalPage;
    mcpNetworkPage *networkPage;
    mcpUserInterfacePage *uiPage;
};

#endif // MCPPAGESMANAGEMENT_H
