#include "minecodelayerview.h"
#include "minecodelayerviewplugin.h"

#include <QtPlugin>

MinecodeLayerViewPlugin::MinecodeLayerViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MinecodeLayerViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MinecodeLayerViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MinecodeLayerViewPlugin::createWidget(QWidget *parent)
{
    return new MinecodeLayerView(parent);
}

QString MinecodeLayerViewPlugin::name() const
{
    return QLatin1String("MinecodeLayerView");
}

QString MinecodeLayerViewPlugin::group() const
{
    return QLatin1String("");
}

QIcon MinecodeLayerViewPlugin::icon() const
{
    return QIcon();
}

QString MinecodeLayerViewPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MinecodeLayerViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MinecodeLayerViewPlugin::isContainer() const
{
    return false;
}

QString MinecodeLayerViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MinecodeLayerView\" name=\"minecodeLayerView\">\n</widget>\n");
}

QString MinecodeLayerViewPlugin::includeFile() const
{
    return QLatin1String("minecodelayerview.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Minecode 2D View, MinecodeLayerViewPlugin)
#endif // QT_VERSION < 0x050000
