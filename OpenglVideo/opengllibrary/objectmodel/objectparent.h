#ifndef OBJECTPARENT_H
#define OBJECTPARENT_H
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <QOpenGLWidget>
#include "opengllibrary/texturelibrary.h"
#include "opengllibrary/shaderlibrary.h"
#include "opengllibrary/cameralibrary.h"

typedef struct VertexData
{
    QVector3D vertexPosition;
    QVector2D textureCoord;
} VertexData;

class ObjectParent : public QObject
{
    Q_OBJECT
public:
    ObjectParent();
    virtual ~ObjectParent();
    void bind();
    void release();
    void destory();
    virtual void makeObject();
    virtual void drawObject();
    virtual void setupObjectShaderMat();
    void setupShader(const QString &vertexPath, const QString &fragmentPath);
    void setupTexture(const QImage &image);
    void setupTexture(const QString &imagePath);
    void setupTexture(const QList<QString> &imagePathList);
    void setupCamera(QVector3D position, QVector3D target, QVector3D worldUp);
    void setupCamera(QVector3D position, float pitch, float yaw, QVector3D worldUp);
    void setWindowWidth(const int &windowWidth);
    void setWindowHeight(const int &windowHeight);
    void setWindowSize(const int &windowWidth, const int &windowHeight);
    void translateByX(const GLfloat &valueData);
    void translateByY(const GLfloat &valueData);
    void translateByZ(const GLfloat &valueData);
    void rotateByX(const GLfloat &angleData);
    void rotateByY(const GLfloat &angleData);
    void rotateByZ(const GLfloat &angleData);
    void setupPerspective(const GLfloat &angleData);
    void setOpenGLFunctions(QOpenGLFunctions *openGLFunctions);
    int getVertexCount();
signals:
    void sendUpdate();
protected:
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLBuffer m_ebo;
    ShaderLibrary m_shaderLibrary;
    TextureLibrary m_textureLibrary;
    CameraLibrary m_cameraLibrary;
    QMatrix4x4 m_modelMat;
    QMatrix4x4 m_viewMat;
    QMatrix4x4 m_projMat;
    QOpenGLFunctions *m_openGLFunctions;
    int m_windowWidth;
    int m_windowHeight;
};

#endif // OBJECTPARENT_H
