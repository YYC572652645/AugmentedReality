#ifndef OBJECTMESH_H
#define OBJECTMESH_H
#include "objectparent.h"

class ObjectMesh : public ObjectParent
{
public:
    ObjectMesh();
    ~ObjectMesh();
    void makeObject() override;
private:
    void initValue();
    bool load(QString fileName, QVector<float> &vPoints,QVector<float> &tPoints, QVector<float> &nPoints);
};

#endif // OBJECTMESH_H
