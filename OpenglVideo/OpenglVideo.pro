#-------------------------------------------------
#
# Project created by QtCreator 2020-03-25T20:36:02
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenglVideo
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
    opengllibrary/objectmodel/videoanalyze.cpp \
    opengllibrary/objectmodel/objectvideo.cpp \

HEADERS  += opengllibrary/openglwidget.h \
    opengllibrary/shaderlibrary.h \
    opengllibrary/texturelibrary.h \
    opengllibrary/objectfactory.h \
    opengllibrary/objectmodel/objectparent.h \
    opengllibrary/objectmodel/objecttriangle.h \
    opengllibrary/objectmodel/objectrectangle.h \
    opengllibrary/cameralibrary.h \
    opengllibrary/opengldef.h \
    opengllibrary/objectmodel/videoanalyze.h \
    opengllibrary/objectmodel/objectvideo.h \

LIBS += -lopengl32

RESOURCES += \
    res/shaders.qrc \
    res/textures.qrc

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release):
{
LIBS += -L$$PWD/lib/ -llibopencv_calib3d320.dll \
-llibopencv_calib3d320.dll \
-llibopencv_core320.dll \
-llibopencv_features2d320.dll \
-llibopencv_flann320.dll \
-llibopencv_highgui320.dll \
-llibopencv_imgcodecs320.dll \
-llibopencv_imgproc320.dll \
-llibopencv_ml320.dll \
-llibopencv_objdetect320.dll \
-llibopencv_photo320.dll \
-llibopencv_shape320.dll \
-llibopencv_stitching320.dll \
-llibopencv_superres320.dll \
-llibopencv_video320.dll \
-llibopencv_videoio320.dll \
-llibopencv_videostab320.dll
}
