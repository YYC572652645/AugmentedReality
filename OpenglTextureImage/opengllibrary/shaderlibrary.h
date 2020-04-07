#ifndef SHADERLIBRARY_H
#define SHADERLIBRARY_H

#include <QObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>

class ShaderLibrary : public QOpenGLShaderProgram
{
    Q_OBJECT
public:
    explicit ShaderLibrary(QObject *parent = 0);
    ~ShaderLibrary();
    bool compileAndBindShaderFile(const QString &vertexPath, const QString &fragmentPath);
    void setupAndEnableGlslValue(const QString &attributeName, const int &offset, const int &tupleSize, const int &stride);
};

#endif // SHADERLIBRARY_H
