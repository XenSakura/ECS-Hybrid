#include <vector>
#include <memory>
using namespace std;
struct Entity
{
    vector<unique_ptr<Component>> components;
};
struct Component
{
    unique_ptr<Entity> parent;
};
class System
{
    public:
    System();
    virtual void Update (float dt) = 0;
    virtual void Deserialize() = 0;
    virtual void Serialize() = 0;
    virtual ~System() = 0;
};
class ComponentManager
{
    public:
    ComponentManager();
    void Update (float dt);
    virtual void Deserialize();
    virtual void Serialize();
    ~ComponentManager();
    private:
    vector<Entity> entities;
    vector<vector<Component>> components;
    vector<System> Systems;
};
struct Sprite : public Component
{

};
struct ParticleEmitter : public Component
{

};

class SpriteSystem : public System
{  
    public:
    SpriteSystem(vector<Sprite>);
    void Update (float dt);
    void Deserialize();
    void Serialize();
    ~SpriteSystem();
    private:
    unique_ptr<vector<Sprite>> sprites;
};
class ParticleSystem : public System
{
    public: 
    ParticleSystem(vector<ParticleEmitter>);
    void Update (float dt);
    void Deserialize();
    void Serialize();
    ~ParticleSystem();
    private:
    unique_ptr<vector<ParticleEmitter>> particles;
};