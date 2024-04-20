#include <entity.hpp>

Entity::Entity() 
{
    // std::cout << "default entity created" << std::endl;
}

Entity::Entity(const std::string& tag, size_t id)
    : m_id(id)
    , m_tag(tag)
{
    std::cout << "entity created, tag: " << tag << " and id: " <<  id << std::endl;
}

Entity::~Entity() 
{
    std::cout << "entity destroyed" << std::endl;
}

void Entity::addComponent() 
{
    std::cout << "component added" << std::endl;
}

void Entity::removeComponent() 
{
    std::cout << "component removed" << std::endl;
}

void Entity::getComponent() 
{
    std::cout << "got component" << std::endl;   
}

void Entity::destroy() 
{
    this->m_alive = false;
}

const std::string& Entity::tag() 
{
    return this->m_tag;
}

bool Entity::isAlive() 
{
    return this->m_alive;
}