#ifndef _ATUML_H_
#define _ATUML_H_

#include <QApplication>
#include "atumlsettingsprovider.h"

class Atuml
{
public:
    Atuml();
    ~Atuml();
    void run();

private:
    AtumlSettingsProvider *settingsProvider;
};

#endif
