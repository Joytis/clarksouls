//
// Created by Clark Burton Chambers on 3/14/16.
//

#ifndef CLANDREWSOULS_INCLUDES_HPP
#define CLANDREWSOULS_INCLUDES_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <stack>
#include <string>
#include <thread>
#include <vector>

#include "Input.hpp"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

//-----------------------------
// Jank-ass Toggle!
//-----------------------------
#define DEBUG

//-----------------------------
// Debug Macros
//-----------------------------
#ifdef DEBUG
// Basic debug string
#define DEBUG_STRING(str) (printf(str + "\n"))
#define DEBUG_ERROR(str) (std::cerr << str << std::endl)

#else

#define DEBUG_STRING(str)
#define DEBUG_ERROR(str)

#endif //DEBUG


#endif //CLANDREWSOULS_INCLUDES_HPP
