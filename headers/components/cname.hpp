#ifndef A2_CNAME_HPP
#define A2_CNAME_HPP

#include <vec2.hpp>

class CName 
{
    public:
        std::string name;

        CName();
        CName(std::string& name);

        ~CName();
};

#endif