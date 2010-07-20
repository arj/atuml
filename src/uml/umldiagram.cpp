#include "umldiagram.h"

UmlDiagram::UmlDiagram(QString theTitle) : fTitle(theTitle)
{
}

void UmlDiagram::setTitle(QString theTitle)
{
    if (fTitle != theTitle) {
        fTitle = theTitle;
        emit titleChanged(fTitle);
    }
}

QString UmlDiagram::title()
{
    return fTitle;
}
