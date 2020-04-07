#include "objectparent.h"

ObjectParent::ObjectParent() : m_vbo(QOpenGLBuffer::VertexBuffer), m_ebo(QOpenGLBuffer::IndexBuffer)
{

}

ObjectParent::~ObjectParent()
{

}

void ObjectParent::bind()
{
    m_shaderLibrary.bind();
    m_textureLibrary.bindAll();
    m_vao.bind();
}

void ObjectParent::release()
{
    m_textureLibrary.releaseAll();
    m_shaderLibrary.release();
    m_vao.release();
}

void ObjectParent::setupShader(const QString &vertexPath, const QString &fragmentPath)
{
    bool successFlage = m_shaderLibrary.compileAndBindShaderFile(vertexPath, fragmentPath);
    if(!successFlage)
    {
        qDebug() << "Compile shader error!";
    }
}

void ObjectParent::setupTexture(const QList<QString> &imagePath)
{
    m_textureLibrary.generateTexture(imagePath);
}

void ObjectParent::makeObject()
{

}
