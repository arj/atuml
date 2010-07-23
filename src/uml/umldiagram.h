#ifndef _UMLDIAGRAM_H_
#define _UMLDIAGRAM_H_

#include <QObject>
#include <QString>

namespace uml {

class UmlDiagram : public QObject
{
    Q_OBJECT

private:
    QString fTitle;

public:
    UmlDiagram(QString theTitle) : fTitle(theTitle) {}
    virtual QString title() const;
    void setTitle(const QString &theTitle);
};

}

#endif
