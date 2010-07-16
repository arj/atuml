TEMPLATE = app
TARGET = atuml
DEPENDPATH += .
INCLUDEPATH += .

RESOURCES += src/resources/atuml.qrc

# Input
HEADERS += src/atuml.h \
           src/atumlsettingsprovider.h \
           src/uml/umldiagram.h
SOURCES += src/atuml.cpp \
           src/main.cpp \
           src/atumlsettingsprovider.cpp \
           src/uml/umldiagram.cpp

# - is necessary for nice filename, i.e
# make dist produces $TARGET$VERSION which yields atuml-0.0.1
VERSION = -0.0.1
