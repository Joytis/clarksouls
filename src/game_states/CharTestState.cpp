//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "CharTestState.hpp"
#include "../Input.hpp"

CharTestState::CharTestState(StateSystem* system, TextureManager *texman) {
    // Has its state system as member function
    m_stateSystem = system;
    m_textureManager = texman;

    // Get and dereference pointer to the texture.
    tesprite.setTexture(*texman->GetTexture("cuteBird"));
    tesprite.setPosition(425.0f, 170.0f);
}


void CharTestState::begin() {
    log_info("CharTestState begin() \n");
}


void CharTestState::end() {
    log_info("CharTestState end()\n");
}


void CharTestState::update(float deltaTime, Input *input) {
    float velocity = 200.0f * deltaTime;

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
    if(input->m_keyboardInput.Up.IsDown){
        tesprite.move(0.0f, -velocity);
    }
    if(input->m_keyboardInput.Down.IsDown){
        tesprite.move(0.0f, velocity);
    }
    if(input->m_keyboardInput.Left.IsDown){
        tesprite.move(-velocity, 0.0f);
    }
    if(input->m_keyboardInput.Right.IsDown){
        tesprite.move(velocity, 0.0f);
    }
}

void CharTestState::render(sf::RenderWindow *window) {
    //Draw Sprite!
    window->draw(tesprite);
}


