#ifndef _ATUMLSETTINGSPROVIDER_H_
#define _ATUMLSETTINGSPROVIDER_H_

#include <QApplication>
#include <QSettings>

class AtumlSettingsProvider
{
private:
    AtumlSettingsProvider();
    AtumlSettingsProvider(const AtumlSettingsProvider& cc);

public:
    ~AtumlSettingsProvider();
    static AtumlSettingsProvider& getInstance();

    int getInt(int id);

    /* Constants for requesting the correct value */
    static const int MaxUndoCount = 1000;

    /* Default values */
    static const int DefaultMaxUndoCount = 9999;
};

#endif
