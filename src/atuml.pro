TEMPLATE = app
TARGET = atuml
DEPENDPATH += .
INCLUDEPATH += .

RESOURCES += resources/atuml.qrc

# Input
HEADERS += atuml.h \
           atumlsettingsprovider.h \
           uml/umldiagram.h
SOURCES += atuml.cpp \
           main.cpp \
           atumlsettingsprovider.cpp \
           uml/umldiagram.cpp

# - is necessary for nice filename, i.e
# make dist produces $TARGET$VERSION which yields atuml-0.0.1
VERSION = -0.0.1
