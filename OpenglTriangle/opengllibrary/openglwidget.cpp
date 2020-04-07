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

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/vertex.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/frament.glsl");

    shaderProgram.link();
    shaderProgram.bind();

    QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);

    QVector<QVector3D> vboData;
    vboData.append(QVector3D(0.0, 0.5, 0.0));
    vboData.append(QVector3D(0.5, -0.5, 0.0));
    vboData.append(QVector3D(-0.5, -0.5, 0.0));

    QVector<int> eboData;
    eboData.append(0);
    eboData.append(1);
    eboData.append(2);

    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(vboData.constData(), vboData.count() * sizeof(QVector3D));

    m_ebo.create();
    m_ebo.bind();
    m_ebo.allocate(eboData.constData(), eboData.count() * sizeof(int));


    int vPosition = shaderProgram.attributeLocation("aPosition");
    shaderProgram.setAttributeBuffer(vPosition, GL_FLOAT, 0, 3, sizeof(GLfloat) * 3);
    shaderProgram.enableAttributeArray(vPosition);
}

void OpenglWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenglWidget::paintGL()
{
    glClearColor(0.25, 0.25, 0.5, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.bind();
    {
        QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    }
    shaderProgram.release();
}
