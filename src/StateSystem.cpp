//
// Created by Clark Burton Chambers on 3/15/16.
//

#include "StateSystem.hpp"


// TODO(clark): IMPLEMENT ERROR HANDLING
StateSystem::StateSystem() {

}

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

void  StateSystem::PushState(std::string key)
{
    if (m_stateMap.find(key) == m_stateMap.end())
    {
        throw e_state_dne();
    }
    else
    {
        m_stateStack.push(m_stateMap[key]);
    }
}

void StateSystem::PopState()
{
    if(!m_stateStack.empty())
    {
        m_stateStack.pop();
    }
    else
    {
        // State stack is empty.
        throw e_empty_stack();
    }
}

void StateSystem::update(sf::Time deltaTime, Input *input)
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

