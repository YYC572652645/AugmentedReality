#include "objectvideo.h"
#include <QDebug>

ObjectVideo::ObjectVideo()
{
this->initValue();
}

ObjectVideo::~ObjectVideo()
{

}

void ObjectVideo::initValue()
{
    connect(&m_videoAnalyze, SIGNAL(sendBufImage(QImage)), this, SLOT(receiveBufImage(QImage)));
    m_videoAnalyze.start();
}

void ObjectVideo::makeObject()
{
    m_vao.create();
    m_vao.bind();

    QVector<VertexData> vboData;
    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(-1.0, 1.0, 0.0);
        vertexData.textureCoord = QVector2D(0.0, 1.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(1.0, 1.0, 0.0);
        vertexData.textureCoord = QVector2D(1.0, 1.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(1.0, -1.0, 0.0);
        vertexData.textureCoord = QVector2D(1.0, 0.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(-1.0, -1.0, 0.0);
        vertexData.textureCoord = QVector2D(0.0, 0.0);
        vboData.append(vertexData);
    }


    QVector<int> eboData;
    eboData.append(0);
    eboData.append(1);
    eboData.append(2);
    eboData.append(0);
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
    m_vbo.release();
}

void ObjectVideo::receiveBufImage(QImage bufImage)
{
    this->setupTexture(bufImage);
    emit sendUpdate();
}
