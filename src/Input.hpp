//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_INPUT_HPP
#define CLARKSOULS_INPUT_HPP

// TODO(clark): figure out why I have to forward include.
// Forward include. Compiler was giving me shit.
class Input;

#include "Includes.hpp"

typedef struct {
    bool IsDown;
    bool IsPressed;
    bool WasDown;
} game_button_state;


typedef struct{
    union {
        game_button_state Buttons[10];
        struct {
            // Directional Inputs
            game_button_state Up;
            game_button_state Down;
            game_button_state Left;
            game_button_state Right;

            // Action Inputs
            game_button_state Interact;
            game_button_state Inventory;
            game_button_state Jump;
            game_button_state Menu;

            // Combat Inputs
            game_button_state LightAttack;
            game_button_state HeavyAttack;

        };
    };
} game_input_states;

// Input class! Pretty much just a bunch of bools that are updated each frams using the SFML framework
// IF YOU CHANGE THE ORDERING OF THE KEYS:
//      Change both the game_x_input structs AND the member key arrays!

class Input {
private:

    //This just cleans up the code a bit. Array of keys for ez pz looping
    sf::Keyboard::Key m_key[10];

    bool m_joystickActive;

    void updateControllerButtonState(int joystick, int button, game_button_state& state);
    void updateKeyboardButtonState(sf::Keyboard::Key key, game_button_state& state);

public:
    //Members
    game_input_states States;

    //Constructors and Destructors
    //Init to 0!
    Input();
    ~Input();

    //Updates tha input to current values! Called every frame
    void UpdateInput();
    void UpdateKeyboardInput();
    void UpdateControllerInput();

    bool IsJoystickActive();
    void ToggleJoyActive();

};


#endif //CLARKSOULS_INPUT_HPP
