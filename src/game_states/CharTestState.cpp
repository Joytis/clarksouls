//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "CharTestState.hpp"
#include "../Input.hpp"

CharTestState::CharTestState(StateSystem* system) {
    // Has its state system as member function
    m_stateSystem = system;


    if(!testure.loadFromFile("src/assets/cute_bird.png")){
        //ERROR HANDLING HERE
    }
    tesprite.setTexture(testure);
    tesprite.setPosition(425.0f, 170.0f);
}

void CharTestState::update(sf::Time deltaTime, Input *input) {
    // Update silly sprite!
    if(input->m_controllerInput.Up.IsPressed){
        tesprite.move(0, -100.0f);
    }
    if(input->m_controllerInput.Down.IsPressed){
        tesprite.move(0, 100.0f);
    }
    if(input->m_controllerInput.Left.IsPressed){
        tesprite.move(-100.0f, 0);
    }
    if(input->m_controllerInput.Right.IsPressed){
        tesprite.move(100.0f, 0);
    }
}

void CharTestState::render(sf::RenderWindow *window) {
    //Draw Sprite!
    window->draw(tesprite);
}

