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
} e_stateSystemError;

//Throw this when State stack is empty
class empty_stack_exception : public state_system_exception {
    virtual const char* what() const throw()
    {
        return "State System is Empty!";
    }
} e_emptyStack;


// Throw this exception when state does not exist in the system
class state_dne_exception : public state_system_exception {
    virtual const char* what() const throw()
    {
        return "State does now exist in this sytem";
    }
} e_stateDNE;

class state_already_exists : public state_system_exception {
    virtual const char* what() const throw() {
        return "State already exists!";
    }
} e_stateExists;


#endif //CLARKSOULS_STATESYSTEMEXCEPTIONS_HPP
