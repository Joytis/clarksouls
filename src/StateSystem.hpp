//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_STATESYSTEM_HPP
#define CLARKSOULS_STATESYSTEM_HPP

#include "Includes.hpp"
#include "IState.hpp"

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
    bool AddState();

    // Pushes a state onto the stack. MAKE SURE TO POP PREVIOUS STATE
    //                                  - Assuming you just want one
    bool PushState();

    // Pops the top state off the stack
    bool PopState();


    // TODO(clark): Implement multiple state updates
    // Calls update function for state on top of stack
    void update();

    // TODO(clark): Implement multiple state rendering
    // Calls render function for state on top of the stack
    void render();

};


#endif //CLARKSOULS_STATESYSTEM_HPP
