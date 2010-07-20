#include "classdiagram.h"

ClassDiagram::ClassDiagram(QString title) : UmlDiagram(title)
{
}

QString ClassDiagram::title()
{
	return UmlDiagram::title();
}

