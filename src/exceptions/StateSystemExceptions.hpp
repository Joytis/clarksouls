//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_STATESYSTEMEXCEPTIONS_HPP
#define CLARKSOULS_STATESYSTEMEXCEPTIONS_HPP

#include <exception>

class state_system_exception : public std::exception{
    virtual const char* what() const throw()
    {
        return "State System Error!";
    }
};

//Throw this when State stack is empty
class e_empty_stack : public state_system_exception {
    virtual const char* what() const throw()
    {
        return "State System is Empty!";
    }
};


// Throw this exception when state does not exist in the system
class e_state_dne : public state_system_exception {
    virtual const char* what() const throw()
    {
        return "State does now exist in this sytem";
    }
};

class e_state_exists : public state_system_exception {
    virtual const char* what() const throw() {
        return "State already exists!";
    }
};


#endif //CLARKSOULS_STATESYSTEMEXCEPTIONS_HPP
