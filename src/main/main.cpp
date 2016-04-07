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

// NOTE(clark):
// When you want to throw an exception, use the macros in dbg.hpp.
// They tun in the form:
//
//      check(BOOLEAN EXPRESSION,
//            EXCEPTION,
//            MESSAGE<printf>)
//
// This will expand into an if statement that when false, throws
//  an exception of the given type and prints a formatted error
//  message.

// NOTE(clark): Check allocations with check_mem(POINTERVALUE)
// NOTE(clark): Leave debug messages with log_info(MESSAGE<printf>)

#include "../Includes.hpp"

#include "../game_states/CharTestState.hpp"
#include "../game_states/MainMenuState.hpp"
#include "../game_states/InputTestState.hpp"
#include "../game_states/Box2DTestState.hpp"

int main() {

    //-------------------
    // Create our window
    //-------------------
    sf::RenderWindow *window;

    try {
        window = new sf::RenderWindow(sf::VideoMode(1152, 648), "ClarkSouls");
        window->setFramerateLimit(60);
        check_mem(window)
    }
    catch(const std::exception &e)
    {
        // TODO(clark): Handle this better. For now, kill code.
        exit(1);
    }
    catch(const e_bad_allocation &e)
    {
        // TODO(clark): Handle
        exit(1);
    }

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
    FontManager *fontManager;

    try {
        fontManager = new FontManager();
        check_mem(fontManager);

        fontManager->AddFont("sansation", new sf::Font);

        //TODO(clark): find a better way to do this. It looks kind of ugly and inefficient.
        if(!fontManager->GetFont("sansation")->loadFromFile("./src/assets/sansation.ttf")) {
            throw new e_manager_obj_cantload;
        }

    }
    catch (const manager_exception & e) {

        // TODO(clark): For now, let's just close the window. but handle later.
        window->close();
    }


    //------------------------------
    // Initialize our tex Manager!
    //------------------------------
    TextureManager *textureManager;

    try {
        textureManager = new TextureManager();
        check_mem(textureManager);
        sf::Texture *temp;

        //---------------------------
        // Cute Bird!
        //---------------------------
        temp = new sf::Texture();
        check_mem(temp)
        check(temp->loadFromFile("./src/assets/cute_bird.png"), e_manager_obj_cantload,
              "Can't load texture cute_bird. Failed to open file.")
        textureManager->AddTexture("cuteBird", temp);

        //---------------------------
        // Player!
        //---------------------------
        temp = new sf::Texture();
        check_mem(temp)
        check(temp->loadFromFile("./src/assets/cute_bird.png"), e_manager_obj_cantload,
              "Can't load texture player. Failed to open file")
        textureManager->AddTexture("player", temp);

        //---------------------------
        // Error!
        //---------------------------
        temp = new sf::Texture();
        check_mem(temp)
        check(temp->loadFromFile("./src/assets/cute_bird.png"), e_manager_obj_cantload,
              "Can't load texture: error. Failed to open file.")
        textureManager->AddTexture("error", temp);

    }
    catch (const manager_exception &e) {

        // TODO(clark): For now, let's just close the window. but handle later.
        window->close();
    }
    catch (const e_bad_allocation &e)
    {
        //TODO(clark): handle
        window->close();
    }


    //------------------------------
    // Initialize our state system!
    //------------------------------
    StateSystem *stateSystem;

    try {
        stateSystem = new StateSystem();
        check_mem(stateSystem);

        // Throws state system exceptions!
        stateSystem->AddState(GS_CHAR_TEST, new CharTestState(stateSystem, textureManager));
        stateSystem->AddState("testTest", new MainMenuState(stateSystem, textureManager));
        stateSystem->AddState(GS_INPUT_TEST, new InputTestState(stateSystem, fontManager));
        stateSystem->AddState(GS_B2_TEST, new Box2DTestState(stateSystem));

        //-------------------------------------------------------------------
        // Change this if you want to change the state the system starts in!
        //-------------------------------------------------------------------
        stateSystem->PushState("inputTest");
    }
    catch (const state_system_exception &e) {

        // TODO(clark): For now, let's just close the window. but handle later.
        window->close();
    }
    catch (const manager_exception &e) {

        //TODO(clark): Again, for now, just close the window.
        window->close();
    }
    catch (const e_bad_allocation &e) {

        //TODO(clark): Handle or break?
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
            catch(const state_system_exception &e) {
                // TODO(clark): Handle these errors. For now, just close window.
                window->close();
            }
            catch(const e_bad_allocation &e)
            {
                // TODO(clark): handle this or let it die?
                exit(1);
            }
            // Update the window
            window->display();
        }
    }
    return EXIT_SUCCESS;
}