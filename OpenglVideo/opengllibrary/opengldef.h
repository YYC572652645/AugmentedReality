#ifndef OPENGLDEF_H
#define OPENGLDEF_H
#include <QColor>
#include <QString>
#include <QVector3D>

namespace OpenglSpace
{
const QColor CLEAR_COLOR = QColor(0, 0, 0);
const QString VERTEX_PATH = ":/shader/vertex.glsl";
const QString FRAMENT_PATH = ":/shader/frament.glsl";
const QString VIDEO_PATH = "camera.mp4";
const QString CONTAINER_PATH = ":/texture/container.jpg";

// 方向向量
const QVector3D CAMERA_POS = QVector3D(0.0f, 0.0f, 3.0f);
const QVector3D TARGET_POS = QVector3D(0.0f, 0.0f, 0.0f);
const QVector3D WORLD_UP = QVector3D(0.0f, 1.0f, 0.0f);
}

#endif // OPENGLDEF_H
