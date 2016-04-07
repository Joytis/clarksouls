//
// Created by Clark Burton Chambers on 4/7/16.
//

#ifndef CLARKSOULS_BOX2DTESTSTATE_HPP
#define CLARKSOULS_BOX2DTESTSTATE_HPP

#define GRAVITY 0.0f, -10.0f

#include "StateIncludes.hpp"
#include "../IState.hpp"

class Box2DTestState : public IState {
public:
private:

    StateSystem *m_stateSystem;

    b2World *m_world;
    b2Body *groundBody;
    b2Body *body;



public:
    Box2DTestState(StateSystem *system);

    virtual void begin() override;
    virtual void end() override;

    virtual void update(float deltaTime, Input *input) override;
    virtual void render(sf::RenderWindow *window) override;
};


#endif //CLARKSOULS_BOX2DTESTSTATE_HPP
