//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "StateSystem.hpp"


// TODO(clark): IMPLEMENT ERROR HANDLING
StateSystem::StateSystem() {

}

void StateSystem::AddState(std::string key, IState *value) {
    if (!(m_stateMap.find(key) == m_stateMap.end())) {
        // State already exists. return false
        throw e_stateExists;
    }
    else{
        m_stateMap[key] = value;
    }
}

void  StateSystem::PushState(std::string key) {
    if (m_stateStack.empty()) {
        // State Stack is empty. Return false scrub!
        throw e_emptyStack;
    }
    else if (m_stateMap[key] == nullptr) {
        throw e_stateDNE;
    }
    else{
        m_stateStack.push(m_stateMap[key]);
    }
}

void StateSystem::PopState() {
    if(!m_stateStack.empty()){
        m_stateStack.pop();
    }
    else{
        // State stack is empty.
        throw e_emptyStack;
    }
}

void StateSystem::update(sf::Time deltaTime, Input *input) {
    if(m_stateStack.empty()){
        throw e_emptyStack;
    }
    else{
        m_stateStack.top()->update(deltaTime, input);
    }
}

void StateSystem::render(sf::RenderWindow *window) {
    if(m_stateStack.empty()){
        throw e_emptyStack;
    }
    else{
        m_stateStack.top()->render(window);
    }

}

