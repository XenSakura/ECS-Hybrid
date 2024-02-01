#include "ECS.h"

void Entity::AddComponent(Component* component)
{
    children.push_back(component);
}
Component * Component1System::BuildComponent(Entity* parent)
{
    Component1 c1;
    c1.parent = parent;
    c1vector.push_back(c1);
    return &c1;
}
Component * Component2System::BuildComponent(Entity* parent)
{
    Component2 c2;
    c2.parent = parent;
    c2vector.push_back(c2);
    return &c2;
}
Entity& Engine::BuildEntity()
{
    static Entity exampleEntity;

    exampleEntity.AddComponent(c1sys.BuildComponent(&exampleEntity));
    exampleEntity.AddComponent(c2sys.BuildComponent(&exampleEntity));
    return &exampleEntity;
}

