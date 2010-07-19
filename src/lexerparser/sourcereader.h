#ifndef _SOURCEREADER_H_
#define _SOURCEREADER_H_

#include <QString>
#include "ast.h"


class SourceReader
{
public:
    SourceReader();
    virtual ~SourceReader() = 0;

    virtual AbstractSyntaxTree read(const QString file) = 0;
};

#endif
