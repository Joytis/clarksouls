//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_STATESYSTEM_HPP
#define CLARKSOULS_STATESYSTEM_HPP

// TODO(clark): Another forward decleration because I suck at programming.
class IState;

#include "IState.hpp"
#include "Includes.hpp"


// State System! Basic usage!
//      - Add pointers to initialized states to the map. Should be associated to a string
//      - Push states from map onto stack. update/render will be read from the states on stack
//      - Pop states off the stack to pull out of scope/push some on.
//

// Methods in class throw e_stateSystemException(s)
class StateSystem {
private:

    // This will be used as an association between a string and its respectice state.
    // The map will just store the states for later loading.
    std::map<std::string, IState*> m_stateMap;

    // This is where the system will be updating and rendering states. Acting as a
    // traditional stack, the system will check the IState* on top for render and update functions.
    std::stack<IState*> m_stateStack;

public:

    // Constructors and Destructors
    StateSystem();
    ~StateSystem();


    // Adds a state to m_stateMap
    // Excaptions:
    //      e_stateExists - State already exists in the m_stateMap
    void AddState(std::string key, IState *value);

    // Gets a state from the state map
    // Exceptions:
    //      e_state_dne - state doesn't exist
    IState *GetState(std::string key);

    // Pushes a state onto the stack and calls begin(). MAKE SURE TO POP PREVIOUS STATE
    //                                  - Assuming you just want one
    // Exceptions:
    //      e_stateDNE - State does not exists in the m_stateMap.
    void PushState(std::string key);


    // Pops the top state off the stack and calls its end() function.
    // Excemptions:
    //      e_emptyStack - throws when. Stack. Is empty. Durrr.
    void PopState();


    // TODO(clark): Implement multiple state updates
    // Calls update function for state on top of stack
    // Exceptions:
    //      e_emptyStack - throws WHEN STACK IS EMPTY DUR.
    void update(float deltaTime, Input *input);


    // TODO(clark): Implement multiple state rendering
    // Calls render function for state on top of the stack
    // Exceptions:
    //      e_emptyStack - throws When STACK. IS EMPTYYYYY WOOOO!!!
    void render(sf::RenderWindow *window);
};


#endif //CLARKSOULS_STATESYSTEM_HPP
