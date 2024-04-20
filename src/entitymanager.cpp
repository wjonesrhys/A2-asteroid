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
        for (auto& e : m_entities) {
            if (!e->isAlive())
            {
                
            }
        }

        auto is_dead = [](auto const e) { return e->isAlive() == false; };
        auto it = std::remove_if(m_entities.begin(), m_entities.end(), is_dead);

        // for (it.begin(); it != v1.end(); ++itr) {

        //     std::cout << *it << " ";

        // }
        m_entities.erase(it, m_entities.end());
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