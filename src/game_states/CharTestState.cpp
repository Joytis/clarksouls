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
    player.SetTexture(texman,"cuteBird");
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
    if (input->States.HeavyAttack .IsPressed){
        m_stateSystem->PopState();
        m_stateSystem->PushState(GS_INPUT_TEST);
    }

    //-------------------------------
    // Update Logic Stuff
    //-------------------------------

    player.update(deltaTime, input);
}

void CharTestState::render(sf::RenderWindow *window) {
    //Draw Sprite!
    window->draw(player.getM_sprite());
}


