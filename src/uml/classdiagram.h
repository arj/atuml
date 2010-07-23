#ifndef _CLASSGIAGRAM_H_
#define _CLASSGIAGRAM_H_

#include "umldiagram.h"
#include "class.h"
#include <QList>

namespace uml {

class ClassDiagram : public UmlDiagram
{
public:
	ClassDiagram(QString title) : UmlDiagram(title) {}

	void addClass(Class *theclass);
private:
	QList<Class*> fClasses;
};

}

#endif
