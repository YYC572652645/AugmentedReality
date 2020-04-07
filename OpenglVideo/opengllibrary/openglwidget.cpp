#include "openglwidget.h"
#include <QMouseEvent>
#include <QVector3D>
#include <QDebug>
#include "opengllibrary/opengldef.h"

OpenglWidget::OpenglWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
}

OpenglWidget::~OpenglWidget()
{
    this->makeCurrent();
    for (auto objectModel : m_objectList)
    {
        objectModel->destory();
    }
    this->doneCurrent();
}

void OpenglWidget::initializeGL()
{
    this->initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


    m_objectList.append(OBJECT_FACTORY->makeObject(ObjectFactory::OBJECT_RECTANGLE));
    m_objectList.append(OBJECT_FACTORY->makeObject(ObjectFactory::OBJECT_TRIANGLE));
    m_objectList.append(OBJECT_FACTORY->makeObject(ObjectFactory::OBJECT_VIDEO));

    for (auto objectModel : m_objectList)
    {
        objectModel->setWindowSize(width(), height());
        objectModel->setupCamera(OpenglSpace::CAMERA_POS, OpenglSpace::TARGET_POS, OpenglSpace::WORLD_UP);
        objectModel->setupShader(OpenglSpace::VERTEX_PATH, OpenglSpace::FRAMENT_PATH);
        objectModel->setupPerspective(45.0f);
        objectModel->setupTexture(OpenglSpace::CONTAINER_PATH);
        objectModel->makeObject();
        objectModel->setOpenGLFunctions(this);
        connect(objectModel, SIGNAL(sendUpdate()), this, SLOT(receiveUpdate()));
    }
}

void OpenglWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenglWidget::paintGL()
{
    glLoadIdentity();

    glClearColor(OpenglSpace::CLEAR_COLOR.redF()
                 , OpenglSpace::CLEAR_COLOR.greenF()
                 , OpenglSpace::CLEAR_COLOR.blueF()
                 , OpenglSpace::CLEAR_COLOR.alphaF());


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto objectModel : m_objectList)
    {
        objectModel->drawObject();
    }
    glFlush();
}

void OpenglWidget::receiveUpdate()
{
    this->update();
}
