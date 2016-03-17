//
// Created by Clark Burton Chambers on 3/17/16.
//

#include "InputTestState.hpp"
#include "../Input.hpp"

InputTestState::InputTestState(StateSystem* system) {
    stateSystem = system;

    if(!m_testFont.loadFromFile("src/assets/sansation.ttf")){
        //TODO(clark): ERROR CHECKING!
    }

    for(int i = 0; i < ARRAY_SIZE(m_testTexts); i++){
        m_testTexts[i].setFont(m_testFont);
        m_testTexts[i].setString("0 0 0");
        m_testTexts[i].setPosition( ((i % 10) * 80) * 1.0f, ((i / 10) * 80) * 1.0f );
        m_testTexts[i].setCharacterSize(25);
    }
}

void InputTestState::update(sf::Time deltaTime, Input* input) {
    for( int i = 0; i < ARRAY_SIZE(m_testTexts); i++ ){
        m_testTexts[i].setString(getStringThing(input->m_keyboardInput.Buttons[i]));
    }
}

void InputTestState::render(sf::RenderWindow *window) {
    // RENDER
    for( int i = 0; i < ARRAY_SIZE(m_testTexts); i++ ){
        window->draw(m_testTexts[i]);
    }
}


std::string InputTestState::getStringThing(game_button_state state) {

    // Temp string to return
    std::string tmp = "";

    tmp.append( (state.IsDown) ? "1 " : "0 " );
    tmp.append( (state.IsPressed) ? "1 " : "0 " );
    tmp.append( (state.WasDown) ? "1" : "0" );

    if(state.IsPressed){
        std::cerr << "Value!" << std::endl;
    }

    return tmp;
}
