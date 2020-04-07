#ifndef OBJECTPARENT_H
#define OBJECTPARENT_H
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include "opengllibrary/texturelibrary.h"
#include "opengllibrary/shaderlibrary.h"

typedef struct VertexData
{
    QVector3D vertexPosition;
    QVector2D textureCoord;
} VertexData;

class ObjectParent : protected QOpenGLFunctions
{
public:
    ObjectParent();
    ~ObjectParent();
    void bind();
    void release();
    void setupShader(const QString &vertexPath, const QString &fragmentPath);
    void setupTexture(const QList<QString> &imagePath);
    virtual void makeObject();
protected:
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLBuffer m_ebo;
    ShaderLibrary m_shaderLibrary;
    TextureLibrary m_textureLibrary;
};

#endif // OBJECTPARENT_H
