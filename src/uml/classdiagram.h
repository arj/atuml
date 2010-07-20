#ifndef _CLASSGIAGRAM_H_
#define _CLASSDIAGRAM_H_

#include "umldiagram.h"
#include "class.h"
#include <QList>

class ClassDiagram : public UmlDiagram
{
public:
	QString title();
	ClassDiagram(QString title);

private:
	QList<Class*> classes;
};

#endif
