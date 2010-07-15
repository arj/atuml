#include "atumlsettingsprovider.h"

#include <iostream>

AtumlSettingsProvider::AtumlSettingsProvider()
{
    std::cout << "AtumlSettingsProvider" << std::endl;
    QCoreApplication::setOrganizationName("Bitflipper");
    QCoreApplication::setOrganizationDomain("bitflipper.de");
    QCoreApplication::setApplicationName("Atuml");
}

AtumlSettingsProvider::~AtumlSettingsProvider()
{
    std::cout << "~AtumlSettingsProvider" << std::endl;
}


AtumlSettingsProvider& AtumlSettingsProvider::getInstance()
{
    static AtumlSettingsProvider instance;
    return instance;
}

int AtumlSettingsProvider::getInt(int id)
{
    QSettings settings; // TODO remove this from here
    if (id == MaxUndoCount)
    {
        return settings.value("ui/MaxUndoCount", DefaultMaxUndoCount).toInt();
    }

    // TODO throw some exception? Errorhandling?
    return 0;
}
