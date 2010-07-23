#include "umldiagram.h"

namespace uml {

void UmlDiagram::setTitle(const QString &theTitle)
{
    fTitle = theTitle;
}

QString UmlDiagram::title() const
{
    return fTitle;
}

}
