//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "Input.hpp"

Input::Input(){

    //Start using Keyboard input
    m_joystickActive = false;

    for(int i = 0; i < ARRAY_SIZE(m_controllerInput.Buttons); i++){
        m_controllerInput.Buttons[i].IsDown = false;
        m_controllerInput.Buttons[i].IsPressed = false;
        m_controllerInput.Buttons[i].WasDown = false;
    }

    for(int i = 0; i < ARRAY_SIZE(m_keyboardInput.Buttons); i++){
        m_keyboardInput.Buttons[i].IsDown = false;
        m_keyboardInput.Buttons[i].IsPressed = false;
        m_keyboardInput.Buttons[i].WasDown = false;
    }

    // Row 1
    m_key[0] = sf::Keyboard::Num1;
    m_key[1] = sf::Keyboard::Num2;
    m_key[2] = sf::Keyboard::Num3;
    m_key[3] = sf::Keyboard::Num4;
    m_key[4] = sf::Keyboard::Num5;
    m_key[5] = sf::Keyboard::Num6;
    m_key[6] = sf::Keyboard::Num7;
    m_key[7] = sf::Keyboard::Num8;
    m_key[8] = sf::Keyboard::Num9;
    m_key[9] = sf::Keyboard::Num0;
    m_key[10] = sf::Keyboard::Dash;
    m_key[11] = sf::Keyboard::Equal;
    m_key[12] = sf::Keyboard::BackSpace;

        // Row 2
    m_key[13] = sf::Keyboard::Tab;
    m_key[14] = sf::Keyboard::Q;
    m_key[15] = sf::Keyboard::W;
    m_key[16] = sf::Keyboard::E;
    m_key[17] = sf::Keyboard::R;
    m_key[18] = sf::Keyboard::T;
    m_key[19] = sf::Keyboard::Y;
    m_key[20] = sf::Keyboard::U;
    m_key[21] = sf::Keyboard::I;
    m_key[22] = sf::Keyboard::O;
    m_key[23] = sf::Keyboard::P;
    m_key[24] = sf::Keyboard::LBracket;
    m_key[25] = sf::Keyboard::RBracket;
    m_key[26] = sf::Keyboard::BackSlash;

        // Row 3
    m_key[27] = sf::Keyboard::A;
    m_key[28] = sf::Keyboard::S;
    m_key[29] = sf::Keyboard::D;
    m_key[30] = sf::Keyboard::F;
    m_key[31] = sf::Keyboard::G;
    m_key[32] = sf::Keyboard::H;
    m_key[33] = sf::Keyboard::J;
    m_key[34] = sf::Keyboard::K;
    m_key[35] = sf::Keyboard::L;
    m_key[36] = sf::Keyboard::SemiColon;
    m_key[37] = sf::Keyboard::Quote;
    m_key[38] = sf::Keyboard::Return;

    // Row 4
    m_key[39] = sf::Keyboard::LShift;
    m_key[40] = sf::Keyboard::Z;
    m_key[41] = sf::Keyboard::X;
    m_key[42] = sf::Keyboard::C;
    m_key[43] = sf::Keyboard::V;
    m_key[44] = sf::Keyboard::B;
    m_key[45] = sf::Keyboard::N;
    m_key[46] = sf::Keyboard::M;
    m_key[47] = sf::Keyboard::Comma;
    m_key[48] = sf::Keyboard::Period;
    m_key[49] = sf::Keyboard::Slash;
    m_key[50] = sf::Keyboard::RShift;

    // Row 5
    m_key[51] = sf::Keyboard::LControl;
    m_key[52] = sf::Keyboard::LAlt;
    m_key[53] = sf::Keyboard::Space;
    m_key[54] = sf::Keyboard::RSystem;
    m_key[55] = sf::Keyboard::RControl;

    // Arrows
    m_key[56] = sf::Keyboard::Up;
    m_key[57] = sf::Keyboard::Down;
    m_key[58] = sf::Keyboard::Left;
    m_key[59] = sf::Keyboard::Right;
}

void Input::updateControllerButtonState(int joystick, int button, game_button_state &state) {
    state.IsDown = (sf::Joystick::isButtonPressed(joystick, button)) ? true : false;
    state.IsPressed = (sf::Joystick::isButtonPressed(joystick, button) && !(state.WasDown)) ? true : false;
    state.WasDown = state.IsDown;
}

void Input::updateKeyboardButtonState(sf::Keyboard::Key key, game_button_state& state) {
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
        updateKeyboardButtonState(m_key[i], m_keyboardInput.Buttons[i]);
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

