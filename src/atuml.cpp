#include "atuml.h"

Atuml::Atuml()
{
    settingsProvider = &AtumlSettingsProvider::getInstance();
}

Atuml::~Atuml()
{
}

void Atuml::run()
{
    // Do nothing at the moment
}
