#include "mcppagesmanagement.h"

mcpPagesManagement::mcpPagesManagement(QObject *parent):
    QObject(parent),
    editorPage(new mcpEditorPage),
    environPage(new mcpEnvironmentPage),
    generalPage(new mcpGeneralPage),
    networkPage(new mcpNetworkPage),
    uiPage(new mcpUserInterfacePage)
{
}

mcpPagesManagement::~mcpPagesManagement()
{
    safedel(editorPage);
    safedel(environPage);
    safedel(generalPage);
    safedel(networkPage);
    safedel(uiPage);
}

QWidget* mcpPagesManagement::pagePointer(PreferencePages type)
{
    switch (type) {
    case PreferencePages::Editor:
        return dynamic_cast<QWidget*>(editorPage);
    case PreferencePages::Environment:
        return dynamic_cast<QWidget*>(environPage);
    case PreferencePages::General:
        return dynamic_cast<QWidget*>(generalPage);
    case PreferencePages::Network:
        return dynamic_cast<QWidget*>(networkPage);
    case PreferencePages::Userinterface:
        return dynamic_cast<QWidget*>(uiPage);
    default:
        return dynamic_cast<QWidget*>(generalPage);
    }
}

enum PreferencePages mcpPagesManagement::enumFromInt(int type)
{
    switch (type) {
    case 0:
        return PreferencePages::General;
    case 1:
        return PreferencePages::Userinterface;
    case 2:
        return PreferencePages::Editor;
    case 3:
        return PreferencePages::Network;
    default:
        return PreferencePages::General;
    }
}
