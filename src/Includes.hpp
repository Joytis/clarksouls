//
// Created by Clark Burton Chambers on 3/14/16.
//

#ifndef CLANDREWSOULS_INCLUDES_HPP
#define CLANDREWSOULS_INCLUDES_HPP

// SFML BOIS
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// BOX2D BOIS
#include <Box2D/Box2D.h>

#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <vector>

#include "dbg.hpp"

#include "Input.hpp"
#include "StateSystem.hpp"
#include "TextureManager.hpp"
#include "FontManager.hpp"

// Exceptions!
#include "exceptions/BasicExceptions.hpp"
#include "exceptions/StateSystemExceptions.hpp"
#include "exceptions/ManagerExceptions.hpp"

// CONSTANTS
#define CLSB2_TIME_STEP (1.0f / 60.0f)
#define CLSB2_VELOCITY_ITTERATIONS 8
#define CLSB2_POSITION_ITTERATIONS 2

// Game State IDs
#define GS_INPUT_TEST "inputTest"
#define GS_CHAR_TEST "charTest"
#define GS_B2_TEST "b2Test"


#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))


typedef struct
{
    union {
        float veloc[3];
        struct {
            float velocity;
            float verVelocity;
            float horVelocity;
        };
    };
} Velocity;



#endif //CLANDREWSOULS_INCLUDES_HPP
