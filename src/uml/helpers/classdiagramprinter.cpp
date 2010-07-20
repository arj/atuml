#include "classdiagramprinter.h"

QString ClassDiagramPrinter::print(const ClassDiagram &classdiagram)
{
	QString str = QString("ClassDiagram {title: %1}").arg(classdiagram.title());

	return str;
}
