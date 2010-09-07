#include "classdiagramprinter.h"

namespace atuml {

namespace uml {

QString ClassDiagramPrinter::print(const ClassDiagram &classdiagram)
{
	QString str = QString("ClassDiagram {title: %1}").arg(classdiagram.title());

	return str;
}

}

}
