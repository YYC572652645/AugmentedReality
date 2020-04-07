#-------------------------------------------------
#
# Project created by QtCreator 2020-03-25T20:36:02
#
#-------------------------------------------------

QT       += core gui opengl 3drender

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenglModel
TEMPLATE = app


SOURCES += main.cpp\
    opengllibrary/openglwidget.cpp \
    opengllibrary/shaderlibrary.cpp \
    opengllibrary/texturelibrary.cpp \
    opengllibrary/objectfactory.cpp \
    opengllibrary/objectmodel/objectparent.cpp \
    opengllibrary/objectmodel/objecttriangle.cpp \
    opengllibrary/objectmodel/objectrectangle.cpp \
    opengllibrary/cameralibrary.cpp \
    opengllibrary/objectmodel/objectmesh.cpp

HEADERS  += opengllibrary/openglwidget.h \
    opengllibrary/shaderlibrary.h \
    opengllibrary/texturelibrary.h \
    opengllibrary/objectfactory.h \
    opengllibrary/objectmodel/objectparent.h \
    opengllibrary/objectmodel/objecttriangle.h \
    opengllibrary/objectmodel/objectrectangle.h \
    opengllibrary/cameralibrary.h \
    opengllibrary/opengldef.h \
    opengllibrary/objectmodel/objectmesh.h

LIBS += -lopengl32

RESOURCES += \
    res/shaders.qrc \
    res/textures.qrc

DISTFILES +=
