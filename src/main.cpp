#include "includes.hpp"

int main() {

    // Create our window
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1152, 648), "ClarkSouls");

    // Set the Icon
    /*
    sf::Image icon;
    if (!icon.loadFromFile("src/assets/icon.png")) {
        return EXIT_FAILURE;
    }
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
     */

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
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }

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
        }
    }

    return EXIT_SUCCESS;
}