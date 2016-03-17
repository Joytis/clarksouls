//
// Created by Clark Burton Chambers on 3/15/16.
//

#ifndef CLARKSOULS_INPUT_HPP
#define CLARKSOULS_INPUT_HPP

#include "Includes.hpp"

typedef struct {
    bool IsDown;
    bool IsPressed;
    bool WasDown;
} game_button_state;

typedef struct{
    uint8_t Joystick;
    union
    {
        game_button_state Buttons[8];
        struct{
            game_button_state Up;
            game_button_state Down;
            game_button_state Left;
            game_button_state Right;
            game_button_state ActionUp;
            game_button_state ActionDown;
            game_button_state ActionLeft;
            game_button_state ActionRight;
        };
    };
} game_controller_input;



typedef struct{
    union {
        game_button_state Buttons[60];
        struct {
            //American Keyboard.
            //Row 1 13
            game_button_state n1;
            game_button_state n2;
            game_button_state n3;
            game_button_state n4;
            game_button_state n5;
            game_button_state n6;
            game_button_state n7;
            game_button_state n8;
            game_button_state n9;
            game_button_state n0;
            game_button_state Dash;
            game_button_state Equals;
            game_button_state BackSpace;

            //Row 2 14
            game_button_state Tab;
            game_button_state Q;
            game_button_state W;
            game_button_state E;
            game_button_state R;
            game_button_state T;
            game_button_state Y;
            game_button_state U;
            game_button_state I;
            game_button_state O;
            game_button_state P;
            game_button_state LBracket;
            game_button_state RBracket;
            game_button_state BackSlash;

            //Row 3 12
            game_button_state A;
            game_button_state S;
            game_button_state D;
            game_button_state F;
            game_button_state G;
            game_button_state H;
            game_button_state J;
            game_button_state K;
            game_button_state L;
            game_button_state Semicolon;
            game_button_state Apos;
            game_button_state Return;

            //Row 4 12
            game_button_state LShift;
            game_button_state Z;
            game_button_state X;
            game_button_state C;
            game_button_state V;
            game_button_state B;
            game_button_state N;
            game_button_state M;
            game_button_state Comma;
            game_button_state Period;
            game_button_state ForwardSlash;
            game_button_state RShift;

            //Row 5 5
            game_button_state LCont;
            game_button_state LAlt;
            game_button_state Space;
            game_button_state RCommand;
            game_button_state RCtrl;

            // Arrows 4
            game_button_state Up;
            game_button_state Down;
            game_button_state Left;
            game_button_state Right;
        };
    };
} game_keyboard_input;

// Input class! Pretty much just a bunch of bools that are updated each frams using the SFML framework
// IF YOU CHANGE THE ORDERING OF THE KEYS:
//      Change both the game_x_input structs AND the member key arrays!

class Input {
private:

    //This just cleans up the code a bit. Array of keys for ez pz looping
    sf::Keyboard::Key m_key[60];

    void updateControllerButtonState(int joystick, int button, game_button_state& state);
    void updateKeyboardButtonState(sf::Keyboard::Key key, game_button_state& state);

public:
    //Members
    game_controller_input m_controllerInput;
    game_keyboard_input m_keyboardInput;

    //Constructors and Destructors
    //Init to 0!
    Input();
    ~Input();

    //Updates tha input to current values! Called every frame
    void UpdateInput();
};


#endif //CLARKSOULS_INPUT_HPP
