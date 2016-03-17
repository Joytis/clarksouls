//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_ISTATE_HPP
#define CLARKSOULS_ISTATE_HPP

#include "Includes.hpp"

//----------------------
// IState class!
//----------------------

// Create different versions of this interface and throw them in some state systems! Woo!
//
//      Create the state and the constructor should initialize it outside the state system
//      Then add it to the state system with the appropriate methoda and go nuts.
class IState{
public:
    // I'm not sure why I do this and what function it provides.
    virtual ~IState(){};

    // Begin function:
    // This function will be called when the state is pushed INTO the StateSystem.
    virtual void begin() = 0;

    // End function:
    // This function will be called when the state is pushed OFF the StateSystem.
    virtual void end() = 0;

    // Currently called every frame in the main game loop by the state system!.
    // The state system should call update and render functions only for states on the stack.

    // update:
    //  Arguments:
    //      sf::Time deltaTime: Should pass the time in seconds.
    //      Input* input: Should pass in currently updated game input.
    virtual void update(float deltaTime, Input *input) = 0;

    // render:
    //  Arguments:
    //      sf::RenderWindow: window that objects in this state will be rendered to! Woo!
    virtual void render(sf::RenderWindow *window) = 0;
};


#endif //CLARKSOULS_ISTATE_HPP
