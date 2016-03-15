//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "CharTestState.hpp"

CharTestState::CharTestState(StateSystem* system) {
    // Has its state system as member function
    m_stateSystem = system;


    if(!testure.loadFromFile("src/assets/cute_bird.png")){
        //ERROR HANDLING HERE
    }
    tesprite.setTexture(testure);
    tesprite.setPosition(500.0f, 500.0f);
}

void CharTestState::update(sf::Time deltaTime, Input *input) {
    // Update silly sprite!
}

void CharTestState::render(sf::RenderWindow *window) {
    //Draw Sprite!
    window->draw(tesprite);
}

