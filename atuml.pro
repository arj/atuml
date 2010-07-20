TEMPLATE = app
TARGET = atuml
DEPENDPATH += .
INCLUDEPATH += .
RESOURCES += src/resources/atuml.qrc

# Input
HEADERS += src/uml/parameter.h \
    src/uml/method.h \
    src/uml/multiplicity.h \
    src/uml/attribute.h \
    src/uml/visibility.h \
    src/lexerparser/ast.h \
    src/lexerparser/sourcereader.h \
    src/uml/class.h \
    src/uml/classdiagram.h \
    src/uml/helpers/classdiagramprinter.h \
    src/atuml.h \
    src/atumlsettingsprovider.h \
    src/uml/umldiagram.h
SOURCES += src/uml/parameter.cpp \
    src/uml/method.cpp \
    src/uml/multiplicity.cpp \
    src/uml/attribute.cpp \
    src/uml/visibility.cpp \
    src/lexerparser/ast.cpp \
    src/lexerparser/sourcereader.cpp \
    src/uml/class.cpp \
    src/uml/classdiagram.cpp \
    src/uml/helpers/classdiagramprinter.cpp \
    src/atuml.cpp \
    src/main.cpp \
    src/atumlsettingsprovider.cpp \
    src/uml/umldiagram.cpp

# - is necessary for nice filename, i.e
# make dist produces $TARGET$VERSION which yields atuml-0.0.1
VERSION = -0.0.1
