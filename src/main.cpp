#include <QApplication>

#include "atuml.h"

#include "uml/classdiagram.h"
#include "uml/helpers/classdiagramprinter.h"
#include "uml/classgraphicsitem.h"

void test()
{
	uml::ui::ClassGraphicsItem item("name");
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	test();
	return 0;

	Atuml atuml(app);
	return atuml.run();
}
