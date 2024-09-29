#include <entitymanager.hpp>
#include <unordered_map>

EntityManager::EntityManager()
{
    std::cout << "entity manager created" << std::endl;
}

EntityManager::~EntityManager()
{
    std::cout << "entity manager destroyed" << std::endl;
}

void EntityManager::update() 
{
    for (auto& e : m_toAdd) 
    {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    m_toAdd.clear();

    //also erase from maps too   
    if (m_entities.size() > 0) {
        auto is_dead = [](auto const e) { return e->isAlive() == false; };
        auto entitiesToRemove = std::remove_if(m_entities.begin(), m_entities.end(), is_dead);
        m_entities.erase(entitiesToRemove, m_entities.end());

        for (auto& map : m_entityMap) {
            //obtains the value from the map
            auto& entityVec = map.second;
            //reorders the entityvec so removables are at the end
            entitiesToRemove = std::remove_if(entityVec.begin(), entityVec.end(), is_dead);
            //loops through and removes those returned as removable
            entityVec.erase(entitiesToRemove, entityVec.end());
        }

        //example of how the remove_if works by printing out the values in the returned iterator
        // for (auto it = newEnd; it != m_entities.end(); ++it) {
        //     std::cout << *it << " ";
        // }
    }
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
    m_totalEntities++;
    auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities));
    m_entities.push_back(e);
    m_entityMap[tag].push_back(e);
    return e;
}

size_t EntityManager::getNumOfEntities() 
{
    return this->m_totalEntities;
}

EntityVec& EntityManager::getEntities()
{
    return m_entities;
}

EntityVec& EntityManager::getEntitiesByTag(const std::string& tag)
{
    return m_entityMap[tag];
}