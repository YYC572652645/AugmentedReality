#include "objectfactory.h"

ObjectFactory* ObjectFactory::instance = new ObjectFactory();

ObjectFactory::ObjectFactory()
{

}

ObjectFactory::~ObjectFactory()
{

}

ObjectFactory *ObjectFactory::getInstance()
{
    return instance;
}

ObjectParent *ObjectFactory::makeObject(ObjectType objectType)
{
    switch (objectType)
    {
    case OBJECT_TRIANGLE: return new ObjectTriangle(); break;
    case OBJECT_RECTANGLE: return new ObjectRectangle(); break;
    case OBJECT_VIDEO: return new ObjectVideo(); break;
    case OBJECT_MAX: break;
    default:break;
    }

    return nullptr;
}
