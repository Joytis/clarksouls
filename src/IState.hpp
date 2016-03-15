//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_ISTATE_HPP
#define CLARKSOULS_ISTATE_HPP

#include "Includes.hpp"

class IState{
public:
    virtual ~IState(){};
    virtual void handle_input() = 0;
    virtual void update(sf::Time deltaTime, Input *input) = 0;
    virtual void render(sf::RenderWindow *window) = 0;
};


#endif //CLARKSOULS_ISTATE_HPP
