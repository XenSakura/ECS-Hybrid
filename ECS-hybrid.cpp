#include "ECS-hybrid.h"
System::System()
{

}
System::~System()
{

}
ComponentManager::ComponentManager()
{
    components.reserve(10);
    vector<Sprite> s;
    components.emplace_back(s);
    vector<ParticleEmitter> p;
    components.emplace_back(p);
    Systems.reserve(10);
    Systems.emplace_back(SpriteSystem(s));
    Systems.emplace_back(ParticleSystem(p));
}
void ComponentManager::Update(float dt)
{
    for (auto& system : Systems)
    {
        system.Update(dt);
    }
}
void ComponentManager::Deserialize()
{

}
void ComponentManager::Serialize()
{

}
ComponentManager::~ComponentManager()
{

}