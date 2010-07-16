#include "atumlsettingsprovider.h"

const char* const AtumlSettingsProvider::PathMaxUndoCount = "ui/MaxUndoCount";
const char* const AtumlSettingsProvider::PathShowSplashScreen = "ui/ShowSplashScreen";

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

int AtumlSettingsProvider::getInt(int id)
{
    return get(id).toInt();
}

bool AtumlSettingsProvider::getBool(int id)
{
    return get(id).toBool();
}

QVariant AtumlSettingsProvider::get(int id)
{
    QSettings settings; // TODO remove this from here?
    if (id == MaxUndoCount)
    {
        return settings.value(PathMaxUndoCount, DefaultMaxUndoCount);
    }
    else if (id == ShowSplashScreen)
    {
    	return settings.value(PathShowSplashScreen, DefaultShowSplashScreen);
    }

    return QVariant();
}

