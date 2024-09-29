#ifndef A2_ENTITY_HPP
#define A2_ENTITY_HPP

#include <iostream>
#include <memory>

#include <cbbox.hpp>
#include <cshape.hpp>
#include <ctransform.hpp>
#include <cname.hpp>

class Entity 
{
        const size_t m_id = 0;
        const std::string m_tag = "Default";
        bool m_alive = true;

    public:
        std::shared_ptr<CBBox>          boundingBox     = nullptr;
        std::shared_ptr<CShape>         shape           = nullptr;
        std::shared_ptr<CTransform>     transform       = nullptr;
        std::shared_ptr<CName>          name            = nullptr;

        Entity();
        Entity(const std::string& tag, size_t id);
        ~Entity();

        void addComponent();
        void removeComponent();
        void getComponent();
        void destroy();
        
        const std::string& tag();
        bool isAlive();
};

#endif