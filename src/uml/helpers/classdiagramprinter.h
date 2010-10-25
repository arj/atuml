#ifndef _CLASSDIAGRAMPRINTER_H_
#define _CLASSDIAGRAMPRINTER_H_

#include <QString>
#include "../classdiagram.h"

namespace atuml {

namespace uml {

class ClassDiagramPrinter
{
public:
	static QString print(const ClassDiagram &classdiagram);
};

}

}

#endif
