//------------------------------------------------------------------------------------------------------
//             88                          88                                              88
//             88                          88                                              88
//             88                          88                                              88
//  ,adPPYba,  88  ,adPPYYba,  8b,dPPYba,  88   ,d8   ,adPPYba,   ,adPPYba,   88       88  88  ,adPPYba,
// a8"     ""  88  ""     `Y8  88P'   "Y8  88 ,a8"    I8[    ""  a8"     "8a  88       88  88  I8[    ""
// 8b          88  ,adPPPPP88  88          8888[       `"Y8ba,   8b       d8  88       88  88   `"Y8ba,
// "8a,   ,aa  88  88,    ,88  88          88`"Yba,   aa    ]8I  "8a,   ,a8"  "8a,   ,a88  88  aa    ]8I
//  `"Ybbd8"'  88  `"8bbdP"Y8  88          88   `Y8a  `"YbbdP"'   `"YbbdP"'    `"YbbdP'Y8  88  `"YbbdP"'
//-------------------------------------------------------------------------------------------------------
// TODO(clark): Stay cool B)
// General Design:
//     - 2d Sidescrolling RPG
//         - Primary function is soulslike action game
//         - GOing to require platforming elements
//
//     - Level up using resource that can be lost on death
//          - Use resource to also purchase items?
//
//     - Combat
//         - Defensive, calculated, and punishing
//         - Each weapon has a semi-unique move-set
//             - By this, I mean weapons in the same classification can have similar movesets
//               by means of animation, size, and shape. But they vary in damage, speed, and
//               possily by move set.
//
//     - Level Design:
//         - Open world level design. Maybe branching paths? Maybe linear? Who knows.
//           Open world would be nice.
//
//     - Enemy and boss design: TBD
//
//     - Networking Capabilities: TBD
//
//     - Cool Guy: B)

// TODO(clark):
//      - Implement event-based error checking
//      - Stay cool B)


#include "../Includes.hpp"

#include "../StateSystem.hpp"
#include "../game_states/CharTestState.hpp"
#include "../game_states/MainMenuState.hpp"
#include "../game_states/InputTestState.hpp"

int main() {

    //-------------------
    // Create our window
    //-------------------
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1152, 648), "ClarkSouls");

    // Set the Icon
    /*
        sf::Image icon;
        if (!icon.loadFromFile("src/assets/icon.png")) {
            return EXIT_FAILURE;
        }
        window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
     */

    //------------------------------
    // Initialize our Font Manager!
    //------------------------------
    FontManager *fontManager = new FontManager();

    // Add fonts to the font manager!
    try {
        fontManager->AddFont("sansation", new sf::Font);

        //TODO(clark): find a better way to do this. It looks kind of ugly and inefficient.
        if(!fontManager->GetFont("sansation")->loadFromFile("./src/assets/sansation.ttf")) {
            throw new e_manager_obj_cantload;
        }

    }
    catch (const manager_exception & e) {
        DEBUG_ERROR(e.what());

        // TODO(clark): For now, let's just close the window. but handle later.
        window->close();
    }


    //------------------------------
    // Initialize our tex Manager!
    //------------------------------
    TextureManager *textureManager = new TextureManager();

    // Add textures to the texture Manager!
    try {
        //---------------------------
        // Cute Bird!
        //--------------------------
        textureManager->AddTexture("cuteBird", new sf::Texture);

        //TODO(clark): find a better way to do this. It looks kind of ugly and inefficient.
        if(!textureManager->GetTexture("cuteBird")->loadFromFile("./src/assets/cute_bird.png")) {
            throw new e_manager_obj_cantload;
        }

        //

        //
    }
    catch (const manager_exception & e) {
        DEBUG_ERROR(e.what());

        // TODO(clark): For now, let's just close the window. but handle later.
        window->close();
    }

    //------------------------------
    // Initialize our state system!
    //------------------------------
    StateSystem* stateSystem = new StateSystem();

    // Wow! Look at all these states!

    try {
        stateSystem->AddState("charTest", new CharTestState(stateSystem, textureManager));
        stateSystem->AddState("testTest", new MainMenuState(stateSystem, textureManager));
        stateSystem->AddState("inputTest", new InputTestState(stateSystem, fontManager));

        //-------------------------------------------------------------------
        // Change this if you want to change the state the system starts in!
        //-------------------------------------------------------------------
        stateSystem->PushState("inputTest");
    }
    catch (const state_system_exception& e) {
        DEBUG_ERROR(e.what());

        // TODO(clark): For now, let's just close the window. but handle later.
        window->close();
    }
    catch (const manager_exception & e) {
        DEBUG_ERROR(e.what());

        //TODO(clark): Again, for now, just close the window.
        window->close();
    }

    //------------------------
    // Initialize our Input!
    //------------------------
    Input* input = new Input();


    //---------------------------
    // Initialize our Game Clock!
    //---------------------------
    sf::Clock gameClock;

    //---------------
    // Game Loops!
    //---------------
    while(window->isOpen())
    {

        // Polls for events in a loop until stack is empty
        //
        // NOTE(clark): Eventually remove escape key
        // Close conditions for window:
        //      1. Escape key pressed
        //      2. Alt and f4 are pressed
        sf::Event event;
        while(window->pollEvent(event))
        {
            // Window Closed Event
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }


            // Checking for escape keys
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                }

                if(event.key.code == sf::Keyboard::F4)
                {
                    window->close();
                }
            }

            // Check if Controller should be used.
            if(!input->IsJoystickActive())
            {
                if(event.type == sf::Event::JoystickButtonPressed)
                {
                    input->ToggleJoyActive();
                }
            }
            else
            {
                if(event.type == sf::Event::KeyPressed)
                {
                    input->ToggleJoyActive();
                }
            }
        }

        // DO INPUT HANDLING HERE
        input->UpdateInput();

        {
            //---------------------
            // UPDATE AND RENDER
            //---------------------

            // Clear screen
            window->clear();

            try {
                // Render Current GameState;
                stateSystem->update(gameClock.restart().asSeconds(), input);
                stateSystem->render(window);
            }
            catch(const state_system_exception& e) {
                DEBUG_ERROR(e.what());
                window->close();
            }
            // Update the window
            window->display();
        }
    }
    return EXIT_SUCCESS;
}