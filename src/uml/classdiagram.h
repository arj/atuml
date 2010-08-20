#ifndef _CLASSGIAGRAM_H_
#define _CLASSGIAGRAM_H_

#include "umldiagram.h"
#include "class.h"
#include <QList>

namespace uml {

/**
 * Implementation of a simple class diagram.
 */
class ClassDiagram : public UmlDiagram
{
public:
    /**
     * Default constructor with diagram title.
     * This default constructor simply calls the constructor
     * of the parent class.
     */
	ClassDiagram(QString title) : UmlDiagram(title) {}

    /**
     * Adds a new class to the diagram.
     * Caller is responsible for class pointer cleanup.
     */
	void addClass(Class *theclass);

    // Getters
    const QList<Class*> classes() const;
private:
	QList<Class*> fClasses;
};

}

#endif
