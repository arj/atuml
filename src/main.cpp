#include <QApplication>

#include "atuml.h"
#include "uml/method.h"
#include "uml/classdiagram.h"
#include "uml/helpers/classdiagramprinter.h"

void test()
{
	/*uml::ClassDiagram cd("Diagram1");
	uml::Class myclass("MyClass");
	uml::Attribute attrib("MyAttrib");
	attrib.setType("Test");

	myclass.addAttribute(attrib);

	cd.addClass(&myclass);

	qDebug() << ClassDiagramPrinter::print(cd);*/
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	test();
	return 0;

	Atuml atuml(app);
	return atuml.run();
}
