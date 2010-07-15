#ifndef _ATUMLSETTINGSPROVIDER_H_
#define _ATUMLSETTINGSPROVIDER_H_

#include <QApplication>

class AtumlSettingsProvider
{
private:
    AtumlSettingsProvider();
    AtumlSettingsProvider(const AtumlSettingsProvider& cc);

public:
    ~AtumlSettingsProvider();
    static AtumlSettingsProvider& getInstance();
};

#endif
