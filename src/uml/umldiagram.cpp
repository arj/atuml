#include "umldiagram.h"

UmlDiagram::UmlDiagram(QString /*theTitle*/)
{
}

void UmlDiagram::setTitle(QString theTitle)
{
    fTitle = theTitle;
}

QString UmlDiagram::title()
{
    return fTitle;
}
