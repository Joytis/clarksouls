//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "Input.hpp"

Input::Input(){

    //Start using Keyboard input
    m_joystickActive = false;

    for(int i = 0; i < ARRAY_SIZE(States.Buttons); i++){
        States.Buttons[i].IsDown = false;
        States.Buttons[i].IsPressed = false;
        States.Buttons[i].WasDown = false;
    }


//    game_button_state Up;
//    game_button_state Down;
//    game_button_state Left;
//    game_button_state Right;
//
//    // Action Inputs
//    game_button_state Interact;
//    game_button_state Inventory;
//    game_button_state Jump;
//    game_button_state Menu;
//
//    // Combat Inputs
//    game_button_state LightAttack;
//    game_button_state HeavyAttack;

    m_key[0] = sf::Keyboard::Up;
    m_key[1] = sf::Keyboard::Down;
    m_key[2] = sf::Keyboard::Left;
    m_key[3] = sf::Keyboard::Right;

    m_key[4] = sf::Keyboard::E;
    m_key[5] = sf::Keyboard::Tab;
    m_key[6] = sf::Keyboard::Space;
    m_key[7] = sf::Keyboard::Escape;

    m_key[8] = sf::Keyboard::S;
    m_key[9] = sf::Keyboard::D;



}

void Input::updateControllerButtonState(int joystick, int button, game_button_state &state) {
    state.IsDown = (sf::Joystick::isButtonPressed(joystick, button)) ? true : false;
    state.IsPressed = (sf::Joystick::isButtonPressed(joystick, button) && !(state.WasDown)) ? true : false;
    state.WasDown = state.IsDown;
}

void Input::updateKeyboardButtonState(sf::Keyboard::Key key, game_button_state &state) {
    state.IsDown = (sf::Keyboard::isKeyPressed(key)) ? true : false;
    state.IsPressed = (sf::Keyboard::isKeyPressed(key) && !(state.WasDown)) ? true : false;
    state.WasDown = state.IsDown;
}


void Input::UpdateInput(){
    if(m_joystickActive){
        UpdateControllerInput();
    } else {
        UpdateKeyboardInput();
    }
}

void Input::UpdateKeyboardInput(){
    for(int i = 0; i < ARRAY_SIZE(m_key); i++){
        updateKeyboardButtonState(m_key[i], States.Buttons[i]);
    }
}

void Input::UpdateControllerInput() {

}

bool Input::IsJoystickActive() {
    return m_joystickActive;
}

void Input::ToggleJoyActive(){
    m_joystickActive = !m_joystickActive;
}

