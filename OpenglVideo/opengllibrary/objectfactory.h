#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include "objectmodel/objectparent.h"
#include "objectmodel/objecttriangle.h"
#include "objectmodel/objectrectangle.h"
#include "objectmodel/objectvideo.h"

#ifndef OBJECT_FACTORY
#define OBJECT_FACTORY ObjectFactory::getInstance()
#endif

class ObjectFactory
{
public:
    enum ObjectType
    {
        OBJECT_TRIANGLE,
        OBJECT_RECTANGLE,
        OBJECT_VIDEO,
        OBJECT_MAX
    };
    static ObjectFactory* getInstance();

    ObjectParent *makeObject(ObjectType objectType);
private:
    ObjectFactory();
    ~ObjectFactory();
private:
    static ObjectFactory* instance;
};

#endif // OBJECTFACTORY_H
