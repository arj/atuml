#include <iostream>
#include "atuml.h"
#include "uml/umldiagram.h"

Atuml::Atuml()
{
    std::cout << "Atuml initialize" << std::endl;
    settingsProvider = &AtumlSettingsProvider::getInstance();
}

Atuml::~Atuml()
{
    std::cout << "~Atuml" << std::endl;
}

void Atuml::run()
{
    UmlDiagram ud("Hallo");
    ud.setTitle("Hallo2");
    std::cout << qPrintable(ud.title()) << std::endl;
    // Do nothing at the moment
}
