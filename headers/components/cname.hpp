#ifndef CNAME_HPP
#define CNAME_HPP

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