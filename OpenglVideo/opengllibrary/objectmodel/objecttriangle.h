#ifndef OBJECTTRIANGLE_H
#define OBJECTTRIANGLE_H
#include "objectparent.h"

class ObjectTriangle : public ObjectParent
{
    Q_OBJECT
public:
    ObjectTriangle();
    ~ObjectTriangle();
    void makeObject() override;
};

#endif // OBJECTTRIANGLE_H
