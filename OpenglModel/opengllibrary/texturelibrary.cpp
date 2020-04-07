#include "texturelibrary.h"

TextureLibrary::TextureLibrary(QObject *parent) : QObject(parent)
{

}

TextureLibrary::~TextureLibrary()
{

}

void TextureLibrary::generateTexture(const QList<QString> &imagePathList)
{
    if (!m_glTexture.isEmpty())
    {
        this->clearTexture();
    }

    for (QString imagePath : imagePathList)
    {
        this->appendGlTexture(imagePath);
    }
}

void TextureLibrary::clearTexture()
{
    for (QOpenGLTexture* glTexture : m_glTexture)
    {
        if (nullptr != glTexture)
        {
            delete glTexture;
            glTexture = nullptr;
        }
    }
    m_glTexture.clear();
}

void TextureLibrary::appendGlTexture(const QList<QString> &imagePathList)
{
    for (auto imagePath : imagePathList)
    {
        this->createGlTexture(imagePath);
    }
}

void TextureLibrary::appendGlTexture(const QString &imagePath)
{
    m_glTexture.append(this->createGlTexture(imagePath));
}

void TextureLibrary::appendGlTexture(const QImage &image)
{
    if (!image.isNull())
    {
        m_glTexture.append(this->createGlTexture(image.mirrored()));
    }
}

void TextureLibrary::destory(const int &index)
{
    if (index >= 0 && index < m_glTexture.size())
    {
        m_glTexture[index]->destroy();
        delete m_glTexture[index];
        m_glTexture[index] = nullptr;
        m_glTexture.removeAt(index);
    }
}

void TextureLibrary::bind(const int &index)
{
    if (index >= 0 && index < m_glTexture.size())
    {
        m_glTexture[index]->bind();
    }
}

void TextureLibrary::bindAll()
{
    for(QOpenGLTexture* glTexture : m_glTexture)
    {
        glTexture->bind();
    }
}

void TextureLibrary::release(const int &index)
{
    if (index >= 0 && index < m_glTexture.size())
    {
        m_glTexture[index]->release();
    }
}

void TextureLibrary::releaseAll()
{
    for(QOpenGLTexture* glTexture : m_glTexture)
    {
        glTexture->release();
    }
}

QOpenGLTexture *TextureLibrary::createGlTexture(const QImage &image)
{
    QOpenGLTexture *glTexture = new QOpenGLTexture(image);

    glTexture->allocateStorage(QOpenGLTexture::RGB, QOpenGLTexture::UInt8);

    glTexture->setMagnificationFilter(QOpenGLTexture::Linear);

    glTexture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);

    return glTexture;
}

QOpenGLTexture *TextureLibrary::createGlTexture(const QString &imagePath)
{
    QOpenGLTexture *glTexture = new QOpenGLTexture(QImage(imagePath).mirrored());

    glTexture->setMinificationFilter(QOpenGLTexture::Nearest);

    glTexture->setMagnificationFilter(QOpenGLTexture::Linear);

    glTexture->setWrapMode(QOpenGLTexture::Repeat);

    return glTexture;
}

