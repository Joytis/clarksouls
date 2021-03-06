//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_MAINMENUSTATE_HPP
#define CLARKSOULS_MAINMENUSTATE_HPP

#include "StateIncludes.hpp"

struct MenuElement {
    sf::Sprite sprite;
};

class MainMenuState : public IState {
private:
    StateSystem *m_stateSystem;
    TextureManager *m_textureManager;


public:
    MainMenuState(StateSystem* system, TextureManager *texman);

    virtual void begin() override ;

    virtual void end() override ;

    virtual void update(float deltaTime, Input *input) override ;

    virtual void render(sf::RenderWindow *window) override ;
};


#endif //CLARKSOULS_MAINMENUSTATE_HPP
