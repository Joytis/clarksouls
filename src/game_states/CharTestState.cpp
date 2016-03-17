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


void CharTestState::begin() {

}


void CharTestState::end() {

}


void CharTestState::update(float deltaTime, Input *input) {
    //-------------------------------
    // Handle Input
    //-------------------------------
    if (input->m_keyboardInput.Space.IsPressed){
        m_stateSystem->PopState();
        m_stateSystem->PushState("inputTest");
    }

    //-------------------------------
    // Update Logic Stuff
    //-------------------------------
    // Update silly sprite!
    if(input->m_controllerInput.Up.IsDown){
        tesprite.move(0, -50.0f);
    }
    if(input->m_controllerInput.Down.IsDown){
        tesprite.move(0, 50.0f);
    }
    if(input->m_controllerInput.Left.IsDown){
        tesprite.move(-50.0f, 0);
    }
    if(input->m_controllerInput.Right.IsDown){
        tesprite.move(50.0f, 0);
    }
}

void CharTestState::render(sf::RenderWindow *window) {
    //Draw Sprite!
    window->draw(tesprite);
}


