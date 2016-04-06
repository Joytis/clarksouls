//
// Created by Clark Burton Chambers on 3/17/16.
//

#ifndef CLARKSOULS_INPUTTESTSTATE_HPP
#define CLARKSOULS_INPUTTESTSTATE_HPP

#include "StateIncludes.hpp"

class InputTestState : public IState {
private:
    StateSystem *m_stateSystem;
    FontManager *m_fontManager;

    sf::Text m_testTexts[10];

    std::string getStringThing(game_button_state state);

public:

    InputTestState(StateSystem* system, FontManager *fontman);

    virtual void begin();
    virtual void end();

    virtual void update(float deltaTime, Input* inupt);
    virtual void render(sf::RenderWindow* window);
};


#endif //CLARKSOULS_INPUTTESTSTATE_HPP
