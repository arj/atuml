#include <QApplication>

#include "atuml.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Atuml atuml(app);
	return atuml.run();
}
