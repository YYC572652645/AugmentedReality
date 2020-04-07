#ifndef OBJECTRECTANGLE_H
#define OBJECTRECTANGLE_H
#include "objectparent.h"

class ObjectRectangle : public ObjectParent
{
    Q_OBJECT
public:
    ObjectRectangle();
    ~ObjectRectangle();
    void makeObject() override;
};

#endif // OBJECTRECTANGLE_H
