#include "atuml.h"

#include "uml/umldiagram.h"

Atuml::Atuml(QApplication &app) : application(app)
{
    splashscreen = new QSplashScreen(QPixmap(":/pictures/atuml.png"));

    settingsProvider = &AtumlSettingsProvider::getInstance();
}

Atuml::~Atuml()
{
    /* settingsprovider need not be deleted as it is a
       singleton and is designed to delete itself. */
    delete splashscreen;
}

int Atuml::run()
{
    /* Now show a splash screen during initialization of windows */
    splashscreen->show();

    showMessage("Initialization");

    // Do nothing at the moment

    return application.exec();
}

void Atuml::showMessage(QString string)
{
    splashscreen->showMessage( string + "...", Qt::AlignBottom, QColor("#1c931c"));
}
