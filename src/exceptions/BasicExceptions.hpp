//
// Created by Clark Burton Chambers on 4/4/16.
//

#ifndef CLARKSOULS_BASICEXCEPTIONS_HPP
#define CLARKSOULS_BASICEXCEPTIONS_HPP

#include <exception>

struct e_bad_allocation : public std::exception{
    virtual const char* what() const throw()
    {
        return "Bad Memory Allocation";
    }
};

struct e_unhandled_state : public std::exception{
    virtual const char* what() const throw()
    {
        return "Unhandled State";
    }
};


#endif //CLARKSOULS_BASICEXCEPTIONS_HPP
