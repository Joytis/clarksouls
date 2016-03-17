//
// Created by Clark Burton Chambers on 3/17/16.
//

#ifndef CLARKSOULS_INPUTTESTSTATE_HPP
#define CLARKSOULS_INPUTTESTSTATE_HPP

#include "StateIncludes.hpp"

class InputTestState : public IState {
private:
    StateSystem* stateSystem;

    sf::Font m_testFont;
    sf::Text m_testTexts[60];

    std::string getStringThing(game_button_state state);

public:

    InputTestState(StateSystem* system);

    virtual void update(sf::Time deltaTime, Input* inupt);
    virtual void render(sf::RenderWindow* window);
};


#endif //CLARKSOULS_INPUTTESTSTATE_HPP
