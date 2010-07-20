#ifndef _UMLDIAGRAM_H_
#define _UMLDIAGRAM_H_

#include <QObject>
#include <QString>

class UmlDiagram : public QObject
{
    Q_OBJECT

private:
    QString fTitle;

public:
    UmlDiagram(QString theTitle);

    QString title();

public slots:
    void setTitle(QString theTitle);

signals:
    void titleChanged(QString newTitle);
};

#endif
