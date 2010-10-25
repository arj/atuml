#include "umldiagram.h"

namespace atuml {

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

}
