#ifndef CAMERALIBRARY_H
#define CAMERALIBRARY_H

#include <QObject>
#include <QVector3D>
#include <QMatrix4x4>

class CameraLibrary : public QObject
{
    Q_OBJECT
public:
    explicit CameraLibrary(QObject *parent = 0);
    ~CameraLibrary();
    QMatrix4x4 getViewMat4x4();
    void setPitch(float pitch);
    void setYaw(float yaw);
    void moveToForward();
    void moveToBackward();
    void moveToLeft();
    void moveToRight();
    void moveToUp();
    void moveToDown();
    void setupCamera(QVector3D position, QVector3D target, QVector3D worldUp);
    void setupCamera(QVector3D position, float pitch, float yaw, QVector3D worldUp);
private:

    float m_yaw;
    float m_pitch;
    QVector3D m_position;
    QVector3D m_forward;
    QVector3D m_right;
    QVector3D m_up;
    QVector3D m_worldup;

    void updateVector();
    void processMouseEvent(float deltaX, float deltaY);
};

#endif // CAMERALIBRARY_H
