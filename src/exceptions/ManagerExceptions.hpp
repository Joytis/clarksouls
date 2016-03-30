//
// Created by Clark Burton Chambers on 3/28/16.
//

#ifndef CLARKSOULS_TEXTUREMANAGEREXCEPTIONS_HPP
#define CLARKSOULS_TEXTUREMANAGEREXCEPTIONS_HPP

#include <exception>

struct manager_exception : public std::exception{
    virtual const char* what() const throw()
    {
        return "Texture Manager Exception!!";
    }
};

struct e_manager_obj_dne : public manager_exception {
    virtual const char* what() const throw()
    {
        return "Texture does not exist in Manager!";
    }
};

struct e_manager_obj_exists : public manager_exception {
    virtual const char* what() const throw()
    {
        return "Texture already exists in Manager!";
    }
};

struct e_manager_obj_cantload : public manager_exception {
    virtual const char* what() const throw()
    {
        return "Texture wasn't loaded! Oh no!";
    }
};

#endif //CLARKSOULS_TEXTUREMANAGEREXCEPTIONS_HPP
