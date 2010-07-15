#ifndef _UMLDIAGRAM_H_
#define _UMLDIAGRAM_H_

#include <QString>

class UmlDiagram
{
private:
    QString fTitle;

public:
    UmlDiagram(QString theTitle);

    void setTitle(QString theTitle);
    QString title();
};

#endif
