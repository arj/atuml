#ifndef _UMLDIAGRAM_H_
#define _UMLDIAGRAM_H_

#include <QObject>
#include <QString>

namespace uml {

/**
 * Base class for all uml diagrams.
 */
class UmlDiagram: public QObject {
Q_OBJECT

public:
	/**
	 * Constructs a new diagram with a given title.
	 *
	 * @param theTitlec The title of the uml diagram.
	 */
	UmlDiagram(QString theTitle) :
		fTitle(theTitle) {
	}

	/**
	 * (Virtual) getter for the title.
	 *
	 * @return Returns the title of the uml diagram.
	 */
	virtual QString title() const;

	/**
	 * Sets a new title for the diagram.
	 *
	 * @param theTitle The new title for the diagram.
	 */
	void setTitle(const QString &theTitle);

private:
	/**
	 * The title of the diagram.
	 */
	QString fTitle;
};

}

#endif
