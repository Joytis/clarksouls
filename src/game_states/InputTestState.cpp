//
// Created by Clark Burton Chambers on 3/17/16.
//

#include "InputTestState.hpp"
#include "../Input.hpp"

InputTestState::InputTestState(StateSystem* system, FontManager *fontman) {
    m_stateSystem = system;
    m_fontManager = fontman;

    for(int i = 0; i < ARRAY_SIZE(m_testTexts); i++){
        m_testTexts[i].setFont(*fontman->GetFont("sansation"));
        m_testTexts[i].setString("0 0 0");
        m_testTexts[i].setPosition( ((i % 10) * 80) * 1.0f, ((i / 10) * 80) * 1.0f );
        m_testTexts[i].setCharacterSize(25);
    }
}


void InputTestState::begin() {
    log_info("InputTestState begin()\n");
}


void InputTestState::end() {
    log_info("InputTestState end()\n");
}



void InputTestState::update(float deltaTime, Input* input) {
    //-------------------------------
    // Handle Input
    //-------------------------------
    if (input->States.HeavyAttack.IsPressed){
        m_stateSystem->PopState();
        m_stateSystem->PushState("charTest");
    }


    //-------------------------------
    // Update Logic Stuff
    //-------------------------------
    for( int i = 0; i < ARRAY_SIZE(m_testTexts); i++ ){
        m_testTexts[i].setString(getStringThing(input->States.Buttons[i]));
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

    return tmp;
}


