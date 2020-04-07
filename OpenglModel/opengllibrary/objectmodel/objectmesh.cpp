#include "objectmesh.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>

ObjectMesh::ObjectMesh()
{

}

ObjectMesh::~ObjectMesh()
{

}

void ObjectMesh::initValue()
{
    this->initializeOpenGLFunctions();
}

void ObjectMesh::makeObject()
{
    m_vao.create();
    m_vao.bind();

    QVector<VertexData> vboData;

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(0.4, 0.6, 0.0);
        vertexData.textureCoord = QVector2D(0.5, 1.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(0.0, -0.6, 0.0);
        vertexData.textureCoord = QVector2D(1.0, 0.0);
        vboData.append(vertexData);
    }

    {
        VertexData vertexData;
        vertexData.vertexPosition = QVector3D(0.8, -0.6, 0.0);
        vertexData.textureCoord = QVector2D(0.0, 0.0);
        vboData.append(vertexData);
    }

    QVector<int> eboData;
    eboData.append(0);
    eboData.append(1);
    eboData.append(2);

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

bool ObjectMesh::load(QString fileName, QVector<float> &vPoints,QVector<float> &tPoints, QVector<float> &nPoints)
{
    QFileInfo fileInfo(fileName);
    if(fileInfo.suffix() != ".obj") return false;

    QFile objFile(fileName);
    if(!objFile.open(QIODevice::ReadOnly)) return false;

    QVector<float> vertextPoints,texturePoints,normalPoints;
    QVector<std::tuple<int,int,int>> facesIndexs;
    while (!objFile.atEnd())
    {
        QByteArray lineData = objFile.readLine();
        lineData = lineData.remove(lineData.count() - 2,2);
        if(lineData.isEmpty())
        {
            for(auto &verFaceInfo : facesIndexs)
            {
                int vIndex = std::get<0>(verFaceInfo);
                int tIndex = std::get<1>(verFaceInfo);
                int nIndex = std::get<2>(verFaceInfo);
                int vPointSizes = vertextPoints.count() / 3;
                int tPointSizes = texturePoints.count() / 2;
                int nPointSizes = normalPoints.count() / 3;
                vPoints << vertextPoints.at((vPointSizes + vIndex) * 3);
                vPoints << vertextPoints.at((vPointSizes + vIndex) * 3 + 1);
                vPoints << vertextPoints.at((vPointSizes + vIndex) * 3 + 2);

                tPoints << texturePoints.at((tPointSizes + tIndex) * 2);
                tPoints << texturePoints.at((tPointSizes + tIndex) * 2 + 1);

                nPoints << normalPoints.at((nPointSizes + nIndex) * 3);
                nPoints << normalPoints.at((nPointSizes + nIndex) * 3 + 1);
                nPoints << normalPoints.at((nPointSizes + nIndex) * 3 + 2);
            }
            vertextPoints.clear();
            texturePoints.clear();
            normalPoints.clear();
            facesIndexs.clear();
            continue;
        }

        QList<QByteArray> strValues = lineData.split(' ');
        QString dataType = strValues.takeFirst();
        if(dataType == "v")
        {
            std::transform(strValues.begin(),strValues.end(),std::back_inserter(vertextPoints),[](QByteArray &str){
                return str.toFloat();
            });
        }else if(dataType == "vt")
        {
            std::transform(strValues.begin(),strValues.end(),std::back_inserter(texturePoints),[](QByteArray &str){
                return str.toFloat();
            });
        }else if(dataType == "vn")
        {
            std::transform(strValues.begin(),strValues.end(),std::back_inserter(normalPoints),[](QByteArray &str){
                return str.toFloat();
            });
        }else if(dataType == "f")
        {
            std::transform(strValues.begin(),strValues.end(),std::back_inserter(facesIndexs),[](QByteArray &str){
                QList<QByteArray> intStr = str.split('/');
                return std::make_tuple(intStr.first().toInt(),intStr.at(1).toInt(),intStr.last().toInt());
            });
        }
    }
    objFile.close();
}
