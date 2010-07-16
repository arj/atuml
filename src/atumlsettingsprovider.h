#ifndef _ATUMLSETTINGSPROVIDER_H_
#define _ATUMLSETTINGSPROVIDER_H_

#include <QApplication>
#include <QSettings>
#include <QVariant>

class AtumlSettingsProvider
{
private:
    AtumlSettingsProvider();
    AtumlSettingsProvider(const AtumlSettingsProvider& cc);

public:
    ~AtumlSettingsProvider();
    static AtumlSettingsProvider& getInstance();

    int getInt(int id);
    bool getBool(int id);
    QVariant get(int id);

    /* Constants for requesting the correct value */
    static const int MaxUndoCount = 1000;
    static const int ShowSplashScreen = 1001;

private:
    /* Config paths */
    static const char* const PathMaxUndoCount;
    static const char* const PathShowSplashScreen;

    /* Default values */
    static const int DefaultMaxUndoCount = 9999;
    static const bool DefaultShowSplashScreen = false;
};

#endif
