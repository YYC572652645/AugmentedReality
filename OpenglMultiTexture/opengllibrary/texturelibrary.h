#ifndef TEXTURELIBRARY_H
#define TEXTURELIBRARY_H
#include <QOpenGLTexture>

class TextureLibrary : public QObject
{
public:
    explicit TextureLibrary(QObject *parent = nullptr);
    ~TextureLibrary();

    void generateTexture(const QList<QString> &imagePathList);
    void appendGlTexture(const QList<QString> &imagePathList);
    void appendGlTexture(const QString &imagePath);
    void appendGlTexture(const QImage &image);
    void bind(const int &index);
    void release(const int &index);
    void destory(const int &index);
    void bindAll();
    void releaseAll();
    void clearTexture();
private:
    QOpenGLTexture *createGlTexture(const QImage &image);
    QOpenGLTexture *createGlTexture(const QString &imagePath);
private:
    QList<QOpenGLTexture*> m_glTexture;
};

#endif // TEXTURELIBRARY_H
