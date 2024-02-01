#include <vector>
#include <memory>
struct Component1 :public Component
{
    int x;
};
struct Component2 :public Component
{
    int y;
};
struct Component
{
    bool isDeleted;
    Entity* parent;
};
class System
{
    virtual Component* BuildComponent(Entity* parent) = 0;
    Entity* GetParent(Component* component) { return component->parent; }
};
class Component1System : public System
{
    private:
    std::vector<Component1> c1vector;
    public:
    Component* BuildComponent(Entity* parent) override;
};
class Component2System : public System
{
    private:
    std::vector<Component2> c2vector;
    public:  
    Component* BuildComponent(Entity* parent) override;
};

class Entity
{
    std::vector<Component*> children;
    public:
    void AddComponent(Component * component);
    template <typename T>
    T* GetComponent()
    {
        for (Component* component : children)
        {
            if (dynamic_cast<T*>(component) != nullptr)
            {
                return dynamic_cast<T*>(component);
            }
        }
    return nullptr; 
    }

};

class Engine
{
    Entity* BuildEntity();
    private:
    Component1System c1sys;
    Component2System c2sys;
};