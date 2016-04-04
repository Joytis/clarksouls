//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "StateSystem.hpp"


// TODO(clark): IMPLEMENT ERROR HANDLING
StateSystem::StateSystem() {

}

//--------------------------------
// ADD STATE!
//--------------------------------
void StateSystem::AddState(std::string key, IState *value)
{
    check_mem(value)
    check(m_stateMap.find(key) == m_stateMap.end(), e_state_exists,
          "State already exists: %s", key.data());

    m_stateMap[key] = value;
}

IState *StateSystem::GetState(std::string key) {
    check(m_stateMap.find(key) != m_stateMap.end(), e_state_dne,
          "State: %s, does not exist in map", key.data())
    check_mem(m_stateMap[key])

    return m_stateMap[key];
}

//--------------------------------
// PUSH STATE!
//--------------------------------
void StateSystem::PushState(std::string key)
{
    // Make sure state exusts!
    check(m_stateMap.find(key) != m_stateMap.end(), e_state_dne,
          "State does not exist: %s", key.data());

    m_stateStack.push(m_stateMap[key]);
    m_stateStack.top()->begin();
}
//--------------------------------
// POP STATE!
//--------------------------------
void StateSystem::PopState()
{
    check(!m_stateStack.empty(), e_empty_stack,
          "Stack is empty! Can't pop")

    m_stateStack.top()->end();
    m_stateStack.pop();
}

//--------------------------------
// UPDATE!
//--------------------------------
void StateSystem::update(float deltaTime, Input *input)
{
    check_mem(input);

    // Can't update an empty stack!
    check(!m_stateStack.empty(), e_empty_stack,
          "Stack Empty, can't update system")

    m_stateStack.top()->update(deltaTime, input);
}

//--------------------------------
// RENDER!
//--------------------------------
void StateSystem::render(sf::RenderWindow *window)
{
    check_mem(window)
    check(!m_stateStack.empty(), e_empty_stack,
          "Stack Empty, can't render!")

    m_stateStack.top()->render(window);
}

