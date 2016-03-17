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
    if (!(m_stateMap.find(key) == m_stateMap.end()))
    {
        // State already exists. return false
        throw e_state_exists();
    }
    else
    {
        m_stateMap[key] = value;
    }
}

//--------------------------------
// PUSH STATE!
//--------------------------------
void  StateSystem::PushState(std::string key)
{
    if (!(m_stateMap.find(key) == m_stateMap.end()))
    {
        m_stateStack.push(m_stateMap[key]);
        m_stateStack.top()->begin();
    }
    else
    {
        throw e_state_dne();
    }
}

//--------------------------------
// POP STATE!
//--------------------------------
void StateSystem::PopState()
{
    if(!m_stateStack.empty())
    {
        m_stateStack.top()->end();
        m_stateStack.pop();
    }
    else
    {
        // State stack is empty.
        throw e_empty_stack();
    }
}

//--------------------------------
// UPDATE!
//--------------------------------
void StateSystem::update(float deltaTime, Input *input)
{
    if(m_stateStack.empty())
    {
        // Stack is empty!
        throw e_empty_stack();
    }
    else
    {
        m_stateStack.top()->update(deltaTime, input);
    }
}

//--------------------------------
// RENDER!
//--------------------------------
void StateSystem::render(sf::RenderWindow *window)
{
    if(m_stateStack.empty())
    {
        //Stack is empty!
        throw e_empty_stack();
    }
    else
    {
        m_stateStack.top()->render(window);
    }

}

