#include "openglwidget.h"
#include <QMouseEvent>
#include <QVector3D>
#include <QDebug>

OpenglWidget::OpenglWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
}

OpenglWidget::~OpenglWidget()
{
}

void OpenglWidget::initializeGL()
{
    this->initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);

    // 深度测试
    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);

    glClearDepth(1.0);

    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    m_objectTriangle = OBJECT_FACTORY->makeObject(ObjectFactory::OBJECT_TRIANGLE);
    m_objectTriangle->setupShader(":/shader/vertex.glsl", ":/shader/frament.glsl");
    QList<QString> listPath;
    listPath.append(":/texture/container.jpg");
    m_objectTriangle->setupTexture(listPath);
    m_objectTriangle->makeObject();

    m_objectRectangle = OBJECT_FACTORY->makeObject(ObjectFactory::OBJECT_RECTANGLE);
    m_objectRectangle->setupShader(":/shader/vertex.glsl", ":/shader/frament.glsl");
    listPath.clear();
    listPath.append(":/texture/container.jpg");
    m_objectRectangle->setupTexture(listPath);
    m_objectRectangle->makeObject();
}

void OpenglWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenglWidget::paintGL()
{
    glLoadIdentity();

    glClearColor(0.25, 0.25, 0.5, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (nullptr != m_objectTriangle)
    {
        m_objectTriangle->bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        m_objectTriangle->release();
    }

    if (nullptr != m_objectRectangle)
    {
        m_objectRectangle->bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        m_objectRectangle->release();
    }
    glFlush();
}
