#-------------------------------------------------
#
# Project created by QtCreator 2020-03-25T20:36:02
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenglWindow
TEMPLATE = app


SOURCES += main.cpp\
    opengllibrary/openglwidget.cpp

HEADERS  += opengllibrary/openglwidget.h

LIBS += -lopengl32
