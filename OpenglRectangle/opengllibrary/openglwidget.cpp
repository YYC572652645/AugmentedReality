#include "openglwidget.h"
#include <QMouseEvent>
#include <QVector3D>
#include <QDebug>

OpenglWidget::OpenglWidget(QWidget *parent) :
    QOpenGLWidget(parent)
  ,m_vbo(QOpenGLBuffer::VertexBuffer)
  ,m_ebo(QOpenGLBuffer::IndexBuffer)
{
}

OpenglWidget::~OpenglWidget()
{
}

void OpenglWidget::initializeGL()
{
    this->initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);

    bool successFlage = shaderLibrary.compileAndBindShaderFile(":/shader/vertex.glsl", ":/shader/frament.glsl");
    if(!successFlage)
    {
        qDebug() << "Compile shader error!";
    }

    QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);

    QVector<QVector3D> vboData;
    vboData.append(QVector3D(-0.5, 0.5, 0.0));
    vboData.append(QVector3D(0.5, 0.5, 0.0));
    vboData.append(QVector3D(0.5, -0.5, 0.0));
    vboData.append(QVector3D(-0.5, -0.5, 0.0));

    QVector<int> eboData;
    eboData.append(0);
    eboData.append(1);
    eboData.append(3);
    eboData.append(1);
    eboData.append(2);
    eboData.append(3);

    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(vboData.constData(), vboData.count() * sizeof(QVector3D));

    m_ebo.create();
    m_ebo.bind();
    m_ebo.allocate(eboData.constData(), eboData.count() * sizeof(int));

    shaderLibrary.setupAndEnableGlslValue("aPosition", 0, 3);
}

void OpenglWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenglWidget::paintGL()
{
    glClearColor(0.25, 0.25, 0.5, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderLibrary.bind();
    {
        QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    shaderLibrary.release();
}
