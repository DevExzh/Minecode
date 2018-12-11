#include "extappconfig.h"

extAppConfig::extAppConfig(QObject *parent):
    QObject(parent)

{

}

void extAppConfig::run()
{
    QXmlStreamWriter *settingsWriter=new QXmlStreamWriter;
    settingsWriter->setAutoFormatting(true);
    settingsWriter->writeStartDocument();
    settingsWriter->writeStartElement("MinecodeStudio");
    settingsWriter->writeAttribute("docAutoSave",convertBoolToString(false));
    settingsWriter->writeAttribute("docExtensionVisiable",convertBoolToString(false));
    settingsWriter->writeEndElement();
    settingsWriter->writeEndDocument();
}
