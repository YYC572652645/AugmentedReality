#ifndef OBJECTRECTANGLE_H
#define OBJECTRECTANGLE_H
#include "objectparent.h"

class ObjectRectangle : public ObjectParent
{
public:
    ObjectRectangle();
    ~ObjectRectangle();
    void makeObject() override;
private:
    void initValue();
};

#endif // OBJECTRECTANGLE_H
