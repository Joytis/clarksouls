//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_CHARTESTSTATE_HPP
#define CLARKSOULS_CHARTESTSTATE_HPP

#include "StateIncludes.hpp"

// This is just a silly little test state

class CharTestState : public IState {
private:
    StateSystem* m_stateSystem;

    sf::Texture testure;
    sf::Sprite  tesprite;
public:
    CharTestState(StateSystem* system);
    void update(sf::Time deltaTime, Input* input);
    void render(sf::RenderWindow* window);
};


#endif //CLARKSOULS_CHARTESTSTATE_HPP
