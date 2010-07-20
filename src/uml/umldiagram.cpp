#include "umldiagram.h"

void UmlDiagram::setTitle(const QString &theTitle)
{
    fTitle = theTitle;
}

QString UmlDiagram::title() const
{
    return fTitle;
}
