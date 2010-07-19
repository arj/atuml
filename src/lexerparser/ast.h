#ifndef _AST_H_
#define _AST_H_

#include <QString>

struct Node
{
    Node(QString tokenString, int filePos) : tokenString(tokenString), filePos(filePos) {}
    QString tokenString;
    int filePos;
};

class AbstractSyntaxTree
{
public:
    AbstractSyntaxTree();
    AbstractSyntaxTree(Node node);
};

#endif
