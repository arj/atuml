TEMPLATE = app
TARGET = atuml
DEPENDPATH += .
INCLUDEPATH += .

RESOURCES += src/resources/atuml.qrc

# Input
HEADERS += src/atuml.h \
           src/atumlsettingsprovider.h \
           src/uml/umldiagram.h \
		   src/uml/classdiagram.h \
		   src/uml/class.h \
		   src/uml/helpers/classdiagramprinter.h
SOURCES += src/atuml.cpp \
           src/main.cpp \
           src/atumlsettingsprovider.cpp \
           src/uml/umldiagram.cpp \
		   src/uml/classdiagram.cpp \
		   src/uml/class.cpp \
		   src/uml/helpers/classdiagramprinter.cpp

# - is necessary for nice filename, i.e
# make dist produces $TARGET$VERSION which yields atuml-0.0.1
VERSION = -0.0.1
