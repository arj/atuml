#include <QApplication>

#include "atuml.h"
#include "uml/method.h"
#include "uml/classdiagram.h"
#include "uml/helpers/classdiagramprinter.h"
#include "uml/classgraphicsitem.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Atuml atuml(app);
	return atuml.run();
}
