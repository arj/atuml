#include "atumlsettingsprovider.h"


AtumlSettingsProvider::AtumlSettingsProvider()
{
    QCoreApplication::setOrganizationName("Bitflipper");
    QCoreApplication::setOrganizationDomain("bitflipper.de");
    QCoreApplication::setApplicationName("Atuml");
}

AtumlSettingsProvider::~AtumlSettingsProvider()
{
}


AtumlSettingsProvider& AtumlSettingsProvider::getInstance()
{
    static AtumlSettingsProvider instance;
    return instance;
}
