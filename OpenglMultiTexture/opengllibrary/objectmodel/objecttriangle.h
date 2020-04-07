#ifndef OBJECTTRIANGLE_H
#define OBJECTTRIANGLE_H
#include "objectparent.h"

class ObjectTriangle : public ObjectParent
{
public:
    ObjectTriangle();
    ~ObjectTriangle();
    void makeObject() override;
private:
    void initValue();
};

#endif // OBJECTTRIANGLE_H
