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

    // 初始化着色器
    bool successFlage = m_shaderLibrary.compileAndBindShaderFile(":/shader/vertex.glsl", ":/shader/frament.glsl");
    if(!successFlage)
    {
        qDebug() << "Compile shader error!";
    }

    // 初始化纹理
    m_textureLibrary.appendGlTexture(":/texture/container.jpg");

    QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);

    QVector<VertexData> vboData;
    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(-0.5, 0.5, 0.0);
        vertexData.textureCoord = QVector2D(0.0, 1.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(0.5, 0.5, 0.0);
        vertexData.textureCoord = QVector2D(1.0, 1.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(0.5, -0.5, 0.0);
        vertexData.textureCoord = QVector2D(1.0, 0.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(-0.5, -0.5, 0.0);
        vertexData.textureCoord = QVector2D(0.0, 0.0);
        vboData.append(vertexData);
    }

    QVector<int> eboData;
    eboData.append(0);
    eboData.append(1);
    eboData.append(3);
    eboData.append(1);
    eboData.append(2);
    eboData.append(3);

    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(vboData.constData(), vboData.count() * sizeof(VertexData));

    m_ebo.create();
    m_ebo.bind();
    m_ebo.allocate(eboData.constData(), eboData.count() * sizeof(int));

    m_shaderLibrary.setupAndEnableGlslValue("aPosition", 0, 3, 5 * sizeof(GLfloat));
    m_shaderLibrary.setupAndEnableGlslValue("aTextCoord", sizeof(QVector3D), 2, 5 * sizeof(GLfloat));
    m_shaderLibrary.setUniformValue("textureImage", 0);
}

void OpenglWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenglWidget::paintGL()
{
    glClearColor(0.25, 0.25, 0.5, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_shaderLibrary.bind();
    m_textureLibrary.bindAll();
    {
        QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    m_textureLibrary.releaseAll();
    m_shaderLibrary.release();
}
