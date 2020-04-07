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

void ObjectParent::destory()
{
    m_vao.destroy();
    m_vbo.destroy();
    m_ebo.destroy();
}

void ObjectParent::setupShader(const QString &vertexPath, const QString &fragmentPath)
{
    bool successFlage = m_shaderLibrary.compileAndBindShaderFile(vertexPath, fragmentPath);
    if(!successFlage)
    {
        qDebug() << "Compile shader error!";
    }
}

void ObjectParent::setupTexture(const QImage &image)
{
    m_textureLibrary.clearTexture();
    m_textureLibrary.appendGlTexture(image);
}

void ObjectParent::setupTexture(const QString &imagePath)
{
    m_textureLibrary.clearTexture();
    m_textureLibrary.appendGlTexture(imagePath);
}

void ObjectParent::setupTexture(const QList<QString> &imagePathList)
{
    m_textureLibrary.generateTexture(imagePathList);
}

void ObjectParent::setupCamera(QVector3D position, QVector3D target, QVector3D worldUp)
{
    m_cameraLibrary.setupCamera(position, target, worldUp);
}
void ObjectParent::setupCamera(QVector3D position, float pitch, float yaw, QVector3D worldUp)
{
    m_cameraLibrary.setupCamera(position, pitch, yaw, worldUp);
}

void ObjectParent::setWindowWidth(const int &windowWidth)
{
    m_windowWidth = windowWidth;
}

void ObjectParent::setWindowHeight(const int &windowHeight)
{
    m_windowHeight = windowHeight;
}

void ObjectParent::setWindowSize(const int &windowWidth, const int &windowHeight)
{
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
}

void ObjectParent::translateByX(const GLfloat &valueData)
{
    m_modelMat.translate(valueData, 0.0f, 0.0f);
}

void ObjectParent::translateByY(const GLfloat &valueData)
{
    m_modelMat.translate(0.0f, valueData, 0.0f);
}

void ObjectParent::translateByZ(const GLfloat &valueData)
{
    m_modelMat.translate(0.0f, 0.0f, valueData);
}

void ObjectParent::rotateByX(const GLfloat &angleData)
{
    m_modelMat.rotate(angleData, 1.0f, 0.0f, 0.0f);
}

void ObjectParent::rotateByY(const GLfloat &angleData)
{
    m_modelMat.rotate(angleData, 0.0f, 1.0f, 0.0f);
}

void ObjectParent::rotateByZ(const GLfloat &angleData)
{
    m_modelMat.rotate(angleData, 0.0f, 0.0f, 1.0f);
}

void ObjectParent::setupPerspective(const GLfloat &angleData)
{
    if (m_windowWidth != 0 && m_windowHeight != 0)
    {
        m_projMat.perspective(angleData, 1.0 * m_windowWidth / m_windowHeight, 0.1f, 100.0f);
    }
}

int ObjectParent::getVertexCount()
{
    return m_ebo.size() / sizeof(GLfloat);
}

void ObjectParent::setOpenGLFunctions(QOpenGLFunctions *openGLFunctions)
{
    m_openGLFunctions = openGLFunctions;
}

void ObjectParent::setupObjectShaderMat()
{
    m_viewMat = m_cameraLibrary.getViewMat4x4();
    m_shaderLibrary.setUniformValue("modelMat", m_modelMat);
    m_shaderLibrary.setUniformValue("viewMat", m_viewMat);
    m_shaderLibrary.setUniformValue("projMat", m_projMat);
}

void ObjectParent::makeObject()
{

}

void ObjectParent::drawObject()
{
    if (nullptr != m_openGLFunctions)
    {
        this->bind();
        this->setupObjectShaderMat();
        m_openGLFunctions->glDrawElements(GL_TRIANGLES, this->getVertexCount(), GL_UNSIGNED_INT, 0);
        this->release();
    }
}
