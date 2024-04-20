#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <memory>
#include <vector>
#include <map>
#include <entity.hpp>

typedef std::vector <std::shared_ptr<Entity>> EntityVec; 
typedef std::map <std::string, EntityVec> EntityMap; 

class EntityManager
{
    EntityVec m_entities;
    EntityVec m_toAdd;

    EntityMap m_entityMap;
    
    size_t m_totalEntities = 0;

    public:
        EntityManager();
        ~EntityManager();

        void update();
        std::shared_ptr<Entity> addEntity(const std::string& tag);

        size_t getNumOfEntities();

        EntityVec& getEntities();
        EntityVec& getEntitiesByTag(const std::string& tag);
};

#endif