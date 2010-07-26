/*
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * class.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _CLASS_H_
#define _CLASS_H_

#include <QObject>
#include <QString>
#include <QList>
#include "attribute.h"
#include "method.h"

namespace uml {

class Class : public QObject
{
    Q_OBJECT

public:
    Class(const QString name);

    void addMethod(Method method);
    void addAttribute(Attribute attribute);
    void removeMethod(Method method);
    void removeAttribute(Attribute attribute);
    const QList<Method> methods() const;
    const QList<Attribute> attributes() const;

    void setName(const QString name);
    void setAbstract(bool value);
    void setActive(bool value);

    bool abstract() const;
    QString name() const;
    bool active() const;
private:
    QString fName;
    bool fAbstract;
    bool fActive;
    QList<Attribute> fAttributes;
    QList<Method> fMethods;
};

}

#endif
