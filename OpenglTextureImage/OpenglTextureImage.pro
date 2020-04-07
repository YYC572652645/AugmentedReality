#-------------------------------------------------
#
# Project created by QtCreator 2020-03-25T20:36:02
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenglTextureImage
TEMPLATE = app


SOURCES += main.cpp\
    opengllibrary/openglwidget.cpp \
    opengllibrary/shaderlibrary.cpp \
    opengllibrary/texturelibrary.cpp

HEADERS  += opengllibrary/openglwidget.h \
    opengllibrary/shaderlibrary.h \
    opengllibrary/texturelibrary.h

LIBS += -lopengl32

RESOURCES += \
    res/shaders.qrc \
    res/textures.qrc

DISTFILES +=
