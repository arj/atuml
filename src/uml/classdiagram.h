#ifndef _CLASSGIAGRAM_H_
#define _CLASSGIAGRAM_H_

#include "umldiagram.h"
#include "class.h"
#include <QList>


namespace atuml {

namespace uml {

/**
 * Implementation of a simple class diagram.
 */
class ClassDiagram: public UmlDiagram {
public:
	/**
	 * Default constructor with diagram title.
	 * This default constructor simply calls the constructor
	 * of the parent class.
	 *
	 * @param title The title of the diagram.
	 */
	ClassDiagram(QString title) :
		UmlDiagram(title) {
	}

	/**
	 * Adds a new class to the diagram.
	 * Caller is responsible for class pointer cleanup.
	 *
	 * @param theclass The new class to add.
	 */
	void addClass(Class* theclass);

	/**
	 * Getter for the list of classes which are represented in the ClassDiagram.
	 *
	 * @return Returns a read only list of classes.
	 */
	const QList<Class*> classes() const;
private:
	/**
	 * The list of classes.
	 */
	QList<Class*> fClasses;
};

}

}

#endif
