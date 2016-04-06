//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_CHARTESTSTATE_HPP
#define CLARKSOULS_CHARTESTSTATE_HPP

#include "StateIncludes.hpp"
#include "../Player.hpp"

// This is just a silly little test state

class CharTestState : public IState {
private:
    StateSystem* m_stateSystem;
    TextureManager *m_textureManager;

    Player player;
public:
    CharTestState(StateSystem* system, TextureManager *texman);

    virtual void begin();
    virtual void end();

    void update(float deltaTime, Input* input);
    void render(sf::RenderWindow* window);
};


#endif //CLARKSOULS_CHARTESTSTATE_HPP
