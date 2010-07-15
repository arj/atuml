#ifndef _ATUML_H_
#define _ATUML_H_

#include <QApplication>
#include <QtGui>
#include "atumlsettingsprovider.h"

class Atuml
{
public:
    Atuml(QApplication &app);
    ~Atuml();
    int run();

private:
    AtumlSettingsProvider *settingsProvider;
    QApplication &application;
    QSplashScreen *splashscreen;

    void showMessage(QString string);
};

#endif
