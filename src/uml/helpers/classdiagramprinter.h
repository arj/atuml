#ifndef _CLASSDIAGRAMPRINTER_H_
#define _CLASSDIAGRAMPRINTER_H_

#include <QString>
#include "../classdiagram.h"

class ClassDiagramPrinter
{
public:
	static QString print(const uml::ClassDiagram &classdiagram);
};

#endif
